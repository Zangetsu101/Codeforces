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

#define N 20
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

ll fact[N];
ll dp[1<<(N-1)][101];
int freq[10];
vi digits;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    fact[0]=1;
    for(int i=1;i<N;i++)
        fact[i]=i*fact[i-1];
    ll n;
    int m;
    cin>>n>>m;
    while(n)
        digits.push_back(n%10),freq[n%10]++,n/=10;
    dp[0][0]=1;
    for(int i=0;i<(1<<digits.size());i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<digits.size();k++)
            {
                if((i>>k)&1||(!i&&!digits[k]))
                    continue;
                dp[i|(1<<k)][(j*10+digits[k])%m]+=dp[i][j];
            }
        }
    }
    ll ans=dp[(1<<digits.size())-1][0];
    for(int i=0;i<10;i++)
        ans/=fact[freq[i]];
    cout<<ans<<endl;
    return 0;
}
