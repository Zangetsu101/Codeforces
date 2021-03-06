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

int dp[N][N*N];
int data[N];
int s[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    vii v;
    for(int i=1;i<=n;i++)
        cin>>data[i],sum+=data[i];
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        v.push_back(pii(a,data[i]));
    }
    sort(all(v),greater< pii >());
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+v[i-1].first;
    int idx=lower_bound(s+1,s+n+1,sum)-s;
    ms(dp,192);
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>0;j--)
        {
            for(int k=v[i-1].second;k<=sum;k++)
                dp[j][k]=max(dp[j][k],dp[j-1][k-v[i-1].second]+v[i-1].first);
        }
    }
    cout<<idx<<' ';
    for(int i=sum;i>=0;i--)
    {
        if(dp[idx][i]>=sum)
        {
            cout<<sum-i<<endl;
            break;
        }
    }
    return 0;
}
