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

int main(){
	int n;
	scanf("%d",&n);
	string s;
	cin>>s;
	int i=0;
	string ans; 
	char c='0';
	for(i;i<n;i++){
		if(s[i]=='1'){
			c+=1;
		}
		else if(c!='0'){
			ans+=c;
			c='0';
			if(i+1>=n||(i+1<n&&s[i+1]=='0'))ans+='0';
		}
		else if(i+1>=n||(i+1<n&&s[i+1]=='0'))ans+='0';
	}
	if(c!='0') ans+=c;
	cout<<ans<<endl;
}
