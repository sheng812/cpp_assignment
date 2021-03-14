/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include "User.h"
#include "LocationList.h"

using namespace std;

User::User()
{
    first_name = "John";
    last_name = "Doe";
    is_imperial = true;
    age = 32;
    height = (is_imperial) ? 6.1 / 3.28 : 6.1;
    weight = (is_imperial) ? 201.5 / 2.20 : 201.5;
    reservations = new LocationList();
    user_filename = "default.txt";
    reservations_filename = "default_reservations.txt";
}

void User::MakeReservation(Location &new_reservation)
{
    if (new_reservation.getType() == "city")
    {
        CityLocation *reservation = dynamic_cast<CityLocation *>(&new_reservation);
        if (reservation->Reserve())
        {
            reservations->AddLocation(*reservation);
            cout << "Successfully make reservation" << endl;
        }
        else
        {
            cout << "Fail to make reservation" << endl;
        }
    }
    else if (new_reservation.getType() == "campus")
    {
        CampusLocation *reservation = dynamic_cast<CampusLocation *>(&new_reservation);
        if (reservation->Reserve())
        {
            reservations->AddLocation(*reservation);
            cout << "Successfully make reservation" << endl;
        }
        else
        {
            cout << "Fail to make reservation" << endl;
        }
    }
}

void User::PrintData() const
{
    cout << "Your data:" << endl;
    cout << "Name:   " << this->to_string() << endl;
    cout << "Age:    " << this->age << endl;
    cout << "Height: " << this->getHeightWithUnit() << endl;
    cout << "Weight: " << this->getWeightWithUnit() << endl;
    cout << "Enter any number to return to menu." << endl;
}

void User::PrintReservations() const
{
    int count = this->reservations->GetCount();
    cout << "Here are your resevations:" << endl;
    for (int i = 0; i < count; i++)
    {
        reservations->GetLocation(i)->Print();
    }
}

void User::setLastName(std::string ln)
{
    this->user_filename = ln + ".txt";
    this->reservations_filename = ln + "_reservations.txt";
    this->last_name = ln;
}

bool User::setHeight(float h)
{
    h = (is_imperial) ? h / 3.28 : h;
    if (h < 0 || h > 2.8)
    {
        cout << "invaid data" << endl;
        return false;
    }
    else
    {
        height = h;
        return true;
    }
}

bool User::setWeight(float w)
{
    w = (is_imperial) ? w / 2.20 : w;
    if (w < 0 || w > 450)
    {
        cout << "invaid data" << endl;
        return false;
    }
    else
    {
        weight = w;
        return true;
    }
}

bool User::setAge(int a)
{
    if (a < 0 || a > 130)
    {
        cout << "invaid data" << endl;
        return false;
    }
    else
    {
        age = a;
        return true;
    }
}

string User::getHeightWithUnit() const
{
    stringstream stream;
    stream << fixed;
    (is_imperial) ? (stream << setprecision(1) << height * 3.28 << " ft") : (stream << setprecision(2) << height << " m");
    return stream.str();
}

string User::getWeightWithUnit() const
{
    stringstream stream;
    stream << fixed;
    (is_imperial) ? (stream << setprecision(1) << weight * 2.20 << " lbs") : (stream << setprecision(1) << weight << " kg");
    return stream.str();
}

void User::Read(bool &is_imperial, std::string fname)
{
    std::string last_name;
    int age;
    float height;
    float weight;
    int imperial;

    if (fname == "")
    {
        fname = "default.txt";
        this->reservations_filename = "default_reservations.txt";
    }

    std::ifstream ifs(fname);

    if (ifs)
    {
        ifs >> this->first_name;
        ifs >> this->last_name;
        ifs >> age;
        ifs >> height;
        ifs >> weight;
        ifs >> imperial;
        this->is_imperial = (bool)imperial;
        this->setAge(age);
        this->setHeight(height);
        this->setWeight(weight);
        ifs.close();
        std::cout << "Successfully read user file" << std::endl;
    }
    else
    {
        std::cout << "Fail to open user_file" << std::endl;
    }
    std::cout << "(user)";
    this->reservations->FromFile(this->reservations_filename);
    this->setLastName(this->last_name);
}

void User::Write(const bool is_imperial)
{

    std::ofstream ofs(this->user_filename);

    if (ofs)
    {
        ofs << this->first_name << " " << this->last_name << " " << this->age << " " << this->height << " " << this->weight << " " << this->is_imperial;
        ofs.close();
        std::cout << "Successfully write user file" << std::endl;
    }
    else
    {
        std::cout << "Fail to write user file" << std::endl;
    }

    this->reservations->ToFile(this->reservations_filename);
}
