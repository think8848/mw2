/******************************************************************************
*@Copyright UniGium Information Technology (ShangHai) Co.,Ltd. 
 2005 ALL RIGHTS RESERVED.

*file name    : player_info.h
*owner        : Andy
*description  : 
*modified     : 2005/1/6
******************************************************************************/ 

#ifndef PLAYER_INFO_H
#define PLAYER_INFO_H

#include "data.h"

#pragma once

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_MOVE_START				0x00030001
#define NET_MSG_PLAYER_MOVE_START_RETURN		0x00030001
#define NET_MSG_PLAYER_MOVE_END					0x00030002
#define NET_MSG_PLAYER_MOVE_END_RETURN			0x00030002
#define NET_MSG_PLAYER_MOVE_SYNC				0x00030003
#define NET_MSG_PLAYER_MOVE_SYNC_RETURN			0x00030003


#define NPC_STATUS_NONE							0x00000000
#define NPC_STATUS_LEADER						0x00000001		// 队长
#define NPC_STATUS_FIGHT						0x00000002
#define NPC_STATUS_BORN							0x00000004
#define NPC_STATUS_FOLLOW						0x00000008		// 队友
#define NPC_STATUS_FULL							0x00000010		// 加血


#define NPC_STATUS_BORN_MASK					0xFFFFFFFB
#define NPC_STATUS_FULL_MASK					0xFFFFFFEF


enum
{
	PLAYER_MOVE_ERROR = -1,
	PLAYER_MOVE_OK
};

typedef struct _PLAYER_MOVE
{
	unsigned int char_id;
	word tx, ty;
	char speed;
	char dir;
}PLAYER_MOVE;

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_CHAT_SERVER				0x00030004
#define NET_MSG_PLAYER_CHAT_SERVER_RETURN		0x00030004

typedef struct _CHAT_SERVER_INFO
{
	DWORD ip;
	WORD  port;
}CHAT_SERVER_INFO;

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_CHARACTER_LIST			0x00030007
#define NET_MSG_PLAYER_CHARACTER_LIST_RETURN	0x00030007

typedef struct _BASE_CHARACTER_INFO
{
	unsigned int  char_id;
	char nickname[MAX_NAME_LENGTH+1];
	char  phyle;
	char  sex;
	int  level;
}BASE_CHARACTER_INFO;

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_SELECT_CHARACTER			0x00030008
#define NET_MSG_PLAYER_SELECT_CHARACTER_RETURN	0x00030008
enum
{
	SELECT_CHARACTER_ERROR = -1,
	SELECT_CHARACTER_OK
};

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_ADD_PLAYER				0x0003000A
#define NET_MSG_PLAYER_ADD_PLAYER_RETURN		0x0003000A

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_ENTER_SCENE				0x0003000C
#define NET_MSG_PLAYER_ENTER_SCENE_RETURN		0x0003000C
enum
{
	ENTER_SCENE_ERROR = -1,
	ENTER_SCENE_OK
};

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_CREATE_CHARACTER			0x0003000E
#define NET_MSG_PLAYER_CREATE_CHARACTER_RETURN	0x0003000E
enum
{
	CREATE_CHARACTER_NICKNAME_EXIST = -2,
	CREATE_CHARACTER_ERROR = -1,
	CREATE_CHARACTER_OK
};

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_EXIT_SCENE				0x0003000F
#define NET_MSG_PLAYER_EXIT_SCENE_RETURN		0x0003000F

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_CHANGE_SCENE				0x00030010
#define NET_MSG_PLAYER_CHANGE_SCENE_RETURN		0x00030010

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_NPC_LIST					0x00030012
#define NET_MSG_PLAYER_NPC_LIST_RETURN			0x00030012

typedef struct BASE_NPC_INFO_STRUCT
{
	unsigned int id;								// ID
	char name[MAX_NAME_LENGTH+1];					// 昵称
	char title[MAX_TITLE_LENGTH+1];					// 称谓
	int filename_id;								// MDA 档案名称 id
	char base_type;									// 基本形态 0 到 8 
	word x, y;										// 目前坐标
	word tx,ty;										// 目的地坐标
	char speed;										// 跑步或者走路 0 -> 走路 1 -> 跑步
	char motility;									// 移动类型
	char dir;										// 方向
	char move_type;									// 移动方式
	int status;										// NPC 目前状态(显示)
	char life_base;									// 目前几转
}BASE_NPC_INFO;

