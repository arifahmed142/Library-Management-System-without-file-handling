#include<iostream>
#include<vector>
#include<string>
#include<iomanip>
using namespace std;

class concept
{
    public:
        string name, serial, author;
        int quantity,borrow;

        void input(){
            cout << "Book Name: ";
            getline(cin, name);
            cout << "Book Serial: ";
            getline(cin, serial);
            cout << "Book Author: ";
            getline(cin, author);
            cout << "Book Quantity: ";
            cin >> quantity;
            cin.ignore();
            borrow = 0;
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
             << setw(30) << "Book Name"
             << setw(15) << "Book Serial"
             << setw(30) << "Book Author"
             << setw(15) << "Available"
             << setw(15) << "Borrowed"
             << endl << endl;

        for (auto &b : books) {
            cout << left
                 << setw(30) << b.name
                 << setw(15) << b.serial
                 << setw(30) << b.author
                 << setw(15) << b.quantity
                 << setw(15) << b.borrow
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
        if (books.empty() == 1){
            cout << "No Books are Found!!!" << endl;
            return main();
        }
        cout << left
             << setw(30) << "Book Name"
             << setw(15) << "Book Serial"
             << setw(30) << "Book Author"
             << setw(15) << "Available"
             << setw(15) << "Borrowed"
             << endl << endl;

        for (auto &b : books) {
            cout << left
                 << setw(30) << b.name
                 << setw(15) << b.serial
                 << setw(30) << b.author
                 << setw(15) << b.quantity
                 << setw(15) << b.borrow
                 << endl;
        }
        bandr:
        cout << endl << "Serial of the Book: ";
        cin >> val;
        Borrow:
        cout << "1. Return.\n2. Borrow.\nChoose: ";
        cin >> choose;
        switch(choose)
        {
        case 1:
            for (int i=0; i<books.size(); i++){
                if (val == books[i].serial){
                    if(books[i].borrow == 0){
                        cout << "No Books Borrowed Before!!!" << endl;
                        goto bandr;

                    }
                    books[i].borrow--;
                    books[i].quantity++;
                    cout << "Book Returned Successfully......" << endl;
                    return main();
                }
            }
            cout << "Book Not Found!!!" << endl;
            goto bandr;
        case 2:
            for (int i=0; i<books.size(); i++){
                if (val == books[i].serial){
                    if(books[i].quantity == 0){
                        cout << "No Books are Available!!!" << endl;
                        goto bandr;

                    }
                    books[i].borrow++;
                    books[i].quantity--;
                    cout << "Book Borrowed Successfully......" << endl;
                    break;
                }
            }
            cout << "Book Not Found!!!" << endl;
            goto bandr;
        default:
            cout << "Choose again!!" << endl;
            goto Borrow;
            break;
        }
        return main();
    case 5:
        cout << "System Shutting down.............." ;
        break;
    default:
        cout << "Choose Again!!" << endl;
        return main();
    }
}
