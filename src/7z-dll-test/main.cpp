// console_template.cpp : Defines the entry point for the console application.
//

#include "targetver.h"
#include <7zpp\7zpp.h>
#include <stdio.h>
#include <tchar.h>
#include <locale.h>
#include <iostream>

typedef std::wstring string16;
typedef wchar_t char16;

const char16* GetAllPathDelimiters()
{
    return L"\\/";
}

string16 ExtractFilePath(const string16& FileName)
{
    string16 Result = FileName;
    return Result.erase(Result.find_last_of(GetAllPathDelimiters()) + 1);
}

string16 GetAppFileName()
{
    char16 filename[MAX_PATH + 10] = { 0 };
    GetModuleFileNameW((HMODULE)&__ImageBase, filename, MAX_PATH);
    return string16(filename);
}

string16 GetAppDir()
{
    return ExtractFilePath(GetAppFileName());
}




int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
    _tsetlocale(LC_ALL, _T(""));
    string16 appdir = GetAppDir();
    string16 filename_7z = appdir + L"7z.dll";
    string16 test_filename = appdir + L"test.7z";
    string16 dest_dir_name = appdir + L"test_out";
    SevenZip::SevenZipLibrary lib;
    bool result = lib.Load(filename_7z);

    if (result) {
        SevenZip::SevenZipExtractor extractor(lib, test_filename);
        SevenZip::CompressionFormatEnum myCompressionFormat;
        extractor.ReadInArchiveMetadata();
        myCompressionFormat = extractor.GetCompressionFormat();
        size_t numberofitems = extractor.GetNumberOfItems();
        std::vector<std::wstring> itemnames = extractor.GetItemsNames();
        std::vector<size_t> origsizes = extractor.GetOrigSizes();

        for (int i = 0; i < itemnames.size(); i++) {
            std::wcout << itemnames[i].c_str() << std::endl;
            std::wcout << origsizes[i] << std::endl;
        }

        //extractor.SetCompressionFormat(SevenZip::CompressionFormat::Zip);
        result = extractor.ExtractArchive(dest_dir_name, NULL);
    }

    _tsystem(_T("pause"));
    return 0;
}

