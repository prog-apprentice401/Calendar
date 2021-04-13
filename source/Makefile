CFLAGS=-Wall
COMPILE_FILES=main.o date.o utils.o outputs.o inputs.o menu.o

all: main.o inputs.o outputs.o date.o utils.o menu.o
	gcc $(CFLAGS) $(COMPILE_FILES) -o Calendar

main.o: main.c
	gcc $(CFLAGS) -c main.c

inputs.o: inputs.c inputs.h
	gcc $(CFLAGS) -c inputs.c

outputs.o: outputs.c outputs.h
	gcc $(CFLAGS) -c outputs.c

date.o: date.c date.h
	gcc $(CFLAGS) -c date.c

utils.o: utils.c utils.h
	gcc $(CFLAGS) -c utils.c

menu.o: menu.c menu.h
	gcc $(CFLAGS) -c menu.c

clean:
	rm *.o Calendar

rmevents:
	rm *.log
