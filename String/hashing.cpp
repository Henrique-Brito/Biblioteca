
//   Complexidade
// Build - O(|s|)
// Get_hash - O(1)
//
//   P e Mod
// São primos positivos
//
//   P deve ser parecido ao número de caracteres
// Só letra minúscula -> 31
// Maiúscula e minúscula -> 53
// Toda a ASCII -> 257
//
//   Mod deve ser grande
// 1e9+7 ou 1e9+9
//
// Comparar somente strings do mesmo tamanho para evitar colisão
// Se continuar com colisão, fazer 2 hashs
// Probabilidade de colisão - 1/Mod

typedef long long ll;

ll h[MAX], pwr[MAX];
const ll p = 31, mod = 1e9+7;
int n; string s;

void build(){
  pwr[0] = 1;
  for( int i=1; i<n; i++ ){
    pwr[i] = pwr[i-1]*p % mod;
  }
  h[0] = s[0];
  for( int i=1; i<n; i++ ){
    h[i] = (h[i-1]*p + s[i]) % mod;
  }
}

ll get_hash(int i, int j){
  if ( i == 0 ){
    return h[j];
  }
  return (h[j] - h[i-1]*pwr[j-i+1] % mod + mod) % mod;
}
