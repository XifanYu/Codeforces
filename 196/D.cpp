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
#include <functional>
#include <string.h>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi; 
typedef double db;

const int mod=1e9+7;
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
#define MP make_pair
#define FF first
#define SS second
#define LB lower_bound
#define UB upper_bound
#define PB push_back
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rrep(i,b,a) for(int i=b;i>=a;i--)
#define all(v) (v).begin(),(v).end()
#define clean(v,a) memset(v,a,sizeof(v))
#define get(a) scanf("%d",&a)
#define get2(a,b) scanf("%d%d",&a,&b)
#define get3(a,b,c) scanf("%d%d%d",&a,&b,&c)

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=4e5+5;
const ll md=122420729;
const ll A=md*md;
const int h=31;
const int base='a'-1;

int d,n;
char s[Maxn];
ll pre[Maxn],suf[Maxn];
ll pw[Maxn];

ll getPre(int l,int r)
{
	ll ret=((pre[r]-pre[l-1]*pw[r-l+1]+A)%md)*pw[l-1]%md;
	return ret;
}

ll getSuf(int l,int r)
{
	ll ret=(suf[r]-suf[l-1]+md)%md;
	return ret;
}

bool check(int l,int r)
{
	return getPre(l,r)==getSuf(l,r);
}

int main()
{
	scanf("%d%s",&d,s+1);
	n=strlen(s+1);
	pw[0]=1;
	rep(i,1,n)
	{
		pre[i]=(pre[i-1]*h+s[i]-base)%md;
		pw[i]=pw[i-1]*h%md;
	}
	rep(i,1,n)
	{
		suf[i]=(suf[i-1]+pw[i-1]*(s[i]-base))%md;
	}
	int bp=n;
	rep(i,1,n)
	{
		if(i>=d) 
		{
			if(check(i-d+1,i))
			{
				bp=i;
				break;
			}
		}
		if(i>d)
		{
			if(check(i-d,i))
			{
				bp=i;
				break;
			}
		}
	}
	while(bp>=1)
	{
		bool cont=true;
		while(s[bp]<'z')
		{
			s[bp]++;
			pre[bp]=(pre[bp-1]*h+s[bp]-base)%md;
			suf[bp]=(suf[bp-1]+pw[bp-1]*(s[bp]-base))%md;
			if(bp>=d)
			{
				if(check(bp-d+1,bp))
				{
					continue;
				}
			}
			if(bp>d)
			{
				if(check(bp-d,bp))
				{
					continue;
				}
			}
			cont=false;
			break;
		}
		if(cont) bp--;
		else break;
	}
	if(bp==0)
	{
		printf("Impossible\n");
		return 0;
	}
	while(bp<n)
	{
		bp++;
		s[bp]='a'-1;
		bool ok=false;
		while(s[bp]<'z')
		{
			s[bp]++;
			pre[bp]=(pre[bp-1]*h+s[bp]-base)%md;
			suf[bp]=(suf[bp-1]+pw[bp-1]*(s[bp]-base))%md;
			if(bp>=d)
			{
				if(check(bp-d+1,bp))
				{
					continue;
				}
			}
			if(bp>d)
			{
				if(check(bp-d,bp))
				{
					continue;
				}
			}
			ok=true;
			break;
		}
		if(!ok)
		{
			printf("Impossible\n");
			return 0;
		}
	}
	printf("%s",s+1);
	return 0;
}
