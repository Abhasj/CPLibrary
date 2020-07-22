int N=300005;
int st[N][22];
int log[N + 1];

void build () {
	for (int i = 0; i < N; ++i) {
		st[i][0] = ar[i];
	}

	log[1] = 0;
	for (int i = 2; i <= N; ++i) {
		log[i] = log[i / 2] + 1;
	}

	for (int j = 1; j <= 25; ++j) {
		for (int i = 0; i + (1 << j) <= N; ++i) {
			st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]); // change f with type of operation
		}
	}
}

int query(int l, int r) {
	int sz = log[r - l + 1];
	return f(st[l][sz], st[r - (1 << sz) + 1][sz]);
}