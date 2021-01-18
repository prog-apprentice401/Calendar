all: main.o date.o utils.o
	gcc -Wall main.c date.c -o Calendar

main.o: main.c
	gcc -Wall -c main.c

date.o: date.c date.h
	gcc -Wall -c date.c

utils.o: utils.c utils.h
	gcc -Wall -c utils.c

clean:
	rm *.o
