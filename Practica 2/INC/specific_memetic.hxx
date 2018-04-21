
using namespace std;

template<unsigned int Generation, unsigned int Percent, bool Mejorado>
	individuo_genetico AM(const muestra &Tr, const muestra &Ts, const unsigned int & seed) {
	default_random_engine probability(seed);

	uniform_real_distribution<float> distribution(0, 1);
	multiset<individuo_genetico, torneo_binario> population;
	multiset<individuo_genetico, torneo_binario> remplazo;
	multiset<individuo_genetico, torneo_binario> padres;
	vector<pair<individuo_genetico, individuo_genetico>> couples;
	typename vector<pair<individuo_genetico, individuo_genetico>>::const_iterator couple;
	typename multiset<individuo_genetico, torneo_binario>::iterator it;
	const unsigned int SELECCIONADOS = 10;
	bool muta;

	individuo_genetico hijo;
	unsigned int n_generation = 0;
	const float Pcm = 0.7;

	const unsigned int M = 30;
	const unsigned int N_EJECUCIONES = 15000;
	unsigned int  n_ejecuciones = 0, n_ejecuciones_aux;


	population = StartPopulation(Tr, Ts, seed, M);
	n_ejecuciones += M;

	do {
		padres = SeleccionarGeneracional(population, SELECCIONADOS);

		couples = MakeCouple(padres, seed, SELECCIONADOS * 0.5);


		for(couple = couples.cbegin(); couple != couples.cend(); ++couple) {

			if(distribution(probability) <= Pcm) {
				hijo = CruceBLX(*couple, Tr, Ts,seed);
				++n_ejecuciones;

				if(distribution(probability) <= Pcm) {
					muta = Mutacion(hijo, Tr, Ts, seed);
					n_ejecuciones += muta;
				}

				if(!Mejorado) {
					if(n_generation % Generation == 0 && distribution(probability) <= Percent/100) {
						hijo = BusquedaLocalAprendizaje(hijo.first, Tr, Ts,seed, n_ejecuciones_aux);
						n_ejecuciones += n_ejecuciones_aux;
					}
				}


				remplazo.insert(hijo);

			}
		}


		if(Mejorado & (n_generation % Generation == 0)) {
			cerr << n_generation << endl;
			multiset<individuo_genetico, torneo_binario> aux;
			it = remplazo.begin();
			for(unsigned int i = 0; i < (Percent/100) * M; ++i) {

				hijo = BusquedaLocalAprendizaje(it->first, Tr, Ts, seed, n_ejecuciones_aux);
				n_ejecuciones += n_ejecuciones_aux;
				it = remplazo.erase(it);
				aux.insert(hijo);
			}

			remplazo.insert(aux.begin(), aux.end());
			aux.clear();
		}

		Remplazo<true>(population, remplazo);

		++n_generation;
		remplazo.clear();
	} while(n_ejecuciones < N_EJECUCIONES);

	return *population.begin();
}
