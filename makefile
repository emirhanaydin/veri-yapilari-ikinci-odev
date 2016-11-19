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
	
gen_libs: main.o bagilliste.o dugum.o gezici.o islem.o konsol.o sayi.o secim.o

compile:
	$(CC) $(LIB)/main.o $(LIB)/bagilliste.o $(LIB)/dugum.o $(LIB)/gezici.o $(LIB)/islem.o $(LIB)/konsol.o $(LIB)/sayi.o $(LIB)/secim.o -o $(BIN)/$(EXE)

run:
	$(BIN)/$(EXE).exe
	
main.o:
	$(CC) -I $(INCL) -c $(SRC)/main.cpp -o $(LIB)/main.o
	
bagilliste.o:
	$(CC) -I $(INCL) -c $(SRC)/bagilliste.cpp -o $(LIB)/bagilliste.o
	
dugum.o:
	$(CC) -I $(INCL) -c $(SRC)/dugum.cpp -o $(LIB)/dugum.o
	
gezici.o:
	$(CC) -I $(INCL) -c $(SRC)/gezici.cpp -o $(LIB)/gezici.o
	
islem.o:
	$(CC) -I $(INCL) -c $(SRC)/islem.cpp -o $(LIB)/islem.o
	
konsol.o:
	$(CC) -I $(INCL) -c $(SRC)/konsol.cpp -o $(LIB)/konsol.o
	
sayi.o:
	$(CC) -I $(INCL) -c $(SRC)/sayi.cpp -o $(LIB)/sayi.o
	
secim.o:
	$(CC) -I $(INCL) -c $(SRC)/secim.cpp -o $(LIB)/secim.o
	
clear:
	DEL "$(BIN)\$(EXE).exe"
	DEL "$(LIB)\*.o"