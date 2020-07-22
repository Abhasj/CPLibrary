struct Matrix {
	vector<vector<ll>> data;
  	int n, m;

  	Matrix(int n, int m) : data(n, vector<ll>(m)), n(n), m(m) {}
  	Matrix(vector<vector<ll>> g) : data(g) {
  		n = g.size();
  		m = g[0].size();
  	}

	Matrix mult(const Matrix&rhs) const {
		int n = (*this).n;
		int m = rhs.m;
		int tmp = rhs.n;
    	Matrix ans(n, m);
	    for (int i = 0; i < n; ++i) {
	    	for (int j = 0; j < tmp; ++j) {
	       		for (int k = 0; k < m; ++k) {
	       			ans.data[i][k] = (ans.data[i][k] + data[i][j] * rhs.data[j][k]) % mod;
	        	}
	      	}
	    }
	    return ans;
	}
 
	Matrix pow(ll pw) const {
		int sz = (*this).n;
	    Matrix ans(sz, sz);
	    Matrix exp = *this;
	    for (int i = 0; i < sz; ++i) { ans.data[i][i] = 1; }
	    while (pw) {
	      if (pw & 1) { ans = ans.mult(exp); }
	      pw >>= 1;
	      exp = exp.mult(exp);
	    }
	    return ans;
	}
};
