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
    ll n,m;
    cin>>n>>m;
    vv a(n,vi(m,0));
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>a[i][j];
    ll dp1[n][m],dp2[n][m],dp3[n][m],dp4[n][m];
   
    dp1[0][0]=a[0][0];
    for(ll i=1;i<m;i++)
        dp1[0][i] = dp1[0][i-1] + a[0][i];
    for(ll i=1;i<n;i++)
        dp1[i][0] = dp1[i-1][0] + a[i][0];
    for(ll i=1;i<n;i++)
        for(ll j=1;j<m;j++)
            dp1[i][j] = max(dp1[i-1][j],dp1[i][j-1])+a[i][j];

    dp2[0][m-1]=a[0][m-1];
    for(ll i=m-2;i>=0;i--)
        dp2[0][i] = dp2[0][i+1] + a[0][i];
    for(ll i=1;i<n;i++)
        dp2[i][m-1] = dp2[i-1][m-1] + a[i][m-1];
    for(ll i=1;i<n;i++)
        for(ll j=m-2;j>=0;j--)
            dp2[i][j] = max(dp2[i-1][j],dp2[i][j+1])+a[i][j];

    dp3[n-1][0]=a[n-1][0];
    for(ll i=1;i<m;i++)
        dp3[n-1][i] = dp3[n-1][i-1] + a[n-1][i];
    for(ll i=n-2;i>=0;i--)
        dp3[i][0] = dp3[i+1][0] + a[i][0];
    for(ll i=n-2;i>=0;i--)
        for(ll j=1;j<m;j++)
            dp3[i][j] = max(dp3[i+1][j],dp3[i][j-1])+a[i][j];

    dp4[n-1][m-1]=a[n-1][m-1];
    for(ll i=m-2;i>=0;i--)
        dp4[n-1][i] = dp4[n-1][i+1] + a[n-1][i];
    for(ll i=n-2;i>=0;i--)
        dp4[i][m-1] = dp4[i+1][m-1] + a[i][m-1];
    for(ll i=n-2;i>=0;i--)
        for(ll j=m-2;j>=0;j--)
            dp4[i][j] = max(dp4[i+1][j],dp4[i][j+1])+a[i][j];
    
    // cout<<endl;

    // for(ll i=0;i<n;i++)
    // {
    //     for(ll j=0;j<m;j++) // meet at i,j
    //         cout<<dp1[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;

    // for(ll i=0;i<n;i++)
    // {
    //     for(ll j=0;j<m;j++) // meet at i,j
    //         cout<<dp2[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;

    // for(ll i=0;i<n;i++)
    // {
    //     for(ll j=0;j<m;j++) // meet at i,j
    //         cout<<dp3[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;

    // for(ll i=0;i<n;i++)
    // {
    //     for(ll j=0;j<m;j++) // meet at i,j
    //         cout<<dp4[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<endl;

    ll ans = 0;
    for(ll i=1;i<n-1;i++)
        for(ll j=1;j<m-1;j++) // meet at i,j
        {
            ans = max(ans, max(dp1[i-1][j] + dp2[i][j+1] + dp4[i+1][j] + dp3[i][j-1], dp1[i][j-1] + dp2[i-1][j] + dp4[i][j+1] + dp3[i+1][j]) );
        }
    cout<<ans<<endl;
    return 0;
}