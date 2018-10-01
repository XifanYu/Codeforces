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

typedef long long ll;

int n,k;

int main(){
	scanf("%d%d",&n,&k);
	if(k==1){
		cout<<"1\n";
	}
	else if(k==2){
		ll ans=1;
		ll wp=n*(n-1)/2;
		ans+=wp;
		cout<<ans<<"\n";
	}
	else if(k==3){
		ll ans=1;
		ll wp=n*(n-1)/2;
		ans+=wp;
		ll wp3=(n*(n-1)*(n-2)/6);
		wp3*=2;
		ans+=wp3;
		cout<<ans<<"\n";
	}
	else if(k==4){
		ll ans=1;
		ll wp=n*(n-1)/2;
		ans+=wp;
		ll wp3=(n*(n-1)*(n-2)/6);
		wp3*=2;
		ans+=wp3;
		ll wp4=((ll)n*(n-1)*(n-2)*(n-3)/24);
		wp4*=9;
		ans+=wp4;
		cout<<ans<<"\n";
	}
return 0;
}
