struct pt {
	ll x, y;
};
 
bool s_x (pt &a, pt &b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}
 
bool s_y (pt &a, pt &b) {
	return a.y < b.y;
}
 
ld dist (pt &a, pt &b) {
	ld t = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	return sqrt(t);
}
 
int n;
vector<pt> a;
ld min_dist = 1e18;

void solve (int l, int r) {
	if (r - l <= 3) {
		for (int i = l; i < r; ++i) {
			for (int j = i + 1; j < r; ++j) {
				if (min_dist > dist(a[i], a[j])) {
					min_dist = dist(a[i], a[j]);
				}
			}
		}
		return;
	}
	int m = (l + r) / 2;
	solve(l, m);
	solve(m, r);
	ll midx = a[m].x;
	vector<pt> temp;
	for (int i = l; i < r; ++i) {
		if (abs(a[i].x - midx) <= min_dist) temp.pb(a[i]); 
	}
	sort(all(temp), s_y);
	for (int i = 0; i < temp.size(); ++i) {
		for (int j = i + 1; j < temp.size(); ++j) {
			if (temp[j].y - temp[i].y > min_dist) break;
			if (min_dist > dist(temp[i], temp[j])) {
				min_dist = dist(temp[i], temp[j]);
			}
		}
	}
}