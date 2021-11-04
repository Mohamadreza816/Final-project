#include "../include/doctor.hpp"
#ifndef PATIENT_H
#define PATIENT_H
using namespace std;
class patient{
private:
    static int health_count;
    static int sick_count;
    int grade;//1-3
public:
    patient(int a_grade = 2);
    patient(const patient& source);
    int treatment(doctor& doc);

};
#endif