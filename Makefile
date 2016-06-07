CC = gcc
CFLAGS = -c -Wall -Iinclude -g
LDFLAGS = -lGLU -lGL -lglut -lm

SOURCES = src/main.c src/Element.c src/Ankle.c src/Arm.c src/Breast.c src/Calf.c src/Chair.c src/Elbow.c src/Face.c src/Finger1.c src/Finger2.c src/Finger3.c src/Finger4.c src/Finger5.c src/Foot.c src/Forearm.c src/Hair.c src/Hand.c src/Head.c src/Hip.c src/Knee.c src/Thigh.c src/Neck.c src/Shoulder.c src/Waist.c src/Wrist.c src/Pelvis.c
OBJS    = $(SOURCES:.c=.o)

all : $(SOURCES) IG

IG : $(OBJS)
	$(CC) $(OBJS) -o $@ $(LDFLAGS)

*.c.o :
	$(CC) $(LDFLAGS) $< -o $@

clean:
	rm $(OBJS) IG