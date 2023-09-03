- Install Obsidian
- Install Visual Studio 22 from here : https://visualstudio.microsoft.com/downloads/
    - ensure you have C++ Desktop Tools + CMake options selected as components when installing VS 2022
- Install Python : https://www.python.org/downloads/
- Install CMake : https://github.com/Kitware/CMake/releases/download/v3.27.1/cmake-3.27.1-windows-x86_64.msi
- from Terminal run `python -m pip install dearpygui`
- Download and install GitHub Desktop : https://desktop.github.com
- Sign in to your GitHub account in GitHub Desktop
- Clone harmony repo through GitHub desktop
- Open harmony repo in Visual Studio 2022 (as a folder)
      - May ask you to select a project to start with, in which case default should be "harmony/templates/harmony-dojo" (the editor)
      - You can add additional projects to build but the process is a pain, once you have done this once you shouldnt need to do it again.
	      - Click Project -> CMake Workspace settings 
		![[Pasted image 20230903180327.png]]
		- This will open a json config file, change the source directory to whatever project you wish to build:
		![[Pasted image 20230903181535.png]] 
		- Ensure you save the file once you changed the source directory 
		- ADDITIONALLY, each time you try to build a new project, you need to setup the CMake build configuration:
		  ![[Pasted image 20230903180824.png]]
		  ![[Pasted image 20230903180854.png]] - Ensure you click "Show Advanced Settings"
		  ![[Pasted image 20230903180935.png]]
				  - Ensure the generator is for Visual Studio 2022 Win64. Save the settings and the project will regenerate. 

	- Now we should be able to run the project. Select the harmony-app / harmony-dojo startup item:- 
	  ![[Pasted image 20230903181214.png]]
	
	- You may need to have a look as there are many projects included, including samples for bgfx etc.
	  
	  - You should now be able to click the green run button to start the app. 