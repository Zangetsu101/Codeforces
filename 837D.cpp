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

#define N 100001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

const int maxi=3600;

bool dp[2][201][3601];
int extra[2][201][3601][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,m;
    cin>>n>>m;
    int f;
    for(int i=1;i<=n;i++)
    {
        f=i&1;
        for(int j=1;j<=min(m,i-1);j++)
        {
            for(int k=0;k<=maxi;k++)
            {
                dp[f][j][k]=dp[f^1][j][k];
                extra[f][j][k][0]=extra[f^1][j][k][0];
                extra[f][j][k][1]=extra[f^1][j][k][1];
            }
        }
        ll v;
        cin>>v;
        int a=0,b=0,r;
        while(v%2==0)
            v/=2,a++;
        while(v%5==0)
            v/=5,b++;
        r=min(a,b);
        a-=r,b-=r;
        dp[f][1][r]=true;
        extra[f][1][r][0]=max(extra[f][1][r][0],a);
        extra[f][1][r][1]=max(extra[f][1][r][1],b);
        int ta,tb,tr;
        for(int j=1;j<=min(m,i-1);j++)
        {
            for(int k=0;k<=maxi;k++)
            {
                if(dp[f^1][j][k])
                {
                    bool flag=true;
                    if(extra[f^1][j][k][0])
                    {
                        flag=false;
                        ta=a+extra[f^1][j][k][0];
                        tb=b;
                        tr=min(ta,tb);
                        ta-=tr,tb-=tr;
                        if(k+r+tr<=maxi)
                        {
                            dp[f][j+1][k+r+tr]=true;
                            extra[f][j+1][k+r+tr][0]=max(extra[f][j+1][k+r+tr][0],ta);
                            extra[f][j+1][k+r+tr][1]=max(extra[f][j+1][k+r+tr][1],tb);
                        }
                    }
                    if(extra[f^1][j][k][1])
                    {
                        flag=false;
                        ta=a;
                        tb=b+extra[f^1][j][k][1];
                        tr=min(ta,tb);
                        ta-=tr,tb-=tr;
                        if(k+r+tr<=maxi)
                        {
                            dp[f][j+1][k+r+tr]=true;
                            extra[f][j+1][k+r+tr][0]=max(extra[f][j+1][k+r+tr][0],ta);
                            extra[f][j+1][k+r+tr][1]=max(extra[f][j+1][k+r+tr][1],tb);
                        }
                    }
                    if(flag)
                    {
                        if(k+r<=maxi)
                        {
                            dp[f][j+1][k+r]=true;
                            extra[f][j+1][k+r][0]=max(extra[f][j+1][k+r][0],a);
                            extra[f][j+1][k+r][1]=max(extra[f][j+1][k+r][1],b);
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=maxi;i>0;i--)
    {
        if(dp[f][m][i])
        {
            ans=i;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