// ---- stephen

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_EXIST_SCENE_RETURN		0x00030013
#define NET_MSG_PLAYER_OTHER_ENTER_RETURN		0x00030014


#define NET_MSG_PLAYER_WEATHER_RETURN			0x00030015

#define NET_MSG_PLAYER_BASE_SCENE_INFO			0x00030100
#define NET_MSG_PLAYER_BASE_SCENE_INFO_RETURN	0x00030100

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_FRIEND_LIST				0x00030016
#define NET_MSG_PLAYER_FRIEND_LIST_RETURN		0x00030016

#define NET_MSG_PLAYER_FRIEND_ADD				0x00030017
#define NET_MSG_PLAYER_FRIEND_ADD_RETURN		0x00030017
enum
{
	FRIEND_ADD_MAX_NUM	 = -3,
	FRIEND_ADD_NOT_ALLOW = -2,
	FRIEND_ADD_ERROR	 = -1,
	FRIEND_ADD_OK		 =  0,
	FRIEND_ADD_BY_OTHER  =  1,
};

#define NET_MSG_PLAYER_FRIEND_SUB				0x00030018
#define NET_MSG_PLAYER_FRIEND_SUB_RETURN		0x00030018

#define NET_MSG_PLAYER_FRIEND_UPDATE			0x00030019
#define NET_MSG_PLAYER_FRIEND_UPDATE_RETURN		0x00030019
enum
{
	FRIEND_UPDATE_ERROR			= -2,
	FRIEND_UPDATE_NOT_ONLINE,	
	FRIEND_UPDATE_OK,
};

#define NET_MSG_PLAYER_FRIEND_ONLINE			0x0003001A
#define NET_MSG_PLAYER_FRIEND_ONLINE_RETURN		0x0003001A

#define NET_MSG_PLAYER_FRIEND_OFFLINE			0x0003001B
#define NET_MSG_PLAYER_FRIEND_OFFLINE_RETURN	0x0003001B

#define NET_MSG_PLAYER_FRIEND_TYPE				0x0003001D
#define NET_MSG_PLAYER_FRIEND_TYPE_RETURN		0x0003001D

#define NET_MSG_PLAYER_FIND_FRIEND				0x0003001E
#define NET_MSG_PLAYER_FIND_FRIEND_RETURN		0x0003001E
enum
{
	FIND_FRIEND_TYPE_ID,
	FIND_FRIEND_TYPE_NAME
};

enum
{
	FIND_FRIEND_ERROR = -2,
	FIND_FRIEND_NOT_ONLINE,
	FIND_FRIEND_OK
};

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_CLIENT_CONFIG			0x0003001C
#define NET_MSG_PLAYER_CLIENT_CONFIG_RETURN		0x0003001C

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_CREATE_GROUP				0x00030030
#define NET_MSG_PLAYER_CREATE_GROUP_RETURN		0x00030030
enum
{
	CREATE_GROUP_HAD		= -2,
	CREATE_GROUP_ERROR		= -1,
	CREATE_GROUP_OK			=  0,
};

#define NET_MSG_PLAYER_ADD_TO_GROUP				0x00030033
#define NET_MSG_PLAYER_ADD_TO_GROUP_RETURN		0x00030033
enum
{
	ADD_TO_GROUP_ERROR = -1,
	ADD_TO_GROUP_OK
};

#define NET_MSG_PLAYER_EXIT_GROUP				0x00030034
#define NET_MSG_PLAYER_EXIT_GROUP_RETURN		0x00030034

