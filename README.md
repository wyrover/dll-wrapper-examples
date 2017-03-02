# dll-wrapper-examples

把常用的 dll 包装引用，可能会使用 vc14 编译输出标准的 C 接口的 DLL(MT 方式编译)，然后包装让低版本的 VC 引用

- projects.bat 用于调用 premake5.exe 生成 vs 工程
- format_code.bat 用于调用 AStyle.exe 格式化代码


带包装的 dll

- zlib.dll
- 7z.dll
- libcurl.dll
- libeay32.dll

## 3rdparty/zlib-1.2.8

生成 zlib.dll


## 3rdparty/7zpp 

用于包装 7z.dll 调用，如果不想编译 7z.dll，直接安装 7z，然后拷贝 7z.dll 过来使用，
编译 7zpp 需要 7z 的源码头文件

http://www.7-zip.org/ 

## 3rdparty/lzma1604

7z 的头文件