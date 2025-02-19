#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class YearGauge{
        private:
                string dateYearStart, dateCurrent;
                double diff, ylPer, noOfSecondsInYear, days;

                string getSystemDate() {
                        time_t now = time(0);
                        tm* ltm = localtime(&now);
                        stringstream ss;
                        ss << setw(4) << setfill('0') << ltm->tm_year + 1900 << "-";
                        ss << setw(2) << setfill('0') << ltm->tm_mon + 1 << "-";
                        ss << setw(2) << setfill('0') << ltm->tm_mday;
                        return ss.str();
                }

                string yearStartDate(){
                        time_t now = time(0);
                        tm* ltm = localtime(&now);
                        stringstream ss;
                        ss << setw(4) << setfill('0') << ltm->tm_year + 1900 << "-";
                        ss << setw(2) << setfill('0') << 1 << "-";
                        ss << setw(2) << setfill('0') << 1;
                        return ss.str();
                }

                double getSecondsInCurrentYear(){
                        time_t now = time(0);
                        tm* ltm = localtime(&now);
                        int year = ltm->tm_year + 1900;
                        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                                return 31622400;
                        else
                                return 31536000;
                }
        public:
                YearGauge(){
                        dateYearStart = yearStartDate();
                        dateCurrent = getSystemDate();

                        noOfSecondsInYear = getSecondsInCurrentYear();

                        struct tm tm1 = {};
                        istringstream ss1(dateYearStart);
                        ss1 >> get_time(&tm1, "%Y-%m-%d");

                        struct tm tm2 = {};
                        istringstream ss2(dateCurrent);
                        ss2 >> get_time(&tm2, "%Y-%m-%d");

                        time_t t1 = mktime(&tm1);
                        time_t t2 = mktime(&tm2);

                        diff = difftime(t2, t1);
                        ylPer = (diff/noOfSecondsInYear) * 100;
                }

                double getPassedPercent(){
                        return ylPer;
                }

                double getPassedDays(){
                        days = diff / (60 * 60 * 24);
                        return days;
                }

};


int main() {

        YearGauge yg;
        double ylPer = yg.getPassedPercent();
        cout <<  "\033[1;31m" << ylPer << "%" << "\033[0m";
        cout << " " << "[";
        for(int i = 0; i <= 100; i++){

                if( i < ylPer)
                        cout << "\033[31m#";
                else
                        cout << "\033[32m.";
        }
        cout << "\033[0m";
        cout << "]";
        cout <<  "\033[1;32m" << 100 - ylPer << "%" << "\033[0m";
	cout << endl;

        return 0;
}

