#include <iostream>
#include <vector>
using namespace std;

void isPrime(vector<bool>& is_prime, int n) { // 소수 판별
    is_prime[0] = false;
    is_prime[1] = false;

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int MAX = 1000000;
    vector<bool> is_prime(MAX + 1, true);

    isPrime(is_prime, MAX);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        bool found = false;

        for (int i = 3; i <= n / 2; i += 2) {
            int a = n - i;

            if (is_prime[i] && is_prime[a]) {
                cout << n << " = " << i << " + " << a << '\n';
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}