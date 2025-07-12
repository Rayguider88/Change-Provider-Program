#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Coin change provider class
class ChangeProvider {
public:
    string name;
    double feePercent; // fee percentage taken from the total

    ChangeProvider(string n, double fee) : name(n), feePercent(fee) {}

    // Calculates payout after fees
    double calculatePayout(double amount) {
        return amount * (1 - feePercent / 100);
    }

    void display() {
        cout << "Provider: " << name << ", Fee: " << feePercent << "%" << endl;
    }
};

int main() {
    vector<ChangeProvider> providers = {
        ChangeProvider("CoinStar", 10.0),
        ChangeProvider("QuickChange", 7.5),
        ChangeProvider("FastCoin", 5.0)
    };

    cout << "--- Welcome to the Coin Machine ---\n\n";

    double coinAmount;
    cout << "Insert total coins ($): ";
    cin >> coinAmount;

    cout << "\nAvailable Change Providers:\n";
    for (size_t i = 0; i < providers.size(); ++i) {
        cout << i + 1 << ". ";
        providers[i].display();
    }

    int choice;
    cout << "\nSelect a provider (1-" << providers.size() << "): ";
    cin >> choice;

    if (choice >= 1 && choice <= providers.size()) {
        ChangeProvider selected = providers[choice - 1];
        double payout = selected.calculatePayout(coinAmount);
        cout << "\nUsing " << selected.name << ", after a " << selected.feePercent
             << "% fee, your payout is: $" << payout << endl;
    } else {
        cout << "Invalid choice. Transaction canceled.\n";
    }

    cout << "\nThank you for using the Coin Machine.\n";

    return 0;
}
