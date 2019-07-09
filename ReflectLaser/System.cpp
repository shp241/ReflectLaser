#include "System.h"

list<Button*> System::buttons = {};//��ť����
Level* System::game = new Level();//ָʾ��ǰ���е���Ϸ
Level* System::levels[12] = {};
bool System::musicOn = true;
int System::chapters = 0;//ָʾ��ǰ���еĹؿ�

void System::initialize() {
	Picture::open();
	System::resetLevel();
	Picture::putPicture("Menu\\MainWindow");//������ҳ��ı���
	Button* BStart = new Start(new Point(400, 180), new Point(400 + 250, 180 + 80));//ʵ�����ĸ����˵���ť
	Button* BOption = new Option(new Point(400, 280), new Point(400 + 250, 280 + 80));
	Button* BHelp = new Help(new Point(400, 380), new Point(400 + 250, 380 + 80));
	Button* BExit = new Exit(new Point(400, 480), new Point(400 + 250, 480 + 80));
	System::add(BStart);//�������ĸ���ť����buttons������
	System::add(BOption);
	System::add(BHelp);
	System::add(BExit);
	System::music("Music\\MenuMusic.wav");
}

void System::add(Button* x) {
	buttons.push_back(x);
}

void System::clear() {
	list<Button*>::iterator it;
	for (it = buttons.begin(); it != buttons.end(); ++it) {
		delete *it;
	}
	buttons.clear();
}

void System::system() {
	initialize();
	forButtons();
}

void System::forButtons() {
	list<Button*>::iterator it;
	MOUSEMSG m;
	while (Picture::opening) {
		FlushMouseMsgBuffer();//���������뻺����
		m = GetMouseMsg();
		if (m.mkLButton) {
			for (it = buttons.begin(); it != buttons.end(); ++it) {
				if ((*it)->ifClick(m.x, m.y)) {
					(*it)->role();
					Sleep(100);
					break;
				}
			}
		}
	}
}

void System::refresh() {
	Button* BNext = new Chapter(new Point(640, 400), new Point(640 + 120, 400 + 40), (chapters + 1) % 12);
	Button* BBack = new Start(new Point(640, 460), new Point(640 + 120, 460 + 40));
	Button* BAntiClocked = new Rotate(new Point(640, 320), new Point(640 + 40, 320 + 40), false);
	Button* BClocked = new Rotate(new Point(720, 320), new Point(720 + 40, 320 + 40), true);
	clear();//�����������еİ�ťɾ��
	RelativePoint* p1 = new RelativePoint(0, 0);
	for (int i = 0; i < 15; i++) {
		p1->setX(i);
		for (int j = 0; j < 15; j++) {
			p1->setY(j);
			(*game->getMap())[*p1]->clear();
			Button* BBlock = new BlockButton(game->getBlock(*p1));
			add(BBlock);
		}
	}//��225�����鰴ť��������
	for (int i = 0; i < 24; i++) {
		game->getItem(i)->clear();
		Button* BItem = new BlockButton(game->getItem(i));
		add(BItem);
	}//��24�����߰�ť��������
	game->getCache()->clear();
	add(BAntiClocked);
	add(BClocked);
	add(BNext);
	add(BBack);
	Picture::putPicture("Menu\\PlayingWindow");
	game->draw();
	if (game->isWin()) {
		clear();
		Picture::putPicture("Menu\\SuccessNotice", Point(250, 200));
		Button* BClose = new Close(new Point(489, 368), new Point(489 + 54, 368 + 25));
		Button* BNext = new Chapter(new Point(640, 400), new Point(640 + 120, 400 + 40), (chapters + 1) % 12);
		Button* BBack = new Start(new Point(640, 460), new Point(640 + 120, 460 + 40));
		add(BNext);
		add(BBack);
		add(BClose);
	}
}

