#include "Head.h"

Head* Head_create(GLUquadricObj* qobj)
{
	Head* self = (Head*)malloc(sizeof(Head));
	float defPos[3] = {0.0, 0.0, 1.7};
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Head_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		glutSolidSphere(1.5, 16, 16);
	glEndList();

	self->face = Face_create(qobj);
	Element_addChild(elem, (Element*)self->face);
		
	return self;
}

void Head_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glPushMatrix();
	{
		glScalef(2.5/3.0,2.5/3.0,1);
		glColor3f(1.0, 153.0/255.0, 51.0/255.0);
		glCallList(((Head*)self)->list);
	}
	glPopMatrix();
}
