// Hierholzer's Algo - Euler Path / Tour

vector<int> adj[N];

stack<int> curr_path;
vector<int> circuit;

void euler_tour (int start) {
	curr_path.push(start);
	while (!curr_path.empty()) {
		int vertex = curr_path.top();
		if (!adj[vertex].size()) {
			circuit.pb(vertex);
			curr_path.pop();
		} else {
			int next = adj[vertex].back();
			adj[vertex].pop_back();
			curr_path.push(next);
		}
	}
}