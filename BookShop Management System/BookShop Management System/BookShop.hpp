//
//  BookShop.hpp
//  BookShop Management System
//
//  Created by Tilak Shakya on 22/11/22.
//

#ifndef BookShop_hpp
#define BookShop_hpp
#include <iostream>
#include <stdio.h>

using namespace  std;

class BookShop {
private:
    char book_number[30];
    char book_name[50];
    char author_name[30];
    int nums_copies;
    
public:
    void show_all_book();
    void modify_book();
    void delete_book(string name);
    void get_book_details();
    void report();
    char* getbooknumber()
    {
        return book_number;
    }
};

#endif /* BookShop_hpp */
