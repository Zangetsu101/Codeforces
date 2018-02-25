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

int a[N],b[N];

int getMin(int l,int r)
{
    int ans=inf;
    for(int i=l;i<=r;i++)
        ans=min(ans,a[i]);
    return ans;
}

int getMax(int l,int r)
{
    int ans=-inf;
    for(int i=l;i<=r;i++)
        ans=max(ans,a[i]);
    return ans;
}

int getSum(int l,int r)
{
    int ans=0;
    for(int i=l;i<=r;i++)
        ans+=b[i];
    return ans;
}

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    string str;
    cin>>str;
    for(int i=1;i<=n;i++)
    {
        if(str[i-1]=='0')
            b[i]=0;
        else
            b[i]=1;
    }
    int l1=-inf,l2=inf,r1=-inf,r2=inf;
    for(int i=5;i<=n;i++)
    {
        if(getSum(i-4,i-1)==0)
        {
            if(b[i])
                l1=max(l1,getMax(i-4,i)+1);
            else
                l2=min(l2,getMax(i-4,i)-1);
        }
        else if(getSum(i-4,i-1)==4)
        {
            if(!b[i])
                r2=min(r2,getMin(i-4,i)-1);
            else
                r1=max(r1,getMin(i-4,i)+1);
        }
    }
    cout<<l1<<' '<<r2<<endl;
    return 0;
}
