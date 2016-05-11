#include "Calf.h"

Calf* Calf_create(GLUquadricObj* qobj, Position pos)
{
	Calf* self = (Calf*)malloc(sizeof(Calf));
	float defPos[3] = {0.0, 0.0, -5.15};
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Calf_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.25, 0.75, 5.0, 16, 16);
	glEndList();
	
	self->ankle = Ankle_create(qobj, pos);
	Element_addChild(elem, (Element*)self->ankle);
	
	return self;
}

void Calf_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 0.0, 0.0);
	glCallList(((Calf*)self)->list);
}
