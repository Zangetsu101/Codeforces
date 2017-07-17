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

#define N 100001
#define mod 1000000007
#define inf 1e9

typedef long long ll;
typedef unsigned long long ull;

int data[N];
int lvalue[N],rvalue[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++)
        cin>>data[i];
    int i=0,j=0;
    while(i<n)
    {
        while(j+1<n&&data[j+1]>=data[j])
            j++;
        while(i<j)
            rvalue[i]=j,i++;
        rvalue[i++]=j++;
    }
    i=n-1,j=n-1;
    while(i>=0)
    {
        while(j-1>=0&&data[j-1]>=data[j])
            j--;
        while(i>j)
            lvalue[i]=j,i--;
        lvalue[i--]=j--;
    }
    for(i=0;i<q;i++)
    {
        int l,r;
        cin>>l>>r;
        l--,r--;
        if(rvalue[l]>=lvalue[r])
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
