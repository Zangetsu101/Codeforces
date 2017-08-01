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

#define N 5005
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int ans[15];
const int p=31;
ll pref[N];
ll pr[N];

bitset<15> dp[N][N];
//bool dp[N][N][15];
bool isPalindrome[N][N];

void preCal()
{
    pr[0]=1;
    pr[1]=p;
    for(int i=2;i<N;i++)
        pr[i]=(pr[i-1]*p)%mod;
}

ll getHash(int i,int j)
{
    ll res=0;
    res=pref[j]-(pref[i-1]*pr[j-i+1])%mod;
    if(res<0)
        res+=mod;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    preCal();
    string str;
    cin>>str;
    int n=str.size();
    for(int i=1;i<=n;i++)
        pref[i]=((pref[i-1]*p)+(str[i-1]-'a'+1))%mod;
    int lim=14;
    for(int i=0;i<n;i++)
        isPalindrome[i+1][i+1]=true;
    for(int i=0;i<n-1;i++)
    {
        if(str[i]==str[i+1])
            isPalindrome[i+1][i+2]=true;
    }
    for(int i=n-2;i>0;i--)
    {
        for(int j=i+2;j<=n;j++)
        {
            if(str[i-1]==str[j-1])
                isPalindrome[i][j]=isPalindrome[i+1][j-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(isPalindrome[i][j])
                dp[i][j][1]=1,ans[1]++;
        }
    }
    for(int i=n-1;i>0;i--)
    {
        for(int j=i+1;j<=n;j++)
        {
            int k=j-i+1;
            k/=2;
            if(getHash(i,i+k-1)==getHash(j+1-k,j))
            {
                for(int l=2;l<=lim;l++)
                {
                    if(!dp[i][j][l-1])
                        break;
                    dp[i][j][l]=dp[i][i+k-1][l-1]&dp[j+1-k][j][l-1];
                    if(dp[i][j][l])
                        ans[l]++;
                }
            }
        }
    }
    for(int i=1;i<=min(n,lim);i++)
        cout<<ans[i]<<' ';
    for(int i=lim+1;i<=n;i++)
        cout<<0<<' ';
    cout<<endl;
    return 0;
}
