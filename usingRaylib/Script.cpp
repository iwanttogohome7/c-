#include "GameManager.h"


//addSecne(script, 이름, 게임 대사, 현실 대사, 시스템 메시지, 선택지1, 선택지2, 침식도 증가량1, 침식도 증가량2, 이미지 키워드) 
// 이름과 대사들은 상황에 맞게 자유롭게 바꿔주세요. 
// 시스템 메시지와 선택지, 침식도 증가량은 필요 없으면 안 적으셔도됩니다. 
// 침식도 증가량은 선택지에 따라 달라질 수 있으니, 선택지마다 다른 값을 넣어주시면 됩니다.
// 이미지 키워드는 이미지가 필요한 부분에 Character.cpp에서 getPNG함수에 있는 키워드 중 하나를 넣어주시면 됩니다.
// 오프닝과 엔딩에는 이미지 키워드가 필요 없으니 빈칸으로 두시면 됩니다.
// 객체지향을 살리기 위해 여자친구와 용의자의 이름은 각각 girlfriend->getName()과 suspect->getName()으로 불러오게 했습니다.
// 플레이어 이름은 PlayerName으로 불러오시면 됩니다. (inputPlayerName함수에서 입력받은 이름이 저장됩니다.)
// 게임 대사만 적으면 왼쪽에만, 현실 대사만 적으면 오른쪽에만 출력되며 둘 다 적으면 양쪽에 모두 출력됩니다.
// addScene함수만 복사해서 사용하시면 됩니다.

int GameManager::getErosionLevel() {
	if (erosion <= 20.0f) return 0;
	if (erosion <= 40.0f) return 1;
	if (erosion <= 60.0f) return 2;
	if (erosion <= 80.0f) return 3;
	return 4;
}

void GameManager::Opening1(std::vector<GameScene>& script) { //여자친구 등장 전 오프닝 시나리오
	addScene(script, "", "", "봄날의 오후.");
	addScene(script, "", "", "오늘은 여느 때와 다르게 창문을 열어 놓은채로 잠에 들었다.");
	addScene(script, "", "", "평소에는 낮에도 어두컴컴한 집에 음식물 쓰레기 냄새가 진동을 해서 머리가 아팠었는데 오늘은 그렇지도 않다.");
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
	addScene(common, suspect->getName(), "...시끄러워. 타닥타닥... 그 소리 좀 안 나게 할 수 없어?", "");
	addScene(common, PlayerName, "", "키보드 소리라는 건가?");
	addScene(common, girlfriend->getName(), "", "벌써부터 정신 이상한 타입이다...");
	addScene(common, "형사", "무슨 소리를 하는 거지? 취조실엔 우리 둘뿐이다.", "");
	addScene(common, suspect->getName(), "키보드 소리. 지금도 계속 치고 있잖아. 엔터... 스페이스바... 날 조종하려고.", "");
	addScene(common, PlayerName, "", "...어?");
	addScene(common, girlfriend->getName(), "", "(웃으며) 오빠 지금 키보드 누르고 있잖아!");
	addScene(common, PlayerName, "", "아 괜히 소름 돋게 그런 말 하지마.");
	addScene(common, "형사", "정신병자 행세로 형량을 줄일 속셈이라면 포기하는 게 좋을 거다.", "");
	addScene(common, "형사", "첫 번째 범행 현장부터 묻겠다.", "");

	playScene(common);
}

void GameManager::Chapter1(std::vector<GameScene>& script) {
	std::vector<GameScene> common; //공통
	addScene(common, suspect->getName(), "내 잘못이 아니야... 그 여자가 죽이라고 했어.", "");
	addScene(common, suspect->getName(), "자길 쳐다보지 않는 X들은 다 눈을 뽑아버려야 한다고.", "");
	addScene(common, "형사", "피해자 3명 모두 안구가 적출된 채 발견됐다.", "");
	addScene(common, "형사", "그게 네 망상 속에 존재하는 '그 여자'의 지시라는 건가?", "");
	addScene(common, PlayerName, "", "와 시작부터 수위 세네.");
	addScene(common, girlfriend->getName(), "", "눈 뽑는 설정 좋다. 집착이 확 느껴져");
	addScene(common, suspect->getName(), "망상? 큭큭... 아니, 신이지. 내 머릿속에, 내 모니터 안에 살아 숨 쉬는 신.", "");
	addScene(common, suspect->getName(), "근데 다른 X들이 내 시선을 빼앗았잖아.", "");
	addScene(common, "형사", "그래서 죽였다고?", "");
	addScene(common, suspect->getName(), "당신도 조심해. 그 여자는... 한눈파는 걸 제일 싫어하니까.", "");
	addScene(common, "", "", "", "", "동기는 병적인 질투심으로 인한 우발적 살인이라는 거군. 흉기는 어디에 유기했지?", "...모니터 안에 있다고? 도대체 그 여자가 누구길래 그렇게 두려워하는 거지?", 0, 10);

	int choice = playScene(common);

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		addScene(branch, girlfriend->getName(), "", "오 냉정한 선택지.");
		addScene(branch, girlfriend->getName(), "", "오빠는 여자가 누군지 안 궁금해?");
		addScene(branch, PlayerName, "", "아니 뭐...");
		addScene(branch, PlayerName, "", "저런 말에 휘둘리면 안 되는 거 아냐?");
		addScene(branch, girlfriend->getName(), "", "ㅎㅎ 오빠 완전 멋진데?!");
	}
	else if(choice == 2) {
		addScene(branch, girlfriend->getName(), "", "…모니터 안의 여자라.");
		addScene(branch, PlayerName, "", "설정 한번 되게 음침하네,");
		addScene(branch, girlfriend->getName(), "", "그러니까!");
		addScene(branch, girlfriend->getName(), "", "근데 왠지 기분이 이상하다.");
		addScene(branch, PlayerName, "", "왜?");
		addScene(branch, girlfriend->getName(), "", "진짜 누가 화면 안에서 보고 있는 느낌?");
		addScene(branch, PlayerName, "", "야 괜히 그런 말 하지마.");
		addScene(branch, girlfriend->getName(), "", "오빠 겁 먹었어?!");
	}
	playScene(branch);
}

void GameManager::Chapter2(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, suspect->getName(), "무서워? 당신 지금... 손끝이 조금 떨리는데.", "");
	addScene(common, "형사", "헛소리 마라. 질문은 내가 한다.", "");
	addScene(common, "형사", "두 번째 피해자의 손가락은 왜 절단한 거지?", "");
	addScene(common, suspect->getName(), "자꾸 딴짓을 하니까! 스마트폰을 만지고, 마우스를 쥐고...", "");
	addScene(common, suspect->getName(), "오직 한 사람에게만 집중해야 하는데, ", "");
	addScene(common, suspect->getName(), "그 손가락들이 자꾸 다른 곳을 만지잖아!", "");
	addScene(common, "형사", "그래서 손가락을 잘랐다?", "");
	addScene(common, suspect->getName(), "그래야 나한테만 집중할 테니까. ", "");
	addScene(common, suspect->getName(), "...당신도 손가락 조심해.", "");
	addScene(common, suspect->getName(), "그렇게 키보드만 두드리고 있다간, 언제 잘려 나갈지 모르니까.", "");
	addScene(common, "", "", "", "", "피해자의 신체 훼손은 철저히 네 가학적인 욕구 때문이었다. 기록해 두지.", "(키보드...? 방금 전부터 왜 자꾸 현실의 나한테 말을 거는 것 같지?)", 0, 10, "침식도");

	int choice = playScene(common);
	int sync = getErosionLevel();

	std::vector<GameScene> branch; //분기
	if (erosion <= 10.0f)
	{
		if (choice == 1) {
			addScene(branch, girlfriend->getName(), "", "손가락 자르는 건 좀 너무했다...");
			addScene(branch, PlayerName, "", "아무래도 범죄자니까.");
		}
		else if (choice == 2) {
			addScene(branch, girlfriend->getName(), "", "근데 아까 좀 소름이었어.");
			addScene(branch, PlayerName, "", "뭐가.");
			addScene(branch, girlfriend->getName(), "", "“키보드 소리” 얘기할 때.");
			addScene(branch, girlfriend->getName(), "", "진짜 우리 들으라는 것처럼 말했잖아.");
			addScene(branch, PlayerName, "", "연출이지 뭐.");
		}
	}
	else if (erosion > 10.0f)
	{
		if (choice == 1) {
			addScene(branch, girlfriend->getName(), "", "손가락 자르는 건 진짜 사이코 같다.");
			addScene(branch, PlayerName, "", "완전 통제형 인간이지.");
			addScene(branch, girlfriend->getName(), "", "오빠는 누가 집착하면 질색할 타입 같아.");
			addScene(branch, PlayerName, "", "당연하지.");
			addScene(branch, girlfriend->getName(), "", "에엑 너무해~");
			addScene(branch, PlayerName, "", "자자 다시 게임에 집중해봐.");
		}
		else if (choice == 2) {
			addScene(branch, girlfriend->getName(), "", "근데 아까 좀 소름이었어.");
			addScene(branch, PlayerName, "", "뭐가.");
			addScene(branch, girlfriend->getName(), "", "“키보드 소리” 얘기할 때.");
			addScene(branch, girlfriend->getName(), "", "진짜 우리 들으라는 것처럼 말했잖아.");
			addScene(branch, PlayerName, "", "연출이지 뭐.");
			addScene(branch, girlfriend->getName(), "", "오빠 손이 왜 이렇게 차가워?");
			addScene(branch, PlayerName, "", "긴장해서 그래.");
			addScene(branch, girlfriend->getName(), "", "…무서워?");
			addScene(branch, PlayerName, "", "아냐.");
			addScene(branch, PlayerName, "", "자자, 다시 게임에 집중해봐.");
		}
	}
	
	playScene(branch);
}

