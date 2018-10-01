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
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n;i;i--)
#define rrep0(i,n) for(int i=n-1;i>=0;i--)
#define forw(v) (v).begin(),(v).end()
#define clean(v,a) memset(v,a,sizeof(v))

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int Maxn=1e5+5;

char s[Maxn];
int n,m;
char mask[Maxn]; //available letters
int cnt[1<<6]; //cnt[j]: number of characters that belong to mask j
int num[1<<6]; //num[j]: number of masks in the array that are contained by mask j

//please check Hall's Theorem out before you solve this problem

void init()
{
	scanf("%s",s);
	n=strlen(s);
	scanf("%d",&m);
	clean(mask,(1<<6)-1);
	rep0(i,m)
	{
		int pos,j=0;
		char tmp[10];
		scanf("%d%s",&pos,tmp);
		mask[--pos]=0;
		while(tmp[j])
		{
			mask[pos]|=(1<<(tmp[j++]-'a'));
		}
	}
	rep0(i,n)
	{
		int x=s[i]-'a';
		rep0(j,(1<<6))
		{
			if((j>>x)&1) cnt[j]++;
			if((j&mask[i])==mask[i]) num[j]++;
		}
	}
}

void del(int pos,int val)
{
	rep0(i,(1<<6))
	{
		if((i>>val)&1) cnt[i]--;
		if((i&mask[pos])==mask[pos]) num[i]--;
	}
}

int main()
{
	init();
	rep0(i,n)
	{
		bool ok=false;
		rep0(j,6)
		{
			if(!((mask[i]>>j)&1)) continue;
			bool choose=true;
			rep0(k,(1<<6))
			{
				if(cnt[k]-((k>>j)&1)<num[k]-((k&mask[i])==mask[i]))
				{
					choose=false;
					break;
				}
			}
			if(choose)
			{
				del(i,j);
				ok=true;
				putchar(j+'a');
				break;
			}
		}
		if(!ok)
		{
			printf("Impossible\n");
			return 0;
		}
	}
	return 0;
}
