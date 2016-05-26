GPP = g++11
CFLAGS = -std=c++11 -Wall -g -lpthread -lX11
BSTOBJECTS = BinNode.o BST.o BSTNode.o Dictionary.o main.o

main : BST.h main.o
	$(GPP) $(CFLAGS) -o $@ $^

%.o : %.cc
	$(GPP) -c $(CFLAGS) $^

#main.o : BST.h BSTNode.h Dictionary.h BinNode.h

#BinNode.o : BinNode.h

#BSTNode.o : BSTNode.h

#Dictionary.o : Dictionary.h

#BST.o : BST.h

clean:
	rm -f *.o *~ *% *# .#* *.h.gch

clean-all: clean
	rm -f bst