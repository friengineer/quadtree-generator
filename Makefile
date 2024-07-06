
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/main

SRC= main.c buildTree.c writeTree.c valueTree.c tests.c

# generic build details

CC=      cc
COPT=    -g
CFLAGS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE)

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c treeStructure.h buildTree.h writeTree.h tests.h

buildTree.o: buildTree.c treeStructure.h buildTree.h

writeTree.o: writeTree.c treeStructure.h writeTree.h

valueTree.o: valueTree.c treeStructure.h valueTree.h buildTree.h

tests.o: tests.c treeStructure.h buildTree.h writeTree.h valueTree.h tests.h
