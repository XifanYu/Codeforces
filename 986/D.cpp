#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl; 
typedef double db;

const int mod=1e9+7;
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

const int Maxn=1500015;

const db PI=acos(-1);



//complex part

struct cd
{
	db x,y;
	cd()
	{
		x=0.0;y=0.0;
	}
	cd(int X)
	{
		x=X;y=0.0;
	}
	cd(db X,db Y)
	{
		x=X;y=Y;
	}
	cd operator+(cd & o)
	{
		return cd(x+o.x,y+o.y);
	}
	cd operator-(cd & o)
	{
		return cd(x-o.x,y-o.y);
	}
	cd operator*(cd & o)
	{
		return cd(x*o.x-y*o.y,x*o.y+y*o.x);
	}
	cd operator/(const int & o)
	{
		return cd(x/o,y/o);
	}
	cd operator+=(cd & o)
	{
		*this = *this + o;
		return *this;
	}
	cd operator-=(cd & o)
	{
		*this = *this - o;
		return *this;
	}
	cd operator*=(cd & o)
	{
		*this = *this * o;
		return *this;
	}
	cd operator/=(const int & o)
	{
		*this = *this / o;
		return *this;
	}
	ll real()
	{
		return (ll)(x+0.5);
	}
};



//fft part

cd p1[Maxn],p2[Maxn];

struct FFT
{
    int reverse(int num,int k)
    {
    	int res=0;
    	for(int i=0;i<k;i++)
    	{
    		if((num>>i)&1)
    		{
    			res|=(1<<(k-i-1));
			}
		}
		return res;
	}

    void transform(cd *a,const int n,bool invert) 
	{
        int k=0;
        while((1<<k)<n) k++;
        for(int i=0;i<n;i++)
        {
        	int x=reverse(i,k);
        	if(i<x)
        	{
        		swap(a[i],a[x]);
			}
		}
		for(int len=2;len<=n;len=(len<<1))
		{
			db ang=2.0*PI/len*(invert?-1:1);
			cd wlen=cd(cos(ang),sin(ang));
			for(int i=0;i<n;i+=len)
			{
				cd w=cd(1);
				for(int j=0;j<len/2;j++)
				{
					cd u=a[i+j],v=a[i+j+len/2]*w;
					a[i+j]=u+v;
					a[i+j+len/2]=u-v;
					w*=wlen;
				}
			}
		}
		if(invert)
		{
			for(int i=0;i<n;i++)
			{
				a[i]/=n;
			}
		}
    }

    void dft(cd *a,const int n) 
	{
        transform(a,n,false);
    }

    void idft(cd *a,const int n) 
	{
        transform(a,n,true);
    }
    
    void multiply(ll *a,int na,ll *b,int nb,ll *c) 
	{
	    
	    int n=1;
	    while(n<na+nb) n=(n<<1);
	    
	    for(int i=0;i<na;i++) p1[i]=a[i];
	    for(int i=0;i<nb;i++) p2[i]=b[i];
	    
	    for(int i=na;i<n;i++) p1[i]=0;
	    for(int i=nb;i<n;i++) p2[i]=0;
	    
	    dft(p1,n);
	    dft(p2,n);
	    
	    for(int i=0;i<n;i++) p1[i]*=p2[i];
	    idft(p1,n);
	    
		for(int i=0;i<n;i++) c[i]=round(p1[i].real());
	}
    
}fft;



//big integer arithmetic part

void push(ll *a, int & len)
{
	ll carry=0;
	for(int i=0;i<len;i++)
	{
		ll tmp=a[i]+carry;
		carry=tmp/1000;
		a[i]=tmp%1000;
	}
	while(carry)
	{
		a[len]=carry%1000;
		len++;
		carry=carry/1000;
	}
}

bool cmp(ll *a,int & alen,ll *b,int & blen)
{
	if(alen>blen) return true;
	if(alen<blen) return false;
	for(int i=alen-1;i>=0;i--)
	{
		if(a[i]>b[i]) return true;
		if(a[i]<b[i]) return false;
	}
	return true;
}

void mult1(ll *a,int & alen,int o,ll *b,int & blen)
{
	for(int i=0;i<alen;i++)
	{
		b[i]=a[i]*o;
	}
	blen=alen;
	push(b,blen);
}

void mult2(ll *a,int & alen,ll *b,int & blen,ll *c,int & clen)
{
	fft.multiply(a,alen,b,blen,c);
	clen=alen+blen-1;
	push(c,clen);
}

void qpow(ll *a,int & len,int k)
{
	if(k==0)
	{
		a[0]=1;
		len=1;
		return;
	}
	qpow(a,len,k>>1);
	mult2(a,len,a,len,a,len);
	if(k&1) mult1(a,len,3,a,len);
}



//allocate three arrays for three big integers

ll n[Maxn];
int nlen;
ll x[Maxn];
int xlen;
ll y[Maxn];
int ylen;

char s[Maxn];
int l;


//start of main

int main()
{
	scanf("%s",s);
	l=strlen(s);
	reverse(s,s+l);
	if(l==1)
	{
		int tmp[10]={0,1,2,3,4,5,5,6,6,6};
		printf("%d\n",tmp[s[0]-'0']);
		return 0;
	}
	nlen=0;
	for(int i=0;i<l;i+=3)
	{
		n[nlen]=0;
		n[nlen]+=s[i]-'0';
		if(i+1<l) n[nlen]+=10*(s[i+1]-'0');
		if(i+2<l) n[nlen]+=100*(s[i+2]-'0');
		nlen++;
	}
	int t=(l-1)*log(10)/log(3);
	t--;
	qpow(x,xlen,t);
	int ans=t*3;
	for(;;mult1(x,xlen,3,x,xlen))
	{
		for(int i=2;i<=4;i++)
		{
			mult1(x,xlen,i,y,ylen);
			if(cmp(y,ylen,n,nlen))
			{
				ans+=i;
				printf("%d\n",ans);
				return 0;
			}
		}
		ans+=3;
	}
	return 0;
}
