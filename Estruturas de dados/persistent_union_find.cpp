
// Union-find persistente

// Union-find com union by rank mais 2 funções

// Union e find_current
//   Complexidade - O(log(n))

// Find_time -> executa o find depois no tempo t
//   Complexidade - O(log(n))

// Roll_back -> retorna ao estado anterior
//   Complexidade - O(1)

struct persistent_dsu{

  int dsu_size;
  vector<int> id, comp_size;
  stack<int> stk;

  persistent_dsu(int in){
    dsu_size = in;
    id.resize(dsu_size);
    comp_size.resize(dsu_size);
    for( int i=0; i<dsu_size; i++ ){
      id[i] = i;
      comp_size[i] = 1;
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
  	if( comp_size[a] > comp_size[b] ){
  		swap(a, b);
  	}
  	id[a] = b;
  	comp_size[b] += comp_size[a];
    stk.push(a);
  }

};