#define NET_MSG_PLAYER_ADD_GROUP_LIST			0x00030031
#define NET_MSG_PLAYER_ADD_GROUP_LIST_RETURN	0x00030031
enum
{
	ADD_GROUP_LIST_NOT_HEADER = -3,
	ADD_GROUP_LIST_EXIST,
	ADD_GROUP_LIST_ERROR,
	ADD_GROUP_LIST_OK,
	ADD_GROUP_LIST_NEW
};

#define NET_MSG_PLAYER_SUB_GROUP_LIST			0x00030032
#define NET_MSG_PLAYER_SUB_GROUP_LIST_RETURN	0x00030032
enum
{
	SUB_GROUP_LIST_NOT_EXIST = -2,
	SUB_GROUP_LIST_ERROR,
	SUB_GROUP_LIST_OK,
};

#define NET_MSG_PLAYER_GROUP_NEW_PLAYER			0x00030035
#define NET_MSG_PLAYER_GROUP_NEW_PLAYER_RETURN  0x00030035

#define NET_MSG_PLAYER_GET_REQUEST_LIST			0x00030036
#define NET_MSG_PLAYER_GET_REQUEST_LIST_RETURN	0x00030036

#define NET_MSG_PLAYER_GET_GROUP_LIST			0x00030037
#define NET_MSG_PLAYER_GET_GROUP_LIST_RETURN	0x00030037

#define NET_MSG_PLAYER_CLEAR_REQUEST_LIST			0x00030038
#define NET_MSG_PLAYER_CLEAR_REQUEST_LIST_RETURN	0x00030038
enum
{
	CLEAR_REQUEST_LIST_ERROR = -1,
	CLEAR_REQUEST_LIST_OK
};

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_MACRO_TEXT				0x00040001
#define NET_MSG_PLAYER_MACRO_TEXT_RETURN		0x00040001

#define NET_MSG_PLAYER_MACRO_NPC				0x00040002
#define NET_MSG_PLAYER_MACRO_NPC_RETURN			0x00040002

#define NET_MSG_PLAYER_MACRO_SELECT				0x00040003
#define NET_MSG_PLAYER_MACRO_SELECT_RETURN		0x00040003

#define NET_MSG_PLAYER_MACRO_CMD				0x00040004
#define NET_MSG_PLAYER_MACRO_CMD_RETURN			0x00040004

#define NET_MSG_PLAYER_TASK_LIST				0x00040005
#define NET_MSG_PLAYER_TASK_LIST_RETURN			0x00040005
typedef struct _MACRO_BASE_INFO
{
	struct 
	{
		SLONG type;
		unsigned char len;
	}base;

	char *text;
}MACRO_BASE_INFO;

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_DATA_CHAR_INFO			0x00050001
#define NET_MSG_PLAYER_DATA_CHAR_INFO_RETURN	0x00050001

#define NET_MSG_PLAYER_DATA_POINT_BACK			0x00050002
#define NET_MSG_PLAYER_DATA_POINT_BACK_RETURN	0x00050002
enum
{
	POINT_BACK_ERROR,
	POINT_BACK_OK
};

#define NET_MSG_PLAYER_DATA_LEVEL_UP			0x00050003
#define NET_MSG_PLAYER_DATA_LEVLE_UP_RETURN		0x00050003

struct net_level_up_t
{
	SERVER_CHATACTER_BASE base;

	SERVER_CHARACTER_FINAL final;
};

#define NET_MSG_PLAYER_DATA_EXP_UP				0x00050004
#define NET_MSG_PLAYER_DATA_EXP_UP_RETURN		0x00050004

#define NET_MSG_PLAYER_FASTNESS					0x00050005
#define NET_MSG_PLAYER_FASTNESS_RETURN			0x00050005

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_BAOBAO_LIST				0x00060001
#define NET_MSG_PLAYER_BAOBAO_LIST_RETURN		0x00060001

#define NET_MSG_PLAYER_BAOBAO_NAME				0x00060002
#define NET_MSG_PLAYER_BAOBAO_NAME_RETURN		0x00060002

#define NET_MSG_PLAYER_BAOBAO_POINT_BACK		0x00060003
#define NET_MSG_PLAYER_BAOBAO_POINT_BACK_RETURN	0x00060003

