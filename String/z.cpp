
// Função Z

// Complexidade: O(n)

// z[i], em s, é a maior substring que começa em i que é um prefixo de s

vector<int> build_z( string s ){

	int n = (int)s.size();
	
	vector<int> z(n, 0);
	z[0] = n;

	int l=0, r=0;
	for( int i=1; i<n; i++ ){
    		if( i <= r ){
     			z[i] = min(r-i+1, z[i-l]);
    		}
    		while( i+z[i]<n and s[z[i]] == s[i+z[i]] ){
    	  		z[i]++;
    		}
   		if( i+z[i]-1 > r ){
      			l = i;
      			r = i+z[i]-1;
    		}
  	}

  	return z;
}

// Retorna todas as ocorrencias de p em s
vector<int> match(string& s, string& p ){

	vector<int> ret;
	auto z = build_z(p+"$"+s);

	for( int i=(int)p.size(); i<z.size(); i++ ){
		if( z[i] == p.size() ){
			ret.pb(i-(int)p.size()); // 1-based
		}
	}

	return ret;
}


//  Problemas:
// https://judge.yosupo.jp/problem/zalgorithm
// https://www.spoj.com/problems/QUERYSTR/

// Com matching:
// https://codeforces.com/group/NTEJ3kWgR3/contest/267299/attachments (problema H)
// https://www.spoj.com/problems/NAJPF/

