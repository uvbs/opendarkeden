//----------------------------------------------------------------------
//
// Filename    : SubVampireSkillInfo.h
// Written By  : elca
// Description :
//
//----------------------------------------------------------------------

#ifndef __SUB_VAMPIRE_SKILL_INFO_H__
#define __SUB_VAMPIRE_SKILL_INFO_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "SocketInputStream.h"
#include "SocketOutputStream.h"

//----------------------------------------------------------------------
//
// Inventory ������ ��� �ִ� ��ü.
//
// GCUpdateInfo ��Ŷ�� ��ܼ� Ŭ���̾�Ʈ���� ���۵ȴ�.
// �������̳� �ɷ��ִ� ���� ���� ������ ������� �ʴ�.
//
//----------------------------------------------------------------------

class SubVampireSkillInfo {

public :

	// read data from socket input stream
	void read (SocketInputStream & iStream) throw (ProtocolException, Error);

	// write data to socket output stream
	void write (SocketOutputStream & oStream) const throw (ProtocolException, Error);

	// get size of object
	uint getSize () const throw () { return szSkillType + szTurn + szTurn; }
	// get max size of object
	static uint getMaxSize () throw () { return szSkillType + szTurn + szTurn; }

	// get debug string
	string toString () const throw ();

public :

	// get / set SkillType
	SkillType_t getSkillType() const throw() { return m_SkillType; }
	void setSkillType(SkillType_t SkillType) throw() { m_SkillType = SkillType; }

	// get / set Turn
	Turn_t getSkillTurn() const throw() { return m_Interval ; }
	void setSkillTurn(Turn_t SkillTurn) throw() { m_Interval = SkillTurn; }

	// get / set CastingTime
	Turn_t getCastingTime() const throw() { return m_CastingTime; }
	void setCastingTime(Turn_t CastingTime) throw() { m_CastingTime = CastingTime; }

private :

	// ��ų Ÿ��
	SkillType_t m_SkillType;

	// �ѹ����� ������ �� ������
	Turn_t m_Interval;

	// ĳ���� Ÿ��
	Turn_t m_CastingTime;

};

#endif