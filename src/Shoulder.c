#include "Shoulder.h"

Shoulder* Shoulder_create(GLUquadricObj* qobj, Position pos)
{
	Shoulder* self = (Shoulder*)malloc(sizeof(Shoulder));
	self->pos=pos;
	
	float defPos[3] = {2.7, 0.0, 3.0};
	if(pos==LEFT)
		defPos[0]*=-1;
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Shoulder_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		glutSolidSphere(0.5, 16, 16);
	glEndList();
	
	self->arm = Arm_create(qobj, pos);
	Element_addChild(elem, (Element*)self->arm);
	
	return self;
}

void Shoulder_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 0.0, 0.0);
	glCallList(((Shoulder*)self)->list);
}
