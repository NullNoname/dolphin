#include "NetPlay.h"

// called from ---GUI--- thread
NetPlayClient::~NetPlayClient()
{
}

// called from ---GUI--- thread
NetPlayClient::NetPlayClient(const std::string& address, const u16 port, NetPlayUI* dialog, const std::string& name) : NetPlay(dialog)
{
}

// called from ---NETPLAY--- thread
unsigned int NetPlayClient::OnData(sf::Packet& packet)
{
	return 0;
}

// called from ---NETPLAY--- thread
void NetPlayClient::ThreadFunc()
{
	return;
}

// called from ---GUI--- thread
void NetPlayClient::GetPlayerList(std::string& list, std::vector<int>& pid_list)
{
}


// called from ---GUI--- thread
void NetPlayClient::SendChatMessage(const std::string& msg)
{
}

// called from ---CPU--- thread
void NetPlayClient::SendPadState(const PadMapping local_nb, const NetPad& np)
{
}

// called from ---GUI--- thread
bool NetPlayClient::StartGame(const std::string &path)
{
	return true;
}

// called from ---GUI--- thread
bool NetPlayClient::ChangeGame(const std::string&)
{
	return true;
}
