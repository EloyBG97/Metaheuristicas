SRC = ./SRC
BIN = ./BIN
INC = ./INC
OBJ = ./OBJ
DOC = ./DOC
CPP = g++ -std=c++11 -Wall -O3

all: $(BIN)/AprendizajeRELIEFP1 $(BIN)/AprendizajeBLP1 $(BIN)/Clasificador1NN

$(BIN)/AprendizajeBLP1: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/BL_Specific.o  $(OBJ)/clasificador.o $(OBJ)/mainBL.o
	$(CPP) -o $(BIN)/AprendizajeBLP1 $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/BL_Specific.o $(OBJ)/clasificador.o $(OBJ)/mainBL.o

$(BIN)/AprendizajeRELIEFP1: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/RELIEF_Specific.o $(OBJ)/clasificador.o  $(OBJ)/mainRELIEF.o
	$(CPP) -o $(BIN)/AprendizajeRELIEFP1 $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/RELIEF_Specific.o $(OBJ)/clasificador.o $(OBJ)/mainRELIEF.o

$(BIN)/Clasificador1NN: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o  $(OBJ)/main1NN.o
	$(CPP) -o $(BIN)/Clasificador1NN $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/main1NN.o

$(OBJ)/muestra.o: $(SRC)/muestra.cpp
	$(CPP) -I$(INC) -c $(SRC)/muestra.cpp -o $(OBJ)/muestra.o

$(OBJ)/individuo.o: $(SRC)/individuo.cpp
	$(CPP) -I$(INC) -c $(SRC)/individuo.cpp -o $(OBJ)/individuo.o

$(OBJ)/clasificador.o: $(SRC)/clasificador.cpp
	$(CPP) -I$(INC) -c $(SRC)/clasificador.cpp -o $(OBJ)/clasificador.o

$(OBJ)/BL_Specific.o: $(SRC)/BL_Specific.cpp
	$(CPP) -I$(INC) -c $(SRC)/BL_Specific.cpp -o $(OBJ)/BL_Specific.o

$(OBJ)/RELIEF_Specific.o: $(SRC)/RELIEF_Specific.cpp
	$(CPP) -I$(INC) -c $(SRC)/RELIEF_Specific.cpp -o $(OBJ)/RELIEF_Specific.o

$(OBJ)/mainBL.o: $(SRC)/mainBL.cpp
	$(CPP) -I$(INC) -c $(SRC)/mainBL.cpp -o $(OBJ)/mainBL.o

$(OBJ)/mainRELIEF.o: $(SRC)/mainRELIEF.cpp
	$(CPP) -I$(INC) -c $(SRC)/mainRELIEF.cpp -o $(OBJ)/mainRELIEF.o

$(OBJ)/main1NN.o: $(SRC)/main1NN.cpp
	$(CPP) -I$(INC) -c $(SRC)/main1NN.cpp -o $(OBJ)/main1NN.o

clean:
	rm $(OBJ)/*.o
	mv $(BIN)/leeme.dat ./
	rm $(BIN)/*
	mv ./leeme.dat $(BIN)/

doxy:
	doxygen $(DOC)/doxPractica.txt
	make -f latex/Makefile
