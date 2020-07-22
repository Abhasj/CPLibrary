	string s;
	while (getline(cin, s)) {
		istringstream ss(s);
		string next;
		while (getline(ss, next, ',')) {
			cout << next << " ";
		}
		cout << endl;
	}