#include "Forearm.h"

Forearm* Forearm_create(GLUquadricObj* qobj, Position pos)
{
	Forearm* self = (Forearm*)malloc(sizeof(Forearm));
	float defPos[3] = {0.0, 0.0, -3.75};
	self->pos=pos;
	self->hasStartRun=0;
	self->defAngleWalk = 0.0;
	self->endAngleWalk = 15.0;
	if(pos == RIGHT)
	{
		self->defAngleWalk = 15.0;
		self->endAngleWalk = 0.0;
	}
	
	self->defAngleRun = 65.0;
	self->endAngleRun = 85.0;
	if(pos == RIGHT)
	{
		self->defAngleRun = 85.0;
		self->endAngleRun = 65.0;
	}
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Forearm_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.25, 0.5, 4.0, 16, 16);
	glEndList();
	
	self->wrist = Wrist_create(qobj, pos);
	Element_addChild(elem, (Element*)self->wrist);
		
	return self;
}

void Forearm_onUpdate(Element* self)
{
	Forearm* sForearm = (Forearm*)self;
	switch(anim)
	{
		case RUN:
			if(t < 0.25)
			{
				if(sForearm->hasStartRun==0)
					glRotatef(4*t*(sForearm->defAngleRun), 1.0, 0.0, 0.0);
				else
					glRotatef(sForearm->defAngleRun + 4*t*(sForearm->endAngleRun - sForearm->defAngleRun), 1.0, 0.0, 0.0);

			}
			else if(t < 0.5)
				glRotatef(sForearm->endAngleRun + 4*(t-0.25)*(-sForearm->endAngleRun + sForearm->defAngleRun), 1.0, 0.0, 0.0);
			else if(t < 0.75)
				glRotatef(sForearm->defAngleRun + 4*(t-0.50)*(sForearm->endAngleRun - sForearm->defAngleRun), 1.0, 0.0, 0.0);
			else
			{
				glRotatef(sForearm->endAngleRun + 4*(t-0.75)*(sForearm->defAngleRun -sForearm->endAngleRun), 1.0, 0.0, 0.0);
				sForearm->hasStartRun=1;
			}
			break;
			
		case WALK:
			if(t < 0.25)
				glRotatef(4*t*(sForearm->defAngleWalk), 1.0, 0.0, 0.0);
			else if(t < 0.75)
				glRotatef(sForearm->defAngleWalk + 2*(t-0.25)*(sForearm->endAngleWalk - sForearm->defAngleWalk), 1.0, 0.0, 0.0);
			else
				glRotatef(sForearm->endAngleWalk + 4*(t-0.75)*(-sForearm->endAngleWalk), 1.0, 0.0, 0.0);
			break;
	}
	
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 0.0, 0.0);
	glCallList(((Forearm*)self)->list);
}
