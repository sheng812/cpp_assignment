/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/

#include <iostream>
#include <iomanip>
#include "Location.h"

using namespace std;

Location::Location(std::string name, std::string address, std::string hours, int allow_reservation, std::string type = "unknown") : RESERVATION_LITMIT(allow_reservation)
{
    this->name = name;
    this->address = address;
    this->hours = hours;
    this->allow_reservation = allow_reservation;
    this->type = type;
}

Location::Location(const Location &copy_from) : RESERVATION_LITMIT(copy_from.RESERVATION_LITMIT)
{
    name = copy_from.name;
    address = copy_from.address;
    hours = copy_from.hours;
    allow_reservation = copy_from.allow_reservation;
    type = copy_from.type;
}

void Location::Print() const
{
    std::cout << left << setw(21) << "Location:" << this->name << std::endl;
    std::cout << left << setw(21) << "Address:" << this->address << std::endl;
    std::cout << left << setw(21) << "Hours:" << this->hours << std::endl;
    std::cout << left << setw(21) << boolalpha << "Allows Reservations:" << this->allow_reservation << std::endl;
    std::cout << endl;
}

