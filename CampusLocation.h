/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/
#ifndef CAMPUSLOCATION_H
#define CAMPUSLOCATION_H

#include "Location.h"

class CampusLocation : public Location
{

public:
    CampusLocation() : Location("name", "address", "hours", 0, "campus") {}
    CampusLocation(const Location &copy_from) : Location(copy_from) {}
    bool Reserve() {return false;}
    void Cancel() {};
    void Print() const;
    void Read(std::istream& s);
    void Write(std::ostream& s) const;
};

#endif
