#include "account.h"
#include <cctype> 
#include <map>
#include <fstream>
map<string, Account> accounts;

map<string, Account> loadAccounts(const string& filename = "accounts.txt") {
    map<string, Account> accounts;
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        Account acc = Account::deserialize(line);
        accounts[acc.id] = acc;
    }
    return accounts;
}
void saveAccounts(const map<string, Account>& accounts, const string& filename = "accounts.txt") {
    ofstream out(filename);
    for (const auto& pair : accounts) {
        out << pair.second.serialize() << "\n";
    }
}

bool isNumber(const string& s){
  for(size_t i = 0; i < s.length(); ++i){
    char ch = s[i];
    if(!isdigit(ch)){
      return false;
    }
  }
  return !s.empty();
}
void table(){
  cout<<"Welcome to Raifeissen Bank!"
      <<"\nSelect an Operation:"
      <<"\n1.Create Account"
      <<"\n2.Delete Account"
      <<"\n3.Add Balance"
      <<"\n4.Withdraw Balance"
      <<"\n5.Show Account"
      <<"\nEnter choice (1-5): ";
}

int bank() {
    accounts = loadAccounts();  // Load from file at start

    while (true) {
        table();

        string input;
        int choice;

        while (true) {
            getline(cin, input);
            if (isNumber(input)) {
                choice = stoi(input);
                if (choice >= 1 && choice <= 5) {
                    break;
                } else {
                    cout << "Please enter a number from (1-5): ";
                }
            } else {
                cout << "Invalid Input, Enter a number from (1-5): ";
            }
        }

        cout << "You selected option " << choice << ".\n";

        switch (choice) {
            case 1: {
                string name, lastname;
                cout << "Enter First Name: ";
                getline(cin, name);
                cout << "Enter Last Name: ";
                getline(cin, lastname);

                Account acc(name, lastname);
                accounts[acc.id] = acc;
                acc.display();
                saveAccounts(accounts);
                break;
            }

            case 5: {
                string searchId;
                cout << "Enter Account ID to search: ";
                getline(cin, searchId);
                auto it = accounts.find(searchId);
                if (it != accounts.end()) {
                    it->second.display();
                } else {
                    cout << "Account with ID " << searchId << " not found\n";
                }
                break;
            }

            // Other cases (2-4) go here...
        }

        cout << "\nDo you want to perform another operation? (y/n): ";
        string cont;
        getline(cin, cont);
        if (cont != "y" && cont != "Y") {
            break;
        }
    }

    return 0;
}


int main(){
  return bank();
}

