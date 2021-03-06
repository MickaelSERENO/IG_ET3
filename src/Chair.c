#include "Chair.h"

Chair* Chair_create(GLUquadricObj* qobj)
{
	Chair* self = (Chair*)malloc(sizeof(Chair));
	float defPos[3] = {CHAIR_POSX + CHAIR_SIZEX/2.0f, CHAIR_POSY + CHAIR_SIZEY/2.0f, -6.0};
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Chair_onUpdate;
	
	//création du cube
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
	
	//Creation des pieds
	self->cylinder = glGenLists(1);
	glNewList(self->cylinder, GL_COMPILE);
		gluCylinder(qobj, 0.25, 0.25, 4.7, 16, 16);
	glEndList();

	return self;
}

void Chair_onUpdate(Element* self)
{
	//Plan horizontal de la chaise (où on s'assoie)
	glColor3f(130.0/255.0, 82.0/255.0, 1.0/255.0);
	glTranslatef(0, 0, self->defPos[2]);
	glPushMatrix();
	{	
		glTranslatef(self->defPos[0], self->defPos[1], 0.0f);
		glScalef(2.5, 2.5, 0.2);
		glCallList(((Chair*)self)->cube);
	}
	glPopMatrix();
	
	//Dossier
	glPushMatrix();
	{
		glTranslatef(self->defPos[0], -2.3, 2.7);
		glScalef(2.5, 0.2, 2.5);
		glCallList(((Chair*)self)->cube);
	}
	glPopMatrix();
	
	//Pieds
	glTranslatef(-4.75, -2.25, -4.9);
	glCallList(((Chair*)self)->cylinder);
	
	glTranslatef(0.0, 4.5, 0.0);
	glCallList(((Chair*)self)->cylinder);
	
	glTranslatef(-4.5, 0.0, 0.0);
	glCallList(((Chair*)self)->cylinder);
	
	glTranslatef(0.0, -4.5, 0.0);
	glCallList(((Chair*)self)->cylinder);
}
