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

vector< vii > values(4*N);
vector< vi > mini(4*N);
int level[N],data[N],tData[N],tin[N],tout[N];
bool visited[N];
vector< vi > adj(N);
int t;

void dfs(int node,int p,int l)
{
    if(visited[node])
        return;
    visited[node]=true;
    tin[node]=++t;
    level[t]=l;
    tData[t]=data[node];
    for(int i=0;i<adj[node].size();i++)
    {
        if(adj[node][i]!=p)
            dfs(adj[node][i],node,l+1);
    }
    tout[node]=t;
}

void build(int node,int l,int r)
{
    int mid=(l+r)>>1;
    if(l==r)
    {
        values[node].push_back(pii(level[l],tData[l]));
        mini[node].push_back(tData[l]);
        return;
    }
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    values[node].resize(values[node*2].size()+values[node*2+1].size());
    merge(all(values[node*2]),all(values[node*2+1]),values[node].begin());
    int m=values[node].front().second;
    for(pii t:values[node])
    {
        m=min(m,t.second);
        mini[node].push_back(m);
    }
}

int query(int node,int l,int r,int i,int j,int x)
{
    if(i>r||j<l)
        return inf;
    if(i<=l&&j>=r)
    {
        int idx=upper_bound(all(values[node]),pii(x,inf))-values[node].begin();
        if(!idx)
            return inf;
        idx--;
        return mini[node][idx];
    }
    int mid=(l+r)>>1;
    return min(query(node*2,l,mid,i,j,x),query(node*2+1,mid+1,r,i,j,x));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,r;
    cin>>n>>r;
    for(int i=1;i<=n;i++)
        cin>>data[i];
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(r,0,0);
    build(1,1,n);
    int m,last=0;
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        int p,q;
        cin>>p>>q;
        int x=((p+last)%n)+1;
        int k=(q+last)%n;
        last=query(1,1,n,tin[x],tout[x],level[tin[x]]+k);
        cout<<last<<endl;
    }
    return 0;
}
