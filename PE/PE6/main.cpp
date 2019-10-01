#include <iostream>
#include <vector>

#include "Society.h"

// Name(s): David Skrenta

int main() {
    Society s;
    int cities_count = 1;
    int cities_num_grow = 0;

    while (true) {
      std::string city_name;
      int city_pop;

      std::cout << "Enter cities: Enter (c) to continue" << std::endl;
      std::cout << "City name:" << std::endl;
      std::cin >> city_name;

      if (city_name == "c") {
        break;
      }

      std::cout << "City population:" << std::endl;
      std::cin >> city_pop;

      s.AddCity(cities_count, city_pop, city_name);
      cities_count++;
    }

    std::cout << "How many times would you like to grow the cities?" << std::endl;
    std::cin >> cities_num_grow;

    for (int i = 0; i < cities_num_grow; i++) {
      std::cout << s << std::endl;
      s.GrowCities();
    }
}

