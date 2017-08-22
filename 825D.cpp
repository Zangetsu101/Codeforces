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

#define N 1000001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int res[26];
int cnt;
int tv[26];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    string s,t;
    cin>>s>>t;
    tr(s,it)
    {
        if(*it=='?')
            cnt++;
        else
            res[*it-'a']++;
    }
    tr(t,it)
        tv[*it-'a']++;
    for(int i=1;i<N;i++)
    {
        if(!cnt)
            break;
        for(int j=0;j<26;j++)
        {
            if(!cnt)
                break;
            if(res[j]<tv[j]*i)
            {
                int v=tv[j]*i-res[j];
                if(cnt>=v)
                    res[j]+=v,cnt-=v;
                else
                    res[j]+=cnt,cnt=0;
            }
        }
    }
    tr(s,it)
    {
        if(*it!='?')
            res[*it-'a']--;
    }
    int i=0;
    tr(s,it)
    {
        if(*it=='?')
        {
            while(!res[i])
                i++;
            *it='a'+i;
            res[i]--;
        }
    }
    cout<<s<<endl;
    return 0;
}
