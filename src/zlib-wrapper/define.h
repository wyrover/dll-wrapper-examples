/* Force using Unicode throughout the code */
#ifndef UNICODE
    #define UNICODE
#endif

/* Microsoft C Compiler does not support the C99 inline keyword */
#ifndef __cplusplus
    #define inline __inline;
#endif // _cplusplus


#include <Windows.h>

#define LOAD_DYNAMIC_SYMBOL(func_type, func_ptr, handle, symbol) \
    if ((func_ptr = (func_type) do_dlsym(handle, symbol)) == NULL) { \
        return; \
    }


/**
 * A helper function to dynamic load a 'symbol' from a given library-handle.
 *
 * @param env jni handle to report contingencies.
 * @param handle handle to the dynamic library.
 * @param symbol symbol to load.
 * @return returns the address where the symbol is loaded in memory,
 *         <code>NULL</code> on error.
 */
static FARPROC WINAPI do_dlsym(HMODULE handle, LPCSTR symbol)
{
    DWORD dwErrorCode = ERROR_SUCCESS;
    FARPROC func_ptr = NULL;

    if (!handle || !symbol) {
        //THROW(env, "java/lang/InternalError", NULL);
        return NULL;
    }

    func_ptr = GetProcAddress(handle, symbol);

    if (func_ptr == NULL) {
        //THROW(env, "java/lang/UnsatisfiedLinkError", symbol);
    }

    return func_ptr;
}
