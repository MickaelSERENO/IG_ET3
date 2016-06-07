#include "Thigh.h"

Thigh* Thigh_create(GLUquadricObj* qobj, Position pos)
{
	Thigh* self = (Thigh*)malloc(sizeof(Thigh));
	float defPos[3] = {1.25, 0.0, -4.75};
	self->pos=pos;
	if (pos==LEFT)
		defPos[0]=-1.25;
		
	self->defAngleWalk = 20.0;
	self->endAngleWalk = -20.0;
	if(pos == RIGHT)
	{
		self->defAngleWalk = -20.0;
		self->endAngleWalk = 20.0;
	}

	self->defAngleRun = 40.0;
	self->endAngleRun = -40.0;
	if(pos == RIGHT)
	{
		self->defAngleRun = -40.0;
		self->endAngleRun = 40.0;
	}
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Thigh_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.75, 1.25, 4.75, 16, 16);
	glEndList();
	
	self->knee = Knee_create(qobj, pos);
	Element_addChild(elem, (Element*)self->knee);
	
	return self;
}

void Thigh_onUpdate(Element* self)
{
	Thigh* sThigh= (Thigh*)self;
	float defAngle=sThigh->defAngleWalk;
	float endAngle=sThigh->endAngleWalk;
	switch(anim)
	{
		case RUN:
			defAngle = sThigh->defAngleRun;
			endAngle = sThigh->endAngleRun;
		case WALK:
		case SIT_GO:
			if(t < 0.25)
				glRotatef(4*t*(defAngle), 1.0, 0.0, 0.0);
			else if(t < 0.75)
				glRotatef(defAngle + 2*(t-0.25)*(endAngle - defAngle), 1.0, 0.0, 0.0);
			else
				glRotatef(endAngle + 4*(t-0.75)*(-endAngle), 1.0, 0.0, 0.0);
			break;
		case SIT_DOWN:
			glRotatef(90 * t, 1, 0, 0);
			break;
	}
	
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(0.0, 51.0/255.0, 102.0/255.0);
	glCallList(((Thigh*)self)->list);
}
