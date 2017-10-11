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

vector< vi > adj(N);
vii required;
map< pii,bool> given;
bool visited[N];
vector< vi > cities(N);

void dfs(int node)
{
    visited[node]=true;
    for(int i=0;i<adj[node].size();i++)
    {
        int v=adj[node][i];
        if(visited[v])
            continue;
        required.push_back(pii(node,v));
        dfs(v);
    }
}

void dfs2(int node,int p,int ans)
{
    cities[ans].push_back(node);
    for(int i=0;i<adj[node].size();i++)
    {
        int v=adj[node][i];
        if(v==p)
            continue;
        int temp=ans;
        if(given[pii(v,node)])
            ans--;
        else
            ans++;
        dfs2(v,node,ans);
        ans=temp;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        given[pii(a,b)]=true;
    }
    dfs(1);
    int ans=0;
    tr(required,it)
    {
        int a=it->first,b=it->second;
        if(!given[pii(a,b)])
            ans++;
    }
    dfs2(1,0,ans);
    for(int i=0;i<n;i++)
    {
        if(cities[i].size())
        {
            cout<<i<<endl;
            sort(all(cities[i]));
            tr(cities[i],it)
                cout<<*it<<' ';
            cout<<endl;
            return 0;
        }
    }
    return 0;
}
