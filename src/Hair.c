#include "Hair.h"

Hair* Hair_create(GLUquadricObj* qobj)
{
	Hair* self = (Hair*)malloc(sizeof(Hair));
	float defPos[3] = {0.0, 0.0, 0.0};
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Hair_onUpdate;
	
	/*self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.20, 0.5, 1.0, 16, 16);
	glEndList();*/

	self->hair = glGenLists(1);
	glNewList(self->hair, GL_COMPILE);
	{
		float r = 1.7;
		int scalex = 32;
		int scaley = 32;
		int i, j;
		float v[32*32][3];
 		for (i=0; i<scalex; ++i) {
			for (j=0; j<scaley; ++j) {
				v[i*scaley+j][0]=r*cos(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
				v[i*scaley+j][1]=r*sin(i*M_PI/(2*scalex));
				v[i*scaley+j][2]=r*sin(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
			}
		}
 		glBegin(GL_QUADS);
		for (i=0; i<scalex-1; ++i) {
			for (j=0; j<scaley; ++j) {
				glVertex3fv(v[i*scaley+j]);
				glVertex3fv(v[i*scaley+(j+1)%scaley]);
				glVertex3fv(v[(i+1)*scaley+(j+1)%scaley]);
				glVertex3fv(v[(i+1)*scaley+j]);
			}
		}
		glEnd();
	}
	glEndList();

	self->frange = glGenLists(1);
	glNewList(self->frange, GL_COMPILE);
	{
		float r = 1.7;
		int scalex = 32;
		int scaley = 32;
		int i, j;
		float v[32*32][3];
 		for (i=0; i<scalex; ++i) {
			for (j=0; j<scaley; ++j) {
				v[i*scaley+j][0]=r*cos(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
				v[i*scaley+j][1]=r*sin(i*M_PI/(2*scalex));
				v[i*scaley+j][2]=r*sin(j*2*M_PI/scaley)*cos(i*M_PI/(2*scalex));
			}
		}
 		glBegin(GL_QUADS);
		for (i=0; i<(scalex-1); ++i) {
			for (j=0; j<scaley/3; ++j) {
				glVertex3fv(v[i*scaley+j]);
				glVertex3fv(v[i*scaley+(j+1)%scaley]);
				glVertex3fv(v[(i+1)*scaley+(j+1)%scaley]);
				glVertex3fv(v[(i+1)*scaley+j]);
			}
		}
		glEnd();
	}
	glEndList();
		
	return self;
}

void Hair_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glPushMatrix();
	{
	
		glRotatef(-30, 0.0, 0.0, 1.0);
		glColor3f(214.0/255.0, 37.0/255.0, 152.0/255.0);
		glCallList(((Hair*)self)->frange);
	}
	glPopMatrix();

	glPushMatrix();
	{
	
		glRotatef(180, 1.0, 0.0, 0.0);
		glColor3f(214.0/255.0, 37.0/255.0, 152.0/255.0);
		glCallList(((Hair*)self)->hair);
	}
	glPopMatrix();
}
