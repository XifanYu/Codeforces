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

class line{
	public:
		int x,y;//actually k=1/x, b=1/y;
		int id;
		bool operator<(const line &o)const{
			return x<o.x||(x==o.x&&y<o.y);
		}
};

class lineset{
	public:
		int x,y;
		vector<int> ids;
};

int n;
vector<int> hull;
vector<lineset> ls;
line l[Maxn];
bool pw[Maxn];

bool check(int id1,int id2,int id3){
	ll d=(ll)ls[id2].y*ls[id3].x*(ls[id2].x-ls[id1].x)*(ls[id3].y-ls[id1].y)-(ll)ls[id2].x*ls[id3].y*(ls[id2].y-ls[id1].y)*(ls[id3].x-ls[id1].x);
	return d>0;
}

void insert(int id){
	int m=hull.size()-1;
	while(m>=0){
		if(ls[hull[m]].y<=ls[id].y){
			hull.pop_back();
			m--;
		}
		else break;
	}
	int l=m-1;
	while(m>0){
		if(check(hull[l],hull[m],id)){
			hull.pop_back();
			m--;
			l--;
		}
		else break;
	}
	hull.PB(id);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i].x,&l[i].y);
		l[i].id=i;
	}
	sort(l+1,l+n+1);
	int it=-1;
	for(int i=1;i<=n;i++){
		if(l[i-1].x==l[i].x&&l[i-1].y==l[i].y){
			ls[it].ids.PB(l[i].id);
		}
		else{
			lineset nls;
			nls.x=l[i].x;
			nls.y=l[i].y;
			nls.ids.PB(l[i].id);
			ls.PB(nls);
			it++;
		}
	}
	for(int i=0;i<=it;i++) insert(i);
	for(auto v:hull){
		for(auto p:ls[v].ids){
			pw[p]=true;
		}
	}
	for(int i=1;i<=n;i++) if(pw[i]) printf("%d ",i);
return 0;
}
