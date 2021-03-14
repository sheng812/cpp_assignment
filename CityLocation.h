/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/
#ifndef CITYLOCATION_H
#define CITYLOCATION_H

#include "Location.h"

class CityLocation : public Location
{

public:
    CityLocation() : Location("name", "address", "hours", 0, "city") {}
    CityLocation(const Location &copy_from) : Location(copy_from) {}
    bool Reserve();
    void Cancel() {allow_reservation++;}
    void Print() const;
    void Read(std::istream& s);
    void Write(std::ostream& s) const;
};

#endif
