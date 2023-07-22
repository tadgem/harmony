- Install Xcode from App Store
- Install brew : https://brew.sh : Copy command, open Terminal, paste + run command
- Install CMake + Python :
	  `brew install cmake`
	  `brew install python`
- Download and install GitHub Desktop : https://desktop.github.com
- Sign in to your GitHub account in GitHub Desktop
- Download + install VSCode
- Clone harmony repo through GitHub desktop
- Open harmony repo in VSCode
- Open terminal in VSCode
- navigate in Terminal to `templates/harmony-dojo`
- Create a build dir : `mkdir build`  then  `cd build`
- Generate Xcode project files : `cmake -G Xcode -T buildsystem=1 ..`
- From Target drop down in Xcode, select `harmony-dojo`
- Profit