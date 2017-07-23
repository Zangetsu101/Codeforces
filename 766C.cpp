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

#define N 1001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int dp[N];
int value[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<26;i++)
        cin>>value[i];
    dp[0]=1;
    int maxi=inf,l=0;
    char ch;
    for(int i=1;i<=n;i++)
    {
        maxi=inf;
        for(int j=i;j>=1;j--)
        {
            ch=str[j-1];
            maxi=min(maxi,value[ch-'a']);
            if(i-j+1<=maxi)
                dp[i]+=dp[j-1],dp[i]%=mod;
            else
                break;
            l=max(l,i-j+1);
        }
    }
    cout<<dp[n]<<endl;
    cout<<l<<endl;
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+1;
        maxi=inf;
        for(int j=i;j>=1;j--)
        {
            ch=str[j-1];
            maxi=min(maxi,value[ch-'a']);
            if(i-j+1<=maxi)
                dp[i]=min(dp[i],dp[j-1]+1);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
