#include "Finger3.h"

Finger3* Finger3_create(GLUquadricObj* qobj, Position pos)
{
	Finger3* self = (Finger3*)malloc(sizeof(Finger3));
	self->pos=pos;

	float defPos[3] = {-0.07, 0.0, -1.0};
	if(pos==LEFT)
		defPos[0]*=-1;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Finger3_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.07, 0.15, 1.0, 16, 16);
	glEndList();
	
	return self;
}

void Finger3_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 0.0, 0.0);
	glCallList(((Finger3*)self)->list);
}
