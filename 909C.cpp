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

#define N 5011
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

ll data[2][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	int n;
	cin>>n;
	data[0][0]=1;
	char last='s';
	for(int i=0;i<n;i++)
	{
		int at=i&1;
		ms(data[at^1],0);
		char ch;
		cin>>ch;
		if(last=='f')
		{
			if(ch=='f')
			{
				for(int j=n;j>0;j--)
					data[at^1][j]=data[at][j-1];
			}
			else
			{
				for(int j=n;j>=0;j--)
					data[at^1][j]=data[at][j];
			}
		}
		else
		{
			if(ch=='f')
			{
				for(int j=0;j<=n;j++)
				{
					data[at^1][1]=(data[at^1][1]+data[at][j])%mod;
					data[at^1][j+2]=(data[at^1][j+2]-data[at][j])%mod;
				}
			}
			else
			{
				for(int j=0;j<=n;j++)
				{
					data[at^1][0]=(data[at^1][0]+data[at][j])%mod;
					data[at^1][j+1]=(data[at^1][j+1]-data[at][j])%mod;
				}
			}
			for(int j=1;j<=n;j++)
				data[at^1][j]=(data[at^1][j]+data[at^1][j-1])%mod;
		}
		last=ch;
	}
	ll ans=0;
	int at=n&1;
	for(int i=0;i<=n;i++)
		ans=(ans+data[at][i])%mod;
	cout<<(ans+mod)%mod<<endl;
	return 0;
}
