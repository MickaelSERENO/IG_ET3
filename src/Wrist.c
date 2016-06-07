#include "Wrist.h"

Wrist* Wrist_create(GLUquadricObj* qobj, Position pos)
{
	Wrist* self = (Wrist*)malloc(sizeof(Wrist));
	float defPos[3] = {0.0, 0.0, 0.0};
	self->pos=pos;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Wrist_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		glutSolidSphere(0.25, 16, 16);
	glEndList();

	self->hand = Hand_create(qobj, pos);
	Element_addChild(elem, (Element*)self->hand);
	
	return self;
}

void Wrist_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 153.0/255.0, 51.0/255.0);
	glCallList(((Wrist*)self)->list);
}
