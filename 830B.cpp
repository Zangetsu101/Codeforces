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

int data[N];
int n;

struct segmentedTree
{
    int cnt[N<<1],mini[N<<1];

    void build()
    {
        for(int i=n;i<(n<<1);i++)
            cnt[i]=1,mini[i]=i-n+1;
        for(int i=n-1;i>0;i--)
        {
            cnt[i]=cnt[i<<1]+cnt[i<<1^1];
            if(data[mini[i<<1]]<=data[mini[i<<1^1]])
                mini[i]=mini[i<<1];
            else
                mini[i]=mini[i<<1^1];
        }
    }

    int getCount(int i,int j)
    {
        i+=n,j+=n;
        int ans=0;
        while(i<j)
        {
            if(i&1)
                ans+=cnt[i],i++;
            if(!(j&1))
                ans+=cnt[j],j--;
            i>>=1,j>>=1;
        }
        if(i==j)
            ans+=cnt[i];
        return ans;
    }
    int getMini(int i,int j)
    {
        i+=n,j+=n;
        int ans=0;
        while(i<j)
        {
            if(i&1)
            {
                if(data[mini[i]]<data[ans])
                    ans=mini[i];
                else if(data[mini[i]]==data[ans])
                    ans=min(ans,mini[i]);
                i++;
            }
            if(!(j&1))
            {
                if(data[mini[j]]<data[ans])
                    ans=mini[j];
                else if(data[mini[j]]==data[ans])
                    ans=min(ans,mini[j]);
                j--;
            }
            i>>=1,j>>=1;
        }
        if(i==j)
        {
            if(data[mini[i]]<data[ans])
                    ans=mini[i];
            else if(data[mini[i]]==data[ans])
                ans=min(ans,mini[i]);
        }
        return ans;
    }

    void remove(int idx)
    {
        idx+=n;
        cnt[idx]=0;
        mini[idx]=0;
        idx>>=1;
        while(idx>0)
        {
            cnt[idx]=cnt[idx<<1]+cnt[idx<<1^1];
            if(data[mini[idx<<1]]<data[mini[idx<<1^1]])
                mini[idx]=mini[idx<<1];
            else if(data[mini[idx<<1]]==data[mini[idx<<1^1]])
                mini[idx]=min(mini[idx<<1],mini[idx<<1^1]);
            else
                mini[idx]=mini[idx<<1^1];
            idx>>=1;
        }
    }
}st;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
//    freopen("Input.txt","r",stdin);
//    freopen("Output.txt","w",stdout);
    cin>>n;
    data[0]=inf;
    for(int i=1;i<=n;i++)
        cin>>data[i];
    st.build();
    ll ans=0;
    int idx=1,mIdx,t;
    while(st.getCount(0,n-1))
    {
        mIdx=st.getMini(0,n-1);
        t=st.getMini(idx-1,n-1);
        if(data[mIdx]<data[t])
        {
            if(mIdx<idx)
                ans+=st.getCount(idx-1,n-1)+st.getCount(0,mIdx-1);
            else
                ans+=st.getCount(idx-1,mIdx-1);
            idx=mIdx;
            st.remove(mIdx-1);
        }
        else
        {
            ans+=st.getCount(idx-1,t-1);
            idx=t;
            st.remove(t-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}
