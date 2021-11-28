CC=gcc
CFLAGS=-Wall -g

.PHONY: all clean valgrind

all: bin bin/HuffmanDriver

bin: 
	mkdir -p bin

bin/HuffmanDriver: bin/HuffmanDriver.o bin/Huffman.o ../ListADT/bin/list.o \
					../PriorityQueueADT/bin/pqueue.o \
					../BinaryTreeADT/bin/binarytree.o
	${CC} ${CFLAGS} bin/HuffmanDriver.o bin/Huffman.o ../ListADT/bin/list.o \
					../PriorityQueueADT/bin/pqueue.o \
					../BinaryTreeADT/bin/binarytree.o \
					-o bin/HuffmanDriver

bin/HuffmanDriver.o: src/HuffmanDriver.c include/Huffman.h 
	${CC} ${CFLAGS} -c src/HuffmanDriver.c -o bin/HuffmanDriver.o

bin/Huffman.o: src/Huffman.c include/Huffman.h ../ListADT/include/list.h \
				../PriorityQueueADT/include/pqueue.h ../BinaryTreeADT/include/binarytree.h
	${CC} ${CFLAGS} -c src/Huffman.c -o bin/Huffman.o

../ListADT/bin/list.o:
	cd ../ListADT; make bin/list.o
	
../PriorityQueueADT/bin/pqueue.o:
	cd ../PriorityQueueADT; make bin/pqueue.o
	
../BinaryTreeADT/bin/binarytree.o:
	cd ../BinaryTreeADT; make bin/binarytree.o
	
valgrind: bin/HuffmanDriver
	valgrind -v --leak-check=yes --track-origins=yes --leak-check=full --show-leak-kinds=all bin/HuffmanDriver

clean:
	rm -rf bin/*.o bin/HuffmanDriver