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

typedef pair<int,int> pi;

int n;
int a[30];
int b[30];
map<int,int> mp;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",a+i);
	memcpy(b,a,sizeof a);
	sort(b+0,b+n);
	for(int i=0;i<n;i++) mp[b[i]]=i;
	for(int i=0;i<n;i++){
		if(i) printf(" ");
		printf("%d",b[(mp[a[i]]+1)%n]);
	}
	printf("\n");
return 0;
} 
