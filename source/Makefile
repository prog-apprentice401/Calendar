CFLAGS=-Wall
COMPILE_FILES=main.o date.o utils.o outputs.o logs.c

all: main.o outputs.o date.o utils.o logs.o
	gcc $(CFLAGS) $(COMPILE_FILES) -o Calendar

main.o: main.c
	gcc -Wall -c main.c

logs.o: logs.c logs.h
	gcc -Wall -c logs.c

outputs.o: outputs.c outputs.h
	gcc -Wall -c outputs.c

date.o: date.c date.h
	gcc -Wall -c date.c

utils.o: utils.c utils.h
	gcc -Wall -c utils.c

clean:
	rm *.o Calendar
