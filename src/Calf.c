#include "Calf.h"

Calf* Calf_create(GLUquadricObj* qobj, Position pos)
{
	Calf* self = (Calf*)malloc(sizeof(Calf));
	float defPos[3] = {0.0, 0.0, -5.15};
	
	self->defAngleWalk = 0.0;
	self->endAngleWalk = -20.0;
	if(pos == RIGHT)
	{
		self->defAngleWalk = -20.0;
		self->endAngleWalk = 0.0;
	}
	
	self->defAngleRun = 0.0;
	self->endAngleRun = -25.0;
	if(pos == RIGHT)
	{
		self->defAngleRun = -25.0;
		self->endAngleRun = 0.0;
	}
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Calf_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.25, 0.75, 5.0, 16, 16);
	glEndList();
	
	self->ankle = Ankle_create(qobj, pos);
	Element_addChild(elem, (Element*)self->ankle);
	
	return self;
}

void Calf_onUpdate(Element* self)
{
	Calf* sCalf= (Calf*)self;
	float defAngle=sCalf->defAngleWalk;
	float endAngle=sCalf->endAngleWalk;
	switch(anim)
	{
		case RUN:
			defAngle = sCalf->defAngleRun;
			endAngle = sCalf->endAngleRun;
		case WALK:
			if(t < 0.25)
				glRotatef(4*t*(defAngle), 1.0, 0.0, 0.0);
			else if(t < 0.75)
				glRotatef(defAngle + 2*(t-0.25)*(endAngle - defAngle), 1.0, 0.0, 0.0);
			else
				glRotatef(endAngle + 4*(t-0.75)*(-endAngle), 1.0, 0.0, 0.0);
			break;
	}
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 0.0, 0.0);
	glCallList(((Calf*)self)->list);
}
