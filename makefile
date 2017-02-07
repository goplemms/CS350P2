prog2tree: simplefork.o option_parse.o
	gcc simplefork.o option_parse.o -o prog2tree
simplefork.o: simplefork.c option_parse.c
	gcc -Wall -c simplefork.c option_parse.c
option_parse.o: option_parse.c
	gcc -Wall -c option_parse.c
clean:
	rm *.o prog2tree
celan: clean

submit:
	mkdir Prog2Song_isong
	cp {option_parse.h,option_parse.c,simplefork.c,makefile} Prog2Song_isong
	tar cvvf Prog2Song_isong.tar Prog2Song_isong
	gzip Prog2Song_isong.tar
	mv Prog2Song_isong.tar.gz Prog2Song_isong.tgz


