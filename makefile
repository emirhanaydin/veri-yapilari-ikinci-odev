CC=g++
BIN=bin
INCL=include
LIB=lib
SRC=src
EXE=main

all: make_dirs gen_libs compile run

make_dirs:
	IF NOT EXIST $(BIN) (MD "$(BIN)")
	IF NOT EXIST $(INCL) (MD "$(INCL)")
	IF NOT EXIST $(LIB) (MD "$(LIB)")
	IF NOT EXIST $(SRC) (MD "$(SRC)")

gen_libs: test.o sayi.o dugum.o gezici.o

compile:
	$(CC) $(LIB)/test.o $(LIB)/sayi.o $(LIB)/dugum.o $(LIB)/gezici.o -o $(BIN)/$(EXE)
	
run: 
	$(BIN)/$(EXE).exe

main.o:
	$(CC) -I $(INCL) -c $(SRC)/main.cpp -o $(LIB)/main.o

test.o:
	$(CC) -I $(INCL) -c $(SRC)/test.cpp -o $(LIB)/test.o
	
sayi.o:
	$(CC) -I $(INCL) -c $(SRC)/sayi.cpp -o $(LIB)/sayi.o
	
dugum.o:
	$(CC) -I $(INCL) -c $(SRC)/dugum.cpp -o $(LIB)/dugum.o
	
gezici.o:
	$(CC) -I $(INCL) -c $(SRC)/gezici.cpp -o $(LIB)/gezici.o

	
clean:
	DEL "$(BIN)\$(EXE).exe"
	DEL "$(LIB)\*.o"