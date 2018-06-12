#include <individuo.h>
#include <iostream>

using namespace std;

individuo::individuo()
:qualities()
{
  result = false;
}

individuo::~individuo() {
  qualities.clear();
}


individuo::individuo(const string &data, const typename individuo::size_type &nQualities) {

  typename individuo::size_type start = 0, fin, i;
  string quality;

  qualities.resize(nQualities - 1);


  for (i = 0; i < nQualities - 1; ++i) {
    fin = data.find(",", start);
    quality = data.substr(start, fin - start);
    qualities[i] = atof(quality.c_str());

    start = fin + 1;
  }

  result = (data[start] == '1');

}

individuo::individuo(const individuo &I) {
  qualities = I.qualities;
  result = I.result;
}

individuo &individuo::operator=(const individuo &i) {
  if(&i != this) {
    qualities = i.qualities;
    result = i.result;
  }

  return *this;
}

bool individuo::operator==(const individuo &I) const {
  if(result != I.getResult()) return false;
  if(getSize() != I.getSize()) return false;

  typename individuo::size_type i = 0;
  bool result = true;

  do {
    result = result &&  (qualities[i] == I.qualities[i]);
    ++i;
  }while(result && i < getSize());

  return result;
}

bool individuo::getResult() const {
  return result;
}

typename individuo::size_type individuo::getSize() const {
  return qualities.size();
}

typename individuo::value_type& individuo::getQuality(const size_type &n) {
  return qualities[n];
}

const individuo::value_type &individuo::getQuality(const size_type &n) const {
  return qualities[n];
}
