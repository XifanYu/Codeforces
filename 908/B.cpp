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

int n,m;
string s[55];
string ins;
string ss="0123";
int sx,sy;
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int ans=0;

void test(string a){
	int x=sx,y=sy;
	int now=0;
	while(now<ins.length()&&x>=0&&x<n&&y>=0&&y<m&&s[x][y]!='E'&&s[x][y]!='#'){
		char d=ins[now++];
		x+=dx[ss[d-'0']-'0'];
		y+=dy[ss[d-'0']-'0'];
	}
	if(x>=0&&x<n&&y>=0&&y<m&&s[x][y]=='E') ans++;
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<m;j++){
			if(s[i][j]=='S'){
				sx=i;sy=j;
			}
		}
	}
	cin>>ins;
	do{
		test(ss);
	}while(next_permutation(ss.begin(),ss.end()));
	cout<<ans<<"\n";
return 0;
}
