#include <algorithm>
#include <ios>
#include <iostream>
#include <optional>
#include <vector>

constexpr auto MAX_ITEMS      = 30;
constexpr auto MAX_MODEL_NAME = 60;        

enum class Product
{
        Invalid = -1,
        Milk,
        Cheese,
        Yoghurt,
        Butter,
        Icecream,
        Cream,
        Custard,
        Count
};

/// @brief Holds the names of the product categories.
constexpr std::string_view PRODUCT_NAMES[static_cast<int>(Product::Count)] = {
    [static_cast<int>(Product::Milk)] = "Milk",         
    [static_cast<int>(Product::Cheese)] = "Cheese",
    [static_cast<int>(Product::Yoghurt)] = "Yoghurt",  
     [static_cast<int>(Product::Butter)] = "Butter",
    [static_cast<int>(Product::Icecream)] = "Icecream", 
    [static_cast<int>(Product::Cream)] = "Cream",
    [static_cast<int>(Product::Custard)] = "Custard",

};

/// @brief Checks if the given product is valid.
constexpr auto is_valid_product(Product prod) { return prod > Product::Invalid && prod < Product::Count; }

/// @brief Return the name of the given product.
constexpr auto get_product_name(Product prod)
{
        if (!is_valid_product(prod)) { return std::string_view {""}; }

        return PRODUCT_NAMES[static_cast<int>(prod)];
}

/// @brief Prints a list of all the product categories available.
auto list_products()
{
        std::cout << "Product list: \n";
        std::for_each_n(std::begin(PRODUCT_NAMES), std::size(PRODUCT_NAMES), [i = 0](const auto& name) mutable {
                std::printf("(%d) %s\n", i, name.data());
                i++;
        });
        std::printf("---------------\n");
}

/// Represents a stocked item corresponding to one of the listed product categories.
struct Item
{
        Product     id;           
        std::string name;        
        float       price;        
        std::string BBD;
        int         nstock;      
        Item() = default;

        Item(const Product prod, const std::string& name, const float price, const std::string& BBD, const int nstock) :
                id {prod}, name {name}, price {price}, BBD {BBD}, nstock {nstock}
        {}

        auto print() const { std::printf("%32s%60s%15f%11s%8d\n", get_product_name(id).data(), name.c_str(), price, BBD.c_str(), nstock); }
};

/// Holds the inventory of all the stocked items in the store.
struct Inventory
{
        using SearchPredicate = std::function<bool(const Item&)>;
        using Items           = std::vector<Item>;
        using ItemPtr         = Items::iterator;        

        Items items;

        Inventory() { items.reserve(MAX_ITEMS); }

        /// @brief Adds the given item to the inventory.
        auto add(const Item& item) { items.emplace_back(item); }

        /// @brief Deletes the given item from the inventory.
        auto remove(ItemPtr pitem) { items.erase(pitem); }

        /// @brief Look for the item for which the given predicate returns true.
        ///
        /// @returns nullptr if item is not found else pointer to item.
        auto search(const SearchPredicate& pred) -> ItemPtr
        {
                auto pitem = std::find_if(items.begin(), items.end(), pred);
                if (pitem != items.end()) { return pitem; }

                return {};
        }

        /// @brief Prints a table listing currently stocked items in the inventory.
        auto list()
        {
                std::printf("%32s%60s%15s%11s%8s\n", "Product", "Product Name", "Price (GBP)","BBD", "Qty.");
                std::for_each(items.begin(), items.end(), [](const auto& item) { item.print(); });
                std::printf("---------------\n");
        }
};

struct InventoryUI
{
        enum class Option
        {
                Invalid      = -1,
                AddItem      = 'a',
                RemoveItem   = 'r',
                EditItem     = 'e',
                SearchItem   = 's',
                ListProducts = 'p',
                ListItems    = 'l',
                Quit         = 'q',
        };

        Inventory inventory;

        auto      user_input_handler() {}

