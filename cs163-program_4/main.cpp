#include <fstream>
#include <iostream>
#include <cstring>
#include "bst.h"
#include "product.h"
using namespace std;


int main()
{
    binary_tree obj;

    int choice = 0;
    char item_buffer[MAX]; //dummy arrays to get user input and send it to a function in my class
    char description_buffer[MAX]; // have to use dummy arrays because the data memebers
                                  //are in a class and main does not have acess to them
    char category_buffer[MAX];
    char type_buffer[MAX];
    int price_buffer = 0;
    char quantity_buffer[MAX];
    char seller_id_buffer[MAX];
    char shop_name_buffer[MAX];


        do
        {
        menu(choice);
            if(choice == 1) //allow user to insert data into text file
            {

                cout << "What is the name of the item:" << endl;
                cin.get(item_buffer, MAX, '\n');
                cin.ignore(MAX,'\n');

                cout << "What is the description of the item:" <<endl;
                cin.get(description_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                cout << "What is the category:" << endl;
                cin.get(category_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                cout << "What is the type:" <<endl;
                cin.get(type_buffer, MAX ,'\n');
                cin.ignore(MAX, '\n');

                cout << "What is the price:" <<endl;
                cin >> price_buffer;
                cin.ignore(MAX, '\n');

                cout << "What is the qauntity:" <<endl;
                cin.get(quantity_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                cout << "What is the seller:" << endl;
                cin.get(seller_id_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                cout << "What is the shops name:" <<endl;
                cin.get(shop_name_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                product full_product(item_buffer, description_buffer,category_buffer, type_buffer, price_buffer, quantity_buffer, seller_id_buffer, shop_name_buffer);                //product full_product is the constructor with arguments so im calling it to create space for the private data members

                obj.insert(full_product);
            }

            if(choice == 2)
            {
                obj.display();
            }

            if(choice == 3)
            {
                cout << "What is the item's name you want to search for:" <<endl;
                cin.get(item_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                product to_fill;

                obj.retrieve(to_fill, item_buffer);


            }
            if(choice == 4)
            {
                cout << "What is the item's name that you want to remove?" <<endl;
                cin.get(item_buffer, MAX, '\n');
                cin.ignore(MAX, '\n');

                product empty_product;

                obj.remove(empty_product, item_buffer);

            }

            if(choice == 5)
            {

                int price_low = 0;
                int price_high = 0;

                cout << "What is the low price range you want to add" <<endl;
                cin >> price_low;
                cin.ignore(MAX, '\n');

                cout << "What is the max price range you want to add" <<endl;
                cin >> price_high;
                cin.ignore(MAX, '\n');

                obj.display_price(price_low, price_high);


            }

            if(choice == 6)
            {
                int height = obj.height();
                cout << height << endl;

            }
        } while(choice != 7);



        return 0;

}


