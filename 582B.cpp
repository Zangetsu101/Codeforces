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

int dp[40001];
int dp2[10001];
int data[101];
int cnt[3*N];
int n;

void func()
{
    dp[0]=1;
    for(int i=1;i<4*n*n;i++)
    {
        dp[i]=1;
        for(int j=i-1;j>=max(0,i-n);j--)
        {
            if(data[j%n]<=data[i%n])
                dp[i]=max(dp[i],dp[j]+1);
        }
    }
}

void func2()
{
    dp2[n*n-1]=1;
    for(int i=n*n-2;i>=0;i--)
    {
        dp2[i]=1;
        for(int j=i+1;j<=min(n*n-1,i+n);j++)
        {
            if(data[j%n]>=data[i%n])
                dp2[i]=max(dp2[i],dp2[j]+1);
        }
    }
}

int pre(int t,int k)
{
    return dp[(t-1)*n+k];
}
int post(int t,int k)
{
    return dp2[(n-t)*n+k];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int t;
    cin>>n>>t;
    for(int i=0;i<n;i++)
        cin>>data[i],cnt[data[i]]++;
    func();
    func2();
    int ans=0;
    if(t<=2*n)
    {
        for(int i=0;i<n;i++)
            ans=max(ans,pre(t,i));
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(data[j]>=data[i])
                    ans=max(ans,pre(n,i)+post(n,j)+(t-2*n)*cnt[data[i]]);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