// Chapter3부터는 선택지마다 침식도에 따른 분기가 비슷해서 switch문으로 처리했습니다.
void GameManager::Chapter3(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, suspect->getName(), "보고 있어. 분명히 보고 있어.", "");
	addScene(common, "형사", "취조실 거울 뒤의 수사관들을 말하는 거라면, 당연히 보고 있다.", "");
	addScene(common, suspect->getName(), "아니, 그딴 머저리들 말고.", "");
	addScene(common, suspect->getName(), "'화면 밖'에서 널 내려다보는 그 눈동자 말이야.", "");
	addScene(common, "형사", "(미간을 찌푸리며) 선 넘지 마라.여긴 게임이 아니야.", "");
	addScene(common, suspect->getName(), "게임? 하하하! 누가 게임을 하고 있는 걸까?", "");
	addScene(common, suspect->getName(), "당신이 날 조종하는 걸까, 아니면 그 여자가 우릴 가지고 노는 걸까?", "");
	addScene(common, "", "", "", "", "화면 밖이라니... 누가 날 보고 있다는 거야? 나를 안다는 투로 말하지 마!", "CCTV에 찍힌 네 동선을 확인했다. 알리바이를 댈 생각은 마라.", 10, 0);

	int choice = playScene(common);
	int sync = getErosionLevel();

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		switch (sync) {
		case 0: 
			addScene(branch, PlayerName, "", "살인마 보기보다 더 말이 안 통하는 녀석이네.");
			addScene(branch, girlfriend->getName(), "", "안 유명한 게임치고 분위기 괜찮지 않아?!");
			addScene(branch, PlayerName, "", "스토리는 좀 유치하지만.");
			addScene(branch, girlfriend->getName(), "", "오빠 은근 재밌게 하고 있는 거 아냐 ㅡㅡ?");
			addScene(branch, "", "", "유라가 옆구리를 찔렀다.");
			addScene(branch, PlayerName, "", "윽. 나름 재미있어.");
			break;
		default:
			addScene(branch, girlfriend->getName(), "", "만약 진짜 누가 계속 오빠 지켜보고 있으면 어떨 거 같아?");
			addScene(branch, PlayerName, "", "무섭겠지 당연히.");
			addScene(branch, girlfriend->getName(), "", "나도… 무서울 것 같아.");
			addScene(branch, "", "", "유라는 내 쪽으로 몸을 붙였다.");
			break;
		}
	}
	else if (choice == 2) {
		switch (sync) {
		case 0:
			addScene(branch, PlayerName, "", "살인마 보기보다 더 말이 안 통하는 녀석이네.");
			addScene(branch, girlfriend->getName(), "", "안 유명한 게임치고 분위기 괜찮지 않아?!");
			addScene(branch, PlayerName, "", "스토리는 좀 유치하지만.");
			addScene(branch, girlfriend->getName(), "", "오빠 은근 재밌게 하고 있는 거 아냐 ㅡㅡ?");
			addScene(branch, "", "", "유라가 옆구리를 찔렀다.");
			addScene(branch, PlayerName, "", "윽. 나름 재미있어.");
			break;
		default: 
			addScene(branch, PlayerName, "", "살인마 보기보다 더 말이 안 통하는 녀석이네.");
			addScene(branch, girlfriend->getName(), "", "안 유명한 게임치고 분위기 괜찮지 않아?!");
			addScene(branch, girlfriend->getName(), "", "살인마도 뭔가 캐릭터가 재미있는 것 같아.");
			addScene(branch, PlayerName, "", "살인마도 그렇고 스토리도 좀 유치하지만.");
			addScene(branch, girlfriend->getName(), "", "오빠 은근 재밌게 하고 있는 거 아냐 ㅡㅡ?");
			addScene(branch, "", "", "유라가 옆구리를 찔렀다.");
			addScene(branch, PlayerName, "", "윽. 나름 재미있어.");
			break;
		}
	}

	playScene(branch);
}

void GameManager::Chapter4(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, suspect->getName(), "그 방을 꾸미는 데 꽤 오랜 시간이 걸렸지.", "");
	addScene(common, suspect->getName(), "창문이란 창문은 다 시멘트로 발라버렸어.", "");
	addScene(common, suspect->getName(), "빛 한 줌 못 들어오게.", "");
	addScene(common, "형사", "4번째 피해자가 발견된 지하 창고를 말하는 건가.", "");
	addScene(common, "형사", " 왜 그런 짓을 한 거지?", "");
	addScene(common, suspect->getName(), "바깥세상을 볼 수 없게 만들면, 세상엔 우리 둘만 남게 되니까.", "");
	addScene(common, suspect->getName(), " 나만 보고, 내 목소리만 듣고, 내 숨결만 느끼는 완벽한 장소.", "");
	addScene(common, suspect->getName(), " 그래야만 안심이 됐거든.", "");
	addScene(common, "형사", "피해자들을 외부와 철저히 단절시켜서 심리적으로 지배하려 했군.", "");
	addScene(common, suspect->getName(), "지배? 아니, 사랑이지. 바깥세상의 쓰레기 같은 소음으로부터 지켜준 거야. 큭큭…", "");
	addScene(common, "", "", "", "", "(순간, 닫혀있는 등 뒤의 방문이 몹시 거슬리기 시작한다) …바깥세상과 단절된 완벽한 곳이라. 이 묘하게 숨 막히는 기분은 대체 뭐지?", "감금과 세뇌를 사랑으로 포장하지 마라. 다음 피해자는 어떻게 유인했지?", 10, 0);

	int choice = playScene(common);
	int sync = getErosionLevel();

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		switch (sync) {
		case 0:
			addScene(branch, PlayerName, "", "저 방 진짜 답답해 보인다…");
			addScene(branch, "", "", "내 자취방도 거의 저 수준인데.");
			addScene(branch, "", "", "갑자기 유라한테 미안한 마음이 들었다.");
			break;
		default:
			addScene(branch, girlfriend->getName(), "", "바깥이랑 단절된 공간…");
			addScene(branch, girlfriend->getName(), "", "뭔가 좋을 것 같아.");
			addScene(branch, PlayerName, "", "뭐가 좋아.");
			addScene(branch, girlfriend->getName(), "", "좋아하는 사람이랑 둘만 있을 수 있고.");
			addScene(branch, PlayerName, "", "너 오늘 왜 이렇게 무서운 말을 많이 하냐?");
			addScene(branch, girlfriend->getName(), "", "히히. 게임 분위기에 영향 받았나봐~");
			addScene(branch, "", "", "유라의 얼굴을 한번 보고, 게임 속 살안마의 취조를 이어갔다.");
			break;
		}
	}
	else if (choice == 2) {
		switch (sync) {
		case 0:
			addScene(branch, PlayerName, "", "저 방 진짜 답답해 보인다…");
			addScene(branch, "", "", "내 자취방도 거의 저 수준인데.");
			addScene(branch, "", "", "갑자기 유라한테 미안한 마음이 들었다.");
			break;
		default:
			addScene(branch, PlayerName, "", "저 방 진짜 답답해 보인다…");
			addScene(branch, "", "", "유라의 말을 듣자,");
			addScene(branch, "", "", "내 자취방도 답답하진 않을까란 생각이 들었다.");
			addScene(branch, "", "", "어두컴컴한 방을 둘러보니 갑자기 유라한테 미안한 마음이 들었다.");
			break;
		}
	}

	playScene(branch);
}

