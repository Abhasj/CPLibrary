const int N = 3e5 + 9;
const int mod = 1e9 + 7;

const int MAX = 10000005;
bool prime[MAX];
int prec[MAX];
vector<int> P;

const int LIM = 250;
int memo[LIM*LIM][LIM];


ll rec(ll N, int K) {
  if (N <= 1 || K < 0) return 0;
  if (N <= P[K]) return N-1;
  if (N < MAX && P[K] * 1LL * P[K] > N) return N-1 - prec[N] + prec[P[K]];

  bool ok = N < LIM*LIM && K < LIM;
  if (ok && memo[N][K]) return memo[N][K];

  ll ret = N/P[K] - rec(N/P[K], K-1) + rec(N, K-1);

  if (ok) memo[N][K] = ret;
  return ret;
}

ll count_primes(ll N) {
  if (N < MAX) return prec[N];
  int K = prec[(int)sqrt(N) + 1];
  return N-1 - rec(N, K) + prec[P[K]];
}

void init_count_primes() {
  prime[2] = true;
  for (int i = 3; i < MAX; i += 2) prime[i] = true;

  for (int i = 3; i*i < MAX; i += 2)
    if (prime[i])
      for (int j = i*i; j < MAX; j += i+i)
        prime[j] = false;
  for(int i=2; i<MAX; i++) if (prime[i]) P.push_back(i);
  for(int i=1; i<MAX; i++) prec[i] = prec[i-1] + prime[i];
}