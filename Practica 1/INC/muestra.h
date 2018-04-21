#ifndef _MUESTRA_H_
#define _MUESTRA_H_

#include <individuo.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

class muestra {
  public:
    typedef unsigned int size_type;
    typedef float probability_type;

    muestra();
    ~muestra();
    muestra(const muestra &M);
    muestra(const char* const name);
    muestra(const vector<muestra> &V);

    muestra& operator=(const muestra &m);

    vector<muestra> subMuestras(const size_type &n) const;
    individuo getIndividuo(const size_type &n) const;
    size_type getSize() const;
    probability_type getPositiveProbability() const;
    probability_type getNegativeProbability() const;

    muestra leaveOneOut(const individuo &I) const;

    vector<individuo::value_type> getMaxValue() const;
    vector<individuo::value_type> getMinValue() const;

  private:
    void Normalize();

    void setMaxValue();
    void setMinValue();

    muestra(const vector<individuo> &P, const vector<individuo> &N);
    vector<individuo> positive;
    vector<individuo> negative;
    vector<individuo::value_type> max_value;
    vector<individuo::value_type> min_value;

    size_type size;
    probability_type p_positive;



};

#endif
