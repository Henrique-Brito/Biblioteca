
// Union Find com path compression
// Complexidade
// Find - O(log(n))
// Union - O(log(n))

const ll MAX = (ll)3e5 + 10;

int n, id[MAX];

void build(){
	for( int i=0; i<n; i++ ) id[i] = i;
}

int find(int k){
	return id[k] == k ? k : id[k] = find(id[k]);
}

void unite(int a, int b){
	id[find(a)] = find(b);
}
