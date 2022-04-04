#include <algorithm>
#include <array>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using std::cin;

constexpr auto nl        = '\n';
constexpr auto Max_Items = 30;

enum class databaseitems: char

{
        Invalid = -1,
        Chocolate,
        Pancakemix,
        Milk,
        Beer,
        Keyholder,
        Earphones,
        Fruit,
        Cheese,
        Yoghurt,
        Battery,
        Count
};


 using namespace std;
 void input();
 void remove();
 void edit();
 void searchitem();
 void exit();
 void display();

int main()
{
        int operation;
        std::cout << "1.Add Item" << nl;
        std::cout << "2.Remove Item" << nl;
        std::cout << "3.Edit Item" << nl;
        std::cout << "4.Search for an Item by Name" << nl;
        std::cout << "5.Exist Database" << nl;
        std::cin >> operation;
        switch (operation)
        {
                case 1:
                Add:
                        break;
                case 2:
                Remove:
                        break;
                case 3:
                Edit:
                        break;
                case 4:
                Search:
                        break;
                case 5:
                Exit:
                        break;
                        std::cin;
        }

        struct Item;
        {
                std::string Item ;
                std::string BBD;
                float       Price;
                std::string Type;

                std::ofstream newitem("newitem.txt",std::ios::app);
                std::cout << "Enter newitem" << nl;
                std::cin >> Item;
               
               std::cout<< "Enter newitem BBD" << nl;
               std::cin >> BBD;

               std::cout << "Enter newitem price" << nl;
               std::cin >> Price;

               std::cout << "Enter newitem Type" << nl;
               std::cin >> Type;
               
               newitem << Item << ' ' << BBD << ' ' << Price << ' ' << Type << ' '<< nl;

               newitem.close();

        }
        main();
        void remove();
        { std::vector<char> Items;
            Items.erase(std::remove(Items.begin(), Items.end(), 5), Items.end());
            

        }
        main();

           void searchitem();
           {
                   std::ifstream items("newitem.txt");
                   std::string Item;
                   std::string str;
                   std::string BBD;
                   float Price;
                   std::string Type;

                   system ("cls");
                   std::cout << "Enter Item:" ;
                   std::cin >> str;
                   
                   while (items >> Item >> BBD >> Price >> Type) {
                           if (str == Item)
                           {
                                   system ("cls");
                                   std::cout << "Item Name found" << nl;
                                   std::cout << "Item" << ' ' << "BBD" << ' ' << "Price" << ' ' << "Type" << ' ' <<nl;
                                   std::cout << "-----------------" << nl;
                                   std::cout << Item << ' ' << BBD << ' ' << Price << ' ' << Type << ' ' << nl;
                                

                           }
                           if (! (str == Item)) {
                                   system ("cls");
                                   std::cout << "No Items Found" << nl;
                           }


                   }
                   system ("pause");
                   std::cin.get ();
                   main ();



           }
           void Exit();
           {

           
                   system("cls");
                   system("pause");
                   std::cin.get ();


           }

           
}

        

      