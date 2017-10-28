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
 
long NOK (long a, long b) {
	return a / NOD(a, b) * b;
}
 
int main() {
	long m, n, c = 0, a = 0, b = 0;
	cin >> m >> n;
	long g = NOD(m, n);
	m /= g;
	n /= g;
	a = NOK(m, n) / m;
	b = NOK(m, n) / n;
	c = a + b -2;
	cout << c << " ";
	if(a % 2 == 0 and b % 2 == 0) cout << 1;
	if(a % 2 == 0 and b % 2 != 0) cout << 4;
	if(a % 2 != 0 and b % 2 != 0) cout << 3;
	if(a % 2 != 0 and b % 2 == 0) cout << 2;
	return 0;
}