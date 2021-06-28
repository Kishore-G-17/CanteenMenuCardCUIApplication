/*                  Exercise -2                               */
/*  List ADT implementation using single linked list */
/*       Hotel menucard management */
/* In this application menu card is accessed by both customer and Admin.*/
/* so I am going to perform two types of operations */
/*         1.Admin Operations          */
/*         2.Customer Operations       */
/* For doing 'Admin operations'there must be some security system.so,I have added 'Authentication'
   fucntionality to do the 'Admin Operations'.
         Username:hotelname
         Password:1234    */


#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

using namespace std;

class menucard   //user-defined datatype 'menucard'
{
    private:
        char *itemName;
        float price;
    public:
        void setItemName(char*);
        void setPrice(float);
        char* getItemName();
        float getPrice();
        void MemoryAllocationForItemName();
};
class Node
{
    private:
        menucard *data;
        Node *link;
        Node *root1,*root2;
    public:
        Node();

        /* Admin operations */

        int InsertAnItem(Node*,menucard*);
        float SearchAnItem(char *);
        int ModifyAnItem(Node*,char *,int);
        int DeleteAnItem(char *);

        /* customer operations  */

        int BuyAnItem(Node*,menucard*);
        int RemoveAnItem(char*);
        float calculateBill();
        void DisplayTheChoosedItems();

        //Operations common to both admin and customer

        void DisplayTheMenu();              
        void DisplayOneItem(Node *);
        Node* FindMaxPriceItem();
        Node* FindMinPriceItem();

        //others

        Node* getLink();
        menucard* getData();
        Node* getRoot1();
        Node* getRoot2();


};
void admin();
void customer();
void adminOperations();