#include<common_gmetic.h>

using namespace std;

poblacion_genetico StartPopulation(const muestra &Tr, const unsigned int M, const unsigned int & seed) {
	const typename individuo::size_type SIZE = Tr.getIndividuo(0).getSize();
	static default_random_engine generator(seed);
	uniform_real_distribution<double> distribution(0 ,1);

	poblacion_genetico P(M);
	individuo_genetico aux;

	aux.first.resize(SIZE);

	for(unsigned int i = 0; i < M; i++) {
		for(unsigned int j = 0; j < SIZE; ++j) {
			aux.first[j] = distribution(generator);
		}
		
		aux.second = fObjetivo(aux.first, Tr);

		P[i] = aux;
	} 

	return P;
}

vector<unsigned int> Seleccionar(const poblacion_genetico & P, const unsigned int & N, const unsigned int & seed) {
	vector<unsigned int> seleccionados(N);

	for(unsigned int i = 0; i < N; ++i) {
		seleccionados[i] = torneoBinario(P, seed);
	}

	return seleccionados;
}

/*
pair<unsigned int, unsigned int> SeleccionarEstacionario(const poblacion_genetico & P, const unsigned int & seed) {
	pair<unsigned int, unsigned int> pareja;

	pareja.first = torneoBinario(P, seed);
	pareja.second = torneoBinario(P, seed);

	return pareja;

}
*/

//Torneo Binario
unsigned int torneoBinario(const poblacion_genetico &P, const unsigned int & seed) {
	unsigned int oponente1, oponente2;
	static default_random_engine generator(seed);
	uniform_int_distribution<unsigned int> distribution(0 ,P.size() - 1);

	oponente1 = distribution(generator);

	do {
		oponente2 = distribution(generator);
	} while (oponente1 == oponente2);


	return (P[oponente1].second.first + P[oponente1].second.second < P[oponente2].second.first + P[oponente1].second.second)?oponente2:oponente1;
}


//Cruce

pair<individuo_genetico,individuo_genetico> CruceBLX(const pair<individuo_genetico*, individuo_genetico*> & C, const muestra &Tr, const unsigned int & seed) {
	const float ALPHA = 0.3;
	const unsigned int SIZE = Tr.getIndividuo(0).getSize();
	typename individuo::value_type min , max, I;
	pair<individuo_genetico,individuo_genetico> hijos;
	static default_random_engine generator(seed);


	hijos.first.first.resize(SIZE);
	hijos.second.first.resize(SIZE);

		for(unsigned int j = 0; j < C.first->first.size(); ++j) {
			if(C.first->first[j] < C.second->first[j]) {
				max = C.second->first[j];
				min = C.first->first[j];
			}

			else {
				min = C.second->first[j];
				max = C.first->first[j];
			}

			I = max - min;

			uniform_real_distribution<double> distribution(min - I * ALPHA, max + I * ALPHA);

			hijos.first.first[j] = distribution(generator);
			hijos.second.first[j] = distribution(generator);
		}

		hijos.first.second = fObjetivo(hijos.first.first, Tr);
		hijos.second.second = fObjetivo(hijos.second.first, Tr);
		



	return hijos;
}


individuo_genetico CruceMean(const pair<individuo_genetico*, individuo_genetico*> & C, const muestra &Tr) {
		const typename individuo::size_type SIZE = Tr.getIndividuo(0).getSize();

		individuo_genetico hijo;

		hijo.first.resize(SIZE);

		for(unsigned int j = 0; j < C.first->first.size(); ++j) {
			hijo.first[j] = (C.first->first[j] + C.second->first[j]) * 0.5;
		}

		hijo.second = fObjetivo(hijo.first, Tr);



	return hijo;
}

//Mutacion
bool Mutacion(individuo_genetico & I, const muestra & Tr, const unsigned int & seed) {
	static default_random_engine generator(seed);
	bool muta = false;
	normal_distribution<typename individuo::value_type> distribution_n(0 , 0.3);
	uniform_real_distribution<double> distribution(0 ,1);
	

	const float Pg = 0.001;

	for(unsigned int i = 0; i < I.first.size(); ++i) {
		if(distribution(generator) <= Pg) {
			I.first[i] += distribution_n(generator);
			if(I.first[i] > 1) I.first[i] = 1;
			else if(I.first[i] < 0) I.first[i] = 0;
			muta = true;
		}
	}

	if(muta)
		I.second = fObjetivo(I.first, Tr);

	return muta;
}

void RemplazoGeneracional(poblacion_genetico & P, poblacion_genetico & R) {

	vector<unsigned int> index_ordenado(P.size());
	unsigned int peor_individuo, mejor_individuo;

	for(unsigned int i = 0; i < index_ordenado.size(); ++i)
		index_ordenado[i] = i;
	
	sort(index_ordenado.begin(), index_ordenado.end(), [&](unsigned int idx1, unsigned int idx2) {
		float coste1 = R[idx1].second.first + R[idx1].second.second,
			  coste2 = R[idx2].second.first + R[idx2].second.second;

		return coste1 < coste2;
	});

	peor_individuo = index_ordenado[0];
	
	sort(index_ordenado.begin(), index_ordenado.end(), [&](unsigned int idx1, unsigned int idx2) {
		float coste1 = P[idx1].second.first + P[idx1].second.second,
			  coste2 = P[idx2].second.first + P[idx2].second.second;

		return coste1 > coste2;
	});

	mejor_individuo = index_ordenado[0];

	if(R[peor_individuo].second.first + R[peor_individuo].second.second < P[mejor_individuo].second.first + P[mejor_individuo].second.second)
		R[peor_individuo] = P[mejor_individuo];

	P.swap(R);
}

void RemplazoEstacionario(poblacion_genetico & P, poblacion_genetico & R) {

	vector<unsigned int> index_ordenado(P.size());
	unsigned int  i;


	for(i = 0; i < index_ordenado.size(); ++i)
		index_ordenado[i] = i;
	
	sort(index_ordenado.begin(), index_ordenado.end(), [&](unsigned int idx1, unsigned int idx2) {
		float coste1 = P[idx1].second.first + P[idx1].second.second,
			  coste2 = P[idx2].second.first + P[idx2].second.second;

		return coste1 < coste2;
	});

	for(i = 0; i < R.size(); ++i)
		if(P[index_ordenado[i]].second.first + P[index_ordenado[i]].second.second < R[i].second.first + R[i].second.second) {
			P[index_ordenado[i]] = R[i];
		}
}

vector<unsigned int> ElegirAleatorios(const vector<individuo_genetico> & P, const  unsigned int & N, const unsigned int &seed) {
	vector<unsigned int> individuos_elegidos(N);
	unsigned int aux1;
	vector<int> escogidos(N, -1);
	static default_random_engine generator(seed);
	uniform_int_distribution<unsigned int> distribution(0 ,P.size() - 1);


	for(size_t i = 0; i < N; ++i) {
		do {
			aux1 = distribution(generator);
		}while(find(escogidos.cbegin(), escogidos.cend(), aux1) != escogidos.cend());

		individuos_elegidos[i] = aux1;
	}

	return individuos_elegidos;
}
