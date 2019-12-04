#include<bits/stdc++.h>
using namespace std;
 
#define ll int
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
#define tr1(x) cerr << #x << ": " << x << endl
#define tr2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl
#define tr3(x,y,z) cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define mod 1000000007
#define inf 9999999999999999ll
ll dp[2001][2001];
int main()
{
  /*  ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);*/
    ll n,k;
    scanf(" %d %d",&n,&k);
//    cin>>n>>k;
//    vv dp(k+1,vi(n+1,0));
    for(ll j=0;j<=n;j++)
    {
        dp[1][j]=1;
    }
    for(ll i=2;i<=k;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            //last number is j;
            //length is i;
            dp[i][j]=0;
            for(ll f=1;f*f<=j;f++)
            {
                if(j%f==0)
                {
                    if(f*f==j)
                    {
                        dp[i][j]+=dp[i-1][f];
                        dp[i][j]%=mod;
                    }
                    else
                    {
                        dp[i][j]+=dp[i-1][f];
                        dp[i][j]%=mod;
                        dp[i][j]+=dp[i-1][j/f];
                        dp[i][j]%=mod;
                    }
                    
                }
                
            }
        }
    }
    long long ans=0;
    for(ll i=1;i<=n;i++)
    {
        ans+=dp[k][i];
        ans%=mod;
    }
    printf("%d\n",ans);
//    cout<<ans<<endl;
}
