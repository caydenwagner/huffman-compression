CC=gcc
CFLAGS=-Wall -g

.PHONY: all clean valgrind

all: bin bin/binarytreedriver

bin: 
	mkdir -p bin

bin/binarytreedriver: bin/binarytreedriver.o bin/binarytree.o \
						../ListADT/bin/list.o \
						../PriorityQueueADT/bin/pqueue.o
	${CC} ${CFLAGS} bin/binarytreedriver.o bin/binarytree.o ../ListADT/bin/list.o \
						../PriorityQueueADT/bin/pqueue.o -o bin/binarytreedriver

bin/binarytreedriver.o: src/binarytreedriver.c include/binarytree.h 
	${CC} ${CFLAGS} -c src/binarytreedriver.c -o bin/binarytreedriver.o

bin/binarytree.o: src/binarytree.c include/binarytree.h ../ListADT/include/list.h \
					../PriorityQueueADT/include/pqueue.h
	${CC} ${CFLAGS} -c src/binarytree.c -o bin/binarytree.o

../ListADT/bin/list.o:
	cd ../ListADT; make bin/list.o
	
../PriorityQueueADT/bin/pqueue.o:
	cd ../PriorityQueueADT; make bin/pqueue.o
	
valgrind: bin/binarytreedriver
	valgrind -v --leak-check=yes --track-origins=yes --leak-check=full \
	--show-leak-kinds=all bin/binarytreedriver

clean:
	rm -rf bin/*.o bin/binarytreedriver