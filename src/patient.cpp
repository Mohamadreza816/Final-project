#include "../include/patient.hpp"
using namespace std;
int patient::health_count = 0;
int patient::sick_count = 0;
//constructor
patient::patient(int a_grade)
    : grade{a_grade}
{
}
//end of constructor
/*****************************************************/
/*****************************************************/
//copy constructor
patient::patient(const patient& source)
  :patient{source.grade}
{}
//end of copy constructor
/*****************************************************/
/*****************************************************/
//treatment method
int patient::treatment(doctor& doc)
{
    switch (grade)
    {
    case 1: //Easy to treat

        if (doc.get_xp() >= 0)
        {
            doc.set_xp(0);
            doc.set_energy(10,0);
            doc.set_credit(0);
            health_count++;
        }
        break;
    case 2: //normal
        if (doc.get_xp() >= 30)
        {
            doc.set_xp(0);
            doc.set_energy(15,0);
            doc.set_credit(0);
            health_count++;
        }else
        {
            doc.set_xp(1);
            doc.set_energy(15,0);
            doc.set_credit(1);
            sick_count++;
        }
        break;
    case 3://difficult
        if (doc.get_xp() >= 60)
        {
            doc.set_xp(0);
            doc.set_energy(20,0);
            doc.set_credit(0);
            health_count++;
        }else
        {
            doc.set_xp(1);
            doc.set_energy(20,1);
            doc.set_credit(1);
            sick_count++;
        }
        break;
    default:
        cout << "This grade has not define:)" << endl;
        break;
    }
    return 0;
}
//End of treatment method
/*****************************************************/
/*****************************************************/