void GameManager::Chapter5(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, suspect->getName(), "근데 밀실에 가둬나도 결국 시간이 지나면 변하더라고.", "");
	addScene(common, suspect->getName(), "살이 빠지고, 생기가 사라지고… 그건 내가 원한 완벽한 모습이 아니었어.", "");
	addScene(common, "형사", "그래서 약물을 쓴 건가? 시신에서 다량의 &@#이 검출됐다.", "");
	addScene(common, suspect->getName(), "움직이지 못하게 해야 했으니까.", "");
	addScene(common, suspect->getName(), "가장 아름다울 때, 날 바라보는 그 완벽한 순간에 영원히 멈춰 두고 싶었어.", "");
	addScene(common, suspect->getName(), "늙지도, 변하지도, 날 떠나지도 못하게.", "");
	addScene(common, "형사", "산 사람을 인형처럼 박제하려 했다니, 역겹군.", "");
	addScene(common, suspect->getName(), "역겨워? 하하. 근데 이 세계에서는 그럴 걱정이 없잖아.", "");
	addScene(common, suspect->getName(), "썩지도 변하지도 않지. ‘그녀’가 알려줬어.", "");
	addScene(common, suspect->getName(), "다음은 굳이 번거롭게 내 지하실까지 끌고 올 필요 없이,", "");
	addScene(common, suspect->getName(), "그냥 여기 가둬두면 영원히 내 것으로 만드는 방법이 있다고.", "");
	addScene(common, "형사", "... 그 여자는 네 망상이 아닌건가?", "");
	addScene(common, suspect->getName(), "(피식 웃으며) “당신도 알잖아.“", "");
	addScene(common, "", "", "", "", "지금은 취조중이다. 여긴 네 소설을 듣는 자리 아니니까, 쓸데없는 말 말고 사실 관계만 똑바로 진술해.", "(펜을 내려놓는다. 왜인지 그 말을 부정할 수가 없다.)", 0, 10);

	int choice = playScene(common);
	int sync = getErosionLevel();

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		switch (sync) {
		case 0:
			addScene(branch, PlayerName, "", "박제는 진짜 선 넘었네.");
			addScene(branch, PlayerName, "", "사랑이 아니라 소유욕이지…");
			addScene(branch, girlfriend->getName(), "", "맞아. 사람을 물건처럼 보는 것 같아서 좀 그래.");
			break;
		case 1:
			addScene(branch, PlayerName, "", "박제는 진짜 선 넘었네.");
			addScene(branch, PlayerName, "", "사랑이 아니라 소유욕이지…");
			addScene(branch, girlfriend->getName(), "", "사람을 물건처럼 보는 건가…?");
			break;
		default:
			addScene(branch, "", "", "", "");
			break;
		}
	}
	else if (choice == 2) {
		switch (sync) {
		case 0:
			addScene(branch, PlayerName, "", "박제는 진짜 선 넘었네.");
			addScene(branch, PlayerName, "", "사랑이 아니라 소유욕이지…");
			addScene(branch, girlfriend->getName(), "", "맞아. 사람을 물건처럼 보는 것 같아서 좀 그래.");
			break;
		case 1:
			addScene(branch, girlfriend->getName(), "", "근데 변하지 않았으면 좋겠다는 마음은 이해돼.");
			addScene(branch, PlayerName, "", "사람 마음은 원래 변하는 거지 뭐.");
			addScene(branch, girlfriend->getName(), "", "오빠도 변할 거야?");
			addScene(branch, PlayerName, "", "갑자기…? 당연히 아니지.");
			addScene(branch, girlfriend->getName(), "", "그럼 됐어.");
			break;
		default:
			addScene(branch, girlfriend->getName(), "", "계속 그대로였으면 좋겠다.");
			addScene(branch, PlayerName, "", "뭐가.");
			addScene(branch, girlfriend->getName(), "", "지금 이 상태. 오빠랑 나.");
			addScene(branch, PlayerName, "", "갑자기 감성적이네.");
			addScene(branch, girlfriend->getName(), "", "원래 오래 좋아하면 욕심 생기잖아.");
			addScene(branch, PlayerName, "", "……");
			addScene(branch, girlfriend->getName(), "", "안 변했으면 좋겠고. 안 떠났으면 좋겠고.");
			addScene(branch, "", "", "어딘가 이상하다.");
			addScene(branch, PlayerName, "", "유라야 가서 물 좀 마시고 와.");
			addScene(branch, girlfriend->getName(), "", "아아, 알겠어! 먼저 진행하면 안 돼! 알았지?!");
			break;
		}
	}

	playScene(branch);
}
void GameManager::Chapter6(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, suspect->getName(), "오늘따라 피곤해 보이네. 잠을 못 자셨나?", "");
	addScene(common, "형사", "내 상태는 네가 신경 쓸 것 없다. 여섯 번째 피해자 얘기를 해라.", "");
	addScene(common, suspect->getName(), "여섯 번째… 아~ 그 애.. 처음엔 도망치려고 했는데.", "");
	addScene(common, suspect->getName(), "문을 긁고, 소리를 지르고. 근데 신기하지? 결국엔 다들 조용해져.", "");
	addScene(common, suspect->getName(), "밖에서 아무도 안 오는 걸 알면.", "");
	addScene(common, "형사", "언제부터 감금했지?", "");
	addScene(common, suspect->getName(), "처음 만난 날부터… 좋아하면 곁에 두고 싶은 게 당연하잖아? 그렇지 않아?", "");
	addScene(common, suspect->getName(), "놓아주면 변하지까. 내 손 안에 있을 때만 안 변하거든.", "");
	addScene(common, suspect->getName(), "어느 순간부터 그 애가 나 말고는 아무것도 찾지 않게 됐어.", "");
	addScene(common, suspect->getName(), "전화도 안 하고, 밖에도 안 나가고. 그게 제일 보기 좋았어.", "");
	addScene(common, "형사", "그건 사랑이 아니라 소유욕이다.", "");
	addScene(common, suspect->getName(), "(눈가가 붉어지며) ... 누구나 잃고 싶지 않은 사람이 있는 거 아닌가요, 형사님?", "");		
	addScene(common, "", "", "", "", "(괜히 파일을 넘긴다) ... 다음 질문으로 넘어가지.", "그런 심리 조작 시도는 통하지 않는다. 이미 너에 대한 정보는 알고 있어. 납치 장소를 말해.", 10, 0);

	int choice = playScene(common);
	int sync = getErosionLevel();
	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		switch (sync) {
		case 0:
			addScene(branch, girlfriend->getName(), "", "저 살인마 완전 집착 덩어리네!!");
			addScene(branch, PlayerName, "", "현실이면 바로 잡혀가야지.");
			break;
		case 1:
			addScene(branch, girlfriend->getName(), "", "사람은 계속 혼자 두면 불안해지잖아.");
			addScene(branch, girlfriend->getName(), "", "저 살인마 말이야. 그래서 더 옆에 있고 싶어지는 거 아닐까?");
			addScene(branch, PlayerName, "", "그래도 적당히 해야지.");
			addScene(branch, girlfriend->getName(), "", "뭐든 적당히가 어려운 것 같아.");
			addScene(branch, "", "", "유라가 잠깐 멈칫했다.");
			break;
		default:
			addScene(branch, girlfriend->getName(), "", "난 오빠 없으면 진짜 심심할 거 같아.");
			addScene(branch, PlayerName, "", "안 그래도 우리 하루종일 붙어 있잖아.");
			addScene(branch, girlfriend->getName(), "", "그걸로 부족해..! 지금보다 더 붙어 있고 싶어…");
			addScene(branch, "", "", "유라의 눈이 반짝였다.");
			addScene(branch, PlayerName, "", "지금보다 더…?");
			addScene(branch, girlfriend->getName(), "", "오빠는 특별하니까.");
			addScene(branch, "", "", "무슨 소리를 하는 거지?");
			addScene(branch, "", "", "잠깐 정적이 흘렀다.");
			addScene(branch, girlfriend->getName(), "", "…없어지면 싫을 정도로.");
			addScene(branch, "", "", "오늘따라 유라가 많이 칭얼댄다.");
			addScene(branch, "", "", "기념일을 잊었었나?");
			addScene(branch, "", "", "게임 끝나면 달력을 확인해봐야겠다는 생각이 뇌리를 스쳤다.");
			addScene(branch, PlayerName, "", "(일단 게임에 집중.)");
			break;
		}
	}
	else if (choice == 2) {
		switch (sync) {
		case 0:
			addScene(branch, girlfriend->getName(), "", "저 살인마 완전 집착 덩어리네!!");
			addScene(branch, PlayerName, "", "현실이면 바로 잡혀가야지.");;
			break;
		case 1:
			addScene(branch, girlfriend->getName(), "", "저 살인마 완전 집착 덩어리네!!");
			addScene(branch, PlayerName, "", "현실이면 바로 잡혀가야지.");
			addScene(branch, girlfriend->getName(), "", "오빠는 도망 안 갈 거지?");
			addScene(branch, PlayerName, "", "? 어디를.");
			addScene(branch, girlfriend->getName(), "", "그냥~ 농담.");
			break;
		default:
			addScene(branch, girlfriend->getName(), "", "난 오빠 없으면 진짜 심심할 거 같아.");
			addScene(branch, PlayerName, "", "안 그래도 우리 하루종일 붙어 있잖아.");
			addScene(branch, girlfriend->getName(), "", "그걸로 부족해..! 지금보다 더 붙어 있고 싶어…");
			addScene(branch, "", "", "유라의 눈이 반짝였다.");
			addScene(branch, PlayerName, "", "지금보다 더…?");
			addScene(branch, girlfriend->getName(), "", "오빠는 특별하니까.");
			addScene(branch, "", "", "무슨 소리를 하는 거지?");
			addScene(branch, "", "", "잠깐 정적이 흘렀다.");
			addScene(branch, girlfriend->getName(), "", "…없어지면 싫을 정도로.");
			addScene(branch, "", "", "오늘따라 유라가 많이 칭얼댄다.");
			addScene(branch, "", "", "기념일을 잊었었나?");
			addScene(branch, "", "", "게임 끝나면 달력을 확인해봐야겠다는 생각이 뇌리를 스쳤다.");
			addScene(branch, PlayerName, "", "(일단 게임에 집중.)");
			break;
		}
	}

	playScene(branch);
}

