#include <iostream>
using namespace std;
 
int main() {
    double x1,y1,r1,x2,y2,r2;
    cin>>x1>>y1>>r1>>x2>>y2>>r2;
    double d1 = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
    double d2 = (r1+r2)*(r1+r2);
    if((x2==x1)&&(y1==y2)&&(r1==r2)){
        cout<<-1;
    }
    else if(d1>d2 or d1<(r1-r2)*(r1-r2)){
        cout<<0;
    }
    else if(d1==d2 or d1==(r1-r2)*(r1-r2)){
        cout<<1;
    }
    else if(d1<d2){
        cout<<2;
    }
    return 0;
}
