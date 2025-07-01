#ifndef BLOODDONATION_H
#define BLOODDONATION_H

#include <string>

class BloodDonation {
private:
    int mID;
    int mAge;
    double mWeight;
    std::string mDate;

public:
    BloodDonation(int id, int age, double weight, std::string date);
    BloodDonation(int id);
    ~BloodDonation();

    int getID() const;
    int getAge() const;
    double getWeight() const;
    std::string getDate() const;

    void setID(int id);
    void setAge(int age);
    void setWeight(double weight);
    void setDate(const std::string& date);

    void print() const;
};

#endif
