int N; // number of nodes.
int lg = log2(N);

vector<int> adj[N];
ll dp[N][lg];
ll level[N];

void dfs (int node, int par) {
	for (int next : adj[node]) {
		if (next != par) {
			level[next]  = level[node] + 1;
			dp[next][0] = node;
			dfs (next, node);
		}
	}
}

void pre() {
	dp[0][0] = 0;
	dfs (0, -1);
	for (int i = 1; i < lg; ++i) {
		for (int j = 0; j < n; ++j) {
			dp[i][j] = dp[i - 1][dp[i - 1][j]];
		}
	}
}
 
int lca (int a, int b) {
	if (level[a] > level[b]) swap(a, b);
	int dis = level[b] - level[a];
	for (int i = lg - 1; i >= 0; --i) {
		if (dis & (1 << i)) {
			b = dp[i][b];
		}
	}
	if (a == b) return a;
	for (int i = lg - 1; i >= 0; --i) {
		if (dp[i][b] != dp[i][a]) {
			a = dp[i][a];
			b = dp[i][b];
		}
	}
	return dp[0][a];
}