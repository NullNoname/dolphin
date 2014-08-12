#include "NetPlay.h"

// called from ---GUI--- thread
NetPlayServer::~NetPlayServer()
{
}

// called from ---GUI--- thread
NetPlayServer::NetPlayServer(const u16 port, const std::string& name, NetPlayUI* dialog, const std::string& game) : NetPlay(dialog)
{
}

// called from ---NETPLAY--- thread
void NetPlayServer::ThreadFunc()
{

	return;
}

// called from ---NETPLAY--- thread
unsigned int NetPlayServer::OnConnect(sf::TcpSocket& socket)
{

	return 0;
}

// called from ---NETPLAY--- thread
unsigned int NetPlayServer::OnDisconnect(sf::TcpSocket& socket)
{
	return 0;
}

// called from ---GUI--- thread
bool NetPlayServer::GetPadMapping(const int pid, int map[])
{
	return false;
}

// called from ---GUI--- thread
bool NetPlayServer::SetPadMapping(const int pid, const int map[])
{
	return false;
}

// called from ---NETPLAY--- thread
void NetPlayServer::UpdatePadMapping()
{
}

// called from ---GUI--- thread and ---NETPLAY--- thread
u64 NetPlayServer::CalculateMinimumBufferTime()
{
	return 0;
}

// called from ---GUI--- thread and ---NETPLAY--- thread
void NetPlayServer::AdjustPadBufferSize(unsigned int size)
{
}

// called from ---NETPLAY--- thread
unsigned int NetPlayServer::OnData(sf::Packet& packet, sf::TcpSocket& socket)
{
	return 0;
}

// called from ---GUI--- thread
void NetPlayServer::GetPlayerList(std::string& list, std::vector<int>& pid_list)
{
}

// called from ---GUI--- thread / and ---NETPLAY--- thread
void NetPlayServer::SendChatMessage(const std::string& msg)
{
}

// called from ---GUI--- thread
bool NetPlayServer::ChangeGame(const std::string &game)
{
	return true;
}

// called from ---CPU--- thread
void NetPlayServer::SendPadState(const PadMapping local_nb, const NetPad& np)
{
}

// called from ---GUI--- thread
bool NetPlayServer::StartGame(const std::string &path)
{
	return false;
}


// called from ---GUI--- thread
bool NetPlayServer::StopGame()
{
	return true;
}

// called from multiple threads
void NetPlayServer::SendToClients(sf::Packet& packet, const PlayerId skip_pid)
{
}
