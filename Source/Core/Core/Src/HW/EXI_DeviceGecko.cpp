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

#include <functional>

#include "EXI_Device.h"
#include "EXI_DeviceGecko.h"
#include "../Core.h"

GeckoSockServer::GeckoSockServer()
	: client_running(false)
{
}

GeckoSockServer::~GeckoSockServer()
{
}

void GeckoSockServer::GeckoConnectionWaiter()
{
}

bool GeckoSockServer::GetAvailableSock(int &sock_to_fill)
{
	return false;
}

void GeckoSockServer::ClientThread()
{
}

void CEXIGecko::ImmReadWrite(u32 &_uData, u32 _uSize)
{
}
