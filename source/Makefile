CFLAGS=-Wall
COMPILE_FILES=main.o date.o utils.o outputs.o inputs.o events.o

all: $(COMPILE_FILES)
	gcc $(CFLAGS) $(COMPILE_FILES) -o Calendar

inputs.o: inputs.c inputs.h
	gcc $(CFLAGS) -c inputs.c

outputs.o: outputs.c outputs.h
	gcc $(CFLAGS) -c outputs.c

date.o: date.c date.h
	gcc $(CFLAGS) -c date.c

utils.o: utils.c utils.h
	gcc $(CFLAGS) -c utils.c

events.o: events.c events.h
	gcc $(CFLAGS) -c events.c

clean:
	rm *.o Calendar

rmevents:
	echo "" > Events.log
