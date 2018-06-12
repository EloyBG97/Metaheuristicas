#include <iostream>
#include <cstdlib>
#include <individuo.h>
#include <muestra.h>
#include <chrono>
#include <clasificador.h>

using namespace std;
using namespace std::chrono;


int main(int argc, char **argv) {
  if(argc < 2) {
    cerr << "Uso: " << argv[0] << " <nombre_fichero>" << endl;
    exit(EXIT_FAILURE);
  }

  const typename muestra::size_type N_PARTICIONES = 5;

  high_resolution_clock::time_point tantes,tdespues;
  vector<duration<double>> tiempo_transcurrido(N_PARTICIONES);

  muestra test(argv[1]);
  vector<muestra> aux, submuestras = test.subMuestras(5);

  typename muestra::size_type i;
  typename  vector<muestra>::const_iterator it;

  vector<pair<float, float>> solucion(N_PARTICIONES);
  const vector<typename individuo::value_type> W(test.getIndividuo(0).getSize(), 1);



  for(i = 0; i < N_PARTICIONES; ++i) {
    aux = submuestras;

    it = submuestras.cbegin();
    test = *(it + i);

    submuestras.erase(it + i);
    muestra training(submuestras);

    tantes = high_resolution_clock::now();
    solucion[i] = fObjetivo(W, training);
    tdespues = high_resolution_clock::now();

    tiempo_transcurrido[i]  = duration_cast<duration<double> >(tdespues - tantes);


    solucion[i].first = validacionTest(W, training, test);

    submuestras = aux;
  }

  for( i = 0; i < N_PARTICIONES; ++i) {
    cout << "\nParticion " << i << ": " << endl;
    cout << "\tTiempo: " << tiempo_transcurrido[i].count() << endl;
    cout << "\tTasa Clasificacion: " << solucion[i].first * 0.5 << endl;
    cout << "\tTasa Reduccion: " << solucion[i].second * 0.5 << endl;
    cout << "\tAgregacion: " << solucion[i].first * 0.5 + solucion[i].second * 0.5 << endl;
  }



  exit(EXIT_SUCCESS);
}
