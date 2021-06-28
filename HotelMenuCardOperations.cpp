#include "MenuCard.h"

Node::Node()
{
    this->root1=NULL;
    this->root2=NULL;
}
Node* Node::getRoot1()
{
    return (this->root1);
}
Node* Node::getRoot2()
{
    return (this->root2);
}
void menucard::setItemName(char *itemName)
{
    this->itemName=itemName;
}
void menucard::setPrice(float price)
{
    this->price=price;
}
char* menucard::getItemName()
{
    return (this->itemName);
}
float menucard::getPrice()
{
    return (this->price);
}
void menucard::MemoryAllocationForItemName()
{
    itemName=new char[30];
}
Node* Node::getLink()
{
    return (this->link);
}
menucard* Node::getData()
{
    return (this->data);
}


int Node::InsertAnItem(Node *tempNode,menucard *temp)
{
    tempNode->data=temp;
    tempNode->link=NULL;
    if (this->root1 == NULL)
    {
        this->root1 = tempNode;
        return 1;
    }
    else
    {
        float z = SearchAnItem(tempNode->data->getItemName());
        if (z)
        {
            return 2;
        }
        else
        {
            Node *p = this->root1;
            while (p->link != NULL)
            {
                p = p->link;
            }
            p->link = tempNode;
            return 1;
        }
    }
}
void Node::DisplayTheMenu()
{
    Node *p = this->root1;
    while (p->link != NULL)
    {
        DisplayOneItem(p);
        p = p->link;
    }
    DisplayOneItem(p);
}
void Node::DisplayOneItem(Node *p)
{
    cout<<"\n   "<< p->data->getItemName()<<"                          " << p->data->getPrice();
}
int Node::DeleteAnItem(char *itemname)
{
    Node *p = this->root1;
    Node *parent = NULL;
    Node *temp1 = NULL;
    int flag = 0;

        
    if ((root1->link == NULL) && (strcmp(root1->data->getItemName(), itemname) == 0)) //when list is having only one item and if key element is first element
    {
        this->root1 = NULL;
        return 1;
    }
    else if ((root1->link != NULL) && (strcmp(root1->data->getItemName(), itemname) == 0))
    {
        this->root1 = this->root1->link;
        return 1;
    }
    else
    {
        while (p->link != NULL)
        {
            if (strcmp(p->data->getItemName(), itemname) == 0)
            {
                flag = 1;
                temp1 = p->link;
                parent->link = temp1;
                break;
            }
            parent = p;
            p = p->link;
        }
        if (strcmp(p->data->getItemName(), itemname) == 0 && flag != 1)
        {
            flag = 1;
            parent->link = NULL;
        }
        if (flag == 0)
        {
            return 2;
        }
        if (flag != 0)
        {
            return 1;
        }
    }
}
float Node::SearchAnItem(char *itemname)
{
    int flag = 0;
    Node *p = this->root1;
    while (p->link != NULL)
    {
        if (strcmp(itemname, p->data->getItemName()) == 0)
        {
            flag = 2;
            DisplayOneItem(p);
            break;
        }
        p = p->link;
    }
    if (flag == 2)
    {
        return (p->data->getPrice());
    }
    if (strcmp(p->data->getItemName(), itemname) == 0)
    {
        flag = 1;
        DisplayOneItem(p);
        return (p->data->getPrice());
    }
    if (flag == 0)
    {
        return 0;
    }
}
int Node::ModifyAnItem(Node *p,char *name,int price)
{
    if(price == 0)
    {
        p->data->setItemName(name);
        return 1;
    }
    else
    {
        p->data->setPrice(price);
        return 2;
    }   
}
int Node::BuyAnItem(Node *tempNode,menucard *temp)
{
    tempNode->data = temp;
    tempNode->link = NULL;
    if (this->root2 == NULL)
    {
        this->root2 = tempNode;
        return 1;
    }
    else
    {
        Node *p = this->root2;
        while (p->link != NULL)
        {
            p = p->link;
        }
        p->link = tempNode;
        return 1;
    }
}
int Node::RemoveAnItem(char *itemname)
{
    Node *p = this->root2;
    Node *parent;
    Node *temp1;
    int flag=0;
    if (this->root2->link == NULL && strcmp(this->root2->data->getItemName(), itemname) == 0)
    {
        flag=1;
        this->root2 = NULL;
        return 1;
    }
    else if ((this->root2->link != NULL) && (strcmp(this->root2->data->getItemName(), itemname) == 0))
    {
        flag=1;
        this->root2 = this->root2->link;
        return 1;
    }
    else
    {
        while (p->link != NULL)
        {
            if (strcmp(p->data->getItemName(), itemname) == 0)
            {
                flag=1;
                temp1 = p->link;
                parent->link = temp1;
                break;
            }
            parent = p;
            p = p->link;
        }
        if(flag == 0)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
}
void Node::DisplayTheChoosedItems()
{
    
    Node *p = this->root2;
    while (p->link != NULL)
    {
        DisplayOneItem(p);
        p = p->link;
    }
    DisplayOneItem(p);
}
float Node::calculateBill()
{

    float sum = 0, finalAmount1, finalAmount2;
    Node *p = this->root2;
    while (p->link != NULL)
    {
        sum = sum + (p->data->getPrice());
        p = p->link;
    }
    sum = sum + (p->data->getPrice());
    return sum;
}
Node* Node::FindMaxPriceItem()
{
    Node *p = this->root1;
    Node *temp;
    int i = 1;
    float max = 0;
    while (p->link != NULL)
    {
        if ((p->data->getPrice()) > (max))
        {
            max = (p->data->getPrice());
            temp = p;
        }
        p = p->link;
    }
    if ((p->data->getPrice()) > (max))
    {
        max = p->data->getPrice();
        temp = p;
    }
    return (temp);
}
Node* Node::FindMinPriceItem()
{
    Node *p = this->root1;
    Node *temp = NULL;
    int i = 1;
    float min = p->data->getPrice();
    if (root1->link == NULL)
    {
       return (temp);
    }
    else
    {
        while (p->link != NULL)
        {
            if ((p->data->getPrice()) < (min))
            {
                min = p->data->getPrice();
                temp = p;
            }
            p = p->link;
        }
        if ((p->data->getPrice()) < min)
        {
            min = p->data->getPrice();
            temp = p;
        }
        if (temp == NULL)
        {
            return(this->root1);
        }
        else
        {
            return(temp);
        }
    }
}