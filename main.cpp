#include <iostream>
#include <ctime>
#include <limits>
#include <cstdio>
#include <jsoncpp/json/json.h>
// https://linux.tips/programming/how-to-install-and-use-json-cpp-library-on-ubuntu-linux-os

using namespace std;

struct country
{
  string name;
  string capital;
  int population;
  float area;
};

int main()
{

  // initialize country vector
  Json::Value countryJSON;
  cin >> countryJSON;
  // higherLower game(countryJSON);

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  // convert json to c++ vector
  country temp;
  vector<country> countries;
  for (int i = 0; i < countryJSON.size(); i++)
  {

    temp.name = countryJSON[i]["name"].asString();
    temp.capital = countryJSON[i]["capital"].asString();
    temp.population = countryJSON[i]["population"].asInt();
    // not sure why area doesn't work
    //  tempCountry.area = countryJSON[i]["area"].asString;
    countries.push_back(temp);
  }

  vector<country> countries1 = countries;
  vector<country> countries2 = countries;

  // bubble sort
  for (int i = 0; i < countries.size(); i++)
  {

    for (int j = 0; j < countries.size() - 1; j++)
    {

      // swap
      if (countries[j].population > countries[j + 1].population)
      {
        temp.population = countries[j].population;
        countries[j].population = countries[j + 1].population;
        countries[j + 1].population = temp.population;
      }
    }
  }

  // selection sort
  int minIndex = 0;

  for (int i = 0; i < countries1.size() - 1; i++)
  {
    minIndex = i;
    for (int j = i + 1; j < countries1.size(); j++)
    {
      if (countries1[j].population < countries1[minIndex].population)
      {
        minIndex = j;
      }
    }
    temp.population = countries1[i].population;
    countries1[i].population = countries1[minIndex].population;
    countries1[minIndex].population = temp.population;
  }

  // insertion sort
  int j;

  for (int i = 1; i < countries2.size(); i++)
  {
    // move item back until it's in the right place
    j = i - 1;
    temp.population = countries2[i].population;
    while ((j >= 0) && (temp.population < countries2[j].population))
    {
      countries2[j + 1].population = countries2[j].population;
      j--;
    }
    countries2[j + 1].population = temp.population;
  }

  // printing out country arrays to check if sorts worked

  for (country temp : countries)
  {
    cout << temp.population << " ";
  }

  cout << endl;

  for (country temp : countries1)
  {
    cout << temp.population << " ";
  }

  cout << endl;

  for (country temp : countries2)
  {
    cout << temp.population << " ";
  }

  /*
  
  Currently unused code for higher lower game 
  
  */

  // country myCountry = game.getCountry();
  // cout << myCountry.name << endl;

  // cout << "Welcome to higher and lower (with countries)!" << endl;

  // string choice;
  // // get two random countries at start of the game
  // country randomCountry = game.getCountry();
  // country currentCountry = game.getCountry();
  // game.setCurrent(currentCountry);
  // // need to validate this
  // getline(cin, choice);
  // cout << choice << endl;
  // cout << choice.length() << endl;

  // while (choice != 3)
  // {
  //     game.menu();

  //     cout << "Is " << currentCountry.name << "'s population higher or lower than " << randomCountry.name << endl;
  //     cin >> choice;
  //     switch (choice)
  //     {
  //     case 1:
  //         // rightside is more than left
  //         if (currentCountry.population > randomCountry.population)
  //         {
  //             cout << "CORRECT!";
  //             game.incPoints();
  //             game.removeCountry(currentCountry);
  //             currentCountry = randomCountry;
  //             randomCountry = game.getCountry();
  //         }
  //         else
  //         {
  //             cout << "WRONG YOU LOSE!";
  //             exit(1);
  //         }
  //         break;
  //     case 2:
  //         if (currentCountry.population < randomCountry.population)
  //         {
  //             cout << "CORRECT!";
  //             game.incPoints();
  //             game.removeCountry(currentCountry);
  //             currentCountry = randomCountry;
  //             randomCountry = game.getCountry();
  //         }
  //         else
  //         {
  //             cout << "WRONG YOU LOSE!";
  //             exit(1);
  //         }
  //         break;
  //     case 3:
  //         break;
  //     }
  // }
  // cout << ""
  // high low game, sort algorithms
  // cout << "1."

  // has hints hints are just the area of the country

  return 0;
}
