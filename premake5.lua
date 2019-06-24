workspace "haydn"

configurations {
	"Debug",
	"Release"
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["spdlog"] = "externals/spdlog/include"

project "haydn"
	location "haydn"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/core/**.h",
		"src/core/**.cpp",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"src",
		"%{IncludeDir.spdlog}"
	}

	links 
	{
		"pthread"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "HAYDN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HAYDN_RELEASE"
		runtime "Release"
		optimize "on"

project "app"
	location "app"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/app/**.h",
		"src/app/**.cpp"
	}

	includedirs
	{
		"src",
		"%{IncludeDir.spdlog}"
	}

	links
	{
		"haydn",
		"pthread"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "HAYDN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HAYDN_RELEASE"
		runtime "Release"
		optimize "on"
