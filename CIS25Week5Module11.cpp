#include <iostream>
#include <string>
using namespace std;

class product {
public:
	int id;
	string name;
	double price;


	product(int productId, string productName, double productPrice) {
		id = productId;
		name = productName;
		price = productPrice;
		
	}

	~product() {
		cout << "Product destructed";

	}

	void printDetailes() {
		cout << " Product Details " << endl:
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Price: $" << price << endl;
	}
};

int main() {
	product myProduct(823, "Charger", 543.23);

	myProduct.printDetailes();

	return 0;
}
