#include <iostream>
#include <iomanip>

using namespace std;

long long fibArray[100];

long long fib(int n){
    if(fibArray[n]!=0) return fibArray[n];
    else if(n == 0) return fibArray[n] = 0;
    else if(n==1) return fibArray[n] = 1;
    else return fibArray[n] = fib(n-1)+fib(n-2);
}

int main() {
    int n;
    cin>>n;
    int count = 0;
    long long sum = 0;
    for(int i = 1; sum<n; i++){
        sum += fib(i);
        if(sum <= n) count++;
    }
    cout<<count;
    return 0;
}
