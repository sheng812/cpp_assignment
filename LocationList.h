/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/
#ifndef LOCATIONLIST_H
#define LOCATIONLIST_H

#include "Location.h"
#include "CityLocation.h"
#include "CampusLocation.h"

class LocationList
{
private:
    Location** list;
    int Grow();
    int capacity;
    int size;

public:
    LocationList();
    ~LocationList();
    int GetCount() const { return size; }
    Location* GetLocation(int index) const { return (list[index]); }
    void AddLocation(const Location& new_loc);
    void FromFile(std::string fname);
    void ToFile(std::string fname);
};

#endif
