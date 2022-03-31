#include <algorithm>
#include <array>
#include <cstdio>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

constexpr auto MAX_items= 30;


using namespace std;

        // std::vector<char> items;
        // items.reserve(30);

        enum class items : char

        {
               Invalid = -1,
               chocolate,
                pancakemix,
                milk,
                beer,
                keyholder,
                earphones,
                mug,
                cheese,
                yoghurt,
                battery,
                razor,
                Count 
        };




 struct Databaseitems;
// Properties
enum class itemsDescription 
{
       items name;
        std::string BBD;
        float  Price;
        std::string Type;
        
};

        

        int operation;
        cout << "1.Add item" << endl;
        cout << "2.Remove item" << endl;
        cout << "3.Edit Item" << endl;
        cout << "4.Search for an Item by Name" << endl;
        cout << "5.Exist Database" << endl;
}

// std::array<char, 30> items = { chocolate , pancakemix, milk, beer, keyholder, earphones, mug, burger, laptop, cheese, yoghurt, schoolbag, battery,
// razor, bleach, sanitarypad, bodyspray, cake, shoes, mouthwash, wristwatch, candy, tissue, hairbrush, ink, books, teabags, trashbags, mop, soap} ;

//    std::array<char, 4>
//  array[0] = Name;
// array [1] = BBD;

// items = {Name, BBD, Price, Type}

// vector<items> myitems = {chocolate, pancakemix, milk, beer, keyholder, earphones, mug, burger, laptop, cheese, yoghurt, schoolbag, battery, razor,
// bleach, sanitarypad, bodyspray, cake, shoes, mouthwash, wristwatch, candy, tissue, hairbrush, ink, books, teabags, trashbags, mop, soap}; cout <<
// "Initial vector size is " << myitems.size() << "\n" ; std::string newitem {};
//   std::cout << "Add item (item): " ;
//  std::getline( std::cin, newitem);
// std::string item{};

// while (true) {
// const auto space_pos = std::find(newitem.begin(), newitem.end(), ' ');
