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

#define N 501
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

bool dp[N][N];
bool temp[N][N];
int value[N];
bool flag[N];
int n,k;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>value[i];
    flag[0]=true;
    dp[0][0]=true;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=k;j++)
        {
            for(int l=0;l<=k;l++)
            {
                if(j>=value[i]&&flag[j-value[i]])
                {
                    temp[j][l]=dp[j][l]|dp[j-value[i]][l];
                    if(l>=value[i])
                        temp[j][l]|=dp[j-value[i]][l-value[i]];
                }
                else
                    temp[j][l]=dp[j][l];
            }
        }
        for(int j=k;j-value[i]>=0;j--)
            flag[j]|=flag[j-value[i]];
        for(int j=0;j<=k;j++)
        {
            for(int l=0;l<=k;l++)
                dp[j][l]=temp[j][l];
        }
    }
    int cnt=0;
    for(int i=0;i<=k;i++)
    {
        if(dp[k][i])
            cnt++;
    }
    cout<<cnt<<endl;
    for(int i=0;i<=k;i++)
    {
        if(dp[k][i])
            cout<<i<<' ';
    }
    cout<<endl;
    return 0;
}

/*
15 185
69 61 185 127 169 42 140 93 12 115 36 46 19 80 123
*/
