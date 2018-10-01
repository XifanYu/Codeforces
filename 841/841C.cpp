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

int m,a[200005],b[200005];
int sorteda[200005],sortedb[200005];
map<int,vector<int> > mp;
map<int,int> nmp;

int main(){
	scanf("%d",&m);
	for(int i=1;i<=m;i++) {
		scanf("%d",a+i);
		sorteda[i]=a[i];
	}
	for(int i=1;i<=m;i++) {
		scanf("%d",b+i);
		sortedb[i]=b[i];
	}
	sort(sortedb+1,sortedb+m+1);
	sort(sorteda+1,sorteda+m+1);
	reverse(sorteda+1,sorteda+m+1);
	int i=1;
	while(i<=m){
		vector<int> p;
		while(sortedb[i]==sortedb[i+1]){
			p.push_back(sorteda[i]);
			i++;
		}
		p.push_back(sorteda[i]);
		mp[sortedb[i]]=p;
		nmp[sortedb[i]]=p.size();
		i++;
	}
	for(int i=1;i<=m;i++){
		if(i-1) printf(" ");
		int x=nmp[b[i]]-1;
		printf("%d",mp[b[i]][x]);
		nmp[b[i]]=x;
	}
	printf("\n");
return 0;
}
