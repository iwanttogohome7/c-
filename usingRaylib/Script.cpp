#include "GameManager.h"


//addSecne(script, 이름, 게임 대사, 현실 대사, 시스템 메시지, 선택지1, 선택지2, 침식도 증가량1, 침식도 증가량2) 
// 이름과 대사들은 상황에 맞게 자유롭게 바꿔주세요. 
// 시스템 메시지와 선택지, 침식도 증가량은 필요 없으면 안 적으셔도됩니다. 
// 침식도 증가량은 선택지에 따라 달라질 수 있으니, 선택지마다 다른 값을 넣어주시면 됩니다.
// 게임 대사만 적으면 왼쪽에만, 현실 대사만 적으면 오른쪽에만 출력되며 둘 다 적으면 양쪽에 모두 출력됩니다.
// addScene함수만 복사해서 사용하시면 됩니다.


void GameManager::Opening1(std::vector<GameScene>& script) { //여자친구 등장 전 오프닝 시나리오
	addScene(script, "", "", "봄날의 오후.");
	addScene(script, "", "", "오늘은 여느 때와 다르게 창문을 열어 놓은채로 잠에 들었다.");
	addScene(script, "", "", "평소에는 낮에도 어두컴컴한 집에");
	addScene(script, "", "", "음식물 쓰레기 냄새가 진동을 해서 머리가 아팠었는데");
	addScene(script, "", "", "오늘은 그렇지도 않다.");
	addScene(script, "", "", "따뜻하고 선선한 날씨 탓에 나도 모르게 집에서 눈이 감겼나 보다.");
	addScene(script, "", "", "이런 나에게도 이 풋풋한 날씨를 만끽할 자격은 있다고 생각한다.");
	addScene(script, "", "", "아니 그럴 자격이 있을까?");
	addScene(script, "", "", "나에게도…");
	addScene(script, "", "", ".........");
	addScene(script, "", "", "............");
	addScene(script, "", "", "................");
	addScene(script, "???", "", "…빠");
	addScene(script, "???", "", "..빠 …오빠! 일어나봐!");
}

