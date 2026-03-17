#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int W_0, I_0, T, D, I, A;

    cin >> W_0 >> I_0 >> T;
    cin >> D >> I >> A;

    int W = W_0;
    int I_G = I_0;

    W_0 += (I - (I_0 + A))*D;

    if (W_0 <= 0) {
        cout << "Danger Diet" << '\n';
    }
    else { cout << W_0 << ' ' << I_0 << '\n'; };


    for (int i = 0; i < D; i++) {
        int con = I_G + A;
        int diff = I - con;
        W += diff;


        if (abs(diff) > T) {
            if (diff < 0) {
                I_G += (I - con - 1) / 2;
            }
            else I_G += (I - con) / 2;
        }
    }


    if ((W <= 0) || (I_G <= 0)) {
        cout << "Danger Diet" << '\n';
    }
    else if (I_0 - I_G > 0) { cout << W << ' ' << I_G << ' ' << "YOYO" << '\n'; }
    else if (I_0 - I_G <= 0)
    {
        cout << W << ' ' << I_G << ' ' << "NO" << '\n';
    };

    return 0;
}