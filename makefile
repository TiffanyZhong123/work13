all: work13.o
	gcc -o test work13.o
work13.o: work13.c
	gcc -c work13.c
run:
	./test
clean:
	rm *.o
	rm *.txt
