#ifndef UNICODE
#define UNICODE
#endif

#include <windows.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <filesystem>


int hexstr_to_int(std::string& str)
{
	int result;
	std::stringstream ss;
	ss << std::hex << str;
	ss >> result;
	return result;
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE previnstance, PWSTR pCmdLine, int nCmdShow)
{
	HANDLE mutex = OpenMutex(MUTEX_ALL_ACCESS, 0, L"volumehotkey");
	if (!mutex)
	{
		mutex = CreateMutex(0, 0, L"volumehotkey");
	}
	else
	{
		int msg_id = MessageBox(NULL, L"volumehotkey is already running. reboot to reload configuration", L"Already running", MB_OK);
		return 0;
	}

	std::string string_buf;
	std::ifstream file("./keys.txt");
	std::vector<int> keys;

	while (std::getline(file, string_buf))
	{
		keys.push_back(hexstr_to_int(string_buf));
	}

	int MODIFIER_KEY = keys[0];
	int VOL_UP = keys[1];
	int VOL_DOWN = keys[2];

	RegisterHotKey(NULL, 1, MODIFIER_KEY, VOL_UP);
	RegisterHotKey(NULL, 1, MODIFIER_KEY, VOL_DOWN);

	INPUT input[1] = {};

	MSG msg = {};
	while (GetMessage(&msg, 0, NULL, NULL))
	{
		if (msg.message == WM_HOTKEY)
		{
			if (HIWORD(msg.lParam) == VOL_UP)
			{
				input[0].type = INPUT_KEYBOARD;
				input[0].ki.wVk = VK_VOLUME_UP;
			}

			else if (HIWORD(msg.lParam) == VOL_DOWN)
			{
				input[0].type = INPUT_KEYBOARD;
				input[0].ki.wVk = VK_VOLUME_DOWN;
			}

			SendInput(ARRAYSIZE(input), input, sizeof(input));
		}
	}

	return 0;
}