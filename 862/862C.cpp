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

int main(){
	int n,x;
	cin>>n>>x;
	if(n==1){
		cout<<"YES"<<"\n";
		cout<<x<<"\n";
	}
	else if(n==2){
		if(x!=0){
			cout<<"YES"<<"\n";
			cout<<0<<" "<<x<<"\n";
		}
		else cout<<"NO"<<"\n";
	}
	else{
		cout<<"YES\n";
		int pw=1<<17;
		int now=0;
		for(int i=1;i<=n-3;i++){
			printf("%d ",i);
			now^=i;
		}
		if(now==x){
			cout<<pw<<" "<<pw*2<<" "<<pw*3<<"\n";
		}
		else{
			cout<<0<<" "<<(pw^now)<<" "<<(pw^x)<<"\n";
		}
	}
return 0;
}