void GameManager::Opening2(std::vector<GameScene>& script) { //이름 입력 전 오프닝 시나리오
	addScene(script, "", "", "나의 여자친구인 유라");
	addScene(script, "", "", "삼 년전 학교 동아리에서 처음 만나 연인 사이로 까지 발전하게 되었다.");
	addScene(script, "", "", "내가 자취방에서 낮잠을 잘 때면 이렇게 나를 무자비하게 흔들어 깨우곤 한다.");
	addScene(script, girlfriend->getName(), "", "오빠 아직두 자?! 해가 벌써 여기까지 떴는데 언제 일어날 거야~");
	addScene(script, "", "", "아. 책상에 어제 먹은 라면 안 치워놨는데…");
	addScene(script, "", "", "쪽팔린다.");
	addScene(script, "", "", "그래도 오늘은 문을 열어놔서 다행이다.");
	addScene(script, girlfriend->getName(), "", "이제 그만 눈 뜨기!");
	addScene(script, girlfriend->getName(), "", "오빠 자는 거 구경하는 것도 재밌지만 오늘은 할 일이 많단 말이야!!");
	addScene(script, "", "", "집이 이렇게나 더러운데 유라는 화난 기색도 없이 항상 나에게 말을 걸어준다.");
	addScene(script, PlayerName, "", "우음… 무슨 일이야…?");
	addScene(script, girlfriend->getName(), "", "히히 드디어 일어났네?");
	addScene(script, girlfriend->getName(), "", "오빠 일어날 때까지 기다리느라 나 진짜 심심해 죽는 줄 알았어…");
	addScene(script, girlfriend->getName(), "", "짜잔! 이거 봐봐.");
	addScene(script, girlfriend->getName(), "", "나 어제 밤새워서 찾은 추리 게임인데 오빠랑 하려고 꾹 참고 안 했거든.");
	addScene(script, girlfriend->getName(), "", "오빠 추리 게임 좋아하잖아. 얼른 노트북 앞으로 와봐!");
	addScene(script, "", "", "히키 생활을 2년 동안 한 나에게는 취미가 하나 있었다.");
	addScene(script, "", "", "그건 바로 추리게임을 하는 것.");
	addScene(script, "", "", "나를 유일하게 위로해 줄 수 있는 건 유라와 머리에 쥐가 날 정도로 범인을 밝혀내기 힘든 추리게임 뿐이다.");
	addScene(script, "", "", "여자친구가 켜 놓은 컴퓨터 화면 앞으로 다가가니 들어본 적 없는 타이틀의 게임이 화면에 켜져 있었다.");
	addScene(script, PlayerName, "", "처음 보는 게임인데. 어디서 가져온 거야?");
	addScene(script, girlfriend->getName(), "", "요즘 공포게임 할 게 없어서 심심하다고 했었잖아~");
	addScene(script, girlfriend->getName(), "", "오빠가 재미있어 할 만한 게임 열심히 찾아봤어!");
	addScene(script, "", "", "나도 모르는 게임을 어떻게 찾은걸까.");
	addScene(script, "", "", "유라가 우울해 하는 나를 위해서 인터넷 서핑을 열심히 했나보다.");
	addScene(script, girlfriend->getName(), "", "이거 봐봐 타이틀 분위기 대박이지?");
	addScene(script, girlfriend->getName(), "", "오빠가 주인공이고 나는 옆에서 도와주는 역할 할게!");
	addScene(script, girlfriend->getName(), "", "이 게임은 오빠가 선택을 진짜 잘해야 된대.");
	addScene(script, girlfriend->getName(), "", "주인공의 선택에 따라 엔딩이 완전히 갈린다더라고.");
	addScene(script, "", "", "여타 다른 공포 미연시랑 다른 점이 있나.");
	addScene(script, "", "", "똥겜의 냄새가 난다.");
	addScene(script, "", "", "그래도 유라가 가져온 게임이니까 실망시키지 말고 열심히 해봐야지.");
	addScene(script, girlfriend->getName(), "", "오빠 이거봐봐 닉네임을 입력해야 된대! 뭘로 할거야?!");
	addScene(script, "", "", "유라가 플레이 버튼을 누르는 순간 사전 설명도 없이 바로 플레이어 이름 입력창이 떴다.");
	addScene(script, "", "", "세계관 설명도 안 해주고 바로 게임 시작?");
	addScene(script, "", "", "하꼬 인디게임이라고 해도 말이야. 너무 불친절 한 거 아니야?");
	addScene(script, "", "", "하는 수 없이 키보드에 손을 올려 닉네임을 입력했다.");
}

void GameManager::Opening3(std::vector<GameScene>& script) { // 이름 입력 후 오프닝 시나리오
	addScene(script, PlayerName, "", "흐아암~...");
	addScene(script, girlfriend->getName(), "", "지금까지 잤잖아~ 하품하면 어떡해!");
	addScene(script, "", "", "시작도 전인데 하품이 나왔다.");
	addScene(script, PlayerName, "", "미안미안. 아직 잠이 덜 깼나봐. 다시 집중할게.");
	addScene(script, "", "", "눈을 부릅뜨고 게임 스크립트를 넘겨보니 어떤 방이 하나 나왔다.");
}

