#include "raylib.h"
#include <iostream>
#include <string>
#include <cstdlib> 
#include <thread> 
#include <chrono> 
#include <iomanip>
#include <vector>
#include "Character.h"
#include "GameManager.h"

int TOTAL_WIDTH = 155;






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

void GameManager::titleScreen() {
    while (!WindowShouldClose()) {
        int screenW = GetScreenWidth();
        int screenH = GetScreenHeight();
        BeginDrawing();
        ClearBackground(BLACK);
        std::string title = "싱 크";
		std::string start = "Press SPACE or ENTER to Start";

		DrawRectangleLines(480, 1, 960, 521, GRAY);
        DrawTextEx(font, title.c_str(), {500, 5}, 500, 1, WHITE);

        DrawRectangleLines(240, 521, 1500, 200, GRAY);
        DrawTextEx(font, start.c_str(), { 240, 525 }, 145, 1, WHITE);

		EndDrawing();

        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER)) {
            break;
        }
    }
}

void GameManager::OpeningScene() {
    // 이미지 로드 (미리 준비된 여자친구 이미지)
    Texture2D girlfriendImg = LoadTexture("picture.png");
    

    std::vector<GameScene> openingTexts;
    Opening(openingTexts);

    int i = 0;

    while (!WindowShouldClose()) {
        int screenW = GetScreenWidth();
        int screenH = GetScreenHeight();

        BeginDrawing();
        ClearBackground(BLACK);

        // ── 배경 (나중에 배경 이미지로 교체 가능) ──
        //DrawRectangle(0, 0, screenW, screenH, { 20, 20, 30, 255 });

        // ── 캐릭터 이미지 (화면 중앙) ──
        float imgScale = (float)(screenH * 0.8f) / girlfriendImg.height;
        int imgW = girlfriendImg.width * imgScale;
        int imgH = girlfriendImg.height * imgScale;
        int imgX = (screenW - imgW) / 2;
        int imgY = screenH - imgH - 120; // 대사창 위에 위치
        DrawTextureEx(girlfriendImg, { (float)imgX, (float)imgY }, 0, imgScale, WHITE);

        // ── 하단 대사창 ──
        int boxH = 200;
        int boxY = screenH - boxH - 1;

        // 대사창 배경 (반투명)
        DrawRectangle(0, boxY, screenW, boxH, { 0, 0, 0, 180 });
        DrawRectangleLines(1, boxY, screenW-1, boxH, GRAY);

        if (i < (int)openingTexts.size()) {
            GameScene& s = openingTexts[i];

            // 화자 이름
            if (!s.speaker.empty()) {
                DrawRectangle(20, boxY - 40, 200, 40, { 0, 0, 0, 200 });
                DrawRectangleLines(20, boxY - 40, 200, 40, GRAY);
                int nameW = MeasureTextEx(font, s.speaker.c_str(), 32, 1).x;
                DrawTextEx(font, s.speaker.c_str(), { (float)(20 + (200 - nameW) / 2), (float)(boxY - 35) }, 32, 1, WHITE);
            }

            // 대사 내용
            std::string line = "";
            if (!s.realLine.empty()) line = s.realLine;
            else if (!s.gameLine.empty()) line = s.gameLine;
            else if (!s.systemMessage.empty()) line = s.systemMessage;

            DrawTextEx(font, line.c_str(), { 30, (float)(boxY + 20) }, 32, 1, WHITE);
        }
        else {
            // 마지막: 동기화 메시지
            std::string syncMsg = ">> 시스템 동기화 시작...";
            int msgW = MeasureTextEx(font, syncMsg.c_str(), 24, 1).x;
            DrawTextEx(font, syncMsg.c_str(), { (float)(screenW / 2 - msgW / 2), (float)(boxY + 60) }, 32, 1, GREEN);
        }

        // 계속 안내
        DrawTextEx(font, "▶", { (float)(screenW - 40), (float)(screenH - 50) }, 32, 1, GRAY);

        EndDrawing();

        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER)) {
            if (i <= (int)openingTexts.size()) i++;
            if (i > (int)openingTexts.size()) break;
        }
    }

    UnloadTexture(girlfriendImg);
}

