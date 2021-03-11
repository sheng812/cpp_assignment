/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/

#include <iostream>
#include <iomanip>
#include "User.h"
#include "LocationList.h"

using namespace std;

User::User() {
    first_name = "John";
    last_name = "Doe";
    is_metric = false;
    age = 32;
    height = (!is_metric) ? 6.1 / 3.28 : 6.1;
    weight = (!is_metric) ? 201.5 / 2.20 : 201.5;
    reservations = new LocationList();
}

void User::MakeReservation(const Location new_reservation) {
    if (new_reservation.IsReservable()) {
        reservations->AddLocation(new_reservation);
        cout << "add successfully" << endl;
    } else {
        cout << "invalid index" << endl;
    }
}

void User::PrintData() const {
    cout << "Your data:" << endl;
    cout << "Name:   " << this->to_string() << endl;
    cout << "Age:    " << this->age << endl;
    cout << "Height: " << this->getHeightWithUnit() << endl;
    cout << "Weight: " << this->getWeightWithUnit() << endl;
    cout << "Enter any number to return to menu." << endl;
}

void User::PrintReservations() const {
    int count = this->reservations->GetCount();
    cout << "Here are your resevations:" << endl;
    for (int i = 0; i < count; i++) {
        reservations->GetLocation(i).Print();
    }
}

bool User::setHeight(float h)
    {
        h = (!is_metric) ? h / 3.28 : h;
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
        w = (!is_metric) ? w / 2.20 : w;
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
        (!is_metric) ? (stream << setprecision(1) << height * 3.28 << " ft") : (stream << setprecision(2) << height << " m");
        return stream.str();
    }

string User::getWeightWithUnit() const
    {
        stringstream stream;
        stream << fixed;
        (!is_metric) ? (stream << setprecision(1) << weight * 2.20 << " lbs") : (stream << setprecision(1) << weight << " kg");
        return stream.str();
    }

// string User::getUnit()
//     {
//         return (!is_metric) ? "(imperial)" : "(metric)";
//     }

