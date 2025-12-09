#include "slot.h"
#include <iostream>
using namespace std;

void addSlot(vector<Slot> &slots) {
    Slot s;
    cout << "\nEnter Slot ID (number): ";
    cin >> s.id;

    // Check duplicate ID
    for (const auto &slot : slots) {
        if (slot.id == s.id) {
            cout << "Slot with this ID already exists!\n";
            return;
        }
    }

    cout << "Enter rate per hour for this slot: ";
    cin >> s.ratePerHour;

    s.isOccupied = false;
    s.vehicleNumber = "";

    slots.push_back(s);
    cout << "Slot added successfully!\n";
}

void listSlots(const vector<Slot> &slots) {
    if (slots.empty()) {
        cout << "\nNo slots available.\n";
        return;
    }

    cout << "\n---- Parking Slots ----\n";
    for (const auto &s : slots) {
        cout << "Slot ID: " << s.id
             << ", Rate/hr: " << s.ratePerHour
             << ", Status: " << (s.isOccupied ? "Occupied" : "Free");
        if (s.isOccupied) {
            cout << ", Vehicle: " << s.vehicleNumber;
        }
        cout << "\n";
    }
}

Slot* findSlotById(vector<Slot> &slots, int slotId) {
    for (auto &s : slots) {
        if (s.id == slotId) return &s;
    }
    return nullptr;
}