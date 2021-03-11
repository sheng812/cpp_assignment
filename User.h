/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/
#ifndef USER_H
#define USER_H

#include "LocationList.h"

class User {
    private:
        std::string first_name;
        std::string last_name;
        int age;
        float height;
        float weight;
        bool is_metric;
        LocationList* reservations;

    public:
        User();
        void MakeReservation(const Location new_reservation);
        std::string to_string() const {return first_name + " " + last_name;}
        void PrintData() const;
        void PrintReservations() const;
        std::string getFirstName() const {return first_name;}
        void setFirstName(std::string fn) {first_name = fn;}
        std::string getLastName() const {return last_name;}
        void setLastName(std::string ln) {last_name = ln;}
        int getAge() const {return age;}
        bool setAge(int a);
        std::string getHeightWithUnit() const;
        bool setHeight(float h);
        std::string getWeightWithUnit() const;
        bool setWeight(float w);
        bool IsMetric() const {return is_metric;};
        void toggleIsMetric() {is_metric = !is_metric;}
        //std::string getUnit();
};

#endif