#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class item {
public:
    string name;
    int quantity;

    void saveToFile() {
        if (out.is_open()) {
            outFile << name << "," << quantity;
            outFile.close();
            cout << "Succesfully saved to items.txt" << endl;
        }
        else {
            cout << "Error, Unable to open" << endl;

        }
    }


    void loadFromFile() {
        ifstream inFile("items.txt");
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {

                size_t commaPos = line.find(',');
                if (commaPos != string::npos) {

                    string loadedName = line.substr(0, commaPos);
                    int loadedQuantity = stoi(line.substr(commaPos + 1));


                    cout << "Loaded from file - Name: " << loadedName
                        << ", Quantity: " << loadedQuantity << endl;
                }
            }
            inFile.close();
        }
        else {
            cout << "Error: Unable to open file for reading." << endl;
        }
    }
};

int main() {

    Item item;

    item.name = "Notebook";
    item.quantity = 8;

    item.saveToFile();

    item.loadFromFile();

    return 0;
}