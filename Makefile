CC = gcc
CFLAGS = -c -Wall -Iinclude -g
LDFLAGS = -lGLU -lGL -lglut -lm

SOURCES = src/main.c src/Element.c src/Ankle.c src/Arm.c src/Breast.c src/Calf.c src/Chair.c src/Elbow.c src/Eye.c src/Foot.c src/Forearm.c src/Hand.c src/Head.c src/Hip.c src/Knee.c src/Thigh.c src/Neck.c src/Nose.c src/Shoulder.c src/Waist.c src/Wrist.c src/Pelvis.c
OBJS    = $(SOURCES:.c=.o)

all : $(SOURCES) IG

IG : $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

*.c.o :
	$(CC) $(LDFLAGS) $< -o $@

clean:
	rm $(OBJS) IG
