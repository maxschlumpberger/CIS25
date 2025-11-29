

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Item {
    string name;
    int id = 0;
};

Item* binarySearch(Item* inventory, int size, int selectedId) {
    int start = 0;
    int end = size - 1;
    
    while (start <= end) {
        int mid = (start + end) / 2;

        if (inventory[mid].id == selectedId) {
            return &inventory[mid];
        }
        else if (inventory[mid].id < selectedId) {
            start = mid + 1;

        }
        else {
            end = mid - 1;
        }
    }
    return nullptr;
}


int main()
{
    const int arr_size = 100;
    Item* inventory = new Item[arr_size];

    string sampleNames[] = {
        "almond", "anchovie", "antler", "apple", "apricot", "artichoke", "asparagus", "axe", "banana", "barley", "bark", "beans", "beet", "blackberry", "blueberry", "brazilnut", "broccoli", "broom", "brusselsprout", "buckwheat", "cabbage", "cantaloupe", "carrot", "cashew", "cauliflower", "celery", "cherry", "chestnut", "chickpeas", "chili", "coconut", "corn", "cranberry", "cucumber", "currant", "date", "dragonfruit", "eggplant", "fig", "garlic", "ginger", "grape", "grapefruit", "guava", "hazelnut", "honeydew", "kale", "kiwi", "leek", "lemon", "lentils", "lettuce", "lime", "lychee", "macadamia", "mandarin", "mango", "marker", "millet", "mulberry", "nectarine", "oats", "okra", "olive", "onion", "orange", "papaya", "parsnip", "passionfruit", "peach", "pear", "peas", "pecan", "pepper", "persimmon", "pineapple", "pistachio", "plum", "pomegranate", "potato", "pumpkin", "quinoa", "radish", "raspberry", "rhubarb", "rice", "rye", "seaweed", "shallot", "sorghum", "spelt", "spinach", "squash", "starfruit", "strawberry", "sunflowerseed", "sweetpotato", "tangerine", "tomato", "turmeric"

    };

    for (int i = 0; i < arr_size; i++) {
        inventory[i].id = 10 + i;
        inventory[i].name = sampleNames[i];
    }


    
    
    for (int i = 0; i < arr_size; i++) {
        cout << "ID: " << inventory[i].id << ", Name: " << inventory[i].name << endl;
    }

    int searchById;
    cout << "Please enter in the ID(10 - 109): ";
    cin >> searchById;

    Item* foundItem = binarySearch(inventory, arr_size, searchById);

    if (foundItem) {
        cout << "ID: " << foundItem->id << " - " << foundItem->name << endl;

    }
    else {
        cout << "Item not found. ";

    }

    



    delete[] inventory;
    return 0;
}
 
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
