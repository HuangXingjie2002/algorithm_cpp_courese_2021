//
// Created by mushr on 2021/12/1.
//

#ifndef ALGORITHM_CPP_COURESE_2021_DATE_H
#define ALGORITHM_CPP_COURESE_2021_DATE_H


#include <iostream>
#include <ctime>

using std::ostream;
using std::istream;


class Date {
    /**
             namespace std
        {
          using ::clock_t;
          using ::time_t;
          using ::tm;

          using ::clock;
          using ::difftime;
          using ::mktime;
          using ::time;
          using ::asctime;
          using ::ctime;
          using ::gmtime;
          using ::localtime;
          using ::strftime; struct
        } // namespace
     */
private:
    time_t currentTimeStamp;
    struct tm * currentTimeStampStruct{};
public:
    Date() {
        this->currentTimeStamp = time(nullptr);
        this->currentTimeStampStruct = localtime(&this->currentTimeStamp); // 获取当前时间的结构体
    }

    friend ostream& operator<<(ostream &cout, Date &date);
};

ostream& operator<<(ostream &cout, Date &date) {
    cout << date.currentTimeStampStruct->tm_year + 1900 << "/"
         << date.currentTimeStampStruct->tm_mon + 1 << "/" << date.currentTimeStampStruct->tm_mday
         << " " << date.currentTimeStampStruct->tm_hour << ":" << date.currentTimeStampStruct->tm_min
         << ":" << date.currentTimeStampStruct->tm_sec;
    return cout;
}

#endif //ALGORITHM_CPP_COURESE_2021_DATE_H
