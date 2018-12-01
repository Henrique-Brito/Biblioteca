
// Complexidade - O(h)
// h = numero de digitos de b (menor número)

int mdc(int a, int b){
  if( !b ){
    return a;
  }else{
    return mdc(b, a%b);
  }
}
