#include "Face.h"

Face* Face_create(GLUquadricObj* qobj)
{
	Face* self = (Face*)malloc(sizeof(Face));
	float defPos[3] = {0.0, 1.0, 0.0};
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Face_onUpdate;
	
	self->eye = glGenLists(1);
	glNewList(self->eye, GL_COMPILE);
		glutSolidSphere(0.25, 16, 16);
	glEndList();

	self->pupil = glGenLists(1);
	glNewList(self->pupil, GL_COMPILE);
		glutSolidSphere(0.15, 16, 16);
	glEndList();

	self->nose = glGenLists(1);
	glNewList(self->nose, GL_COMPILE);
		glutSolidSphere(0.2, 16, 16);
	glEndList();

	self->mouth = glGenLists(1);
	glNewList(self->mouth, GL_COMPILE);
		glutSolidSphere(0.25, 16, 16);
	glEndList();
		
	return self;
}

void Face_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glPushMatrix();
	{
		glTranslatef(0.5, -0.2, 0.5);
		glColor3f(1.0, 1.0, 1.0);
		glCallList(((Face*)self)->eye);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(0.5, -0.05, 0.5);
		glColor3f(0.0, 102.0/255.0, 204.0/255.0);
		glCallList(((Face*)self)->pupil);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-0.5, -0.2, 0.5);
		glColor3f(1.0, 1.0, 1.0);
		glCallList(((Face*)self)->eye);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glTranslatef(-0.5, -0.05, 0.5);
		glColor3f(0.0, 102.0/255.0, 204.0/255.0);
		glCallList(((Face*)self)->pupil);
	}
	glPopMatrix();

	glPushMatrix();
	{
		glScalef(1.0,1.5, 1.0);
		glColor3f(1.0, 153.0/255.0, 51.0/255.0);
		glCallList(((Face*)self)->nose);
	}
	glPopMatrix();
	glPushMatrix();
	{
		glTranslatef(0.0, 0.0, -0.5);
		glScalef(1.5,1.0,1.0);
		glColor3f(1.0, 51.0/255.0, 51.0/255.0);
		glCallList(((Face*)self)->mouth);
	}
	glPopMatrix();
}
