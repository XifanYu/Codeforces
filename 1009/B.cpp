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

int len;
char s[Maxn];
vector<int> pos[3];
int id[3];

int main()
{
	scanf("%s",s);
	len=strlen(s);
	int now=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='0')
		{
			pos[0].PB(i);
		}
		else if(s[i]=='1')
		{
			pos[1].PB(i);
		}
		else
		{
			pos[2].PB(i);
		}
	}
	while(id[0]<pos[0].size()&&(pos[2].size()==0||pos[0][id[0]]<pos[2][id[2]]))
	{
		putchar('0');
		id[0]++;
	}
	for(;id[1]<pos[1].size();id[1]++) putchar('1');
	while(id[0]<pos[0].size()||id[2]<pos[2].size())
	{
		if(id[0]<pos[0].size()&&id[2]<pos[2].size())
		{
			if(pos[0][id[0]]<pos[2][id[2]])
			{
				putchar('0');
				id[0]++;
			}
			else
			{
				putchar('2');
				id[2]++;
			}
		}
		else if(id[0]<pos[0].size())
		{
			putchar('0');
			id[0]++;
		}
		else
		{
			putchar('2');
			id[2]++;
		}
	}
	return 0;
}
