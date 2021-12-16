#include "doctor.hpp"
#include "medicaldevice.hpp"
#include <vector>
#ifndef PATIENT_HPP
#define PATIENT_HPP
using namespace std;
class patient{
private:
    static int health_count;
    static int sick_count;
    int grade;//1-3
    int status;
public:
    void set_status(int);
    int get_status();
    int get_health_count();//return health count
    int get_sick_count();//return sick count
    patient(int a_grade = 2);
    patient(const patient& source);
    int treatment(doctor& doc ,vector<device*>&);
    patient &operator=(const patient &rhs); //copy assogment(operator overloading)
};
#endif