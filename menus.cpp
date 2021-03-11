/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "menus.h"
#include "LocationList.h"
#include "User.h"

using namespace std;

/**
 * print main menu
 */
void printMainMenu()
{
    cout << "Welcome (back) to Safe-ish Badgers!" << endl;
    cout << "[1] View testing locations" << endl;
    cout << "[2] Make test reservation" << endl;
    cout << "[3] Use symptom checker" << endl;
    cout << "[4] View my reservation" << endl;
    cout << "[5] View my personal data" << endl;
    cout << "[6] Adjust my personal data" << endl;
    cout << "[7] Change settings" << endl;
    cout << "[8] Exit program" << endl;
    cout << "Please enter a menu item:" << endl;
}
/**
 * print test locations
 * 
 * @param locations an array of Location 
 */
void printTestingLocations(const LocationList& locations) {
    string index;
    cout << "Testing Locations:" << endl;
    for (int i = 0; i < locations.GetCount(); i++)
    {
        index = "[" + to_string(i + 1) + "]";
        cout << left << setw(4) << index << locations.GetLocation(i).to_string() << endl;
    }
    index = "[" + to_string(locations.GetCount() + 1) + "]";
    cout << left << setw(4) << index << "Return to main menu" << endl;
    cout << "Choose a location for more information, or return to the menu:" << endl;
}

/**
 * print symptom checker
 * 
 * @param symtoms array storing the symptoms
 * @param selected parallel array to symptoms. True if the corresponding symptom is selected, and vice versa
 * @param size symptoms array size
 */
void printSymptomChecker(std::string symptoms[], bool selected[], int size)
{
    string index;
    cout << "Select Your Symptoms:" << endl;
    for (int i = 0; i < size; i++)
    {
        index = selected[i] ? ("[" + to_string(i + 1) + "*]") : ("[" + to_string(i + 1) + "]");
        cout << left << setw(5) << index << symptoms[i] << endl;
    }
    index = "[" + to_string(size + 1) + "]";
    cout << left << setw(5) << index << "Submit Symptoms" << endl;
    index = "[" + to_string(size + 2) + "]";
    cout << left << setw(5) << index << "Cancel and return to main menu" << endl;
}

/**
 * print advice message
 * 
 * @param count the number of symptoms selected
 */
void printAdviceMessage(int count)
{
    switch (count)
    {
    case 0:
        cout << "You seem to be feeling fine. Remember to test regularly for Covid-19." << endl;
        break;
    case 1:
    case 2:
        cout << "Please stay home and monitor your symptoms. If your symptoms persist or you develop new symptoms," << endl;
        cout << "please go to an available testing site to be tested for Covid-19." << endl;
        break;
    default:
        cout << "Please go to an available testing site to be tested for Covid-19." << endl;
    }
    cout << "Press enter to return to sympton checker." << endl;
}

void printMainmenu() {
    cout << "Welcome (back) to Safe-ish Badgers!" << endl;
    cout << "[1] View testing locations" << endl;
    cout << "[2] Make test reservation" << endl;
    cout << "[3] Use symptom checker" << endl;
    cout << "[4] View my reservations" << endl;
    cout << "[5] View my personal data" << endl;
    cout << "[6] Adjust my personal data" << endl;
    cout << "[7] Change settings" << endl;
    cout << "[8] Exit program" << endl;
    cout << "Please enter a menu item" << endl;
}

void printUserDataMenu(const User&  user) {
    cout << "Set your personal data" << endl;
    cout << "[1] First name (" << user.getFirstName() << ")" << endl;
    cout << "[2] Last name (" << user.getLastName() << ")" << endl;
    cout << "[3] Age (" << user.getAge() << ")" << endl;
    cout << "[4] Height (" << user.getHeightWithUnit() << ")" << endl;
    cout << "[5] Weight (" << user.getWeightWithUnit() << ")" << endl;
    cout << "[6] Return to main menu" << endl;
    cout << "Please enter a menu item:" << endl;
}

void printSettingsMenu(const bool is_metric) {
    cout << "Change your app settings:" << endl;
    if (is_metric) {
        cout << "[1] Switch units (metric)" << endl;
    } else {
        cout << "[1] Switch units (imperial)" << endl;
    }
    cout << "[2] Return to main menu" << endl;
    cout << "please enter a menu item" << endl;
}

void printReservationLocations(const LocationList& locations){
    string index;
    cout << "Testing Locations:" << endl;
    for (int i = 0; i < locations.GetCount(); i++)
    {
        if (locations.GetLocation(i).IsReservable()) {
            index = "[" + to_string(i) + "]";
            cout << left << setw(4) << index << locations.GetLocation(i).to_string() << endl;
        }
    }
    cout << "Choose a location to reserve, or return to the menu:" << endl;
}
