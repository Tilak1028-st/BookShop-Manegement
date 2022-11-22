//
//  BookShop.cpp
//  BookShop Management System
//
//  Created by Tilak Shakya on 22/11/22.
//

#include "BookShop.hpp"
#include<string.h>
#include<iomanip>
#include<iostream>


//MARK: - Function to show all books in the records
void BookShop::show_all_book(){
    cout << "Book's Number" << book_number << endl;
    cout << "Book's Name" << book_name << endl;
    cout << "Book's Author" << author_name << endl;
    cout << "No. Of Copies" << nums_copies << endl;;
}


//MARK: - Function to modify book's name
void BookShop::modify_book(){
    cout << "\n Book's Number" << book_number << endl;;
    cout << "\nEnter Modify Book Name: ";
    cin.ignore();
    cin.getline(book_name, 50);
    cout << "\nModify Author Name: ";
    cin.ignore();
    cin.getline(author_name, 50);
    fflush(stdin);
    cout<<"\nEnter No. Of Copies : ";
    cin>>nums_copies;
}


//MARK: - Function to get book details
void BookShop::get_book_details(){
    cout << "ENTER DETAIL ABOUT BOOK YOU WANT TO PURCHASE" << endl;
    cout << "ENTER BOOK NUMBER";
    cin >> book_number;
    cout << "ENTER THE NAME OF THE BOOK" << endl;
    cin >> book_name;
    cout << "ENTER THE AUTHOR'S NAME" << endl;
    cin.ignore();
    cin.getline(author_name,50);
    fflush(stdin);
    cout<<"\nEnter No. Of Copies : ";
    cin>>nums_copies;
}


void BookShop::report(){
    cout<<book_number<<setw(30)<<book_name<<setw(30)<<author_name<<setw(30)<<nums_copies<<endl;
}