void System::music(string m) {
	PlaySound(m.c_str(), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void System::resetLevel() {
	for (int i = 0; i < 12; i++) {
		levels[i] = new Level();
	}
	int c;
	//Level_0
	{
		c = 0;
		for (int i = 0; i < 3; i++) {
			levels[c]->setItem(i, new Mirror());
		}
		levels[c]->addEmitter(new Emitter(new RelativePoint(3, 8), new Colour(Colour::COLOUR_RED), 2));
		levels[c]->addEmitter(new Emitter(new RelativePoint(12, 6), new Colour(Colour::COLOUR_BLUE), 6));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_BLUE), new RelativePoint(7, 9)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(8, 6)));
	}

	//Level_1
	{c++;
	for (int i = 0; i < 3; i++) {
		levels[c]->setItem(i, new Mirror());
	}
	levels[c]->addEmitter(new Emitter(new RelativePoint(0, 3), new Colour(Colour::COLOUR_BLUE), 3));
	levels[c]->addEmitter(new Emitter(new RelativePoint(3, 14), new Colour(Colour::COLOUR_GREEN), 1));
	levels[c]->addEmitter(new Emitter(new RelativePoint(14, 11), new Colour(Colour::COLOUR_RED), 6));
	levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_YELLOW), new RelativePoint(7, 4)));
	levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_MAGENTA), new RelativePoint(7, 8)));
	levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_CYAN), new RelativePoint(9, 6)));
	}

	//Level_2
	{
		c++;
		for (int i = 0; i < 1; i++) {
			levels[c]->setItem(i, new Mirror());
		}
		for (int i = 1; i < 4; i++) {
			levels[c]->setItem(i, new DoubleMirror());
		}
		levels[c]->addEmitter(new Emitter(new RelativePoint(2, 9), new Colour(Colour::COLOUR_RED), 2));
		levels[c]->addEmitter(new Emitter(new RelativePoint(12, 5), new Colour(Colour::COLOUR_BLUE), 6));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_BLUE), new RelativePoint(5, 5)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_BLUE), new RelativePoint(10, 6)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_BLUE), new RelativePoint(8, 10)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(2, 6)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(5, 11)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(11, 9)));
	}

	//Level_3
	{
		c++;
		for (int i = 0; i < 3; i++) {
			levels[c]->setItem(i, new DoubleMirror());
		}
		levels[c]->addEmitter(new Emitter(new RelativePoint(1, 7), new Colour(Colour::COLOUR_GREEN), 2));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_GREEN), new RelativePoint(4, 4)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_GREEN), new RelativePoint(8, 4)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_GREEN), new RelativePoint(9, 3)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_GREEN), new RelativePoint(6, 5)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_GREEN), new RelativePoint(6, 11)));
	}

	//Level_4
	{
		c++;
		for (int i = 0; i < 3; i++) {
			levels[c]->setItem(i, new Mirror());
		}
		for (int i = 3; i < 4; i++) {
			levels[c]->setItem(i, new HalfMirror());
		}
		for (int i = 3; i < 12; i++) {
			for (int j = 1; j < 6; j++) {
				levels[c]->getMap()->change(new RelativePoint(i, j), new Wall());
			}
		}
		levels[c]->getMap()->clearBlock(new RelativePoint(5, 3));
		levels[c]->getMap()->clearBlock(new RelativePoint(9, 3));
		levels[c]->getMap()->clearBlock(new RelativePoint(6, 4));
		levels[c]->getMap()->clearBlock(new RelativePoint(8, 4));
		levels[c]->getMap()->clearBlock(new RelativePoint(7, 5));
		levels[c]->addEmitter(new Emitter(new RelativePoint(1, 7), new Colour(Colour::COLOUR_RED), 2));
		levels[c]->addEmitter(new Emitter(new RelativePoint(13, 8), new Colour(Colour::COLOUR_GREEN), 6));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_GREEN), new RelativePoint(10, 2)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(4, 2)));
	}

	//Level_5
	{
		c++;
		for (int i = 0; i < 1; i++) {
			levels[c]->setItem(i, new Mirror());
		}
		for (int i = 1; i < 19; i++) {
			levels[c]->setItem(i, new HalfMirror());
		}
		for (int i = 0; i < 12; i++) {
			levels[c]->getMap()->change(new RelativePoint(i, 3), new Wall());
		}
		for (int i = 4; i < 13; i++) {
			levels[c]->getMap()->change(new RelativePoint(11, i), new Wall());
		}
		for (int i = 2; i < 11; i++) {
			levels[c]->getMap()->change(new RelativePoint(i, 12), new Wall());
		}
		for (int i = 6; i < 12; i++) {
			levels[c]->getMap()->change(new RelativePoint(2, i), new Wall());
		}
		for (int i = 3; i < 9; i++) {
			levels[c]->getMap()->change(new RelativePoint(i, 6), new Wall());
		}
		for (int i = 7; i < 11; i++) {
			levels[c]->getMap()->change(new RelativePoint(8, i), new Wall());
		}
		for (int i = 4; i < 8; i++) {
			levels[c]->getMap()->change(new RelativePoint(i, 10), new Wall());
		}
		for (int i = 4; i < 7; i++) {
			levels[c]->getMap()->change(new RelativePoint(i, 8), new Wall());
		}
		levels[c]->getMap()->change(new RelativePoint(4, 9), new Wall());
		levels[c]->addEmitter(new Emitter(new RelativePoint(0, 1), new Colour(Colour::COLOUR_RED), 2));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(12, 1)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(13, 2)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(11, 13)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(8, 14)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(1, 9)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(2, 5)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(7, 5)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(10, 8)));
		levels[c]->addTarget(new Target(new Colour(Colour::COLOUR_RED), new RelativePoint(5, 9)));
	}

	//Level_6
}

