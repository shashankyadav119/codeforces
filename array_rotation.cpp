#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define f1(n) for (int i = 0; i < n; i++)
#define f2(n) for (int j = 0; j < n; j++)
#define mmax 100005
#define all(v) v.begin(), v.end()
#define ll long long

typedef pair<int, int> pi;

void rev(int arr[], int n)
{
    cout<<endl<<endl;
    for (int i = 0; i < n / 2; i++)
    {
        swap(arr[i], arr[n - 1 - i]);
    }

    // cout<<endl;

    f1(n)
    {
        cout << arr[i] << " ";
    }
}

void rota(int arr[], int n, int k)
{
    int a[k], temp[n - k];
    f1(k)
    {
        a[i] = arr[i];
        cout << a[i] << " ";
    }

    cout << endl;

    f1(n - k)
    {
        temp[i] = arr[k + i];
        cout << temp[i] << " ";
    }

    rev(a, k);
    rev(temp, n - k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    int arr[n];
    f1(n)
    {
        cin >> arr[i];
    }

    rota(arr, n, k);
    return 0;
}