#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f1(n) for (int i = 0; i < n; i++)
#define f2(n) for (int j = 0; j < n; j++)
#define mmax 100005
#define all(v) v.begin(), v.end()
#define ll long long

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, d;
    cin >> n >> d;
    int l[n];
    int ard[d];
    int ar[n-d];
    f1(n)
    {
        cin >> l[i];
        if(i<d)
        {
            ard[i] = l[i];
        }
        if(i>=d)
        {
            ar[d-i] = l[i];
        }
        
    }

   
    // for(int i = 0;i<d;i++)
    // {
    //     ard[i] = l[i];
    // }

    // for(int i = 0;i<n-d;i++)
    // {
    //     ar[i] = l[d+i];
    // }

    for(int i = 0;i<n-d;i++)
    {
        cout<<ar[i]<<" ";
    }

    for(int i = 0;i<d;i++)
    {
        cout<<ard[i]<<" ";
    }
}