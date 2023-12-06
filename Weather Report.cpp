#include <iostream>
#include <iomanip>
#include <vector>

class WeatherReport {
private:
    int day_of_month;
    int hightemp;
    int lowtemp;
    double amount_rain;
    double amount_snow;

public:
    WeatherReport() : day_of_month(99), hightemp(999), lowtemp(-999), amount_rain(0), amount_snow(0) {}

    void enterData() {
        std::cout << "Enter day of the month: ";
        std::cin >> day_of_month;

        std::cout << "Enter high temperature: ";
        std::cin >> hightemp;

        std::cout << "Enter low temperature: ";
        std::cin >> lowtemp;

        std::cout << "Enter amount of rain: ";
        std::cin >> amount_rain;

        std::cout << "Enter amount of snow: ";
        std::cin >> amount_snow;
    }

    void displayReport() const {
        std::cout << std::setw(15) << "Day" << std::setw(15) << "High Temp" << std::setw(15) << "Low Temp"
                  << std::setw(15) << "Rain" << std::setw(15) << "Snow" << std::endl;

        std::cout << std::setw(15) << day_of_month << std::setw(15) << hightemp << std::setw(15) << lowtemp
                  << std::setw(15) << amount_rain << std::setw(15) << amount_snow << std::endl;
    }
};

int main() {
    std::vector<WeatherReport> monthlyReport(30); // Assuming a month has 30 days

    int choice;
    do {
        std::cout << "\nMenu:\n1. Enter Data\n2. Display Report\n3. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                int day;
                std::cout << "Enter day of the month (1-30): ";
                std::cin >> day;
                if (day >= 1 && day <= 30) {
                    monthlyReport[day - 1].enterData();
                } else {
                    std::cout << "Invalid day. Please enter a day between 1 and 30.\n";
                }
                break;

            case 2:
                std::cout << "\nMonthly Weather Report:\n";
                for (const auto& report : monthlyReport) {
                    report.displayReport();
                }
                break;

            case 3:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Please enter a valid option.\n";
        }

    } while (choice != 3);

    return 0;
}
