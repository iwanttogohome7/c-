#pragma once
#include "raylib.h"
#include <string>
#include <cstdlib> 
#include <thread> 
#include <chrono> 
#include <iomanip>
#include <vector>
#include <functional>
#include <conio.h> //Windows전용
#include "Character.h"


struct GameScene
{
    std::string speaker;
    std::string gameLine;
    std::string realLine;
    std::string systemMessage;
    std::string options[2];  // 선택지 (비어있으면 출력 안 함)
    float erosionIncrease1 = 0;  // 선택지 1을 선택했을 때 증가할 침식도
	float erosionIncrease2 = 0;  // 선택지 2를 선택했을 때 증가할 침식도
};

class GameManager {
private:
    Font font;
    float erosion;           // 침식도
    int interrogationCount;  // 취조 횟수
    Character* suspect; // 용의자 캐릭터 포인터
    Character* girlfriend; // 여자친구 캐릭터 포인터
    std::vector<std::string> gameLog; // 게임 대사 로그
	std::vector<std::string> realLog; // 현실 대사 로그
    std::vector<std::function<void(std::vector<GameScene>&)>> ChapterList; //챕터 함수들을 담을 함수 배열

public:
    // 생성자에서 캐릭터 객체 초기화
    GameManager();
    // 소멸자에서 캐릭터 객체 메모리 해제
    ~GameManager();

    //GameManager
    void addScene(std::vector<GameScene>& script, std::string name, std::string gameLine, std::string realLine, std::string systemLine = "", std::string opt1 = "", std::string opt2 = "", float erosion1 = 0.0f, float erosion2 = 0.0f);
    void addGameLog(std::string name, std::string text);
    void addRealLog(std::string name, std::string text);
    void playAnimation(); // 애니메이션 재생 함수 (오프닝 -> 게임)
	void renderFrame(const GameScene& scene); // 기본 틀 그리기 함수
	int playScene(std::vector<GameScene>& script);
    void titleScreen();
    void OpeningScene();
    void run();
    void checkEnding();

    //시나리오 데이터
	void Opening(std::vector<GameScene>& script);
    void Chapter1(std::vector<GameScene>& script);
    void Chapter2(std::vector<GameScene>& script);
    void Chapter3(std::vector<GameScene>& script);
    void Chapter4(std::vector<GameScene>& script);
    void Chapter5(std::vector<GameScene>& script);
    void Chapter6(std::vector<GameScene>& script);
    void Chapter7(std::vector<GameScene>& script);
    void Chapter8(std::vector<GameScene>& script);
    void Chapter9(std::vector<GameScene>& script);
    void Chapter10(std::vector<GameScene>& script);
};