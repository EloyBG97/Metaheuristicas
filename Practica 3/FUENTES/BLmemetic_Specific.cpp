#include <BLmemetic_Specific.h>

pair<vector<individuo::value_type>, pair<float, float>> BusquedaLocalAprendizaje(vector<individuo::value_type> solucion, const muestra &training, const unsigned int & seed, unsigned int &n_ejecuciones) {
  static default_random_engine generator(seed);
  static uniform_real_distribution<typename individuo::value_type> distribution(0,1);

  vector<typename individuo::value_type> aux(solucion.size());
  typename individuo::size_type i ,k = 0;
  pair<float, float> coste_aux_p, coste_solucion_p;
  float coste_aux, coste_solucion;
  typename individuo::size_type n_caracteristicas = training.getIndividuo(0).getSize();
  
  n_ejecuciones =  0;

  do {
      i = 0;

      coste_solucion_p = fObjetivo(solucion,training);
      coste_solucion = (coste_solucion_p.first + coste_solucion_p.second) * 0.5;


      do {
        aux = generarVecino(solucion,i % n_caracteristicas, seed);

        coste_aux_p = fObjetivo(aux,training);
        coste_aux = (coste_aux_p.first + coste_aux_p.second) * 0.5;

        ++i;

      } while ((coste_aux <= coste_solucion) & (i < 2* n_caracteristicas));

      if(coste_aux > coste_solucion) {
        solucion = aux;
        coste_solucion_p = coste_aux_p;
      }

      ++n_ejecuciones;
      k += i;

    }while((coste_aux > coste_solucion) & (k < 2* n_caracteristicas));


  return pair<vector<typename individuo::value_type>, pair<float, float>>(solucion, coste_solucion_p);
}
