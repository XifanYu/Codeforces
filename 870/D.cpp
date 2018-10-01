#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <memory.h>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const int Maxn=5005;

int n;
int xp[Maxn];
int xb[Maxn];
int p[Maxn];
int b[Maxn];
vector<int> v;

bool check(int x)
{
	p[0]=x;
	b[0]=(xp[0]^x);
	for(int i=1;i<n;i++)
	{
		p[i]=(xp[i]^b[0]);
		b[i]=(xb[i]^p[0]);
	}
	for(int i=0;i<n;i++)
	{
		if(p[b[i]]!=i) 
		{
			return false;
		}
	}
	return true;
}

void print(int x)
{
	int b0=(xp[0]^x);
	for(int i=0;i<n;i++)
	{
		printf("%d ",(xp[i]^b0));
	}
	printf("\n");
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("? %d %d\n",i,0);
		fflush(stdout);
		scanf("%d",xp+i);
	}
	for(int i=1;i<n;i++)
	{
		printf("? %d %d\n",0,i);
		fflush(stdout);
		scanf("%d",xb+i);
	}
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		if(check(i))
		{
			v.push_back(i);
		}
	}
	printf("!\n%d\n",v.size());
	print(v[0]);
	return 0;
}
