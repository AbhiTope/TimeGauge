#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class YearGauge{
        private:
                string dateYearStart, dateCurrent;
                double diff, ylPer, noOfSecondsInYear, days;

                time_t getSystemDate() {
                        time_t result = time(0);
                        tm* ltm = localtime(&result);
			ltm->tm_year += 1900;
			result = mktime(ltm);
			return result;
                }

                time_t yearStartDate(){
                        time_t result = time(0);
                        tm* ltm = localtime(&result);
			ltm->tm_year += 1900;
			ltm->tm_sec = 0;
			ltm->tm_min = 0;
			ltm->tm_hour = 0;
			ltm->tm_mday = 1;
			ltm->tm_mon = 0;
			ltm->tm_wday = 0;
			ltm->tm_yday = 0;
			result = mktime(ltm);
                        return result;
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

                        time_t ysd = yearStartDate();
                        time_t cd = getSystemDate();

                        diff = difftime(cd, ysd);
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

