class Bank {
private:
    vector<long long> bal; // store balances, 0-indexed internally

    // helper to check if account index (1-indexed externally) is valid
    inline bool valid(int account) {
        return account >= 1 && account <= (int)bal.size();
    }

public:
    Bank(vector<long long>& balance) {
        bal = balance; // copy (balances are 1-indexed in problem but we store 0-indexed)
    }

    bool transfer(int account1, int account2, long long money) {
        if (!valid(account1) || !valid(account2)) return false;
        int a = account1 - 1;
        int b = account2 - 1;
        if (bal[a] < money) return false;
        bal[a] -= money;
        bal[b] += money;
        return true;
    }

    bool deposit(int account, long long money) {
        if (!valid(account)) return false;
        bal[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!valid(account)) return false;
        int a = account - 1;
        if (bal[a] < money) return false;
        bal[a] -= money;
        return true;
    }
};
