#pragma once
#include <vector>
#include "GameManager.h"


//addSecne(script, 이름, 게임 대사, 현실 대사, 시스템 메시지, 선택지1, 선택지2, 침식도 증가량1, 침식도 증가량2) 
// 이름과 대사들은 상황에 맞게 자유롭게 바꿔주세요. 
// 시스템 메시지와 선택지, 침식도 증가량은 필요 없으면 안 적으셔도됩니다. 
// 침식도 증가량은 선택지에 따라 달라질 수 있으니, 선택지마다 다른 값을 넣어주시면 됩니다.
// 게임 대사만 적으면 왼쪽에만, 현실 대사만 적으면 오른쪽에만 출력되며 둘 다 적으면 양쪽에 모두 출력됩니다.
// addScene함수만 복사해서 사용하시면 됩니다.

void GameManager::Opening(std::vector<GameScene>& script) {
	addScene(script, "", "", "", "오프닝용입니다.");
	addScene(script, "유라", "", "오빠 이거봐봐 닉네임을 입력해야 된대! 뭘로 할거야?!");
	addScene(script, "", "", "", "유라가 플레이 버튼을 누르는 순간 사전 설명도 없이 바로 플레이어 이름 입력창이 떴다.");
	std::string PlayerName;
}

void GameManager::Chapter1(std::vector<GameScene>& script) {
	std::vector<GameScene> common; //공통
	addScene(common, "", "화면이 암전된 후, 차가운 형광등 아래 취조실이 나타난다.", "", "형광등 아래 남성의 실체가 보인다.");
	addScene(common, "", "맞은편에 사내가 앉아 있다.", "", "취조실의 공기가 차갑게 가라앉습니다.");
	addScene(common, "", "그는 왼쪽 검지 손톱을 뜯으며 당신을 응시한다.", "", "", "책상 위의 서류를 확인한다.", "\"???, 본인 맞습니까?\"", 5.0f, 30.0f);

	int choice = playScene(common);

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		addScene(branch, "", "당신은 책상 위에 놓인 누런 서류 봉투를 열자 사건 현장 사진들이 쏟아진다.", "", "꺾인 팔다리, 기괴하게 화장된 얼굴… 그중 한 장의 사진 구석에 빨갛게 물든 귀걸이가 찍혀 있다.");
		addScene(branch, "유라", "", "와... 저 사진들 진짜 징그럽다..", "여자친구가 게임 속 사진들을 바라봅니다.");
		addScene(branch, "유라", "", "근데 저 사진안에 있는 귀걸이..", "여자친구가 게임 속 귀걸이를 유심히 바라봅니다.");
		addScene(branch, "유라", "", "내가 어제 잃어버린 거랑 되게 비슷하지 않아?", "여자친구가 게임 속 귀걸이를 유심히 바라봅니다.");
	}
	else if(choice == 2) {
		addScene(branch, "", "당신은 서류는 거들떠보지도 않은 채 ???의 눈을 꿰뚫어 보듯 묻는다.", "", "???의 눈을 응시한다.");
		addScene(branch, "", "그는 손톱을 뜯던 동작을 멈추고 천천히 고개를 든다.", "");
		addScene(branch, "", "초점 없는 눈동자에 당신의 모습이 비친다.", "");
		addScene(branch, "???", "형사님, 방금 말하실 때 왼쪽 입꼬리가 15도 정도 더 올라간 거 아세요?", "", "???가 당신을 바라보며 웃습니다.");
		addScene(branch, "???", "조심해주세요. 전 그런거에 예민하니까요.", "");
	}
	playScene(branch);
}

void GameManager::Chapter2(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, "", "2번째 취조입니다.", "", "2번째", "1번", "2번");

	int choice = playScene(common);

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		addScene(branch, "선택지", "1번 선택지", "1번 선택지", "1번 선택지");
	}
	else if (choice == 2) {
		addScene(branch, "", "2번 선택지", "", "2번 선택지");
	}
	playScene(branch);
}

void GameManager::Chapter3(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, "", "3번째 취조입니다.", "", "3번째", "1번", "2번");

	int choice = playScene(common);

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		addScene(branch, "", "1번 선택지", "", "1번 선택지");
	}
	else if (choice == 2) {
		addScene(branch, "", "2번 선택지", "", "2번 선택지");
	}
	playScene(branch);
}

void GameManager::Chapter4(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, "", "4번째 취조입니다.", "", "4번째", "1번", "2번");

	int choice = playScene(common);

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		addScene(branch, "", "1번 선택지", "", "1번 선택지");
	}
	else if (choice == 2) {
		addScene(branch, "", "2번 선택지", "", "2번 선택지");
	}
	playScene(branch);
}

void GameManager::Chapter5(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, "", "5번째 취조입니다.", "", "5번째", "1번", "2번");

	int choice = playScene(common);

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		addScene(branch, "", "1번 선택지", "", "1번 선택지");
	}
	else if (choice == 2) {
		addScene(branch, "", "2번 선택지", "", "2번 선택지");
	}
	playScene(branch);
}

void GameManager::Chapter6(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, "", "6번째 취조입니다.", "", "6번째", "1번", "2번");

	int choice = playScene(common);

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		addScene(branch, "", "1번 선택지", "", "1번 선택지");
	}
	else if (choice == 2) {
		addScene(branch, "", "2번 선택지", "", "2번 선택지");
	}
	playScene(branch);
}

void GameManager::Chapter7(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, "", "7번째 취조입니다.", "", "7번째", "1번", "2번");

	int choice = playScene(common);

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		addScene(branch, "", "1번 선택지", "", "1번 선택지");
	}
	else if (choice == 2) {
		addScene(branch, "", "2번 선택지", "", "2번 선택지");
	}
	playScene(branch);
}

void GameManager::Chapter8(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, "", "8번째 취조입니다.", "", "8번째", "1번", "2번");

	int choice = playScene(common);

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		addScene(branch, "", "1번 선택지", "", "1번 선택지");
	}
	else if (choice == 2) {
		addScene(branch, "", "2번 선택지", "", "2번 선택지");
	}
	playScene(branch);
}

void GameManager::Chapter9(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, "", "9번째 취조입니다.", "", "9번째", "1번", "2번");

	int choice = playScene(common);

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		addScene(branch, "", "1번 선택지", "", "1번 선택지");
	}
	else if (choice == 2) {
		addScene(branch, "", "2번 선택지", "", "2번 선택지");
	}
	playScene(branch);
}

void GameManager::Chapter10(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, "", "10번째 취조입니다.", "", "10번째", "1번", "2번");

	int choice = playScene(common);

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		addScene(branch, "", "1번 선택지", "", "1번 선택지");
	}
	else if (choice == 2) {
		addScene(branch, "", "2번 선택지", "", "2번 선택지");
	}
	playScene(branch);
}