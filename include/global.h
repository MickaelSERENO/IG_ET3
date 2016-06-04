#ifndef GLOBAL_INC
#define GLOBAL_INC

typedef enum Anim
{
	NOTHING, WAIT, SIT_DOWN, SIT_GO, SIT_TURN_GO, SIT_TURN_DOWN, WALK, RUN
}Anim;

extern float t;
extern Anim anim;

#endif