#define NET_MSG_PLAYER_BAOBAO_LEVEL_UP			0x00060004
#define NET_MSG_PLAYER_BAOBAO_LEVLE_UP_RETURN	0x00060004

#define NET_MSG_PLAYER_BAOBAO_EXP_UP			0x00060005
#define NET_MSG_PLAYER_BAOBAO_EXP_UP_RETURN		0x00060005

#define NET_MSG_PLAYER_BAOBAO_FOLLOW			0x00060006
#define NET_MSG_PLAYER_BAOBAO_FOLLOW_RETURN		0x00060006

#define NET_MSG_PLAYER_BAOBAO_CLOSE				0x00060007
#define NET_MSG_PLAYER_BAOBAO_CLOSE_RETURN		0x00060007

#define NET_MSG_PLAYER_BAOBAO_ACTION_ON			0x00060008
#define NET_MSG_PLAYER_BAOBAO_ACTION_ON_RETURN	0x00060008

#define NET_MSG_PLAYER_BAOBAO_ACTION_OFF		0x00060009
#define NET_MSG_PLAYER_BAOBAO_ACTION_OFF_RETURN	0x00060009

#define NET_MSG_PLAYER_BAOBAO_ADD				0x0006000A
#define NET_MSG_PLAYER_BAOBAO_ADD_RETURN		0x0006000A

#define NET_MSG_PLAYER_BAOBAO_REMOVE			0x0006000B
#define NET_MSG_PLAYER_BAOBAO_REMOVE_RETURN		0x0006000B

#define NET_MSG_PLAYER_BAOBAO_FASTNESS			0x0006000C
#define NET_MSG_PLAYER_BAOBAO_FASTNESS_RETURN	0x0006000C

//////////////////////////////////////////////////////////////////////////
//
//
//
//
//
//////////////////////////////////////////////////////////////////////////
#define NET_MSG_PLAYER_ITEM_LIST				0x00070001
#define NET_MSG_PLAYER_ITEM_LIST_RETURN			0x00070001

#define NET_MSG_PLAYER_ITEM_ADD					0x00070002
#define NET_MSG_PLAYER_ITEM_ADD_RETURN			0x00070002

#define NET_MSG_PLAYER_ITEM_REMOVE				0x00070003
#define NET_MSG_PLAYER_ITEM_REMOVE_RETURN		0x00070003

typedef struct _ITEM_DATA_EX
{
	int idx;

	PUBLIC_ITEM_DATA imd;

}ITEM_DATA_EX;

#define NET_MSG_PLAYER_ITEM_CHANGE				0x00070004
#define NET_MSG_PLAYER_ITEM_CHANGE_RETURN		0x00070004

#define NET_MSG_PLAYER_ITEM_USE					0x00070005
#define NET_MSG_PLAYER_ITEM_USE_RETURN			0x00070005

#define NET_MSG_PLAYER_ITEM_MONEY				0x00070006
#define NET_MSG_PLAYER_ITEM_MONEY_RETURN		0x00070006

#define NET_MSG_PLAYER_ITEM_GIVE				0x00070007
#define NET_MSG_PLAYER_ITEM_GIVE_RETURN			0x00070007

#define NET_MSG_PLAYER_ITEM_DISCHARGE			0x00070008
#define NET_MSG_PLAYER_ITEM_DISCHARGE_RETURN	0x00070008
enum
{
	DISCHARGE_RETURN_NOT_EQUIPE = -2,
	DISCHARGE_RETURN_NO_POCKET,
	DISCHARGE_RETURN_OK,
};

#define NET_MSG_PLAYER_EQUIPE_CHANGE			0x00070009
#define NET_MSG_PLAYER_EQUIPE_CHANGE_RETURN		0x00070009
enum
{
	EQUIPE_CHANGE_ERROR_PHYLE = -6,
	EQUIPE_CHANGE_ERROR_LEVEL,
	EQUIPE_CHANGE_ERROR_HP,
	EQUIPE_CHANGE_ERROR_MP,
	EQUIPE_CHANGE_ERROR_ATT,
	EQUIPE_CHANGE_ERROR_SP,
	EQUIPE_CHANGE_OK,
};

