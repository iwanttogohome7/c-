#pragma once
#include "raylib.h"
#include <string>

class Character {
protected:
    std::string name;
    float erosion;
public:
    Character(std::string n);
    virtual ~Character();

    std::string getName() const { return name; }
    void getErosion(float e) { erosion = e; }

    virtual Color getTextColor() = 0;
    virtual std::string getPNG(const std::string keyword) = 0;
};

class Suspect : public Character {
public:
    Suspect();
    Color getTextColor() override;      
    std::string getPNG(const std::string keyword) override;
};

class Girlfriend : public Character {
public:
    Girlfriend();                      
    Color getTextColor() override;      
    std::string getPNG(const std::string keyword) override;
};