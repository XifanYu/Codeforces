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

unordered_map<string,int> mp;
int n;



unordered_set<string> ss[70005];

int main(){
	scanf("%d",&n);
	getchar();
	for(int t=1;t<=n;t++){
		string s;
		char c;
		while((c=getchar())>='0'){
			s+=c;
		}
		for(int i=0;i<9;i++){
			string val="";
			for(int j=i;j<9;j++){
				val+=s[j];
				ss[t].insert(val);
			}
		}
		unordered_set<string>::iterator it=ss[t].begin();
		while(it!=ss[t].end()){
			mp[*it]++;
			it++;
		}
	}
	for(int t=1;t<=n;t++){
		unordered_set<string>::iterator it=ss[t].begin();
		string ans="99999999999";
		while(it!=ss[t].end()){ 
			if(mp[*it]==1){
				if((*it).length()<ans.length()) ans=*it;
			}
			it++;
		}
		cout<<ans<<"\n";
	}
return 0;
}
