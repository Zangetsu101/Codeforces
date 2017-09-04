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

#define N 1501
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int dp[101][101][N];
int data[101][101];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int cases;
    cin>>cases;
    while(cases--)
	{
	    ms(dp,-1);
	    int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                cin>>data[i][j];
        }
        int three=0,two=0;
        int temp=data[1][1];
        while(temp%3==0)
            temp/=3,three++;
        while(temp%2==0)
            temp/=2,two++;
        dp[1][1][three]=two;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(i==1&&j==1)
                    continue;
                temp=data[i][j];
                three=0,two=0;
                while(temp%3==0)
                    three++,temp/=3;
                while(temp%2==0)
                    two++,temp/=2;
                for(int k=three;k<N;k++)
                {
                    if(dp[i-1][j][k-three]!=-1&&dp[i][j-1][k-three]!=-1)
                        dp[i][j][k]=max(dp[i-1][j][k-three],dp[i][j-1][k-three])+two;
                    else if(dp[i-1][j][k-three]!=-1)
                        dp[i][j][k]=dp[i-1][j][k-three]+two;
                    else if(dp[i][j-1][k-three]!=-1)
                        dp[i][j][k]=dp[i][j-1][k-three]+two;
                }
            }
        }
        int ans=0;
        for(int i=1;i<N;i++)
            ans=max(ans,min(dp[n][m][i],i));
        cout<<ans<<endl;
	}
    return 0;
}
