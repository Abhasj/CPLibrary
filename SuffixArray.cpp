// Taken from cp - algorithms.

vector<int> sort_cyclic(string const& s) {
    int n = s.size();
    vector<int> pos(n), cat(n), cnt(max(n, 256), 0);
    for (int i = 0; i < n; ++i) {
    	cnt[s[i]]++;
    }
    for (int i = 1; i < 256; ++i) {
    	cnt[i] += cnt[i - 1];
    }
    for (int i = 0; i < n; ++i) {
    	pos[--cnt[s[i]]] = i;
    }
    cat[pos[0]] = 0;
    int c = 0;
    for (int i = 1; i < n; ++i) {
    	if (s[pos[i]] != s[pos[i - 1]]) {
    		c++;
    	}
    	cat[pos[i]] = c;
    }
    vector<int> new_pos(n), new_cat(n);
    for (int h = 0; (1 << h) < n; ++h) {
    	for (int i = 0; i < n; ++i) {
    		new_pos[i] = pos[i] - (1 << h);
    		if (new_pos[i] < 0) new_pos[i] += n;
    	}
    	fill(cnt.begin(), cnt.end(), 0);
    	for (int i = 0; i < n; ++i) {
    		cnt[cat[i]]++;
    	}
    	for (int i = 1; i < n; ++i) {
    		cnt[i] += cnt[i - 1];
    	}
    	for (int i = n - 1; i >= 0; --i) {
    		pos[--cnt[cat[new_pos[i]]]] = new_pos[i];
    	}
    	new_cat[pos[0]] = 0;
    	c = 0;
    	for (int i = 1; i < n; ++i) {
    		if (cat[pos[i]] != cat[pos[i - 1]] ||
    			cat[(pos[i] + (1 << h)) % n] != cat[(pos[i - 1] + (1 << h)) % n]) {
    			c++;
    		}
    		new_cat[pos[i]] = c;
    	}
    	cat.swap(new_cat);
    }
    return pos;
}

vector<int> suffix_array(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

vector<int> lcp(string &s, vector<int> &sa) {
    int n = s.size();
    vector<int> where(n, 0);
    for (int i = 0; i < n; i++)
        where[sa[i]] = i;

    int k = 0;
    vector<int> lcp(n - 1, 0);
    for (int i = 0; i < n; i++) {
        if (where[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[where[i] + 1];
        while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[where[i]] = k;
        if (k) k--;
    }
    return lcp;
}