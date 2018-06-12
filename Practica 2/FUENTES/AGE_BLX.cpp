#include <iostream>
#include <cstdlib>
#include <individuo.h>
#include <muestra.h>
#include <ctime>
#include <specific_genetic.h>
#include <chrono>

#define MOSTRAR_SOLUCION 0

using namespace std;
using namespace std::chrono;

int main(int argc, char **argv) {
  if(argc < 2) {
    cerr << "Uso: " << argv[0] << " <nombre_fichero> <seed_optional>" << endl;
    exit(EXIT_FAILURE);
  }

  const typename muestra::size_type N_PARTICIONES = 5;
  high_resolution_clock::time_point tantes,tdespues;
  vector<duration<double>> tiempo_transcurrido(N_PARTICIONES);

  unsigned int seed = (argc==3)?atoi(argv[2]):time(NULL);
  srand(seed);
  muestra test(argv[1]);

  vector<muestra> aux, submuestras = test.subMuestras(5);

  typename muestra::size_type i,j;
  typename  vector<muestra>::const_iterator it;

  vector<pair<vector<individuo::value_type>, pair<float, float>>> solucion(N_PARTICIONES);
  vector<float> tasa_training(N_PARTICIONES);

  for(i = 0; i < N_PARTICIONES; ++i) {
    aux = submuestras;

    it = submuestras.cbegin();
    test = *(it + i);

    submuestras.erase(it + i);
    muestra training(submuestras);

    tantes = high_resolution_clock::now();

    solucion[i] = AGE_BLX(training, seed);
    tdespues = high_resolution_clock::now();

    tiempo_transcurrido[i]  = duration_cast<duration<double> >(tdespues - tantes);

    

    for(j = 0; j < solucion[i].first.size(); ++j)
      if(solucion[i].first[j] < 0.2) solucion[i].first[j] = 0;

    tasa_training[i] = (validacionTraining(solucion[i].first, training) / (float) training.getSize()) * 100;

    solucion[i].second.first = (validacionTest(solucion[i].first, training, test) / (float) test.getSize()) * 100;


    submuestras = aux;
  }

  cout << seed;
  for( i = 0; i < N_PARTICIONES; ++i) {
    cout << "\nParticion " << i << ": " << endl;
    cout << "\tTiempo: " << tiempo_transcurrido[i].count() << endl;
    cout << "\tTasa Clasificacion Training: " << tasa_training[i] << endl;
    cout << "\tTasa Clasificacion Test: " << solucion[i].second.first << endl;
    cout << "\tTasa Reduccion: " << solucion[i].second.second << endl;
    cout << "\tAgregacion: " << solucion[i].second.first * 0.5 + solucion[i].second.second * 0.5 << endl;

    #if MOSTRAR_SOLUCION == 1
    typename muestra::size_type j;

    cout << "\tSolucion : {";

    for(j = 0; j < solucion[i].first.size(); ++j)
      cout << solucion[i].first[j] << " ";

    cout << "}" << endl << endl;
    #endif
  }



  exit(EXIT_SUCCESS);
}
