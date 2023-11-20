#include "higherLower.h"

higherLower::higherLower(const Json::Value &countryJSON)
{

    // convert the json into a vector / initalize vector
    for (int i = 0; i < countryJSON.size(); i++)
    {
        country tempCountry;
        tempCountry.name = countryJSON[i]["name"].asString();
        tempCountry.capital = countryJSON[i]["capital"].asString();
        tempCountry.population = countryJSON[i]["population"].asInt();
        // not sure why area doesn't work
        //  tempCountry.area = countryJSON[i]["area"].asString;

        countries.push_back(tempCountry);
    }
}

country higherLower::getCountry()
{

    int randNum = rand() % countries.size();

    country newCountry = countries[randNum];

    return newCountry;
}

void higherLower::removeCountry(country deleted)
{
    for (int i = 0; i < countries.size(); i++)
    {
        if (countries[i].name == deleted.name)
        {
            countries.erase(countries.begin() + i);
            return;
        }
    }
}

void higherLower::menu()
{
    cout << "1. Higher" << endl;
    cout << "2. Lower" << endl;
    cout << "3. Exit" << endl;

}


country higherLower::getCurrent()
{
    return currentCountry;
}

void higherLower::setCurrent(country newCountry)
{
    currentCountry = newCountry;
}


int higherLower::getPoints(){
    return points;
}

void higherLower::incPoints(){
    points++;
}

bool operator>(country left, country right){
    if(left.population > right.population)
    {
        return true;
    }
    return false;
}

bool operator<(country left, country right){
    if(left.population < right.population)
    {
        return true;
    }
    return false;
}


