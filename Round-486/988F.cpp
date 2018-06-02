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

#define N 2001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int dp[N];
bool isRaining[N];
int umbrella[N];
int mp[100001];
int rmp[100001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    ms(dp,63);
    int a,n,m;
    cin>>a>>n>>m;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        for(int j=l+1;j<=r;j++)
            isRaining[j]=true;
    }
    vi v;
    for(int i=0;i<m;i++)
    {
        int x,u;
        cin>>x>>u;
        if(!umbrella[x])
            umbrella[x]=u;
        else
            umbrella[x]=min(umbrella[x],u);
        v.push_back(u);
    }
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    int cnt=1;
    for(int i=0;i<v.size();i++)
        mp[cnt++]=v[i],rmp[v[i]]=cnt-1;
    for(int i=0;i<=a;i++)
    {
        if(umbrella[i])
            umbrella[i]=rmp[umbrella[i]];
    }
    if(!isRaining[0])
        dp[0]=0;
    if(umbrella[0])
        dp[umbrella[0]]=0;
    for(int i=0;i<a;i++)
    {
        int mini=inf;
        for(int j=0;j<cnt;j++)
            mini=min(mini,dp[j]);
        if(isRaining[i+1])
            dp[0]=inf;
        else
            dp[0]=mini;
        for(int j=1;j<cnt;j++)
            dp[j]+=mp[j];
        if(umbrella[i+1])
        {
            for(int j=0;j<cnt;j++)
                dp[umbrella[i+1]]=min(dp[umbrella[i+1]],dp[j]);
        }
    }
    int ans=inf;
    for(int i=0;i<cnt;i++)
        ans=min(ans,dp[i]);
    if(ans<inf)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
    return 0;
}
