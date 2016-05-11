#include "Pelvis.h"

Pelvis* Pelvis_create(GLUquadricObj* qobj)
{
	Pelvis* self = (Pelvis*)malloc(sizeof(Pelvis));
	float defPos[3] = {0.0, 0.0, 0.0};
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Pelvis_onUpdate;
	
	//Créer le bassin
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
	
		//Créer le cercle
		glBegin(GL_TRIANGLE_FAN);
			glVertex3f(0.0, 0.0, 0.0);
			for(uint32_t i=0; i < PELVIS_NB_EDGE+1; i++)
			{
				float pos[] = {PELVIS_RADIUS*(float)cos(i*2*PI/PELVIS_NB_EDGE), PELVIS_RADIUS*(float)sin(i*2*PI/PELVIS_NB_EDGE), 0.0f};
				glVertex3f(pos[0], pos[1], pos[2]);
			}
		glEnd();
		
		//Créer le rectangle
		glBegin(GL_POLYGON);
			glVertex3f(0.25, -0.5, -1.0);
			glVertex3f(-0.25, -0.5, -1.0);
			glVertex3f(-0.25, 0.5, -1.0);
			glVertex3f(0.25, 0.5, -1.0); 
		glEnd();
		
		//Les relier. Le rectangle créera un défaut au niveau de ses coins (car ce n'est pas un cercle)
		glBegin(GL_QUADS);
			for(uint32_t i=0; i < PELVIS_NB_EDGE+1; i++)
			{
				float pos1[] = {PELVIS_RADIUS*(float)cos(i*2*PI/PELVIS_NB_EDGE), PELVIS_RADIUS*(float)sin(i*2*PI/PELVIS_NB_EDGE), 0.0f};
				float pos2[] = {PELVIS_RADIUS*(float)cos((i+1)*2*PI/PELVIS_NB_EDGE), PELVIS_RADIUS*(float)sin((i+1)*2*PI/PELVIS_NB_EDGE), 0.0f};
				float pos3[3];
				float pos4[3];
			
				if(i == PELVIS_NB_EDGE/4)
				{	
					
					pos3[0] = 0.25; 
					pos3[1] = 0.5;
					pos3[2] = -1.0;
					
					pos4[0] = -0.25; 
					pos4[1] = 0.5;
					pos4[2] = -1.0;
				}
				
				else if(i==3*PELVIS_NB_EDGE/4)
				{
					pos4[0] = 0.25; 
					pos4[1] = -0.5;
					pos4[2] = -1.0;
					
					pos3[0] = -0.25; 
					pos3[1] = -0.5;
					pos3[2] = -1.0;
				}
					
				else if(i < PELVIS_NB_EDGE/4 || i > 3*PELVIS_NB_EDGE/4)
				{
					pos3[0] = -0.25; 
					if(i == 3*PELVIS_NB_EDGE/4+1)
						pos3[1] = 0.5;
					else
						pos3[1] = pos2[1]*1.0/PELVIS_RADIUS;
					pos3[2] = -1.0;
					
					pos4[0] = -0.25; 
					if(i == PELVIS_NB_EDGE/4-1)
						pos4[1] = 0.5;
					else
						pos4[1] =  pos1[1]*1.0/PELVIS_RADIUS;
					pos4[2] = -1.0;
				}
				
				else
				{
					pos3[0] = 0.25; 
					if(i==PELVIS_NB_EDGE/4+1)
						pos3[1]=-0.5;
					else
						pos3[1] = pos2[1]*1.0/PELVIS_RADIUS;
					pos3[2] = -1.0;
					
					pos4[0] = 0.25; 
					if(i==3*PELVIS_NB_EDGE/4-1)
						pos4[1] = -0.5;
					else
						pos4[1] =  pos1[1]*1.0/PELVIS_RADIUS;
					pos4[2] = -1.0;
				}
				
				glVertex3f(pos1[0], pos1[1], pos1[2]);
				glVertex3f(pos2[0], pos2[1], pos2[2]);
				glVertex3f(pos3[0], pos3[1], pos3[2]);
				glVertex3f(pos4[0], pos4[1], pos4[2]);
			}
		glEnd();
	glEndList();
	
	self->rightThigh = Thigh_create(qobj, RIGHT);
	self->leftThigh = Thigh_create(qobj, LEFT);
	Element_addChild(elem, (Element*)self->leftThigh);
	Element_addChild(elem, (Element*)self->rightThigh);
	
	return self;
}

void Pelvis_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glPushMatrix();
	{
		glScalef(1.0, BODY_SCALE, 1.0);
		glColor3f(0.0, 0.0, 1.0);
		glCallList(((Pelvis*)self)->list);
	}
	glPopMatrix();
}
