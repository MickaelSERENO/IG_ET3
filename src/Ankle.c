#include "Ankle.h"

Ankle* Ankle_create(GLUquadricObj* qobj, Position pos)
{
	Ankle* self = (Ankle*)malloc(sizeof(Ankle));
	float defPos[3] = {0.0, 0.0, 0.0};
	self->pos=pos;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Ankle_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		glutSolidSphere(0.25, 16, 16);
	glEndList();
	
	return self;
}

void Ankle_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 0.0, 0.0);
	glCallList(((Ankle*)self)->list);
}

