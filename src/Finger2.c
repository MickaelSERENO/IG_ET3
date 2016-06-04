#include "Finger2.h"

Finger2* Finger2_create(GLUquadricObj* qobj, Position pos)
{
	Finger2* self = (Finger2*)malloc(sizeof(Finger2));
	self->pos=pos;

	float defPos[3] = {0.07, 0.0, -0.8};
	if(pos==LEFT)
		defPos[0]*=-1;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Finger2_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.07, 0.15, 0.8, 16, 16);
	glEndList();
	
	return self;
}

void Finger2_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 0.0, 0.0);
	glCallList(((Finger2*)self)->list);
}
