#include <BL_Specific.h>
#include <iostream>

pair<vector<individuo::value_type>, pair<float, float>> BusquedaLocalAprendizaje(const muestra &training, const muestra &test, const unsigned int & seed) {
  static default_random_engine generator(seed);
  static uniform_real_distribution<typename individuo::value_type> distribution(0,1);

  vector<typename individuo::value_type> solucion(training.getIndividuo(0).getSize());

  vector<typename individuo::value_type> aux(solucion.size());
  typename individuo::size_type i, j ;
  pair<float, float> coste_aux_p, coste_solucion_p;
  float coste_aux, coste_solucion;
  typename individuo::size_type n_caracteristicas = training.getIndividuo(0).getSize();
  unsigned int n_ejecuciones =  0;

  for(j = 0; j < solucion.size();++j){
    solucion[j] = distribution(generator);
  }


  do {
      i = 0;

      coste_solucion_p = fObjetivo(solucion,training,test);
      coste_solucion = (coste_solucion_p.first + coste_solucion_p.second) * 0.5;


      do {
        aux = generarVecino(solucion,i % n_caracteristicas, i);

        coste_aux_p = fObjetivo(aux,training,test);
        coste_aux = (coste_aux_p.first + coste_aux_p.second) * 0.5;

        ++i;

      } while ((coste_aux <= coste_solucion) & (i < 20* n_caracteristicas));

      if(coste_aux > coste_solucion) {
        solucion = aux;
        coste_solucion_p = coste_aux_p;
      }

      ++n_ejecuciones;

    }while((coste_aux > coste_solucion) & (n_ejecuciones < 15000));


  return pair<vector<typename individuo::value_type>, pair<float, float>>(solucion, coste_solucion_p);
}


vector<individuo::value_type> generarVecino(vector<individuo::value_type> W, const unsigned int &i, const unsigned int &seed) {
   static default_random_engine generator(seed);
   static normal_distribution<typename individuo::value_type> distribution(1.0 , 0.3);

    W[i] += distribution(generator);
    if(W[i] < 0) W[i] = 0;
    else if(W[i] > 1) W[i] = 1;


  return W;
}
