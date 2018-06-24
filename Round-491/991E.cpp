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

int finalFlag;
ll dp[20][1<<19];
int sz;
int mp[20];
int limit;

ll func(int idx,int mask)
{
    ll &ans=dp[idx][mask];
    if(ans!=-1)
        return ans;
    if(idx==limit)
    {
        int flag=0;
        for(int i=0;i<sz;i++)
        {
            if((mask>>i)&1)
                flag|=(1<<mp[i]);
        }
        if(flag==finalFlag)
            ans=1;
        else
            ans=0;
        return ans;
    }
    ans=0;
    bool flag[10]={false};
    for(int i=0;i<sz;i++)
    {
        if((mask>>i)&1)
            continue;
        if(!idx&&!mp[i]||flag[mp[i]])
            continue;
        ans+=func(idx+1,mask|(1<<i));
        flag[mp[i]]=true;
    }
    return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("Input.txt","r",stdin); 
	//freopen("Output.txt","w",stdout);
    ll n;
    cin>>n;
    ll temp=n;
    int i=0;
    while(temp)
        finalFlag|=(1<<(temp%10)),mp[i++]=temp%10,temp/=10;
    sz=i;
    limit=i;
    int cnt=0;
    for(int i=0;i<10;i++)
    {
        if((finalFlag>>i)&1)
            cnt++;
    }
    ll ans=0;
    while(limit>=cnt)
    {
        ms(dp,-1);
        ans+=func(0,0);
        limit--;
    }
    cout<<ans<<endl;
	return 0;
}
		
