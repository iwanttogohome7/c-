#include "Character.h"

Character::Character(std::string n) : name(n), erosion(0.0f) {} //생성자, 이름 초기화

Character::~Character() {}; //가상 소멸자, 다형성을 위해 필요

// 2. 용의자 클래스 (Suspect) 구현
Suspect::Suspect() : Character("살인마") {}
Color Suspect::getTextColor() {
    return WHITE; // 용의자는 항상 흰색
}
std::string Suspect::getPNG(const std::string keyword) {
    return "";
}

// 3. 여자친구 클래스 (Girlfriend) 구현
Girlfriend::Girlfriend() : Character("유라") {}
Color Girlfriend::getTextColor() {
    return WHITE;
}
std::string Girlfriend::getPNG(const std::string keyword) {
	// 키워드에 따른 이미지(현재는 임시 이미지 파일명)
    if(keyword == "오프닝") return "opening.png";

	// 침식도에 따른 이미지(현재는 임시 이미지 파일명)
    if(keyword == "침식도")
    {
        if (erosion >= 100.0f) return "bad.png";
        if (erosion >= 30.0f) return "normal.png";
        else return "happy.png";
    }

    return "";
}