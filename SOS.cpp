
for(int mask = 0; mask < (1 << N); ++mask) {
	dp[mask][0] = A[mask];
	if (mask & 1) {
		dp[mask][0] += A[mask ^ 1];
	}
	for(int i = 1; i < N; ++i) {
		dp[mask][i] = dp[mask][i - 1];
		if (mask & (1 << i)) {
			dp[mask][i] += dp[mask ^ (1 << i)][i - 1];
		}
	}
	F[mask] = dp[mask][N - 1];
}

//memory optimized.
for (int i = 0; i < (1 << N); ++i) {
	F[i] = A[i];
}
for (int i = 0; i < N; ++i) { 
	for (int mask = 0; mask < (1 << N); ++mask) {
		if (mask & (1 << i)) {
			F[mask] += F[mask ^ (1 << i)];
		}
	}
}
