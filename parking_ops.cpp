#include "parking_ops.h"
#include <iostream>
using namespace std;

static double calculateCharge(double hours, double ratePerHour) {
    return hours * ratePerHour;
}

void parkVehicle(vector<Slot> &slots) {
    if (slots.empty()) {
        cout << "No slots available. Please add slots first.\n";
        return;
    }

    // Show free slots
    bool anyFree = false;
    cout << "\nFree Slots:\n";
    for (const auto &s : slots) {
        if (!s.isOccupied) {
            cout << "Slot ID: " << s.id << " (Rate/hr: " << s.ratePerHour << ")\n";
            anyFree = true;
        }
    }

    if (!anyFree) {
        cout << "No free slots available.\n";
        return;
    }

    int slotId;
    cout << "\nEnter Slot ID to park vehicle: ";
    cin >> slotId;

    Slot *slot = findSlotById(slots, slotId);
    if (!slot) {
        cout << "Invalid Slot ID.\n";
        return;
    }

    if (slot->isOccupied) {
        cout << "This slot is already occupied.\n";
        return;
    }

    cout << "Enter Vehicle Number: ";
    string vno;
    cin >> vno;          // simple, no spaces

    slot->isOccupied = true;
    slot->vehicleNumber = vno;

    cout << "Vehicle parked successfully in Slot " << slot->id << ".\n";
}

void removeVehicle(vector<Slot> &slots) {
    if (slots.empty()) {
        cout << "No slots available.\n";
        return;
    }

    int slotId;
    cout << "\nEnter Slot ID to remove vehicle from: ";
    cin >> slotId;

    Slot *slot = findSlotById(slots, slotId);
    if (!slot) {
        cout << "Invalid Slot ID.\n";
        return;
    }

    if (!slot->isOccupied) {
        cout << "This slot is already empty.\n";
        return;
    }

    cout << "Vehicle in this slot: " << slot->vehicleNumber << "\n";
    double hours;
    cout << "Enter hours parked: ";
    cin >> hours;

    if (hours < 0) {
        cout << "Invalid hours.\n";
        return;
    }

    double charge = calculateCharge(hours, slot->ratePerHour);
    cout << "Parking charge = " << hours 
         << " * " << slot->ratePerHour 
         << " = " << charge << "\n";

    // Clear the slot
    slot->isOccupied = false;
    slot->vehicleNumber.clear();

    cout << "Vehicle removed. Slot is now free.\n";
}