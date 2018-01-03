#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    ll qt, t;
    cin >> qt >> t;
    vector<ll> numbers;
    ll n;
    for (ll i = 0; i < qt ; ++i)
    {
        cin >> n;
        numbers.push_back(n);
    }
    sort( numbers.begin() , numbers.end() );
    ll ans = 0LL;
    for (ll i = 0; i < qt; ++i)
    {
        ans += numbers[i]*max(1LL,t-i);
    }
    cout << ans << endl;
}