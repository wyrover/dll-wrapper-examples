#pragma once

#include <Windows.h>
#include <tchar.h>
#include <string>


namespace SevenZip
{
#ifdef _UNICODE
    typedef std::wstring TString;
#else
    typedef std::string TString;
#endif
}
