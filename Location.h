/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/
#ifndef LOCATION_H
#define LOCATION_H

class Location
{
protected:
    std::string name;
    std::string address;
    std::string hours;
    std::string type;
    int allow_reservation;
    const int RESERVATION_LITMIT;

public:
    Location(std::string name, std::string address, std::string hours, int allow_reservation, std::string type);
    Location(const Location &copy_from);
    virtual bool IsReservable() const {return (allow_reservation > 0);} 
    std::string to_string() const {return name;}
    virtual void Print() const = 0;
    virtual void Read(std::istream& s) = 0;
    virtual void Write(std::ostream& s) const = 0;
    virtual bool Reserve() = 0;
    virtual void Cancel() = 0;
    std::string getType() const {return type;}
};

#endif
