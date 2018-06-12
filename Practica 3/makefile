SRC = ./FUENTES
BIN = ./BIN
INC = ./INC
OBJ = ./OBJ
DOC = ./DOC
CPP = g++ -std=c++11 -Wall -O3 -march=native -g

all: $(BIN)/AGG_BLX $(BIN)/AM_10_01mej $(BIN)/RELIEF $(BIN)/LocalSearch $(BIN)/Clasificador1NN $(BIN)/SimulatedAnneling $(BIN)/IterativeLocalSearch $(BIN)/DiferentialEvolutionRand $(BIN)/DiferentialEvolutionBest

$(BIN)/AGG_BLX: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/specific_genetic.o  $(OBJ)/clasificador.o $(OBJ)/AGG_BLX.o $(OBJ)/common_gmetic.o
	$(CPP) -o $(BIN)/AGG_BLX $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/common_gmetic.o $(OBJ)/specific_genetic.o $(OBJ)/clasificador.o $(OBJ)/AGG_BLX.o

$(BIN)/AM_10_01mej: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/AM_10_01mej.o $(OBJ)/common_gmetic.o $(OBJ)/BLmemetic_Specific.o $(OBJ)/BL_Specific.o
	$(CPP) -o $(BIN)/AM_10_01mej $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/common_gmetic.o $(OBJ)/clasificador.o $(OBJ)/BLmemetic_Specific.o $(OBJ)/BL_Specific.o $(OBJ)/AM_10_01mej.o

$(BIN)/LocalSearch: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/BL_Specific.o  $(OBJ)/clasificador.o $(OBJ)/LocalSearch.o
	$(CPP) -o $(BIN)/LocalSearch $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/BL_Specific.o $(OBJ)/clasificador.o $(OBJ)/LocalSearch.o

$(BIN)/RELIEF: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/RELIEF_Specific.o $(OBJ)/clasificador.o  $(OBJ)/RELIEF.o
	$(CPP) -o $(BIN)/RELIEF $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/RELIEF_Specific.o $(OBJ)/clasificador.o $(OBJ)/RELIEF.o

$(BIN)/Clasificador1NN: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o  $(OBJ)/Clasificador1NN.o
	$(CPP) -o $(BIN)/Clasificador1NN $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/Clasificador1NN.o

$(BIN)/SimulatedAnneling: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/SA_specific.o $(OBJ)/SimulatedAnneling.o $(OBJ)/BL_Specific.o
	$(CPP) -o $(BIN)/SimulatedAnneling $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/SA_specific.o $(OBJ)/SimulatedAnneling.o $(OBJ)/BL_Specific.o

$(BIN)/IterativeLocalSearch: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/SA_specific.o $(OBJ)/IterativeLocalSearch.o $(OBJ)/ILS_specific.o
	$(CPP) -o $(BIN)/IterativeLocalSearch $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/SA_specific.o $(OBJ)/IterativeLocalSearch.o $(OBJ)/ILS_specific.o

$(BIN)/DiferentialEvolutionRand: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/DE_specific.o $(OBJ)/DiferentialEvolutionRand.o  $(OBJ)/common_gmetic.o
	$(CPP) -o $(BIN)/DiferentialEvolutionRand $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/DE_specific.o $(OBJ)/DiferentialEvolutionRand.o  $(OBJ)/common_gmetic.o

$(BIN)/DiferentialEvolutionBest: $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/DE_specific.o $(OBJ)/DiferentialEvolutionBest.o  $(OBJ)/common_gmetic.o
	$(CPP) -o $(BIN)/DiferentialEvolutionBest $(OBJ)/muestra.o $(OBJ)/individuo.o $(OBJ)/clasificador.o $(OBJ)/DE_specific.o $(OBJ)/DiferentialEvolutionBest.o  $(OBJ)/common_gmetic.o


$(OBJ)/IterativeLocalSearch.o: $(SRC)/IterativeLocalSearch.cpp
	$(CPP) -I$(INC) -c $(SRC)/IterativeLocalSearch.cpp -o $(OBJ)/IterativeLocalSearch.o

$(OBJ)/DiferentialEvolutionRand.o: $(SRC)/DiferentialEvolutionRand.cpp
	$(CPP) -I$(INC) -c $(SRC)/DiferentialEvolutionRand.cpp -o $(OBJ)/DiferentialEvolutionRand.o

$(OBJ)/DiferentialEvolutionBest.o: $(SRC)/DiferentialEvolutionBest.cpp
	$(CPP) -I$(INC) -c $(SRC)/DiferentialEvolutionBest.cpp -o $(OBJ)/DiferentialEvolutionBest.o

$(OBJ)/DE_specific.o: $(SRC)/DE_specific.cpp
	$(CPP) -I$(INC) -c $(SRC)/DE_specific.cpp -o $(OBJ)/DE_specific.o

$(OBJ)/ILS_specific.o: $(SRC)/ILS_specific.cpp
	$(CPP) -I$(INC) -c $(SRC)/ILS_specific.cpp -o $(OBJ)/ILS_specific.o

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

$(OBJ)/SA_specific.o: $(SRC)/SA_specific.cpp
	$(CPP) -I$(INC) -c $(SRC)/SA_specific.cpp -o $(OBJ)/SA_specific.o

$(OBJ)/SimulatedAnneling.o: $(SRC)/SimulatedAnneling.cpp
	$(CPP) -I$(INC) -c $(SRC)/SimulatedAnneling.cpp -o $(OBJ)/SimulatedAnneling.o

$(OBJ)/AM_10_01mej.o: $(SRC)/AM_10_01mej.cpp
	$(CPP) -I$(INC) -c $(SRC)/AM_10_01mej.cpp -o $(OBJ)/AM_10_01mej.o

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
