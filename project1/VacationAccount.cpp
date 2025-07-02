#include "VacationAccount.h"
#include "DateUtility.h"
#include <iostream>

VacationAccount::VacationAccount(int id) {
    mID = id;
    mBalance = 0.0;
    historySize = 0;
    donationHistory = nullptr;
}

VacationAccount::VacationAccount(const VacationAccount& other) {
    mID = other.mID;
    mBalance = other.mBalance;
    historySize = other.historySize;
    donationHistory = new BloodDonation*[historySize];
    for (int i = 0; i < historySize; ++i)
        donationHistory[i] = new BloodDonation(*other.donationHistory[i]);
}

VacationAccount::~VacationAccount() {
    for (int i = 0; i < historySize; ++i)
        delete donationHistory[i];
    delete[] donationHistory;
}

int VacationAccount::getID() const { return mID; }
double VacationAccount::getBalance() const { return mBalance; }

bool VacationAccount::addVacationToAccount(BloodDonation* donation) {
    if (!donation || donation->getID() != mID || donation->getID() == -1 ||
        donation->getAge() == -1 || donation->getWeight() == -1 || donation->getDate() == "")
        return false;

    for (int i = 0; i < historySize; ++i) {
        if (DateUtility::isSameDay(donation->getDate(), donationHistory[i]->getDate()) ||
            !DateUtility::isSixMonthsApart(donation->getDate(), donationHistory[i]->getDate()))
            return false;
    }

    BloodDonation** newHistory = new BloodDonation*[historySize + 1];
    for (int i = 0; i < historySize; ++i)
        newHistory[i] = donationHistory[i];

    newHistory[historySize] = new BloodDonation(*donation);
    delete[] donationHistory;
    donationHistory = newHistory;
    historySize++;

    mBalance += 4.0;
    return true;
}

void VacationAccount::printDonationHistory() const {
    for (int i = 0; i < historySize; ++i)
        donationHistory[i]->print();
}
