#include<iostream>
#include<string.h>
#include <stdlib.h>
#include <ctime>
using namespace std;

class Bank {
    long acc_no;
    float balance = 0.0;
    string name;

public:
    void openAccount();

    void showAccount() {
        cout << "\n\nAccount Number: " << acc_no << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    void deposit() {
        long amt;
        cout << "Enter Amount you want to Deposit: ";
        cin >> amt;
        balance += amt;
    }

    void withdraw() {
        long amt;
        cout << "Enter Amount you want to Withdraw: ";
        cin >> amt;
        
        if (amt <= balance){
            balance -= amt;
            cout << amt << " deduct sucessfully !  \n You current account balance is " << balance;
        }
        else 
            cout << "You've not enough balance ! \n You current account balance is "<< balance;
    }

    long create_new_ac() {
        srand((unsigned)time(0));
        return rand() * 999;
    }   

    bool searchAccount(int);
};

void Bank :: openAccount() {
    acc_no = create_new_ac();
    cout << "Name: ";
    cin >> name;
    cout << "How much money you want to deposit: ";
    cin >> balance;
}

bool Bank :: searchAccount(int a) {
    if(acc_no == a){
        showAccount();
        return true;
    }
    return false;
}

int is_account_found(Bank acc_arr[], int current_no, int ac_no)
{
    bool is_found = false;
    for (int i = 0; i < current_no; i++)
    {
        if (acc_arr[i].searchAccount(ac_no))
            return i;
    }
    cout << "NO data present on ac number " << ac_no;
    return 0;
}

int main()
{
    Bank account[100];

    int found = 0, a, ch, current_ac_no = 0;

    do {
        cout << "\n\n1. Create account \n2. Display All\n3. Display By Account Number\n4. Deposit\n5. Withdraw\n6. Exit" << endl;
             
        cout << "\n\nEnter Your Choice: ";
        cin >> ch;

        switch(ch) {
            case 1:
                account[current_ac_no].openAccount();
                current_ac_no += 1;
                break;

            case 2:
                for(int i = 0; i < current_ac_no; i++)
                    account[i].showAccount();
                break;

            case 3:
                cout << "\n\nEnter Account Number: ";
                cin >> a;
                is_account_found(account, current_ac_no, a);
                break;

            case 4:
                cout << "\n\nEnter Account Number to Deposit: ";
                cin >> a;
                int is_found = is_account_found(account, current_ac_no, a);
                if (is_found != false) {
                    account[is_found].deposit();
                    break;
                }

            case 5:
                cout << "\n\nEnter Account Number to Withdraw: ";
                cin >> a;
                for (int i = 0; i < current_ac_no; i++) {
                    found = account[i].searchAccount(a);
                    if(found){
                        account[i].withdraw();
                        break;
                    }
                }
                if(found != 1)
                    cout << "Record Not Found";
                break;

            case 6:
                cout << "\n\nHave a nice day";
                break;

            default: 
                cout << "\n\nSorry.. Try Again!!";
        };

    }while(ch != 6);

    return 0;
}
