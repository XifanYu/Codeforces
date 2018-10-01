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

int n;
string s;
int ans=0;

int main(){
	cin>>n;
	cin>>s;
	int l=0,r=0;
	while(l<n){
		bool fa[256];
		memset(fa,0,sizeof fa);
		int now=0;
		while(r<n&&s[r]<='z'&&s[r]>='a'){
			if(!fa[s[r]]){
				now++;
				fa[s[r]]=true;
			}
			r++;
		}
		r++;
		l=r;
		ans=max(ans,now); 
	}
	printf("%d\n",ans);
return 0;
}
