#include "product.h"


struct product_node //node where we will store our data inside of
{
    product data;
    product_node * left;
    product_node * right;
};

class binary_tree
{
    public:
        binary_tree();
        ~binary_tree();
        int insert(product & full_product);
        int display();
        int remove(product & empty_product, char item_buffer[]);
        int retrieve(product & to_fill, char item_buffer[]);
        int display_price(int price_low, int price_high);
        int height();
        int destructor();


    private:
        product_node * root;
        int insert(product_node *& root, product & full_product);
        int display(product_node * root);
        int remove(product_node *& root, product & empty_product, char item_buffer[]);
        int retrieve(product_node * root, product & to_fill, char item_buffer[]);
        int display_price(product_node * root, int price_low, int price_high);
        int height(product_node * root);
        int destructor(product_node *& root);
        int ios(product & empty_product, product_node *& root);
};

