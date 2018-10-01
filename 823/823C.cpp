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
using namespace std;

char s[2000005];
string str[100005];
vector<pair<pair<int,int>,int> > intv;


int main(){
	int n;
	fill(s,s+1000005,'a');
	cin>>n;
	for(int i=1;i<=n;i++){
		string t;
		cin>>t;
		str[i]=t;
		int l=t.length()-1;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x;
			cin>>x;
			intv.push_back(make_pair(make_pair(x,x+l),i));
		}
	}
	sort(intv.begin(),intv.end());
	int len=intv.size();
	int last=0;
	for(int i=0;i<len;i++){
		int a,b,c;
		a=intv[i].first.first;
		b=intv[i].first.second;
		c=intv[i].second;
		if(b<=last) continue;
		else{
			for(int j=b,pos=str[c].length()-1;j>max(last,a-1);j--,pos--) s[j]=str[c][pos];
			last=b;
		}
	}
	for(int i=1;i<=last;i++) cout<<s[i];
return 0;
}
