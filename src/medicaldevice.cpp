#include "../include/medicaldevice.hpp"
using namespace std;
device ::device(char *a_name, int a_count)
    : name{a_name}, count{a_count}
{
}