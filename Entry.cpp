#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

class concept
{
    public:
        string name, serial, author, status;

        void input(){
            cout << "Book Name: ";
            getline(cin, name);
            cout << "Book Serial: ";
            getline(cin, serial);
            cout << "Book Author: ";
            getline(cin, author);
            status = "Available" ;
            cout << endl;

        }
};

vector <concept> books;
int main()
{
    string val;
    int choose;
    cout << "This System is built for Book's Information." << endl << endl
        << "1. Entry New Book." << endl
        << "2. Show Book list. " << endl
        << "3. Remove Book. " << endl
        << "4. Borrow/Return Report. " << endl
        << "5. Exit System." << endl << endl
        << "Choose Your Step Number: " ;

    cin >> choose;
    switch(choose)
    {
    case 1:{
        cout << "How Many Books: ";
        int n;
        cin >> n;
        cin.ignore();
        for (int i=0; i<n; i++){
            concept temp;
            temp.input();
            books.push_back(temp);
        }
        return main();
    }
    case 2:
        cout << left
             << setw(20) << "Book Name"
             << setw(15) << "Book Serial"
             << setw(20) << "Book Author"
             << setw(15) << "Availability"
             << endl << endl;

        for (auto &b : books) {
            cout << left
                 << setw(20) << b.name
                 << setw(15) << b.serial
                 << setw(20) << b.author
                 << setw(15) << b.status
                 << endl;
        }
        cout << endl;
        return main();
    case 3:
        rmv:
        cout << "1. Remove by Serial." << endl
            << "2. Remove by Name." << endl
            << "Choose: ";
            cin >> choose;
            if (choose == 1){
                cout << "Serial of the Book: ";
                cin >> val;
                for (int i=0; i<books.size(); i++){
                    if (val == books[i].serial){
                        books.erase(books.begin() + i);
                        cout << "Book Removal Successful........" << endl;
                        break;
                    }
                }
            }else{
                cout << "Name of the Book: ";
                cin >> val;
                for (int i=0; i<books.size(); i++){
                    if (val == books[i].name){
                        books.erase(books.begin() + i);
                        cout << "Book Removal Successful........" << endl;
                        break;
                    }
                }
            }
        return main();
    case 4:
        cout << left
             << setw(20) << "Book Name"
             << setw(15) << "Book Serial"
             << setw(20) << "Book Author"
             << setw(15) << "Availability"
             << endl << endl;

        for (auto &b : books) {
            cout << left
                 << setw(20) << b.name
                 << setw(15) << b.serial
                 << setw(20) << b.author
                 << setw(15) << b.status
                 << endl;
        }
        cout << endl << "Serial of the Book wanna Borrow or Return: ";
        cin >> val;
        for (int i=0; i<books.size(); i++){
            if (val == books[i].serial){
                if (books[i].status == "Available"){
                    books[i].status = "Borrowed";
                    cout << "Book Borrowed...." << endl;

                }else{
                    books[i].status = "Available";
                    cout << "Book Returned...." << endl;
                }
                break;
            }
        }
        return main();
    default:
        break;
    }
}
