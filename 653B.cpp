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

int dp[7][7];

vector< vi > adj(6);

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<q;i++)
    {
        string a,b;
        cin>>a>>b;
        adj[b.front()-'a'].push_back(a.front()-'a');
    }
    dp[1][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<6;j++)
        {
            if(dp[i][j])
            {
                for(int k=0;k<adj[j].size();k++)
                    dp[i+1][adj[j][k]]+=dp[i][j];
            }
        }
    }
    int ans=0;
    for(int i=0;i<6;i++)
        ans+=dp[n][i];
    cout<<ans<<endl;
    return 0;
}
