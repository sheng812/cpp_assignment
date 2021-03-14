/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/

#include <iostream>
#include <fstream>
#include <string>
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
    for (int i = 0; i < size; i++)
    {
        delete list[i];
    }
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

void LocationList::AddLocation(const Location &new_loc)
{
    if (size == capacity)
    {
        capacity = this->Grow();
    }
    if (new_loc.getType() == "city")
    {
        this->list[size] = new CityLocation(new_loc);
    }
    else if (new_loc.getType() == "campus")
    {
        this->list[size] = new CampusLocation(new_loc);
    }
    size++;
}

void LocationList::FromFile(std::string fname)
{
    std::ifstream ifs(fname);
    std::string line;

    if (ifs)
    {
        std::getline(ifs, line);
        if (!line.empty())
        {
            int count = std::stoi(line);
            for (int i = 0; i < count; i++)
            {
                std::getline(ifs, line);
                if (line == "citylocation")
                {
                    CityLocation *location = new CityLocation();
                    location->Read(ifs);
                    this->AddLocation(*location);
                }
                else if (line == "campuslocation")
                {
                    CampusLocation *location = new CampusLocation();
                    location->Read(ifs);
                    this->AddLocation(*location);
                }
            }
        }
        ifs.close();
        std::cout << "Successfully read locations file" << std::endl;
    }
    else
    {
        std::cout << "Fail to read locations file" << std::endl;
    }
}

void LocationList::ToFile(std::string fname)
{
    std::ofstream ofs(fname);

    if (ofs)
    {
        ofs << this->size << std::endl;
        for (int i = 0; i < this->size; i++)
        {
            this->GetLocation(i)->Write(ofs);
        }
        ofs.close();
        std::cout << "Successfully write locations file" << std::endl;
    }
    else
    {
        std::cout << "Fail to write locations file" << std::endl;
    }
}
