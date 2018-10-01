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

pair<int,int> f[105];
int n,m;
vector<int> ok;


int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		f[i]=make_pair(y,x);
	}
	sort(f+1,f+m+1);
	if(f[m].first==1) cout<<-1<<"\n";
	else if(m==0){
		if(n==1) cout<<1<<"\n";
		else cout<<-1<<"\n";
	}
	else{
		int ans=0;
		for(int j=1;j<=100;j++){
			for(int k=1;k<=m;k++){
				if(j*(f[k].first-1)<f[k].second&&j*f[k].first>=f[k].second) {
					if(k==m) {
						ans++;
						ok.push_back(j);
					}
					continue;
				}
				else break;
			}
		}
		if(ans>1) {
			int fl;
			for(int i=0;i<ok.size();i++){
				int nfl=(n-1)/ok[i]+1;
				if(i>0){
					if(nfl!=fl) {
						cout<<-1<<"\n";
						exit(0);
					}
				}
				fl=nfl;
			}
			cout<<fl<<"\n";
		}
		else cout<<((n-1)/ok[0])+1<<"\n";
	}
return 0;
}
