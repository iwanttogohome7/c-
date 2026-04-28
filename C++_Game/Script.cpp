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
	std::vector<GameScene> common; //공통
	addScene(common, "", "", "봄날의 오후.");
	addScene(common, "", "", "오늘은 여느 때와 다르게 창문을 열어 놓은채로 잠에 들었다.");
	addScene(common, "", "", "평소에는 낮에도 어두컴컴한 집에");
	addScene(common, "", "", "음식물 쓰레기 냄새가 진동을 해서 머리가 아팠었는데");
	addScene(common, "", "", "오늘은 그렇지도 않다.");
	addScene(common, "", "", "따뜻하고 선선한 날씨 탓에 나도 모르게 집에서 눈이 감겼나 보다.");
	addScene(common, "", "", "이런 나에게도 이 풋풋한 날씨를 만끽할 자격은 있다고 생각한다.");
	addScene(common, "", "", "아니 그럴 자격이 있을까?");
	addScene(common, "", "", "나에게도…");
	addScene(common, "", "", ".");
	addScene(common, "", "", ".");
	addScene(common, "", "", ".");
	addScene(common, "???", "", "…빠");
	addScene(common, "주인공", "", "..빠 …오빠! 일어나봐!");
	addScene(common, "", "", "나의 여자친구인 유라");
	addScene(common, "", "", "삼 년전 학교 동아리에서 처음 만나 연인 사이로 까지 발전하게 되었다.");
	addScene(common, "", "", "내가 자취방에서 낮잠을 잘 때면 이렇게 나를 무자비하게 흔들어 깨우곤 한다.");
	addScene(common, "유라", "", "오빠 아직두 자?! 해가 벌써 여기까지 떴는데 언제 일어날 거야~");
	addScene(common, "", "", "아. 책상에 어제 먹은 라면 안 치워놨는데…");
	addScene(common, "", "", "쪽팔린다.");
	addScene(common, "", "", "그래도 오늘은 문을 열어놔서 다행이다.");
	addScene(common, "유라", "", "이제 그만 눈 뜨기!");
	addScene(common, "", "", "오빠 자는 거 구경하는 것도 재밌지만 오늘은 할 일이 많단 말이야!!");
	addScene(common, "", "", "집이 이렇게나 더러운데 ㅇㅇ이는 화난 기색도 없이 항상 나에게 말을 걸어준다.");
	addScene(common, "주인공", "", "우음… 무슨 일이야…?");
	addScene(common, "유라", "", "히히 드디어 일어났네?");
	addScene(common, "유라", "", "오빠 일어날 때까지 기다리느라 나 진짜 심심해 죽는 줄 알았어…");
	addScene(common, "유라", "", "짜잔! 이거 봐봐.");
	addScene(common, "유라", "", "나 어제 밤새워서 찾은 추리 게임인데 오빠랑 하려고 꾹 참고 안 했거든.");
	addScene(common, "유라", "", "오빠 추리 게임 좋아하잖아. 얼른 노트북 앞으로 와봐!");
	addScene(common, "", "", "히키 생활을 2년 동안 한 나에게는 취미가 하나 있었다.");
	addScene(common, "", "", "그건 바로 추리게임을 하는 것.");
	addScene(common, "", "", "나를 유일하게 위로해 줄 수 있는 건 유라와 머리에 쥐가 날 정도로 범인을 밝혀내기 힘든 추리게임 뿐이다.");
	addScene(common, "", "", "여자친구가 켜 놓은 컴퓨터 화면 앞으로 다가가니 들어본 적 없는 타이틀의 게임이 화면에 켜져 있었다.");
	addScene(common, "주인공", "", "처음 보는 게임인데. 어디서 가져온 거야?");
	addScene(common, "유라", "", "요즘 공포게임 할 게 없어서 심심하다고 했었잖아~");
	addScene(common, "유라", "", "오빠가 재미있어 할 만한 게임 열심히 찾아봤어!");
	addScene(common, "", "", "나도 모르는 게임을 어떻게 찾은걸까.");
	addScene(common, "", "", "유라가 우울해 하는 나를 위해서 인터넷 서핑을 열심히 했나보다.");
	addScene(common, "유라", "", "이거 봐봐 타이틀 분위기 대박이지?");
	addScene(common, "유라", "", "오빠가 주인공이고 나는 옆에서 도와주는 역할 할게!");
	addScene(common, "유라", "", "이 게임은 오빠가 선택을 진짜 잘해야 된대.");
	addScene(common, "유라", "", "주인공의 선택에 따라 엔딩이 완전히 갈린다더라고.");
	addScene(common, "", "", "여타 다른 공포 미연시랑 다른 점이 있나.");
	addScene(common, "", "", "똥겜의 냄새가 난다.");
	addScene(common, "", "", "그래도 유라가 가져온 게임이니까 실망시키지 말고 열심히 해봐야지.");
	addScene(common, "유라", "", "오빠 이거봐봐 닉네임을 입력해야 된대! 뭘로 할거야?!");
	addScene(common, "", "", "유라가 플레이 버튼을 누르는 순간 사전 설명도 없이 바로 플레이어 이름 입력창이 떴다.");
	addScene(common, "", "", "세계관 설명도 안 해주고 바로 게임 시작?");
	addScene(common, "", "", "하꼬 인디게임이라고 해도 말이야. 너무 불친절 한 거 아니야?");
	addScene(common, "", "", "하는 수 없이 키보드에 손을 올려 닉네임을 입력했다.");
	addScene(common, "주인공", "", "흐아암~...");
	addScene(common, "유라", "", "지금까지 잤잖아~ 하품하면 어떡해!");
	addScene(common, "", "", "시작도 전인데 하품이 나왔다.");
	addScene(common, "주인공", "", "미안미안. 아직 잠이 덜 깼나봐. 다시 집중할게.");
	addScene(common, "", "", "눈을 부릅뜨고 게임 스크립트를 넘겨보니 어떤 방이 하나 나왔다.");
	playScene(common);
	std::string PlayerName;
}

void GameManager::Chapter1(std::vector<GameScene>& script) {
	std::vector<GameScene> common; //공통
	addScene(common, "", "화면이 암전된 후, 차가운 형광등 아래 취조실이 나타난다.", "", "형광등 아래 남성의 실체가 보인다.");
	addScene(common, "", "맞은편에 사내가 앉아 있다.", "", "취조실의 공기가 차갑게 가라앉습니다.");
	addScene(common, "", "그는 왼쪽 검지 손톱을 뜯으며 당신을 응시한다.", "", "", "책상 위의 서류를 확인한다.", "\"???, 본인 맞습니까?\"", 5.0f);

	int choice = playScene(common);

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		addScene(branch, "", "당신은 책상 위에 놓인 누런 서류 봉투를 열자 사건 현장 사진들이 쏟아진다.", "", "꺾인 팔다리, 기괴하게 화장된 얼굴… 그중 한 장의 사진 구석에 빨갛게 물든 귀걸이가 찍혀 있다.");
		addScene(branch, "유라", "", "와... 저 사진들 진짜 징그럽다..", "유라가 게임 속 사진들을 바라봅니다.");
		addScene(branch, "유라", "", "근데 저 사진안에 있는 귀걸이..", "유라가 게임 속 귀걸이를 유심히 바라봅니다.");
		addScene(branch, "유라", "", "내가 어제 잃어버린 거랑 되게 비슷하지 않아?", "유라가 게임 속 귀걸이를 유심히 바라봅니다.");
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