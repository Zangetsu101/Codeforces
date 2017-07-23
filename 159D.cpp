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

#define N 2001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

bool isPalindrome[N][N];
int dp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    string str;
    cin>>str;
    int n=str.size();
    for(int i=1;i<=n;i++)
    {
        isPalindrome[i][i]=true;
        if(i<n&&str[i-1]==str[i])
            isPalindrome[i][i+1]=true;
    }
    for(int i=n-2;i>0;i--)
    {
        for(int j=i+2;j<=n;j++)
        {
            if(str[i-1]==str[j-1])
                isPalindrome[i][j]|=isPalindrome[i+1][j-1];
        }
    }
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]+=dp[i-1];
        for(int j=i;j>0;j--)
        {
            if(isPalindrome[j][i])
                dp[i]++;
        }
    }
    ll ans=0;
    for(int i=n;i>0;i--)
    {
        for(int j=i;j<=n;j++)
        {
            if(isPalindrome[i][j])
                ans+=dp[i-1];
        }
    }
    cout<<ans<<endl;
    return 0;
}
