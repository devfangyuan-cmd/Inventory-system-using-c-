#include <iostream>
#include <string>
using namespace std;

const int MAX_ITEMS = 50; //Maximum amount of stored items is 50

// Functions Declaration
void showMenu();
void addItem(string itemNames[], int itemQty[], int &itemCount);
void removeItem(string itemNames[], int itemQty[], int itemCount);
void checkInventory(string itemNames[], int itemQty[], int itemCount);
void showSummary(string itemNames[], int itemQty[], int itemCount);

int main() {
    string itemNames[MAX_ITEMS];
    int itemQty[MAX_ITEMS] = {0};
    int itemCount = 0;
    int choice;

    do { //Menu
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addItem(itemNames, itemQty, itemCount);
                break;

            case 2:
                removeItem(itemNames, itemQty, itemCount);
                break;

            case 3:
                checkInventory(itemNames, itemQty, itemCount);
                break;

            case 4:
                showSummary(itemNames, itemQty, itemCount);
                break;

            case 5:
                cout << "Thank you for using the inventory system!" << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 5);

    return 0;
}

// =====Functions Definitions=====

//Menu
void showMenu() {
    cout << "\n===== INVENTORY MENU =====" << endl;
    cout << "1. Add Item" << endl;
    cout << "2. Remove Item" << endl;
    cout << "3. Check Inventory" << endl;
    cout << "4. Show Summary" << endl;
    cout << "5. Exit" << endl;
}

//Function that add items
void addItem(string itemNames[], int itemQty[], int &itemCount) {
    string name;
    int amount;
    bool found = false;

    cout << "Enter item name: ";
    getline(cin, name);
    cout << "Enter quantity to add: ";
    cin >> amount;
    cin.ignore();

    if (amount <= 0) {
        cout << "Invalid amount!" << endl;
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        if (itemNames[i] == name) {
            itemQty[i] += amount;
            found = true;
            break;
        }
    }

    if (!found && itemCount < MAX_ITEMS) {
        itemNames[itemCount] = name;
        itemQty[itemCount] = amount;
        itemCount++;
    }

    cout << "Added " << amount << " " << name << "s successfully!" << endl;
}

//Function that remove items
void removeItem(string itemNames[], int itemQty[], int itemCount) {
    string name;
    int amount;
    bool found = false;

    if (itemCount == 0) {
        cout << "Inventory is empty!" << endl;
        return;
    }

    cout << "Enter item name to remove: ";
    getline(cin, name);
    cout << "Enter quantity to remove: ";
    cin >> amount;
    cin.ignore();

    for (int i = 0; i < itemCount; i++) {
        if (itemNames[i] == name) {
            found = true;
            if (amount > 0 && amount <= itemQty[i]) {
                itemQty[i] -= amount;
                cout << "Removed " << amount << " " << name << "s." << endl;
            } else {
                cout << "Invalid amount or not enough stock!" << endl;
            }
            break;
        }
    }

    if (!found) {
        cout << "Item not found in inventory!" << endl;
    }
}

//Function what is inside the inventory
void checkInventory(string itemNames[], int itemQty[], int itemCount) {
    if (itemCount == 0) {
        cout << "Inventory is empty!" << endl;
        return;
    }

    cout << "\n===== CURRENT INVENTORY =====" << endl;
    for (int i = 0; i < itemCount; i++) {
        cout << i + 1 << ". " << itemNames[i] << " - " << itemQty[i] << endl;
    }
}

//The sum of items inside inventory
void showSummary(string itemNames[], int itemQty[], int itemCount) {
    if (itemCount == 0) {
        cout << "No items in inventory yet!" << endl;
        return;
    }

    cout << "\n===== INVENTORY SUMMARY =====" << endl;
    int totalItems = 0;
    for (int i = 0; i < itemCount; i++) {
        cout << "- " << itemNames[i] << ": " << itemQty[i] << endl;
        totalItems += itemQty[i];
    }
    cout << "-----------------------------" << endl;
    cout << "Total items in inventory: " << totalItems << endl;
}
