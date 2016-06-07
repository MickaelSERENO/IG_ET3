#include "Finger4.h"

Finger4* Finger4_create(GLUquadricObj* qobj, Position pos)
{
	Finger4* self = (Finger4*)malloc(sizeof(Finger4));
	self->pos=pos;

	float defPos[3] = {-0.22, 0.0, -0.8};
	if(pos==LEFT)
		defPos[0]*=-1;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Finger4_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.07, 0.15, 0.8, 16, 16);
	glEndList();
	
	return self;
}

void Finger4_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 153.0/255.0, 51.0/255.0);
	glCallList(((Finger4*)self)->list);
}
