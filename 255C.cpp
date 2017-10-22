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
#include <unordered_map>

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

#define N 4001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

short dp[N][2][2*N];
int data[N];
int r[1000001];
vi v;

int h(int a)
{
    return a+4000;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>data[i],v.push_back(data[i]);
    sort(all(v));
    vector<int>::iterator it=unique(all(v));
    v.resize(it-v.begin());
    for(int i=0;i<v.size();i++)
        r[v[i]]=i;
    for(int i=0;i<n;i++)
        data[i]=r[data[i]];
    int ans=1;
    for(int i=0;i<n;i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            dp[i][0][h(data[j]-data[i])]=max((int)dp[i][0][h(data[j]-data[i])],dp[j][1][h(data[i])]+1);
            dp[i][1][h(data[j])]=max((int)dp[i][1][h(data[j])],max((int)dp[j][0][h(data[i]-data[j])],1)+1);
            ans=max(ans,(int)dp[i][0][h(data[j]-data[i])]);
            ans=max(ans,(int)dp[i][1][h(data[j])]);
//            v.push_back(data[j]);
        }
//        tr(v,it)
//            visited[*it]=false;
//        v.clear();
    }
    cout<<ans<<endl;
    return 0;
}