//MainMenu��
MainMenu::MainMenu(Point* p0, Point* p1) :Button(p0, p1) {}

void MainMenu::role() {
	System::clear();
	Picture::putPicture("Menu\\MainWindow");//������ҳ��ı���
	Button* BStart = new Start(new Point(400, 180), new Point(400 + 250, 180 + 80));//ʵ�����ĸ����˵���ť
	Button* BOption = new Option(new Point(400, 280), new Point(400 + 250, 280 + 80));
	Button* BHelp = new Help(new Point(400, 380), new Point(400 + 250, 380 + 80));
	Button* BExit = new Exit(new Point(400, 480), new Point(400 + 250, 480 + 80));
	System::add(BStart);//�������ĸ���ť����buttons������
	System::add(BOption);
	System::add(BHelp);
	System::add(BExit);
}

//Start��
Start::Start(Point* p0, Point* p1) :Button(p0, p1) {}

void Start::role() {
	System::resetLevel();
	System::clear();//����ú����󣬽����������еİ�ťɾ��
	Picture::putPicture("Menu\\ChapterChoose");//���ơ��ؿ�ѡ�񡱽���
	Button* BChapter[12];//ʵ����ʮ�����ؿ�ѡ��ť
	Button* BMenu = new MainMenu(new Point(0, 0), new Point(150, 100));
	System::add(BMenu);
	int ChapterY[3] = { 160,290,430 };
	int ChapterX[4] = { 40 ,230,420, 620 };
	int width = 140;
	int height = 100;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			BChapter[i * 4 + j] = new Chapter(new Point(ChapterX[j], ChapterY[i]),
				new Point(ChapterX[j] + width, ChapterY[i] + height), i * 4 + j);
		}
	}
	for (int i = 0; i < 12; i++) {
		System::add(BChapter[i]);
	}//��12���ؿ�ѡ��ť��������
}

//Option��
Option::Option(Point* p0, Point* p1) :Button(p0, p1) {}

void Option::role() {
	System::clear();
	Picture::putPicture("Menu\\Option");//���ơ�ѡ�����
	Button* BMusic = new Music(new Point(450, 100), new Point(450 + 250, 100 + 80), System::musicOn ? "Music\\MenuMusic.wav" : "Music\\Null.wav");
	Button* BMenu = new MainMenu(new Point(450, 480), new Point(450 + 250, 480 + 80));
	System::add(BMenu);
	System::add(BMusic);
}

//Music��
Music::Music(Point* p0, Point* p1, string music) :Button(p0, p1) {
	this->music = music;
}

