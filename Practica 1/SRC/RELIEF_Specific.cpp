#include <RELIEF_Specific.h>

pair<vector<individuo::value_type>, pair<float, float>> reliefAprendizaje(const muestra &training) {
  vector<typename individuo::value_type> solucion(training.getIndividuo(0).getSize(), 0);
  pair<float, float> coste_solucion;
  typename muestra::size_type i;
  typename individuo::size_type j;
  typename individuo::value_type quality_enemigo, quality_amigo, quality, maximo;
  individuo mejor_amigo, peor_enemigo;
  individuo aux;


  for(i = 0; i < training.getSize(); ++i) {
    aux = training.getIndividuo(i);
    mejor_amigo = Amigo(aux, training);
    peor_enemigo = Enemigo(aux, training);



    for(j = 0; j < solucion.size(); ++j) {
      quality_enemigo = peor_enemigo.getQuality(j);
      quality_amigo = mejor_amigo.getQuality(j);

      quality = aux.getQuality(j);
      solucion[j] += (sqrt((quality-quality_enemigo) * (quality-quality_enemigo)) - sqrt((quality-quality_amigo) * (quality-quality_amigo)));
    }
  }

  maximo = solucion[0];
  for(j = 1; j < solucion.size(); ++j) {
    solucion[j];
    if(solucion[j] > maximo) maximo = solucion[j];
  }


  for(j = 0; j < solucion.size(); ++j) {
    if(solucion[j] < 0) solucion[j] = 0;
    else if (solucion[j] > 1) solucion[j] /= maximo;
  }

  coste_solucion = fObjetivo(solucion, training);

  return pair<vector<individuo::value_type>, pair<float, float>>(solucion, coste_solucion);

}

individuo Enemigo(const individuo &i1,  const muestra &training) {
  static vector<typename individuo::value_type> w(i1.getSize(), 1);
  typename muestra::size_type i = 0;
  individuo  aux, enemigo;
  typename individuo::value_type distancia, distancia_maxima;

  while(i1.getResult() == training.getIndividuo(i).getResult()) {
    ++i;
  }

  enemigo = training.getIndividuo(i);
  distancia_maxima = distanciaIndividuos(i1, enemigo, w);

  for(i = i + 1; i < training.getSize(); ++i) {
      aux = training.getIndividuo(i);
      distancia = distanciaIndividuos(i1, aux, w);

      if(distancia >= distancia_maxima) {
        distancia_maxima = distancia;
        enemigo = aux;
      }
  }

  return enemigo;
}

individuo Amigo(const individuo &i1,  const muestra &training) {
  static vector<typename individuo::value_type> w(i1.getSize(), 1);
  typename muestra::size_type i = 0;
  individuo aux, amigo;
  muestra leave = training.leaveOneOut(i1);
  typename individuo::value_type distancia, distancia_minima;

  while(i1.getResult() != leave.getIndividuo(i).getResult()) {
    ++i;
  }

  amigo = leave.getIndividuo(i);
  distancia_minima = distanciaIndividuos(i1, amigo, w);

  for(i = i + 1; i < leave.getSize(); ++i) {
      aux = leave.getIndividuo(i);
      distancia = distanciaIndividuos(i1, aux, w);

      if(distancia <= distancia_minima) {
        distancia_minima = distancia;
        amigo = aux;
      }
  }

  return amigo;
}