void GameManager::Prologue(std::vector<GameScene>& script) { // 게임 시작 후 프롤로그 시나리오
	std::vector<GameScene> common;
	addScene(common, "", "", "", "철컹, 무거운 철문이 닫히는 소리.");
	addScene(common, "", "", "", "당신은 취조실 책상 맞은편에 앉아있는 남자를 바라본다.");
	addScene(common, "", "", "", "연쇄 살인 및 시신 훼손 혐의. 용의자 번호 409번.");
	addScene(common, "", "", "", "남자는 초점 없는 눈으로 허공을 응시하며 쉴 새 없이 손톱을 물어뜯고 있다.");
	addScene(common, PlayerName, "", "오… 분위기 꽤 제대로 만들었네.");
	addScene(common, girlfriend->getName(), "", "이런 음침한 느낌 좋다. 딱 우리 취향이야.");
	addScene(common, "형사", "기록 시작. 용의자, 고개 들어. 이름과 나이를 밝혀라.", "");
	addScene(common, "살인마", "...시끄러워. 타닥타닥... 그 소리 좀 안 나게 할 수 없어?", "");
	addScene(common, PlayerName, "", "키보드 소리라는 건가?");
	addScene(common, girlfriend->getName(), "", "벌써부터 정신 이상한 타입이다...");
	addScene(common, "형사", "무슨 소리를 하는 거지? 취조실엔 우리 둘뿐이다.", "");
	addScene(common, "살인마", "키보드 소리. 지금도 계속 치고 있잖아. 엔터... 스페이스바... 날 조종하려고.", "");
	addScene(common, PlayerName, "", "...어?");
	addScene(common, girlfriend->getName(), "", "(웃으며) 오빠 지금 키보드 누르고 있잖아!");
	addScene(common, PlayerName, "", "아 괜히 소름 돋게 그런 말 하지마.");
	addScene(common, "형사", "정신병자 행세로 형량을 줄일 속셈이라면 포기하는 게 좋을 거다.", "");
	addScene(common, "형사", "첫 번째 범행 현장부터 묻겠다.", "");

	playScene(common);
}

void GameManager::Chapter1(std::vector<GameScene>& script) {
	std::vector<GameScene> common; //공통
	addScene(common, "살인마", "내 잘못이 아니야... 그 여자가 죽이라고 했어.", "");
	addScene(common, "살인마", "자길 쳐다보지 않는 X들은 다 눈을 뽑아버려야 한다고.", "");
	addScene(common, "형사", "피해자 3명 모두 안구가 적출된 채 발견됐다.", "");
	addScene(common, "형사", "그게 네 망상 속에 존재하는 '그 여자'의 지시라는 건가?", "");
	addScene(common, PlayerName, "", "와 시작부터 수위 세네.");
	addScene(common, girlfriend->getName(), "", "눈 뽑는 설정 좋다. 집착이 확 느껴져");
	addScene(common, "살인마", "망상? 큭큭... 아니, 신이지. 내 머릿속에, 내 모니터 안에 살아 숨 쉬는 신.", "");
	addScene(common, "살인마", "근데 다른 X들이 내 시선을 빼앗았잖아.", "");
	addScene(common, "형사", "그래서 죽였다고?", "");
	addScene(common, "살인마", "당신도 조심해. 그 여자는... 한눈파는 걸 제일 싫어하니까.", "");
	addScene(common, "", "", "", "", "동기는 병적인 질투심으로 인한 우발적 살인이라는 거군. 흉기는 어디에 유기했지?", "...모니터 안에 있다고? 도대체 그 여자가 누구길래 그렇게 두려워하는 거지?", 0, 10);

	int choice = playScene(common);

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		addScene(branch, PlayerName, "", "당연히 A지.");
		addScene(branch, girlfriend->getName(), "", "역시 오빠.");
	}
	else if(choice == 2) {
		addScene(branch, PlayerName, "", "모니터 안에 살아있는 신이라... 단단히 미쳤네.");
		addScene(branch, girlfriend->getName(), "", "근데 난 좀 이해돼.");
		addScene(branch, PlayerName, "", "뭐가?");
		addScene(branch, girlfriend->getName(), "", "좋아하는 사람이 자꾸 다른 데 보면 짜증나는 거.");
		addScene(branch, girlfriend->getName(), "", "...오빠도 게임하면서 딴 거 하지마.");
		addScene(branch, PlayerName, "", "폰도 안 보고 있거든?");
		addScene(branch, girlfriend->getName(), "", "응ㅎㅎ 잘하구 있어.");
	}
	playScene(branch);
}

