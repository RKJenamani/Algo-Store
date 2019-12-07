#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define lf long double
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef pair <ll,ll> ii;
typedef vector <ll> vi;
typedef vector <ii> vii;
typedef vector <bool> vb;
typedef vector <vector <ll> > vv;
typedef vector <string> vs;
typedef vector <lf> vf;
#define mod 1000000007
#define inf 999999999999999ll
 
int main()
{
    ll t,k,a,b;
    cin>>t>>k;
    vi dp(100001,0);
    dp[0]=1;
    for(ll i=1;i<=100000;i++)
    {
        if(i-k >= 0 )
            dp[i]=(dp[i-1]%mod+dp[i-k]%mod)%mod;
        else
            dp[i]=dp[i-1];
        // cout<<dp[i]<<" ";
    }
    for(ll i=1;i<=100000;i++)
        dp[i] = (dp[i]%mod + dp[i-1]%mod)%mod;
    while(t--)
    {
        cin>>a>>b;
        cout<<(dp[b]-dp[a-1]+mod)%mod<<endl;
    }
    return 0;
}