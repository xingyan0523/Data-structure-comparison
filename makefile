all: testbench

testbench: testbench.c LL.o ARR.o BST.o HASH.o
	gcc testbench.c LL.o ARR.o BST.o HASH.o -o testbench

LL.o: Linked_list.c structure.h
	gcc -c Linked_list.c -o LL.o

ARR.o: Array.c structure.h
	gcc -c Array.c -o ARR.o

BST.o: BST.c structure.h
	gcc -c BST.c -o BST.o

HASH.o :Hash.c structure.h
	gcc -c Hash.c -o HASH.o

clean:
	rm testbench
	rm LL.o
	rm ARR.o
	rm BST.o
	rm HASH.o