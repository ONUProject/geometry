#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int x1, y1;
	cin >> x1 >> y1;
	int x2,y2,z2;
	cin >> x2 >> y2 >> z2;
	double D = 1/sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + z2*z2 );
	cout << fixed << setprecision(3) << D ;
	return 0;
}
