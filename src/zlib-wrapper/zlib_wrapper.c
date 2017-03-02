#include "define.h"
#include <zlib.h>
#include <zconf.h>


typedef int (__cdecl *__dlsym_deflateInit2_)(z_streamp, int, int, int, int, int, const char *, int);
typedef int (__cdecl *__dlsym_deflate)(z_streamp, int);
typedef int (__cdecl *__dlsym_deflateSetDictionary)(z_streamp, const Bytef *, uInt);
typedef int (__cdecl *__dlsym_deflateReset)(z_streamp);
typedef int (__cdecl *__dlsym_deflateEnd)(z_streamp);
static __dlsym_deflateInit2_ dlsym_deflateInit2_;
static __dlsym_deflate dlsym_deflate;
static __dlsym_deflateSetDictionary dlsym_deflateSetDictionary;
static __dlsym_deflateReset dlsym_deflateReset;
static __dlsym_deflateEnd dlsym_deflateEnd;


typedef int (__cdecl *__dlsym_inflateInit2_)(z_streamp, int, const char *, int);
typedef int (__cdecl *__dlsym_inflate)(z_streamp, int);
typedef int (__cdecl *__dlsym_inflateSetDictionary)(z_streamp, const Bytef *, uInt);
typedef int (__cdecl *__dlsym_inflateReset)(z_streamp);
typedef int (__cdecl *__dlsym_inflateEnd)(z_streamp);
static __dlsym_inflateInit2_ dlsym_inflateInit2_;
static __dlsym_inflate dlsym_inflate;
static __dlsym_inflateSetDictionary dlsym_inflateSetDictionary;
static __dlsym_inflateReset dlsym_inflateReset;
static __dlsym_inflateEnd dlsym_inflateEnd;

static HMODULE libz = NULL;


void zlib_init()
{
    libz = LoadLibrary(L"zlib1.dll");

    if (!libz)  {
    }

    LOAD_DYNAMIC_SYMBOL(__dlsym_deflateInit2_, dlsym_deflateInit2_, libz, "deflateInit2_");
    LOAD_DYNAMIC_SYMBOL(__dlsym_deflate, dlsym_deflate, libz, "deflate");
    LOAD_DYNAMIC_SYMBOL(__dlsym_deflateSetDictionary, dlsym_deflateSetDictionary, libz, "deflateSetDictionary");
    LOAD_DYNAMIC_SYMBOL(__dlsym_deflateReset, dlsym_deflateReset, libz, "deflateReset");
    LOAD_DYNAMIC_SYMBOL(__dlsym_deflateEnd, dlsym_deflateEnd, libz, "deflateEnd");
    LOAD_DYNAMIC_SYMBOL(__dlsym_inflateInit2_, dlsym_inflateInit2_, libz, "inflateInit2_");
    LOAD_DYNAMIC_SYMBOL(__dlsym_inflate, dlsym_inflate, libz, "inflate");
    LOAD_DYNAMIC_SYMBOL(__dlsym_inflateSetDictionary, dlsym_inflateSetDictionary, libz, "inflateSetDictionary");
    LOAD_DYNAMIC_SYMBOL(__dlsym_inflateReset, dlsym_inflateReset, libz, "inflateReset");
    LOAD_DYNAMIC_SYMBOL(__dlsym_inflateEnd, dlsym_inflateEnd, libz, "inflateEnd");
}

void zlib_uninit()
{
    if (libz)
        FreeLibrary(libz);
}