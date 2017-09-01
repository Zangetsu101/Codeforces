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

void func(int k)
{
    if(!k)
    {
        cout<<"a"<<endl;
        return;
    }
    int i=0;
    string ans;
    while(true)
    {
        int temp=sqrt(2*k);
        if(temp*(temp+1)/2>k)
            temp--;
        if(!k||temp==1||temp*(temp-1)/2>k)
            break;
        for(int j=0;j<=temp;j++)
            ans.push_back('a'+i);
        k-=temp*(temp+1)/2;
        i++;
    }
    while(k)
    {
        for(int j=0;j<2;j++)
            ans.push_back('a'+i);
        i++;
        k--;
    }
    cout<<ans<<endl;
}


int main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
//    int k;
//    cin>>k;
    int n;
    cin>>n;
    func(n);
    return 0;
}
