Account* findAccount(const string& accountNumber) {
        auto it = find_if(accounts.begin(), accounts.end(),
            [&accountNumber](Account* acc) {
                return acc-> accountNumber == accountNumber;
            });
        return (it != accounts.end()) ? *it : nullptr;