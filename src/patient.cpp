#include "../include/patient.hpp"
#include <iomanip>
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
//set_status
void patient::set_status(int st)
{
    status = st;
}
//end of set status
/*****************************************************/
/*****************************************************/
//get_status
int patient::get_status()
{
    return status;
}
//end of status
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
int patient::treatment(doctor &doc, vector<device*> & md)
{
    try
    {
        switch (grade)
        {
        case 1: //Easy to treat
        {
            if (md.empty())
            {
                throw out_of_range("you have not enough devicre for treat!");
            }

            //delete device from vector
            int check = 0;
            for (auto it = md.begin(); it != md.end(); ++it)
            {
                if ((*it)->get_name() == "pill")
                {
                    (*it)->use(doc);
                    md.erase(it);
                    it = md.end() - 1;
                    check = 1;
                }
            }
            if (check == 0)
            {
                throw out_of_range("you have not enough device for treat!");
            }
            doc.set_xp(HEALTHY);
            doc.set_energy(10, HEALTHY);
            doc.set_credit(HEALTHY);
            doc.set_coin(7);
            health_count++;
            this->set_status(HEALTHY);
            break;
        }
        case 2: //normal
        {
            if (doc.get_xp() >= 40)
            {
                if (md.empty())
                {
                    throw out_of_range("you have not enough devicre for treat!");
                }
                //we can treat
                //delete device from vector
                int check = 0;
                for (auto it = md.begin(); it != md.end(); ++it)
                {
                    if ((*it)->get_name() == "ampoule")
                    {
                        (*it)->use(doc);
                        md.erase(it);
                        it = md.end() - 1;
                        check = 1;
                    }
                }
                if (check == 0)
                {
                    throw out_of_range("you have not enough device for treat!");
                }
                doc.set_xp(HEALTHY);
                doc.set_energy(15, HEALTHY);
                doc.set_credit(HEALTHY);
                doc.set_coin(13);
                health_count++;
                this->set_status(HEALTHY);
            }
            else //We start treatment but the patient does not recover
            {
                cout << setw(20) << setfill('*') << "pateint dosen't recover!!!" << endl;
                if (md.empty())
                {
                    throw out_of_range("you have not enough devicre for treat!");
                }
                //delete device from vector
                int check = 0;
                for (auto it = md.begin(); it != md.end(); ++it)
                {
                    if ((*it)->get_name() == "ampoule")
                    {
                        (*it)->use(doc);
                        md.erase(it);
                        it = md.end() - 1;
                        check = 1;
                    }
                }
                if (check == 0)
                {
                    throw out_of_range("you have not enough device for treat!");
                }
                doc.set_xp(ILL);
                doc.set_energy(15, ILL);
                doc.set_credit(ILL);
                sick_count++;
                this->set_status(ILL);
            }
            break;
        }
        case 3: //difficult
        {
            if (doc.get_xp() >= 80)
            {
                if (md.empty())
                {
                    throw out_of_range("you have not enough devicre for treat!");
                }
                //delete device from vector
                int check = 0;
                for (auto it = md.begin(); it != md.end(); ++it)
                {
                    if ((*it)->get_name() == "pill")
                    {
                        (*it)->use(doc);
                        md.erase(it);
                        it = md.end() - 1;
                        check = 1;
                    }
                }
                if (check == 0)
                {
                    throw out_of_range("you have not enough device for treat!");
                }
                check = 0;
                for (auto it = md.begin(); it != md.end(); ++it)
                {
                    if ((*it)->get_name() == "ampoule")
                    {
                        (*it)->use(doc);
                        md.erase(it);
                        it = md.end() - 1;
                        check = 1;
                    }
                }
                if (check == 0)
                {
                    throw out_of_range("you have not enough device for treat!");
                }
                doc.set_xp(HEALTHY);
                doc.set_energy(20, HEALTHY);
                doc.set_credit(HEALTHY);
                doc.set_coin(20);
                health_count++;
                this->set_status(HEALTHY);
            }
            else //We start treatment but the patient does not recover
            {
                cout << setw(20) << setfill('*') << "pateint dosen't recover!!!" << endl;
                if (md.empty())
                {
                    throw out_of_range("you have not enough devicre for treat!");
                }
                //use and delete pill device from vector
                int check = 0;
                for (auto it = md.begin(); it != md.end(); ++it)
                {
                    if ((*it)->get_name() == "pill")
                    {
                        (*it)->use(doc);
                        md.erase(it);
                        it = md.end() - 1;
                        check = 1;
                    }
                }
                if (check == 0)
                {
                    throw out_of_range("you have not enough device for treat!");
                }
                //use and delete ampoule
                check = 0;
                for (auto it = md.begin(); it != md.end(); ++it)
                {
                    if ((*it)->get_name() == "ampoule")
                    {
                        (*it)->use(doc);
                        md.erase(it);
                        it = md.end() - 1;
                        check = 1;
                    }
                }
                if (check == 0)
                {
                    throw out_of_range("you have not enough device for treat!");
                }
                doc.set_xp(ILL);
                doc.set_energy(20, ILL);
                doc.set_credit(ILL);
                sick_count++;
                this->set_status(ILL);
            }
            break;
        }
        default:
            cout << "=============================" << endl;
            cout << "This grade has not define:)" << endl;
            break;
        }
    }
    catch (const out_of_range &e)
    {
        cout << "=============================" << endl;
        std::cerr << e.what() << '\n';
        cout << setw(20) << setfill('*') << "pateint dosen't recover!!!" << endl;
        doc.set_xp(ILL);
        doc.set_energy(15, ILL);
        doc.set_credit(ILL);
        sick_count++;
        this->set_status(ILL);
    }
    catch (const invalid_argument &e)
    {
        cout << "=============================" << endl;
        cerr << e.what() << endl;
        cout << setw(20) << setfill('*') << "pateint dosen't recover!!!" << endl;
        doc.set_xp(ILL);
        doc.set_energy(15, ILL);
        doc.set_credit(ILL);
        sick_count++;
        this->set_status(ILL);
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
    return *this;
}
//End of operator overloading