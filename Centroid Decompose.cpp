void dfs2(int node, int par) {
	sub[node] = 1;
	nn++;
	for (int next : g[node]) {
		if (next != par) {
			dfs2(next, node);
			sub[node] += sub[next];
		}
	}
}
 
int dfs3(int node, int par) {
	for (int next : g[node]) {
		if (next != par && sub[next] > (nn / 2)) return dfs3(next, node);
	}
	return node;
}

void decompose(int node, int par)  {
	nn = 0;
	dfs2(node, -1);
	int cent = dfs3(node, -1);
	up[cent] = par;
	for (auto it = g[cent].begin(); it != g[cent].end(); ++it) {
		g[*it].erase(cent);
		nn = 0;
		decompose(*it, cent);
	}
	g[cent].clear();
}
 