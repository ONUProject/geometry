#include <iostream>
#include <cmath>
using namespace std;

const int ARRAY_SIZE = 205;
const int NUM_INCREASE = 102;

int A[ARRAY_SIZE][ARRAY_SIZE];
int dfs (int i, int j)
{
    int ans = 0;
    A[i][j]=2;
    if (A[i+1][j]==0) {
        ans++;
    }
    if (A[i][j+1]==0) {
        ans++;
    }
    if (A[i-1][j]==0) {
        ans++;
    }
    if (A[i][j-1]==0) {
        ans++;
    }
    if (A[i+1][j]==1) {
        ans += dfs(i+1, j);
    }
    if (A[i][j+1]==1) {
        ans += dfs(i, j+1);
    }
    if (A[i-1][j]==1) {
        ans += dfs(i-1, j);
    }
    if (A[i][j-1]==1) {
        ans += dfs(i, j-1);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    for (int i=0; i<ARRAY_SIZE; i++) {
        for (int j=0; j<ARRAY_SIZE; j++) {
            A[i][j]=0;
        }
    }
    int a, b;
    for (int i=0; i<n; i++) {
        cin >> a >> b;
        A[a+NUM_INCREASE][b+NUM_INCREASE]=1;
    }
    int minX=1000, maxX=-1, minY=1000, maxY=-1;
    for (int i=0; i<205; i++) {
        for (int j=0; j<205; j++) {
            if (A[i][j]==1) {
                if(j<minX)
                    minX=j;
                if (j>maxX)
                    maxX=j;
                if (i<minY)
                    minY=i;
                if (i>maxY)
                    maxY=i;
            }
        }
    }
    int minMaxSide = max(maxX - minX + 1, maxY - minY + 1);
    int ans = 0;
    for (int i=0; i<ARRAY_SIZE; i++)
    {
        for (int j=0; j<ARRAY_SIZE; j++)
        {
            if (A[i][j]==1)
            {
                ans += dfs(i, j);
            }
        }
    }
    int maxSideForMaxSquare = (int) ceil(ans/4.0);
    if(maxSideForMaxSquare < minMaxSide){
        int secondSide = (ans - 2*minMaxSide)/2;
        cout<< minMaxSide * secondSide - n;
    }
    else{
        int minSideForMaxSquare = (int) floor(ans/4.0);
        cout<<maxSideForMaxSquare * minSideForMaxSquare - n;
    }


    return 0;

}
