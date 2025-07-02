
#include "DateUtility.h"
#include <algorithm> // Required for swap
#include <cmath>

bool DateUtility::isSixMonthsApart(const std::string& date1, const std::string& date2) {
    if (!isValidDates(date1, date2)) {
        return false;
    }
    int arr1[3] = {0, 0, 0}; // [month, day, year]
    int counter1 = 0;
    for (char c : date1) {
        if (c == '/') { counter1++; continue; }
        arr1[counter1] = arr1[counter1] * 10 + (c - '0');
    }

    int arr2[3] = {0, 0, 0};
    int counter2 = 0;
    for (char c : date2) {
        if (c == '/') { counter2++; continue; }
        arr2[counter2] = arr2[counter2] * 10 + (c - '0');
    }


    int totalMonths1 = arr1[2] * 12 + arr1[0];
    int totalMonths2 = arr2[2] * 12 + arr2[0];

    // Return true if the absolute difference is 6 months or more.
    return std::abs(totalMonths1 - totalMonths2) >= 6;
}

bool DateUtility::isSameDay(const std::string& d1, const std::string& d2) {
    if (!isValidDates(d1, d2)) {
        return false;
    }
    return d1 == d2;
}

bool DateUtility::isNum(char c) {
    return c >= '0' && c <= '9';
}
bool DateUtility::isValidDate(const std::string& date) {
    //should be 10 characters, no white space or nothing
    if (date.length() != 10 || date[2] != '/' || date[5] != '/') {
        return false;
    }

    // check that all other characters are numbers
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            continue; // Skip the slashes we already checked.
        }
        if (!isNum(date[i])) {
            return false;
        }
    }

    // use stoi because the prof said its fine
    try {
        int month = std::stoi(date.substr(0, 2));
        int day   = std::stoi(date.substr(3, 2));
        int year  = std::stoi(date.substr(6, 4));

        // logic
        if (month < 1 || month > 12 || day < 1 || day > 31 || year < 1900 || year > 2100) {
            return false;
        }
    } catch (const std::exception& e) {
        // if stoi fails its invalid
        return false;
    }
    return true;
}
bool DateUtility::isValidDates(const std::string& d1, const std::string& d2) {
    // validate 2 dates for the functions above
    return isValidDate(d1) && isValidDate(d2);
}


