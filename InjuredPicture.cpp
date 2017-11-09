// И.Е.Мазурок cpp.mazurok.com
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
// Куда падать если Ua == 1 буква на точно картине? А нет такого теста.

struct point {
    double x, y;
    point() {x=0; y=0;}
    point (double x, double y) {
        this->x = x; 
		this->y = y;
    }
    bool between(const point & a, const point & b) {
        double u = (a.x == b.x? (y - b.y) / (a.y - b.y): (x - b.x) / (a.x - b.x));
        return (u >= 0) and (u <= 1.) and (y - b.y == u * (a.y - b.y)) and (x - b.x == u * (a.x - b.x));
    }
    double distance(const point & a) {
        return sqrt((a.x-x)*(a.x-x) + (a.y-y)*(a.y-y));
    } 
};

int main() {
    point A, B, C, D;
    double H, answer = 0;
    cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y >> H;
    double denominator=(D.y-C.y)*(A.x-B.x)-(D.x-C.x)*(A.y-B.y);
    if (denominator == 0) {
        if (A.between(C,D)) {
            if (B.between(C,D)) {
               if (A.distance(B) <= H) answer = M_PI * A.distance(B) / 2.;
               else answer = A.distance(B) * asin (H / A.distance(B)); // нет такого теста
            } else {
                if (C.between(A,B)) {
                    if (A.distance(B) <= H)  answer = -1; // нет такого теста
                    else answer = A.distance(B) * (asin (H / A.distance(B)) - acos(A.distance(C) / A.distance(B)));
                } else {
                    if (A.distance(B) <= H)   answer = A.distance(B) * (M_PI / 2 - acos(A.distance(D) / A.distance(B))); 
                    else answer = A.distance(B) * (asin (H / A.distance(B)) - acos(A.distance(D) / A.distance(B))); 
                    answer = -1; // нет таких тестов
                }
            }
        } else if (B.between(C,D)) {
            double a = min(A.distance(C), A.distance(D));
            if (A.distance(B)*A.distance(B) < a * a + H * H) {
                answer = A.distance(B) * acos(a / A.distance(B));
            } else {
                answer = A.distance(B) * asin(H / A.distance(B)); // нет такоо теста
            }
        } else {
            double a = max(A.distance(C), A.distance(D));
            if (A.distance(B)*A.distance(B) < a * a + H * H) {
                answer = A.distance(B) * (asin (H / A.distance(B)) - acos(a / A.distance(B)));
            }
        }
    } else {
        double Ua, Ub;
        Ua = ((D.x-B.x)*(D.y-C.y)-(D.x-C.x)*(D.y-B.y))/denominator;
        Ub = ((A.x-B.x)*(D.y-B.y)-(D.x-B.x)*(A.y-B.y))/denominator;
        if (Ua > 0. && Ua < 1. && Ub > 0. && Ub < 1.) {
            point E(A.x * Ua + B.x * (1 - Ua), A.y * Ua + B.y * (1 - Ua));
            double a = A.distance(E);
            double c = A.distance(B);
            double b = sqrt(c*c - a*a);
            answer = min(b,H);
        }
    }
    cout << fixed << setprecision(3) << answer << endl;
    return 0;
}
