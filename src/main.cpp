#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

double getYL(){
	time_t now = time(0);
	time_t currentTime, yearStartTime;

	tm* ltm = localtime(&now);
	ltm->tm_year += 1900;

	currentTime = mktime(ltm);

	ltm->tm_sec = 0;
	ltm->tm_min = 0;
	ltm->tm_hour = 0;
	ltm->tm_mday = 1;
	ltm->tm_mon = 0;
	ltm->tm_wday = 0;
	ltm->tm_yday = 0;

	yearStartTime = mktime(ltm);

	int year = ltm->tm_year;
	int noOfSecondsInYear = 31536000;
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
		noOfSecondsInYear = 31622400;

	double diff = difftime(currentTime, yearStartTime);
	return (diff/noOfSecondsInYear) * 100;

}

int main() {

	double ylPer = getYL();
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

