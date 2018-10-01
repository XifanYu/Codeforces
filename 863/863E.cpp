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

const int Maxn=200005;

typedef pair<int,int> pi;
typedef pair<pi,int> ppi;

int n;
ppi ra[Maxn];
pi f[Maxn];
pi b[Maxn];
vector<int> disj;

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ra[i]=ppi(pi(x,y),i);
	}
	sort(ra+1,ra+n+1);
	priority_queue<pi,vector<pi>,less<pi> > fw;
	for(int i=1;i<=n;i++){
		pi joint=pi(-1,-1);
		while(true){
			if(fw.empty()) break;
			pi x=fw.top();
			if(x.second+1>=ra[i].first.first){
				joint=x;
				fw.pop();
			}
			else break;
		}
		if(joint==pi(-1,-1)){
			fw.push(ra[i].first);
		}
		else fw.push(pi(min(joint.first,ra[i].first.first),max(joint.second,ra[i].first.second)));
		f[i]=fw.top();
	}
	priority_queue<pi,vector<pi>,greater<pi> > bw;
	for(int i=n;i;i--){
		pi joint=pi(-1,-1);
		while(true){
			if(bw.empty()) break;
			pi x=bw.top();
			if(ra[i].first.second+1>=x.first){
				joint=x;
				bw.pop();
			}
			else break;
		}
		if(joint==pi(-1,-1)){
			bw.push(ra[i].first);
		}
		else bw.push(pi(min(joint.first,ra[i].first.first),max(joint.second,ra[i].first.second)));
		b[i]=bw.top();
	}
	if(n>1){
		if(ra[1].first.first==ra[2].first.first){
			cout<<ra[1].second<<"\n";
			return 0;
		}
		for(int i=2;i<n;i++){
			pi x=f[i-1],y=b[i+1];
			if(x.second>=ra[i].first.second||(y.first<=ra[i].first.first&&y.second>=ra[i].first.second)||(x.second+1>=y.first&&y.second>=ra[i].first.second)){
				cout<<ra[i].second<<"\n";
				return 0;
			}
		}
		if(ra[n].first.second<=f[n-1].second){
			cout<<ra[n].second<<"\n";
			return 0;
		}
	}
	cout<<-1<<"\n";
return 0;
}
