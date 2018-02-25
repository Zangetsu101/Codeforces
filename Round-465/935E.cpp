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

#define N 10001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int sign;
string str;
int close[N];
ll dp[N][101][2];
bool flag[N][101][2];

ll func(int pos,int rem,bool f)
{
    ll &ans=dp[pos][rem][f];
    if(flag[pos][rem][f])
        return ans;
    if(f)
        ans=-inf;
    else
        ans=inf;
    flag[pos][rem][f]=true;
    if(str[pos]>='0'&&str[pos]<='9')
    {
        if(!rem)
            return ans=str[pos]-'0';
        else
            return inf;
    }
    pos++;
    ll l1,l2,r1,r2;
    for(int i=0;i<=rem;i++)
    {
        l1=func(pos,i,true);
        l2=func(pos,i,false);
        r1=inf,r2=inf;
        if(i<rem)
            r1=func(close[pos]+2,rem-1-i,true),r2=func(close[pos]+2,rem-1-i,false);
        if(f)
        {
            if(abs(l1)!=inf)
            {
                if(abs(r1)!=inf)
                    ans=max(ans,l1+sign*r1);
                if(abs(r2)!=inf)
                    ans=max(ans,l1+sign*r2);
            }
            if(abs(l2)!=inf)
            {
                if(abs(r1)!=inf)
                    ans=max(ans,l2+sign*r1);
                if(abs(r1)!=inf)
                    ans=max(ans,l2+sign*r2);
            }
        }
        else
        {
            if(abs(l1)!=inf)
            {
                if(abs(r1)!=inf)
                    ans=min(ans,l1+sign*r1);
                if(abs(r2)!=inf)
                    ans=min(ans,l1+sign*r2);
            }
            if(abs(l2)!=inf)
            {
                if(abs(r1)!=inf)
                    ans=min(ans,l2+sign*r1);
                if(abs(r1)!=inf)
                    ans=min(ans,l2+sign*r2);
            }
        }
        r1=func(close[pos]+2,rem-i,true),r2=func(close[pos]+2,rem-i,false);
        sign*=-1;
        if(f)
        {
            if(abs(l1)!=inf)
            {
                if(abs(r1)!=inf)
                    ans=max(ans,l1+sign*r1);
                if(abs(r2)!=inf)
                    ans=max(ans,l1+sign*r2);
            }
            if(abs(l2)!=inf)
            {
                if(abs(r1)!=inf)
                    ans=max(ans,l2+sign*r1);
                if(abs(r1)!=inf)
                    ans=max(ans,l2+sign*r2);
            }
        }
        else
        {
            if(abs(l1)!=inf)
            {
                if(abs(r1)!=inf)
                    ans=min(ans,l1+sign*r1);
                if(abs(r2)!=inf)
                    ans=min(ans,l1+sign*r2);
            }
            if(abs(l2)!=inf)
            {
                if(abs(r1)!=inf)
                    ans=min(ans,l2+sign*r1);
                if(abs(r1)!=inf)
                    ans=min(ans,l2+sign*r2);
            }
        }
        sign*=-1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    cin>>str;
    int n=str.size();
    stack<int> s;
    for(int i=0;i<n;i++)
    {
        if(str[i]>='0'&&str[i]<='9')
            close[i]=i;
        if(str[i]=='(')
            s.push(i);
        else if(str[i]==')')
            close[s.top()]=i,s.pop();
    }
    int p,m;
    cin>>p>>m;
    if(p<m)
        sign=1;
    else
        sign=-1;
    cout<<func(0,min(p,m),true)<<endl;
    return 0;
}
