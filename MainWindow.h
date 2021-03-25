#pragma once

#include <cstdlib>
#include <windows.h>
#include"GameWindow.h"
#include"OptionWindow.h"



class MainWindow
{
public:
	MainWindow();
	~MainWindow();
	void show();
	void exitMainWindow();

private:
	GameWindow* gamewindow;
	OptionWindow* optionwindow;
};

