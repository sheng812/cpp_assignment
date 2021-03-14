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
        bool is_imperial;
        LocationList* reservations;

        std::string user_filename;
        std::string reservations_filename;

    public:
        User();
        void MakeReservation(Location& new_reservation);
        std::string to_string() const {return first_name + " " + last_name;}
        void PrintData() const;
        void PrintReservations() const;

        std::string getFirstName() const {return first_name;}
        std::string getLastName() const {return last_name;}
        int getAge() const {return age;}
        std::string getHeightWithUnit() const;
        std::string getWeightWithUnit() const;
        bool IsImperial() const {return is_imperial;};

        void setFirstName(std::string fn) {first_name = fn;}
        void setLastName(std::string ln);
        bool setAge(int a);
        bool setHeight(float h);
        bool setWeight(float w);
        void toggleIsImperial() {is_imperial = !is_imperial;}
        
        void Read(bool& is_imperial, std::string fname = "");
        void Write(const bool is_imperial);
        //std::string getUnit();
};

#endif