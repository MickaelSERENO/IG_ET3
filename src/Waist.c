#include "Waist.h"

Waist* Waist_create(GLUquadricObj* qobj)
{
	Waist* self = (Waist*)malloc(sizeof(Waist));
	float defPos[3] = {0.0, 0.0, 3.25};
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Waist_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		glutSolidSphere(1.0, 16, 16);
	glEndList();
	
	self->breast = Breast_create(qobj);	
	self->hip = Hip_create(qobj);
	Element_addChild(elem, (Element*)self->breast);
	Element_addChild(elem, (Element*)self->hip);

	return self;
}

void Waist_onUpdate(Element* elem)
{
	glTranslatef(elem->defPos[0], elem->defPos[1], elem->defPos[2]);
	glPushMatrix();
	{
		glScalef(1.3,BODY_SCALE,1.0);
		glColor3f(0.0, 0.0, 1.0);
		glCallList(((Waist*)elem)->list);
	}
	glPopMatrix();
}
