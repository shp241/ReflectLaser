#include "Menu.h"
#include<windows.h>
#include "mmsystem.h"//��������ͷ�ļ�
#pragma comment(lib,"winmm.lib")//��������ͷ�ļ���
#include<stdio.h>

//MainMenu��
MainMenu::MainMenu(Point* p0, Point* p1) :Button(p0, p1) {}

void MainMenu::role() {
	System::clear();
	System::game->clear();
	Picture::putPicture("Menu\\MainWindow");//������ҳ��ı���

	Music(new Point(), new Point()).role();//��������

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
	MusicClose* BMusicClose = new MusicClose(new Point(450, 100), new Point(450 + 250, 100 + 80));
	Button* BMenu = new MainMenu(new Point(450, 480), new Point(450 + 250, 480 + 80));
	System::add(BMenu);
	System::add(BMusicClose);
}

//Music��
Music::Music(Point* p0, Point* p1) :Button(p0, p1) {}

void Music::role() {
	char buf[128];
	char str[128] = { 0 };
	int i = 0;
	//use mciSendCommand
	MCI_OPEN_PARMS mciOpen;
	MCIERROR mciError;
	//SetWindowText(NULL,"12345");
	mciOpen.lpstrDeviceType = "mpegvideo";
	mciOpen.lpstrElementName = "Music\\MenuMusic.wav";
	mciError = mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)& mciOpen);
	if (mciError)
	{
		mciGetErrorString(mciError, buf, 128);
		printf("send MCI_OPEN command failed:%s\n", buf);
		return;
	}
	UINT DeviceID = mciOpen.wDeviceID;
	MCI_PLAY_PARMS mciPlay;
	mciError = mciSendCommand(DeviceID, MCI_PLAY, 0, (DWORD)& mciPlay);
	if (mciError)
	{
		printf("send MCI_PLAY command failed\n");
		return;
	}
	PlaySound("Music\\MenuMusic.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}//�ú���������Ϸ�������˵�ʱ����һ��

//MusicOpen��ť
MusicOpen::MusicOpen(Point* p0, Point* p1) :Music(p0, p1) {}
void MusicOpen::role() {
	char buf[128];
	char str[128] = { 0 };
	int i = 0;
	//use mciSendCommand
	MCI_OPEN_PARMS mciOpen;
	MCIERROR mciError;
	//SetWindowText(NULL,"12345");
	mciOpen.lpstrDeviceType = "mpegvideo";
	mciOpen.lpstrElementName = "Music\\MenuMusic.wav";
	mciError = mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)& mciOpen);
	if (mciError)
	{
		mciGetErrorString(mciError, buf, 128);
		printf("send MCI_OPEN command failed:%s\n", buf);
		return;
	}
	UINT DeviceID = mciOpen.wDeviceID;
	MCI_PLAY_PARMS mciPlay;
	mciError = mciSendCommand(DeviceID, MCI_PLAY, 0, (DWORD)& mciPlay);
	if (mciError)
	{
		printf("send MCI_PLAY command failed\n");
		return;
	}
	PlaySound("Music\\MenuMusic.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	System::clear();//�������
	MusicClose* BMusicClose = new MusicClose(new Point(450, 100), new Point(450 + 250, 100 + 80));//�ڸոյĿ����ְ�ťλ��ʵ����һ�������ְ�ť
	Button* BMenu = new MainMenu(new Point(450, 480), new Point(450 + 250, 480 + 80));//ʵ����һ�����˵���ť
	System::add(BMenu);//��������
	System::add(BMusicClose);
}

//MusicClose��ť
MusicClose::MusicClose(Point* p0, Point* p1) :Music(p0, p1) {}

void MusicClose::role() {
	char buf[128];
	char str[128] = { 0 };
	int i = 0;
	//use mciSendCommand
	MCI_OPEN_PARMS mciOpen;
	MCIERROR mciError;
	//SetWindowText(NULL,"12345");
	mciOpen.lpstrDeviceType = "mpegvideo";
	mciOpen.lpstrElementName = nullptr;
	mciError = mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)& mciOpen);
	if (mciError)
	{
		mciGetErrorString(mciError, buf, 128);
		printf("send MCI_OPEN command failed:%s\n", buf);
		return;
	}
	UINT DeviceID = mciOpen.wDeviceID;
	MCI_PLAY_PARMS mciPlay;
	mciError = mciSendCommand(DeviceID, MCI_PLAY, 0, (DWORD)& mciPlay);
	if (mciError)
	{
		printf("send MCI_PLAY command failed\n");
		return;
	}
	PlaySound(nullptr, NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	System::clear();//�������
	MusicOpen* BMusicOpen = new MusicOpen(new Point(450, 100), new Point(450 + 250, 100 + 80));//ʵ����һ�������ְ�ť
	Button* BMenu = new MainMenu(new Point(450, 480), new Point(450 + 250, 480 + 80));//ʵ����һ�����˵���ť
	System::add(BMenu);//��������
	System::add(BMusicOpen);
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
	System::clear();//�������
	Picture::close();//�رմ���
}

//Chapter��
Chapter::Chapter(Point* p0, Point* p1, int chapters) :Button(p0, p1) {
	this->chapters = chapters;
}

void Chapter::role() {
	System::clear();//����ú����󣬽����������еİ�ťɾ��
	Picture::putPicture("Menu\\PlayingWindow");//���ơ���Ϸ������
	System::game = new Level("Level_" + to_string(chapters));
	Button* BNext = new Chapter(new Point(640, 400), new Point(640 + 120, 400 + 40), (chapters + 1) % 12);
	Button* BBack = new Start(new Point(640, 460), new Point(640 + 120, 460 + 40));
	Button* BAntiClocked = new Rotate(new Point(640, 320), new Point(640 + 40, 320 + 40), false);
	Button* BClocked = new Rotate(new Point(720, 320), new Point(720 + 40, 320 + 40), false);
	RelativePoint* p = new RelativePoint();
	for (int i = 0; i < 15; i++) {
		p->setX(i);
		for (int j = 0; j < 15; j++) {
			p->setY(j);
			System::add((*System::game->getMap())[*p]);
		}
	}//��225�����鰴ť��������
	for (int i = 0; i < 24; i++) {
		System::add(System::game->getItem(i));
	}//��24�����߰�ť��������
	System::add(BAntiClocked);
	System::add(BClocked);
	System::add(BNext);
	System::add(BBack);
	System::refresh();
}

//Rotate��
Rotate::Rotate(Point* p0, Point* p1, bool clocked) :Button(p0, p1) {
	this->clocked = clocked;
}

void Rotate::role() {
	System::game->getCache()->rotate(clocked);
	System::refresh();
}

//Close��
Close::Close(Point* p0, Point* p1) :Button(p0, p1) {}

void Close::role() {
	System::rid(*this);
	Picture::putPicture("Menu\\PlayingWindow");
	System::game->draw();
}