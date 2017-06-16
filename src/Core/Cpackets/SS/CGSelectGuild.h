//////////////////////////////////////////////////////////////////////
// 
// Filename    : CGSelectGuild.h 
// Written By  :
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __CG_SELECT_GUILD_H__
#define __CG_SELECT_GUILD_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class CGSelectGuild;
//
//////////////////////////////////////////////////////////////////////

class CGSelectGuild : public Packet
{
public:
	
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_CG_SELECT_GUILD; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw() { return szGuildID; }

	// get packet name
	string getPacketName() const throw() { return "CGSelectGuild"; }

	// get packet's debug string
	string toString() const throw();

	// get/set GuildID
	GuildID_t getGuildID() const throw() { return m_GuildID; }
	void setGuildID( GuildID_t GuildID ) throw() { m_GuildID = GuildID; }


private :

	// Guild ID
	GuildID_t m_GuildID;
	
};


//////////////////////////////////////////////////////////////////////
//
// class CGSelectGuildFactory;
//
// Factory for CGSelectGuild
//
//////////////////////////////////////////////////////////////////////

class CGSelectGuildFactory : public PacketFactory {

public:
	
	// constructor
	CGSelectGuildFactory() throw() {}
	
	// destructor
	virtual ~CGSelectGuildFactory() throw() {}

	
public:
	
	// create packet
	Packet* createPacket() throw() { return new CGSelectGuild(); }

	// get packet name
	string getPacketName() const throw() { return "CGSelectGuild"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_CG_SELECT_GUILD; }

	// get Packet Max Size
	PacketSize_t getPacketMaxSize() const throw() { return szGuildID; }
};


//////////////////////////////////////////////////////////////////////
//
// class CGSelectGuildHandler;
//
//////////////////////////////////////////////////////////////////////

class CGSelectGuildHandler {

public:

	// execute packet's handler
	static void execute(CGSelectGuild* pCGSelectGuild, Player* pPlayer) throw(Error);

};

#endif