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

int a[11],b[11];

int main(){
	int n,m;
	cin>>n>>m;
	int t1=10,t2=10;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		t1=min(t1,a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",b+i);
		t2=min(t2,b[i]);
	}
	int t=100;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==b[j]) t=min(t,a[i]);
		}
	}
	cout<<min(t,(min(t1,t2)*10+max(t1,t2)))<<"\n";
return 0;
}