void Music::role() {
	System::clear();//�������
	System::musicOn = !System::musicOn;
	Button* BMenu = new MainMenu(new Point(450, 480), new Point(450 + 250, 480 + 80));//ʵ����һ�����˵���ť
	Button* BMusic = new Music(new Point(450, 100), new Point(450 + 250, 100 + 80), System::musicOn ? "Music\\Null.wav" : "Music\\MenuMusic.wav");//�ڸոյ����ְ�ťλ��ʵ����һ�����ְ�ť
	System::add(BMenu);//��������
	System::add(BMusic);
	System::music(!System::musicOn ? "Music\\Null.wav" : "Music\\MenuMusic.wav");
}

//Help��
Help::Help(Point* p0, Point* p1) : Button(p0, p1) {}

void Help::role() {
	System::clear();//����ú����󣬽����������еİ�ťɾ��
	Picture::putPicture("Menu\\Help");//���ƹؿ�ѡ�����ı���
	Button* BMenu = new MainMenu(new Point(450, 480), new Point(450 + 250, 480 + 80));//ʵ�������˵���ť
	System::add(BMenu);
}

//Exit��
Exit::Exit(Point* p0, Point* p1) :Button(p0, p1) {}

void Exit::role() {
	Picture::close();//�رմ���
}

//Chapter��
Chapter::Chapter(Point* p0, Point* p1, int chapters) :Button(p0, p1) {
	this->chapters = chapters;
}

void Chapter::role() {
	if (System::musicOn) {
		System::music("Music\\PlayingMusic.wav");
	}
	System::game = new Level(*System::levels[chapters]);
	System::chapters = chapters;
	System::refresh();
}

//Rotate��
Rotate::Rotate(Point* p0, Point* p1, bool clocked) :Button(p0, p1) {
	this->clocked = clocked;
}

void Rotate::role() {
	System::game->getCache()->rotate(clocked);
	System::game->getCache()->draw();
}

//Close��
Close::Close(Point* p0, Point* p1) :Button(p0, p1) {}

void Close::role() {
	Button* BNext = new Chapter(new Point(640, 400), new Point(640 + 120, 400 + 40), (System::chapters + 1) % 12);
	Button* BBack = new Start(new Point(640, 460), new Point(640 + 120, 460 + 40));
	Button* BAntiClocked = new Rotate(new Point(640, 320), new Point(640 + 40, 320 + 40), false);
	Button* BClocked = new Rotate(new Point(720, 320), new Point(720 + 40, 320 + 40), true);
	System::clear();//�����������еİ�ťɾ��
	RelativePoint* p = new RelativePoint();
	for (int i = 0; i < 15; i++) {
		p->setX(i);
		for (int j = 0; j < 15; j++) {
			p->setY(j);
			(*System::game->getMap())[*p]->clear();
			Button* BBlock = new BlockButton((*System::game->getMap())[*p]);
			System::add(BBlock);
		}
	}//��225�����鰴ť��������
	for (int i = 0; i < 24; i++) {
		System::game->getItem(i)->clear();
		Button* BItem = new BlockButton(System::game->getItem(i));
		System::add(BItem);
	}//��24�����߰�ť��������
	System::game->getCache()->clear();
	System::add(BAntiClocked);
	System::add(BClocked);
	System::add(BNext);
	System::add(BBack);
	Picture::putPicture("Menu\\PlayingWindow");
	System::game->draw();
}

//BlockButton��
BlockButton::BlockButton(Point* p0, Point* p1, Block* block) : Button(p0, p1) {
	this->block = block;
}

BlockButton::BlockButton(Block* block) : Button(new Point(*block->getPosition()->getActualPoint()), new Point(block->getPosition()->getActualPoint()->getX() + 40, block->getPosition()->getActualPoint()->getY() + 40)) {
	this->block = block;
}

void BlockButton::role() {
	if (block->isEmpty()) {
		if (!System::game->getCache()->isEmpty()) {
			System::game->getMap()->change(block->getPosition(), System::game->getCache());
			System::game->clearCache();
			System::refresh();
		}
	}
	else if (block->canMove()) {
		if (System::game->getCache()->isEmpty()) {
			RelativePoint* p = new RelativePoint(*block->getPosition());
			System::game->setCache(dynamic_cast<Item*>(block));
			System::game->clearBlock(p);
			delete p;
			System::refresh();
		}
	}
}