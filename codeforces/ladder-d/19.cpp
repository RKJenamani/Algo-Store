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
    ll n;
    cin>>n;
    vi p(n,0);
    for(ll i=0;i<n;i++)
        cin>>p[i];
    vi dp(n,0);
    dp[0]=2;
    ll ans=2;
    for(ll i=1;i<n;i++)
    {
        if(p[i]==1)
            dp[i] = ((2*dp[i-1])%mod + 2)%mod; 
        else
            dp[i] = (( (2*dp[i-1])%mod - dp[p[i]-2] + mod)%mod +2)%mod;
    }
    cout<<dp[n-1]<<endl;
    return 0;
}