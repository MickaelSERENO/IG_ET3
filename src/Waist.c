#include "Waist.h"

Waist* Waist_create(GLUquadricObj* qobj)
{
	Waist* self = (Waist*)malloc(sizeof(Waist));
	float defPos[3] = {0.0, 0.0, 3.25};
	Element_init((Element*)self, defPos);
	
	self->defposWalk = 0.0;
	self->endposWalk = -0.5;
	
	Element* elem = (Element*)self;
	elem->onUpdate = Waist_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		glutSolidSphere(1.0, 16, 16);
	glEndList();
	
	self->breast = Breast_create(qobj);	
	self->hip = Hip_create(qobj);
	Element_addChild(elem, (Element*)self->breast);
	Element_addChild(elem, (Element*)self->hip);

	return self;
}

void Waist_onUpdate(Element* elem)
{
	Waist* sWait = (Waist*)elem;
	switch(anim)
	{
		case WALK:
		case RUN:
			if(t < 0.25)
				glTranslatef(0.0, 0.0, 4*t*(sWait->endposWalk));
			else if(t<0.5)
				glTranslatef(0.0, 0.0, sWait->endposWalk + 4*(t-0.25)*(sWait->defposWalk - sWait->endposWalk));
			else if(t<0.75)
				glTranslatef(0.0, 0.0, 4*(t-0.5)*(sWait->endposWalk));
			else
				glTranslatef(0.0, 0.0, sWait->endposWalk + 4*(t-0.75)*(sWait->defposWalk - sWait->endposWalk));
			break;
	}
	
	glTranslatef(elem->defPos[0], elem->defPos[1], elem->defPos[2]);
	glPushMatrix();
	{
		glScalef(1.3,BODY_SCALE+0.3,1.0);
		glColor3f(0.0, 0.0, 1.0);
		glCallList(((Waist*)elem)->list);
	}
	glPopMatrix();
}
