#include <iostream>
#include <string>
#include <map>

#include "Society.h"

bool City::IsBig() const {
    if (population_ > 100000) {
        return true;
    } 
    return false;
}

void City::Grow(int const num_people) {
    if (num_people >= 0) {
        percent_change_ = (1.0 * num_people) / population_;
        population_ += num_people;
    }
}

void City::Shrink(int const num_people) {
    if (num_people >= 0) {
        population_ -= num_people;
    }
}

void Society::GrowCities() {
    City * biggest = cities_.at(1);
    
    for (auto const& x: cities_) {
        City * c = x.second;

        if (c->get_population() > biggest->get_population()) {
            biggest = c;
        }

        if (c->IsBig()) {
            int prev_small = c->get_population();
            double ratio = (1.0 * c->get_population()) / biggest->get_population();
            c->Grow((int) ratio * c->get_population());
            c->Shrink((int) c->get_population() * .1);
            double percent_change_small = (1.0 * c->get_population() - prev_small) / prev_small;
            c->set_percent_change(percent_change_small);
        } 
        else {
            int prev = c->get_population();
            double ratio = (1.0 * c->get_population()) / biggest->get_population();
            c->Grow((int) ratio * .3 * c->get_population());
            c->Shrink((int) c->get_population() * .1);
            double percent_change = (1.0 * c->get_population() - prev) / prev;
            c->set_percent_change(percent_change);
        }
    }
}

std::ostream& operator<<(std::ostream &os, const City &c) {
    os << c.name_ << ": " << c.population_  << " (" << c.percent_change_ << "% change)";
    return os;
}

std::ostream& operator<<(std::ostream &os, const Society &s) {
    for (auto const& x : s.cities_) {
        os << *(x.second) << std::endl;
    }
    return os;
}
