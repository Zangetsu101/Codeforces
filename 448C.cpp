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

#define N 5001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int data[N];
int value[4*N];
int n;

void build(int node,int l,int r)
{
    int mid=(l+r)>>1;
    if(l==r)
    {
        value[node]=l;
        return;
    }
    build(node*2,l,mid);
    build(node*2+1,mid+1,r);
    if(data[value[node*2]]<data[value[node*2+1]])
        value[node]=value[node*2];
    else
        value[node]=value[node*2+1];
}

int query(int node,int l,int r,int i,int j)
{
    int mid=(l+r)>>1;
    if(i>r||j<l)
        return -1;
    if(i<=l&&j>=r)
        return value[node];
    int lvalue=query(node*2,l,mid,i,j);
    int rvalue=query(node*2+1,mid+1,r,i,j);
    if(lvalue==-1)
        return rvalue;
    if(rvalue==-1)
        return lvalue;
    if(data[lvalue]<data[rvalue])
        return lvalue;
    else
        return rvalue;
}

int solve(int l,int r,int cnt)
{
    if(r<l)
        return 0;
    if(l==r)
        return min(1,data[l]-cnt);
    int idx=query(1,0,n-1,l,r);
    return min(r-l+1,data[idx]-cnt+solve(l,idx-1,data[idx])+solve(idx+1,r,data[idx]));

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>data[i];
    build(1,0,n-1);
    cout<<solve(0,n-1,0)<<endl;
    return 0;
}
