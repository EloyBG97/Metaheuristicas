using namespace std;

//remplazo
template<bool conelitismo>
void Remplazo(multiset<individuo_genetico, torneo_binario> & P, multiset<individuo_genetico, torneo_binario> & R)  {
	typename multiset<individuo_genetico, torneo_binario>::iterator it;
	individuo_genetico elitismo = *P.cbegin();

	//SIGUIENTE GENERACION
	P.insert(R.cbegin(), R.cend());

	it = --P.end();

	for(unsigned int i = 0; i < R.size(); ++i) {
		it = P.erase(it);
		--it;
	}


	//MANTENER LA MEJOR SOLUCION DE P_{t-1}
	if(conelitismo) {
		if(P.find(elitismo) == P.end()) {
			P.erase(--P.end());
			P.insert(elitismo);
		}
	}
}
