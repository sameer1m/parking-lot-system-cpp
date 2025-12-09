#include <iostream>
#include <vector>
#include "slot.h"
#include "parking_ops.h"
using namespace std;

int main() {
    vector<Slot> slots;

    int choice;
    while (true) {
        cout << "\n===== PARKING LOT SYSTEM =====\n";
        cout << "1. Add Parking Slot\n";
        cout << "2. View All Slots\n";
        cout << "3. Park Vehicle\n";
        cout << "4. Remove Vehicle (and calculate charge)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            addSlot(slots);
        } else if (choice == 2) {
            listSlots(slots);
        } else if (choice == 3) {
            parkVehicle(slots);
        } else if (choice == 4) {
            removeVehicle(slots);
        } else if (choice == 5) {
            cout << "Exiting...\n";
            break;
        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}