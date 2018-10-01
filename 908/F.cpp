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
typedef pair<int,int> pi; 

int n,x;
string s;
ll cost=0;

int main(){
	scanf("%d",&n);
	int pr=-1,pg=-1,pb=-1;
	int mr=0,mb=0;
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		cin>>s;
		if(s=="G"){
			if(pr!=-1){
				cost+=x-pr;
				mr=max(mr,x-pr);
			}
			if(pb!=-1){
				cost+=x-pb;
				mb=max(mb,x-pb);
			}
			if(pg!=-1&&mr+mb>x-pg){
				cost-=(mr+mb)-(x-pg);
			}
			pr=pb=pg=x;
			mr=mb=0;
		}
		else if(s=="R"){
			if(pr!=-1){
				cost+=(x-pr);
				mr=max(mr,x-pr);
			}
			pr=x;
		}
		else if(s=="B"){
			if(pb!=-1){
				cost+=(x-pb);
				mb=max(mb,x-pb);
			}
			pb=x;
		}
	}
	printf("%I64d\n",cost);
return 0;
}
