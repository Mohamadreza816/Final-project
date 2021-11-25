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
patient::patient(const patient &source)
    : patient{source.grade}
{
}
//end of copy constructor
/*****************************************************/
/*****************************************************/
//get_hc method
int patient::get_health_count()
{
    return health_count;
}
//end of hc count method
/*****************************************************/
/*****************************************************/
//get_sc method
int patient::get_sick_count()
{
    return sick_count;
}
//end of get_sc method
/*****************************************************/
/*****************************************************/
//treatment method
int patient::treatment(doctor &doc, device &dev, device &dev1)
{
    try
    {
        switch (grade)
        {
        case 1: //Easy to treat

            if (dev.get_count() > 0)
            {
                dev.use(doc);
                doc.set_xp(HEALTHY);
                doc.set_energy(10, HEALTHY);
                doc.set_credit(HEALTHY);
                doc.set_coin(7);
                health_count++;
            }
            else
            {
                throw out_of_range("you have not enough devicre for treat!");
            }
            break;
        case 2: //normal
            if (doc.get_xp() >= 70)
            {
                if (dev1.get_count() > 0)//we can treat
                {
                    dev.use(doc);
                    doc.set_xp(HEALTHY);
                    doc.set_energy(15, HEALTHY);
                    doc.set_credit(HEALTHY);
                    doc.set_coin(13);
                    health_count++;
                }
                else
                {
                    throw out_of_range("you have not enough devicre for treat!");
                }
            }
            else//We start treatment but the patient does not recover
            {
                dev.use(doc);
                doc.set_xp(ILL);
                doc.set_energy(15, ILL);
                doc.set_credit(ILL);
                sick_count++;
            }
            break;
        case 3: //difficult
            if (doc.get_xp() >= 100)
            {
                if (dev.get_count() > 0 && dev1.get_count() > 0)
                {
                    dev.use(doc);
                    doc.set_xp(HEALTHY);
                    doc.set_energy(20, HEALTHY);
                    doc.set_credit(HEALTHY);
                    doc.set_coin(20);
                    health_count++;
                }
                else
                {
                    throw out_of_range("you have not enough devicre for treat!");
                }
            }
            else//We start treatment but the patient does not recover
            {
                dev.use(doc);
                doc.set_xp(ILL);
                doc.set_energy(20, ILL);
                doc.set_credit(ILL);
                sick_count++;
            }
            break;
        default:
            cout << "This grade has not define:)" << endl;
            break;
        }
    }
    catch (const out_of_range &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
//End of treatment method
/*****************************************************/
/*****************************************************/
//operator overloading
patient &patient ::operator=(const patient &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    grade = rhs.grade;
}
//End of operator overloading