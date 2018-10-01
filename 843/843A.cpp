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

const int Maxn=100005;

int n;
int a[Maxn],b[Maxn];
bool used[Maxn];
int insort[Maxn];
map<int,int> mp;
vector<vector<int> >ans;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",a+i);
		b[i]=a[i];
		mp[a[i]]=i;
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++){
		insort[mp[b[i]]]=i;
	}
	memset(used,0,sizeof used);
	for(int i=1;i<=n;i++){
		if(used[i]) continue;
		int j=i;
		vector<int> ss;
		ss.push_back(j);
		used[j]=true;
		while(insort[j]!=i){
			j=insort[j];
			ss.push_back(j);
			used[j]=true;
		}
		ans.push_back(ss);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d",ans[i].size());
		sort(ans[i].begin(),ans[i].end());
		for(int j=0;j<ans[i].size();j++){
			printf(" %d",ans[i][j]);
		}
		printf("\n");
	}
return 0;
}
