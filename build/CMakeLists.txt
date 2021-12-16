cmake_minimum_required(VERSION 3.0)
project(PHASE1)
add_executable(app ../src/main.cpp ../src/doctor.cpp ../src/patient.cpp ../src/medicaldevice.cpp )
include_directories(../include)