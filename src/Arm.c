#include "Arm.h"

Arm* Arm_create(GLUquadricObj* qobj, Position pos)
{
	Arm* self = (Arm*)malloc(sizeof(Arm));
	float defPos[3] = {0.0, 0.0, -4.5};
	self->pos=pos;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Arm_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.5, 0.5, 4.5, 16, 16);
	glEndList();
	
	self->elbow = Elbow_create(qobj, pos);
	Element_addChild(elem, (Element*)self->elbow);
	return self;
}

void Arm_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 0.0, 0.0);
	glCallList(((Arm*)self)->list);
}
