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

int have[256],need[256],spare=0,remain[256];

int main(){
	string s,t;
	cin>>s;
	cin>>t;
	for(int i=0;i<t.length();i++) need[t[i]]++;
	for(int i=0;i<s.length();i++){
		if(s[i]!='?') have[s[i]]++;
		else spare++;
	}
	int lb=0,ub=1e6+1;
	while(ub-lb>1){
		int mi=(ub+lb)>>1;
		long long sum=0;
		for(int i='a';i<='z';i++){
			sum+=((long long)mi*need[i]-have[i]>0?(long long)mi*need[i]-have[i]:0);
		}
		if(sum<=spare) lb=mi;
		else ub=mi;
	}
	for(int i='a';i<='z';i++){
		remain[i]=((long long)lb*need[i]-have[i]>0?(long long)lb*need[i]-have[i]:0);
	}
	int id='a';
	for(int i=0;i<s.length();i++){
		if(s[i]!='?') printf("%c",s[i]);
		else{
			while(remain[id]==0&&id<'z') id++;
			printf("%c",char(id));
			remain[id]--;
		}
	}
	printf("\n");
return 0;
}
