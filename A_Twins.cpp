#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f1(n) for (int i = 0; i < n; i++)
#define f2(n) for (int j = 0; j < n; j++)
#define mmax 100005
#define all(v) v.begin(), v.end()
#define ll long long

typedef pair<int, int> pi;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    vector<ll> v;
    ll sum = 0, sum1 = 0;
    f1(n)
    {
        int temp;
        cin >> temp;
        v.pb(temp);
        sum = sum + temp;
    }

    sort(v.begin(), v.end());

    f1(n)
    {
        sum1 += sum - v[i];
        sum = sum - v[i];

        if (sum1 > sum)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    return 0;
}