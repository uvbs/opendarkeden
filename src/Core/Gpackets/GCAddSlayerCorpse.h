//----------------------------------------------------------------------
// 
// Filename    : GCAddSlayerCorpse.h 
// Written By  : Reiot
// 
//----------------------------------------------------------------------

#ifndef __GC_ADD_SLAYER_CORPSE_H__
#define __GC_ADD_SLAYER_CORPSE_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"
#include "PCSlayerInfo3.h"

//----------------------------------------------------------------------
//
// class GCAddSlayerCorpse;
//
// �����̾��� ��ü ������ ��Ƽ� Ŭ���̾�Ʈ�� �����Ѵ�.
//
//----------------------------------------------------------------------

class GCAddSlayerCorpse : public Packet {

public :
	~GCAddSlayerCorpse() throw() {}

	// constructor
	GCAddSlayerCorpse() throw() { m_TreasureCount = 0; }
	GCAddSlayerCorpse(const PCSlayerInfo3 & slayerInfo) throw() : m_SlayerInfo(slayerInfo) {}


public :

    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error);
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_GC_ADD_SLAYER_CORPSE; }
	
	// get packet's body size
	PacketSize_t getPacketSize() const throw() { return m_SlayerInfo.getSize() + szBYTE; }

	// get packet's name
	string getPacketName() const throw() { return "GCAddSlayerCorpse"; }
	
	// get packet's debug string
	string toString() const throw();


public :

	// get slayer info
	PCSlayerInfo3 & getSlayerInfo() throw() { return m_SlayerInfo; }
	const PCSlayerInfo3 & getSlayerInfo() const throw() { return m_SlayerInfo; }
	void setSlayerInfo(const PCSlayerInfo3 & slayerInfo) throw() { m_SlayerInfo = slayerInfo; }

	// get/set Treasure Count
	BYTE getTreasureCount() const throw() { return m_TreasureCount; }
	void setTreasureCount(BYTE Count) throw() { m_TreasureCount = Count; }

private :
	
	// �����̾��� �ܸ� ����
	PCSlayerInfo3 m_SlayerInfo;

	// ���� ����
	BYTE m_TreasureCount;

};


//--------------------------------------------------------------------------------
//
// class GCAddSlayerCorpseFactory;
//
// Factory for GCAddSlayerCorpse
//
//--------------------------------------------------------------------------------

class GCAddSlayerCorpseFactory : public PacketFactory {

public :
	
	// create packet
	Packet* createPacket() throw() { return new GCAddSlayerCorpse(); }

	// get packet name
	string getPacketName() const throw() { return "GCAddSlayerCorpse"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_GC_ADD_SLAYER_CORPSE; }

	// get packet's body size
	// *OPTIMIZATION HINT*
	// const static GCAddSlayerCorpsePacketSize �� ����, �����϶�.
	PacketSize_t getPacketMaxSize() const throw()
	{ 
		return PCSlayerInfo3::getMaxSize() + szBYTE;
	}

};


//--------------------------------------------------------------------------------
//
// class GCAddSlayerCorpseHandler;
//
//--------------------------------------------------------------------------------

class GCAddSlayerCorpseHandler {

public :

	// execute packet's handler
	static void execute(GCAddSlayerCorpse* pPacket, Player* pPlayer) throw(Error);

};

#endif