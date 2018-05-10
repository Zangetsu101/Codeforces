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

#define N 101
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

vector< vii > adj(N);
bool flag[N][N][26][2];
bool dp[N][N][26][2];

bool func(int a,int b,int last,bool turn)
{
    bool &ans=dp[a][b][last][turn];
    if(flag[a][b][last][turn])
        return ans;
    flag[a][b][last][turn]=true;
    if(turn)
    {
        for(int i=0;i<adj[a].size();i++)
        {
            if(adj[a][i].second>=last)
                ans|=!func(adj[a][i].first,b,adj[a][i].second,!turn);
        }
    }
    else
    {
        for(int i=0;i<adj[b].size();i++)
        {
            if(adj[b][i].second>=last)
                ans|=!func(a,adj[b][i].first,adj[b][i].second,!turn);
        }
    }
    return ans;
}
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
        int a,b;
        char c;
        cin>>a>>b>>c;
        c-='a';
        adj[a].push_back(pii(b,c));
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(func(i,j,0,true))
                cout<<'A';
            else
                cout<<'B';
        }
        cout<<endl;
    }
    return 0;
}
