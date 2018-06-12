#include <muestra.h>
#include <cassert>

muestra::muestra() {
  size = 0;
  p_positive = 0;
}

muestra::~muestra() {
  positive.clear();
  negative.clear();
}

muestra::muestra(const muestra &m) {
  positive = m.positive;
  negative = m.negative;
  size = m.size;
  p_positive = m.p_positive;
}

muestra::muestra(const char* const name) {
  ifstream fich(name);
  typename muestra::size_type n_atributtes = 0;
  int aux;
  string str;

  do {
    getline(fich,str,'\n');
    aux = str.find("@attribute");
  } while(aux == string::npos);

  do {
    ++n_atributtes;
    getline(fich,str,'\n');
    aux = str.find("@attribute");
  } while(aux != string::npos);

  do {
    getline(fich,str,'\n');
    aux = str.find("@data");
  } while(aux == string::npos);

  getline(fich,str,'\n');

  while(!fich.eof()) {

    individuo i1(str, n_atributtes);

    if(i1.getResult())
      positive.push_back(i1);

    else
      negative.push_back(i1);

    getline(fich,str,'\n');

  }

  size = positive.size() + negative.size();
  p_positive = (typename muestra::probability_type) positive.size() / size;


  Normalize();

}


muestra::muestra(const vector<individuo> &P, const vector<individuo> &N) {
  positive = P;
  negative = N;

  size = P.size() + N.size();
  p_positive = (typename muestra::probability_type) positive.size() / size;

  Normalize();

}




muestra& muestra::operator=(const muestra &m) {
  if(&m != this) {
      positive = m.positive;
      negative = m.negative;
      size = m.size;
      p_positive = m.p_positive;
    }

    return *this;
}


/**********************************LEAVE-ONE-OUT*******************************/
muestra muestra::leaveOneOut(const individuo &I) const {
  muestra leave = *this;
  typename vector<individuo>::const_iterator it;

  if(I.getResult()) {
    it = find(leave.positive.cbegin(), leave.positive.cend(), I);
    if(it != leave.positive.cend()) leave.positive.erase(it);
  }

  else {
    it = find(leave.negative.cbegin(), leave.negative.cend(), I);
    if(it != leave.negative.cend()) leave.negative.erase(it);
  }

  --leave.size;
  leave.p_positive = (typename muestra::probability_type) leave.positive.size() / leave.size;

  return leave;
}

/***********************************TRABAJO DE SUBMUESTRAS **************************************/
//CON LOS INDIVIDUOS SOBRANTES SE AÑADE OTRA MUESTRA AL VECTOR
vector<muestra> muestra::subMuestras(const typename muestra::size_type &n) const {
  vector<muestra> aux(n + (positive.size() % n || negative.size() % n));
  vector<individuo> p_aux, n_aux;
  typename muestra::size_type i = 0;
  typename muestra::size_type j = 0;
  typename muestra::size_type k = 0;
  typename muestra::size_type z,y;
  typename muestra::size_type size_aux = size / n;

  for(i = 0; i < n; ++i) {
    p_aux.resize(size_aux * p_positive);
    n_aux.resize(size_aux * (1 - p_positive));
    y = z = 0;

    while(y < p_aux.size()) {
      p_aux[y] = positive[j];
      ++y;
      ++j;
    }

    while(z < n_aux.size()) {
      n_aux[z] = negative[k];
      ++z;
      ++k;
    }

    aux[i] = muestra(p_aux, n_aux);



    p_aux.clear();
    n_aux.clear();
  }

 if(aux.size() > n)  {
   i = 0;
   p_aux.resize(positive.size() - j);
   while(j < positive.size())
     p_aux[i++] = positive[j++];

     i = 0;
     n_aux.resize(negative.size() - k);

     while(k < negative.size())
     n_aux[i++] = negative[k++];



   aux[aux.size() - 1] = muestra(p_aux, n_aux);

 }


 return aux;

}

muestra::muestra(const vector<muestra> &V) {
  vector<individuo>::const_iterator it;
  typename vector<muestra>::size_type i;

  it = positive.cbegin();
  for(i = 0; i < V.size();  ++i) {
    positive.insert(it, V[i].positive.cbegin(), V[i].positive.cend() );
    it = positive.cbegin();
  }

  it = negative.cbegin();
  for(i = 0; i < V.size();  ++i) {
    negative.insert(it, V[i].negative.cbegin(), V[i].negative.cend() );
    it = negative.cbegin();
  }

  size = positive.size() + negative.size();
  p_positive = (typename muestra::probability_type) positive.size() / size;

  Normalize();
}

/************************************GETTER*******************************************/

individuo muestra::getIndividuo(const typename muestra::size_type &n) const {
  assert(n < size);
  return (n < positive.size())?positive[n]:negative[n % positive.size()];
}

typename muestra::size_type muestra::getSize() const {
  return size;
}

typename muestra::probability_type muestra::getPositiveProbability() const {
  return p_positive;
}

typename muestra::probability_type muestra::getNegativeProbability() const {
  return 1 - p_positive;
}

vector<individuo::value_type> muestra::getMaxValue() const {
  return max_value;
}
vector<individuo::value_type> muestra::getMinValue() const {
  return min_value;
}

/*******************************NORMALIZACION**************************************************************/

void muestra::Normalize(){
  typename individuo::size_type j;
  typename muestra::size_type i;
  typename individuo::value_type aux;
  individuo i1;

  setMaxValue();
  setMinValue();


  for( i = 0; i < positive.size(); ++i) {
    for( j = 0; j < positive[i].getSize(); ++j) {
      aux = (positive[i].getQuality(j) - min_value[j]) / (max_value[j] - min_value[j]);
      positive[i].getQuality(j) = aux;
    }

  }

  for( i = 0; i < negative.size(); ++i) {
    for( j = 0; j < negative[i].getSize(); ++j) {
      aux = (negative[i].getQuality(j) - min_value[j]) / (max_value[j] - min_value[j]);
      negative[i].getQuality(j) = aux;
    }

  }

}

void muestra::setMaxValue() {
  typename individuo::size_type i, limit = getIndividuo(0).getSize();
  typename muestra::size_type j;
  typename individuo::value_type aux;

  max_value.resize(limit);

  for (i = 0; i < limit; ++i) {
    max_value[i] = getIndividuo(0).getQuality(i);
  }



  for(j = 1; j < getSize(); ++j) {
    for (i = 0; i < limit; ++i) {
      aux = getIndividuo(j).getQuality(i);

      if(aux > max_value[i]) max_value[i] = aux;
    }
  }
}

void muestra::setMinValue() {
  typename individuo::size_type i, limit = getIndividuo(0).getSize();
  typename muestra::size_type j;
  typename individuo::value_type aux;

  min_value.resize(limit);

  for (i = 0; i <limit; ++i) {
    min_value[i] = getIndividuo(0).getQuality(i);
  }



  for(j = 1; j < getSize(); ++j) {
    for (i = 0; i < limit; ++i) {
      aux = getIndividuo(j).getQuality(i);

      if(aux < min_value[i]) min_value[i] = aux;
    }
  }
}
