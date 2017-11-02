#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>
#include <queue>
#include <stack>
#include <bitset>

#define endl "\n"
#define si(a) scanf("%d",&a)
#define sii(a,b) scanf("%d %d",&a,&b)
#define siii(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sl(a) scanf("%lld",&a)
#define sll(a,b) scanf("%lld %lld",&a,&b)
#define pf printf
#define vi vector<int>
#define vii vector<pair<int,int> >
#define pii pair<int,int>
#define all(c) c.begin(),c.end()
#define ms(a,c) memset(a,c,sizeof(a))
#define tr(c,i) for(decltype((c).begin()) i=(c).begin();i!=(c).end();i++)
#define trr(c,i) for(decltype((c).rbegin()) i=(c).rbegin();i!=(c).rend();i++)

using namespace std;

#define N 100001
#define mod 1000000007
#define inf 1061109567

typedef long long ll;
typedef unsigned long long ull;

int first[N];
int n;
queue<int> q;

void go()
{
	queue< pii > temp;
	for(int i=2;i<=n;i+=2)
		temp.push(pii(i,0));
	bool flag;
	while(!temp.empty())
	{
		flag=true;
		pii t=temp.front();
		temp.pop();
		if(first[t.first]>first[t.second])
			continue;
		if(first[t.first])
			flag=false;
		first[t.first]=first[t.second]+1;
		q.push(t.first);
		if(!flag)
			continue;
		if(t.first!=1)
			temp.push(pii(t.first-1,t.first));
		if(t.first!=n)
			temp.push(pii(t.first+1,t.first));
	}
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	cin>>n;
	go();
	cout<<q.size()<<endl;
	while(!q.empty())
		cout<<q.front()<<' ',q.pop();
	cout<<endl;
	return 0;
}
