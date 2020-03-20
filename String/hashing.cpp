
//   Complexidade
// Build - O(|s|)
// Operator() - O(1)
//
// mod deve ser um primo grande - 1e9+7 ou 1e9+9
//
// p deve ser maior que o tamanho do alfabeto e deve ser gerado de forma aleatória para evitar hacks
//
// Comparar somente strings do mesmo tamanho para evitar colisão
// Houver colisão, fazer 2 hash's
// Probabilidade de colisão de uma comparação - 1/Mod

// Exemplo: str_hash(s, uniform(27, mod-1), mod), com mod = 1e9+7

typedef long long ll;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

ll uniform(ll l, ll r){
	uniform_int_distribution<ll> uid(l, r);
	return uid(rng);
}

struct str_hash{

	int n;
	ll p, mod;
	vector<ll> h, pwr;

	str_hash(){}

	str_hash(string& s, ll _p, ll _mod) : n((int)s.size()), p(_p), mod(_mod), h(n), pwr(n){
  		pwr[0] = 1;
  		for( int i=1; i<n; i++ ){
    			pwr[i] = pwr[i-1]*p % mod;
  		}
 	 	h[0] = s[0];
  		for( int i=1; i<n; i++ ){
    			h[i] = (h[i-1]*p + s[i]) % mod;
  		}
	}

	ll operator()(int i, int j){
  		if ( i == 0 ){
    		return h[j];
  		}
  		return (h[j] - h[i-1]*pwr[j-i+1] % mod + mod) % mod;
	}
};

