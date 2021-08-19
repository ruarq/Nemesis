workspace "Nemesis"
	configurations { "Debug", "Release" }

project "Nemesis"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"

	objdir "ObjectFiles"
	targetdir "Bin/%{cfg.buildcfg}"

	files { "Source/**.hpp", "Source/**.cpp" }
	links { "sfml-system", "sfml-window", "sfml-graphics", "sfml-audio" }

	filter { "configurations:Debug" }
		symbols "On"

	filter { "configurations:Release" }
		optimize "On"