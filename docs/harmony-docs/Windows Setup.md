- Install Obsidian
- Install Visual Studio 22 from here : https://visualstudio.microsoft.com/downloads/
- Install Python : https://www.python.org/downloads/
- Install CMake : https://github.com/Kitware/CMake/releases/download/v3.27.1/cmake-3.27.1-windows-x86_64.msi
- from Terminal run `python -m pip install dearpygui`
- Download and install GitHub Desktop : https://desktop.github.com
- Sign in to your GitHub account in GitHub Desktop
- Download + install VSCode : https://code.visualstudio.com/download
- Clone harmony repo through GitHub desktop
- Open harmony repo in VS2022 (as a folder)
- Setup CMake VS Settings 
	- in VS2022 -> Solution Explorer -> Find the root CMakeLists.txt -> Right Click and "Configure Projects"
	- More than likely this will produce errors, open the harmony repo in VSCode.
	- There should be 2 files in the root of the repo now `CMakeSettings.json` and `CppProperties.json`
	- `CMakeSettings.json` should look like the following:

```
{
	  "configurations": [
	    {
	      "buildCommandArgs": "",
	      "buildRoot": "${projectDir}\\out\\build\\${name}",
	      "cmakeCommandArgs": "",
	      "configurationType": "Debug",
	      "ctestCommandArgs": "",
	      "generator": "Visual Studio 17 2022 Win64",
	      "inheritEnvironments": [ "msvc_x64" ],
	      "installRoot": "${projectDir}\\out\\install\\${name}",
	      "intelliSenseMode": "windows-msvc-x64",
	      "name": "Debug"
	    }
	  ]
}
```
 
 - `CppProperties.json` should look like this:

```
{
  "configurations": [
    {
      "inheritEnvironments": [
        "msvc_x64"
      ],
      "name": "x64-Debug",
      "includePath": [
        "${env.INCLUDE}",
        "${workspaceRoot}\\**"
      ],
      "defines": [
        "WIN32",
        "_DEBUG",
        "UNICODE",
        "_UNICODE"
      ],
      "intelliSenseMode": "windows-msvc-x64"
    }
  ]
}

```

- On the tool bar, the Green Play button should say "Select Startup Item" or something similar, in the drop down box, select "harmony-dojo" or "harmony-app"
- Press the Green Play button to compile. 
- Voila

