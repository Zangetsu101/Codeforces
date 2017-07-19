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

#define N 1505
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

short dp[26][N][N];
short ans[26][N];
short data[N][26];

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
    for(int i=0;i<n;i++)
        data[i+1][str[i]-'a']=data[i][str[i]-'a']+1;
    for(int k=0;k<26;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(str[i-1]=='a'+k)
                    dp[k][i][j]=dp[k][i-data[i][k]][j]+data[i][k];
                else if(j>=1)
                    dp[k][i][j]=dp[k][i-data[i-1][k]-1][j-1]+data[i-1][k]+1;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
                ans[k][j]=max(ans[k][j],dp[k][i][j]);
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int m;
        char ch;
        cin>>m>>ch;
        cout<<(int)ans[ch-'a'][m]<<endl;
    }
    return 0;
}
