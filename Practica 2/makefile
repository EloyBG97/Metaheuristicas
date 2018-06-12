SRC = ./FUENTES
BIN = ./BIN
INC = ./INC
OBJ = ./OBJ
DOC = ./DOC
CPP = g++ -std=c++11 -Wall -O3 -march=native

all: $(BIN)/AGG_BLX $(BIN)/AGG_CA $(BIN)/AGE_BLX $(BIN)/AGE_CA $(BIN)/AM_10_01 $(BIN)/AM_10_1 $(BIN)/AM_10_01mej $(BIN)/RELIEF $(BIN)/LocalSearch $(BIN)/Clasificador1NN

$(BIN)/AGG_BLX: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/specific_genetic.o  $(OBJ)/clasificador.o $(OBJ)/AGG_BLX.o $(OBJ)/common_gmetic.o
	$(CPP) -o $(BIN)/AGG_BLX $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/common_gmetic.o $(OBJ)/specific_genetic.o $(OBJ)/clasificador.o $(OBJ)/AGG_BLX.o

$(BIN)/AGG_CA: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/specific_genetic.o  $(OBJ)/clasificador.o $(OBJ)/AGG_CA.o $(OBJ)/common_gmetic.o
	$(CPP) -o $(BIN)/AGG_CA $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/common_gmetic.o $(OBJ)/specific_genetic.o $(OBJ)/clasificador.o $(OBJ)/AGG_CA.o

$(BIN)/AGE_BLX: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/specific_genetic.o  $(OBJ)/clasificador.o $(OBJ)/AGE_BLX.o $(OBJ)/common_gmetic.o
	$(CPP) -o $(BIN)/AGE_BLX $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/common_gmetic.o $(OBJ)/specific_genetic.o $(OBJ)/clasificador.o $(OBJ)/AGE_BLX.o

$(BIN)/AGE_CA: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/specific_genetic.o  $(OBJ)/clasificador.o $(OBJ)/AGE_CA.o $(OBJ)/common_gmetic.o
	$(CPP) -o $(BIN)/AGE_CA $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/common_gmetic.o $(OBJ)/specific_genetic.o $(OBJ)/clasificador.o $(OBJ)/AGE_CA.o

$(BIN)/AM_10_01: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/AM_10_01.o $(OBJ)/common_gmetic.o $(OBJ)/BLmemetic_Specific.o $(OBJ)/BL_Specific.o
	$(CPP) -o $(BIN)/AM_10_01 $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/common_gmetic.o $(OBJ)/clasificador.o $(OBJ)/BLmemetic_Specific.o $(OBJ)/BL_Specific.o $(OBJ)/AM_10_01.o

$(BIN)/AM_10_1: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/AM_10_1.o $(OBJ)/common_gmetic.o $(OBJ)/BLmemetic_Specific.o $(OBJ)/BL_Specific.o
	$(CPP) -o $(BIN)/AM_10_1 $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/common_gmetic.o  $(OBJ)/clasificador.o $(OBJ)/BLmemetic_Specific.o $(OBJ)/BL_Specific.o $(OBJ)/AM_10_1.o

$(BIN)/AM_10_01mej: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/AM_10_01mej.o $(OBJ)/common_gmetic.o $(OBJ)/BLmemetic_Specific.o $(OBJ)/BL_Specific.o
	$(CPP) -o $(BIN)/AM_10_01mej $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/common_gmetic.o $(OBJ)/clasificador.o $(OBJ)/BLmemetic_Specific.o $(OBJ)/BL_Specific.o $(OBJ)/AM_10_01mej.o

$(BIN)/LocalSearch: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/BL_Specific.o  $(OBJ)/clasificador.o $(OBJ)/LocalSearch.o
	$(CPP) -o $(BIN)/LocalSearch $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/BL_Specific.o $(OBJ)/clasificador.o $(OBJ)/LocalSearch.o

$(BIN)/RELIEF: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/RELIEF_Specific.o $(OBJ)/clasificador.o  $(OBJ)/RELIEF.o
	$(CPP) -o $(BIN)/RELIEF $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/RELIEF_Specific.o $(OBJ)/clasificador.o $(OBJ)/RELIEF.o

