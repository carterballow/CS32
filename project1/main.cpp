#include "BloodDonation.h"
#include "VacationAccount.h"
#include "DateUtility.h"
#include <cassert>
#include <iostream>

int main() {
    BloodDonation d1(123456, 45, 150.5, "01/24/2021");
    BloodDonation d2(123456, 45, 150.5, "06/25/2020");
    BloodDonation d3(123456, 45, 150.5, "04/23/1905");
    BloodDonation d4(123456, 45, 150.5, "10/24/1907");
    
    VacationAccount acc(123456);

    assert(acc.getBalance() == 0.0);
    assert(acc.addVacationToAccount(&d1) == true);
    assert(acc.getBalance() == 4.0);
    assert(acc.addVacationToAccount(&d2) == true);
    assert(acc.getBalance() == 8.0);
    assert(acc.addVacationToAccount(&d3) == true);
    assert(acc.getBalance() == 12.0);
    assert(acc.addVacationToAccount(&d4) == true);
    assert(acc.getBalance() == 16.0);
    
    acc.printDonationHistory();
    
    BloodDonation t1(123450, 45, 150.5, "10/24/2021");
    BloodDonation t2(123450, 45, 150.5, "04/21/2022");
    BloodDonation t3(123450, 45, 150.5, "04/23/1905");
    BloodDonation t4(123456, 45, 150.5, "10/24/1910");
    
    VacationAccount trytwo(123450);

    assert(trytwo.getBalance() == 0.0);
    assert(trytwo.addVacationToAccount(&t1) == true);
    assert(trytwo.getBalance() == 4.0);
    assert(trytwo.addVacationToAccount(&t2) == true);
    assert(trytwo.getBalance() == 8.0);
    assert(trytwo.addVacationToAccount(&t3) == true);
    assert(trytwo.getBalance() == 12.0);
    assert(acc.addVacationToAccount(&t4) == true);
    assert(trytwo.getBalance() == 12.0);

    trytwo.printDonationHistory();
    acc.printDonationHistory();
    
    assert(DateUtility::isValidDate("01/01/2023") == true);
    assert(DateUtility::isValidDate("12/31/2000") == true);
    assert(DateUtility::isValidDate("02/29/2024") == true); 
    assert(DateUtility::isValidDate("13/01/2023") == false); 
    assert(DateUtility::isValidDate("00/01/2023") == false);
    assert(DateUtility::isValidDate("01/32/2023") == false);
    assert(DateUtility::isValidDate("01/00/2023") == false);
    assert(DateUtility::isValidDate("01/01/1899") == false); 
    assert(DateUtility::isValidDate("01/01/2101") == false);
    assert(DateUtility::isValidDate("1/1/2023") == false);  
    assert(DateUtility::isValidDate("01-01-2023") == false); 
    assert(DateUtility::isValidDate("01/_1/2023") == false); 

    // Test isSameDay
    assert(DateUtility::isSameDay("05/15/2022", "05/15/2022") == true);
    assert(DateUtility::isSameDay("05/15/2022", "05/16/2022") == false);
    assert(DateUtility::isSameDay("05/15/2022", "1/1/22") == false); 

    // Test isSixMonthsApart
    assert(DateUtility::isSixMonthsApart("01/10/2023", "07/09/2023") == true); 
    assert(DateUtility::isSixMonthsApart("01/31/2023", "08/01/2023") == true); 
    assert(DateUtility::isSixMonthsApart("10/01/2022", "04/01/2023") == true);  
    assert(DateUtility::isSixMonthsApart("01/10/2023", "06/10/2023") == false); 
    assert(DateUtility::isSixMonthsApart("01/10/2023", "01/10/2023") == false);
    assert(DateUtility::isSixMonthsApart("07/10/2023", "01/10/2023") == true);  
    assert(DateUtility::isSixMonthsApart("01/01/2023", "bad-date") == false);   

    // Valid donation
    BloodDonation validDon(111111, 30, 150.0, "01/01/2024");
    assert(validDon.getID() == 111111);
    assert(validDon.getAge() == 30);
    assert(validDon.getWeight() == 150.0);
    assert(validDon.getDate() == "01/01/2024");

    BloodDonation invalidID(12345, 30, 150.0, "01/01/2024");
    assert(invalidID.getID() == -1);

    BloodDonation invalidAge(222222, 20, 150.0, "01/01/2024");
    assert(invalidAge.getAge() == -1);

    BloodDonation invalidWeight(333333, 30, 100.0, "01/01/2024");
    assert(invalidWeight.getWeight() == -1);

    BloodDonation invalidDate(444444, 30, 150.0, "99/99/9999");
    assert(invalidDate.getDate() == "");

    VacationAccount acc1(100001);
    assert(acc1.getID() == 100001);
    assert(acc1.getBalance() == 0.0);

    BloodDonation d1_1(100001, 40, 180.0, "03/15/2022");
    assert(acc1.addVacationToAccount(&d1_1) == true);
    assert(acc1.getBalance() == 4.0);

    BloodDonation d1_2(100001, 40, 180.0, "09/12/2022"); 
    assert(acc1.addVacationToAccount(&d1_2) == true);
    assert(acc1.getBalance() == 8.0);

    BloodDonation d1_3(100001, 41, 182.0, "05/20/2023"); 
    assert(acc1.addVacationToAccount(&d1_3) == true);
    assert(acc1.getBalance() == 12.0);

    VacationAccount acc2(100002);
    BloodDonation d2_1(100002, 25, 120.0, "01/01/2023");
    assert(acc2.addVacationToAccount(&d2_1) == true);
    assert(acc2.getBalance() == 4.0);

    // Reject: Same day donation
    BloodDonation d2_2_sameDay(100002, 25, 120.0, "01/01/2023");
    assert(acc2.addVacationToAccount(&d2_2_sameDay) == false);
    assert(acc2.getBalance() == 4.0);

    BloodDonation d2_3_tooSoon(100002, 25, 121.0, "06/30/2023");
    assert(acc2.addVacationToAccount(&d2_3_tooSoon) == false);
    assert(acc2.getBalance() == 4.0);

    BloodDonation d2_4_badAge(100002, 99, 122.0, "08/08/2023");
    assert(d2_4_badAge.getAge() == -1);
    assert(acc2.addVacationToAccount(&d2_4_badAge) == false);
    assert(acc2.getBalance() == 4.0);

    VacationAccount acc3(100003);
    assert(acc3.addVacationToAccount(nullptr) == false);
    assert(acc3.getBalance() == 0.0);

    BloodDonation d3_1(100003, 50, 200.0, "11/05/2021");
    assert(acc3.addVacationToAccount(&d3_1) == true);
    assert(acc3.getBalance() == 4.0);

    BloodDonation d3_2(100003, 50, 200.0, "05/05/2022");
    assert(acc3.addVacationToAccount(&d3_2) == true);
    assert(acc3.getBalance() == 8.0);

    VacationAccount acc4(100004);
    BloodDonation d4_1_wrongID(999999, 33, 155.0, "02/02/2022"); 
    assert(acc4.addVacationToAccount(&d4_1_wrongID) == false);
    assert(acc4.getBalance() == 0.0);

    VacationAccount acc5_original(100005);
    BloodDonation d5_1(100005, 28, 140.0, "04/01/2024");
    BloodDonation d5_2(100005, 28, 140.0, "10/01/2024");
    acc5_original.addVacationToAccount(&d5_1);
    acc5_original.addVacationToAccount(&d5_2);
    assert(acc5_original.getBalance() == 8.0);


    VacationAccount acc5_copy(acc5_original);
    assert(acc5_copy.getID() == 100005);
    assert(acc5_copy.getBalance() == 8.0); 

    BloodDonation d5_3(100005, 29, 142.0, "04/01/2025");
    assert(acc5_original.addVacationToAccount(&d5_3) == true);
    assert(acc5_original.getBalance() == 12.0);
    assert(acc5_copy.getBalance() == 8.0); 

    BloodDonation d5_4(100005, 29, 142.0, "11/11/2025");
    assert(acc5_copy.addVacationToAccount(&d5_4) == true);
    assert(acc5_copy.getBalance() == 12.0);
    assert(acc5_original.getBalance() == 12.0); 
    
    VacationAccount WRONG(123451);
    assert(WRONG.getBalance() == 0.0);
    BloodDonation w1(123451, 45, 150.5, "10/24/2000");
    assert(WRONG.addVacationToAccount(&w1) == true);
    assert(WRONG.getBalance() == 4.0);
    WRONG.printDonationHistory();
    
    int assertion_count = 0;

    assert(DateUtility::isValidDate("02/29/2024") == true); assertion_count++;
    assert(DateUtility::isValidDate("02/31/2023") == true); assertion_count++;
    assert(DateUtility::isValidDate("01/01/1900") == true); assertion_count++;
    assert(DateUtility::isValidDate("12/31/2100") == true); assertion_count++; 
    assert(DateUtility::isValidDate("01/01/1899") == false); assertion_count++;
    assert(DateUtility::isValidDate("01/01/2101") == false); assertion_count++;
    assert(DateUtility::isSixMonthsApart("08/31/2023", "02/28/2024") == true); assertion_count++;
    assert(DateUtility::isSixMonthsApart("08/31/2023", "02/01/2024") == true); assertion_count++; 
    assert(DateUtility::isSixMonthsApart("02/01/2024", "08/01/2024") == true); assertion_count++;
    assert(DateUtility::isSameDay("01/01/2023", "01/01/2023") == true); assertion_count++;
    assert(DateUtility::isSameDay("01/01/2023", "bad-date") == false); assertion_count++;

    BloodDonation b_valid(111111, 21, 101.0, "01/01/1900");
    assert(b_valid.getID() == 111111); assertion_count++;
    assert(b_valid.getAge() == 21); assertion_count++;
    assert(b_valid.getWeight() == 101.0); assertion_count++;
    assert(b_valid.getDate() == "01/01/1900"); assertion_count++;

    BloodDonation b_invalid(9999999, 66, 280.1, "12/31/2101");
    assert(b_invalid.getID() == -1); assertion_count++;
    assert(b_invalid.getAge() == -1); assertion_count++;
    assert(b_invalid.getWeight() == -1); assertion_count++;
    assert(b_invalid.getDate() == ""); assertion_count++;

    VacationAccount acc1_perfect(100001);
    assert(acc1_perfect.getID() == 100001 && acc1_perfect.getBalance() == 0.0); assertion_count++;

    BloodDonation p1(100001, 30, 150.0, "01/01/2020");
    assert(acc1_perfect.addVacationToAccount(&p1) == true && acc1_perfect.getBalance() == 4.0); assertion_count++;
    BloodDonation p2(100001, 30, 150.0, "07/01/2020");
    assert(acc1_perfect.addVacationToAccount(&p2) == true && acc1_perfect.getBalance() == 8.0); assertion_count++;
    BloodDonation p3(100001, 31, 151.0, "01/01/2021");
    assert(acc1_perfect.addVacationToAccount(&p3) == true && acc1_perfect.getBalance() == 12.0); assertion_count++;
    BloodDonation p4(100001, 31, 151.0, "07/01/2021");
    assert(acc1_perfect.addVacationToAccount(&p4) == true && acc1_perfect.getBalance() == 16.0); assertion_count++;
    BloodDonation p5(100001, 32, 152.0, "01/01/2022");
    assert(acc1_perfect.addVacationToAccount(&p5) == true && acc1_perfect.getBalance() == 20.0); assertion_count++;
    BloodDonation p6(100001, 32, 152.0, "07/01/2022");
    assert(acc1_perfect.addVacationToAccount(&p6) == true && acc1_perfect.getBalance() == 24.0); assertion_count++;

    VacationAccount acc2_rules(100002);
    assert(acc2_rules.getID() == 100002 && acc2_rules.getBalance() == 0.0); assertion_count++;
    BloodDonation r1(100002, 45, 200.0, "05/10/2023");
    assert(acc2_rules.addVacationToAccount(&r1) == true && acc2_rules.getBalance() == 4.0); assertion_count++;

    BloodDonation r2_same(100002, 45, 200.0, "05/10/2023");
    assert(acc2_rules.addVacationToAccount(&r2_same) == false && acc2_rules.getBalance() == 4.0); assertion_count++;

    BloodDonation r3_soon(100002, 45, 200.0, "06/10/2023");
    assert(acc2_rules.addVacationToAccount(&r3_soon) == false && acc2_rules.getBalance() == 4.0); assertion_count++;
    
    BloodDonation r4_soon(100002, 45, 200.0, "10/10/2023");
    assert(acc2_rules.addVacationToAccount(&r4_soon) == false && acc2_rules.getBalance() == 4.0); assertion_count++;

    BloodDonation r5_valid(100002, 45, 200.0, "11/10/2023");
    assert(acc2_rules.addVacationToAccount(&r5_valid) == true && acc2_rules.getBalance() == 8.0); assertion_count++;

    BloodDonation r6_soon_again(100002, 45, 200.0, "03/10/2024");
    assert(acc2_rules.addVacationToAccount(&r6_soon_again) == false && acc2_rules.getBalance() == 8.0); assertion_count++;
    
    VacationAccount acc3_nightmare(100003);
    assert(acc3_nightmare.getID() == 100003 && acc3_nightmare.getBalance() == 0.0); assertion_count++;
    
    BloodDonation n1_bad_id(123, 40, 150.0, "01/01/2022");
    assert(acc3_nightmare.addVacationToAccount(&n1_bad_id) == false && acc3_nightmare.getBalance() == 0.0); assertion_count++;
    
    BloodDonation n2_bad_age(100003, 100, 150.0, "01/01/2022");
    assert(acc3_nightmare.addVacationToAccount(&n2_bad_age) == false && acc3_nightmare.getBalance() == 0.0); assertion_count++;

    BloodDonation n3_bad_weight(100003, 40, 50.0, "01/01/2022");
    assert(acc3_nightmare.addVacationToAccount(&n3_bad_weight) == false && acc3_nightmare.getBalance() == 0.0); assertion_count++;

    BloodDonation n4_bad_date(100003, 40, 150.0, "01/01/22");
    assert(acc3_nightmare.addVacationToAccount(&n4_bad_date) == false && acc3_nightmare.getBalance() == 0.0); assertion_count++;
    
    BloodDonation n5_null(100003, 40, 150.0, "01/01/2022");
    assert(acc3_nightmare.addVacationToAccount(nullptr) == false && acc3_nightmare.getBalance() == 0.0); assertion_count++;

    BloodDonation n6_valid(100003, 40, 150.0, "01/01/2022");
    assert(acc3_nightmare.addVacationToAccount(&n6_valid) == true && acc3_nightmare.getBalance() == 4.0); assertion_count++;

    VacationAccount acc4_identity(100004);
    assert(acc4_identity.getID() == 100004 && acc4_identity.getBalance() == 0.0); assertion_count++;
    BloodDonation i1_wrong_id(100001, 30, 150.0, "01/01/2023");
    assert(acc4_identity.addVacationToAccount(&i1_wrong_id) == false && acc4_identity.getBalance() == 0.0); assertion_count++;
    BloodDonation i2_wrong_id(100002, 30, 150.0, "02/02/2023");
    assert(acc4_identity.addVacationToAccount(&i2_wrong_id) == false && acc4_identity.getBalance() == 0.0); assertion_count++;
    BloodDonation i3_correct_id(100004, 30, 150.0, "03/03/2023");
    assert(acc4_identity.addVacationToAccount(&i3_correct_id) == true && acc4_identity.getBalance() == 4.0); assertion_count++;
    BloodDonation i4_wrong_again(100003, 30, 150.0, "10/10/2023");
    assert(acc4_identity.addVacationToAccount(&i4_wrong_again) == false && acc4_identity.getBalance() == 4.0); assertion_count++;

    VacationAccount acc_for_copy_test(100005);
    BloodDonation twin_d1(100005, 50, 160.0, "01/15/2020");
    BloodDonation twin_d2(100005, 50, 160.0, "07/15/2020");
    BloodDonation twin_d3(100005, 51, 161.0, "02/15/2021");
    acc_for_copy_test.addVacationToAccount(&twin_d1);
    acc_for_copy_test.addVacationToAccount(&twin_d2);
    acc_for_copy_test.addVacationToAccount(&twin_d3);
    assert(acc_for_copy_test.getBalance() == 12.0); assertion_count++;

    VacationAccount acc_copied_version(acc_for_copy_test);
    assert(acc_copied_version.getID() == 100005); assertion_count++;
    assert(acc_copied_version.getBalance() == 12.0); assertion_count++;

    BloodDonation twin_d4(100005, 51, 161.0, "08/15/2021");
    assert(acc_for_copy_test.addVacationToAccount(&twin_d4) == true); assertion_count++;
    assert(acc_for_copy_test.getBalance() == 16.0); assertion_count++;
    assert(acc_copied_version.getBalance() == 12.0); assertion_count++; 

    BloodDonation twin_d5(100005, 52, 162.0, "09/15/2022");
    assert(acc_copied_version.addVacationToAccount(&twin_d5) == true); assertion_count++;
    assert(acc_copied_version.getBalance() == 16.0); assertion_count++;
    assert(acc_for_copy_test.getBalance() == 16.0); assertion_count++; 
    
    std::cout << assertion_count << "+ assertions passed" << std::endl;

    return 0;
}
