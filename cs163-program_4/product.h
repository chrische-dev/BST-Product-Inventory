//CS163, Program #4, chrische@pdx.edu
//purpose of this program is to store our data into a bst use recursive functions to access the data

#include <iostream>

#ifndef PRODUCT 
#define PRODUCT 


const int MAX = 100;


class product
{
    public:
        product();
        product(char item_buffer[], char description_buffer[]
                , char category_buffer[], char type_buffer[], 
                int price_buffer, char quantity_buffer[], 
                char seller_id_buffer[], char shop_name_buffer[]);
        ~product();
        int display();
        bool matches();
        int copy(product & full_product);
        int compare(product & full_product);
        int compare_retrieve(char item_buffer[]);
        int compare_price(int price_low, int price_high);

    private:
            char * item;
            char * description;
            char * category;
            char * type;
            int price;
            char * quantity;
            char * seller_id;
            char * shop_name;

};

int menu(int & choice);

#endif

