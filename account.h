#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <chrono>
#include <random>
using namespace std;

  string generateUniqueID(){
    auto now = chrono::system_clock::now();
    auto millis = chrono::duration_cast<chrono::milliseconds>(now.time_since_epoch()).count();

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1000, 9999);

    stringstream ss;
    ss << "ID" << millis << dist(gen);
    return ss.str();
  }

  class Account {
  public:
    string id;
    string name;
    string lastname;
    double balance = 0;


    Account() {
        id = generateUniqueID();
        name = "";
        lastname = "";
    }

    Account( string name, string lastname): name(name), lastname(lastname) {
        id = generateUniqueID();
      }
    

    void display(){
      cout <<"\n__________________________"
           <<"\n|*** ACCOUNT INFORMATION ***|"
           <<"\n__________________________"
           <<"\n| Account id: "<< id 
           <<"\n__________________________"
           <<"\n| Account Name: "<< name
           <<"\n__________________________"
           <<"\n| Account lastname: "<< lastname 
           <<"\n__________________________"
           <<"\n| Account Balance: "<<balance
           <<"\n__________________________";
    }

    string serialize() const {
        stringstream ss;
        ss << id << "," << name << "," << lastname << "," << balance;
        return ss.str();
    }

    static Account deserialize(const string& line) {
        stringstream ss(line);
        string id, name, lastname, balanceStr;
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, lastname, ',');
        getline(ss, balanceStr);

        Account acc;
        acc.id = id;
        acc.name = name;
        acc.lastname = lastname;
        acc.balance = stod(balanceStr);
        return acc;
    }
  };