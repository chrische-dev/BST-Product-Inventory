#include <iostream>
#include <cstring>

#include "product.h"
using namespace std;

product::product() //product constructor
{
    item = nullptr;
    description = nullptr;
    category = nullptr;
    type = nullptr;
    price = 0;
    quantity = nullptr;
    seller_id = nullptr;
    shop_name = nullptr;
}

product::product(char item_buffer[], char description_buffer[], char category_buffer[], char type_buffer[], int price_buffer, char quantity_buffer[], char seller_id_buffer[], char shop_name_buffer[])
{                                                           //constructor here creates space for private data members and strcpy from main

    item = new char[strlen(item_buffer)+1];
    strcpy(item,item_buffer);

    description = new char[strlen(description_buffer)+1];
    strcpy(description, description_buffer);

    category = new char[strlen(category_buffer)+1];
    strcpy(category, category_buffer);

    type = new char[strlen(type_buffer)+1];
    strcpy(type, type_buffer);

    price = price_buffer;

    quantity = new char[strlen(quantity_buffer)+1];
    strcpy(quantity,quantity_buffer);

    seller_id = new char[strlen(seller_id_buffer)+1];
    strcpy(seller_id, seller_id_buffer);

    shop_name = new char[strlen(shop_name_buffer)+1];
    strcpy(shop_name, shop_name_buffer);
}


product::~product() //product deconstructor
{

    if (item) delete [] item;
    if (description) delete [] description;
    if (category) delete [] category;
    if(type) delete [] type;
    if(price) price = 0;
    if (quantity) quantity = 0;
    if(seller_id) seller_id = 0;
    if(shop_name) delete [] shop_name;
}

int product::copy(product & full_product)
{
    // Delete any data members of Product (item, description, etc.) if they are present.
    if (item) delete [] item;
    if (description) delete [] description;
    if (category) delete [] category;
    if(type) delete [] type;
    if(price) price = 0;
    if (quantity) quantity = 0;
    if(seller_id) seller_id = 0;
    if(shop_name) delete [] shop_name;


    item = new char[strlen(full_product.item)+1];
    strcpy(item, full_product.item);

    description = new char[strlen(full_product.description)+1];
    strcpy(description, full_product.description);

    category = new char[strlen(full_product.category)+1];
    strcpy(category, full_product.category);

    type = new char[strlen(full_product.type)+1];
    strcpy(type, full_product.type);

    price = full_product.price;

    quantity = new char[strlen(full_product.quantity)+1];
    strcpy(quantity, full_product.quantity);

    seller_id = new char[strlen(full_product.seller_id)+1];
    strcpy(seller_id, full_product.seller_id);

    shop_name = new char[strlen(full_product.shop_name)+1];
    strcpy(shop_name, full_product.shop_name);


    return 1;   
}
int product::compare(product & full_product)
{             
    if(strcmp(item, full_product.item)<0) //title is where you are at in the tree,and full_product.title is the data you are inserting
    {
        return 1;
    }
    
    else
    {
        return 0;
    }

    if(strcmp(item, full_product.item) == 0)
    {
        return 3;
    }

}

int product::compare_retrieve(char item_buffer[]) //compares the item's name
{
    if(strcmp(item, item_buffer) == 0)
    {
        return 1;
    }
    
    if(strcmp(item, item_buffer)<0) //goes right because item is smaller than what u are looking for
    {
        return 2;
    }
    else
    {
        return 0;
    }
}

int product::compare_price(int price_low, int price_high) // compares the roots price to the price range from user
{
    if(price >= price_low && price <= price_high)
    {
        return 1;
    }

    return 0;
}



int product::display() //display function in my product class so it can access its data members inside of the class
{                       // then table can call this function because its public
    cout << item <<endl;
    cout << description << endl;
    cout << category << endl;
    cout << type << endl;
    cout << price <<endl;
    cout << quantity <<endl;
    cout << seller_id << endl;
    cout << shop_name << endl;
    return 1;

}

int menu(int & choice)
{
    cout << endl << "Menu" <<endl;
    cout << "1. insert new product" <<endl;
    cout << "2. display all" << endl;
    cout << "3. retrieve" << endl;
    cout << "4. remove a item" <<endl;
    cout << "5. display products in a range of price" <<endl;
    cout << "6. determine the height of the tree" <<endl;
    cout << "7. quit" <<endl;
    cout << "enter a number 1-7:";
    cin >> choice;
    cin.ignore(100, '\n');

    return 1;
}



