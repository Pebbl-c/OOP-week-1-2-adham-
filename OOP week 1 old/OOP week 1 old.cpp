#include <iostream>
#include <ctime>
using namespace std;

struct {
    int isdone=0;
    char date[26];
    double price;
}company1[10], company2[10];

//basically allows you to enter the data, can be re-entered but once confirmed cannot be overwritten. will skip entered data. e.g [already have data for transaction 1 & 2, skip to 3]
void insertdata(char no_of_company) {
    int i;
    char input='1';
    time_t tr_time;
    cout << endl;
    if (no_of_company == '1') {
        for (i = 0; i < 10; i++) {
            if (company1[i].isdone == 0) {
                if (input == '2') {
                    i--;
                    company1[i].isdone = 0;
                }
                else if (input == '3')
                    break;
                cout << "Please insert the price of transaction " << i + 1 << " (company 1) : RM ";
                cin >> company1[i].price;
                time(&tr_time);
                ctime_s(company1[i].date, sizeof company1[i].date, &tr_time);
                company1[i].isdone = 1;
                cout << "\nPlease choose the following:\n1- Record Next Data\n2- Re-enter Data\n3- Finish entering data\n";
                cin >> input;
            }
        }
        cout << endl;
    }
    else if (no_of_company == '2') {
        for (i = 0; i < 10; i++) {
            if (company2[i].isdone == 0) {
                if (input == '2') {
                    i--;
                    company2[i].isdone = 0;
                }
                else if (input == '3')
                    break;
                cout << "Please insert the price of transaction " << i + 1 << " (company 2) : RM ";
                cin >> company2[i].price;
                time(&tr_time);
                ctime_s(company2[i].date, sizeof company2[i].date, &tr_time);
                company2[i].isdone = 1;
                cout << "\nPlease choose the following:\n1- Record Next Data\n2- Re-enter Data\n3- Finish entering data\n";
                cin >> input;
            }
        }
        cout << endl;
    }
}

//you can choose to view data from which company, no data results in error
void viewdata(char no_of_company) {
    if (no_of_company == '1') {
        if (company1[0].price == 0) {
            cout << "Error!! No value inserted for company 1 yet\n\n";
        }
        else if (company1[0].price != 0) {
            cout << "\nData for Company 1:\n--------------------------------------\n";
            for (int i = 0; i < 10; i++) {
                if (company1[i].isdone == 1) {
                    cout << "Transaction " << i + 1 << " : RM " << company1[i].price << " at " << company1[i].date;
                }
            }
            cout << "--------------------------------------\n\n";
        }
    }
    else if (no_of_company == '2') {
        if (company2[0].price == 0) {
            cout << "Error!! No value inserted for for company 2 yet\n\n";
        }
        else if (company2[0].price != 0) {
            cout << "\nData for Company 2:\n--------------------------------------\n";
            for (int i = 0; i < 10; i++) {
                if (company2[i].isdone == 1) {
                    cout << "Transaction " << i + 1 << " : RM " << company2[i].price << " at " << company2[i].date;
                }
            }
            cout << "--------------------------------------\n\n";
        }
    }
}

//main menu (and other menus), loops if invalid input
void mainmenu(){
 char input;
    while (1) {
        cout << "========Data Collection Software========\nType the following:\nS - Start inserting data\nV - View data\nX - Exit\n\n";
        cin >> input;
        if (input == 'S' || input == 's') {
            while (1) {
                cout << "\nFrom which company? (1/2) : Company ";
                cin >> input;
                if (input == '1' || input == '2')
                    break;
                else
                    cout << "Error !!! Invalid input" << endl;
                cout << endl;
            }
            if (company1[9].isdone == 1 && input == '1')
                cout << "Already entered transactions for this company\n\n";
            else if (company2[9].isdone == 1 && input == '2')
                cout << "Already entered transactions for this company\n\n";
            else
                insertdata(input);
        }
        else if (input == 'V' || input == 'v') {
            while (1) {
                cout << "\nFrom which company? \n1- Company 1\n2- Company 2\n3- both company\n\n";
                cin >> input;
                if (input == '1' || input == '2' || input == '3')
                    break;
                else
                    cout << "Error !!! Invalid input" << endl;
                cout << endl;
            }
            if (input == '1' || input == '2') {
                viewdata(input);
            }
            else if (input == '3') {
                viewdata('1');
                viewdata('2');
            }
        }
        else if (input == 'X' || input == 'x') {
            break;
        }
    }
}

int main()
{
    mainmenu();
    return 0;
}