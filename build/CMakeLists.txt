cmake_minimum_required(VERSION 3.0)
project(PHASE1)
add_executable(app ../src/patient.cpp ../src/medicaldevice.cpp ../src/doctor.cpp ../src/main.cpp)
include_directories(../include)