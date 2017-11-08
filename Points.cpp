#include <iostream>
#include <cmath>

using  namespace std;

struct point{
    int x;
    int y;

    point(int xCoordinate, int yCoordinate){
        x = xCoordinate;
        y = yCoordinate;
    }
    point(){
        x = 0;
        y = 0;
    }
    bool operator==(point &point1){
    	return x==point1.x and y==point1.y;
    }
    bool operator!=(point &point1){
    	return !(x==point1.x and y==point1.y);
    }
};

struct straight{

    int a;
    int b;
    int c;
    straight(point point1, point point2){
        int deltaX = point2.x - point1.x;
        int deltaY = point2.y - point1.y;

        a = deltaY;
        b = -deltaX;
        c = deltaX * point1.y - deltaY * point1.x;
    }
    straight(int aCoefficient, int bCoefficient, point point){
        a = aCoefficient;
        b = bCoefficient;
        c = - point.y*b - a*point.x;
    }

};

int sgn(int a){
    if(a < 0) return -1;
    else return a > 0;
}

int main() {
    const int MAX_NUM = 10000;
    int n;
    cin>>n;

    point firstBasic;
    point secondBasic;

    cin>>firstBasic.x>>firstBasic.y;
    cin>>secondBasic.x>>secondBasic.y;

    point array[MAX_NUM];

    for(int i = 0; i < n; i++){
        cin>>array[i].x>>array[i].y;
    }
    int maxCount = 0;

    for(int i = 0; i<n; i++){
        straight firstStraight(firstBasic, array[i]);
        straight firstParallelStraight(firstStraight.a, firstStraight.b, secondBasic);

        straight secondStraight(secondBasic, array[i]);
        straight secondParallelStraight(secondStraight.a, secondStraight.b, firstBasic);

        int firstMax = 0;
        int secondMax = 0;
        for(int j=0; j<n; j++){
        	if(array[i]!=firstBasic){
            	int firstSgn = sgn(firstParallelStraight.a * array[j].x + firstParallelStraight.b * array[j].y + firstParallelStraight.c);
            	int secondSgn = sgn(firstStraight.a * array[j].x + firstStraight.b * array[j].y +firstStraight.c);
            	if(firstSgn != secondSgn or firstSgn==0 or secondSgn == 0) {
                	firstMax++;
            	}
        		
        	}
			if(array[i]!=secondBasic){
            	int thirdSgn = sgn(secondParallelStraight.a * array[j].x + secondParallelStraight.b * array[j].y + secondParallelStraight.c);
            	int fourthSgn = sgn(secondStraight.a * array[j].x + secondStraight.b * array[j].y + secondStraight.c);
            	if(thirdSgn != fourthSgn or thirdSgn == 0 or fourthSgn == 0){
                	secondMax++;
            	}
				
			}

        }
        maxCount = max(maxCount, max(firstMax, secondMax));
    }
    cout<<maxCount;



    return 0;
}
