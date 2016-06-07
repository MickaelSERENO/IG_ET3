#include "Finger1.h"

Finger1* Finger1_create(GLUquadricObj* qobj, Position pos)
{
	Finger1* self = (Finger1*)malloc(sizeof(Finger1));
	self->pos=pos;

	float defPos[3] = {0.22, 0.0, -0.6};
	if(pos==LEFT)
		defPos[0]*=-1;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Finger1_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.07, 0.15, 0.6, 16, 16);
	glEndList();
	
	return self;
}

void Finger1_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 153.0/255.0, 51.0/255.0);
	glCallList(((Finger1*)self)->list);
}
