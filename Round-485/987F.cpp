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

#define N 9000001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int n;
bitset<N> visited;
bitset<N> data;
int mask;

//void bfs(int node)
//{
//    queue<int> q;
//    q.push(node);
//    while(!q.empty())
//    {
//        int t=q.front();
//        q.pop();
//        if(visited[t])
//            continue;
//        visited[t]=true;
//        if(t<(1<<n))
//        {
//            for(int i=0;i<n;i++)
//            {
//                if((t>>i)&1)
//                    continue;
//                if(!visited[t|(1<<i)])
//                    q.push(t|(1<<i));
//            }
//            if(data[~t&mask]&&!visited[(1<<n)+(~t&mask)])
//                q.push((1<<n)+(~t&mask));
//        }
//        else
//        {
//            t-=(1<<n);
//            if(!visited[t]&&data[t])
//                q.push(t);
//        }
//    }
//}

void dfs(int node)
{
    if(visited[node])
        return;
    visited[node]=true;
    if(node<(1<<n))
    {
        for(int i=0;i<n;i++)
        {
            if((node>>i)&1)
                continue;
            dfs(node|(1<<i));
        }
        if(data[~node&mask])
            dfs((1<<n)+(~node&mask));
    }
    else
    {
        node-=(1<<n);
        if(data[node])
            dfs(node);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int m;
    cin>>n>>m;
    mask=1<<n;
    mask--;
    for(int i=0;i<m;i++)
    {
        int a;
        cin>>a;
        data[a]=true;
    }
    int ans=0;
    for(int i=0;i<(1<<n);i++)
    {
        if(!data[i]||visited[(1<<n)+i])
            continue;
        ans++;
        dfs((1<<n)+i);
    }
    cout<<ans<<endl;
    return 0;
}
