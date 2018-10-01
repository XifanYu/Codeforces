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

const int Maxn=200005;

int n;
int a[Maxn];
int num[Maxn];
vector<int> ex;
int ans=0;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		num[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(num[i]==0){
			ex.push_back(i);
		}
	}
	int id=0;
	for(int i=1;i<=n;i++){
		int x=a[i];
		if(num[x]>=2){
			if(x<ex[id]) num[x]=-1;
			else {
				a[i]=ex[id++]; 
				ans++;
				num[x]-=1;
			}
		}
		else if(num[x]==-1){
			a[i]=ex[id++];
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++){
		if(i>1) printf(" ");
		printf("%d",a[i]);
	}
	printf("\n");
return 0;
}
