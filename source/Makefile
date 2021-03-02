CFLAGS=-Wall
COMPILE_FILES=main.o events.o date.o utils.o outputs.o

all: main.o events.o outputs.o date.o utils.o
	gcc $(CFLAGS) $(COMPILE_FILES) -o Calendar

main.o: main.c
	gcc $(CFLAGS) -c main.c

events.o: events.c events.h
	gcc $(CFLAGs)-c events.c

outputs.o: outputs.c outputs.h
	gcc $(CFLAGS) -c outputs.c

date.o: date.c date.h
	gcc $(CFLAGS) -c date.c

utils.o: utils.c utils.h
	gcc $(CFLAGS) -c utils.c

clean:
	rm *.o Calendar
