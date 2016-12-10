#include <windows.h>
#include "External\packet.h"

namespace PSO2DamageDump
{
	PACKED(
	struct PacketCharacterInfo
	{
		DWORD playerID; //0x8-0xB
		BYTE unk1[0x64]; //0xc-0x6f
		WCHAR name[0x12]; //0x70-0x93
		BYTE unk2[0x130]; //0x94-0x1c3
		WCHAR title[0x24]; //1c4-0x20b
		WCHAR account[0x40]; //20c-28b
	} ATTRPACK;
	);

	PACKED(
	struct PacketUserInfo
	{
		DWORD playerID; //0x8-0xB
		//Don't care about the rest!
	} ATTRPACK;
	);

	PACKED(
	struct PacketSpawnInfo
	{
		DWORD ID; //0x8-0xB
		BYTE unk1[0x18]; //0xc-0x23
		CHAR name[0x1D]; //0x24-?, not sure how long it is
	} ATTRPACK;
	);

	PACKED(
	struct PacketDamage
	{
		DWORD playerID; //0x8-0xB
		BYTE unk1[8]; //0xC-0x12
		DWORD targetID; //0x14-0x17
		BYTE unk2[6]; //0x18-0x1D
		WORD instanceID; //0x1E-1F
		DWORD sourceID; //0x20-0x23
		BYTE unk3[8]; //0x24-0x2B
		DWORD atkID; //0x2C-0x2F
		INT32 value; //0x30-0x33, damage, healing, etc..., can be positive or negative
		BYTE unk4[16]; //0x34-0x43
		BYTE flags; //0x44
		BYTE unk5[11]; //0x45-0x50
	} ATTRPACK;
	);

	PACKED(
	struct PacketVehicleSpawn //08.10
	{
		DWORD objID;
		BYTE unk1[0x18];
		BYTE objName[0x16];
		BYTE unk2[0x22];
		DWORD ownerID;
		BYTE unk3[0x8];
	} ATTRPACK;
	);


	PACKED(
	struct PacketPetSpawn //08.11
	{
		DWORD petID;
		BYTE unk1[0x18]; //Some random pet info, idk
		BYTE petName[0x16]; //It's not a wchar actually, for once
		BYTE unk2[0x72];
		DWORD ownerID;
		BYTE unk3[0x20];
	} ATTRPACK;
	);


	PACKED(
	struct PacketPlayerAction //04.15
	{
		DWORD playerID;
		BYTE unk1[0x8];
		DWORD objID;
		BYTE unk2[0xC];
		DWORD userID; //The user taking the action
		BYTE unk3[0x1C];
		CHAR action[0xC];
	} ATTRPACK;
	);
}
