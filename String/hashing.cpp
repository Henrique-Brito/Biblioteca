
//   Complexidade
// Build - O(n)
// Get_hash - O(1)
//
//   P e M
// São primos positivos
//
//   P deve ser parecido ao número de caracteres
// Só letra minúscula -> 31
// Maiúscula e minúscula -> 53
// Toda a ASCII -> 257
//
//   M deve ser grande
// 10e9+7 ou 10e9+9
//
// Comparar somente strings do mesmo tamanho para evitar colisão
// Se continuar com colisão, fazer 2 hashs
// Probabilidade de colisão - 1/M

// Creditos: Bruno Maletta - https://github.com/brunomaletta

typedef long long ll;

ll h[MAX], pwr[MAX];
const ll p = 31, m = 1e9+7;
int n; string s;

void build(){
  pwr[0] = 1;
  for( int i=1; i<n; i++ ){
    pwr[i] = pwr[i-1]*p % m;
  }
<<<<<<< HEAD
	h[0] = s[0];
	for( int i=1; i<n; i++ ){
    h[i] = (h[i-1]*p + s[i]) % m;
=======
  hash[0] = s[0];
  for( int i=1; i<n; i++ ){
    hash[i] = (hash[i-1]*p + s[i]) % m;
>>>>>>> 3e14ab3846d4d6927d177141018d5864302f3591
  }
}

ll get_hash(int i, int j){
<<<<<<< HEAD
	if ( i == 0 ){
    return h[j];
  }
	return (h[j] - h[i-1]*pwr[j-i+1] % m + m) % m;
=======
  if ( i == 0 ){
    return hash[j];
  }
  return (hash[j] - hash[i-1]*pwr[j-i+1] % m + m) % m;
>>>>>>> 3e14ab3846d4d6927d177141018d5864302f3591
}
