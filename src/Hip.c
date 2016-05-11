#include "Hip.h"

Hip* Hip_create(GLUquadricObj* qobj)
{
	Hip* self = (Hip*)malloc(sizeof(Hip));
	float defPos[3] = {0.0, 0.0, -3.25};
	Element_init((Element*)self, defPos);
	Element* elem = (Element*)self;
	elem->onUpdate = Hip_onUpdate;
	
	self->list = glGenLists(1);
	glNewList(self->list, GL_COMPILE);
		gluCylinder(qobj, 2.5, 1.5, 3.0, 16, 16);
	glEndList();
	
	self->pelvis = Pelvis_create(qobj);	
	Element_addChild(elem, (Element*)self->pelvis);

	return self;
}

void Hip_onUpdate(Element* elem)
{
	glTranslatef(elem->defPos[0], elem->defPos[1], elem->defPos[2]);
	glPushMatrix();
	{
		glScalef(1.0,BODY_SCALE, 1.0);
		glColor3f(1.0, 1.0, 1.0);
		glCallList(((Hip*)elem)->list);
	}
	glPopMatrix();
}
