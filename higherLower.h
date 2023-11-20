#include <vector>
#include <iostream>



using namespace std;



class higherLower
{
public:
    vector<country> countries;

    higherLower(const Json::Value &countryJSON);

    // get random country
    country getCountry();
    void menu();

    country getCurrent();
    void setCurrent(country newCountry);

    void removeCountry(country deleted);

    // operators
    friend bool operator<(country left, country right);
    friend bool operator>(country left, country right);

    int getPoints();
    void incPoints();

private:
    country currentCountry;
    int points;
};
