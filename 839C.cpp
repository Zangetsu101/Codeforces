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

#define endl "\n"
#define sf(a) scanf("%d",&a)
#define sff(a,b) scanf("%d %d",&a,&b)
#define sfff(a,b,c) scanf("%d %d %d",&a,&b,&c)
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
#define mod 100000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

double ans;
vector< vi > adj(N);

void dfs(int node,int par,double p,int l)
{
    bool flag=false;
    for(int i=0;i<adj[node].size();i++)
    {
        if(adj[node][i]==par)
            continue;
        flag=true;
        if(par)
            dfs(adj[node][i],node,p/(adj[node].size()-1),l+1);
        else
            dfs(adj[node][i],node,p/adj[node].size(),l+1);
    }
    if(!flag)
        ans+=l*p;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0,1,0);
    cout<<fixed<<setprecision(8)<<ans<<endl;
    return 0;
}
