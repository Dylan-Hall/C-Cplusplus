all: process_image

process_image: main.o calculations.o sizes.o
	@echo "process_image"
	gcc main.o calculations.o sizes.o -o process -L../libs/ -I../include/ -lm -lsize -lc

main.o: main.c
	@echo "main.o"
	gcc -c main.c -I ../include
   
calculations.o: calculations.c
	@echo "calculations.o"
	gcc -c calculations.c -I../include
	ar cq ../libs/libc.a calculations.o
   
sizes.o: sizes.c
	@echo "sizes.o"
	gcc -c sizes.c -I../include
	ar cq ../libs/libsize.a sizes.o

clean:   
	rm *o process_image ../libs/libsize.a libc.a 
