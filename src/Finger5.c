#include "Finger5.h"

Finger5* Finger5_create(GLUquadricObj* qobj, Position pos)
{
	Finger5* self = (Finger5*)malloc(sizeof(Finger5));
	self->pos=pos;

	float defPos[3] = {-0.4, 0.0, -0.4};
	if(pos==LEFT)
		defPos[0]*=-1;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Finger5_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.07, 0.1, 0.6, 16, 16);
	glEndList();
	
	return self;
}

void Finger5_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 153.0/255.0, 51.0/255.0);
	glCallList(((Finger5*)self)->list);
}
