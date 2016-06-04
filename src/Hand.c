#include "Hand.h"

Hand* Hand_create(GLUquadricObj* qobj, Position pos)
{
	Hand* self = (Hand*)malloc(sizeof(Hand));
	float defPos[3] = {0.0, 0.0, -1.1};
	self->pos=pos;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Hand_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.4, 0.25, 1.1, 16, 16);
	glEndList();

	self->finger1 = Finger1_create(qobj, pos);
	Element_addChild(elem, (Element*)self->finger1);
	self->finger2 = Finger2_create(qobj, pos);
	Element_addChild(elem, (Element*)self->finger2);
	self->finger3 = Finger3_create(qobj, pos);
	Element_addChild(elem, (Element*)self->finger3);
	self->finger4 = Finger4_create(qobj, pos);
	Element_addChild(elem, (Element*)self->finger4);
	self->finger5 = Finger5_create(qobj, pos);
	Element_addChild(elem, (Element*)self->finger5);
	
	return self;
}

void Hand_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glPushMatrix();
	{
		glScalef(1.0,0.55,1.0);
		glColor3f(1.0, 0.0, 0.0);
		glCallList(((Hand*)self)->list);
	}
	glPopMatrix();

}
