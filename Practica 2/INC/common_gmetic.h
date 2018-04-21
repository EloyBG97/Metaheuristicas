#ifndef _COMMON_GMETIC_H_
#define _COMMON_GMETIC_H_

#include <clasificador.h>
#include <utility>
#include <set>

using namespace std;

typedef pair<vector<individuo::value_type>, pair<float, float>> individuo_genetico;

class torneo_binario {
	public:
		bool operator()(const individuo_genetico & I1, const individuo_genetico & I2);
};


multiset<individuo_genetico, torneo_binario> StartPopulation(const muestra &Tr, const muestra &Ts, const unsigned int & seed, const unsigned int M);

multiset<individuo_genetico, torneo_binario> SeleccionarEstacionario(const multiset<individuo_genetico, torneo_binario> & P, const unsigned int & seed);
multiset<individuo_genetico, torneo_binario> SeleccionarGeneracional(const multiset<individuo_genetico, torneo_binario> & P, const unsigned int & N);

//remplazo
template<bool conelitismo = false>
void Remplazo(multiset<individuo_genetico, torneo_binario> & P, multiset<individuo_genetico, torneo_binario> & R);

void RemplazoElitismo(multiset<individuo_genetico, torneo_binario> & P, const multiset<individuo_genetico, torneo_binario> & R);

//Cruce
individuo_genetico CruceBLX(const pair<individuo_genetico, individuo_genetico> & C, const muestra &Tr, const muestra &Ts, const unsigned int & seed);
individuo_genetico CruceMean(const pair<individuo_genetico, individuo_genetico> & C, const muestra &Tr, const muestra &Ts);

//Mutacion
bool Mutacion(individuo_genetico & I, const muestra & Tr, const muestra & Ts, const unsigned int & seed);

//AUX
vector<pair<individuo_genetico, individuo_genetico>> MakeCouple(const multiset<individuo_genetico, torneo_binario> & P,  const unsigned int & seed, const unsigned int & n_couples);

#include <common_gmetic.hxx>
#endif
