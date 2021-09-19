#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

struct City {

    string name;
    long population;
    double cost;

};

// Assume each country has at least 1 city
struct Country {

    string name;
    vector<City> cities;

};

struct Tours {

    string title;
    vector<Country> countries;

};

void ruler() {

    cout << "\n1234567890123456789012345678901234567890123456789012345678901234567890\n" << endl;

}

int main() {

    Tours tours {
        "Tour Ticket Prices From Miami",
        {
            {
                "Colombia",{
                    {"Bogota" , 8778000 , 400.98},
                    {"Cali" , 2401000 , 424.12},
                    {"Medellin" , 2464000 , 350.98},
                    {"Cartagena" , 972000 , 345.34},
                },
            },
            {
                "Brazil",{
                    {"Rio De Janeiro" , 13500000 , 567.45},
                    {"Sao Paulo" , 113100000 , 975.45},
                    {"Salvador" , 18234000 , 855.99},
                },
            },
            {
                "Chile",{
                    {"Valdivia" , 2600000 , 569.12},
                    {"Santiago" , 70400000 , 520.00},
                },
            },

            {
                "Argentina",{
                    {"Buenos Aires" , 3010000 , 723.77},
                },
            },
        }
    };

    const int totalWidth {70};
    const int countryWidth {20};
    const int cityWidth {20};
    const int populationWidth {15};
    const int costWidth {15};

    // display the report title header centered in width of total width
//    ruler();
    int titleLenght = tours.title.length();
    cout << "\n" << setw((totalWidth - titleLenght) / 2) << "" << tours.title << endl;
    cout << setw(totalWidth) << setfill('-') << "" << endl;
    cout << setfill(' ');
    cout << setw(countryWidth) << left << "Country"
         << setw(cityWidth) << left << "City"
         << setw(populationWidth) << right << "Population"
         << setw(costWidth) << right << "Cost"
         << endl;

    cout << setw(totalWidth) << setfill('-') << "" << endl;     // display totalWidth dashes

    cout << setfill(' ');       // reset setfill to blank spaces
    cout << setprecision(2) << fixed;       // for displaying the cost with 2 decimal digits

    for (Country country : tours.countries) {

        for (size_t i = 0 ; i < country.cities.size() ; i++) {

            cout << setw(countryWidth) << left << ((i == 0) ? country.name : "")
                 << setw(cityWidth) << left << country.cities.at(i).name
                 << setw(populationWidth) << right << country.cities.at(i).population
                 << setw(costWidth) << right << country.cities.at(i).cost
                 << endl;

        }

        cout << setw(totalWidth) << setfill('-') << "" << endl;
        cout << setfill(' ');

    }

    cout << endl << endl;

    getch();
    return 0;
}
