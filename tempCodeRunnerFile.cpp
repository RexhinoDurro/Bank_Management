#include "account.h"
#include <cctype> 
#include <map>
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

int bank(){
  map<string, Account> accounts;
  string input;
  int choice;
  int id;
  string name, lastname;

  table();
  while(true){
    getline(cin, input);
    
    if(isNumber(input)){
      choice = stoi(input);
      if (choice >= 1 && choice <= 5){
        break;
      }
      else{
        cout <<"please enter a number from (1-5): ";
      }
    }
    else{
      cout <<"Invalid Input, Enter a number from (1-5): ";
    }
  }
  cout << "You selected option " << choice << ".\n";

  switch(choice){
  case 1: {
    cout << "Enter First Name: ";
    getline(cin, name);

    cout << "Enter Last Name";
    getline(cin, lastname);

    Account acc(name, lastname);
    accounts[acc.id] = acc;
    acc.display();
    break;
  }
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5: {
    string searchId;
    cout << "Enter Account ID to search: ";
    getline(cin, searchId);
    auto it = accounts.find(searchId);
    if(it != accounts.end()){
      it->second.display();
    } else {
      cout << "Account with ID" << searchId <<"not found \n";
    }
    }
  }
   return 0;
  
}

