#include<specific_genetic.h>

using namespace std;

//Cruce BLX / Generacional
individuo_genetico AGG_BLX(const muestra &Tr, const muestra &Ts, const unsigned int & seed) {
	default_random_engine generator(seed);
	uniform_real_distribution<float> distribution(0, 1);
	multiset<individuo_genetico, torneo_binario> population;
	multiset<individuo_genetico, torneo_binario> remplazo;
	multiset<individuo_genetico, torneo_binario> padres;
	vector<pair<individuo_genetico, individuo_genetico>> couples;
	typename vector<pair<individuo_genetico, individuo_genetico>>::const_iterator couple;
	individuo_genetico hijo;
	const unsigned int SELECCIONADOS = 10;
	const float Pc = 0.7;
	bool muta;

	const size_t M = 30;
	const unsigned int N_EJECUCIONES = 15000;
	unsigned int  n_ejecuciones = 0;


	population = StartPopulation(Tr, Ts, seed, M);
	n_ejecuciones += M;

	do {

		padres = SeleccionarGeneracional(population, SELECCIONADOS);

		couples = MakeCouple(padres, seed, SELECCIONADOS * 0.5);



		for(couple = couples.cbegin(); couple != couples.cend(); ++couple) {

			if(distribution(generator) <= Pc) {
				hijo = CruceBLX(*couple, Tr, Ts,seed);
				++n_ejecuciones;

				muta = Mutacion(hijo, Tr, Ts, seed);
				n_ejecuciones += (muta)?1:0;



				remplazo.insert(hijo);

			}
		}


		Remplazo<true>(population, remplazo);

		remplazo.clear();
	} while(n_ejecuciones < N_EJECUCIONES);

	return *population.begin();
}

//Cruce Mean / Generacional
individuo_genetico AGG_CA(const muestra &Tr, const muestra &Ts, const unsigned int & seed) {
	default_random_engine generator(seed);
	uniform_real_distribution<float> distribution(0, 1);
	multiset<individuo_genetico, torneo_binario> population;
	multiset<individuo_genetico, torneo_binario> remplazo;
	multiset<individuo_genetico, torneo_binario> padres;
	vector<pair<individuo_genetico, individuo_genetico>> couples;
	typename vector<pair<individuo_genetico, individuo_genetico>>::const_iterator couple;
	individuo_genetico hijo;
	const float Pc = 0.7;
	const unsigned int SELECCIONADOS = 10;
	bool muta;

	const size_t M = 30;
	const unsigned int N_EJECUCIONES = 15000;
	unsigned int  n_ejecuciones = 0;


	population = StartPopulation(Tr, Ts, seed, M);
	n_ejecuciones += M;
	do {
		padres = SeleccionarGeneracional(population, SELECCIONADOS);

		couples = MakeCouple(padres, seed, SELECCIONADOS * 0.5);


		for(couple = couples.cbegin(); couple != couples.cend(); ++couple) {

			if(distribution(generator) <= Pc) {
				hijo = CruceMean(*couple, Tr, Ts);
				++n_ejecuciones;

				Mutacion(hijo, Tr, Ts, seed);
				n_ejecuciones += muta;

				remplazo.insert(hijo);

			}
		}


		Remplazo<true>(population, remplazo);

		remplazo.clear();
	} while(n_ejecuciones < N_EJECUCIONES);

	return *population.begin();
}

//Cruce BLX / Estacionario
individuo_genetico AGE_BLX(const muestra &Tr, const muestra &Ts, const unsigned int & seed) {
	multiset<individuo_genetico, torneo_binario> population;
	multiset<individuo_genetico, torneo_binario> remplazo;
	multiset<individuo_genetico, torneo_binario> padres;
	vector<pair<individuo_genetico, individuo_genetico>> couples;
	typename vector<pair<individuo_genetico, individuo_genetico>>::const_iterator couple;
	individuo_genetico hijo;
	bool muta;
	const unsigned int SELECCIONADOS = 10;
	const size_t M = 30;
	const unsigned int N_EJECUCIONES = 15000;
	unsigned int n_ejecuciones = 0;


	population = StartPopulation(Tr, Ts, seed, M);
	n_ejecuciones += M;
	do {
		padres = SeleccionarEstacionario(population, seed);

		couples = MakeCouple(padres, seed, SELECCIONADOS * 0.5);


		for(couple = couples.cbegin(); couple != couples.cend(); ++couple) {
				hijo = CruceBLX(*couple, Tr, Ts,seed);
				++n_ejecuciones;


				muta = Mutacion(hijo, Tr, Ts, seed);
				n_ejecuciones += muta;


				remplazo.insert(hijo);


		}


		Remplazo<false>(population, remplazo);

		remplazo.clear();
	} while(n_ejecuciones < N_EJECUCIONES);

	return *population.begin();
}

//Cruce Mean / Estacionario
individuo_genetico AGE_CA(const muestra &Tr, const muestra &Ts, const unsigned int & seed) {
	multiset<individuo_genetico, torneo_binario> population;
	multiset<individuo_genetico, torneo_binario> remplazo;
	multiset<individuo_genetico, torneo_binario> padres;
	vector<pair<individuo_genetico, individuo_genetico>> couples;
	typename vector<pair<individuo_genetico, individuo_genetico>>::const_iterator couple;
	individuo_genetico hijo;
	const unsigned int SELECCIONADOS = 10;
	bool muta;

	const size_t M = 30;
	const unsigned int N_EJECUCIONES = 15000;
	unsigned int  n_ejecuciones = 0;


	population = StartPopulation(Tr, Ts, seed, M);
	n_ejecuciones += M;

	do {
		padres = SeleccionarEstacionario(population, seed);

		couples = MakeCouple(padres, seed, SELECCIONADOS * 0.5);


		for(couple = couples.cbegin(); couple != couples.cend(); ++couple) {
				hijo = CruceMean(*couple, Tr, Ts);
				++n_ejecuciones;


				muta = Mutacion(hijo, Tr, Ts, seed);
				n_ejecuciones += muta;


				remplazo.insert(hijo);
		}


		Remplazo<false>(population, remplazo);

		remplazo.clear();
	} while(n_ejecuciones < N_EJECUCIONES);

	return *population.begin();
}