        auto      list_options()
        {
                std::printf("(%c) Add Item\n", static_cast<char>(Option::AddItem));
                std::printf("(%c) Search Item\n", static_cast<char>(Option::SearchItem));
                std::printf("(%c) List Product Categories\n", static_cast<char>(Option::ListProducts));
                std::printf("(%c) List Items in Stock\n", static_cast<char>(Option::ListItems));
                std::printf("(%c) Quit\n", static_cast<char>(Option::Quit));
        }

        auto get_user_action()
        {
                char opt {};
                std::printf("Select operation: ");
                std::scanf(" %c", &opt);
                std::printf("---------------\n");
                return opt;
        }

        /// @brief Adds item to the inventory.
        auto handle_add_option()
        {
                Item item;
                do {
                        list_products();

                        std::printf("Select product category to add: ");
                        int pid {};
                        std::scanf("%d", &item.id);

                        if (!is_valid_product(item.id)) { std::printf("Invalid option selected. Please try again.\n"); }
                        else
                        {
                                
                                std::printf("Enter product name: ");
                                std::getline(std::cin >> std::ws, item.name);

                                std::printf("Enter price: ");
                                std::cin >> item.price;

                                std::printf("Enter BBD: ");
                                std::cin >> item.BBD;

                                std::printf("Enter quantity: ");
                                std::cin >> item.nstock;

                                return item;
                        }

                } while (true);
        }

        /// @brief Search item by name or product category to perform remove or edit operations on the found item.
        auto handle_search_option()
        {
                char opt {};
                std::printf("Search by (n) Name, (p) Product Category: ");
                std::cin >> opt;

                Inventory::ItemPtr pitem;

                if (opt == 'n')
                {
                        std::string name {};
                        std::printf("Enter product name: ");
                        std::getline(std::cin >> std::ws, name);
                        pitem = inventory.search([&](const Item& item) { return item.name == name; });
                }
                else if (opt == 'p')
                {
                        Product prod {Product::Invalid};
                        list_products();
                        std::printf("Select product id: ");
                        std::scanf("%d", &prod);
                        std::printf("Selected product category: %s\n", get_product_name(prod).data());

                        pitem = inventory.search([&](const Item& item) { return item.id == prod; });
                }
                else
                {
                        std::printf("Invalid option selected. Please try again.\n");
                        return;
                }

                if (pitem != Inventory::ItemPtr {})
                {
                        
                        do {
                                pitem->print();
                                std::printf("---------------\n");

                                std::printf("(%c) Remove Item\n", static_cast<char>(Option::RemoveItem));
                                std::printf("(%c) Edit Item\n", static_cast<char>(Option::EditItem));
                                std::printf("(%c) Quit\n", static_cast<char>(Option::Quit));
                                const auto opt = get_user_action();

                                if (opt == static_cast<char>(Option::RemoveItem))
                                {
                                        inventory.remove(pitem);
                                        break;
                                }
                                else if (opt == static_cast<char>(Option::EditItem))
                                {
                                       
                                        const auto new_item = handle_add_option();
                                        inventory.remove(pitem);
                                        inventory.add(new_item);
                                        break;
                                }
                                else if (opt == static_cast<char>(Option::Quit)) { break; }
                                else { std::printf("Invalid option selected. Please try again.\n"); }
                        } while (true);
                }
                else { std::printf("Item not found. Try adding an item.\n"); }
        }

        auto run()
        {
                std::printf("Shop Inventory v0.1\n");

                do {
                        list_options();
                        const auto opt = get_user_action();
                        if (opt == static_cast<char>(Option::AddItem))
                        {
                                const auto item = handle_add_option();
                                inventory.add(item);
                                std::printf("Added item\n\n");
                        }
                        else if (opt == static_cast<char>(Option::SearchItem)) { handle_search_option(); }
                        else if (opt == static_cast<char>(Option::ListProducts)) { list_products(); }
                        else if (opt == static_cast<char>(Option::ListItems)) { inventory.list(); }
                        else if (opt == static_cast<char>(Option::Quit)) { break; }
                        else { std::printf("Invalid option selected. Please try again.\n"); }
                } while (true);
        }
};

auto main() -> int
{
        InventoryUI ui {};

        ui.run();
}
