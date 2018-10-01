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

#define MP make_pair
#define FS first
#define SC second
#define LB lower_bound
#define PB push_back
#define lc p*2+1
#define rc p*2+2

typedef long long ll;
typedef pair<int,int> pi; 

const int Maxn=2e5+5;

class pnt{
	public:
		int x,y;
		int id;
		bool operator<(const pnt &o) const{
			return x<o.x||(x==o.x&&y<o.y);
		}
};

class pntset{
	public:
		int x,y;
		vector<int> ids;
};

vector<pntset> ps;
vector<int> hull;

bool cross(pi p1,pi p2){
	ll d=(ll)p1.SC*p2.FS-(ll)p1.FS*p2.SC;
	return d<0;
}

bool check(int id1,int id2,int id3){
	pi p1,p2;
	p1.FS=ps[id3].x*(ps[id2].x-ps[id1].x);
	p1.SC=ps[id3].y*(ps[id2].y-ps[id1].y);
	p2.FS=ps[id1].x*(ps[id3].x-ps[id2].x);
	p2.SC=ps[id1].y*(ps[id3].y-ps[id2].y);
	return cross(p1,p2);
}

void insert(int o){
	int m=hull.size()-1;
	while(m>=0){
		if(ps[hull[m]].y<=ps[o].y){
			hull.pop_back();
			m--;
		}
		else break;
	} 
	int l=m-1;
	while(m>0){
		if(check(hull[l],hull[m],o)){
			hull.pop_back();
			m--;
			l--;
		}
		else break;
	}
	hull.PB(o);
}

int n;
bool pw[Maxn];
pnt p[Maxn];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].id=i;
	}
	sort(p+1,p+n+1);
	int lx=-1,ly=-1,it=-1;
	for(int i=1;i<=n;i++){
		if(lx==p[i].x&&ly==p[i].y){
			ps[it].ids.PB(p[i].id);
		}
		else{
			pntset nps;
			nps.x=p[i].x;
			nps.y=p[i].y;
			nps.ids.PB(p[i].id);
			lx=nps.x;
			ly=nps.y;
			ps.PB(nps);
			it++;
		}
	}
	for(int i=0;i<=it;i++) insert(i);
	for(auto v:hull){
		for(auto p:ps[v].ids){
			pw[p]=true;
		}
	}
	for(int i=1;i<=n;i++) if(pw[i]) printf("%d ",i);
return 0;
}
