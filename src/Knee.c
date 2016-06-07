#include "Knee.h"

Knee* Knee_create(GLUquadricObj* qobj, Position pos)
{
	Knee* self = (Knee*)malloc(sizeof(Knee));
	float defPos[3] = {0.0, 0.0, -0.25};
	self->pos=pos;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Knee_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		glutSolidSphere(0.75, 16, 16);
	glEndList();
	
	self->calf = Calf_create(qobj, pos);
	Element_addChild(elem, (Element*)self->calf);
	
	return self;
}

void Knee_onUpdate(Element* self)
{
	switch(anim)
	{
		case SIT_DOWN:
			glRotatef(-90 * t, 1, 0, 0);
			break;
	}
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(0.0, 51.0/255.0, 102.0/255.0);
	glCallList(((Knee*)self)->list);
}
