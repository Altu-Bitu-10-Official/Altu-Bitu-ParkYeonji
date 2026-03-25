#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v;

    for (int i = 1; i <= n; i++)
    {
        v.push_back(i);
    }

    int i = n;
    int start = 1;

    while (v.size() > 1)
    {
        vector<int> temp;

        for (int j = start; j < v.size(); j += 2)
        {
            temp.push_back(v[j]);
        }

        if (v.size() % 2 == 1)
        {
            start = 1 - start;
        }

        v = temp;
        i /= 2;
    }

    cout << v[0];

    return 0;
}