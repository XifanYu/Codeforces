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

typedef pair<int,int> pi;
typedef long long ll;

const int Maxn=105;
int a[Maxn];
int num1=0,num0=0;
int l[Maxn],r[Maxn];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i]) num1++;
	}
	l[0]=0;
	r[0]=num1;
	int maxt=l[0]+r[0];
	for(int i=1;i<=n;i++){
		if(!a[i]) num0++;
		else num1--;
		l[i]=num0;
		r[i]=num1;
		maxt=max(maxt,l[i]+r[i]);
	}
	printf("%d\n",maxt);
return 0;
}
