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

const int Maxn=505;
int w[Maxn],b[2*Maxn],s[3*Maxn];
bool used[Maxn];

int n,m,l,r,ans=0;

void process(){
	r=n;
	l=n;
	for(int i=1;i<=m;i++){
		if(!used[b[i]]) {
			s[l]=b[i];
			used[b[i]]=true;
			l--;
		}
	}
	l++;
}

void count(int i){
	int id;
	for(id=l;id<=r;id++){
		if(s[id]==b[i]) break;
	}
	int c=id+1;
	for(c;c<=r;c++) ans+=w[s[c]];
	s[++r]=s[id];
	for(id;id>l;id--) s[id]=s[id-1];
	l++;
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",w+i);
	for(int i=1;i<=m;i++) scanf("%d",b+i);
	process();
	for(int i=1;i<=m;i++) count(i);
	printf("%d\n",ans);
return 0;
}
