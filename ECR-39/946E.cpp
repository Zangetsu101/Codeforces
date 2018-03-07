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
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int power(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res*=a;
		a*=a;
		b>>=1;
	}
	return res;
}

bool possible(int *cnt,int a,int free)
{
	int temp[10];
	for(int i=0;i<10;i++)
		temp[i]=cnt[i];
	int sum=0;
	temp[a]^=1;
	for(int i=0;i<10;i++)
		sum+=temp[i];
	if(sum<=free)
		return true;
	return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
	int cases;
	cin>>cases;
	while(cases--)
	{
		string str;
		cin>>str;
		int n=str.size();
		if(n%2)
		{
			for(int i=0;i<n-1;i++)
				cout<<9;
			cout<<endl;
			continue;
		}
		int cnt[10];
		ms(cnt,0);
		int sum=0;
		for(int i=0;i<n;i++)
			cnt[str[i]-'0']^=1;
		for(int i=0;i<10;i++)
			sum+=cnt[i];
		bool flag=false;
		for(int i=1;i<=n;i++)
		{
			sum-=cnt[str[n-i]-'0'];
			cnt[str[n-i]-'0']^=1;
			sum+=cnt[str[n-i]-'0'];
			for(int j=str[n-i]-'0'-1;j>=0;j--)
			{
				if(i==n&&!j)
					continue;
				if(possible(cnt,j,i))
				{
					str[n-i]=j+'0';
					sum-=cnt[j];
					cnt[j]^=1;
					sum+=cnt[j];
					for(int k=n-i+1;k<n-sum;k++)
						str[k]='9';
					stack<int> s;
					for(int k=0;k<10;k++)
					{
						if(cnt[k])
							s.push(k);
					}
					for(int k=n-sum;k<n;k++)
						str[k]=s.top()+'0',s.pop();
					flag=true;
					break;
				}
			}
			if(flag)
				break;
		}
		if(flag)
			cout<<str<<endl;
		else
		{
			for(int i=0;i<n-2;i++)
				cout<<9;
			cout<<endl;
		}
	}
	return 0;
}
