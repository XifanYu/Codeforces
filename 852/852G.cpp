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

int n,m;
map<string,int> ct;
set<string> used[5005];
string s;

int calc(string &t, int pos, string nt=""){
	if(pos==t.length()){
		if(used[m].count(nt)){
			return 0;
		}
		else{
			used[m].insert(nt);
			return ct[nt];
		}
	} 
	if(t[pos]=='?'){
		int sum=calc(t,pos+1,nt);
		for(int i=0;i<5;i++){
			sum+=calc(t,pos+1,nt+char('a'+i));
		}
		return sum;
	}
	return calc(t,pos+1,nt+t[pos]);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>s;
		ct[s]++;
	}
	while(m--){
		cin>>s;
		printf("%d\n",calc(s,0));
	}
return 0;
}
