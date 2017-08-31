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

struct circle
{
    int x,y;
    int r;
};

double dist(double x1,double y1,double x2,double y2)
{
    double res=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    return res;
}

bool eq(double a,double b)
{
    if(abs(a-b)<=1e-6)
        return true;
    return false;
}

bool isInside(circle a,circle b)
{
    double d=dist(a.x,a.y,b.x,b.y);
    d+=b.r;
    if(d<a.r||eq(d,a.r))
        return true;
    return false;
}

bool isOutside(circle a,circle b)
{
    double d=dist(a.x,a.y,b.x,b.y);
    d-=b.r;
    if(d>a.r||eq(a.r,d))
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int r,d;
    cin>>r>>d;
    circle inner,outer;
    inner.x=inner.y=outer.x=outer.y=0;
    inner.r=r-d;
    outer.r=r;
    int n;
    cin>>n;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin>>x>>y>>r;
        circle temp;
        temp.x=x,temp.y=y,temp.r=r;
        if(isInside(outer,temp)&&isOutside(inner,temp))
            cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
