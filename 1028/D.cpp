#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef double db;
typedef complex<db> cd;

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
#define PQ priority_queue

/*
 * high precision: printf("%.12lf",(db)ans);
 *
 * clear output buffer: fflush(stdout);
 *
 * sync off: ios::sync_with_stdio(false);
 *
 */

const int md=1e9+7;

int n;
char tmp[10];
int x;
set<int> ss,ls,rs;
map<int,int> mp;
int ans=1;

int main()
{
	scanf("%d",&n);
	ss.clear();ls.clear();rs.clear();
	mp.clear();
	for(int i=1;i<=n;i++)
	{
		scanf("%s%d",tmp,&x);
		if(tmp[1]=='D')
		{
			if(!ls.empty()&&*ls.rbegin()>x)
			{
				mp[x]=1;
				ls.insert(x);
			}
			else if(!rs.empty()&&*rs.begin()<x)
			{
				mp[x]=2;
				rs.insert(x);
			}
			else ss.insert(x);
		}
		else
		{
			set<int>::iterator it=ss.LB(x),l=it,r=it,tp;
			if(it!=ss.end()&&*it==x)
			{
				if(!ls.empty()&&*ls.rbegin()>x)
				{
					printf("0\n");
					return 0;
				}
				if(!rs.empty()&&*rs.begin()<x)
				{
					printf("0\n");
					return 0;
				}
				ans=(ans*2)%md;
				r++;
				if(it!=ss.begin())
				{
					l--;
					bool flag=true;
					while(flag)
					{
						mp[*l]=1;
						ls.insert(*l);
						if(l==ss.begin()) flag=false;
						tp=l--;
						ss.erase(tp);
					}
				}
				while(r!=ss.end())
				{
					mp[*r]=2;
					rs.insert(*r);
					tp=r++;
					ss.erase(tp);
				}
				ss.erase(it);
			}
			else
			{
				if(mp[x]==1)
				{
					if(!ls.empty()&&*ls.rbegin()!=x)
					{
						printf("0\n");
						return 0;
					}
					ls.erase(x);
				}
				else
				{
					if(!rs.empty()&&*rs.begin()!=x)
					{
						printf("0\n");
						return 0;
					}
					rs.erase(x);
				}
				if(it!=ss.begin())
				{
					l--;
					bool flag=true;
					while(flag)
					{
						mp[*l]=1;
						ls.insert(*l);
						if(l==ss.begin()) flag=false;
						tp=l--;
						ss.erase(tp);
					}
				}
				while(r!=ss.end())
				{
					mp[*r]=2;
					rs.insert(*r);
					tp=r++;
					ss.erase(tp);
				}
			}
		}
	}
	if(!ss.empty())
	{
		ans=(ll)ans*(ss.size()+1)%md;
	}
	printf("%d\n",ans);
	return 0;
}
