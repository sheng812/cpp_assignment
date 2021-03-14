/*
name: HSUEH-SHENG FU
Wisc ID: HFU54
*/

#include <iostream>
#include <string>
#include <iomanip>
#include "menus.h"
#include "Location.h"
#include "LocationList.h"
#include "User.h"

using namespace std;

/**
 * count the number of true in selected array
 * 
 * @param selected array stores if the symptoms are selected
 * @param count the number of symptoms selected
 * @return number of true in selected array
 */
int numberOfSelected(bool selected[], int count)
{
    int number_of_selected = 0;
    for (int i = 0; i < count; i++)
    {
        if (selected[i] == true)
        {
            number_of_selected++;
        }
    }
    return number_of_selected;
}

/**
 * safe-ish badgers
 */
int main()
{
    // initialize
    string symptoms[] = {"Fever", "Cough", "Shortness of breath", "Loss of taste or smell", "Fatigue", "Sore throat"};
    // Location *location1 = new Location("Kohl Center, Gate C", "601 W Dayton St", "8:30am-4:30pm", true);
    // Location *location2 = new Location("Dejope Hall, 1165", "640 Elm Dr", "9:30am-5:30pm", false);
    // Location *location3 = new Location("21 N Park St, 1106", "21 N Park St", "7:30am-3:30pm", false);
    // Location *location4 = new Location("Shell, 110", "1430 Monroe St", "8:30am-4:30pm", true);
    // Location *location5 = new Location("Mechanical Engineering Building, 1184", "1513 University Ave", "6:30am-2:30pm", false);
    LocationList *locations = new LocationList();
    // locations->AddLocation(*location1);
    // locations->AddLocation(*location2);
    // locations->AddLocation(*location3);
    // locations->AddLocation(*location4);
    // locations->AddLocation(*location5);

    bool dummy = true;
    User *user = new User();
    user->Read(dummy);
    locations->FromFile("locations.txt");

    const int symptoms_count = 6;
    bool selected[symptoms_count] = {0};
    int input;
    bool endProcess = false;

    do
    {
        printMainMenu();
        cin >> input;
        switch (input)
        {
        case 1: // view testing locations
        {
            bool stop = false;
            do
            {
                printTestingLocations(*locations);
                cin >> input;
                if (!cin)
                {
                    cout << "invalid command" << endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                else if (input > 0 && input < (locations->GetCount() + 1))
                {
                    locations->GetLocation(input - 1)->Print();
                    std::cout << "Press enter to return to menu." << std::endl;
                    cin.ignore(100, '\n');
                    cin.get();
                }
                else if (input == locations->GetCount() + 1)
                {
                    stop = true;
                }
                else
                {
                    cout << "invalid command" << endl;
                }
            } while (!stop);
            break;
        }
        case 2: // make test reservation
        {
            printReservationLocations(*locations);
            cin >> input;
            if (!cin)
            {
                // cout << "invalid command" << endl;
                cin.clear();
                cin.ignore(100, '\n');
            }
            else
            {
                if (input < 0 || input >= locations->GetCount()) {
                    cout << "invalid index" << std::endl;
                } else {
                    user->MakeReservation(*(locations->GetLocation(input)));
                }
                std::cout << "Press enter to return to menu." << std::endl;
                cin.ignore(100, '\n');
                cin.get();
            }
            break;
        }
        case 3: // user symptom checker
        {
            bool stop = false;
            do
            {
                printSymptomChecker(symptoms, selected);
                cin >> input;
                if (!cin)
                {
                    cout << "invalid command" << endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                else if (input > 0 && input < (symptoms_count + 1))
                {
                    selected[input - 1] = !selected[input - 1];
                }
                else if (input == symptoms_count + 1)
                {
                    printAdviceMessage(numberOfSelected(selected, symptoms_count));
                    cin.ignore(100, '\n');
                    cin.get();
                }
                else if (input == symptoms_count + 2)
                {
                    stop = true;
                }
                else
                {
                    cout << "invalid command" << endl;
                }
            } while (!stop);
            break;
        }
        case 4: // view my reservations
            user->PrintReservations();
            std::cout << "Press enter to return to menu." << std::endl;
            cin.ignore(100, '\n');
            cin.get();
            break;
        case 5: // view my personal data
            user->PrintData();
            cin.ignore(100, '\n');
            cin.get();
            break;
        case 6: // adjust my personal data
        {
            int user_data_input;
            bool stop = false;
            string first_name;
            string last_name;
            int age;
            float height;
            float weight;
            do
            {
                printUserDataMenu(*user);
                cin >> user_data_input;
                switch (user_data_input)
                {
                case 1:
                    cout << "Please enter your first name" << endl;
                    cin >> first_name;
                    user->setFirstName(first_name);
                    break;
                case 2:
                    cout << "Please enter your last name" << endl;
                    cin >> last_name;
                    user->setLastName(last_name);
                    break;
                case 3:
                    do
                    {
                        cout << "Please enter your age" << endl;
                        cin >> age;
                        if (!cin)
                        {
                            cin.clear();
                            cin.ignore(100, '\n');
                            age = -1; // give invalid int if input is invaid
                        }
                    } while (!user->setAge(age));
                    break;
                case 4:
                    do
                    {
                        cout << "Please enter your height" << endl;
                        cin >> height;
                        if (!cin)
                        {
                            cin.clear();
                            cin.ignore(100, '\n');
                            height = -1; // give invalid float if input is invalid
                        }
                    } while (!user->setHeight(height));
                    break;
                case 5:
                    do
                    {
                        cout << "Please enter your weight" << endl;
                        cin >> weight;
                        if (!cin)
                        {
                            cin.clear();
                            cin.ignore(100, '\n');
                            weight = -1;
                        }
                    } while (!user->setWeight(weight));
                    break;
                case 6:
                    stop = true;
                    break;
                default:
                    cout << "invalid command" << endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }
            } while (!stop);
            break;
        }
        case 7: // change setting
        {
            int user_settings_input;
            bool stop = false;
            do
            {
                printSettingsMenu(user->IsImperial());
                cin >> user_settings_input;
                switch (user_settings_input)
                {
                case 1:
                    user->toggleIsImperial();
                    break;
                case 2:
                {   
                    std::string last_name;
                    cout << "Please enter your last name" << endl;
                    cin >> last_name;
                    user->Read(dummy, last_name + ".txt");
                    break;
                }
                case 3:
                    user->Write(true);
                    break;
                case 4:
                    stop = true;
                    break;
                default:
                    cout << "invalid command" << endl;
                    cin.clear();
                    cin.ignore(100, '\n');
                }
            } while (!stop);
            break;
        }
        case 8: // exit the program
            endProcess = true;
            break;
        default:
            cout << "invalid command" << endl;
            cin.clear();
            cin.ignore(100, '\n');
        }
    } while (!endProcess);

    return 0;
}
