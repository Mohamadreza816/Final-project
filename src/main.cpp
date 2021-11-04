#include "../include/doctor.hpp"
#include "../include/patient.hpp"
#include <vector>
int main()
{
    doctor d1("pe");
    vector<patient> list;
    patient p1{1};
    list.push_back(p1);
    patient p2{p1};
    list.push_back(p2);
    patient p3{p1};
    list.push_back(p3);
    patient p4{p1};
    list.push_back(p4);
    patient p5{2};
    list.push_back(p5);
    patient p6{2};
    list.push_back(p6);
    patient p7{3};
    list.push_back(p7);
    for(auto item: list)
    {
        item.treatment(d1);
    }
     cout << "xp: " << d1.get_xp() << endl;
     cout << "energy: " <<d1.get_energy() << endl;
     cout << "credit: " << d1.get_credit() << endl;
}