void GameManager::Chapter7(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, suspect->getName(), "있잖아, 형사님 이름 한 번 알려주면 안돼? 우리 오래됐는데.", "");
	addScene(common, "형사", "취조관은 이름을 밝히지 않는다.", "");
	addScene(common, suspect->getName(), "그래도 괜찮아. 이미 알 것 같으니까.", "");
	addScene(common, "형사", "... 그게 무슨 소리지?", "");
	addScene(common, suspect->getName(), "계속 보고 있었잖아. 당신이 어떤 말에 멈추는지, 어떤 질문에 시선을 피하는지.", "");
	addScene(common, suspect->getName(), "이름보다 더 많은 걸 알아버린 거 같아. 궁금해?", "");
	addScene(common, "형사", "(의자를 뒤로 당기며) 헛소리 집어치워.", "");
	addScene(common, suspect->getName(), "(낮고 또렷하게)" + PlayerName, "");
	addScene(common, "형사", "... 내가 이름을 밝힌 적이 있던가? 누가 알려준 거지?", "");
	addScene(common, suspect->getName(), "(잠시 생각하는 듯 고개를 기울이며) “... 형사님이 알려준 것 같기도 하고, 그 여자한테 들은 것 같기도 하고..", "");
	addScene(common, "", "", "", "", "공범이 있다는 거냐. 그 여자 신원을 대라.", "(내가 알려준 적이 없다는 걸 안다. 근데 … 그 여자의 정체는 혹시.)", 0, 10);

	int choice = playScene(common);
	int sync = getErosionLevel();
	
	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		switch (sync) {
		case 0:
			addScene(branch, girlfriend->getName(), "", "와 깜짝이야…");
			addScene(branch, girlfriend->getName(), "", "갑자기 이름 튀어나오는 거 뭐야?");
			addScene(branch, PlayerName, "", "플레이어 닉네임 넣는 연출인가 보지.");
			addScene(branch, girlfriend->getName(), "", "그래도 타이밍 진짜 소름이었다.");
			addScene(branch, girlfriend->getName(), "", "딱 쳐다보면서 말하잖아.");
			addScene(branch, PlayerName, "", "연출은 잘 만든 듯 하네.");
			addScene(branch, girlfriend->getName(), "", "히히.");
			addScene(branch, girlfriend->getName(), "", "오빠 이름 들으니까 괜히 반갑네.");
			break;
		case 1:
			addScene(branch, girlfriend->getName(), "", "근데 진짜 공범 있는 걸까?");
			addScene(branch, PlayerName, "", "계속 “그 여자” 얘기하잖아.");
			addScene(branch, girlfriend->getName(), "", "음… 근데 왠지 저 살인마,");
			addScene(branch, girlfriend->getName(), "", "혼자 착각하는 걸 수도 있을 거 같아.");
			addScene(branch, PlayerName, "", "망상이라는 거?");
			addScene(branch, girlfriend->getName(), "", "응. 좋아하는 사람 생각을 너무 많이 해서.");
			addScene(branch, PlayerName, "", "위험하네 그건.");
			break;
		case 2:
			addScene(branch, girlfriend->getName(), "", "근데 진짜 공범 있는 걸까?");
			addScene(branch, PlayerName, "", "계속 “그 여자” 얘기하잖아.");
			addScene(branch, girlfriend->getName(), "", "음… 근데 왠지 저 살인마,");
			addScene(branch, girlfriend->getName(), "", "혼자 착각하는 걸 수도 있을 거 같아.");
			addScene(branch, PlayerName, "", "망상이라는 거?");
			addScene(branch, girlfriend->getName(), "", "응. 좋아하는 사람 생각을 너무 많이 해서.");
			addScene(branch, PlayerName, "", "위험하네 그건.");
			break;
		default:
			addScene(branch, girlfriend->getName(), "", "이제 알겠어.");
			addScene(branch, PlayerName, "", "뭘…");
			addScene(branch, girlfriend->getName(), "", "저 살인마가 왜 이름을 부르고 싶어 했는지.");
			addScene(branch, PlayerName, "", "왜 그런건데…?");
			addScene(branch, girlfriend->getName(), "", "이름은 제일 쉽게 묶어둘 수 있는 거잖아.");
			addScene(branch, girlfriend->getName(), "", "계속 부르면.");
			addScene(branch, girlfriend->getName(), "", "계속 듣게 하면.");
			addScene(branch, girlfriend->getName(), "", "결국 그 사람 머릿속엔 자기 목소리만 남게 되거든.");
			addScene(branch, PlayerName, "", "무슨 말을 그렇게…");
			addScene(branch, girlfriend->getName(), "", "나도 오빠 이름 엄청 좋아해.");
			addScene(branch, girlfriend->getName(), "", "계속 부르고 싶어.");
			addScene(branch, girlfriend->getName(), "", "계속 듣게 하고 싶고.");
			addScene(branch, girlfriend->getName(), "", "다른 사람들은 아무도 못 부르게 하고 싶어.");
			addScene(branch, PlayerName, "", "…유라야.");
			addScene(branch, girlfriend->getName(), "", "왜 그런 표정이야?");
			addScene(branch, "", "", "유라는 웃었다.");
			addScene(branch, "", "", "노트북 화면 속 살인마도 마치 같은 타이밍에 입꼬리를 올린 것처럼 보였다.");
			addScene(branch, "", "", "평소에는 이렇지 않았는데,");
			addScene(branch, "", "", "다른 공포게임을 같이 할 때와는 느낌이 달랐다.");
			addScene(branch, "", "", "");
			addScene(branch, "", "", "화면에 고정된 시선을 다른 곳으로 뗄 수 없었다");
			break;
		}
	}
	else if (choice == 2) {
		switch (sync) {
		case 0:
			addScene(branch, girlfriend->getName(), "", "와 깜짝이야…");
			addScene(branch, girlfriend->getName(), "", "갑자기 이름 튀어나오는 거 뭐야?");
			addScene(branch, PlayerName, "", "플레이어 닉네임 넣는 연출인가 보지.");
			addScene(branch, girlfriend->getName(), "", "그래도 타이밍 진짜 소름이었다.");
			addScene(branch, girlfriend->getName(), "", "딱 쳐다보면서 말하잖아.");
			addScene(branch, PlayerName, "", "연출은 잘 만든 듯 하네.");
			addScene(branch, girlfriend->getName(), "", "히히.");
			addScene(branch, girlfriend->getName(), "", "오빠 이름 들으니까 괜히 반갑네.");
			break;
		case 1:
			addScene(branch, girlfriend->getName(), "", "난 오빠 이름 부르는 거 좋아.");
			addScene(branch, PlayerName, "", "왜? 갑자기.");
			addScene(branch, girlfriend->getName(), "", "그냥.");
			addScene(branch, girlfriend->getName(), "", "이름 부르면 오빠가 더 가까워진 느낌 나잖아.");
			addScene(branch, PlayerName, "", "그런가?");
			addScene(branch, girlfriend->getName(), "", "응.");
			addScene(branch, girlfriend->getName(), "", "내 쪽만 봐주는 느낌.");
			addScene(branch, "", "", "유라는 장난스럽게 웃었지만 손끝은 어느새 내 소매를 붙잡고 있었다.");
			addScene(branch, PlayerName, "", "그럼 많이 불러줘.");
			addScene(branch, girlfriend->getName(), "", PlayerName + ", " + PlayerName + ", " + PlayerName + "!!");
			break;
		case 2:
			addScene(branch, girlfriend->getName(), "", "근데 저 살인마 말 좀 무섭지 않았어?");
			addScene(branch, PlayerName, "", "어떤 거.");
			addScene(branch, girlfriend->getName(), "", "“계속 보고 있었다”는 거.");
			addScene(branch, PlayerName, "", "…아.");
			addScene(branch, girlfriend->getName(), "", "사실 좋아하면 계속 보게 되잖아.");
			addScene(branch, girlfriend->getName(), "", "그러다보면 알게 되고,");
			addScene(branch, girlfriend->getName(), "", "그 사람이 어떤 표정 지을지.");
			addScene(branch, girlfriend->getName(), "", "뭘 숨기고 있는지.");
			addScene(branch, "", "", "순간, 게임 속 살인마가 했던 대사가 머릿속을 스쳐 지나갔다.");
			addScene(branch, girlfriend->getName(), "", "히히.");
			addScene(branch, girlfriend->getName(), "", "근데 나도 오빠 엄청 많이 알고 있는데.");
			addScene(branch, PlayerName, "", "예를 들면?");
			addScene(branch, girlfriend->getName(), "", "지금 무서워하고 있는 거.");
			addScene(branch, "", "", "괜스레 침을 한번 꼴깍 삼켰다.");
			break;
		default:
			addScene(branch, girlfriend->getName(), "", "이제 알겠어.");
			addScene(branch, PlayerName, "", "뭘…");
			addScene(branch, girlfriend->getName(), "", "저 살인마가 왜 이름을 부르고 싶어 했는지.");
			addScene(branch, PlayerName, "", "왜 그런건데…?");
			addScene(branch, girlfriend->getName(), "", "이름은 제일 쉽게 묶어둘 수 있는 거잖아.");
			addScene(branch, girlfriend->getName(), "", "계속 부르면.");
			addScene(branch, girlfriend->getName(), "", "계속 듣게 하면.");
			addScene(branch, girlfriend->getName(), "", "결국 그 사람 머릿속엔 자기 목소리만 남게 되거든.");
			addScene(branch, PlayerName, "", "무슨 말을 그렇게…");
			addScene(branch, girlfriend->getName(), "", "나도 오빠 이름 엄청 좋아해.");
			addScene(branch, girlfriend->getName(), "", "계속 부르고 싶어.");
			addScene(branch, girlfriend->getName(), "", "계속 듣게 하고 싶고.");
			addScene(branch, girlfriend->getName(), "", "다른 사람들은 아무도 못 부르게 하고 싶어.");
			addScene(branch, PlayerName, "", "…유라야.");
			addScene(branch, girlfriend->getName(), "", "왜 그런 표정이야?");
			addScene(branch, "", "", "유라는 웃었다.");
			addScene(branch, "", "", "노트북 화면 속 살인마도 마치 같은 타이밍에 입꼬리를 올린 것처럼 보였다.");
			addScene(branch, "", "", "평소에는 이렇지 않았는데,");
			addScene(branch, "", "", "다른 공포게임을 같이 할 때와는 느낌이 달랐다.");
			addScene(branch, "", "", "");
			addScene(branch, "", "", "화면에 고정된 시선을 다른 곳으로 뗄 수 없었다");
			break;
		}
	}

	playScene(branch);
}

