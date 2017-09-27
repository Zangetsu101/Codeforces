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

#define N 351
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

const int pivot=350;

bool visited[N][N];
int dp[N][N][8][31];

int depth[31];
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
int n;

void solve(int x,int y,int dir,int dep)
{
    if(dp[x][y][dir][dep]!=-1||dep==n+1)
        return;
    dp[x][y][dir][dep]=0;
    for(int i=0;i<depth[dep];i++)
        visited[x][y]=true,x+=dx[dir],y+=dy[dir];
    x-=dx[dir],y-=dy[dir];
    int offset=(dir+1)%8;
    solve(x+dx[offset],y+dy[offset],offset,dep+1);
    offset=(dir-1+8)%8;
    solve(x+dx[offset],y+dy[offset],offset,dep+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    ms(dp,-1);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>depth[i];
    solve(pivot/2,pivot/2,0,1);
    int ans=0;
    for(int i=0;i<=pivot;i++)
    {
        for(int j=0;j<=pivot;j++)
        {
            if(visited[i][j])
                ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
