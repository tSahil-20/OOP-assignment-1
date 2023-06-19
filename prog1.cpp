#include<iostream>
#include<string>
using namespace std;

class Book{
    string title;
    string author;
    string isbn;
    bool isAvailable;

    public:
    Book(){}
    Book(string title,string author, string isbn, bool isAvailable){
        this->title = title;
        this->author = author;
        this->isbn = isbn;
        this->isAvailable = isAvailable;
    }
    string getTitle(){ return title; }
    string getauthor(){ return author; }
    string getisbn(){ return isbn; }
    bool getisAvailable(){ return isAvailable; }
    void setisAvailable(bool ava){ isAvailable = ava; }
};

class Library{
    Book b[50];
    int n=0;
    public:
    Library(){}
    void addbook(string t,string a, string isbn){
        n++; 
        b[n] = Book(t, a, isbn, true); 
        cout<<"Book added in Library"<<endl;
    }
    void borrowbook(string i){  
        for(int a=0;a<n+1;a++){
            if(b[a].getisbn() == i){
                if(b[a].getisAvailable()==true){
                    b[a].setisAvailable(false);
                    cout << "Book with isb number: "<< i << " is being borrowed!" << endl;
                    return;
                }else{ cout << "Book with isb number: "<< i << " is not Available" << endl; }
                return;
            }
        }
    }

    void returnbook(string i){  
        for(int a=0;a<n+1;a++){
            if(b[a].getisbn() == i){
                    b[a].setisAvailable(true);
                    cout << "Book with isb number: "<< i << " is being returned!" << endl;
            } else{ cout << "Book with isb number: "<< i << " does not exist!" << endl; }
        }
    }

    void displayBook(){  
        for(int a=0;a<n+1;a++){
            if(b[a].getisAvailable() == true){
                    cout<<"Book details --> " << endl;
                    cout<<"Book Title: "<<b[a].getTitle() << endl;
                    cout<<"Book Author: "<<b[a].getauthor() << endl;
                    cout<<"Book Bn: "<<b[a].getisbn() << endl;
            }
            cout<<endl;
        }
    }

};

int main(){
    int flag = 1, option;
    string bname, bauthor, bn;
    Library lib;
    while(flag){
        cout <<endl<<"Enter 1 for adding new book"<<endl<<"Enter 2 for borrowing book"<<endl<<"Enter 3 for Returning a book"<<endl<<"Enter 4 for Displaying books"<<endl<<"Enter 5 for exit"<<endl<<endl;
        cout<<"Enter options: ";
        cin>>option;
        switch (option){
        case 1:
            cout << "Enter book name: ";
            cin >> bname ;
            cout << "Enter book author: ";
            cin >> bauthor ;
            cout << "Enter book bn: ";
            cin >> bn ;
            lib.addbook(bname, bauthor, bn);
        break;
        
        case 2:
            cout << "Enter book bn: ";
            cin >> bn ;
            lib.borrowbook(bn);
        break;

        case 3:
            cout << "Enter book bn: ";
            cin >> bn ;
            lib.returnbook(bn);
        break;

        case 4:
            lib.displayBook();
        break;

        case 5:
            cout << "Bye Bro!!!"<<endl<<"See you soon!!"<<endl;
            flag = 0;
        break;

        default:
            cout<<"Enter correct option"<<endl;
            break;
        }
    }
    cout << '\n';
    return 0;
}