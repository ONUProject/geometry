#include <iostream>
using namespace std;
 
 
int main() {
    int length;
    int fishQuantity;
    int fishPerDay;
    cin>>length>>fishQuantity>>fishPerDay;
    int count=0;
    for(int i=0;i<fishQuantity;i++){
 
 
 
        int x1;
        int y1;
        int x2;
        int y2;
        cin>>x1>>y1>>x2>>y2;
        if(((x1*x1+y1*y1)<=length*length) or ((x2*x2+y2*y2)<=length*length)){
            count++;
        }
        else {
 
            int a;
            int b;
            int c;
 
            int deltaX = x2 - x1;
            int deltaY = y2 - y1;
 
            a = deltaY;
            b = -deltaX;
            c = deltaX * y1 - deltaY * x1;
 
            int maxX = max(x1, x2);
            int minX = min(x1, x2);
 
            int maxY = max(y1, y2);
            int minY = min(y1, y2);
 
 
            if ((c * c <= length * length * (a * a + b * b) and
                 ((a == 0 and -c <= b * maxY and -c >= b * minY) or (b == 0 and -c <= a * maxX and -c >= a * minX) or
                  (a != 0 and b != 0 and -c * b <= (a * a + b * b) * maxY and -c * b >= (a * a + b * b) * minY)))) {
                count++;
            }
        }
 
 
    }
    cout<<count/fishPerDay+1;
    return 0;
}
