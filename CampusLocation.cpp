/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/

#include <iostream>
#include <iomanip>
#include "CampusLocation.h"

void CampusLocation::Print() const
{
    std::cout << std::left << std::setw(21) << "*** On-Campus ***" << std::endl;
    std::cout << std::left << std::setw(21) << "Location:" << this->name << std::endl;
    std::cout << std::left << std::setw(21) << "Address:" << this->address << std::endl;
    std::cout << std::left << std::setw(21) << "Hours:" << this->hours << std::endl;
    std::cout << std::left << std::setw(21) << "Allows Reservations:" << this->allow_reservation << std::endl;
    std::cout << std::endl;
}

void CampusLocation::Read(std::istream& s) {
    std::string name;
    std::string address;
    std::string hours;

    std::getline(s, name, ',');
    s.ignore(256, ' ');
    std::getline(s, address, ',');
    s.ignore(256, ' ');
    std::getline(s, hours);

    this->name = name;
    this->address = address;
    this->hours = hours;
}

void CampusLocation::Write(std::ostream& s) const {
    s << "campuslocation" << std::endl;
    s << this->name << ", " << this->address << ", " << this->hours << std::endl;
}

