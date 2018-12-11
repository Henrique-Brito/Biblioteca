
// Segment Tree

// Acha a soma de um segmento qualquer
// e faz o update de um elemento por vez

// Complexidade
// Build  -> O(n)
// Query  -> O(log(n))
// Update -> O(log(n))

const int MAX = (int)2e5 + 10;
int n, v[MAX], seg[4*MAX];

void build(int at, int b, int e){
  if( b==e ){
    seg[at] = v[b];
	  return;
  }
  int m = (b+e)/2;
  build(2*at, b, m);
  build(2*at +1, m+1, e);
  seg[at] = seg[2*at] + seg[2*at +1];
}

ll query(int at, int b, int e, int qb, int qe){
  if( b>e || qb>e || qe<b ){
    return 0;
  }
  if( qb<=b && e<=qe ){
    return seg[at];
  }
  int m = (b+e)/2;
  return query(2*at, b, m, qb, qe) + query(2*at +1, m+1, e, qb, qe);
}

void update(int at, int b, int e, int pos, int x){
  if( b==e ){
    seg[at] = x;
    return;
  }
  int m = (b+e)/2;
  if( pos <= m ){
    update(2*at, b, m, pos, x);
  }else{
    update(2*at +1, m+1, e, pos, x);
  }
  seg[at] = seg[2*at] + seg[2*at +1];
}
