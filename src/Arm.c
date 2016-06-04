#include "Arm.h"

Arm* Arm_create(GLUquadricObj* qobj, Position pos)
{
	Arm* self = (Arm*)malloc(sizeof(Arm));
	float defPos[3] = {0.0, 0.0, -4.5};
	self->pos=pos;
	
	self->defAngleWalk = -30.0;
	self->endAngleWalk = 15.0;
	if(pos == RIGHT)
	{
		self->defAngleWalk = 15.0;
		self->endAngleWalk = -30.0;
	}
	
	self->defAngleRun = -60.0;
	self->endAngleRun = 60.0;
	if(pos == RIGHT)
	{
		self->defAngleRun = 60.0;
		self->endAngleRun = -60.0;
	}
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Arm_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.5, 0.5, 4.5, 16, 16);
	glEndList();
	
	self->elbow = Elbow_create(qobj, pos);
	Element_addChild(elem, (Element*)self->elbow);
	return self;
}

void Arm_onUpdate(Element* self)
{
	Arm* sArm = (Arm*)self;
	float defAngle=sArm->defAngleWalk;
	float endAngle=sArm->endAngleWalk;
	switch(anim)
	{
		case RUN:
			defAngle = sArm->defAngleRun;
			endAngle = sArm->endAngleRun;
		case WALK:
		case SIT_GO:
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
	glCallList(((Arm*)self)->list);
}
