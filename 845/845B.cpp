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
	string s;
	cin>>s;
	int sum1=0,sum2=0;
	for(int i=0;i<3;i++) sum1+=s[i]-'0';
	for(int i=3;i<6;i++) sum2+=s[i]-'0';
	int ic[6],dc[6];
	for(int i=0;i<6;i++){
		ic[i]=(i<3?9-(s[i]-'0'):(s[i]-'0'));
		dc[i]=(i<3?(s[i]-'0'):9-(s[i]-'0'));
	}
	sort(ic,ic+6);
	sort(dc,dc+6);
	reverse(ic,ic+6);
	reverse(dc,dc+6);
	int dif=sum1-sum2;
	int id=0;
	while(dif!=0){
		if(dif>0){
			dif-=dc[id++];
			if(dif<0) dif=0;
		}
		else{
			dif+=ic[id++];
			if(dif>0) dif=0;
		}
	}
	printf("%d\n",id);
return 0;
}
