/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "CityLocation.h"

bool CityLocation::Reserve() {
    if (this->allow_reservation > 0) {
        this->allow_reservation--;
        return true;
    } else {
        return false;
    }
}

void CityLocation::Print() const
{
    std::cout << std::left << std::setw(21) << "*** Off-Campus ***" << std::endl;
    std::cout << std::left << std::setw(21) << "Location:" << this->name << std::endl;
    std::cout << std::left << std::setw(21) << "Address:" << this->address << std::endl;
    std::cout << std::left << std::setw(21) << "Hours:" << this->hours << std::endl;
    std::cout << std::left << std::setw(21) << "Allows Reservations:" << this->allow_reservation << std::endl;
    std::cout << std::endl;
}

void CityLocation::Read(std::istream& s) {
    std::string name;
    std::string address;
    std::string hours;
    std::string allow_reservation;

    std::getline(s, name, ',');
    s.ignore(256, ' ');
    std::getline(s, address, ',');
    s.ignore(256, ' ');
    std::getline(s, hours, ',');
    s.ignore(256, ' ');
    std::getline(s, allow_reservation);

    this->name = name;
    this->address = address;
    this->hours = hours;
    this->allow_reservation = std::stoi(allow_reservation);
}

void CityLocation::Write(std::ostream& s) const {
    s << "citylocation" << std::endl;
    s << this->name << ", " << this->address << ", " << this->hours << ", " << this->allow_reservation << std::endl;
}

