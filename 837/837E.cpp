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
using namespace std;

long long gcd(long long m,long long n){
	if(n==0) return m;
	else return gcd(n,m%n);
}

long long f(long long m,long long n){
	long long p=1,mint=n;
	if(m==1) return n;
	if(n==0) return 0;
	if(m>=n){
		for(long long i=2;i<=sqrt(m);i++){
			if(m%i==0){
				long long x=n%i;
				if(x<=mint){
					mint=x;
					p=i;
				}
			}
		}
		for(long long i=sqrt(m);i>=2;i--){
			if(m%i==0){
				long long y=n%(m/i);
				if(y<=mint){
					mint=y;
					p=m/i;
				}
			}
		}
		if(p==1) return n;
		return mint+f(m/p,n/p);
	}
	if(m<n){
		for(long long i=2;i<=sqrt(m);i++){
			if(m%i==0){
				long long x=n%i;
				if(x<=mint){
					mint=x;
					p=i;
				}
			}
		}
		for(long long i=sqrt(m);i>=1;i--){
			if(m%i==0){
				long long y=n%(m/i);
				if(y<=mint){
					mint=y;
					p=m/i;
				}
			}
		}
		return mint+f(m/p,n/p);
	}
}

int main(){
	long long a,b;
	scanf("%I64d %I64d",&a,&b);
	long long x=gcd(a,b);
	printf("%I64d\n",f(a/x,b/x));
return 0;
}
