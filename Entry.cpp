#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string>name;
vector<string>serial;
vector<string>author;
vector<string>status;

class concept
{
    public:
        string nam, ser, auth, state;

        void input(){
            cout << "Book Name: ";
            cin >> nam;
            cout << "Book Serial: ";
            cin >> ser;
            cout << "Book Author: ";
            cin >> auth;
            state = "Available" ;
            name.push_back(nam);
            serial.push_back(ser);
            author.push_back(auth);
            status.push_back(state);
        }
};

void display(int p)
{

    cout << name[p] << "\t\t" << serial[p] << "\t\t" << author[p] << "\t\t" << status[p] << endl ;
}

int main()
{
    int choose;
    cout << "This System is built for Book's Information." << endl << endl
        << "1. Entry New Book." << endl
        << "2. Show Book list. " << endl
        << "3. Remove Book. " << endl
        << "4. Borrow Report. " << endl
        << "5. Exit System." << endl << endl
        << "Choose Your Step Number: " ;

    cin >> choose;
    switch(choose)
    {
    case 1:{
        concept book[100];
        int cnt;
        cout << "Quantity of Books: " ;
        cin >> cnt;
        for (int i=0; i<cnt; i++){
            book[i].input();
            cout << endl;
        }
        return main();
    }
    case 2:

        return main();
    case 3:
        return main();
    case 4:
        return main();
    default:
        break;
    }
}
