#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;



double days_in_month(int month){

	if(month == 2){
		time_t now = time(0); 
		tm *ltm = localtime(&now);
		int year = ltm->tm_year + 1900;
		if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			return 29;
		return 28;
	}
	else if((month % 2 == 0 && month < 7) || ( month % 2 != 0 && month > 7))
		return 30;

	return 31;
}

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

double getML(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	double month_days = days_in_month(ltm->tm_mon + 1);
	return (ltm->tm_mday / month_days) * 100;
}

double getWL(){
	time_t now = time(0);
	tm *ltm = localtime(&now);
	//return (double)ltm->tm_wday;
	return (((double)ltm->tm_wday + 1)/7) * 100;
}

void display(double per){

	cout <<  "\033[1;31m" << per << "%" << "\033[0m";
	for(int i = 0; i < 85; i++)
		cout << " ";
        cout <<  "\033[1;32m" << 100 - per << "%" << "\033[0m";
	cout << endl;
        for(int i = 0; i <= 100; i++){

                if( i < per)
                        cout << "\033[101;31m ";
                else
                        cout << "\033[102;32m ";
        }
        cout << "\033[0m";
	cout << endl;

}

int main() {

	display(getYL());
	display(getML());
	display(getWL());

        return 0;
}