// 화면 그리기
void GameManager::renderFrame(const GameScene& scene) {
    int screenW = GetScreenWidth();
    int screenH = GetScreenHeight();
    int halfW = screenW / 2;
    int fontSize = 32;
    int lineHeight = fontSize + 4;

    BeginDrawing();
    ClearBackground(BLACK);

    // ── 상단 영역 선 ──────────────────────────
    DrawLine(0, 0, screenW, 0, GRAY);       // 최상단선
    DrawLine(0, 45, screenW, 45, GRAY);     // 상단 구분선
    DrawLine(halfW, 0, halfW, 40, GRAY);    // 상단 중앙 세로선

    // 취조 횟수 (좌상단)
    std::string leftTop = "[" + std::to_string(interrogationCount) + "번째 취조]";
    int ltW = MeasureTextEx(font, leftTop.c_str(), fontSize, 1).x;
    DrawTextEx(font, leftTop.c_str(), { (float)(halfW - ltW) / 2, 10 }, fontSize, 1, WHITE);

    // 침식도 (우상단)
    std::string erosionStr;
    if (erosion < 10.0f)       erosionStr = std::to_string(erosion).substr(0, 4);
    else if (erosion < 100.0f) erosionStr = std::to_string(erosion).substr(0, 5);
    else                       erosionStr = std::to_string(erosion).substr(0, 6);
    std::string rightTop = "[Sync Error : " + erosionStr + "%]";
    int rtW = MeasureTextEx(font, rightTop.c_str(), fontSize, 1).x;
    DrawTextEx(font, rightTop.c_str(), { (float)halfW + (float)(halfW - rtW) / 2, 10 }, fontSize, 1, RED);

    // ── 로그 영역 ─────────────────────────────
    int logStartY = 50;
    int logEndY = screenH - 160;

    // 중앙 세로선 (로그 영역)
    DrawLine(halfW, 40, halfW, logEndY, GRAY);

    // 게임 로그 (왼쪽)
    int maxLines = (logEndY - logStartY) / lineHeight;
    for (int i = 0; i < (int)gameLog.size() && i < maxLines; i++) {
        DrawTextEx(font, gameLog[i].c_str(), { 10, (float)(logStartY + i * lineHeight) }, fontSize, 1, LIGHTGRAY);
    }
    // 현실 로그 (오른쪽)
    for (int i = 0; i < (int)realLog.size() && i < maxLines; i++) {
        DrawTextEx(font, realLog[i].c_str(), { (float)(halfW + 10), (float)(logStartY + i * lineHeight) }, fontSize, 1, WHITE);
    }

    // ── 하단 UI 영역 선 ───────────────────────
    DrawLine(0, logEndY, screenW, logEndY, GRAY);           // 로그/하단 구분선
    //DrawLine(0, logEndY + 30, screenW, logEndY + 30, GRAY); // 시스템메시지 구분선
    DrawLine(0, logEndY + 70, screenW, logEndY + 70, GRAY); // 선택지 구분선
    DrawLine(0, screenH - 5, screenW, screenH - 5, GRAY);   // 최하단선

    // 시스템 메시지
    DrawTextEx(font, "[시스템 메시지]", { 10, (float)(logEndY + 5) }, fontSize, 1, YELLOW);
    DrawTextEx(font, scene.systemMessage.c_str(), { 10, (float)(logEndY + 35) }, fontSize, 1, LIGHTGRAY);

    // 선택지 or 계속
    if (scene.options[0].empty()) {
        DrawTextEx(font, "계속하려면 스페이스나 엔터 키를 누르세요...", { 10, (float)(logEndY + 72) }, fontSize, 1, DARKGRAY);
    }
    else {
        std::string opt1 = "1. " + scene.options[0];
        std::string opt2 = "2. " + scene.options[1];
        DrawTextEx(font, opt1.c_str(), { 10, (float)(logEndY + 70) }, fontSize, 1, GREEN);
        if (!scene.options[1].empty()) {
            DrawTextEx(font, opt2.c_str(), { 10, (float)(logEndY + 110) }, fontSize, 1, GREEN);
        }
    }

    EndDrawing();
}  


int GameManager::playScene(std::vector<GameScene>& script) {
    int choice = 0;
    int i = 0;
    bool logged = false;  // 추가

    while (i < (int)script.size() && !WindowShouldClose()) {
        GameScene& s = script[i];

        // 한 번만 로그 추가
        if (!logged) {
            if (!s.gameLine.empty()) addGameLog(s.speaker, s.gameLine);
            if (!s.realLine.empty()) addRealLog(s.speaker, s.realLine);
            logged = true;
        }

        renderFrame(s);

        if (s.options[0].empty()) {
            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER)) {
                i++;
                logged = false;  // 다음 씬으로 넘어갈 때 초기화
            }
        }
        else {
            if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_KP_1)) {
                choice = 1;
                erosion += s.erosionIncrease1;
                s.options[0] = s.options[1] = "";
                i++;
                logged = false;
            }
            else if (IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_KP_2)) {
                choice = 2;
                erosion += s.erosionIncrease2;
                s.options[0] = s.options[1] = "";
                i++;
                logged = false;
            }
        }

        if (erosion >= 100.0f) {
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
    InitWindow(1920, 1080, "싱크");
    SetTargetFPS(60);

    // 한글 코드포인트 로드
    std::vector<int> codepoints;
    font = LoadFontEx("malgun.ttf", 32, nullptr, 0x3FFFF);

    titleScreen();
    OpeningScene();

    std::vector<GameScene> script;

    for (int i = 0; i < (int)ChapterList.size(); i++) {
        gameLog.clear();
        realLog.clear();
        script.clear();
        ChapterList[i](script);
        interrogationCount++;
        if (erosion >= 100.0f) break;
    }

    checkEnding();

    UnloadFont(font);
    CloseWindow();
}