void GameManager::Chapter8(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, suspect->getName(), "그 사람들이 떠난 게 아니야. 내가 정리한 거지.", "");
	addScene(common, suspect->getName(), "하나씩. 천천히. 티 안 나게.", "");
	addScene(common, "형사", "피해자 주변 인물들은 어떻게 정리했지?", "");
	addScene(common, suspect->getName(), "쉬워. 사람 사이엔 항상 오해할 만한 틈이 있거든.", "");
	addScene(common, suspect->getName(), "그 틈에 작은 걸 하나 심어놓으면… 알아서 멀어져. 내가 손댈 필요도 없이.", "");
	addScene(common, "형사", "그러면 피해자는.", "");
	addScene(common, suspect->getName(), "처음엔 이상하게 생각했겠지. 근데 주변이 하나둘 없어지면 결국 나한테 오게 돼있어.", "");
	addScene(common, suspect->getName(), "달리 갈 데가 없으니까… 그게 제일 편한 방법이었어.", "");
	addScene(common, "형사", "편한 방법.", "");
	addScene(common, suspect->getName(), "(잠시 뜸을 들이며) 누군가 나만 바라보게 만들고 싶으면, 다른 걸 전부 없애면 되거든.", "");
	addScene(common, suspect->getName(), "사랑받으려고 한 게 아니야. 그 사람한테 내가 전부가 되고 싶었던 거지.", "");
	addScene(common, "", "", "", "", "(다른 걸 전부 없애면 된다. 그 말이 어디선가 들어본 것처럼 귀에 걸린다.)", "계획적 고립이었군. 구체적인 수단을 진술해라.", 15, 0);

	int choice = playScene(common);
	int sync = getErosionLevel();

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		switch (sync) {
		case 0:
			addScene(branch, girlfriend->getName(), "", "왜 그래 오빠?");
			addScene(branch, PlayerName, "", "아니…");
			addScene(branch, PlayerName, "", "방금 저 대사 좀 기분 이상해서.");
			addScene(branch, girlfriend->getName(), "", "“다른 걸 전부 없애면 된다” 그거?");
			addScene(branch, PlayerName, "", "응.");
			addScene(branch, girlfriend->getName(), "", "엄청 극단적이긴 하지.");
			addScene(branch, PlayerName, "", "근데 이상하게 계속 귀에 남네.");
			addScene(branch, girlfriend->getName(), "", "오빠 완전 몰입했구나~!");
			break;
		case 1:
			addScene(branch, girlfriend->getName(), "", "저 말. 묘하게 기억에 남지 않아?");
			addScene(branch, PlayerName, "", "…너도?");
			addScene(branch, girlfriend->getName(), "", "응… 사람은 결국 자기한테 제일 필요한 사람만 남기고 싶어하잖아.");
			addScene(branch, "", "", "유라는 턱을 괸 채 화면을 바라봤다.");
			addScene(branch, girlfriend->getName(), "", "좋아하면 욕심이 생기는 건 어쩔 수 없는 거 같아.");
			break;
		case 2:
			addScene(branch, girlfriend->getName(), "", "나도 가끔 그런 생각 해.");
			addScene(branch, PlayerName, "", "무슨 생각.");
			addScene(branch, girlfriend->getName(), "", "오빠 주변 사람들 다 조용해지면 좋겠다고.");
			addScene(branch, PlayerName, "", "…뭐?");
			addScene(branch, girlfriend->getName(), "", "아…! 이상한 뜻이 아니라");
			addScene(branch, girlfriend->getName(), "", "그냥 아무 방해 없이 둘이 있고 싶다는 거였어…");
			addScene(branch, PlayerName, "", "우리 지금도 그렇게 하고 있잖아.");
			addScene(branch, girlfriend->getName(), "", "맞아… 헤헤 그래서 난 지금이 제일 좋아.");
			addScene(branch, "", "", "유라가 사랑스럽게 웃었지만, 시선은 이상할 정도로 진지했다.");
			break;
		default:
			addScene(branch, girlfriend->getName(), "", "결국 사람은 하나만 남기고 싶어지는 거야.");
			addScene(branch, PlayerName, "", "유라야…");
			addScene(branch, girlfriend->getName(), "", "좋아하는 게 커질수록 더.");
			addScene(branch, PlayerName, "", "그건 정상 아니야.");
			addScene(branch, "","", "정말 그럴까?");
			addScene(branch, girlfriend->getName(), "", "근데 오빠도 알잖아.");
			addScene(branch, girlfriend->getName(), "", "누군가가 자기만 봐줬으면 좋겠다는 마음.");
			addScene(branch, "", "", "속으로는 나도 이렇게 생각하고 있었을지 모른다.");
			addScene(branch, "", "", "잠깐 정적이 흘렀다.");
			addScene(branch, "", "", "유라는 천천히 내 손가락 사이를 깍지 끼웠다.");
			addScene(branch, girlfriend->getName(), "", "난 오빠한테 내가 제일 중요했으면 좋겠어.");
			addScene(branch, girlfriend->getName(), "", "다른 사람들보다 훨씬 더.");
			break;
		}
	}
	else if (choice == 2) {
		switch (sync) {
		case 0:
			addScene(branch, girlfriend->getName(), "", "오빠의 선택 엄청 냉정해…!");
			addScene(branch, PlayerName, "", "다른 선택지 고르는 게 하수지.");
			addScene(branch, girlfriend->getName(), "", "근데 저 살인마 진짜 음침하다…");
			addScene(branch, girlfriend->getName(), "", "사람 관계를 일부러 망가뜨린 거잖아.");
			addScene(branch, PlayerName, "", "현실에서도 저런 타입이 제일 무섭지.");
			addScene(branch, girlfriend->getName(), "", "맞아.");
			addScene(branch, girlfriend->getName(), "", "겉으로는 티도 안 나고.");
			break;
		case 1:
			addScene(branch, girlfriend->getName(), "", "사람 사이 멀어지는 건 진짜 한순간인 거 같아.");
			addScene(branch, PlayerName, "", "갑자기?");
			addScene(branch, girlfriend->getName(), "", "그냥.");
			addScene(branch, girlfriend->getName(), "", "오해 하나만 생겨도 금방 어색해지잖아.");
			addScene(branch, PlayerName, "", "그렇긴 하지.");
			addScene(branch, girlfriend->getName(), "", "그래서 저 살인마가 더 무서운 거 같아.");
			addScene(branch, girlfriend->getName(), "", "굳이 직접 뭘 안 해도 되니까.sf");
			addScene(branch, PlayerName, "", "계획형 범죄 느낌이지.");
			addScene(branch, girlfriend->getName(), "", "맞아…");
			break;
		case 2:
			addScene(branch, girlfriend->getName(), "", "근데 조금 이해는 간다");
			addScene(branch, PlayerName, "", "뭐가?");
			addScene(branch, girlfriend->getName(), "", "좋아하는 사람이 자꾸 다른 사람들이랑 더 가까우면…");
			addScene(branch, girlfriend->getName(), "", "괜히 신경 쓰이잖아.");
			addScene(branch, PlayerName, "", "그걸 저렇게 해결하면 안 되지.");
			addScene(branch, girlfriend->getName(), "", "당연히 진짜로 그러면 안 되지~!!");
			addScene(branch, girlfriend->getName(), "", "근데 마음 자체는 이해된다는 거야.");
			addScene(branch, PlayerName, "", "또 위험한 말 한다.");
			addScene(branch, girlfriend->getName(), "", "게임에 몰입해 버렸어…!!");
			break;
		default:
			addScene(branch, girlfriend->getName(), "", "오빠는 내가 제일 가까운 사람이지?");
			addScene(branch, PlayerName, "", "갑자기 그건 왜 물어.");
			addScene(branch, girlfriend->getName(), "", "그냥 확인하고 싶어서.");
			addScene(branch, PlayerName, "", "뭐… 그렇지.");
			addScene(branch, girlfriend->getName(), "", "다행이다.");
			addScene(branch, "", "", "유라는 작게 웃더니");
			addScene(branch, "", "", "내 팔에 천천히 기대왔다.");
			addScene(branch, girlfriend->getName(), "", "사람은 결국 제일 편한 데로 가게 되잖아.");
			addScene(branch, PlayerName, "", "……");
			addScene(branch, girlfriend->getName(), "", "오빠한테 나는 그런 사람이면 좋겠어.");
			break;
		}
	}
	playScene(branch);
}

