#include <ILS_specific.h>

using namespace std;

vector<individuo::value_type> generarVecinoFuerte(vector<individuo::value_type> W, const unsigned int &t, const unsigned int &seed) {
    static default_random_engine generator(seed);
    static uniform_int_distribution<unsigned int> distribution_u(0, W.size() - 1);
    static normal_distribution<typename individuo::value_type> distribution(1.0 , 0.3);
    vector<unsigned int>  elegidos(t);
    unsigned int i = 0;
    unsigned int aux;

    for(i = 0; i < elegidos.size(); ++i) {
        do {
            aux = distribution_u(generator);
        } while(find(elegidos.cbegin(), elegidos.cend(), aux) != elegidos.cend());

        elegidos[i] = aux;

        W[aux] += distribution(generator);
        if(W[aux] < 0) W[i] = 0;
        else if(W[aux] > 1) W[i] = 1;

    }

  return W;
}

pair<vector<individuo::value_type>, pair<float, float>> LocalSearch(const vector<individuo::value_type> &W, const muestra &training, const unsigned int & seed) {
  static default_random_engine generator(seed);
  static uniform_real_distribution<typename individuo::value_type> distribution(0,1);

  vector<typename individuo::value_type> solucion(W);

  vector<typename individuo::value_type> aux(solucion.size());
  typename individuo::size_type i, j ;
  pair<float, float> coste_aux_p, coste_solucion_p;
  float coste_aux, coste_solucion;
  typename individuo::size_type n_caracteristicas = training.getIndividuo(0).getSize();
  unsigned int n_ejecuciones =  0;

  do {
      i = 0;

      coste_solucion_p = fObjetivo(solucion,training);
      coste_solucion = (coste_solucion_p.first + coste_solucion_p.second) * 0.5;


      do {
        aux = generarVecino(solucion,i % n_caracteristicas, seed);

        coste_aux_p = fObjetivo(aux,training);
        coste_aux = (coste_aux_p.first + coste_aux_p.second) * 0.5;

        ++i;

      } while ((coste_aux <= coste_solucion) & (i < 20* n_caracteristicas));

      if(coste_aux > coste_solucion) {
        solucion = aux;
        coste_solucion_p = coste_aux_p;
      }

      ++n_ejecuciones;

    }while((coste_aux > coste_solucion) & (n_ejecuciones < 1000));

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

pair<vector<individuo::value_type>, pair<float, float>> iterativeLocalSearch(const muestra &training, const unsigned int & seed) {
    static default_random_engine generator(seed);
    static uniform_real_distribution<typename individuo::value_type> distribution(0,1);

    pair<vector<individuo::value_type>, pair<float, float>> solucion_total, solucion_total_aux;

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

    solucion_total = LocalSearch(solucion, training, seed);

    for(unsigned int i = 0; i < 15; ++i) {
        aux = generarVecinoFuerte(solucion_total.first, 0.1 * training.getIndividuo(0).getSize(), seed);
        solucion_total_aux  = LocalSearch(aux, training, seed);

        if(solucion_total_aux.second.first + solucion_total_aux.second.second > solucion_total.second.first + solucion_total.second.second) {
            solucion_total =  solucion_total_aux;
        }
    }

    return solucion_total;
}
