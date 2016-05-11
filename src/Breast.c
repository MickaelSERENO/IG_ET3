#include "Breast.h"

Breast* Breast_create(GLUquadricObj* qobj)
{
	Breast* self = (Breast*)malloc(sizeof(Breast));
	float defPos[3] = {0.0, 0.0, 0.25};
	Element_init((Element*)self, defPos);
	
	self->defAngleWalk = 15.0;
	self->endAngleWalk = -15.0;
	
	Element* elem = (Element*)self;
	elem->onUpdate = Breast_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 1.5, 2.5, 3.5, 16, 16);
	glEndList();
	
	self->leftShoulder = Shoulder_create(qobj, LEFT);
	self->rightShoulder = Shoulder_create(qobj, RIGHT);
	self->neck = Neck_create(qobj);
	Element_addChild(elem, (Element*)self->leftShoulder);
	Element_addChild(elem, (Element*)self->rightShoulder);
	Element_addChild(elem, (Element*)self->neck);

	return self;
}

void Breast_onUpdate(Element* elem)
{
	Breast* sBreast = (Breast*)elem;
	switch(anim)
	{
		case WALK:
			if(t < 0.25)
				glRotatef(4*t*(sBreast->defAngleWalk), 0.0, 0.0, 1.0);
			else if(t < 0.75)
				glRotatef(sBreast->defAngleWalk + 2*(t-0.25)*(sBreast->endAngleWalk - sBreast->defAngleWalk), 0.0, 0.0, 1.0);
			else
				glRotatef(sBreast->endAngleWalk + 4*(t-0.75)*(-sBreast->endAngleWalk), 0.0, 0.0, 1.0);
			break;
	}
	
	glTranslatef(elem->defPos[0], elem->defPos[1], elem->defPos[2]);
	glPushMatrix();
	{
		glScalef(1.0,BODY_SCALE, 1.0);
		glColor3f(1.0, 1.0, 1.0);
		glCallList(((Breast*)elem)->list);
	}
	glPopMatrix();
}
