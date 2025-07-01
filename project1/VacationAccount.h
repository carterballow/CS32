#ifndef VACATIONACCOUNT_H
#define VACATIONACCOUNT_H

#include "BloodDonation.h"

class VacationAccount {
private:
    int mID;
    double mBalance;
    BloodDonation** donationHistory;
    int historySize;

public:
    VacationAccount(int id);
    VacationAccount(const VacationAccount& other);
    ~VacationAccount();

    int getID() const;
    double getBalance() const;

    bool addVacationToAccount(BloodDonation* donation);
    void printDonationHistory() const;
};

#endif
