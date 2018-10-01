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

string s;
int n;
char a[27]={'0','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
vector<int> pos[27];
int lenth[1505][1505];
int f_len[27][1505];
bool unappeared[27];

int find(char x){
	for(int i=1;i<=26;i++) if(a[i]==x) return i;
}

void process(){
	for(int i=1;i<=26;i++){
		fill(f_len[i]+1,f_len[i]+1505,2000);
		for(int j=1;j<=n;j++)fill(lenth[j]+0,lenth[j]+n,2000);
		char x=a[i];
		bool notok=true;
		for(int j=0;j<n;j++){
			if(s[j]==x) {pos[i].push_back(j);notok=false;}
		}
		if(notok) unappeared[i]=true;
		int siz=pos[i].size();
		for(int l=0;l<siz;l++){
			for(int r=l;r<siz;r++){
				lenth[l][r]=pos[i][r]-pos[i][l]-(r-l);
				f_len[i][r-l+1]=min(f_len[i][r-l+1],lenth[l][r]);
			}
		}
	}
}

int main(){
	cin>>n;
	cin>>s;
	process();
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int l;
		char x;
		cin>>l;
		cin>>x;
		int j=find(x);
		if(unappeared[j]) cout<<l<<endl;
		else{
		int q=upper_bound(f_len[j]+1,f_len[j]+1505,l)-f_len[j]-1;
		if(l+q>n) cout<<n<<endl;
		else cout<<l+q<<endl;
		}
	}
return 0;
}
