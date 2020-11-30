reverse: main.o revl.o revc.o revw.o
	gcc -o reverse main.o revl.o revc.o revw.o

main.o: main.c
	gcc -c main.c
revl.o: revl.c
	gcc -c revl.c
revc.o: revc.c
	gcc -c revc.c
revw.o: revw.c
	gcc -c revw.c

clean:
	rm reverse main.o revl.o revc.o revw.o
