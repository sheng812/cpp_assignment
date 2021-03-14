/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/
#ifndef MENUS_H
#define MENUS_H

#include "LocationList.h"
#include "User.h"

void printMainMenu();
void printSymptomChecker(std::string symptoms[], bool selected[], int a = 6);
void printAdviceMessage(int count);
void printMainmenu();
void printTestingLocations(const LocationList& locations);
void printUserDataMenu(const User& user);
void printSettingsMenu(const bool is_imperial);
void printReservationLocations(const LocationList& locations);

#endif
