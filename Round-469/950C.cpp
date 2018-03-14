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

#define N 200001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

set<int> one,zero;
vector< vi > v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	string str;
	cin>>str;
	int n=str.size();
	for(int i=0;i<n;i++)
	{
		if(str[i]=='1')
			one.insert(i+1);
		else
			zero.insert(i+1);
	}
	if(zero.empty())
	{
		cout<<-1<<endl;
		return 0;
	}
	while(!zero.empty())
	{
		vi t;
		int z=*zero.begin();
		t.push_back(z);
		zero.erase(zero.begin());
		set<int>::iterator it=one.lower_bound(z),it2;
		while(it!=one.end())
		{
			int o=*it;
			it2=zero.lower_bound(o);
			if(it2==zero.end())
			{
				cout<<-1<<endl;
				return 0;
			}
			z=*it2;
			t.push_back(o);
			t.push_back(z);
			one.erase(it);
			zero.erase(it2);
			it=one.lower_bound(z);
		}
		v.push_back(t);
	}
	if(!one.empty())
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i].size()<<' ';
		for(int j=0;j<v[i].size();j++)
			cout<<v[i][j]<<' ';
		cout<<endl;
	}
	return 0;
}
