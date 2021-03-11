/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/

#include <iostream>
#include <iomanip>
#include "Location.h"

using namespace std;

Location::Location(std::string name, std::string address, std::string hours, int allow_reservation)
{
    this->name = name;
    this->address = address;
    this->hours = hours;
    this->allow_reservation = allow_reservation;
}

Location::Location(const Location &copy_from)
{
    name = copy_from.name;
    address = copy_from.address;
    hours = copy_from.hours;
    allow_reservation = copy_from.allow_reservation;
}

virtual void Location::Print() const
{
    std::cout << left << setw(21) << "Location:" << this->name << std::endl;
    std::cout << left << setw(21) << "Address:" << this->address << std::endl;
    std::cout << left << setw(21) << "Hours:" << this->hours << std::endl;
    std::cout << left << setw(21) << boolalpha << "Allows Reservations:" << this->allow_reservation << std::endl;
    std::cout << endl;
}

