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

class pnt
{
public:
	int x,y;
	pnt(int X,int Y)
	{
		x=X;y=Y;
	}
	bool operator<(const pnt & o)const
	{
		return x<o.x;
	}
	pnt operator+(pnt & o)
	{
		return pnt(x+o.x,y+o.y);
	}
	db ang()
	{
		return atan2(y,x);
	}
};

ll dis(pnt a)
{
	return (ll)a.x*a.x+(ll)a.y*a.y;
}

int q;
unordered_map<ll,set<pnt>> mp;//set of points with the same distance to the origin
unordered_map<db,int> cnt;//count of pairs of symmetrical points given a specific angle of the axis
int num=0;

void update(int t,pnt a)
{
	ll d=dis(a);
	if(t==1)
	{
		for(auto p:mp[d])
		{
			pnt ax=p+a;
			db ang=ax.ang();
			cnt[ang]+=2;
		}
		db ang=a.ang();
		cnt[ang]++;
		mp[d].insert(a);
		num++;
	}
	else
	{
		mp[d].erase(a);
		for(auto p:mp[d])
		{
			pnt ax=p+a;
			db ang=ax.ang();
			cnt[ang]-=2;
		}
		db ang=a.ang();
		cnt[ang]--;
		num--;
	}
}

int main()
{
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int t,x,y;
		scanf("%d%d%d",&t,&x,&y);
		if(t==3)
		{
			db ang=pnt(x,y).ang();
			printf("%d\n",num-cnt[ang]);
		}
		else
		{
			update(t,pnt(x,y));
		}
	}
	return 0;
}