$(BIN)/Clasificador1NN: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o  $(OBJ)/Clasificador1NN.o
	$(CPP) -o $(BIN)/Clasificador1NN $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/Clasificador1NN.o


$(OBJ)/muestra.o: $(SRC)/muestra.cpp
	$(CPP) -I$(INC) -c $(SRC)/muestra.cpp -o $(OBJ)/muestra.o

$(OBJ)/individuo.o: $(SRC)/individuo.cpp
	$(CPP) -I$(INC) -c $(SRC)/individuo.cpp -o $(OBJ)/individuo.o

$(OBJ)/clasificador.o: $(SRC)/clasificador.cpp
	$(CPP) -I$(INC) -c $(SRC)/clasificador.cpp -o $(OBJ)/clasificador.o

$(OBJ)/specific_genetic.o: $(SRC)/specific_genetic.cpp
	$(CPP) -I$(INC) -c $(SRC)/specific_genetic.cpp -o $(OBJ)/specific_genetic.o

$(OBJ)/common_gmetic.o: $(SRC)/common_gmetic.cpp
	$(CPP) -I$(INC) -c $(SRC)/common_gmetic.cpp -o $(OBJ)/common_gmetic.o

$(OBJ)/BL_Specific.o: $(SRC)/BL_Specific.cpp
	$(CPP) -I$(INC) -c $(SRC)/BL_Specific.cpp -o $(OBJ)/BL_Specific.o

$(OBJ)/BLmemetic_Specific.o: $(SRC)/BLmemetic_Specific.cpp
	$(CPP) -I$(INC) -c $(SRC)/BLmemetic_Specific.cpp -o $(OBJ)/BLmemetic_Specific.o

$(OBJ)/RELIEF_Specific.o: $(SRC)/RELIEF_Specific.cpp
	$(CPP) -I$(INC) -c $(SRC)/RELIEF_Specific.cpp -o $(OBJ)/RELIEF_Specific.o

$(OBJ)/AGG_BLX.o: $(SRC)/AGG_BLX.cpp
	$(CPP) -I$(INC) -c $(SRC)/AGG_BLX.cpp -o $(OBJ)/AGG_BLX.o

$(OBJ)/AGG_CA.o: $(SRC)/AGG_CA.cpp
	$(CPP) -I$(INC) -c $(SRC)/AGG_CA.cpp -o $(OBJ)/AGG_CA.o

$(OBJ)/AGE_CA.o: $(SRC)/AGE_CA.cpp
	$(CPP) -I$(INC) -c $(SRC)/AGE_CA.cpp -o $(OBJ)/AGE_CA.o

$(OBJ)/AGE_BLX.o: $(SRC)/AGE_BLX.cpp
	$(CPP) -I$(INC) -c $(SRC)/AGE_BLX.cpp -o $(OBJ)/AGE_BLX.o

$(OBJ)/AM_10_01.o: $(SRC)/AM_10_01.cpp
	$(CPP) -I$(INC) -c $(SRC)/AM_10_01.cpp -o $(OBJ)/AM_10_01.o

$(OBJ)/AM_10_01mej.o: $(SRC)/AM_10_01mej.cpp
	$(CPP) -I$(INC) -c $(SRC)/AM_10_01mej.cpp -o $(OBJ)/AM_10_01mej.o

$(OBJ)/AM_10_1.o: $(SRC)/AM_10_1.cpp
	$(CPP) -I$(INC) -c $(SRC)/AM_10_1.cpp -o $(OBJ)/AM_10_1.o

$(OBJ)/LocalSearch.o: $(SRC)/LocalSearch.cpp
	$(CPP) -I$(INC) -c $(SRC)/LocalSearch.cpp -o $(OBJ)/LocalSearch.o

$(OBJ)/RELIEF.o: $(SRC)/RELIEF.cpp
	$(CPP) -I$(INC) -c $(SRC)/RELIEF.cpp -o $(OBJ)/RELIEF.o

$(OBJ)/Clasificador1NN.o: $(SRC)/Clasificador1NN.cpp
	$(CPP) -I$(INC) -c $(SRC)/Clasificador1NN.cpp -o $(OBJ)/Clasificador1NN.o



clean:
	rm $(OBJ)/*.o
	rm $(BIN)/*

doxy:
	doxygen $(DOC)/doxPractica.txt
	make -f latex/Makefile
