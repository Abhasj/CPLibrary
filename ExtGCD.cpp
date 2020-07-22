// returns {gcd, x, y} such that ax + by = gcd
tuple<int, int, int> euclid(int a, int b) {
int x = 1, y = 0, x1 = 0, y1 = 1, t;
while (b != 0) {
		int q = a / b;
		t = x;
		x = x1;
		x1 = t - q * x1;
		t = y;
		y = y1;
		y1 = t - q * y1;
		t = b;
		b = a - q * b;
		a = t;
	}
	return a > 0 ? tuple<int,int,int>{a, x, y} : tuple<int,
	int,int>{-a, -x, -y};
}