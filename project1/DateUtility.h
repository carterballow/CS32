#ifndef DATEUTILITY_H
#define DATEUTILITY_H

#include <string>

class DateUtility {
public:
    static bool isSixMonthsApart(const std::string& date1, const std::string& date2);
    static bool isSameDay(const std::string& d1, const std::string& d2);
};

#endif
