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

#define N 300001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int power(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1)
            res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}

char ans[N];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    string a,b;
    cin>>a>>b;
    int n=a.size();
    sort(all(a));
    sort(all(b));
    reverse(all(b));
    int as=0,bs=0;
    int al=n/2,bl=n/2;
    if(n%2)
        bl--;
    else
        al--,bl--;
    int s=0,l=n-1;
    for(int i=0;i<n;i++)
    {
        if(i%2)
        {
            if(b[bs]>a[as])
                ans[s++]=b[bs++];
            else
                ans[l--]=b[bl--];
        }
        else
        {
            if(a[as]<b[bs])
                ans[s++]=a[as++];
            else
                ans[l--]=a[al--];
        }
    }
    ans[n]='\0';
    cout<<ans<<endl;
    return 0;
}
