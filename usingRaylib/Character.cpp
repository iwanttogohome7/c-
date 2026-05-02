#include "Character.h"

Character::Character(std::string n) : name(n) {} //생성자, 이름 초기화

Character::~Character() {}; //가상 소멸자, 다형성을 위해 필요

// 2. 용의자 클래스 (Suspect) 구현
Suspect::Suspect() : Character("용의자 X") {}
std::string Suspect::speak(const std::string& dialogue) {
    return dialogue;
}
void Suspect::updateAppearance(float erosion) {}

// 3. 여자친구 클래스 (Girlfriend) 구현
Girlfriend::Girlfriend() : Character("유라"), erosion(0.0f) {}
std::string Girlfriend::speak(const std::string& dialogue) {
    if (erosion >= 30.0f) return "..." + dialogue;
    return dialogue;
}
void Girlfriend::updateAppearance(float e) {
    erosion = e;
}