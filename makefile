all: randfile.o
	gcc -o randfile randfile.o
randfile.o: randfile.c
	gcc -c randfile.c
run:
	./randfile
clean:
	rm *.o
	rm randfile
	rm writetarget.txt