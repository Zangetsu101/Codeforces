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

#define N 32001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

bool state[33][33];
vi primes;
bool flag[N];

void sieve()
{
    primes.push_back(2);
    for(int i=3;i<N;i+=2)
    {
        if(!flag[i])
        {
            primes.push_back(i);
            if(i<=(int)sqrt(N))
            {
                for(int j=i*i;j<N;j+=2*i)
                    flag[j]=true;
            }
        }
    }
}

int gcd(int a,int b)
{
    if(!b)
        return a;
    return gcd(b,a%b);
}

int cnt(int &a,int j)
{
    int res=0;
    while(a%primes[j]==0)
        a/=primes[j],res++;
    return res;
}

map< pii , int > mp;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    sieve();
    state[0][0]=true;
//    cout<<primes.size()<<endl;
    for(int i=1;i<33;i++)
    {
        for(int j=1;j<33;j++)
        {
            if(i>=1&&j>=2)
                state[i][j]|=state[i-1][j-2];
            if(i>=2&&j>=1)
                state[i][j]|=state[i-2][j-1];
        }
    }
    int n;
    cin>>n;
    bool flag;
    for(int i=0;i<n;i++)
    {
        flag=true;
        int j=0;
        int a,b;
        cin>>a>>b;
        int ta=a,tb=b;
        if(mp[pii(a,b)]==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        else if(mp[pii(a,b)]==2)
        {
            cout<<"NO"<<endl;
            continue;
        }
        if(a==1&&b==1)
        {
            cout<<"YES"<<endl;
            continue;
        }
        if(gcd(a,b)==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        while(j<primes.size())
        {
            int cnt1=cnt(a,j),cnt2=cnt(b,j);
            if(!state[cnt1][cnt2])
            {
                flag=false;
                break;
            }
            if(primes[j]>(int)sqrt(a)&&primes[j]>(int)sqrt(b))
                break;
            j++;
        }
        if(a>1&&flag)
        {
            int c=0;
            while(b%a==0)
                b/=a,c++;
            if(!state[1][c])
                flag=false;
        }
        if(b>1&&flag)
        {
            int c=0;
            while(a%b==0)
                a/=b,c++;
            if(!state[1][c])
                flag=false;
        }
        if(flag)
        {
            cout<<"YES"<<endl;
            mp[pii(ta,tb)]=1;
        }
        else
        {
            cout<<"NO"<<endl;
            mp[pii(ta,tb)]=2;
        }
    }
    return 0;
}
