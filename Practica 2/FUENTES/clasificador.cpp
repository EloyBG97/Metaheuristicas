#include <clasificador.h>

pair<float, float> fObjetivo(const vector<individuo::value_type>&W, const muestra &training) {
  return pair<float, float>(tasaClas(W, training),tasaRed(W, 0.2));
}

float tasaClas(const vector<individuo::value_type>&W, const muestra &training) {
  typename muestra::size_type bien_training;

  bien_training = validacionTraining(W, training);

  return (bien_training / (float) training.getSize()) * 100;

}

float tasaRed(const vector<individuo::value_type>&W, const float &tasa) {
  typename  vector<individuo::value_type>::size_type i, j = 0;

  for(i = 0; i < W.size(); ++i)
    j += (W[i] < tasa);

  return (j / (float) W.size()) * 100;
}

muestra::size_type validacionTraining(const vector<individuo::value_type>&W, const muestra &training) {
    typename muestra::size_type i, bien_clasificados = 0;

    muestra leave;
    individuo i1;

    for(i = 0; i < training.getSize(); ++i) {
        i1 = training.getIndividuo(i);

        leave = training.leaveOneOut(i1);

        bien_clasificados += (clasifica(W, leave, i1) == i1.getResult());
    }

    return bien_clasificados;
}


muestra::size_type validacionTest(const vector<individuo::value_type>&W, const muestra &training, const muestra &test) {
      typename muestra::size_type i, bien_clasificados = 0;
      individuo i1;

      for(i = 0; i < test.getSize(); ++i) {
          i1 = test.getIndividuo(i);

          bien_clasificados += (clasifica(W, training, i1) == i1.getResult());
      }

      return bien_clasificados;
}


bool clasifica(const vector<individuo::value_type>&W, const muestra &conocimiento, const individuo &I) {
  typename muestra::size_type i;
  individuo min, aux;
  typename individuo::value_type dist_min, dist_aux;

  min = conocimiento.getIndividuo(0);
  dist_min = distanciaIndividuos(min, I, W);

  for(i = 1; i < conocimiento.getSize(); ++i) {
    aux = conocimiento.getIndividuo(i);
    dist_aux = distanciaIndividuos(aux, I, W);

    if(dist_min > dist_aux) {
      dist_min = dist_aux;
      min = aux;
    }
  }

  return min.getResult();
}

individuo::value_type distanciaIndividuos(const individuo &I1, const individuo &I2, const vector<individuo::value_type>&W) {
  typename individuo::value_type distancia = 0;
  typename individuo::size_type i;
  typename individuo::value_type aux;

  for(i = 0; i < I1.getSize(); ++i) {
    aux = I1.getQuality(i) - I2.getQuality(i);
    distancia += W[i] * aux * aux;
  }

  return sqrt(distancia);
}
