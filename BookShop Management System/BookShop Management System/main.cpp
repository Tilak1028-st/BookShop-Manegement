//
//  main.cpp
//  BookShop Management System
//
//  Created by Tilak Shakya on 21/11/22.
//

#include <iostream>
#include <fstream>
#include "BookShop.hpp"
using namespace std;

fstream fp;
BookShop bk;

//MARK: - Function will add book in the record.
void write_book()
{
    system("cls");
    int more_or_main;
    fp.open("book.dat",ios::out|ios::app);
    do
    {
        bk.get_book_details();
        fp.write((char*)&bk,sizeof(BookShop));
        cout<<"\nPress 1 to add more books.";
        cout<<"\nPress 2 to return to main menu.\n";
        cout<<"Enter: ";
        cin>>more_or_main;
    }while(more_or_main == 1);
    fp.close();
}


//MARK: - Function will display  book
void display_a_book(char n[])
{
    system("cls");
    cout<<"\nBOOK DETAILS\n";
    int check=0;
    fp.open("book.dat",ios::in);
    while(fp.read((char*)&bk,sizeof(BookShop))) {
        if(strcmp(bk.getbooknumber(),n)==0) {
            bk.show_all_book();
            check=1;
        }
    }
    fp.close();
    if(check==0)
        cout<<"\n\nBook does not exist";
}


//MARK: - Function will modify book's name
void modify_book()
{
    system("cls");
    char n[20];
    int found=0;
    cout<<"\n\n\tMODIFY BOOK";
    cout<<"\n\n\tEnter The book number: ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    while(fp.read((char*)&bk,sizeof(BookShop)) && found==0) {
        if(strcmp(bk.getbooknumber(),n)==0) {
            bk.show_all_book();
            cout<<"\nEnter The New Details of book"<<endl;
            bk.modify_book();
            int pos=-1*sizeof(bk);
            fp.seekp(pos,ios::cur);
            fp.write((char*)&bk,sizeof(BookShop));
            cout<<"\n\n\t Record Updated Successfully...";
            found=1;
        }
    }
    fp.close();
    if(found==0)
        cout<<"\n\n Record Not Found ";
}


//MARK: - Function will delete book from the record.
void delete_book()
{
    system("cls");
    char n[20];
    int flag=0;
    cout<<"\n\n\n\tDELETE BOOK";
    cout<<"\n\nEnter The Book's number You Want To Delete: ";
    cin>>n;
    fp.open("book.dat",ios::in|ios::out);
    fstream fp2;
    fp2.open("Temp.dat",ios::out);
    fp.seekg(0,ios::beg);
    while(fp.read((char*)&bk,sizeof(BookShop)))
    {
        if(strcmp(bk.getbooknumber(),n)!=0)
        {
            fp2.write((char*)&bk,sizeof(BookShop));
        }
        else
            flag=1;
    }
    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat","book.dat");
    if(flag==1)
        cout<<"\n\n\tRecord Deleted ..";
    else
        cout<<"\n\nRecord not found";
}

void display_allb()
{
    system("cls");
    fp.open("book.dat",ios::in);
    if(!fp)
    {
        cout<<"ERROR!!! FILE COULD NOT BE OPEN ";
        return;
    }
    cout<<"\n\n\t\tBook LIST\n\n";
    cout<<"============================================================================================\n";
    cout<<"Book Number"<<setw(20)<<"Book Name"<<setw(25)<<"Author"<<setw(25)<<"Copies"<<endl;
    cout<<"============================================================================================\n";
    while(fp.read((char*)&bk,sizeof(BookShop)))
    {
        bk.report();
    }
    fp.close();
}

void intro()
{
    system("color 06");
    system("cls");
    cout<<"\t\t\t\t*\t*";
    cout<<"\t\t\t\t**\t**";
    cout<<"\t\t\t\t***\t***";
    cout<<"\t\t\t\t****\t****";
    cout<<"\t\t\t\t*****\t*****";
    cout<<"\t\t\t\t******\t******";
    cout<<"\t\t\t\t*******\t*******";
    cout<<"\t\t\t\t*******\t*******";
    cout<<"\t\t\t\t******\t******";
    cout<<"\t\t\t\t*****\t*****";
    cout<<"\t\t\t\t****\t****";
    cout<<"\t\t\t\t***\t***";
    cout<<"\t\t\t\t**\t**";
    cout<<"\t\t\t\t*\t*";
}


//MARK: - Main Function
int main(int argc, const char * argv[]) {
    
    int option = 0;
    for(;;){
        intro();
        
        cout << "*********************" << endl;
        cout << "Welcome to Book Shop" << endl;
        cout << "********************" << endl;
        cout << " " << endl;
        cout << "Press 1 to TO BUY" << endl;
        cout << "Press 2 to SHOW ALL BOOKS" << endl;
        cout << "Press 3 to CHECK AVAILABILITY" << endl;
        cout << "Press 4 to MODIFY BOOKS" << endl;
        cout << "Press 5 to DELETE BOOKS" << endl;
        cout << "Press 6 to EXIT" << endl;
        cout<<"\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout<<"\n\t\tOption: ";
        
        cin >> option;
        
        switch (option) {
            case 1:
                write_book();
                break;
            case 2:
                display_allb();
                break;
            case 3:
                char num[20];
                system("cls");
                cout<<"\n\n\tPlease Enter The book No. ";
                cin>>num;
                display_a_book(num);
                break;
            case 4:
                modify_book();
                break;
            case 5:
                delete_book();
                break;
            case 6:
                exit(0);
                break;
            default:
                cout << "\a";
        }
    }
    return 0;
}
