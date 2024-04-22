.PHONY: all
all: hello-first hello-second

hello.o: hello.c hello.h
	gcc -c -o hello.o hello.c

hello-flexible.o: hello-flexible.c hello-flexible.h
	gcc -c -o hello-flexible.o hello-flexible.c

libhello.a: hello.o hello-flexible.o
	ar cq libhello.a hello.o hello-flexible.o

hello-first.o: hello-first.c
	gcc -c -o hello-first.o hello-first.c

hello-second.o: hello-second.c
	gcc -c -o hello-second.o hello-second.c 

hello-first: hello-first.o libhello.a
	gcc -o hello-first hello-first.o libhello.a

hello-second: hello-second.o libhello.a
	gcc -o hello-second hello-second.o libhello.a

.PHONY: clean
clean:
	rm hello-first hello-second *.o libhello.a

test:
