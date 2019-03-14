
// Union-find persistente

// Union-find com union by rank mais 2 funções

// Union e find_current
//   Complexidade - O(log(n))

// Find_time -> executa o find depois no tempo t
//   Complexidade - O(log(n))

// Roll_back -> retorna ao estado anterior
//   Complexidade - O(1)

struct persistent_dsu{

  int n;
  vector<int> id, size;
  stack<int> stk;

  persistent_dsu(int in){
    n = in;
    id.resize(n);
    size.resize(n);
    for( int i=0; i<n; i++ ){
      id[i] = i;
      size[i] = 1;
    }
  }
  int find_current(int k){
  	return id[k] == k ? k : find_current(id[k]);
  }

  int find_time(int k, int t){
    if( !t ) return k;
    return id[k] == k ? k : find_time(id[k], --t);
  }

  void roll_back(){
    if( stk.empty() ) return;
    int u = stk.top(); stk.pop();
    id[u] = u;
  }

  void unite(int a, int b){
  	a = find_current(a);
  	b = find_current(b);
  	if( size[a] > size[b] ){
  		swap(a, b);
  	}
  	id[a] = b;
  	size[b] += size[a];
    stk.push(a);
  }

};