void GameManager::Chapter9(std::vector<GameScene>& script) {
	std::vector<GameScene> common;
	addScene(common, suspect->getName(), "마지막으로 하나만 물어봐도 돼? 형사로서 말고. 그냥 사람 대 사람으로.", "");
	addScene(common, "형사", "...", "");
	addScene(common, suspect->getName(), "그 사람이 나한테 말했어. 언젠가 농담처럼.", "");
	addScene(common, suspect->getName(), "‘나만 바라봐주는 사람이 좋더라’고.", "");
	addScene(common, "형사", "...", "");
	addScene(common, suspect->getName(), "그 말 한 마디면 충분했어. 그게 전부였거든.", "");
	addScene(common, suspect->getName(), "그 사람이 원하는 걸 내가 이뤄준 것뿐이야. 나만 바라보게 만들었으니까.", "");
	addScene(common, "형사", "그게 살인의 이유인가..?", "");
	addScene(common, suspect->getName(), "(고개를 젓는다) 살인이 아니라 완성이지.", "");
	addScene(common, suspect->getName(), "(아주 낮은 목소리로) ... 형사님도 누군가한테 그런 말 한 적 있지 않아요?", "");
	addScene(common, "형사", "(그 말이 왜 이렇게 오래 머무르는 건지 모르겠다.)", "");
	addScene(common, "", "", "", "", "취조를 종료한다. 최종 진술을 녹취하겠다.", "(있다. 분명히 있다. 근데 왜 지금 그게 떠오르는 거지.)", 0, 15);

	int choice = playScene(common);
	int sync = getErosionLevel();

	std::vector<GameScene> branch; //분기
	if (choice == 1) {
		switch (sync) {
		case 0:
			addScene(branch, girlfriend->getName(), "", "오…");
			addScene(branch, girlfriend->getName(), "", "끝까지 완전 형사처럼 갔네.");
			addScene(branch, PlayerName, "", "저런 말에 휘둘리면 안 되니까.");
			addScene(branch, girlfriend->getName(), "", "살인이 아니라 완성이라니…");
			addScene(branch, PlayerName, "", "정상적인 사고는 아니지.");
			addScene(branch, girlfriend->getName(), "", "응. 좋아한다고 사람을 자기한테 맞춰 바꾸려는 거잖아.");
			addScene(branch, girlfriend->getName(), "", "이제 게임이 거의 끝난 것 같은데? 게임 분위기는 진짜 좋았다.");
			addScene(branch, girlfriend->getName(), "", "오빠랑 같이 오랜만에 게임하니까 너무 좋았어ㅎㅎ");
			break;
		case 1:
			addScene(branch, girlfriend->getName(), "", "오빠는 냉정하네.");
			addScene(branch, PlayerName, "", "선택지 말이야?");
			addScene(branch, girlfriend->getName(), "", "아니…");
			addScene(branch, girlfriend->getName(), "", "난 마지막 말 조금 무서웠어.");
			addScene(branch, PlayerName, "", "“나만 바라봐주는 사람”?");
			addScene(branch, PlayerName, "", "그냥 흔한 집착 대사지.");
			addScene(branch, girlfriend->getName(), "", "근데 은근 기억 남지 않아?");
			addScene(branch, girlfriend->getName(), "", "오빠랑 오랜만에 게임 하니까 너무 재밌었어…ㅎㅎ");
			break;
		case 2:
			addScene(branch, girlfriend->getName(), "", "나도 저 말 이해는 가.");
			addScene(branch, PlayerName, "", "뭐가.");
			addScene(branch, girlfriend->getName(), "", "좋아하면 자꾸 확인하고 싶잖아.");
			addScene(branch, girlfriend->getName(), "", "내가 제일 중요한 사람인지.");
			addScene(branch, PlayerName, "", "다들 어느 정도는 그렇지.");
			addScene(branch, girlfriend->getName(), "", "응.근데 어떤 사람들은 그 마음이 너무 커지는 거고.");
			addScene(branch, "", "", "잠깐 침묵이 흘렀다.");
			addScene(branch, girlfriend->getName(), "", "오빠는 안 떠날 거지?");
			addScene(branch, PlayerName, "", "갑자기 왜 그런 말을 해.");
			addScene(branch, girlfriend->getName(), "", "그냥…. 갑자기 불안해져서.");
			addScene(branch, girlfriend->getName(), "", "좋아하는 사람한테 그런 말 한 적 없어?");
			addScene(branch, PlayerName, "", "무슨 말");
			addScene(branch, girlfriend->getName(), "", "“나만 봐달라” 같은 거.");
			addScene(branch, PlayerName, "", "장난으로는 있지.");
			addScene(branch, girlfriend->getName(), "", "그렇구나.");
			addScene(branch, "", "", "유라는 괜히 웃으면서도");
			addScene(branch, "", "", "내 얼굴을 한참 바라봤다.");
			addScene(branch, girlfriend->getName(), "", "근데 사람은 좋아하면 욕심 생기는 거 같아.");
			addScene(branch, girlfriend->getName(), "", "계속 자기만 봐줬으면 싶고.");
			addScene(branch, PlayerName, "", "적당해야지 그런 건.");
			addScene(branch, girlfriend->getName(), "", "응. 적당해야지.");
			break;
		case 3:
			addScene(branch, girlfriend->getName(), "", "오빠는 내가 제일 중요해?");
			addScene(branch, PlayerName, "", "갑자기 그건 왜.");
			addScene(branch, girlfriend->getName(), "", "그냥 궁금해서.");
			addScene(branch, PlayerName, "", "당연히 중요하지.");
			addScene(branch, girlfriend->getName(), "", "제일?");
			addScene(branch, PlayerName, "", "...유라야.");
			addScene(branch, girlfriend->getName(), "", "히히.");
			addScene(branch, girlfriend->getName(), "", "농담이야.");
			addScene(branch, "", "", "그렇게 말했지만,");
			addScene(branch, "", "", "유라는 내 대답을 기다리는 사람처럼 조용히 웃고 있었다.");
			break;
		default:
			addScene(branch, girlfriend->getName(), "", "결국 저 살인마도");
			addScene(branch, girlfriend->getName(), "", "좋아하는 사람한테 인정받고 싶었던 거겠지.");
			addScene(branch, PlayerName, "", "그 방식이 잘못된 거고.");
			addScene(branch, girlfriend->getName(), "", "응.");
			addScene(branch, girlfriend->getName(), "", "근데 계속 혼자 두면 사람은 이상해지잖아.");
			addScene(branch, PlayerName, "", "...");
			addScene(branch, girlfriend->getName(), "", "나만 봐줬으면 좋겠다는 생각도 커지고.");
			addScene(branch, girlfriend->getName(), "", "다른 건 다 거슬리게 되고.");
			addScene(branch, PlayerName, "", "유라.");
			addScene(branch, girlfriend->getName(), "", "난 그냥...");
			addScene(branch, girlfriend->getName(), "", "오빠가 내 옆에 오래 있었으면 좋겠어.");
			addScene(branch, "", "", "유라는 웃으며 말했지만, ");
			addScene(branch, "", "", "손끝은 내 손목을 놓지 않고 있었다.");
			break;
		}
	}
	else if (choice == 2) {
		switch (sync) {
		case 0:
			addScene(branch, girlfriend->getName(), "", "살인이 아니라 완성이라니…");
			addScene(branch, PlayerName, "", "정상적인 사고는 아니지.");
			addScene(branch, girlfriend->getName(), "", "응. 좋아한다고 사람을 자기한테 맞춰 바꾸려는 거잖아.");
			addScene(branch, girlfriend->getName(), "", "이제 게임이 거의 끝난 것 같은데? 게임 분위기는 진짜 좋았다.");
			addScene(branch, girlfriend->getName(), "", "오빠랑 같이 오랜만에 게임하니까 너무 좋았어ㅎㅎ");
			break;
		case 1:
			addScene(branch, girlfriend->getName(), "", "왜 그래 오빠?");
			addScene(branch, girlfriend->getName(), "", "표정 이상해.");
			addScene(branch, PlayerName, "", "아니...");
			addScene(branch, PlayerName, "", "방금 대사가 좀 걸려서.");
			addScene(branch, girlfriend->getName(), "", "“나만 바라봐주는 사람이 좋다” 그거 ? ");
			addScene(branch, PlayerName, "", "응.");
			addScene(branch, girlfriend->getName(), "", "연인끼리는 한 번쯤 하는 말 아니야?");
			addScene(branch, PlayerName, "", "그렇긴 한데...");
			addScene(branch, girlfriend->getName(), "", "오빠도 전에 비슷한 말 했었잖아.");
			addScene(branch, PlayerName, "", "내가?");
			addScene(branch, girlfriend->getName(), "", "기억 안 나?");
			addScene(branch, "", "", "유라는 장난스럽게 웃었지만, 왠지 모르게 그 말이 오래 남았다.");
			break;
		case 2:
			addScene(branch, girlfriend->getName(), "", "나도 저 말 이해는 가.");
			addScene(branch, PlayerName, "", "뭐가.");
			addScene(branch, girlfriend->getName(), "", "좋아하면 자꾸 확인하고 싶잖아.");
			addScene(branch, girlfriend->getName(), "", "내가 제일 중요한 사람인지.");
			addScene(branch, PlayerName, "", "다들 어느 정도는 그렇지.");
			addScene(branch, girlfriend->getName(), "", "응.근데 어떤 사람들은 그 마음이 너무 커지는 거고.");
			addScene(branch, "", "", "잠깐 침묵이 흘렀다.");
			addScene(branch, girlfriend->getName(), "", "오빠는 안 떠날 거지?");
			addScene(branch, PlayerName, "", "갑자기 왜 그런 말을 해.");
			addScene(branch, girlfriend->getName(), "", "그냥…. 갑자기 불안해져서.");
			addScene(branch, girlfriend->getName(), "", "좋아하는 사람한테 그런 말 한 적 없어?");
			addScene(branch, PlayerName, "", "무슨 말");
			addScene(branch, girlfriend->getName(), "", "“나만 봐달라” 같은 거.");
			addScene(branch, PlayerName, "", "장난으로는 있지.");
			addScene(branch, girlfriend->getName(), "", "그렇구나.");
			addScene(branch, "", "", "유라는 괜히 웃으면서도");
			addScene(branch, "", "", "내 얼굴을 한참 바라봤다.");
			addScene(branch, girlfriend->getName(), "", "근데 사람은 좋아하면 욕심 생기는 거 같아.");
			addScene(branch, girlfriend->getName(), "", "계속 자기만 봐줬으면 싶고.");
			addScene(branch, PlayerName, "", "적당해야지 그런 건.");
			addScene(branch, girlfriend->getName(), "", "응. 적당해야지.");
			break;
		case 3:
			addScene(branch, girlfriend->getName(), "", "오빠는 내가 그런 말 하면 부담스러워?");
			addScene(branch, PlayerName, "", "어떤 말.");
			addScene(branch, girlfriend->getName(), "", "나만 봐달라는 거.");
			addScene(branch, PlayerName, "", "...상황에 따라 다르지.");
			addScene(branch, girlfriend->getName(), "", "난 가끔 진짜 그렇게 생각해.");
			addScene(branch, PlayerName, "", "유라야.");
			addScene(branch, girlfriend->getName(), "", "오빠가 다른 데 보고 있으면 괜히 신경 쓰여.");
			addScene(branch, girlfriend->getName(), "", "왜 그런지 모르겠는데, 계속 확인하고 싶고.");
			addScene(branch, PlayerName, "", "게임 때문에 과몰입한 거 아냐?");
			addScene(branch, girlfriend->getName(), "", "그럴까?");
			addScene(branch, "", "", "유라는 웃었지만, ");
			addScene(branch, "", "", "눈은 전혀 웃지 못하고 있었다.");
			break;
		default:
			addScene(branch, girlfriend->getName(), "", "이제 조금 알 거 같아.");
			addScene(branch, PlayerName, "", "뭘...");
			addScene(branch, girlfriend->getName(), "", "왜 사람이 망가지는지.");
			addScene(branch, PlayerName, "", "...");
			addScene(branch, girlfriend->getName(), "", "좋아하는 게 너무 커지면, ");
			addScene(branch, girlfriend->getName(), "", "다른 건 안 보이게 되잖아.");
			addScene(branch, PlayerName, "", "유라.");
			addScene(branch, girlfriend->getName(), "", "난 오빠만 있으면 되는데, ");
			addScene(branch, girlfriend->getName(), "", "오빠는 자꾸 다른 걸 보려고 하니까 불안해.");
			addScene(branch, PlayerName, "", "그런 말 하지 마.");
			addScene(branch, girlfriend->getName(), "", "왜?");
			addScene(branch, girlfriend->getName(), "", "난 진심인데.");
			addScene(branch, "", "", "유라는 천천히 내 어깨에 기대며 작게 웃었다.");
			addScene(branch, girlfriend->getName(), "", "계속 같이 있으면 안 돼?");
			addScene(branch, girlfriend->getName(), "", "오래오래.");
			break;
		}
	}

	playScene(branch);
}

