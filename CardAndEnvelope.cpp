#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std; 
 
int main() { 
    double envelopeX, envelopeY, cardX, cardY;
    cin >> cardX >> cardY >> envelopeX >> envelopeY;
    
    if (envelopeX < envelopeY) swap(envelopeX, envelopeY);
    if (cardX < cardY) swap(cardX, cardY);
    
    double high = envelopeY / 2;
    double width = envelopeX / 2;
    double d = sqrt(cardX * cardX + cardY * cardY) / 2;
    double y1 = sqrt(d * d - width * width);
    double alpha = 2 * atan2(cardY, cardX);
    double y2 = width * sin(alpha) + y1 * cos(alpha);
    if ((envelopeX >= cardX && envelopeY >= cardY) || y2 < envelopeY / 2) {
    	cout << "Possible";
    } else {
    	cout << "Impossible";
    }
    return 0; 
}
