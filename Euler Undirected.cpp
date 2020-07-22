set<int> adj[N];

stack<int> curr_path;
vector<int> circuit;

void euler_tour (int start) {
	curr_path.push(start);
	while (!curr_path.empty()) {
		int vertex = curr_path.top();
		if (!adj[vertex].size()) {
			curr_path.pop();
			circuit.pb(vertex);
		} else {
			auto it = adj[vertex].begin();
			int next = *it;
			curr_path.push(next);
			adj[vertex].erase(it);
			it = adj[next].find(vertex);
			adj[next].erase(it);
		}
	}
}