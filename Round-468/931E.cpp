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

int freq[26];
vector< vi > v(26);

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
		freq[str[i]-'a']++,v[str[i]-'a'].push_back(i);
	double res=0;
	for(int i=0;i<26;i++)
	{
		if(!freq[i])
			continue;
		int ans=0;
		for(int j=1;j<=n;j++)
		{
			int f[26];
			ms(f,0);
			for(int k=0;k<v[i].size();k++)
				f[(str[(v[i][k]+j)%n])-'a']++;
			int cnt=0;
			for(int k=0;k<26;k++)
			{
				if(f[k]==1)
					cnt++;
			}
			ans=max(ans,cnt);
		}
		res+=(1.0*ans)/n;
	}
	cout<<fixed<<setprecision(8)<<res<<endl;
	return 0;
}
