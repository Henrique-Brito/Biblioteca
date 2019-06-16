
// Segment Tree

// Acha a soma de um segmento qualquer
// e faz o update de um elemento por vez

// Complexidade
// Build  -> O(n)
// Query  -> O(log(n))
// Update -> O(log(n))

const int MAX = (int)2e5 + 10;

namespace seg{

  int n;
  int vec[MAX];
  ll seg[4*MAX];

  ll make_node(int v){
    return v;
  }
  ll make_neutro(){
    return 0;
  }
  ll combina(ll a, ll b){
    return a+b;
  }

  void build(int at=1, int l=0, int r=n-1){
    if( l==r ){
      seg[at] = make_node(vec[l]);
  	  return;
    }
    int m = (l+r)/2;
    build(2*at, l, m);
    build(2*at +1, m+1, r);
    seg[at] = combina(seg[2*at], seg[2*at +1]);
  }

  ll query(int ql, int qr, int at=1, int l=0, int r=n-1 ){
    if( l>r || ql>r || qr<l ){
      return make_neutro();
    }
    if( ql<=l && r<=qr ){
      return seg[at];
    }
    int m = (l+r)/2;
    return combina(query(ql, qr, 2*at, l, m), query(ql, qr, 2*at +1, m+1, r));
  }

  void update(int pos, int x, int at=1, int l=0, int r=n-1){
    if( l==r ){
      seg[at] = make_node(x);
      return;
    }
    int m = (l+r)/2;
    if( pos <= m ){
      update(pos, x, 2*at, l, m);
    }else{
      update(pos, x, 2*at +1, m+1, r);
    }
    seg[at] = combina(seg[2*at], seg[2*at +1]);
  }
}
