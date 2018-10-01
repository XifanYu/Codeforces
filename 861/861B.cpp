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
using namespace std;

int k[105],f[105];
int n,m;
bool ok[105];



int main(){
	cin>>n>>m;
	int l=1,r=1e9;
	for(int i=1;i<=m;i++){
		scanf("%d%d",k+i,f+i);
		int j1=(k[i]+f[i]-1)/f[i];
		int j2;
		if(f[i]>1) j2=(k[i]-1)/(f[i]-1);
		else j2=1e9;
		l=max(l,j1),r=min(r,j2);
		cout<<j1<<" "<<j2<<endl;
		cout<<l<<" "<<r<<endl;
	}
	if(l==r){
		cout<<(n-1)/l+1<<"\n";
	}
	else cout<<-1<<"\n";

return 0;
}
