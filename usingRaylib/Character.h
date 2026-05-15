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

    virtual std::string speak(const std::string& dialogue) = 0;
    virtual Color getTextColor() = 0;
    virtual std::string getPNG() = 0;
};

class Suspect : public Character {
public:
    Suspect();
    std::string speak(const std::string& dialogue) override;
    Color getTextColor() override;      
    std::string getPNG() override;      
};

class Girlfriend : public Character {
public:
    Girlfriend();                       // erosion 중복 제거
    std::string speak(const std::string& dialogue) override;
    Color getTextColor() override;      
    std::string getPNG() override;      
};