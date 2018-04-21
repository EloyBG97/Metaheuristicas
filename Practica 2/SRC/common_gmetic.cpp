#include<common_gmetic.h>

using namespace std;

bool torneo_binario::operator()(const individuo_genetico & I1, const individuo_genetico & I2) {
	pair<float, float> coste1 = I1.second,
										 coste2 = I2.second;

	return coste1.first + coste1.second < coste2.first + coste2.second;
}

multiset<individuo_genetico, torneo_binario> StartPopulation(const muestra &Tr, const muestra &Ts, const unsigned int & seed, const unsigned int M) {
	const typename individuo::size_type SIZE = Tr.getIndividuo(0).getSize();

	default_random_engine generator(seed);
	uniform_real_distribution<typename individuo::value_type> distribution(0,1);

	multiset<individuo_genetico, torneo_binario> P;
	individuo_genetico aux;

	aux.first.resize(SIZE);

	do {
		for(unsigned int j = 0; j < SIZE; ++j) {
			aux.first[j] = distribution(generator);
		}

		aux.second = fObjetivo(aux.first, Tr, Ts);

		P.insert(aux);
	} while (P.size() < M);

	return P;
}

multiset<individuo_genetico, torneo_binario> SeleccionarGeneracional(const multiset<individuo_genetico, torneo_binario> & P, const unsigned int & N) {
	multiset<individuo_genetico, torneo_binario> padres;

	typename multiset<individuo_genetico, torneo_binario>::const_iterator it = P.cbegin();

	for(unsigned int i = 0; i < N; ++i) {
		padres.insert(*(it++));
	}

	return padres;
}

multiset<individuo_genetico, torneo_binario> SeleccionarEstacionario(const multiset<individuo_genetico, torneo_binario> & P, const unsigned int & seed) {
	multiset<individuo_genetico, torneo_binario> seleccionados;
	vector<pair<individuo_genetico, individuo_genetico>>individuos = MakeCouple(P, seed, 2);

	for(unsigned int i = 0; i < 2; i++) {
		seleccionados.insert(individuos[i].first);
		seleccionados.insert(individuos[i].second);
	}


	seleccionados.erase(--seleccionados.end());
	seleccionados.erase(--seleccionados.end());

	return  seleccionados;
}

//Cruce

individuo_genetico CruceBLX(const pair<individuo_genetico, individuo_genetico> & C, const muestra &Tr, const muestra &Ts, const unsigned int & seed) {
	static default_random_engine generator(seed);
	const float ALPHA = 0.3;
	const unsigned int SIZE = Tr.getIndividuo(0).getSize();
	typename individuo::value_type min , max, I;
	individuo_genetico hijo;


	hijo.first.resize(SIZE);

		for(unsigned int j = 0; j < C.first.first.size(); ++j) {
			if(C.first.first[j] < C.second.first[j]) {
				max = C.second.first[j];
				min = C.first.first[j];
			}

			else {
				min = C.second.first[j];
				max = C.first.first[j];
			}

			I = max - min;

			uniform_real_distribution<typename individuo::value_type> distribution(min - I * ALPHA, max + I * ALPHA);

			hijo.first[j] = distribution(generator);
		}

		hijo.second = fObjetivo(hijo.first, Tr, Ts);



	return hijo;
}


individuo_genetico CruceMean(const pair<individuo_genetico, individuo_genetico> & C, const muestra &Tr, const muestra &Ts) {
		const typename individuo::size_type SIZE = Tr.getIndividuo(0).getSize();

		individuo_genetico hijo;

		hijo.first.resize(SIZE);

		for(unsigned int j = 0; j < C.first.first.size(); ++j) {
			hijo.first[j] = (C.first.first[j] + C.second.first[j]) * 0.5;
		}

		hijo.second = fObjetivo(hijo.first, Tr, Ts);



	return hijo;
}

//Mutacion
bool Mutacion(individuo_genetico & I, const muestra & Tr, const muestra & Ts, const unsigned int & seed) {
	static default_random_engine generator(seed);
	bool muta = false;
	uniform_real_distribution<float> probabilidad(0, 1);
	normal_distribution<typename individuo::value_type> distribution_n(0 , 0.3);

	const float Pg = 0.01;

	for(unsigned int i = 0; i < I.first.size(); ++i) {
		if(probabilidad(generator) <= Pg) {
			I.first[i] += distribution_n(generator);
			if(I.first[i] > 1) I.first[i] = 1;
			else if(I.first[i] < 0) I.first[i] = 0;
			muta = true;
		}
	}

	if(muta)
		I.second = fObjetivo(I.first, Tr, Ts);

	return muta;
}

//AUX
vector<pair<individuo_genetico, individuo_genetico>> MakeCouple(const multiset<individuo_genetico, torneo_binario> & P, const unsigned int & seed, const  unsigned int & n_couples) {
	static default_random_engine generator(seed);
	uniform_int_distribution<unsigned int> distribution(0, P.size() -1);
	typename multiset<individuo_genetico, torneo_binario>::const_iterator it;
	unsigned int aux1, aux2, aux3;

	vector<pair<individuo_genetico, individuo_genetico>> couples(n_couples);
	vector<int> escogidos(n_couples * 2, -1);

	pair<individuo_genetico, individuo_genetico> couple;
	unsigned int k = 0;

	for(size_t i = 0; i < couples.size(); ++i) {
		it = P.cbegin();


		do {
			aux1 = distribution(generator);
		}while(find(escogidos.cbegin(), escogidos.cend(), aux1) != escogidos.cend());

		escogidos[k++] = aux1;


		do {
			aux2 = distribution(generator);

		}while(find(escogidos.cbegin(), escogidos.cend(), aux2) != escogidos.cend());

		escogidos[k++] = aux2;



		if(aux1 > aux2) {
			aux3 = aux1;
			aux1 =  aux2;
			aux2 = aux3;
		}

		for(unsigned int j = 0; j < aux1; ++j) {
			++it;
		}

		couple.first = *it;

		for(unsigned int j = aux1; j < aux2; ++j) {
			++it;
		}


		couple.second = *it;

		couples[i] = couple;

	}

	return couples;
}
