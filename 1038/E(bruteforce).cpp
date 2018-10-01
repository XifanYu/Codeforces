#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef double db;
typedef complex<db> cd;

ll qpow(ll x,ll k,ll mod)
{
    ll ret=1;
	while(k)
	{
	   if(k&1)	
	   {
	   	 ret=ret*x;
	   	 ret=ret%mod;
	   }
	   x=x*x;
	   x=x%mod;
	   k=(k>>1);
	}
	return ret;	
}
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

const int Maxs=21381400;

int n;
int x[6]={1,2,3,2,3,3},y[6]={0,0,0,1,1,2};
int state[16];
int v[6];
vector<int> val[6];
int sum[4];
int ans=0;

void bruteforce(int a[6])
{
	int tmp=0;
	for(int i=0;i<6;i++)
	{
		if(a[i]) tmp+=val[i][a[i]-1];
	}
	for(int i=0;i<3;i++)
	{
		if(a[i]&&a[5-i]&&tmp==val[i][a[i]-1]+val[5-i][a[5-i]-1]) return;
	}
	int deg[4]={0};
	bool hit[4]={false};
	for(int i=0;i<6;i++)
	{
		if(a[i]&1)
		{
			deg[x[i]]++;
			deg[y[i]]++;
		}
		if(a[i])
		{
			hit[x[i]]=true;
			hit[y[i]]=true;
		}
	}
	int cnt=0;
	for(int i=0;i<4;i++)
	{
		if(deg[i]&1) cnt++;
	}
	if(cnt>2) return;
	for(int i=0;i<4;i++)
	{
		if(hit[i]) tmp+=sum[i];
	}
	ans=max(ans,tmp);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<6;i++)
	{
		state[x[i]+y[i]*4]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;c--;
		if(a==c)
		{
			sum[a]+=b;
			continue;
		}
		if(a<c) swap(a,c);
		int t=a+c*4;
		val[state[t]].PB(b);
		v[state[t]]++;
	}
	for(int i=0;i<6;i++) 
	{
		sort(all(val[i]));
		reverse(all(val[i]));
		for(int j=1;j<val[i].size();j++)
		{
			val[i][j]+=val[i][j-1];
		}
	}
	for(int a0=0;a0<=v[0];a0++)
	{
		for(int a1=0;a1<=v[1];a1++)
		{
			for(int a2=0;a2<=v[2];a2++)
			{
				for(int a3=0;a3<=v[3];a3++)
				{
					for(int a4=0;a4<=v[4];a4++)
					{
						for(int a5=0;a5<=v[5];a5++)
						{
							int a[6]={a0,a1,a2,a3,a4,a5};
							bruteforce(a);
						}
					}
				}
			}
		}
	}
	for(int i=0;i<4;i++)
	{
		ans=max(ans,sum[i]);
	}
	printf("%d\n",ans);
	return 0;
}
