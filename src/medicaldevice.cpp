 #include "../include/medicaldevice.hpp"

 using namespace std;
//device construcrtor
device::device(string a_name)
   : name{a_name}
{
}
//End of constructor
/*****************************************************/
/*****************************************************/
//device destructor
device::~device()
{
    
}
//end of device detructor

//------------------------------------------------
//pill class implement

//static var
int pill ::count_pill = 0;

//pill constructor
pill::pill(string a_name)
:device{a_name}
{
    name = a_name;
}
//end of pill constructor
/*****************************************************/
/*****************************************************/
//buy method for pill
void pill::buy(doctor &doc, int count)
{
    //price of pill is 5 coin
    int sum = count * 5;
    if (doc.get_coin() >= sum)
    {
        doc.set_coin(-sum);              //decrease amount of coin
        count_pill = count_pill + count; //increase pill count
    }
    else
    {
        throw out_of_range("count of coin isn't enough!");
    }
}
//end of buy method
/*****************************************************/
/*****************************************************/
// use method for pill
bool pill::use(doctor &doc)
{
    //use poll for treatment
    try
    {

        if (doc.get_xp() >= 0)
        {
            count_pill--; //decrease pill count
        }
        else
        {
            throw out_of_range("ypur experience isn't enough for use pill!");
        }
    }
    catch (const out_of_range &e)
    {
        std::cerr << e.what() << '\n';
        return false;
    }
    return true;
}
//end odf use method
/*****************************************************/
/*****************************************************/
//get_count_pill method
int pill::get_count()
{
    return count_pill;
}
//End of get_count_pill method
/*****************************************************/
/*****************************************************/
//get_name
string pill::get_name()
{
    return name;
}
//end of get_name
/*****************************************************/
/*****************************************************/
//== operator for pill
bool pill::operator==(device & rhs)
{
    return this->get_name() == rhs.get_name();
}
//pill destructor
pill::~pill()
{
}
//------------------------------------------------
//ampoule class implement

//static var
int ampoule::count_ampoule = 0;

//constructor
ampoule::ampoule(string a_name)
    : device{a_name}
{
    name = a_name;
}
//end of constructor
/*****************************************************/
/*****************************************************/
//buy method for ampoule
void ampoule::buy(doctor &doc, int count)
{
    //price of ampoule is 10 coin

    int sum = count * 10;
    if (doc.get_coin() >= sum)
    {
        doc.set_coin(-sum);                    //decrease amount of coin
        count_ampoule = count_ampoule + count; //increase ampoule count
    }
    else
    {
        throw out_of_range("count of coin isn't enough!");
    }
}
//End of buy method
/*****************************************************/
/*****************************************************/
// use method for ampoule
bool ampoule::use(doctor &doc)
{

    if (doc.get_xp() >= 30)
    {
        count_ampoule--; //decrease ampoule count
    }
    else
    {
        throw invalid_argument("your experience isn't enough for use ampoule!");
    }

    return true;
}
//End of use method for ampoule
/*****************************************************/
/*****************************************************/
//get count ampoule method
int ampoule::get_count()
{
    return count_ampoule;
}
//End of get count ampoule method
/*****************************************************/
/*****************************************************/
//get name constructor
string ampoule::get_name()
{
    return name;
}
//get name constructor
/*****************************************************/
/*****************************************************/
//==operator for ampoule class
bool ampoule::operator==(device & rhs)
{
    return this->get_name() == rhs.get_name();
}
/*****************************************************/
/*****************************************************/
//ampoule destructor
ampoule::~ampoule()
{

}