#include "patient.h"
#include "pill.h"
#include "ampoule.h"
#include <iomanip>
//static var
int patient::health_count = 0;
int patient::sick_count = 0;
//constructor
patient::patient(QObject *parent) : QObject(parent)
{

}
//end of constructor
/*****************************************************/
/*****************************************************/

//set_status method
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
//get_hc method and emit signal
int patient::get_health_count()
{
    emit noticehealth(QVariant(health_count));
    return health_count;
}
//end of hc count method
/*****************************************************/
/*****************************************************/
//get_sc method and emit signal
int patient::get_sick_count()
{
    emit noticesick(QVariant(sick_count));
    return sick_count;
}
//end of get_sc method
/*****************************************************/
/*****************************************************/
//treatment method and emit signals
int patient::treatment(int g)
{
    doctor d{"doc"};
    pill p{"pill"};
    ampoule a{"ampoule"};
    try
    {

        switch (g)//grade number
        {
        case 1: //Easy to treat
        {
            if (p.get_count() <= 0)//if count of pill is 0
            {
                throw out_of_range("you have not enough devicre for treat!");
            }
            d.set_xp(HEALTHY);
            d.set_energy(10, HEALTHY);
            d.set_credit(HEALTHY);
            d.set_coin(7);
            health_count++;
            this->set_status(HEALTHY);
            emit noticetreatmessage(QVariant (""));// no error message
            emit noticehealth(QVariant(health_count));//update health count
            break;
        }
        case 2: //normal
        {
            if (d.get_xp() >= 40)//enough xp for treat patient gerad 2
            {
                if (a.get_count() <= 0)//if count of ampoule is 0
                {
                    throw out_of_range("you have not enough devicre for treat!");
                }
                else
                {
                    d.set_xp(HEALTHY);
                    d.set_energy(15, HEALTHY);
                    d.set_credit(HEALTHY);
                    d.set_coin(13);
                    health_count++;
                    this->set_status(HEALTHY);
                    emit noticetreatmessage(QVariant (""));//no eror message
                    emit noticehealth(QVariant(health_count));//update health count
                }

            }
/*xp < 40*/ else //We start treatment but the patient does not recover
            {
                cout << setw(20) << setfill('*') << "pateint dosen't recover!!!" << endl;
                if (a.get_count() <= 0)//if count of ampoule is 0
                {
                    throw out_of_range("you have not enough devicre for treat!");
                }
                else
                {
                    d.set_xp(ILL);
                    d.set_energy(15, ILL);
                    d.set_credit(ILL);
                    sick_count++;
                    this->set_status(ILL);
                    emit noticetreatmessage(QVariant ("you xp is low"));//error message
                    emit noticesick(QVariant(sick_count));//update sick count
                }

            }
            break;
        }
        case 3: //difficult
        {
            if (d.get_xp() >= 80)
            {
                if (a.get_count()<= 0 || p.get_count() <= 0)//if count of ampoule and pill are 0
                {
                    throw out_of_range("you have not enough devicre for treat!");
                }
                else
                {
                    d.set_xp(HEALTHY);
                    d.set_energy(20, HEALTHY);
                    d.set_credit(HEALTHY);
                    d.set_coin(20);
                    health_count++;
                    this->set_status(HEALTHY);
                    emit noticetreatmessage(QVariant (""));//no error message
                    emit noticehealth(QVariant(health_count));//update health count
                }
            }
            else //We start treatment but the patient does not recover
            {
                cout << setw(20) << setfill('*') << "pateint dosen't recover!!!" << endl;
                if (a.get_count()<= 0 || p.get_count() <= 0)//if count of ampoule and pill are 0
                {
                    throw out_of_range("you have not enough devicre for treat!");
                }
                cout << "here" << endl;
                d.set_xp(ILL);
                d.set_energy(20, ILL);
                d.set_credit(ILL);
                sick_count++;
                this->set_status(ILL);

                emit noticesick(QVariant(sick_count));//update sick count
                emit noticetreatmessage(QVariant ("your xp is low"));//show eror message
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
        cout << "=============================**" << endl;
        std::cerr << e.what() << '\n';
        cout << setw(20) << setfill('*') << "pateint dosen't recover!!!" << endl;//shoe message in console

        d.set_xp(ILL);
        d.set_energy(15, ILL);
        d.set_credit(ILL);
        sick_count++;
        this->set_status(ILL);

        emit noticesick(QVariant(sick_count));//update sick count
        emit noticetreatmessage(QVariant ("you have not enough devicre for treat!"));//show error message
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
