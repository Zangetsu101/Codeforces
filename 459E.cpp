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

#define N 300001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

struct edge
{
    int u,v,w;
    edge(int a=0,int b=0,int c=0)
    {
        u=a,v=b,w=c;
    }

    bool operator<(edge a)
    {
        return w>a.w;
    }
}edges[N];

int dp[N];
int temp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        edges[i]=edge(a,b,w);
    }
    sort(edges,edges+m);
    int prev=-1;
    vi v;
    for(int i=0;i<m;i++)
    {
        if(edges[i].w!=prev)
        {
            tr(v,it)
                dp[*it]=max(dp[*it],temp[*it]);
            v.clear();
        }
        v.push_back(edges[i].u);
        temp[edges[i].u]=max(temp[edges[i].u],dp[edges[i].v]+1);
        prev=edges[i].w;
    }
    tr(v,it)
        dp[*it]=max(dp[*it],temp[*it]);
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}
