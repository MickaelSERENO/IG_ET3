CC = gcc
CFLAGS = -c -Wall -Iinclude -g
LDFLAGS = -lGLU -lGL -lglut -lm

SOURCES = src/main.c src/Element.c src/Arm.c src/Body.c src/Calf.c src/Elbow.c src/Eye.c src/Foot.c src/Forearm.c src/Hand.c src/Head.c src/Knee.c src/Thigh.c src/Nose.c src/Shoulder.c src/Wrist.c src/Pelvis.c
OBJS    = $(SOURCES:.c=.o)

all : $(SOURCES) IG

IG : $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

*.c.o :
	$(CC) $(LDFLAGS) $< -o $@

clean:
	rm $(OBJS) IG
