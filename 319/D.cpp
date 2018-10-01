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

#define MP make_pair
#define FF first
#define SS second
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n;i;i--)
#define rrep0(i,n) for(int i=n-1;i>=0;i--)
#define forw(v) (v).begin(),(v).end()

typedef long long ll;
typedef pair<int,int> pi; 
typedef double db; 

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=5e4+5;
const int k=37;
const int md=1e9+7;
const ll MD=(ll)md*md;
char s[Maxn];
ll pw[Maxn];
ll hsh[Maxn];
int n;

ll get(int i,int j)
{
	return (hsh[j]-hsh[i-1]*pw[j-i+1]+MD)%md;
}

int pp(int i,int j)//longest previous substring
{
	int lb=0,ub=i+1;
	while(ub-lb>1)
	{
		int mi=(ub+lb)>>1;
		if(get(i-mi+1,i)==get(j-mi+1,j)) lb=mi;
		else ub=mi;
	}
	return lb;
}

int ss(int i,int j)//longest subsequent substring
{
	int lb=0,ub=n-j+2;
	while(ub-lb>1)
	{
		int mi=(ub+lb)>>1;
		if(get(i,i+mi-1)==get(j,j+mi-1)) lb=mi;
		else ub=mi;
	}
	return lb;
}

void solve(int x)
{
	int cur=1;
	int d=n-2*x+1,i;
	for(i=1;i<=d;i++)
	{
		if(get(i,i+x-1)==get(i+x,i+2*x-1)) i+=x-1;
		else s[cur++]=s[i];
	}
	for(;i<=n;i++)
	{
		s[cur++]=s[i];
	}
	n=--cur;
}

bool check(int i)
{
	for(int l=i;l+i<=n;l+=i)
	{
		if(pp(l,l+i)+ss(l,l+i)>=i+1) return true;
	}
	return false;
}

void prepare()
{
	hsh[0]=0;
	for(int i=1;i<=n;i++) hsh[i]=(hsh[i-1]*k+s[i])%md;
}

int main()
{
	scanf("%s",s+1);
	for(n=1;s[n];n++);
	n--;
	pw[0]=1;
	for(int i=1;i<=n;i++) pw[i]=(pw[i-1]*k)%md;
	prepare();
	for(int i=1;i<=n/2;i++)
	{
		if(check(i))
		{
			solve(i);
			prepare();
		}
	}
	s[n+1]=0;
	printf("%s\n",s+1);
	return 0;
}
