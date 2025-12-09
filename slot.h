#ifndef SLOT_H
#define SLOT_H

#include <string>
#include <vector>
using namespace std;

struct Slot {
    int id;                // Slot number / ID
    bool isOccupied;       // true = vehicle parked
    string vehicleNumber;  // Vehicle number if occupied
    double ratePerHour;    // Parking rate
};

void addSlot(vector<Slot> &slots);
void listSlots(const vector<Slot> &slots);
Slot* findSlotById(vector<Slot> &slots, int slotId);

#endif