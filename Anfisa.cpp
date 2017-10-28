#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a,b,z;
    cin>>a>>b>>z;


    double square;
    double zAngleInRadians = M_PI*z/180;


    if(z==0){
        square=0;
    }

    else if(z==90){
        square = a*b*sqrt(2);
    }

    else if(cos(zAngleInRadians)/sin(zAngleInRadians)>=a*sqrt(2)/(2*b)){
        square = a*a/(2*cos(zAngleInRadians));
    }

    else{
        square = b * sqrt(2) * (2 * a - b * cos(zAngleInRadians) * sqrt(2) / sin(zAngleInRadians)) /
                 (2 * sin(zAngleInRadians));
    }

    cout << fixed << setprecision(4) <<square;


    return 0;
}
