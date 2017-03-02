# dll-wrapper-examples

把常用的 dll 包装引用，可能会使用 vc14 编译输出标准的 C 接口的 DLL，然后包装引用


带包装的 dll

- zlib.dll
- 7z.dll
- libcurl.dll
- libeay32.dll


## 3rdparty/7zpp 

用于包装 7z.dll 调用，如果不想编译 7z.dll，直接安装 7z，然后拷贝 7z.dll 过来使用，
编译 7zpp 需要 7z 的源码头文件
