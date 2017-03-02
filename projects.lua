includeexternal ("premake-vs-include.lua")

workspace "dll-wrapper-examples"
    language "C++"
    location "build/%{_ACTION}/%{wks.name}"    
    if _ACTION == "vs2015" then
        toolset "v140_xp"
    end

    project "7zpp"            
        kind "StaticLib"                       
        files
        {
           
            "3rdparty/7zpp/src/**.h",
            "3rdparty/7zpp/src/**.cpp", 
            "3rdparty/7zpp/src/**.c"
            
        }   
        includedirs
        {
            "H:/rover/rover-self-work/cpp/rover-fork/7z1604-srcWithVs2015Up3/CPP",
            "H:/rover/rover-self-work/cpp/rover-fork/7z1604-srcWithVs2015Up3/C"
        }
        has_stdafx("src", "3rdparty/7zpp")

    group "dll-wrapper-examples"    
--        project "ZipDLL"            
--            kind "SharedLib"                         
--            files
--            {
--                "ZipDLL/*.def",   
--                "ZipDLL/**.h",
--                "ZipDLL/**.cpp", 
--                "ZipDLL/**.c"
--                
--            }   
--            has_stdafx("ZipDLL", ".")
        
        create_console_project("zlib-wrapper", "src")
            includedirs
            {
                "3rdparty/zlib-1.2.8"
            }
            
        create_console_project("7z-dll-test", "src")
            includedirs
            {
                "3rdparty/7zpp"
            }
            links
            {
                "7zpp"
            }