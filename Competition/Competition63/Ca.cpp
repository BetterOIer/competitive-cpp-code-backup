#include <bits/stdc++.h>
long long n, k;
std::vector<int> a, b, nums1, nums2;	//	Original DP
int mod(int a) {
	return a >= 1000000007 ? a - 1000000007 : a;
}
class matrix {
	public:
		std::array<std::array<long long, 64>, 64> c;
		matrix operator * (const matrix &a) const {
			matrix b;
			for(int i = 0; i < 64; i++)
				for(int j = 0; j < 64; j++)
					for(int k = 0; k < 64; k++)
						b.c[i][j] = (b.c[i][j] + c[i][k] * a.c[k][j]) % 1000000007;
			return b;
		}
		matrix pow(long long p) const {
			if(p == 1)
				return *this;
			if(p & 1)
				return pow(p ^ 1) * *this;
			return (*this * *this).pow(p >> 1);
		}
		matrix() : c() {}
		matrix(const matrix &a) : c(a.c) {}
} g;
int main() {
	std::cin >> n >> k;
	if(k == 0) {
		std::cout << "1\n";
		return 0;
	}
	for(int i = 0; i < (1 << k + k - 1); i++)
		if(__builtin_popcount(i) == k)
			nums1.emplace_back(i);
	for(int i = 1 << k + k - 1; i < (1 << k + k); i++)
		if(__builtin_popcount(i) == k)
			nums2.emplace_back(i);
	if(k >= 4) {
		a.resize(1 << k + k, 0), b.resize(1 << k + k, 0), a[(1 << k) - 1 << k] = 1;
		for(int i = 1; i <= n; i++) {
			b.swap(a), a.clear(), a.resize(1 << k + k, 0);
			for(int j : nums1)
				a[j << 1] = b[j];
			for(int j : nums2) {
				int l = j << 1;
				l &= (1 << k + k) - 1;
				for(int x = 1 << k + k - 1; x > 0; x >>= 1)
					if(!(l & x))
						a[l ^ x] = mod(a[l ^ x] + b[j]);
			}
		}
		std::cout << a[(1 << k) - 1 << k] << '\n';
	} else /*k <= 3*/ {
		for(int j : nums1)
			g.c[j][j << 1]++;
		for(int j : nums2) {
			int l = j << 1;
			l &= (1 << k + k) - 1;
			for(int x = 1 << k + k - 1; x > 0; x >>= 1)
				if(!(l & x))
					g.c[j][l ^ x]++;
		}
		std::cout << (g.pow(n)).c[(1 << k) - 1 << k][(1 << k) - 1 << k] << '\n';
	}
	return 0;
}
//	O\left(\min\left\{n \cdot C_{2k}^k, \left(C_{2k}^k\right)^3 \log n\right\}\right)
//	matrix when k < 4