#include "Breast.h"

Breast* Breast_create(GLUquadricObj* qobj)
{
	Breast* self = (Breast*)malloc(sizeof(Breast));
	float defPos[3] = {0.0, 0.0, 0.25};
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Breast_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 1.5, 2.5, 3.5, 16, 16);
	glEndList();
	
	self->leftShoulder = Shoulder_create(qobj, LEFT);
	self->rightShoulder = Shoulder_create(qobj, RIGHT);
	self->neck = Neck_create(qobj);
	Element_addChild(elem, (Element*)self->leftShoulder);
	Element_addChild(elem, (Element*)self->rightShoulder);
	Element_addChild(elem, (Element*)self->neck);

	return self;
}

void Breast_onUpdate(Element* elem)
{
	glTranslatef(elem->defPos[0], elem->defPos[1], elem->defPos[2]);
	glPushMatrix();
	{
		glScalef(1.0,BODY_SCALE, 1.0);
		glColor3f(1.0, 1.0, 1.0);
		glCallList(((Breast*)elem)->list);
	}
	glPopMatrix();
}
