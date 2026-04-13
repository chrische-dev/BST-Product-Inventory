#include "bst.h"

binary_tree::binary_tree()
{
    root = nullptr;
}

binary_tree::~binary_tree()
{
    destructor();

}

int binary_tree::destructor()
{
    if(!root)
        return 0;

    return destructor(root);
}

int binary_tree::destructor(product_node *& root)
{
    if(!root)
        return 0;

    destructor(root->left);

    destructor(root->right);

    delete root;

    root = nullptr;

    return 1;
}



int binary_tree::insert(product & full_product)
{

    return insert(root, full_product);
}

int binary_tree::insert(product_node *& root, product & full_product)
{
    if(!root)
    {
        root = new product_node;        //you don't need this in the wrapper because this stopping condition stops if root is nullptr
        root->data.copy(full_product);  // copy the data using root->data.copy because data has access to what copy is accesing
        root->left = nullptr;
        root->right = nullptr;
        return 1;
    }
    
    int num = root->data.compare(full_product); //compare function gets called by root->data because compare needs data's members

    if(num < 1) //if function returns a 0 then that means that data being inserted is smaller than roots data
    {
        return insert(root->left, full_product); //go left if data being inserted is smaller than roots data
    }

    else
    {
        return insert(root->right, full_product); //otherwise if the data is larger than roots data traverse right
    }

}

int binary_tree::display()
{
    if(!root)       //nothing to display
        return 0;

    return display(root); //call the recursive function
}

int binary_tree::display(product_node * root)
{
    if(!root)
        return 0;

    //left, root , right
    display(root->left); // traverse left 
    root->data.display(); //you don't need to pass in full_product because your display function already has access to it since it's in the product class
    display(root->right); //traverse right

    return 1;
}

int binary_tree::remove(product & empty_product, char item_buffer[])
{
    if(!root)
        return 0;
        
    return remove(root, empty_product, item_buffer);
}


int binary_tree::remove(product_node *& root, product & empty_product, char item_buffer[])
{
    //in main ask them for the title they want to delete
    if(!root) //match not found 
        return 0;

    int num = root->data.compare_retrieve(item_buffer);

    if(num == 1)// Base Case
    {
        if(root->left == nullptr && root->right == nullptr)
        {
            delete root;
            root = nullptr;
            return 1;
        }

        if(root->left != nullptr && root->right == nullptr)//One has data the other is nullptr, do this twice 
        {
            product_node * hold = root->left;
            delete root;
            root = hold;
            return 1;
        }
        if(root->right != nullptr && root->left == nullptr)
        {
            product_node * hold = root->right;
            delete root;
            root = hold;
            return 1;
        }
        else
        {
            ios(empty_product, root->right);
            root->data.copy(empty_product);
            return 1;
        }
            
    }

    if(num < 1)
    {
        remove(root->left, empty_product, item_buffer);
    }

    else if(num == 2)
    {
        remove(root->right, empty_product, item_buffer);
    }

    
    return 1;
    
}

int binary_tree::ios(product & empty_product, product_node *& root)
{
    if(root->left == nullptr)
    {
        product_node * hold = root->right;
        empty_product.copy(root->data);
        delete root;
        root = hold;
        return 1;
    }
    return ios(empty_product, root->left);
}

int binary_tree::retrieve(product & to_fill, char item_buffer[])
{
    if(!root)
        return 0;

        return retrieve(root, to_fill, item_buffer);
}

int binary_tree::retrieve(product_node * root, product & to_fill, char item_buffer[])
{
    if(!root)
        return 0;

    
    int num = root->data.compare_retrieve(item_buffer);

    if(num == 2)
    {
        to_fill.copy(root->data); //to fill is a empty class but has access to functions so it can pass in data to the copy func
        
        return 1;
    }

    retrieve(root->left, to_fill, item_buffer);

    return retrieve(root->right, to_fill, item_buffer);
}


int binary_tree::display_price(int price_low, int price_high)
{
    if(!root)
        return 0;

        return display_price(root, price_low, price_high);
}

int binary_tree::display_price(product_node * root, int price_low, int price_high)
{
    if(!root)
        return 0;

    int num = root->data.compare_price(price_low, price_high); //passes in the users 2 price ranges to compare to roots price

    if(num == 1)
    {
        root->data.display(); //displays if roots data is in the price range
    }

    display_price(root->left, price_low, price_high);

    return display_price(root->right, price_low, price_high);
}


int binary_tree::height()
{
    if(!root)
        return 0;

        return height(root) - 1; //height is the amount of edges not the nodes
}

int binary_tree::height(product_node * root)
{
    if(!root) 
        return 0;

    int left_height = height(root->left) + 1;

    int right_height = height(root->right) + 1;

    if(left_height > right_height)
    {
        return left_height;
    }
    else
    {
        return right_height;
    }
}












