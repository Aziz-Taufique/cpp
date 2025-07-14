#include <bits/stdc++.h>
using namespace std;

void compute(string s, char c, int *left, int *right)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == c)
        {
            *left = i;
            break;
        }
    }

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == c)
        {
            *right = i;
            break;
        }
    }
}

int main()
{
    string s = "aaaba";
    char c = 'a';
    int left = -1;
    int right = -1;

    int *pf = &left;
    int *pl = &right;
    compute(s, c, pf, pl);

    cout << left << " " << right << endl;

    return 0;
}