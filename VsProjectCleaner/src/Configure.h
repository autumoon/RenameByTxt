//author:autumoon
//mail:autumoon@vip.qq.com

#pragma once

#include "SimpleIni.h"
#include "StdStrFile.h"
#include <tchar.h>
#include "Defines.h"

typedef struct _config_s 
{
	bool bRemPath;
	std::wstring strSuffix;
	std::vector<std::string> vDirPaths;
	std::vector<std::string> vFilePaths;

	_config_s()
	{
		//内部初始化
		bRemPath = true;
		strSuffix = _T(".mp3");
	}

}config_s;

int ReadIniFromFile(const std::string& strIniPath, config_s& _conf);
int WriteIniToFile(const std::string& strIniPath, const config_s& _conf);

std::wstring VectorToString(const std::vector<std::string>& vStrings);

//std::string GetIniPath()
//{
//	TCHAR chpath[MAX_PATH];
//	GetModuleFileName(NULL, chpath, sizeof(chpath));
//	int index = CString(chpath).ReverseFind('\\');
//	CString strIniPath = CString(chpath).Mid(0, index) + CString("\\Settings.ini");
//
//	return CMfcStrFile::CString2string(strIniPath);
//}