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

ll a,b,c=0; 
int num1[20],num2[20],dig[10];
int l1=0,l2=0;

void makemax(int pos=0){
	int i=pos;
	while(i<l1){
		for(int j=9;j>=0;j--){
			if(dig[j]){
				dig[j]--;
				num1[i++]=j;
				break;
			}
		}
	}
}

void makeint(){
	for(int i=0;i<l1;i++){
		c*=10;
		c+=num1[i];
	}
}

void dfs(int pos){
	if(pos==l2){
		makeint();
		printf("%I64d\n",c);
		exit(0);
	}
	for(int i=9;i>=0;i--){
		if(dig[i]>0&&i==num2[pos]){
			dig[i]--;
			num1[pos]=i;
			dfs(pos+1);
			dig[i]++;
		}
		if(dig[i]>0&&i<num2[pos]){
			dig[i]--;
			num1[pos]=i;
			makemax(pos+1);
			makeint();
			printf("%I64d\n",c);
			exit(0);
		}
	}
}

int main(){
	scanf("%I64d%I64d",&a,&b);
	while(a){
		dig[a%10]++;
		a/=10;
		l1++;
	}
	while(b){
		num2[l2++]=b%10;
		b/=10;
	}
	int id1,id2;
	id1=(l2-1)/2,id2=l2/2;
	while(id1>=0){
		swap(num2[id1],num2[id2]);
		id1--;id2++;
	}
	if(l1==l2) dfs(0);
	else if(l1<l2) makemax();
	makeint();
	printf("%I64d\n",c);
return 0;
}