// 아이템 획득 시나리오
void GameManager::itemScene(std::vector<GameScene>& script) {
	addScene(script, girlfriend->getName(), "", "오빠 이거 봐봐! 내가 만든 간식인데 맛있어!");
	addScene(script, girlfriend->getName(), "", "내가 밤새워서 레시피 연구한 건데!");
	addScene(script, girlfriend->getName(), "", "오빠가 좋아하는 맛으로 만들었어!");
	addScene(script, "", "", "", "여자친구가 수상한 간식을 건넸다. 지금은 배가 안 고프니 나중에 먹어야지. ");
}

// 아이템 사용 시나리오
void GameManager::itemUsing(std::vector<GameScene>& script) {
	addScene(script, girlfriend->getName(), "", "내가 준 과자 안먹을거야?");
	addScene(script, girlfriend->getName(), "", "안 먹으면 후회할텐데");
	addScene(script, "", "", "", "수상한 간식을 먹겠습니까?", "먹는다", "먹지 않는다", -20, 0);
}

void GameManager::BadEndingScene(std::vector<GameScene>& script) {
	addScene(script, "", "", "", "[Sync Error: 100.00% … Connection Established] 환영합니다. 게임을 재시작합니다.");
	addScene(script, "", "", "", "화면이 꺼지지 않는다.");
	addScene(script, girlfriend->getName(), "", "", "…오빠.");
	addScene(script, PlayerName, "", "", "응.");
	addScene(script, girlfriend->getName(), "", "", "재밌었어?");
	addScene(script, PlayerName, "", "", "응.");
	addScene(script, girlfriend->getName(), "", "", "다행이다.");
	addScene(script, "", "", "", "유라가 조용히 가방을 연다.");
	addScene(script, "", "", "", "USB 하나를 꺼낸다.");
	addScene(script, girlfriend->getName(), "", "", "있잖아, 이거도 찾았는데.");
	addScene(script, girlfriend->getName(), "", "", "이번엔 좀 더 어려운 거래. 오빠 잘 할 수 있을 것 같아서 가져왔어.");
	addScene(script, girlfriend->getName(), "", "", "해볼래?");
	addScene(script, "", "", "", "주인공은 아무 말 없이 USB를 받아든다.");
	addScene(script, "", "", "", "컴퓨터에 꽂는다.");
	addScene(script, girlfriend->getName(), "", "", "(작게, 혼잣말처럼) …잘됐다.");
	addScene(script, "", "", "", "화면에 타이틀이 뜬다.");
	addScene(script, "", "", "", "처음 보는 게임이다.");
	addScene(script, "", "", "", "아니.");
	addScene(script, "", "", "", "똑같은 게임이다.");
	addScene(script, "", "", "", "[ 게임을 시작합니다. ]");
	addScene(script, "", "", "", "END - Sync 100% [Connection Established]");
}

