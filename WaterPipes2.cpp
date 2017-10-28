#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int *P;
struct wor
{
	double a;
	int b, c;
};

bool cmd (wor w1, wor w2)
{
	return w1.a<w2.a;
}

wor *C;

int find_set (int a)
{
	if (a==P[a])
		return a;
	return find_set(P[a]);	
}

void union_set (int a, int b, int *q)
{
	a=find_set(a);
	b=find_set(b);
	if (a!=b)
	{
		P[b]=a;
		*q=1;
	}
}

int main() {
	int n, t=0;
	cin >> n;
	C=new wor[n*(n-1)/2];
	P=new int[n];
	int X[n], Y[n];
	for (int i=0; i<n; i++)
	{
		cin >> X[i] >> Y[i];
		P[i]=i;
	}
	for (int i=0; i<n; i++)
	{
		for (int j=i+1; j<n; j++)
		{
			C[t].a=sqrt((X[j]-X[i])*(X[j]-X[i])+(Y[j]-Y[i])*(Y[j]-Y[i]));
			C[t].b=i;
			C[t].c=j;
			t++;
		}
	}
	int q=0;
	double ans=0;
	sort (C, C+n*(n-1)/2, cmd);
	for (int i=0; i<n*(n-1)/2; i++)
	{
		union_set(C[i].b,C[i].c, &q);
		if (q==1)
			ans+=C[i].a;
		q=0;
	}
	cout << round (ans);
	return 0;
}
