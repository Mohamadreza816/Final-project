#include "doctor.hpp"
#include "medicaldevice.hpp"
#ifndef PATIENT_HPP
#define PATIENT_HPP
using namespace std;
class patient{
private:
    static int health_count;
    static int sick_count;
    int grade;//1-3
public:
    int get_health_count();//return health count
    int get_sick_count();//return sick count
    patient(int a_grade = 2);
    patient(const patient& source);
    int treatment(doctor& doc, device&, device& );
    patient &operator=(const patient &rhs); //copy assogment(operator overloading)
};
#endif