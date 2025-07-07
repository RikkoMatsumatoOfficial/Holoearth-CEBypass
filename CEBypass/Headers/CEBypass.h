#pragma once
#include <Windows.h>
#include <iostream>
#include "WinReg.hpp"
#include <filesystem>
namespace f = std::filesystem;
using namespace std;
namespace CEBypass {
	void MainBypass() {
		f::create_directory("C:\\CEBypass-FarewellHoloearth");
		SetFileAttributesA("C:\\CEBypass-FarewellHoloearth", FILE_ATTRIBUTE_READONLY | FILE_ATTRIBUTE_HIDDEN);
		winreg::RegKey xxx{ HKEY_CURRENT_USER, L"SOFTWARE\\Cheat Engine", KEY_ALL_ACCESS };
		if (!xxx) {
			printf("Failed to Open RegKey in the Current User(Cheat Engine)!!!");
			Sleep(4000);
			exit(11);
		}
		else {
			xxx.SetDwordValue(L"Don't use tempdir", (DWORD)1);
			xxx.SetStringValue(L"Scanfolder", L"C:\\CEBypass-FarewellHoloearth");
			cout << "Successfully Bypassed Cheat Engine for Game Holoearth or Another Game!!!" << endl;
		}
	}
}
