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
int a[200005];
bool visit[200005];
stack<int> stk;
int now=1;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",a+i);
	}
	int pos=1;
	while(now<=n){
		if(pos<=k) {
			visit[a[pos]]=true;
			stk.push(a[pos++]);
		}
		else{
			int j=now;
			while(j<=n&&!visit[j])j++;
			for(int i=0;i<j-now;i++){
				a[pos+i]=j-i-1;
			}
			pos=pos+j-now;
			now=j;
		}
		while(!stk.empty()&&stk.top()==now){
			stk.pop();
			now++;
		}
		if(visit[now]){
			printf("-1\n");
			exit(0);
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
return 0;
}
