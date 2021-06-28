#include"MenuCard.h"
Node *node=new Node(); //temporary object to call the member functions of 'Node' class

int main()
{
    int option1,option2; 

    while(1)
    {
        cout<<"\n ********** Welcome to Hotel ****************** \n";
        cout<<"\n        1:Administrator              ";
        cout<<"\n        2:Customer                   ";
        cout<<"\n        3:Quit                       \n";
        cout<<"\n ******************************************* \n";

        cout<<"\n Enter your option: ";
        cin>>option1;

        switch(option1)
        { 
            case 1:admin();break;
            case 2:customer();break;
            case 3:exit(1);
            default:
            {
                if(option1 != 1 && option1 != 2 && option1 !=3)
                {
                    cout<<"\n Invalid input !"<<endl;
                }
            }
        }

    }
    return 0;
}
void admin()
{
    int i = 0;
    char *password1 = new char[30];
    char *username1 = new char[30];
    char *username2 = new char[30];
    char *password2 = new char[30];
    strcpy(username1, "hotelname");
    strcpy(password1, "1234");
    cout << "\n Enter username: ";
    cin >> username2;
    cout << "\n Enter password: ";
    while (1)
    {
        *(password2 + i) = getch();
        if (*(password2 + i) == 13) //ASCII value of 'ENTER' key is '13'
        {
            *(password2 + i) = '\0';
            break;
        }
        i++;
    }
    if ((strcmp(username1, username2) == 0) && strcmp(password1, password2) == 0)
    {
        cout << "\n\n Authentication success \n";
        adminOperations();
    }
    else
    {
        cout << "\n\n Username or Password Incorrect \n";
    }
}
void adminOperations()
{
    int option;
    do
    {

        cout << "\n\n *********** Admin Operations ****************";
        cout << "\n\n       1:Insert an item ";
        cout << "\n       2:Delete an item ";
        cout << "\n       3:Display the menuCard";
        cout << "\n       4:Search an item ";
        cout << "\n       5:Modify an item price or name";
        cout << "\n       6:Find the item with maximum price ";
        cout << "\n       7:Find the item with minimum price ";
        cout << "\n       8:Quit";
        cout << "\n\n *********************************************";

        cout << "\n Enter your option:";
        cin >> option;

        switch (option)
        {
            case 1:
            {
                char *itemName=new char[30];
                float price;
                Node *tempNode = new Node();
                menucard *temp = new menucard();
                temp->MemoryAllocationForItemName();
                cout << "\n Enter the name of the item: ";
                cin >> itemName;
                temp->setItemName(itemName);
                cout << "\n Enter the price of the item: ";
                cin >> price;
                temp->setPrice(price);
                int res=node->InsertAnItem(tempNode,temp);
                if(res == 1)
                {
                    cout << endl
                        << "\n Item with name " <<itemName<< " with price " << price << " added successfully to the menucard " << endl;
                }
                else if(res == 2)
                {
                    cout << "\n\n Item with name " << itemName << " already exists in menucard !";
                }
                break;
            }
            case 2:
            {
                if(node->getRoot1() == NULL)
                {
                    cout<<"List is empty!"<<endl;
                }
                else
                {
                    char *itemname = new char[30];
                    cout << "\n Enter the name of the item to remove from menucard: ";
                    cin >> itemname;
                    int res=node->DeleteAnItem(itemname);
                    if(res == 1)
                    {
                        cout << "\n Item with name " << itemname << " removed from menucard";
                    }
                    else if(res == 2)
                    {
                        cout<<"\n There is no item named "<<itemname;
                    }
                }
                break;
            }
            case 3:
            {
                if (node->getRoot1() == NULL)
                {
                    cout << "\n menucard is empty!";
                }
                else
                {
                    cout << "\n************ Menu Card ************************* \n";
                    cout << "\n  Item Name                    Item Price \n";
                    node->DisplayTheMenu();
                    cout << "\n\n*************************************************";
                }
                break;
            }
            case 4:
            {
                if (node->getRoot1() == NULL)
                {
                    cout << "\n Menu card is empty !" << endl;
                }
                else
                {
                    char *itemname = (char *)calloc(30, sizeof(char));
                    cout << "\n Enter the item name to search: ";
                    cin >> itemname;
                    float z = node->SearchAnItem(itemname);
                    if (z == 0)
                    {
                        cout << "\n sorry! The menu doesn't contains the item with name " << itemname;
                    }
                }
                break;
            }
            case 5:
            {
                if(node->getRoot1() == NULL)
                {
                    cout<<"List is empty !"<<endl;
                }
                else
                {
                    char *itemname = new char[30];
                    cout << "\n Enter the name of the item you want to modify: ";
                    cin >> itemname;
                    int flag = 0;
                    int option;
                    Node *p = node->getRoot1();
                    while (p->getLink() != NULL)
                    {
                        if (strcmp(p->getData()->getItemName(), itemname) == 0)
                        {
                            flag = 1;
                            cout << "\n\n ******** Enter which field you want to modify *****\n";
                            cout << "\n                  1:Name of the item                         ";
                            cout << "\n                  2:Price of the item        ";
                            cout << "\n *******************************************************\n";
                            cout << "\n Enter your option :";
                            cin >> option;
                            switch (option)
                            {
                                case 1:
                                {
                                    char *tempName = new char[30];
                                    cout << "\n Enter name to modify: ";
                                    cin >> tempName;
                                    int res=node->ModifyAnItem(p,tempName,0);
                                    if(res == 1)
                                    {
                                        cout<<endl<<"     Item with old name ' "<<itemname<<" ' is modified by new name ' "<<tempName<<" ' successfully!"<<endl;
                                    }
                                    break;
                                }
                                case 2:
                                {
                                    float tempPrice;
                                    cout << "\n Enter price to modify: ";
                                    cin >> tempPrice;
                                    int res=node->ModifyAnItem(p,NULL,tempPrice);
                                    if(res == 2)
                                    {
                                        cout<<endl<<"    Item with old name ' "<<itemname<<" ' is modified by new price ' "<<tempPrice<<" ' successfully!"<<endl;
                                    }
                                    break;
                                }
                                default:
                                {
                                    cout << "\n Invalid Input ";
                                    break;
                                }
                                
                            }
                        }
                        p = p->getLink();
                    }
                    if (strcmp(p->getData()->getItemName(), itemname) == 0)
                    {
                        int option1;
                        flag = 1;
                        cout << "\n\n ******** Enter which field you want to modify *****\n";
                        cout << "\n                  1:Name of the item                         ";
                        cout << "\n                  2:Price of the item        \n";
                        cout << "\n *******************************************************\n";
                        cout << "\n Enter your option :";
                        cin >> option1;
                        switch (option1)
                        {
                            case 1:
                            {
                                char *tempName = new char[30];
                                cout << "\n Enter name to modify: ";
                                cin >> tempName;
                                int res=node->ModifyAnItem(p,tempName,0);
                                if(res == 1)
                                {
                                    cout<<endl<<"    Item with old name ' "<<itemname<<" ' is modified by new name ' "<<tempName<<" ' successfully!"<<endl;
                                }
                                break;
                            }
                            case 2:
                            {
                                float tempPrice;
                                cout << "\n Enter Price to modify: ";
                                cin >> tempPrice;
                                int res=node->ModifyAnItem(p,NULL,tempPrice);
                                if(res == 1)
                                {
                                    cout<<endl<<"   Item with old name ' "<<itemname<<" ' is modified by new price ' "<<tempPrice<<" ' successfully!"<<endl;
                                }
                                break;
                            }
                            default:
                            {
                                cout << "\n Invalid Input ";
                                break;
                            }
                            
                        }
                        
                    }  
                    if (flag == 0)
                    {
                        cout << "\n sorry! The menu doesn't contains the item with name " << itemname;
                    }
                }
                break;
            }
            case 6:
            {
                if(node->getRoot1() == NULL)
                {
                    cout<<"List is empty !"<<endl;
                }
                else
                {
                    Node *temp=node->FindMaxPriceItem();
                    cout << "\n The item with maximum price : " << endl;
                    node->DisplayOneItem(temp);
                }
                break;
            }
            case 7:
            {
                if(node->getRoot1() == NULL)
                {
                    cout<<"List is empty !"<<endl;
                }
                else
                {
                    Node *temp=node->FindMinPriceItem();
                    cout << "\n The item with minimum price : " << endl;
                    node->DisplayOneItem(temp);
                }
                break;
            }    
            default:
            {
                if (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6 && option != 7 && option != 8)
                {
                    cout << "\n Invalid input";
               }
            }
        }

    } while (option != 8);
}
void customer()
{
    int option;
    cout << "\n Note: Dear customer,Please check menucard before you start buying !";
    do
    {
        cout << "\n\n *********** Customer Operations ****************";
        cout << "\n\n       1:Buy an item ";
        cout << "\n       2:Remove an item ";
        cout << "\n       3:Display the Items choosed";
        cout << "\n       4:Search an item ";
        cout << "\n       5:Display the menucard";
        cout << "\n       6:Find the item with maximum price ";
        cout << "\n       7:Find the item with minimum price ";
        cout << "\n       8:Calculate Bill ";
        cout << "\n       9:Quit";
        cout << "\n\n  *********************************************";

        cout << "\n\n Enter your option:";
        cin >> option;

        switch (option)
        {
            case 1:
            {
                int option;
                if (node->getRoot1() == NULL)
                {
                    cout << "\n Sorry! Menu card is empty !";
                }
                else
                {
                    float Price,price;
                    char *name=new char[30];
                    menucard *temp = new menucard();
                    Node *tempNode = new Node();
                    temp->MemoryAllocationForItemName();
                    cout << "\n Enter the name of the item you want to buy: ";
                    cin >> name;
                    temp->setItemName(name);
                    Price = node->SearchAnItem(name);
                    temp->setPrice(Price);
                    if (Price != 0)
                    {
                        cout << "\n\n If you want to buy the above item displayed: ";
                        cout << "\n\n *********** Confirmation *********************";
                        cout << "\n\n               1:yes";
                        cout << "\n               2:No";
                        cout << "\n\n *********************************************";

                        cout << "\n\n Enter your option: ";
                        cin >> option;

                        switch (option)
                        {
                        case 1:
                        {
                            int res=node->BuyAnItem(tempNode,temp);
                            if(res == 1)
                            {
                                cout << "\n Item with name " << name<< " added successfully to your choosed list!";
                            }
                            break;
                        }
                        case 2:
                        {
                            cout << "\n Item with name " << name << " cancelled by you ";
                            break;
                        }
                        default:
                        {
                            if (option != 1 && option != 2)
                            {
                                cout << "Invalid input";
                            }
                        }
                        }
                    }
                    else
                    {
                        cout << "\n sorry! The menucard doesn't contains the item you have entered ";
                    }
                }
                break;
            }
            case 2:
            {
                if (node->getRoot2() == NULL)
                {
                    cout << "\n choosed list is empty!";
                }
                else
                {
                    char *itemname = new char[30];
                    cout << "\n Enter the name of the item to remove from choosed list: ";
                    cin >> itemname;
                    int res=node->RemoveAnItem(itemname);
                    if(res == 1)
                    {
                        cout << "\n Item with name " << itemname << " removed from choosed list ";
                    }
                    else if(res == 2)
                    {
                        cout<< "\n Item with name "<< itemname<<" doesn't exists in your choosed list!"<<endl;  
                    }
                }
                break;
            }
            case 3:
            {
                if (node->getRoot2() == NULL)
                {
                    cout << "\n choosed list is empty!";
                }
                else
                {
                    cout << "\n************ Menu Card ************************* \n";
                    cout << "\n  Item Name                    Item Price \n";
                    node->DisplayTheChoosedItems();
                    cout << "\n\n*************************************************";
                }
                break;
            }
            case 4:
            {
                if (node->getRoot1() == NULL)
                {
                    cout << "\n Menu card is empty !" << endl;
                }
                else
                {
                    char *itemname = (char *)calloc(30, sizeof(char));
                    cout << "\n Enter the item name to search: ";
                    cin >> itemname;
                    float z = node->SearchAnItem(itemname);
                    if (z == 0)
                    {
                        cout << "\n sorry! The menu doesn't contains the item with name " << itemname;
                    }
                } 
                break;   
            }
            case 5:
            {
                if (node->getRoot1() == NULL)
                {
                    cout << "\n menucard is empty!";
                }
                else
                {
                    cout << "\n************ Menu Card ************************* \n";
                    cout << "\n  Item Name                    Item Price \n";
                    node->DisplayTheMenu();
                    cout << "\n\n*************************************************";
                }
                break;
            }
            case 6:
            {
                if(node->getRoot1() == NULL)
                {
                    cout<<"List is empty !"<<endl;
                }
                else
                {
                    Node *temp=node->FindMaxPriceItem();
                    cout << "\n The item with maximum price : " << endl;
                    node->DisplayOneItem(temp);
                }
                break;

            }
            case 7:
            {
                if(node->getRoot1() == NULL)
                {
                    cout<<"List is empty !"<<endl;
                }
                else
                {
                    Node *temp=node->FindMinPriceItem();
                    cout << "\n The item with minimum price : " << endl;
                    node->DisplayOneItem(temp);
                }
                break;
            }
            case 8:
            {
                if(node->getRoot2() == NULL)
                {
                    cout<<endl<<"  choosedList is empty!"<<endl;
                }
                else
                {
                    float res,finalAmount1,finalAmount2;
                    res=node->calculateBill();
                    cout << "\n *********************** BILL ******************************";
                    cout << "\n\n               Total price = " << res;
                    finalAmount1 = ((15.0 * 100.0) / res);
                    finalAmount2 = res- finalAmount1;
                    cout << "\n\n     Total amount with 15 percentage discount = " << finalAmount2 << endl;
                    cout << "\n ************************************************************";   
                }
                break;
            }
            default:
            {
                if (option != 1 && option != 2 && option != 3 && option != 4 && option != 5 && option != 6 && option != 7 && option != 8 && option != 9)
                {
                    cout << "\n Invalid input";
                }
            }
        }

    } while (option != 9);
}