#include "Neck.h"

Neck* Neck_create(GLUquadricObj* qobj)
{
	Neck* self = (Neck*)malloc(sizeof(Neck));
	float defPos[3] = {0.0, 0.0, 3.5};
	
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Neck_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 0.6, 0.6, 0.5, 16, 16);
	glEndList();
	
	self->head = Head_create(qobj);
	Element_addChild(elem, (Element*)self->head);
		
	return self;
}

void Neck_onUpdate(Element* self)
{
	glTranslatef(self->defPos[0], self->defPos[1], self->defPos[2]);
	glColor3f(1.0, 153.0/255.0, 51.0/255.0);
	glCallList(((Neck*)self)->list);
}

