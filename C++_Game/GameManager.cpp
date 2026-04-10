#pragma once
#include <iostream>
#include <string>
#include <cstdlib> 
#include <thread> 
#include <chrono> 
#include <iomanip>
#include <vector>
#include <conio.h> //Windows전용
#include <Windows.h> //Windows전용
#include "Character.h"
#include "GameManager.h"

int TOTAL_WIDTH = 155;

//덮어쓰기용
void GameManager::goToXY(int x, int y) {
    HANDLE hOut;
    COORD Cur;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(hOut, Cur);
}

// 콘솔 창 설정
void GameManager::initConsole() {
    // [8;세로;가로t] 콘솔 창 크기 조절
    std::cout << "\x1b[8;45;180t]";

    // 커서 숨기기 (깜빡임 방지)
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(hConsole, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cursorInfo);

    HWND hWnd = GetConsoleWindow();
    if (hWnd) {
        MoveWindow(hWnd, 100, 100, 1280, 800, TRUE);
    }
}




//생성자
GameManager::GameManager() : erosion(0.0f), interrogationCount(1) {
	suspect = new Suspect();
	girlfriend = new Girlfriend();

	// ChapterList에 각 챕터 함수 저장
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter1(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter2(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter3(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter4(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter5(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter6(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter7(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter8(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter9(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter10(s); });
}
//소멸자
GameManager::~GameManager() {
	delete suspect;
	delete girlfriend;
}

void GameManager::addScene(std::vector<GameScene>& script, std::string name, std::string gameLine, std::string realLine, std::string systemLine, std::string opt1, std::string opt2, float erosion1, float erosion2) 
{
	GameScene temp;
	temp.speaker = name;
	temp.gameLine = gameLine;
	temp.realLine = realLine;
	temp.systemMessage = systemLine;
	temp.options[0] = opt1;
	temp.options[1] = opt2;
	temp.erosionIncrease1 = erosion1;
	temp.erosionIncrease2 = erosion2;
    

	script.push_back(temp);
}

void GameManager::addGameLog(std::string name, std::string text)
{
	if (text.empty()) return;
	if (name.empty())
	{
		gameLog.push_back(text);
	}
	else
	{
		gameLog.push_back("[" + name + "] " + text);
	}
}	
void GameManager::addRealLog(std::string name, std::string text)
{
	if (text.empty()) return;
	if (name.empty())
	{
		realLog.push_back(text);
	}
	else
	{
		realLog.push_back("[" + name + "] " + text);
	}
}

//텍스트 중앙 정렬
void GameManager::printCenterInBox(std::string text, int width) {
    int len = text.length();
    int space = (width - len) / 2;
    if (space > 0) std::cout << std::string(space, ' '); // 왼쪽 공백 채우기
    std::cout << text;
    if (space > 0) std::cout << std::string(width - len - space, ' '); // 오른쪽 공백 채우기
}

// 화면 그리기
void GameManager::renderFrame(const GameScene& scene) {
    // 이전 화면 덮어쓰기
	goToXY(0, 0);

    int totalWidth = 155;
    int halfWidth = totalWidth / 2;

	// UI 상단 영역: 취조 횟수와 침식도 표시
    std::string leftTop = "[" + std::to_string(interrogationCount) + "번째 취조]";
    std::string rightTop;
    if(erosion < 10.0f) rightTop = "[Sync Error : " + std::to_string(erosion).substr(0, 4) + "%]";
    else if(erosion < 100.0f) rightTop = "[Sync Error : " + std::to_string(erosion).substr(0, 5) + "%]";
    else rightTop = "[Sync Error : " + std::to_string(erosion).substr(0, 6) + "%]";

    std::cout << std::setfill('=') << std::setw(totalWidth) << "" << std::endl;
    std::cout << std::setfill(' ');

    printCenterInBox(leftTop, halfWidth - 1);
    std::cout << "|"; // 중앙 구분선
    printCenterInBox(rightTop, halfWidth);
    std::cout << std::endl;

    std::cout << std::setfill('-') << std::setw(totalWidth) << "" << std::endl;
    std::cout << std::setfill(' '); 

	// UI 중앙 영역: 왼쪽은 게임 대사, 오른쪽은 현실 대사
    int maxLines = 30;
    for (int i = 0; i < maxLines; i++) {
        std::string leftContent = (i < gameLog.size()) ? gameLog[i] : "";
        std::string rightContent = (i < realLog.size()) ? realLog[i] : "";

        if (i < gameLog.size()) {
            leftContent = gameLog[i];
        }
        if (i < realLog.size()) {
            rightContent = realLog[i];
        }

        std::cout << std::left << std::setw(halfWidth - 1) << leftContent << "| ";
        std::cout << std::left << std::setw(halfWidth - 1) << rightContent << std::endl;
    }

	// 4. UI 하단 영역: 시스템 메시지와 선택지
    std::cout << std::setfill('=') << std::setw(totalWidth) << "" << std::endl;
    std::cout << std::setfill(' ');

    std::cout << "[시스템 메시지]" << std::endl;
    std::cout << std::left << std::setw(totalWidth) << scene.systemMessage << std::endl;
    std::cout << std::setfill('-') << std::setw(totalWidth) << "" << std::endl;
	std::cout << std::setfill(' ');

    if (scene.options[0].empty())
    {
        std::cout << std::left << std::setw(totalWidth) << "계속하려면 아무 키를 누르세요..." << std::endl;
        std::cout << std::left << std::setw(totalWidth) << "" << std::endl;
        std::cout << std::setfill('-') << std::setw(totalWidth) << "" << std::endl;
        std::cout << std::setfill(' ') << std::setw(totalWidth) << " ";
    }
    else
    {
		std::string opt1 = "1. " + scene.options[0];
		std::string opt2 = "2. " + scene.options[1];
        std::cout << std::left << std::setw(totalWidth) << opt1 << std::endl;
        if (!scene.options[1].empty()) std::cout << std::left << std::setw(totalWidth) << opt2 << std::endl;
        std::cout << std::setfill('-') << std::setw(totalWidth) << "" << std::endl;
    }
}  

int GameManager::playScene(std::vector<GameScene>& script) {
    while (_kbhit()) _getch();

	int choice = 0;

    for (int i = 0; i < script.size(); i++) {
        GameScene& s = script[i];
        //게임 대사가 있을 때만 왼쪽에 추가
        if (!s.gameLine.empty()) {
            addGameLog(s.speaker, s.gameLine);
        }
        //현실 대사가 있을 때만 오른쪽에 추가
        if (!s.realLine.empty()) {
            addRealLog(s.speaker, s.realLine);
        }
   
        renderFrame(s);

        if (s.options[0].empty()) {
            _getch();
        }
        else {
            std::cout << "입력(선택지 번호 입력 후 Enter): ";
            std::cin >> choice;
            std::cin.ignore(1000, '\n');
			if(choice == 1) erosion += s.erosionIncrease1;
			else if (choice == 2) erosion += s.erosionIncrease2;
            s.options[0] = s.options[1] = "";
        }
        if (erosion >= 100.0f)
        {
            erosion = 100.0f;
            break;
        }
    }
    return choice;
}

// 엔딩 판별
void GameManager::checkEnding() 
{
    if (erosion < 30.0f) 
    {
        std::cout << ">> 해피 엔딩: 연결 해제 성공" << std::endl;
    }
    else if (erosion < 100.0f) 
    {
        std::cout << ">> 노말 엔딩: ~~" << std::endl;
    }
    else 
    {
        std::cout << ">> 배드 엔딩: Connection Established... 게임 오버" << std::endl;
    }
}

// 메인 게임 루프
void GameManager::run() {
	openingConsole();
	printf("게임이 시작됩니다...\n");
    std::string playerName;
	std::cout << "이름을 입력해주세요: ";
	std::cin >> playerName;

	initConsole();
    std::vector<GameScene> script;

    for (int i = 0; i < ChapterList.size(); i++)
    {
		gameLog.clear();
		realLog.clear();
		script.clear();
        ChapterList[i](script);
		interrogationCount++;
        if (erosion >= 100.0f)
        {
            break; // 침식도가 100% 이상이면 즉시 종료
        }
    }


	checkEnding();
}

