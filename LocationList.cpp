/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/

#include <iostream>
#include "Location.h"
#include "LocationList.h"

LocationList::LocationList()
{
    capacity = 8;
    list = new Location *[capacity];
    size = 0;
}

LocationList::~LocationList()
{
    delete[] list;
}

int LocationList::Grow()
{
    Location **new_list = new Location *[2 * capacity];
    for (int i = 0; i < capacity; i++)
    {
        new_list[i] = list[i];
    }
    delete[] list;
    list = new_list;
    return 2 * capacity;
}

void LocationList::AddLocation(const Location& new_loc)
{
    if (size == capacity)
    {
        capacity = this->Grow();
    }
    this->list[size] = new Location(new_loc);
    size++;
}
