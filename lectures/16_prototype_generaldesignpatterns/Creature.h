#ifndef _CREATURE_H_
#define _CREATURE_H_


class Creature {
public:
    Creature(int age): age_(age)
    {
        std::vector<Disease *> tmp;
        this->diseases_ = tmp;
    }

    int get_age() const { return age_; };
    
    void age(int years) { age_ += years; };

    std::vector<Disease *> get_diseases() const {return diseases_; }; 

    void Spread(Creature * c2);
    void Infect(Disease * d) { diseases_.push_back(d); };

    friend std::ostream& operator<<(std::ostream &os, const Creature &d);

    // 1) Create a virtual Creature * Clone() method.
    // When a creature is cloned, the clone starts at age 0
    // Diseases that are hereditary should be inherited.
    virtual Creature * Clone();

private:
    int age_;
    std::vector<Disease *> diseases_;
};


// 2) Create 1 subclass of Creature. For this subclass,
// make its cloning behavior slightly different.
// For instance, some Cloned creatures might also inherit non-hereditary diseases.
// It's up to you!

// when you implement your subclass, make sure to call the Creature constructor in your subclass' constructor

class Subclass : public Creature {
public:
    
    // Note that we call the base class' constructor
    // as the first thing in the initialization list.
    // we do NOT make a new age_ or diseases_ field!
    Subclass(int age): Creature(age) {
    } 

    // function definition of Clone() must exactly match the base class!
    Creature * Clone();
};



// 3) In your main.cpp, instantiate your subclass. (the rest of the work for this
// part of the exercise will happen in main.)

#endif // _CREATURE_H_
