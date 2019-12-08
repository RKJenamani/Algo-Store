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

vi decToBinary(ll n) 
{ 
    vi binaryNum;  
    int i = 0; 
    while (n > 0) {  
        binaryNum.pb(n % 2); 
        n = n / 2; 
        i++; 
    }  
    reverse(binaryNum.begin(),binaryNum.end());
    return binaryNum; 
} 
 
int main()
{
    ll l,r;
    cin>>l>>r;
    vi binl, binr;
    binl = decToBinary(l);
    binr = decToBinary(r);

    // for(ll i=0;i<binl.size();i++)
    //     cout<<binl[i];
    // cout<<endl;

    // for(ll i=0;i<binr.size();i++)
    //     cout<<binr[i];
    // cout<<endl;

    vi ans(binr.size(),0);

    if(binr.size()>binl.size())
    {
        for(ll i=0;i<binr.size();i++)
        {
            ans[i]=1;
        }        
    }
    else
    {
        ll flag = 1;
        for(ll i=0;i<binr.size();i++)
        {
            if(flag && binr[i]==binl[i]) 
            {
                ans[i]=0;
            }
            else
            {
                flag=0;
                ans[i]=1;
            }
        }
    }

    // for(ll i=0;i<ans.size();i++)
    //     cout<<ans[i];
    // cout<<endl;


    ll val=0;
    ll pow=1;
    for(ll i=ans.size()-1;i>=0;i--)
    {
        val+=pow*ans[i];
        pow*=2;
    }
    cout<<val<<endl;

    return 0;
}