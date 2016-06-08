#include "Arm.h"

Arm* Arm_create(GLUquadricObj* qobj, Position pos)
{
	Arm* self = (Arm*)malloc(sizeof(Arm));
	float defPos[3] = {0.0, 0.0, -4.5}; //Position par défaut de l'élément
	self->pos=pos;
	
	//Angles limites pour l'animation marche
	self->defAngleWalk = -30.0;
	self->endAngleWalk = 15.0;
	
	//Bras gauche ou bras droit ?
	if(pos == RIGHT)
	{
		self->defAngleWalk = 15.0;
		self->endAngleWalk = -30.0;
	}
	
	//De même pour la course
	self->defAngleRun = -60.0;
	self->endAngleRun = 60.0;
	if(pos == RIGHT)
	{
		self->defAngleRun = 60.0;
		self->endAngleRun = -60.0;
	}
	
	//Appel le constructeur parent
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Arm_onUpdate; //Initialise la surchage de onUpdate
	
	//initialisation des formes opengl
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.5, 0.5, 4.5, 16, 16);
	glEndList();
	
	//Initialisation des enfants
	self->elbow = Elbow_create(qobj, pos);
	Element_addChild(elem, (Element*)self->elbow);
	return self;
}

void Arm_onUpdate(Element* self)
{
	Arm* sArm = (Arm*)self;
	float defAngle=sArm->defAngleWalk;
	float endAngle=sArm->endAngleWalk;
	
	//Transformation selon l'animation (les animations sont paramétrées selon t)
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

		case WAIT:
			if(((Arm*)self)->pos == RIGHT)
				glRotatef(-40, 0, 1, 0);
			else
				glRotatef(40, 0, 1, 0);
			break;
	}
		
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 1.0, 1.0);
	glCallList(((Arm*)self)->list);
}
