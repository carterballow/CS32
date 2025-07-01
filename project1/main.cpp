#include "BloodDonation.h"
#include "VacationAccount.h"
#include <cassert>
#include <iostream>

int main() {
    BloodDonation d1(123456, 45, 150.5, "2025-01-01");
    BloodDonation d2(123456, 45, 150.5, "2025-07-10");
    VacationAccount acc(123456);

    assert(acc.getBalance() == 0.0);
    assert(acc.addVacationToAccount(&d1) == true);
    assert(acc.getBalance() == 4.0);
    assert(acc.addVacationToAccount(&d2) == true);
    assert(acc.getBalance() == 8.0);

    acc.printDonationHistory();
    return 0;
}

