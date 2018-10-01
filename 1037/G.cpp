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

const int Maxn=1e5+5;

char s[Maxn];
int n;
int pre[Maxn][26],nxt[Maxn][26]; //previous occurence and next occurence of character c at position i: pre[i][c], nxt[i][c]
int sum[Maxn],lsum[Maxn][26],rsum[Maxn][26]; //xor sum of contiguous segments, prefix grundy number, and suffix grundy number
bool flag[26]; //used to calculate grundy number: grundy number equals the mex of the grundy numbers of its subsequent games

int grundy(int l,int r)
{
	clean(flag,false);
	for(int i=0;i<26;i++)
	{
		int p1=nxt[l][i],p2=pre[r][i];
		if(p1>p2) continue;
		int val=(rsum[l][i]^sum[p2]^sum[p1]^lsum[r][i]);
		flag[val]=true;
	}
	for(int i=0;i<26;i++) if(!flag[i]) return i;
	return 26;
}

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) s[i]-='a';
	s[0]=s[n+1]=-1;
	vector<pi> seg;
	for(int j=0;j<26;j++) pre[0][j]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
		{
			pre[i][j]=(j==s[i])?i:pre[i-1][j];
			seg.PB(pi(i,-pre[i][j]-1));
		}
	}
	for(int j=0;j<26;j++) nxt[n+1][j]=n+1;
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<26;j++)
		{
			nxt[i][j]=(j==s[i])?i:nxt[i+1][j];
			seg.PB(pi(nxt[i][j]-1,-i));
		}
	}
	sort(all(seg)); //first sort by the segments' right ends(left to right), and then sort by the segments' left end(right to left)
	seg.resize(unique(all(seg))-seg.begin());
	for(auto v:seg)
	{
		int l=-v.SS,r=v.FF;
		int x=grundy(l,r);
		if(s[l-1]>=0&&s[l-1]==s[r+1]) //is a whole segment indicated by two consecutive positions of the same character 
		{
			sum[r+1]=(sum[l-1]^x);
		}
		if(s[l-1]>=0&&pre[r][s[l-1]]==l-1) //is a prefix
		{
			lsum[r][s[l-1]]=x;
		}
		if(s[r+1]>=0&&nxt[l][s[r+1]]==r+1) //is a suffix
		{
			rsum[l][s[r+1]]=x;
		}
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		if(grundy(l,r)) puts("Alice");
		else puts("Bob"); 
	}
	return 0;
}
