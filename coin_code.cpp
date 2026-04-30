#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <limits>
using namespace std;

// Greedy approach
int greedy_coin(vector<int> coins, int amount) {
    sort(coins.begin(), coins.end(), greater<int>());
    int count = 0;

    for (int i = 0; i < (int)coins.size(); i++) {
        while (amount >= coins[i]) {
            amount -= coins[i];
            count++;
        }
    }
    return (amount == 0) ? count : INT_MAX;
}

// DP approach
int dp_coin(vector<int> coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < (int)coins.size(); j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }
    return dp[amount];
}


void flush_input() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    int n, amount;


    while (true) {
        cout << "Enter number of coin denominations: ";
        if (cin >> n && n > 0) {
            flush_input();
            break;
        }
        cout << "Invalid! Enter a positive integer.\n";
        flush_input();
    }


    vector<int> coins(n);
    cout << "Enter " << n << " coin denominations:(space separated) ";
    for (int i = 0; i < n;) {
        if (cin >> coins[i] && coins[i] > 0) {
            i++;
        } else {
            cout << "Invalid coin! Enter positive integers only: ";
            flush_input();
        }
    }
    flush_input();

    while (true) {
        cout << "Enter target amount: ";
        if (cin >> amount && amount >= 0) {
            flush_input();
            break;
        }
        cout << "Invalid! Enter non-negative integer.\n";
        flush_input();
    }

    cout << "\nCoins : ";
    for (int c : coins) cout << c << " ";
    cout << "\nAmount: " << amount << "\n";

    int g = greedy_coin(coins, amount);
    int d = dp_coin(coins, amount);
    int h = min(g, d);  

    cout << "\nGreedy result : " << (g == INT_MAX ? -1 : g) << " coins\n";
    cout << "DP     result : " << (d == INT_MAX ? -1 : d) << " coins\n";
    cout << "Hybrid result : " << (h == INT_MAX ? -1 : h) << " coins\n";

    cout << "\nPress Enter to exit...";
    cin.get();

    return 0;
}