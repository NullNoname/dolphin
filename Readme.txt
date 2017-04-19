Dolphin-emu 3.0 - The Gamecube / Wii Emulator
==========================================
This project is a modified version of Dolphin 3.0 that is buildable in Ubuntu 14.04 and 16.04, just for historical interest.
Please DO NOT report any bugs caused from this build to the Dolphin team!

[Changes from original source]
The following features, which depends on SFML-Network, had to be removed because SFML had major API changes before the release of Ubuntu 14.04.
* NetPlay
* GBA Device
* USBGecko Device
* Cheat Downloader
Menu entries for these features remain, but selecting them will do nothing.

In addition, to prevent this version from conflicting with the official versions of Dolphin, executable filename and related directory names are renamed to "dolphin-emu-3.0" instead of "dolphin-emu". User settings are stored in "~/.dolphin-emu-3.0/".

[Build Instructions]
* Step 1: Install Required Packages and get the source
$ sudo apt-get install git build-essential cmake libao-dev libasound2-dev libbluetooth-dev libglew-dev libgtk2.0-dev liblzo2-dev libopenal-dev libpulse-dev libreadline-dev libsdl1.2-dev libsoil-dev libxext-dev libxrandr-dev lsb-release pkg-config zlib1g-dev nvidia-cg-dev
$ git clone https://github.com/NullNoname/dolphin.git
$ cd dolphin

* Optional: Install portaudio19-dev (NOT RECOMMENDED!)
portaudio19-dev is required for mic support. Unfortunately, this package will likely cause dependency problem on your system (it uninstalls bunch of multimedia applications) and thus not recommended for most people.
$ sudo apt-get install portaudio19-dev libjack-dev libjack0

* Step 2: Add WebUpd8 PPA (Required only for Ubuntu 16.04, please skip to Step 3 in Ubuntu 14.04)
Dolphin-emu 3.0 requires wxWidgets 2.8. It was available in the main repository in Ubuntu 14.04, but in 16.04 it was removed.
Thanksfully WebUpd8 (http://www.webupd8.org) has wxWidgets 2.8 for Ubuntu 16.04 in their PPA (https://launchpad.net/~nilarimogard/+archive/ubuntu/webupd8).

$ sudo add-apt-repository ppa:nilarimogard/webupd8
$ sudo apt-get update

* Step 3: Install wxWidgets 2.8
$ sudo apt-get install libwxbase2.8-dev libwxgtk2.8-dev wx2.8-headers

* Step 4: Build
$ mkdir Build
$ cd Build
$ cmake ../
$ make
$ sudo make install

* Optional: Create a Launcher Icon
$ cd ../
$ sudo cp ./dolphin-emu-3.0.desktop /usr/share/applications/dolphin-emu-3.0.desktop
$ sudo cp ./Source/Core/DolphinWX/resources/Dolphin.xpm /usr/share/pixmaps/dolphin-emu-3.0.xpm

[License]
GNU General Public License, Version 2 (see license.txt for more info)
