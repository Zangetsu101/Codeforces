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

#define N 30001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int dp[N][601];
int value[N];
int dx[]={-1,0,1};
int n,d;
const int pivot=300;

int mp(int p)
{
    int v=d+p-pivot;
    return v;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    cin>>n>>d;
    int mx=0;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        value[a]++;
        mx=max(mx,a);
    }
    for(int i=mx;i>=0;i--)
    {
        for(int j=1;j<=2*pivot;j++)
        {
            dp[i][j]=value[i];
            for(int k=0;k<3;k++)
            {
                if(i+mp(j)+dx[k]>i&&i+mp(j)+dx[k]<=mx)
                    dp[i][j]=max(dp[i][j],value[i]+dp[i+mp(j)+dx[k]][j+dx[k]]);
            }
        }
    }
    cout<<dp[d][pivot]<<endl;
    return 0;
}
