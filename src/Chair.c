#include "Chair.h"

Chair* Chair_create(GLUquadricObj* qobj)
{
	Chair* self = (Chair*)malloc(sizeof(Chair));
	float defPos[3] = {-7.0, 0.0, -6.0};
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Chair_onUpdate;
	
	self->cube = glGenLists(1);
	glNewList(self->cube, GL_COMPILE);
		glBegin(GL_TRIANGLES);
			//devant
			glVertex3f( -1.0 , 1.0 , -1.0 );
			glVertex3f( 1.0 , 1.0 , 1.0 );
			glVertex3f( 1.0 , 1.0 , -1.0 );
			
			glVertex3f( -1.0 , 1.0 , -1.0 );
			glVertex3f( -1.0 , 1.0 , 1.0 );
			glVertex3f( 1.0 , 1.0 , 1.0 );

			//dessus
			glVertex3f( 1.0 , 1.0 , 1.0 );
			glVertex3f( -1.0 , 1.0 , 1.0 );
			glVertex3f( -1.0 , -1.0 , 1.0 );
			
			glVertex3f( 1.0 , 1.0 , 1.0 );
			glVertex3f( -1.0 , -1.0 , 1.0 );
			glVertex3f( 1.0 , -1.0 , 1.0 );

			//derrière
			glVertex3f( -1.0 , -1.0 , -1.0 );
			glVertex3f( 1.0 , -1.0 , 1.0 );
			glVertex3f( 1.0 , -1.0 , -1.0 );
			
			glVertex3f( -1.0 , -1.0 , -1.0 );
			glVertex3f( -1.0 , -1.0 , 1.0 );
			glVertex3f( 1.0 , -1.0 , 1.0 );

			//dessous
			glVertex3f( 1.0 , 1.0 , -1.0 );
			glVertex3f( -1.0 , 1.0 , -1.0 );
			glVertex3f( -1.0 , -1.0 , -1.0 );
			
			glVertex3f( 1.0 , 1.0 , -1.0 );
			glVertex3f( -1.0 , -1.0 , -1.0 );
			glVertex3f( 1.0 , -1.0 , -1.0 );
			
			//gauche
			glVertex3f( 1.0 , -1.0 , -1.0 );
			glVertex3f( 1.0 , 1.0 , -1.0 );
			glVertex3f( 1.0 , 1.0 , 1.0 );

			glVertex3f( 1.0 , -1.0 , -1.0 );
			glVertex3f( 1.0 , 1.0 , 1.0 );
			glVertex3f( 1.0 , -1.0 , 1.0 );
			
			//droite
			glVertex3f( -1.0 , -1.0 , -1.0 );
			glVertex3f( -1.0 , 1.0 , -1.0 );
			glVertex3f( -1.0 , 1.0 , 1.0 );

			glVertex3f( -1.0 , -1.0 , -1.0 );
			glVertex3f( -1.0 , 1.0 , 1.0 );
			glVertex3f( -1.0 , -1.0 , 1.0 );
			
		glEnd();
	glEndList();
	
	self->cylinder = glGenLists(1);
	glNewList(self->cylinder, GL_COMPILE);
		gluCylinder(qobj, 0.25, 0.25, 5.0, 16, 16);
	glEndList();

	return self;
}

void Chair_onUpdate(Element* self)
{
	glTranslatef(0, 0, self->defPos[2]);
	glPushMatrix();
	{	
		glTranslatef(self->defPos[0], self->defPos[1], 0.0f);
		glScalef(2.5, 2.5, 0.2);
		glColor3f(1.0, 1.0, 0.0);
		glCallList(((Chair*)self)->cube);
	}
	glPopMatrix();
	
	
	glPushMatrix();
	{
		glTranslatef(self->defPos[0], -2.3, 2.7);
		glScalef(2.5, 0.2, 2.5);
		glColor3f(1.0, 1.0, 0.0);
		glCallList(((Chair*)self)->cube);
	}
	glPopMatrix();
	
	glTranslatef(-4.75, -2.25, -5.2);
	glColor3f(1.0, 1.0, 0.0);
	glCallList(((Chair*)self)->cylinder);
	
	glTranslatef(0.0, 4.5, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glCallList(((Chair*)self)->cylinder);
	
	glTranslatef(-4.5, 0.0, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glCallList(((Chair*)self)->cylinder);
	
	glTranslatef(0.0, -4.5, 0.0);
	glColor3f(1.0, 1.0, 0.0);
	glCallList(((Chair*)self)->cylinder);
}
