#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f1(n) for (int i = 0; i < n; i++)
#define f2(n) for (int j = 0; j < n; j++)
#define mmax 100005
#define all(v) v.begin(), v.end()
#define ll long long

typedef pair<int, int> pi;
ll s[1234567];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll n, ans = 0, count = 0;
    cin >> n;
    // vector<ll> s;
    s[0] = 0;
    f1(n)
    {
        ll temp;
        cin >> temp;
        s[i + 1] = s[i] + temp;
    }
    // cout<<s[n]<<endl;

    if (s[n] % 3 == 0)
    {
        ll t = s[n] / 3;
        ll p = 2 * (s[n] / 3);

        for (int i = 1; i < n; i++)
        {

            if (s[i] == p)
            {
                ans += count;
            }
            if (s[i] == t)
            {
                count++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}