#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>



using namespace std;

int main() {

    // constant definitions
    const double    COST_PER_KWH = 0.14440;     // the cost per kWh
    const string    LINE         =
    "------------------------------------------------------------------";
    const int       NUM_MONTHS   = 12; // number of the month

    // variable declarations
    double      min_Energy;        // minimun of kWh Energy
    double      max_Energy;        // maximun of kWh Energy

    double      energy_kWh;        // input number of energy kWh
    double      total_Energy = 0;      // total number of kWh
    double      total_Savings  = 0;     // total Saving kWh every month
    double      avg_Energy = 0;        // average of kWh

    double      annual_AvgEnergy = 0;  // annual average of kWh
    double      annual_AvgSaving = 0;  // annual average of  savingkWh

    int         year;              // input year
    int         month;             // input month
    int         day;               // input the day of every month
    string      month_name;        // name the month Jan to Dec
    double      day_in_month = 0;      // day_in_month
    int         exit_status = 0;   // exit statatus
    int i = 0;                     // month
    int j = 0;                     // day in mont
    double day_in_year = 0;            // day in year


    // read input and update variables

    cout << left << setw(11) << "Month"
         << right << setw(11) << "Min"
         << setw(11) << "Avg"
         << setw(11) << "Max"
         << setw(11) << "Total kWh"
         << setw(11) << "Savings"
         << endl;
    cout << LINE << endl;

    cin >> year >> month >> day >> energy_kWh;

    while (year != 0 && month != 0 && day != 0 && energy_kWh != 0) {

        for (i = 1; i <= NUM_MONTHS; i++) {

        if (i == 2) {

            // February - check for leap year
            day_in_month = (year % 4 == 0 &&
                           (year % 100 != 0 || year % 400 == 0)) ? 29 : 28;
        } else if (i == 4 || i == 6 || i == 9 || i == 11) {
            // April, June, September, November
            day_in_month = 30;

        } else {
            // January, March, May, July, August, October, December
            day_in_month = 31;            }

        day_in_year = day_in_year + day_in_month;

        switch (i) {
            case 1:
                month_name = "January";
                break;
            case 2:
                month_name = "February";
                 break;
            case 3:
                month_name = "March";
                 break;
            case 4:
                month_name = "April";
                 break;
            case 5:
                month_name = "May";
                 break;
            case 6:
                month_name = "June";
                 break;
            case 7:
                month_name = "July";
                 break;
            case 8:
                month_name = "August";
                 break;
            case 9:
                month_name = "September";
                 break;
            case 10:
                month_name = "October";
                 break;
            case 11:
                month_name = "November";
                 break;
            case 12:
                month_name = "December";
                 break;
            }
            // set min and max equal energy
            min_Energy = energy_kWh;
            max_Energy = energy_kWh;

            total_Energy = 0;

            total_Energy += energy_kWh;

                for (j = 1; j < day_in_month; j++) {

                cin >> year >> month >> day >> energy_kWh;

                if (energy_kWh < min_Energy) {
                    min_Energy = energy_kWh;
                    }

                if (energy_kWh > max_Energy) {
                    max_Energy = energy_kWh;
                }
                total_Energy += energy_kWh;

            }

        avg_Energy = total_Energy / day_in_month;
        total_Savings = total_Energy * COST_PER_KWH;

        cout << fixed << setprecision(2);
        cout << left << setw(11) << month_name
             << right << setw(11) << min_Energy
             << setw(11) << avg_Energy
             << setw(11) << max_Energy
             << setw(11) << total_Energy
             << setw(5) << "$ " << setw(6) << total_Savings
             << endl;


            annual_AvgEnergy += total_Energy;
            annual_AvgSaving += total_Savings;

            cin >> year >> month >> day >> energy_kWh;

        }

    }

        cout << LINE << endl;
        cout << fixed << setprecision(2);
        cout << left << setw(35)
             << "Totals: "
             << right << setw(20) << annual_AvgEnergy
             << setw (4)
             << "$" << annual_AvgSaving
             << endl;


    // while (energy_kWh != 0) {

    return exit_status;
}
