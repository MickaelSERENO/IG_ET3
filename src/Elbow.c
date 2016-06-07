#include "Elbow.h"

Elbow* Elbow_create(GLUquadricObj* qobj, Position pos)
{
	Elbow* self = (Elbow*)malloc(sizeof(Elbow));
	float defPos[3] = {0.0, 0.0, -0.25};
	self->pos=pos;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Elbow_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		glutSolidSphere(0.5, 16, 16);
	glEndList();
	
	self->forearm = Forearm_create(qobj, pos);
	Element_addChild(elem, (Element*)self->forearm);
	return self;
}

void Elbow_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 153.0/255.0, 51.0/255.0);
	glCallList(((Elbow*)self)->list);
}
