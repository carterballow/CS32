#include "BloodDonation.h"
#include <iostream>

BloodDonation::BloodDonation(int id, int age, double weight, std::string date) {
    setID(id);
    setAge(age);
    setWeight(weight);
    setDate(date);
}

BloodDonation::BloodDonation(int id) {
    setID(id);
    mAge = -1;
    mWeight = -1;
    mDate = "";
}

BloodDonation::~BloodDonation() {
    std::cout << "BloodDonation " << mID << " destroyed" << std::endl;
}

int BloodDonation::getID() const { return mID; }
int BloodDonation::getAge() const { return mAge; }
double BloodDonation::getWeight() const { return mWeight; }
std::string BloodDonation::getDate() const { return mDate; }

void BloodDonation::setID(int id) {
    mID = (id >= 100000 && id <= 999999) ? id : -1;
}

void BloodDonation::setAge(int age) {
    mAge = (age >= 21 && age <= 65) ? age : -1;
}

void BloodDonation::setWeight(double weight) {
    mWeight = (weight >= 101.0 && weight <= 280.0) ? weight : -1;
}

void BloodDonation::setDate(const std::string& date) {
    mDate = date;
}

void BloodDonation::print() const {
    std::cout << "ID: " << mID << ", Age: " << mAge << ", Weight: " << mWeight << ", Date: " << mDate << std::endl;
}
