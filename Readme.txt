Dolphin-emu 3.0 - The Gamecube / Wii Emulator
==========================================
This project is a modified version of Dolphin 3.0 that is buildable in Ubuntu 14.04 and 16.04, just for historical interest.

[Changes from original source]
The following features, which depends on SFML-Network, had to be removed because SFML had major API changes before the release of Ubuntu 14.04.
* NetPlay
* GBA Device
* USBGecko Device
* Cheat Downloader

[Build Instructions]
* Step 1: Install Required Packages and get the source
$ sudo apt-get install git build-essential cmake libao-dev libasound2-dev libbluetooth-dev libglew-dev libgtk2.0-dev liblzo2-dev libopenal-dev libpulse-dev libreadline-dev libsdl1.2-dev libsoil-dev libxext-dev libxrandr-dev lsb-release pkg-config zlib1g-dev nvidia-cg-dev
$ git clone 

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
