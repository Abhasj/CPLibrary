int components;
int id[N];
int sz[N];

void init() {
	for (int i = 0; i < N; ++i) {
		id[i] = i;
		sz[i] = 1;
	}
	components = N;
}

int root(int p) {
	while (p != id[p]) {
		id[p] = id[id[p]];
		p = id[p];
	}
	return p;
}

void merge(int p, int q) {
	p = root(p);
	q = root(q);
	if (p == q) return;
	components--;
	if (sz[p] > sz[q]) {
		swap(p, q);
	}
	sz[q] += sz[p];
	sz[p] = 0;
	id[p] = q; 
}

int is_connected(int p, int q) {
	return root(p) == root(q);
}
