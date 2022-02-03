#include "medicaldevice.h"

device::device(string a_name, QObject *parent) : QObject(parent)
{
    name = a_name;
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
