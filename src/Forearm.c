#include "Forearm.h"

Forearm* Forearm_create(GLUquadricObj* qobj, Position pos)
{
	Forearm* self = (Forearm*)malloc(sizeof(Forearm));
	float defPos[3] = {0.0, 0.0, -4.75};
	self->pos=pos;
	
	self->defAngleWalk = 0.0;
	self->endAngleWalk = 15.0;
	if(pos == RIGHT)
	{
		self->defAngleWalk = 15.0;
		self->endAngleWalk = 0.0;
	}
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Forearm_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.25, 0.5, 5.0, 16, 16);
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
