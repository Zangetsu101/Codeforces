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

bool ch[26];

int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,k;
    cin>>n>>k;
    string str;
    cin>>str;
    tr(str,it)
        ch[*it-'a']=true;
    int m=0;
    while(!ch[m])
        m++;
    if(k>n)
    {
        cout<<str;
        for(int i=n;i<k;i++)
            cout<<(char)('a'+m);
        cout<<endl;
        return 0;
    }
    for(int i=k-1;i>=0;i--)
    {
        for(int j=str[i]-'a'+1;j<26;j++)
        {
            if(ch[j])
            {
                str[i]='a'+j;
                m=0;
                while(!ch[m])
                    m++;
                for(int l=i+1;l<n;l++)
                    str[l]='a'+m;
                for(int l=0;l<k;l++)
                    cout<<str[l];
                cout<<endl;
                return 0;
            }
        }
    }
    return 0;
}