void GameManager::Chapter2(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, "살인마", "무서워? 당신 지금... 손끝이 조금 떨리는데.", "");
	addScene(common, "형사", "헛소리 마라. 질문은 내가 한다.", "");
	addScene(common, "형사", "두 번째 피해자의 손가락은 왜 절단한 거지?", "");
	addScene(common, "살인마", "자꾸 딴짓을 하니까! 스마트폰을 만지고, 마우스를 쥐고...", "");
	addScene(common, "살인마", "오직 한 사람에게만 집중해야 하는데, ", "");
	addScene(common, "살인마", "그 손가락들이 자꾸 다른 곳을 만지잖아!", "");
	addScene(common, "형사", "그래서 손가락을 잘랐다?", "");
	addScene(common, "살인마", "그래야 나한테만 집중할 테니까. ", "");
	addScene(common, "살인마", "...당신도 손가락 조심해.", "");
	addScene(common, "살인마", "그렇게 키보드만 두드리고 있다간, 언제 잘려 나갈지 모르니까.", "");
	addScene(common, "", "", "", "", "피해자의 신체 훼손은 철저히 네 가학적인 욕구 때문이었다. 기록해 두지.", "(키보드...? 방금 전부터 왜 자꾸 현실의 나한테 말을 거는 것 같지?)", 0, 10);

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
	addScene(common, "살인마", "보고 있어. 분명히 보고 있어.", "");
	addScene(common, "형사", "취조실 거울 뒤의 수사관들을 말하는 거라면, 당연히 보고 있다.", "");
	addScene(common, "살인마", "아니, 그딴 머저리들 말고.", "");
	addScene(common, "살인마", "'화면 밖'에서 널 내려다보는 그 눈동자 말이야.", "");
	addScene(common, "형사", "(미간을 찌푸리며) 선 넘지 마라.여긴 게임이 아니야.", "");
	addScene(common, "살인마", "게임? 하하하! 누가 게임을 하고 있는 걸까?", "");
	addScene(common, "살인마", "당신이 날 조종하는 걸까, 아니면 그 여자가 우릴 가지고 노는 걸까?", "");
	addScene(common, "", "", "", "", "화면 밖이라니... 누가 날 보고 있다는 거야? 나를 안다는 투로 말하지 마!", "CCTV에 찍힌 네 동선을 확인했다. 알리바이를 댈 생각은 마라.", 10, 0);

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
	addScene(common, "살인마", "그 방을 꾸미는 데 꽤 오랜 시간이 걸렸지.", "");
	addScene(common, "살인마", "창문이란 창문은 다 시멘트로 발라버렸어.", "");
	addScene(common, "살인마", "빛 한 줌 못 들어오게.", "");
	addScene(common, "형사", "4번째 피해자가 발견된 지하 창고를 말하는 건가.", "");
	addScene(common, "형사", " 왜 그런 짓을 한 거지?", "");
	addScene(common, "살인마", "바깥세상을 볼 수 없게 만들면, 세상엔 우리 둘만 남게 되니까.", "");
	addScene(common, "살인마", " 나만 보고, 내 목소리만 듣고, 내 숨결만 느끼는 완벽한 장소.", "");
	addScene(common, "살인마", " 그래야만 안심이 됐거든.", "");
	addScene(common, "형사", "피해자들을 외부와 철저히 단절시켜서 심리적으로 지배하려 했군.", "");
	addScene(common, "살인마", "지배? 아니, 사랑이지. 바깥세상의 쓰레기 같은 소음으로부터 지켜준 거야. 큭큭…", "");
	addScene(common, "", "", "", "", "(순간, 닫혀있는 등 뒤의 방문이 몹시 거슬리기 시작한다) …바깥세상과 단절된 완벽한 곳이라. 이 묘하게 숨 막히는 기분은 대체 뭐지?", "감금과 세뇌를 사랑으로 포장하지 마라. 다음 피해자는 어떻게 유인했지?", 10, 0);

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
	addScene(common, "살인마", "근데 밀실에 가둬나도 결국 시간이 지나면 변하더라고.", "");
	addScene(common, "살인마", "살이 빠지고, 생기가 사라지고… 그건 내가 원한 완벽한 모습이 아니었어.", "");
	addScene(common, "형사", "그래서 약물을 쓴 건가? 시신에서 다량의 &@#이 검출됐다.", "");
	addScene(common, "살인마", "움직이지 못하게 해야 했으니까.", "");
	addScene(common, "살인마", "가장 아름다울 때, 날 바라보는 그 완벽한 순간에 영원히 멈춰 두고 싶었어.", "");
	addScene(common, "살인마", "늙지도, 변하지도, 날 떠나지도 못하게.", "");
	addScene(common, "형사", "산 사람을 인형처럼 박제하려 했다니, 역겹군.", "");
	addScene(common, "살인마", "역겨워? 하하. 근데 이 세계에서는 그럴 걱정이 없잖아.", "");
	addScene(common, "살인마", "썩지도 변하지도 않지. ‘그녀’가 알려줬어.", "");
	addScene(common, "살인마", "다음은 굳이 번거롭게 내 지하실까지 끌고 올 필요 없이,", "");
	addScene(common, "살인마", "그냥 여기 가둬두면 영원히 내 것으로 만드는 방법이 있다고.", "");
	addScene(common, "형사", "... 그 여자는 네 망상이 아닌건가?", "");
	addScene(common, "살인마", "(피식 웃으며) “당신도 알잖아.", "");
	addScene(common, "", "", "", "", "지금은 취조중이다. 여긴 네 소설을 듣는 자리 아니니까, 쓸데없는 말 말고 사실 관계만 똑바로 진술해.", "(펜을 내려놓는다. 왜인지 그 말을 부정할 수가 없다.)", 0, 10);

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
	addScene(common, "살인마", "오늘따라 피곤해 보이네. 잠을 못 자셨나?", "");
	addScene(common, "형사", "내 상태는 네가 신경 쓸 것 없다. 여섯 번째 피해자 얘기를 해라.", "");
	addScene(common, "살인마", "여섯 번째… 아~ 그 애.. 처음엔 도망치려고 했는데.", "");
	addScene(common, "살인마", "문을 긁고, 소리를 지르고. 근데 신기하지? 결국엔 다들 조용해져.", "");
	addScene(common, "살인마", "밖에서 아무도 안 오는 걸 알면.", "");
	addScene(common, "형사", "언제부터 감금했지?", "");
	addScene(common, "살인마", "처음 만난 날부터… 좋아하면 곁에 두고 싶은 게 당연하잖아? 그렇지 않아?", "");
	addScene(common, "살인마", "놓아주면 변하지까. 내 손 안에 있을 때만 안 변하거든.", "");
	addScene(common, "살인마", "어느 순간부터 그 애가 나 말고는 아무것도 찾지 않게 됐어.", "");
	addScene(common, "살인마", "전화도 안 하고, 밖에도 안 나가고. 그게 제일 보기 좋았어.", "");
	addScene(common, "형사", "그건 사랑이 아니라 소유욕이다.", "");
	addScene(common, "살인마", "(눈가가 붉어지며) ... 누구나 잃고 싶지 않은 사람이 있는 거 아닌가요, 형사님?", "");
	addScene(common, "", "", "", "", "(괜히 파일을 넘긴다) ... 다음 질문으로 넘어가지.", "그런 심리 조작 시도는 통하지 않는다. 이미 너에 대한 정보는 알고 있어. 납치 장소를 말해.", 10, 0);

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
	addScene(common, "살인마", "있잖아, 형사님 이름 한 번 알려주면 안돼? 우리 오래됐는데.", "");
	addScene(common, "형사", "취조관은 이름을 밝히지 않는다.", "");
	addScene(common, "살인마", "그래도 괜찮아. 이미 알 것 같으니까.", "");
	addScene(common, "형사", "... 그게 무슨 소리지?", "");
	addScene(common, "살인마", "계속 보고 있었잖아. 당신이 어떤 말에 멈추는지, 어떤 질문에 시선을 피하는지.", "");
	addScene(common, "살인마", "이름보다 더 많은 걸 알아버린 거 같아. 궁금해?", "");
	addScene(common, "형사", "(의자를 뒤로 당기며) 헛소리 집어치워.", "");
	addScene(common, "살인마", "(낮고 또렷하게)" + PlayerName, "");
	addScene(common, "형사", "... 내가 이름을 밝힌 적이 있던가? 누가 알려준 거지?", "");
	addScene(common, "살인마", "(잠시 생각하는 듯 고개를 기울이며) “... 형사님이 알려준 것 같기도 하고, 그 여자한테 들은 것 같기도 하고..", "");
	addScene(common, "", "", "", "", "공범이 있다는 거냐. 그 여자 신원을 대라.", "(내가 알려준 적이 없다는 걸 안다. 근데 … 그 여자의 정체는 혹시.)", 0, 10);

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
	addScene(common, "살인마", "그 사람들이 떠난 게 아니야. 내가 정리한 거지.", "");
	addScene(common, "살인마", "하나씩. 천천히. 티 안 나게.", "");
	addScene(common, "형사", "피해자 주변 인물들은 어떻게 정리했지?", "");
	addScene(common, "살인마", "쉬워. 사람 사이엔 항상 오해할 만한 틈이 있거든.", "");
	addScene(common, "살인마", "그 틈에 작은 걸 하나 심어놓으면… 알아서 멀어져. 내가 손댈 필요도 없이.", "");
	addScene(common, "형사", "그러면 피해자는.", "");
	addScene(common, "살인마", "처음엔 이상하게 생각했겠지. 근데 주변이 하나둘 없어지면 결국 나한테 오게 돼있어.", "");
	addScene(common, "살인마", "달리 갈 데가 없으니까… 그게 제일 편한 방법이었어.", "");
	addScene(common, "형사", "편한 방법.", "");
	addScene(common, "살인마", "(잠시 뜸을 들이며) 누군가 나만 바라보게 만들고 싶으면, 다른 걸 전부 없애면 되거든.", "");
	addScene(common, "살인마", "사랑받으려고 한 게 아니야. 그 사람한테 내가 전부가 되고 싶었던 거지.", "");
	addScene(common, "", "", "", "", "(다른 걸 전부 없애면 된다. 그 말이 어디선가 들어본 것처럼 귀에 걸린다.)", "계획적 고립이었군. 구체적인 수단을 진술해라.", 10, 0);

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
	addScene(common, "살인마", "마지막으로 하나만 물어봐도 돼? 형사로서 말고. 그냥 사람 대 사람으로.", "");
	addScene(common, "형사", "...", "");
	addScene(common, "살인마", "그 사람이 나한테 말했어. 언젠가 농담처럼.", "");
	addScene(common, "살인마", "‘나만 바라봐주는 사람이 좋더라’고.", "");
	addScene(common, "형사", "...", "");
	addScene(common, "살인마", "그 말 한 마디면 충분했어. 그게 전부였거든.", "");
	addScene(common, "살인마", "그 사람이 원하는 걸 내가 이뤄준 것뿐이야. 나만 바라보게 만들었으니까.", "");
	addScene(common, "형사", "그게 살인의 이유인가..?", "");
	addScene(common, "살인마", "(고개를 젓는다) 살인이 아니라 완성이지.", "");
	addScene(common, "살인마", "(아주 낮은 목소리로) ... 형사님도 누군가한테 그런 말 한 적 있지 않아요?", "");
	addScene(common, "형사", "(그 말이 왜 이렇게 오래 머무르는 건지 모르겠다.)", "");
	addScene(common, "", "", "", "", "취조를 종료한다. 최종 진술을 녹취하겠다.", "(있다. 분명히 있다. 근데 왜 지금 그게 떠오르는 거지.)", 0, 10);

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

// 아이템 지급 시나리오
void GameManager::itemScene(std::vector<GameScene>& script) {
	addScene(script, "", "", "", "아이템 지급 시나리오입니다.");
	addScene(script, "", "", "당신은 아이템을 획득했다!");
}

void GameManager::BadEndingScene(std::vector<GameScene>& script) {
	addScene(script, "", "", "", "배드 엔딩 시나리오입니다.");
	addScene(script, "", "", "당신은 최악의 결말을 맞이했다.");
}

void GameManager::NormalEndingScene(std::vector<GameScene>& script) {
	addScene(script, "", "", "", "노멀 엔딩 시나리오입니다.");
	addScene(script, "", "", "당신은 평범한 결말을 맞이했다.");
}

void GameManager::HappyEndingScene(std::vector<GameScene>& script) {
	addScene(script, "", "", "", "해피 엔딩 시나리오입니다.");
	addScene(script, "", "", "당신은 해피 엔딩을 맞이했다!");
}