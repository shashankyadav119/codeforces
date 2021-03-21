#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define f1(n) for (ll i = 0; i < n; i++)
vector<char> random_problems(int m, int k, int n)
{
    vector<char> var_p;
    vector<char> var_n;
    for (int i = 0; i < n; i++)
    {
        char c;
        cin >> c;
        var_p.push_back(tolower(c));
        var_n.push_back(toupper(c));
    }

    vector<char> var;
    var.insert(var.begin(), var_p.begin(), var_p.end());
    var.insert(var.end(), var_n.begin(), var_n.end());
    int temp = 10;
    vector<char> clauses;
    vector<char> all_comb;
    while (next_permutation(var.begin(), var.end()))
    {
        for (int i = 0; i < k; i++)
            all_comb.push_back(var[i]);
    }
    int j = 0;
    while (j < temp)
    {
        sample(all_comb.begin(), all_comb.end(), back_inserter(clauses), m);
    }

    return all_comb;
}
int main()
{
    int k, m, n;
    cout << "enter the number of clauses : ";
    cin >> m;
    cout << "\n\t enter the number of variables in each clause:";
    cin >> k;
    cout << "\n enter the number of variables  :";
    cin >> n;
    vector<char> vec = random_problems(m, k, n);
    int temp = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
        if (i % k - 1 == 0)
            cout << "\n";
    }
}