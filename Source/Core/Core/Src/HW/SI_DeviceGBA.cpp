// Copyright (C) 2003 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/

#include "SI_Device.h"
#include "SI_DeviceGBA.h"

#include "SFML/Network.hpp"
#include "Thread.h"
#include <queue>

namespace { volatile bool server_running; }

// --- GameBoy Advance "Link Cable" ---

void GBAConnectionWaiter()
{
}

void GBAConnectionWaiter_Shutdown()
{
}

bool GetAvailableSock(sf::TcpSocket& sock_to_fill)
{
	return false;
}

GBASockServer::GBASockServer()
{
}

GBASockServer::~GBASockServer()
{
}

// Blocking, since GBA must always send lower byte of REG_JOYSTAT
void GBASockServer::Transfer(char* si_buffer)
{
}

CSIDevice_GBA::CSIDevice_GBA(int _iDeviceNumber)
	: ISIDevice(_iDeviceNumber)
	, GBASockServer()
{
}

int CSIDevice_GBA::RunBuffer(u8* _pBuffer, int _iLength)
{
	return 0;
}