void GameManager::NormalEndingScene(std::vector<GameScene>& script) {
	addScene(script, "", "", "", "[Sync Error: ??% … Signal Fading] 경고: 일부 데이터가 손상되었습니다. 게임이 종료되었습니다.");
	addScene(script, "", "", "", "화면이 꺼진다.");
	addScene(script, girlfriend->getName(), "", "", "다 했다~ 어땠어?");
	addScene(script, PlayerName, "", "", "…나쁘지 않았어.");
	addScene(script, girlfriend->getName(), "", "", "그치? 내가 게임 하나는 잘 찾았지! 히히.");
	addScene(script, girlfriend->getName(), "", "", "오빠 엔딩 보면서 표정이 좀 이상했는데, 무서웠어?");
	addScene(script, PlayerName, "", "", "아니.");
	addScene(script, girlfriend->getName(), "", "", "그럼?");
	addScene(script, PlayerName, "", "", "…그냥 좀 복잡했어.");
	addScene(script, girlfriend->getName(), "", "", "(웃으며) 뭐가 복잡해~ 게임인데.");
	addScene(script, "", "", "", "유라가 내 옆에 바짝 붙어 앉았다.");
	addScene(script, girlfriend->getName(), "", "", "오빠 나 배고파. 뭐 시켜먹을까?");
	addScene(script, PlayerName, "", "", "…아무거나.");
	addScene(script, girlfriend->getName(), "", "", "또 아무거나야~ 오빠가 골라봐.");
	addScene(script, "", "", "", "잠시 유라를 바라봤다.");
	addScene(script, "", "", "", "항상 웃고 있다.");
	addScene(script, "", "", "", "처음 만났을 때부터 지금까지.");
	addScene(script, "", "", "", "뭔가 물어보고 싶은 말이 있었는데.");
	addScene(script, "", "", "", "입이 떨어지지 않았다.");
	addScene(script, "", "", "", "항상 웃고 있는 유라의 얼굴이 처음으로 낯설었지만, 그 이유를 알고 싶지 않았다.");
	addScene(script, "", "", "", "전처럼 시시콜콜한 대화를 하며");
	addScene(script, "", "", "", "유라가 있는 이 집에 계속 있고 싶다는 생각만이 머릿속을 가득 채웠다.");
	addScene(script, girlfriend->getName(), "", "", "오빠 뭐 시킬 거냐니깐?!");
	addScene(script, PlayerName, "", "", "…치킨.");
	addScene(script, girlfriend->getName(), "", "", "오~ 치킨! 좋아. 내가 시킬게.");
	addScene(script, "", "", "", "유라가 핸드폰을 꺼내 주문 앱을 열었다.");
	addScene(script, "", "", "", "나는 다시 꺼진 화면만을 바라본다.");
	addScene(script, "", "", "", "그냥 묻지 않기로 한다.");
	addScene(script, "", "", "", "이대로가 좋아.");
	addScene(script, "", "", "", "END - Sync ??% [Signal Lost]");
}

void GameManager::HappyEndingScene(std::vector<GameScene>& script) {
	addScene(script, "", "", "", "[Sync Error: ??% … Connection Lost] 게임이 종료되었습니다.");
	addScene(script, "", "", "", "화면이 꺼진다.");
	addScene(script, girlfriend->getName(), "", "", "다 했다~");
	addScene(script, PlayerName, "", "", "응.");
	addScene(script, girlfriend->getName(), "", "", "...어땠어?");
	addScene(script, PlayerName, "", "", "나쁘지 않았어.");
	addScene(script, "", "", "", "평소 같으면 “그치? 내가 잘 찾았지!” 하고 웃었을 텐데.");
	addScene(script, "", "", "", "오늘은 그냥 조용히 끄덕인다.");
	addScene(script, girlfriend->getName(), "", "", "...오빠.");
	addScene(script, PlayerName, "", "", "응?");
	addScene(script, girlfriend->getName(), "", "", "나 오늘 일찍 가야 할 것 같아.");
	addScene(script, PlayerName, "", "", "어? 왜? 밥 먹고 가지.");
	addScene(script, girlfriend->getName(), "", "", "괜찮아. 오늘은 그냥 가고 싶어.");
	addScene(script, girlfriend->getName(), "", "", "오빠, 있잖아.");
	addScene(script, PlayerName, "", "", "응.");
	addScene(script, girlfriend->getName(), "", "", "...아무것도 아니야. 잘 자.");
	addScene(script, "", "", "", "현관문이 닫힌다.");
	addScene(script, "", "", "", "유라가 나가자, 코 끝을 찌르는 악취가 나기 시작했다.");
	addScene(script, "", "", "", "신문지로 막아둔 창문 때문에 하루종일 어두컴컴했던 공간도,");
	addScene(script, "", "", "", "걸을 때마다 찐득찐득 거리는 방바닥도,");
	addScene(script, "", "", "", "유라가 나가자마자 눈에 들어온 것들이다.");
	addScene(script, "", "", "", "여자친구가 곁에 있을 때는 몰랐던 것들이었다.");
	addScene(script, "", "", "", "한동안 문을 바라봤다.");
	addScene(script, "", "", "", "유라가 평소랑 뭔가 다른 것 같았는데, 뭐가 다른지 모르겠다.");
	addScene(script, "", "", "", "핸드폰을 집어든다.");
	addScene(script, "", "", "", "오랫동안 열지 않은 채팅방들이 눈에 들어온다.");
	addScene(script, "", "", "", "읽지 않은 메시지들. 다들 언제부턴가 연락이 끊겼다.");
	addScene(script, "", "", "", "아니, 내가 끊었나.");
	addScene(script, "", "", "", "커서가 입력창 위에서 한동안 깜빡인다.");
	addScene(script, "", "", "", "그냥 보낸다.");
	addScene(script, "", "", "", "뭐라고 답장이 올지, 오기는 할지.");
	addScene(script, "", "", "", "그것까지는 모르겠다.");
	addScene(script, "", "", "", "그래도 일단 보냈다.");
	addScene(script, "", "", "", "END - Sync ? ? % [Connection Lost]");
}