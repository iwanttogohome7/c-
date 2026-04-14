#pragma once
#include <string>

//캐릭터 기본 클래스 (메인 캐릭터용)
class Character {
protected:
    std::string name;
public:
    Character(std::string n);
    virtual ~Character();

    // 외부에서 이름을 쓸 수 있게 추가
    std::string getName() const { return name; }
        
	// 침식도에 따른 대사 변화 함수(여자친구에게만 적용 예정)
    virtual std::string speak(const std::string& dialogue) = 0;

	// 외형 업데이트 함수(아스키 아트 추가 시 작업 예정)
    virtual void updateAppearance(float erosion) = 0;
};


// 2. 용의자 클래스 (Suspect) 구현
class Suspect : public Character {
public:
    Suspect();
    std::string speak(const std::string& dialogue) override;
    void updateAppearance(float erosion) override;
};


// 3. 여자친구 클래스 (Girlfriend) 구현
class Girlfriend : public Character {
private:
    float erosion;
public:
    Girlfriend();
    std::string speak(const std::string& dialogue) override;
    void updateAppearance(float erosion) override;
};