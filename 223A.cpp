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

int opening[N];
int ans[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    string str;
    int res=0;
    cin>>str;
    int n=str.size();
    stack< pii > s;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='(')
            opening[i]=-1,s.push(pii(0,i));
        else if(str[i]=='[')
            opening[i]=-1,s.push(pii(1,i));
        else if(str[i]==')')
        {
            if(s.empty())
            {
                opening[i]=-1;
                continue;
            }
            if(s.top().first)
            {
                opening[i]=-1;
                while(!s.empty())
                    s.pop();
            }
            else
            {
                opening[i]=s.top().second;
                s.pop();
            }
        }
        else
        {
            if(s.empty())
            {
                opening[i]=-1;
                continue;
            }
            if(s.top().first)
            {
                opening[i]=s.top().second;
                s.pop();
            }
            else
            {
                opening[i]=-1;
                while(!s.empty())
                    s.pop();
            }
        }
    }
    int start=-1,end=-1;
    for(int i=1;i<=n;i++)
    {
        int v;
        if(str[i-1]==']')
            v=1;
        else
            v=0;
        if(opening[i-1]!=-1)
            ans[i]=v+ans[i-1]+ans[opening[i-1]];
        if(ans[i]>res)
        {
            res=ans[i];
            end=i-1;
            start=opening[i-1];
            while(start&&opening[start-1]!=-1)
                start=opening[start-1];
        }
    }
    cout<<res<<endl;
    if(res)
    {
        for(int i=start;i<=end;i++)
            cout<<str[i];
    }
    cout<<endl;
    return 0;
}
// []()[](()][]()()[]
