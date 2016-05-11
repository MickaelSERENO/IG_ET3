#include "Forearm.h"

Forearm* Forearm_create(GLUquadricObj* qobj, Position pos)
{
	Forearm* self = (Forearm*)malloc(sizeof(Forearm));
	float defPos[3] = {0.0, 0.0, -4.5};
	self->pos=pos;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Forearm_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.25, 0.5, 5.0, 16, 16);
	glEndList();
	
	self->wrist = Wrist_create(qobj, pos);
	Element_addChild(elem, (Element*)self->wrist);
		
	return self;
}

void Forearm_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 0.0, 0.0);
	glCallList(((Forearm*)self)->list);
}