#define NET_MSG_PLAYER_EQUIPE_LIST				0x0007000A
#define NET_MSG_PLAYER_EQUIPE_LIST_RETURN		0x0007000A

#define NET_MSG_PLAYER_BANK_ITEM_LIST			0x0007000B
#define NET_MSG_PLAYER_BANK_ITEM_LIST_RETURN	0x0007000B

#define NET_MSG_PLAYER_BANK_ITEM_CHANGE			0x0007000C
#define NET_MSG_PLAYER_BANK_ITEM_CHANGE_RETURN	0x0007000C

#define NET_MSG_PLAYER_ITEM_INFO				0x0007000D
#define NET_MSG_PLAYER_ITEM_INFO_RETURN			0x0007000D

#define NET_MSG_PLAYER_STORE_ITEM_LIST			0x0007000E
#define NET_MSG_PLAYER_STORE_ITEM_LIST_RETURN	0x0007000E

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_DEAL_SEND_REQUEST		0x00080001
#define NET_MSG_PLAYER_DEAL_SEND_REQUEST_RETURN	0x00080001

#define NET_MSG_PLAYER_DEAL_RECV_REQUEST		0x00080002
#define NET_MSG_PLAYER_DEAL_RECV_REQUEST_RETURN	0x00080002

#define NET_MSG_PLAYER_DEAL_CANCLE				0x00080003
#define NET_MSG_PLAYER_DEAL_CANCLE_RETURN		0x00080003

#define NET_MSG_PLAYER_DEAL_ITEM_LIST			0x00080004
#define NET_MSG_PLAYER_DEAL_ITEM_LIST_RETURN	0x00080004
struct deal_item_t
{
	int item_idx[3];
	int item_num[3];
	int money;
};

#define NET_MSG_PLAYER_DEAL_REVC_ITEM			0x00080005
#define NET_MSG_PLAYER_DEAL_REVC_ITEM_RETURN	0x00080005

#define NET_MSG_PLAYER_DEAL_RESET_ITEM			0x00080006
#define NET_MSG_PLAYER_DEAL_RESET_ITEM_RETURN	0x00080006

#define NET_MSG_PLAYER_DEAL_OK					0x00080007
#define NET_MSG_PLAYER_DEAL_OK_RETURN			0x00080007

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_REFRESH_MAP				0x00090001
#define NET_MSG_PLAYER_REFRESH_MAP_RETURN		0x00090001

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_STORE_BUY				0x000A0001
#define NET_MSG_PLAYER_STORE_BUY_RETURN			0x000A0001

#define NET_MSG_PLAYER_STORE_SELL				0x000A0002
#define NET_MSG_PLAYER_STORE_SELL_RETURN		0x000A0002

#define NET_MSG_PLAYER_BANK_SAVE				0x000A0003
#define NET_MSG_PLAYER_BANK_SAVE_RETURN			0x000A0003

#define NET_MSG_PLAYER_BANK_GIVE				0x000A0004
#define NET_MSG_PLAYER_BANK_GIVE_RETURN			0x000A0004

#define NET_MSG_PLAYER_POPSHOP_ITEM_LIST		0x000A0005
#define NET_MSG_PLAYER_POPSHOP_ITEM_LIST_RETURN	0x000A0005

#define NET_MSG_PLAYER_POPSHOP_ITEM_PUSH		0x000A0006 // 放在当铺口袋
#define NET_MSG_PLAYER_POPSHOP_ITEM_PUSH_RETURN	0x000A0006

#define NET_MSG_PLAYER_POPSHOP_ITEM_POP			0x000A0007 // 取出当铺口袋
#define NET_MSG_PLAYER_POPSHOP_ITEM_POP_RETURN	0x000A0007

//#define NET_MSG_PLAYER_PS_ITEM_CHANGE			0x000A0008
//#define NET_MSG_PLAYER_PS_ITEM_CHANGE_RETURN	0x000A0008

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_SKILL_LIST				0x000B0001
#define NET_MSG_PLAYER_SKILL_LIST_RETURN		0x000B0001

