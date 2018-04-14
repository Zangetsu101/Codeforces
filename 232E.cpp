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

#define N 505
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

char board[N][N];
bitset<N> top[11][N][N],bottom[11][N][N];
int n,m;

void build(int node,int l,int r)
{
    int mid=(l+r)>>1;
    for(int i=mid;i>=l;i--)
    {
        for(int j=m;j>0;j--)
        {
            if(board[i][j]=='#')
                continue;
            top[node][i][j]=top[node][i][j+1];
            if(i==mid)
                top[node][i][j].set(j);
            else
                top[node][i][j]|=top[node][i+1][j];
        }
    }
    for(int i=mid;i<=r;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(board[i][j]=='#')
                continue;
            bottom[node][i][j]=bottom[node][i][j-1];
            if(i==mid)
                bottom[node][i][j].set(j);
            else
                bottom[node][i][j]|=bottom[node][i-1][j];
        }
    }
    if(l!=r)
        build(node+1,l,mid),build(node+1,mid+1,r);
}

void solve(int node,int l,int r,int x,int y,int i,int j)
{
    int mid=(l+r)>>1;
    if(x<=mid&&mid<=i)
    {
//        cout<<top[node][x][y]<<endl;
//        cout<<bottom[node][i][j]<<endl;
        if((top[node][x][y]&bottom[node][i][j]).count())
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
        return;
    }
    if(i<mid)
        solve(node+1,l,mid,x,y,i,j);
    else
        solve(node+1,mid+1,r,x,y,i,j);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
            cin>>board[i][j];
    }
    build(1,1,n);
    int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        solve(1,1,n,x1,y1,x2,y2);
    }
    return 0;
}
