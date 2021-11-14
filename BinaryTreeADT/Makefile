CC=gcc
CFLAGS=-Wall -g

.PHONY: all clean valgrind

all: bin bin/bstdriver

bin: 
	mkdir -p bin

bin/bstdriver: bin/bstdriver.o bin/bst.o ../ListADT/bin/list.o ../PriorityQueueADT/bin/pqueue.o
	${CC} ${CFLAGS} bin/bstdriver.o bin/bst.o ../ListADT/bin/list.o ../PriorityQueueADT/bin/pqueue.o -o bin/bstdriver

bin/bstdriver.o: src/bstdriver.c include/bst.h 
	${CC} ${CFLAGS} -c src/bstdriver.c -o bin/bstdriver.o

bin/bst.o: src/bst.c include/bst.h ../ListADT/include/list.h ../PriorirtyQueueADT/include/pqueue.h
	${CC} ${CFLAGS} -c src/bst.c -o bin/bst.o

../ListADT/bin/list.o:
	cd ../ListADT; make bin/list.o
	
../PriorityQueueADT/bin/pqueue.o:
	cd ../PriorityQueueADT; make bin/pqueue.o
	
valgrind: bin/bstdriver
	valgrind -v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all bin/bstdriver

clean:
	rm -rf bin/*.o bin/bstdriver