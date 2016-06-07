#include "Foot.h"

Foot* Foot_create(GLUquadricObj* qobj, Position pos)
{
	Foot* self = (Foot*)malloc(sizeof(Foot));
	float defPos[3] = {0.0, 0.25, -0.6};
	self->pos=pos;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Foot_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.5, 0.25, 0.7, 16, 16);
	glEndList();
	
	return self;
}

void Foot_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glPushMatrix();
	{
		glScalef(1.0, 1.8, 1.0);
		glColor3f(51.0/255.0, 25.0/255.0, 0.0);
		glCallList(((Foot*)self)->list);
	}
	glPopMatrix();
}
