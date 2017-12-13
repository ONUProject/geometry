#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
 
int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2, z2;
    cin >> x2 >> y2 >> z2;
    int answer2 = 0;
    if (x2 == 0) answer2 = (x1 + z2)*(x1 + z2) + (y1 - y2)*(y1 - y2);
    else if (x2 == A) answer2 = (A - x1 + z2)*(A - x1 + z2) + (y1 - y2)*(y1 - y2);
    else if (y2 == 0) answer2 = (x1 - x2)*(x1 - x2) + (y1 + z2)*(y1 + z2);
    else if (y2 == B) answer2 = (x1 - x2)*(x1 - x2) + (B - y1 + z2)*(B - y1 + z2);
    else answer2 = (x1 - x2)*(x1 - x2) + (y2 - y1)*(y2 - y1);
    cout << fixed << setprecision(2) << sqrt(answer2) << endl;
    return 0;
}