#define NET_MSG_PLAYER_ADD_SKILL				0x000B0002
#define NET_MSG_PLAYER_ADD_SKILL_RETURN			0x000B0002

//#define NET_MSG_PLAYER_SKILL_ADD				0x000B0002
//#define NET_MSG_PLAYER_SKILL_ADD_RETURN			0x000B0002

#define NET_MSG_PLAYER_PET_SKILL_LIST			0x000B0003
#define NET_MSG_PLAYER_PET_SKILL_LIST_RETURN	0x000B0003

#define NET_MSG_PLAYER_PET_ADD_SKILL			0x000B0004
#define NET_MSG_PLAYER_PET_ADD_SKILL_RETURN		0x000B0004

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_START_FIGHT					0x000C0001
#define NET_MSG_PLAYER_START_FIGHT_RETURN			0x000C0001

struct FIGHT_BASE_DATA_EX
{
	char idx;

	FIGHT_BASE_DATA data;
};

#define NET_MSG_PLAYER_FIGHT_CLIENT_READY			0x000C0002
#define NET_MSG_PLAYER_FIGHT_CLIENT_READY_RETURN	0x000C0002

#define NET_MSG_PLAYER_FIGHT_CHARGE_START			0x000C0003
#define NET_MSG_PLAYER_FIGHT_CHARGE_START_RETURN	0x000C0003

#define NET_MSG_PLAYER_FIGHT_STATUS_RESULT			0x000C0004
#define NET_MSG_PLAYER_FIGHT_STATUS_RESULT_RETURN	0x000C0004

#define NET_MSG_PLAYER_FIGHT_COMMAND				0x000C0005
#define NET_MSG_PLAYER_FIGHT_COMMAND_RETURN			0x000C0005

#define NET_MSG_PLAYER_FIGHT_RESULT					0x000C0006
#define NET_MSG_PLAYER_FIGHT_RESULT_RETURN			0x000C0006

#define NET_MSG_PLAYER_FIGHT_PLAY_FINISH			0x000C0007
#define NET_MSG_PLAYER_FIGHT_PLAY_FINISH_RETURN		0x000C0007

#define NET_MSG_PLAYER_FIGHT_END					0x000C0008
#define NET_MSG_PLAYER_FIGHT_END_RETURN				0x000C0008

#define NET_MSG_PLAYER_FIGHT_CHARGE_PAUSE			0x000C0009
#define NET_MSG_PLAYER_FIGHT_CHARGE_PAUSE_RETURN	0x000C0009

#define NET_MSG_PLAYER_PET_FIGHT_COMMAND			0x000C000A
#define NET_MSG_PLAYER_PET_FIGHT_COMMAND_RETURN		0x000C000A

struct fight_result_t
{
	struct  
	{
		FIGHT_ACTION_RESULT action;

		unsigned char value_num;

		int cust_len;
	}base;

	FIGHT_VALUE_RESULT *value;

	char *cust_buf;
};

#define NET_MSG_PLAYER_FIGHT_CHARGE_CONTINUE		0x000C000A
#define NET_MSG_PLAYER_FIGHT_CHARGE_CONTINUE_RETURN	0x000C000A

//////////////////////////////////////////////////////////////////////////
//
#define NET_MSG_PLAYER_NOW_HP_CHANGE				0x000D0001
#define NET_MSG_PLAYER_NOW_HP_CHANGE_RETURN			0x000D0001

#define NET_MSG_PLAYER_NOW_MP_CHANGE				0x000D0002
#define NET_MSG_PLAYER_NOW_MP_CHANGE_RETURN			0x000D0002

#define NET_MSG_PLAYER_PET_NOW_HP_CHANGE			0x000D0003
#define NET_MSG_PLAYER_PET_NOW_HP_CHANGE_RETURN		0x000D0003

#define NET_MSG_PLAYER_PET_NOW_MP_CHANGE			0x000D0004
#define NET_MSG_PLAYER_PET_NOW_MP_CHANGE_RETURN		0x000D0004

#endif // #ifndef PLAYER_INFO_H
