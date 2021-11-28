CC=gcc
CFLAGS=-Wall -g

.PHONY: all clean valgrind

all: bin bin/huffmandriver

bin: 
	mkdir -p bin

bin/huffmandriver: bin/huffmandriver.o bin/huffman.o ../ListADT/bin/list.o \
					../PriorityQueueADT/bin/pqueue.o \
					../BinaryTreeADT/bin/binarytree.o
	${CC} ${CFLAGS} bin/huffmandriver.o bin/huffman.o ../ListADT/bin/list.o \
					../PriorityQueueADT/bin/pqueue.o \
					../BinaryTreeADT/bin/binarytree.o \
					-o bin/huffmandriver

bin/huffmandriver.o: src/huffmandriver.c include/huffman.h 
	${CC} ${CFLAGS} -c src/huffmandriver.c -o bin/huffmandriver.o

bin/huffman.o: src/huffman.c include/huffman.h ../ListADT/include/list.h \
				../PriorityQueueADT/include/pqueue.h ../BinaryTreeADT/include/binarytree.h
	${CC} ${CFLAGS} -c src/huffman.c -o bin/huffman.o

../ListADT/bin/list.o:
	cd ../ListADT; make bin/list.o
	
../PriorityQueueADT/bin/pqueue.o:
	cd ../PriorityQueueADT; make bin/pqueue.o
	
../BinaryTreeADT/bin/binarytree.o:
	cd ../BinaryTreeADT; make bin/binarytree.o
	
valgrind: bin/huffmandriver
	valgrind -v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all bin/huffmandriver

clean:
	rm -rf bin/*.o bin/huffmandriver