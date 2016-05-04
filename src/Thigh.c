#include "Thigh.h"

Thigh* Thigh_create(GLUquadricObj* qobj, Position pos)
{
	Thigh* self = (Thigh*)malloc(sizeof(Thigh));
	float defPos[3] = {1.25, 0.0, -5.0};
	self->pos=pos;
	if (pos==LEFT)
		defPos[0]=-1.25;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Thigh_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.75, 1.25, 5.0, 16, 16);
	glEndList();
	return self;
}

void Thigh_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 0.0, 0.0);
	glCallList(((Thigh*)self)->list);
}
