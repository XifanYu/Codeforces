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

const ll mul=37,md=32416187567;//hash�ĳ�����ģ��// 
const int Maxt=1000005;//���test������//

//�������������prefix��similar�ģ���ô�ƽ϶̵�prefix���ϳ���prefix��һ���ߣ�//
//��ô���е�prefix����Ϊ������ͨ��ͼ������ֻ����ÿ����ͼȡ������ڵĵ�ļ���//

int t,n;
unordered_set<ll> node[Maxt];//ÿһ��test�д�ŵĴ���prefix��node//
unordered_map<ll,set<ll> > edge[Maxt];//ÿһ��test�бߵ������edge[test][��ǰprefix]��һ�����ϣ���ǰprefix��������ÿ��node��һ����// 
unordered_map<ll,bool> notroot[Maxt];//�����һ��prefixû�б�ָ���������ǾͿ��Դ���dfs���������notroot//
unordered_map<ll,int> df[Maxt];//���仯�������飬ÿ��df[��ǰtest][��ǰnode]��ʾ���node��dfs�Ľ��//

int dfs(ll x){//���Ӷ�O(�ڵ������)//
	if(df[t][x]) return df[t][x];//�������return// 
	int ans1=0,ans2=1;//ans1��ȡ��ǰ�ڵ㣬ans2ȡ��ǰ�ڵ�// 
	for(auto nn:edge[t][x]){
		ans1+=dfs(nn);
		for(auto nnn:edge[t][nn])ans2+=dfs(nnn);
	}
return df[t][x]=max(ans1,ans2);
}

int main(){
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		getchar();
		
		while(n--){
			ll val1=0,val2=0;
			string s="";
			char c;
			while('a'<=(c=getchar())) s+=c;
			int id=0;
			while(id<s.length()){
				ll x=0,y=0;
				x=(val1*mul+s[id])%md;
				if(id!=0) y=(val2*mul+s[id])%md;
				edge[t][y].insert(x);//y��x��һ����// 
				val1=x;
				val2=y; 
				node[t].insert(val1);
				id++;
			}
		}
		
		for(auto v:node[t]){
			for(auto u:edge[t][v]){
				notroot[t][u]=1;//�б�ָ��Ĳ���root//
			}
		}
		
		unordered_set<ll>::iterator it=node[t].begin();
		int ans=0;
		while(it!=node[t].end()){
			if(!notroot[t][*it]) {
				ans+=dfs(*it);//��root�Ϳ�ʼdfs//
			}
			it++;
		}
		
		printf("%d\n",ans);
	}
return 0;
}
