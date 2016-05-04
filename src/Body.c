#include "Body.h"

Body* Body_create(GLUquadricObj* qobj)
{
	Body* self = (Body*)malloc(sizeof(Body));
	float defPos[3] = {0.0, 0.0, 0.0};
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Body_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 2.5, 2.5, 7.0, 16, 16);
	glEndList();
	
	self->leftShoulder = Shoulder_create(qobj, LEFT);
	self->rightShoulder = Shoulder_create(qobj, RIGHT);
	self->pelvis = Pelvis_create(qobj);
	Element_addChild(elem, (Element*)self->leftShoulder);
	Element_addChild(elem, (Element*)self->rightShoulder);
	Element_addChild(elem, (Element*)self->pelvis);

	return self;
}

void Body_onUpdate(Element* elem)
{
	glTranslatef(elem->defPos[0], elem->defPos[1], elem->defPos[2]);
	glColor3f(1.0, 1.0, 1.0);
	glCallList(((Body*)elem)->list);
}
