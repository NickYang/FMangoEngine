local glsdk_lua = "external/glsdk_0_5_2/links.lua"

dofile(glsdk_lua)

solution "FMango"
	configurations{"Debug", "Release"}
	defines{"_CRT_SECURE_NO_WARNINGS", "_SCL_SECURE_NO_WARNINGS" }

project("FMango_Core")
	location "Core"
	kind "StaticLib"
	language "c++"
	objdir("Core/obj")
	files("Core/*.cpp")
	files("Core/*.h")
	targetname "Core"
	
	UseLibs {"glload", "glfw", "glm", "freeglut"}
	
	configuration "windows"
		defines "WIN32"
		links{"glu32", "opengl32", "winmm", "user32"}
	
	configuration "Debug"
		targetdir "Bin/Debug"
		targetsuffix "D"
		defines "_DEBUG"
		flags "Symbols"
		
	configuration "Release"
		targetdir "Bin/Release"
		defines "NDEBUG"
		flags {"OptimizeSpeed", "NoFramePointer", "ExtraWarnings", "NoEditAndContinue"};
	
project("FMango_Samples")
	location "Samples"
	kind "ConsoleApp"
	language "c++"
	objdir("Samples/obj")
	files("Samples/*.cpp")
	files("Samples/*.h")
	targetname "Samples"
	includedirs {"Core","external/glsdk_0_5_2"}
	
	UseLibs {"glload", "glfw", "glm", "freeglut"}
	configuration "windows"
		defines "WIN32"
	    links {"glu32", "opengl32", "winmm", "user32" }
		
	configuration "Debug"
		targetdir "Bin/Debug"
		targetsuffix "D"
		defines "_DEBUG"
		flags "Symbols"
		libdirs "Bin/Debug"
		links "CoreD"
	configuration "Release"
		targetdir "Bin/Release"
		defines "NDEBUG"
		flags {"OptimizeSpeed", "NoFramePointer", "ExtraWarnings", "NoEditAndContinue"};
		libdirs "Bin/Release"
		links "Core"