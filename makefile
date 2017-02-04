prog2tree: simplefork.o
	gcc simplefork.o -o prog2tree
simplefork.o:	simplefork.c
	gcc -Wall -c simplefork.c
clean:
	rm *.o prog2tree
