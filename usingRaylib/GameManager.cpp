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


int FONT_SIZE = 35;




//생성자
GameManager::GameManager() : erosion(0.0f), interrogationCount(1), font({ 0 }) {
	suspect = new Suspect();
	girlfriend = new Girlfriend();

	// ChapterList에 각 챕터 함수 저장
	ChapterList.push_back([this](std::vector<GameScene>& s) { Prologue(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter1(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter2(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter3(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter4(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter5(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter6(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter7(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter8(s); });
    ChapterList.push_back([this](std::vector<GameScene>& s) { Chapter9(s); });
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
		std::string start = "Press to Start";
		Vector2 mousePos = GetMousePosition();

		DrawRectangleLines(480, 1, 960, 521, {0,0,0,180});
        DrawTextEx(font, title.c_str(), {500, 5}, 500, 1, WHITE);

		Rectangle startRect = { 600, 521, 1500, 200 };
        Color startColor = CheckCollisionPointRec(mousePos, startRect) ? RED : WHITE;
        DrawRectangleLines(600, 521, 1500, 200, {0,0,0,180});
        DrawTextEx(font, start.c_str(), { 600, 525 }, 145, 1, startColor);

		

        if (CheckCollisionPointRec(mousePos, startRect)) {
            DrawTextEx(font, start.c_str(), { 600, 525 }, 145, 1, startColor);
			if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
                
                break;
        }
        EndDrawing();
    }
}

std::string GameManager::inputPlayerName() {
    std::string input = "";

    while (!WindowShouldClose()) {
        // 문자 입력
        int key = GetCharPressed();
        while (key > 0) {
            if (key >= 32 && key < 128 && input.size() < 10) {
                input += (char)key;
            }
            key = GetCharPressed();
        }

        // 백스페이스
        if (IsKeyPressed(KEY_BACKSPACE) && !input.empty()) {
            input.pop_back();
        }

        // 엔터로 확정
        if (IsKeyPressed(KEY_ENTER) && !input.empty()) {
            break;
        }

        BeginDrawing();
        ClearBackground(BLACK);

        // 입력창 UI
        DrawTextEx(font, "닉네임을 입력하세요 (영문, 최대 10자)", { 700, 380 }, FONT_SIZE, 1, GRAY);
        DrawRectangleLines(700, 440, 500, 60, GRAY);
        DrawTextEx(font, input.c_str(), { 710, 450 }, FONT_SIZE, 1, WHITE);

        // 커서 깜빡임
        if ((int)(GetTime() * 2) % 2 == 0) {
            float inputW = MeasureTextEx(font, input.c_str(), FONT_SIZE, 1).x;
            DrawTextEx(font, "|", { 710 + inputW, 450 }, FONT_SIZE, 1, WHITE);
        }

        // 안내
        DrawTextEx(font, "Enter키로 확정", { 700, 510 }, FONT_SIZE, 1, DARKGRAY);

        EndDrawing();
    }
    return input;
}

void GameManager::OpeningLoop(std::vector<GameScene>& script, Texture2D img, std::string systemMsg)
{
	int i = 0;

    while (!WindowShouldClose()) {
        int screenW = GetScreenWidth();
        int screenH = GetScreenHeight();

        BeginDrawing();
        ClearBackground(BLACK);

        // ── 배경 (나중에 배경 이미지로 교체 가능) ──
        //DrawRectangle(0, 0, screenW, screenH, { 20, 20, 30, 255 });

        // ── 캐릭터 이미지 (화면 중앙) ──
        float imgScale = (float)(screenH * 0.8f) / img.height;
        int imgW = img.width * imgScale;
        int imgH = img.height * imgScale;
        int imgX = (screenW - imgW) / 2;
        int imgY = screenH - imgH - 120; // 대사창 위에 위치
        DrawTextureEx(img, { (float)imgX, (float)imgY }, 0, imgScale, WHITE);

        // ── 하단 대사창 ──
        int boxH = 200;
        int boxY = screenH - boxH - 1;

        // 대사창 배경 (반투명)
        DrawRectangle(0, boxY, screenW, boxH, { 0, 0, 0, 180 });
        DrawRectangleLines(1, boxY, screenW - 1, boxH, GRAY);

        if (i < (int)script.size()) {
            GameScene& s = script[i];

            // 화자 이름
            if (!s.speaker.empty()) {
                DrawRectangle(20, boxY - 40, 200, 40, { 0, 0, 0, 200 });
                DrawRectangleLines(20, boxY - 40, 200, 40, GRAY);
                int nameW = MeasureTextEx(font, s.speaker.c_str(), FONT_SIZE, 1).x;
                DrawTextEx(font, s.speaker.c_str(), { (float)(20 + (200 - nameW) / 2), (float)(boxY - 35) }, FONT_SIZE, 1, WHITE);
            }

            // 대사 내용
            std::string line = "";
            if (!s.realLine.empty()) line = s.realLine;
            else if (!s.gameLine.empty()) line = s.gameLine;
            else if (!s.systemMessage.empty()) line = s.systemMessage;

            DrawTextEx(font, line.c_str(), { 30, (float)(boxY + 20) }, FONT_SIZE, 1, girlfriend->getTextColor());
        }
        else {
            // 마지막: 동기화 메시지
            std::string syncMsg = systemMsg;
            int msgW = MeasureTextEx(font, syncMsg.c_str(), FONT_SIZE, 1).x;
            DrawTextEx(font, syncMsg.c_str(), { (float)(screenW / 2 - msgW / 2), (float)(boxY + 60) }, FONT_SIZE, 1, GREEN);
        }


        // 계속 안내
        DrawTextEx(font, "▶", { (float)(screenW - 40), (float)(screenH - 50) }, FONT_SIZE, 1, GRAY);

        EndDrawing();

        if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            if (i <= (int)script.size()) i++;
            if (i > (int)script.size()) break;
        }
    }
}

void GameManager::OpeningScene() {
	girlfriend->getErosion(erosion);
    // 이미지 로드 (미리 준비된 여자친구 이미지)
    Texture2D girlfriendImg = LoadTexture(girlfriend->getPNG().c_str());
    
	std::vector<GameScene> openingTexts1;
	Opening1(openingTexts1);
	OpeningLoop(openingTexts1, {0}, "");

    std::vector<GameScene> openingTexts2;
    Opening2(openingTexts2);
	OpeningLoop(openingTexts2, girlfriendImg, ">>시스템 동기화 시작");

	PlayerName = inputPlayerName();

    std::vector<GameScene> openingTexts3;
	Opening3(openingTexts3);

	std::string welcomeMsg = ">>" + PlayerName + "님, 환영합니다.<<\n게임을 시작합니다.";
    OpeningLoop(openingTexts3, girlfriendImg, welcomeMsg);

    UnloadTexture(girlfriendImg);
}

int GameManager::drawTextWrapped(const std::string& text, float x, float y, float maxWidth, int fontSize, Color color) {
    std::string currentLine = "";
    float currentY = y;
    int lineCount = 1;
    std::string remaining = text;

    while (!remaining.empty()) {
        // 한 글자씩 늘려가며 maxWidth 넘는 지점 찾기
        std::string testLine = "";
        int cutIndex = 0;

        for (int i = 0; i < (int)remaining.size(); ) {
            // UTF-8 한글은 3바이트
            int charSize = 1;
            unsigned char c = remaining[i];
            if (c >= 0xE0) charSize = 3;
            else if (c >= 0xC0) charSize = 2;

            std::string testAdd = testLine + remaining.substr(i, charSize);
            float testWidth = MeasureTextEx(font, testAdd.c_str(), fontSize, 1).x;

            if (testWidth > maxWidth) break;

            testLine = testAdd;
            cutIndex = i + charSize;
            i += charSize;
        }

        if (cutIndex == 0) break; // 한 글자도 못 들어가면 중단

        DrawTextEx(font, testLine.c_str(), { x, currentY }, fontSize, 1, color);
        remaining = remaining.substr(cutIndex);

        if (!remaining.empty()) {
            currentY += fontSize + 4;
            lineCount++;
        }
    }

    return lineCount;
}

// 화면 그리기
void GameManager::renderFrame(const GameScene& scene) {
    int screenW = GetScreenWidth();
    int screenH = GetScreenHeight();
    int halfW = screenW / 2;
    int lineHeight = FONT_SIZE + 4;

    BeginDrawing();
    ClearBackground(BLACK);

    // ── 상단 영역 선 ──────────────────────────
    DrawLine(0, 0, screenW, 0, GRAY);
    DrawLine(0, 45, screenW, 45, GRAY);
    DrawLine(halfW, 0, halfW, 40, GRAY);

    // 취조 횟수 (좌상단)
    std::string leftTop = "[" + std::to_string(interrogationCount) + "번째 취조]";
    int ltW = MeasureTextEx(font, leftTop.c_str(), FONT_SIZE, 1).x;
    DrawTextEx(font, leftTop.c_str(), { (float)(halfW - ltW) / 2, 5 }, FONT_SIZE, 1, WHITE);

    // 침식도 (우상단)
    std::string erosionStr;
    if (erosion < 10.0f)       erosionStr = std::to_string(erosion).substr(0, 4);
    else if (erosion < 100.0f) erosionStr = std::to_string(erosion).substr(0, 5);
    else                       erosionStr = std::to_string(erosion).substr(0, 6);
    std::string rightTop = "[Sync Error : " + erosionStr + "%]";
    int rtW = MeasureTextEx(font, rightTop.c_str(), FONT_SIZE, 1).x;
    DrawTextEx(font, rightTop.c_str(), { (float)halfW + (float)(halfW - rtW) / 2, 5 }, FONT_SIZE, 1, RED);

    // ── 로그 영역 ─────────────────────────────
    int logStartY = 50;
    int logEndY = screenH - 160;
    float maxLogWidth = halfW - 20;

    DrawLine(halfW, 40, halfW, logEndY, GRAY);

    // 게임 로그 (왼쪽)
    int currentGameY = logStartY;
    for (int i = 0; i < (int)gameLog.size(); i++) {
        if (currentGameY >= logEndY) break;
        Color color = (gameLog[i].find("[") == 0) ? suspect->getTextColor() : LIGHTGRAY;
        int linesDrawn = drawTextWrapped(gameLog[i], 10, currentGameY, maxLogWidth, FONT_SIZE, color);
        currentGameY += linesDrawn * lineHeight;
    }

    // 현실 로그 (오른쪽)
    int currentRealY = logStartY;
    for (int i = 0; i < (int)realLog.size(); i++) {
        if (currentRealY >= logEndY) break;
        Color color = (realLog[i].find("[") == 0) ? girlfriend->getTextColor() : LIGHTGRAY;
        int linesDrawn = drawTextWrapped(realLog[i], halfW + 10, currentRealY, maxLogWidth, FONT_SIZE, color);
        currentRealY += linesDrawn * lineHeight;
    }

    // ── 하단 UI 영역 선 ───────────────────────
    DrawLine(0, logEndY, screenW, logEndY, GRAY);
    DrawLine(0, logEndY + 70, screenW, logEndY + 70, GRAY);
    DrawLine(0, screenH - 5, screenW, screenH - 5, GRAY);

    // 시스템 메시지
    DrawTextEx(font, "[시스템 메시지]", { 10, (float)(logEndY + 5) }, FONT_SIZE, 1, YELLOW);
    DrawTextEx(font, scene.systemMessage.c_str(), { 10, (float)(logEndY + 35) }, FONT_SIZE, 1, LIGHTGRAY);

    // 선택지 or 계속
    if (scene.options[0].empty()) {
        DrawTextEx(font, "계속하려면 스페이스나 엔터 키를 누르세요...", { 10, (float)(logEndY + 72) }, FONT_SIZE, 1, DARKGRAY);
    }
    else {
        std::string opt1 = "1. " + scene.options[0];
        std::string opt2 = "2. " + scene.options[1];
        Vector2 mousePos = GetMousePosition();

        Rectangle opt1Rect = { 10, (float)(logEndY + 70), (float)MeasureTextEx(font, opt1.c_str(), FONT_SIZE, 1).x + 500, (float)FONT_SIZE };
        Rectangle opt2Rect = { 10, (float)(logEndY + 110), (float)MeasureTextEx(font, opt2.c_str(), FONT_SIZE, 1).x + 500, (float)FONT_SIZE };

        Color opt1Color = CheckCollisionPointRec(mousePos, opt1Rect) ? WHITE : GREEN;
        Color opt2Color = CheckCollisionPointRec(mousePos, opt2Rect) ? WHITE : GREEN;
        DrawTextEx(font, opt1.c_str(), { 10, (float)(logEndY + 70) }, FONT_SIZE, 1, opt1Color);
        if (!scene.options[1].empty()) {
            DrawTextEx(font, opt2.c_str(), { 10, (float)(logEndY + 110) }, FONT_SIZE, 1, opt2Color);
        }
    }

    EndDrawing();
}


int GameManager::playScene(std::vector<GameScene>& script) {
    int choice = 0;
    int i = 0;
    int space = 10;
    bool logged = false;  // 추가

    while (i < (int)script.size() && !WindowShouldClose()) {
        GameScene& s = script[i];

        // 한 번만 로그 추가
        if (!logged) {
            if (!s.gameLine.empty()) addGameLog(s.speaker, s.gameLine);

            if (!s.realLine.empty()) 
            {
                if (s.speaker == girlfriend->getName())addRealLog(s.speaker, girlfriend->speak(s.realLine));
				else addRealLog(s.speaker, s.realLine);
            }
            logged = true;
        }

        renderFrame(s);
        Vector2 mousePos = GetMousePosition();
		int logEndY = GetScreenHeight() - 160;

        if (s.options[0].empty()) {
            if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_KP_ENTER) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                i++;
                logged = false;  // 다음 씬으로 넘어갈 때 초기화
            }
        }
        else {
            std::string opt1 = "1. " + s.options[0];
            std::string opt2 = "2. " + s.options[1];

            // 선택지 Rectangle (renderFrame의 위치와 동일하게)
            Rectangle opt1Rect = { 10, (float)(logEndY + 70), (float)MeasureTextEx(font, opt1.c_str(), FONT_SIZE, 1).x + 500, (float)FONT_SIZE };
            Rectangle opt2Rect = { 10, (float)(logEndY + 110), (float)MeasureTextEx(font, opt2.c_str(), FONT_SIZE, 1).x + 500, (float)FONT_SIZE };

            if (IsKeyPressed(KEY_ONE) || IsKeyPressed(KEY_KP_1) || (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, opt1Rect))) {
                choice = 1;
                erosion += s.erosionIncrease1;
                s.options[0] = s.options[1] = "";
                i++;
                logged = false;
            }
            else if (IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_KP_2) || (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(mousePos, opt2Rect))) {
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
    Texture2D girlfriendImg = LoadTexture(girlfriend->getPNG().c_str());

    std::vector<GameScene> script;

    if (erosion < 30.0f) 
    {
        HappyEndingScene(script);
        OpeningLoop(script, girlfriendImg, ">>Happy Ending<<");
    }
    else if (erosion < 100.0f) 
    {
        NormalEndingScene(script);
        OpeningLoop(script, girlfriendImg, ">>Normal Ending<<");
    }
    else 
    {
        BadEndingScene(script);
        OpeningLoop(script, girlfriendImg, ">>Bad Ending<<");
    }

    UnloadTexture(girlfriendImg);
}

// 메인 게임 루프
void GameManager::run() {
    InitWindow(1920, 1080, "싱크");
    SetTargetFPS(60);

    // 한글 코드포인트 로드
    std::vector<int> codepoints;
    font = LoadFontEx("malgun.ttf", FONT_SIZE, nullptr, 0x3FFFF);

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

