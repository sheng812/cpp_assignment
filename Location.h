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
    static int allow_reservation;

public:
    Location(std::string name, std::string address, std::string hours, int allow_reservation);
    Location(const Location &copy_from);
    int IsReservable() const {return allow_reservation;} 
    std::string to_string() const {return name;}
    virtual void Print() const;
    virtual void Read(std::istream& s);
    virtual void Write(std::ostream& s) const;
    virtual bool Reserve();
    virtual bool Cancel();
};

#endif
