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

#define N 100001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

struct line
{
    long double m,c,xRight;
    line(ll mm,ll cc)
    {
        m=mm,c=cc;
        xRight=inf;
    }
};

double xIntersect(line a,line b)
{
    return (b.c-a.c)/(a.m-b.m);
}

ll a[N],b[N];
ll dp[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    vector<line> v;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
        cin>>b[i];
    v.push_back(line(a[n],0));
    int j=0;
    for(int i=n-1;i>0;i--)
    {
        while(v[j].xRight<b[i])
            j++;
        dp[i]=v[j].m*b[i]+v[j].c;
        v.push_back(line(a[i],dp[i]));
        while(v.size()>2)
        {
            line &l3=v[v.size()-1],&l2=v[v.size()-2];
            line &l1=v[v.size()-3];
            if(xIntersect(l1,l3)<xIntersect(l2,l1))
            {
                l2=l3;
                v.pop_back();
            }
            else
                break;
        }
        v[v.size()-2].xRight=xIntersect(v[v.size()-2],v[v.size()-1]);
    }
    cout<<dp[1]<<endl;
    return 0;
}
