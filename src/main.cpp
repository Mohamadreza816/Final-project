#include "../include/doctor.hpp"
#include "../include/patient.hpp"
#include "../include/medicaldevice.hpp"
#include <vector>
// function for show message
void message()
{
    cout << "=============================" << endl;
    cout << "1-Treat" << endl;
    cout << "2-Buy medicaldevice" << endl;
    cout << "3-Exit" << endl;
    cout << "-----------------------------" << endl;
    cout << "Please chose(type number): " << endl;
    cout << "=============================" << endl;
}
int main()
{
    cout << "1-Start \n2-Exit" << endl;
    cout << "-----------------------------" << endl;
    cout << "Please chose(type number): ";
    int chose{0};
    cin >> chose;
    if (chose == 2)
    {
        cout << "Exit..." << endl;
        exit(0);
    }

    else if (chose == 1)
    {
        vector<patient> p_list;                 //a list for store patitint
        vector<device *> md_list;               // a list forstore medical device
        doctor d1("Doctor");                    // make doctor obj
        device *temp = new pill{"pill"};        //make pill obj
        device *temp1 = new ampoule{"ampoule"}; //make ampoule obj
        message();
        cin.clear();
        cin >> chose;
        while (chose != 3)
        {
            if (chose == 1) //for treat
            {
                cout << "Enter a number for pateinet grade(1 - 3): ";
                int size{0};
                cin >> size;
                patient p(size);
                p.treatment(d1, md_list);
                p_list.push_back(p); //store patient in list
            }
            else if (chose == 2) //Buy zone
            {

                cout << "What do you want?\n1-Pill\n2-Ampoule" << endl;
                cout << "-----------------------------" << endl;
                cout << "Please type name(lowercase): ";
                string req;
                cin >> req;
                if (req == "pill")
                {
                    cout << "Coin: " << d1.get_coin() << endl;
                    cout << "How many: ";
                    int num{0};
                    cin.clear();
                    cin >> num;
                    try
                    {
                        temp->buy(d1, num);
                        for (size_t i = 0; i < num; i++)
                        {
                            md_list.push_back(temp);
                        }
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }
                else if (req == "ampoule")
                {
                    cout << "Coin: " << d1.get_coin() << endl;
                    cout << "How many: ";
                    int num{0};
                    cin >> num;

                    try
                    {
                        temp1->buy(d1, num);
                        for (size_t i = 0; i < num; i++)
                        {
                            md_list.push_back(temp1);
                        }
                    }
                    catch (const std::exception &e)
                    {
                        std::cerr << e.what() << '\n';
                    }
                }
                else
                {
                    cout << "=============================" << endl;
                    cout << "Entered name is incorrect!!!" << endl;
                }
            }
            else if (chose != 2 && chose != 1)
            {
                cout << "=============================" << endl;
                cout << "Entered number is incorrect!!!" << endl;
                return 0;
               
            }
            message();
            cin.clear();
            cin >> chose;
        }
        delete temp;
        delete temp1;
        cout << "xp: " << d1.get_xp() << endl;
        cout << "energy: " << d1.get_energy() << endl;
        cout << "credit: " << d1.get_credit() << endl;
        cout << "health count: " << p_list[0].get_health_count() << endl;
        cout << "sick count: " << p_list[0].get_sick_count() << endl;
        cout << "coin: " << d1.get_coin() << endl;
    }
    else
    {
        cout << "Entered number is incorrect!!!" << endl;
        return 0;
    }
}