CC = gcc
CFLAGS = -c -Wall -Iinclude
LDFLAGS = -lGLU -lGL -l glut

SOURCES = src/main.c src/Element.c src/Arm.c src/Calf.c src/Elbow.c src/Eye.c src/Foot.c src/Forearm.c src/Hand.c src/Head.c src/Knee.c src/Lap.c src/Nose.c src/Shoulder.c src/Wrist.c
OBJS    = $(SOURCES:.c=.o)

all : $(SOURCES) IG

IG : $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

*.c.o :
	$(CC) $(LDFLAGS) $< -o $@

clean:
	rm $(OBJS) IG
