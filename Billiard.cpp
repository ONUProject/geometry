#include <iostream>
#include <cmath>
using namespace std;

long NOD (long a, long b) {
	long c;
	while (b) {
		c = a % b;
		a = b;
		b = c;
	}
	return abs(a);
}

int main() {
	long m, n, c = 0, a = 0, b = 0;
	cin >> m >> n;
	long g = NOD(m, n);
	m /= g;
	n /= g;
	cout << (n + m - 2) << " ";
	if(n % 2 == 0 and m % 2 == 0) cout << 1;
	if(n % 2 == 0 and m % 2 != 0) cout << 4;
	if(n % 2 != 0 and m % 2 != 0) cout << 3;
	if(n % 2 != 0 and m % 2 == 0) cout << 2;
	return 0;
}
