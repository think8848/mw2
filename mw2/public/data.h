/******************************************************************************
*@Copyright UniGium Information Technology (ShangHai) Co.,Ltd. 2003 ALL RIGHTS RESERVED.

  *file name    : data.h
  *owner  		: Stephen
  *description  : 
  *modified     : 2004/12/16
******************************************************************************/ 

#ifndef _DATA_H_
#define _DATA_H_


// ---------------- Version Data ----------------------
#define GAME_VERSION	00003
#define GAME_NAME		MSG_GAME_NAME
// ----------------------------------------------------


/*******************************************************************************************************************}
{																													}
{		通用型定义																									}
{																													}
********************************************************************************************************************/
// --- 文字长度 define
#define MAX_FILENAME_LENGTH							16		// 档案名称长度
#define MAX_NAME_LENGTH								14		// 昵称长度
#define MAX_TITLE_LENGTH							20		// 称谓长度
#define MAX_TITLE_INST_LENGTH						40		// 称谓描述长度
#define MAX_MAP_NAME_LENGTH							12		// 地图名称长度
#define MAX_GROUP_NAME_LENGTH						14		// 公会名称长度
#define MAX_BAOBAO_NAME_LENGTH						14		// 宝宝名称长度
#define MAX_ITEM_NAME_LENGTH						10		// 物品名称长度
#define MAX_ITEM_INST_LENGTH						40		// 物品描述长度
#define MAX_SKILL_NAME_LENGTH						14		// 法术名称长度
#define MAX_SKILL_INST_LENGTH						40		// 法术描述长度
#define MAX_DETAIL_INST_LENGTH						256		// 详细说明长度


#define MAX_POCKET_ITEM								24		// 口袋最大容量
#define MAX_EQUIP_ITEM								7		// 装备最大数量
#define MAX_POPSHOP_ITEM							24		// 当铺最大容量

#define MAX_BAOBAO_STACK							20		// 宝宝 stack 最大容量

// --- 资料record define
#define MAX_CHAT_FRIEND_LIST						100		// 好友最大个数


#define MAX_TEAM_PLAYER								5		// 最多组队人数
#define MAX_TEAM_REQUEST							20		// 请求列表 20


// ---- 可以对话的距离
#define NPC_TALK_RANGE								300

#define MAX_MENU_ITEM_LIST							12		// 最多 Macro 选项


#define NPC_ID_MASK						0x80000000		// 1000 0000 0000 0000 0000 0000 0000 0000
#define BAOBAO_ID_MASK					0xC0000000		// 1100 0000 0000 0000 0000 0000 0000 0000


#define BAOBAO_ID_CHECK_MASK			0x40000000		// 0100 0000 0000 0000 0000 0000 0000 0000

#define FOLLOW_NEAR_RANGE							50		// 跟随距离 pixel
#define FOLLOW_JUMP_RANGE							600		// 宝宝脱离自动跳耀距离


#define MAIN_LOOP_MAP_MODE							0	// 主回路地图模式
#define MAIN_LOOP_FIGHT_MODE						1	// 主回路战斗模式


#define MAX_PHYSICS_DOUBLE_TIMES					7	// 最大物理连击次数
#define MAX_MAGIC_DOUBLE_TIMES						7	// 最大法术连击次数
#define MAX_FIGHT_UNIT								20	// 最大战斗单位

// -------- Item control
#define MAX_ITEM_IMAGE								250 
#define MAX_ITEM_OVERFLOW							30


#define PLAYER_MOVE_CHECK_TIMER						250

#define DETAIL_DELAY_TIME							1000


#define MAX_CHARACTER_SKILL_NO						20			// 玩家技能最大数量
#define MAX_BAOBAO_SKILL_NO							8			// 宝宝技能最大数量



#define MAX_BASE_CHARGE_TABLE						20			// 充电速度列表数目

static SLONG base_charge_time_table[MAX_BASE_CHARGE_TABLE]=
{
		5000,					// 0 
		5080,					// 1
		5160,					// 2
		5240,					// 3
		5320,					// 4
		5400,					// 5
		5480,					// 6
		5560,					// 7
		5640,					// 8
		5720,					// 9
		5800,					// 10
		5880,					// 11
		5960,					// 12
		6040,					// 13
		6120,					// 14
		6200,					// 15
		6280,					// 16
		6360,					// 17
		6440,					// 18
		6520					// 19
};


typedef struct PUBLIC_SKILL_BASE_STRUCT				// 技能基本资料
{
	// ---- 基本资料
	UCHR name[MAX_SKILL_NAME_LENGTH+1];				// 名称
	UCHR inst[MAX_SKILL_INST_LENGTH+1];				// 描述
	SHINT effect;									// 使用效果  ( see SKILL_EFFECT enum )
	SHINT mp;										// 所需要 MP
	SHINT add_mp;									// 每次使用需加 MP
	SHINT count;									// 持续回合
	SHINT number;									// 效果人数
	SHINT type;										// 我方敌方判别 0 -> 我方, 1 -> 敌方  
	ULONG lithand;									// 每次使用所加熟练
	// ---- 控制
	SHINT mda_filename_id;							// MDA 档案
	SHINT ani_filename_id;							// ANI 档案
	
} PUBLIC_SKILL_BASE;




#define TOTAL_SKILL								(ARRAYSIZE(skill_base_data))

static PUBLIC_SKILL_BASE skill_base_data[]={
/*	{
		"0000",											// 名称
		"说明0",										// 描述
		0,												// 使用效果  ( see SKILL_EFFECT enum )
		200,											// 所需要 MP
		0,												// 每次使用需加 MP
		0,												// 持续回合
		0,												// 效果人数
		1,												// 我方敌方判别 0 -> 我方, 1 -> 敌方  
		0,												// 每次使用所加熟练
		0,												// MDA 档案
		0												// ANI 档案
	},

	{	"0001",	"说明1",0,0,0,0,0,0,0,0,0 	},
	{	"0002",	"说明2",0,0,0,0,0,0,0,0,0 	},
	{	"0003",	"说明3",0,0,0,0,0,0,0,0,0 	},
	{	"0004",	"说明4",0,0,0,0,0,0,0,0,0 	},
	{	"0005",	"说明5",0,0,0,0,0,0,0,0,0 	},
	{	"0006",	"说明6",0,0,0,0,0,0,0,0,0 	},
	{	"0007",	"说明7",0,0,0,0,0,0,0,0,0 	},
	{	"0008",	"说明8",0,0,0,0,0,0,0,0,0 	},
	{	"0009",	"说明9",0,0,0,0,0,0,0,0,0 	},
	{	"0010",	"说明10",0,0,0,0,0,0,0,0,0 	},
	{	"0011",	"说明11",0,0,0,0,0,0,0,0,0 	},
	{	"0012",	"说明12",0,0,0,0,0,0,0,0,0 	},
	{	"0013",	"说明13",0,0,0,0,0,0,0,0,0 	},
	{	"0014",	"说明14",0,0,0,0,0,0,0,0,0 	},
	{	"0015",	"说明15",0,0,0,0,0,0,0,0,0 	},
	{	"0016",	"说明16",0,0,0,0,0,0,0,0,0 	},
	{	"0017",	"说明17",0,0,0,0,0,0,0,0,0 	},
	{	"0018",	"说明18",0,0,0,0,0,0,0,0,0 	},
	{	"0019",	"说明19",0,0,0,0,0,0,0,0,0 	}
*/
	{	"衰老术一阶",     	"单体衰老",    	     4,	     5,	       0.080,	     3,	     1,	     1,	     1,	    201,	 202 },
	{	"衰老术二阶",     	"群体衰老",    	     4,	    15,	       0.130,	     3,	     2,	     1,	     1,	     1,	     1	},
	{	"衰老术三阶",     	"单体衰老",    	     4,	    10,	       0.120,	     3,	     1,	     1,	     1,	     1,	     1	},
	{	"衰老术四阶",     	"群体衰老",    	     4,	    30,	       0.170,	     3,	     2,	     1,	     1,	     1,	     1	},
	{	"毒系一阶",       	"单体中毒",    	     3,	     5,	       0.080,	     3,	     1,	     1,	     1,	     1,	     1	},
	{	"毒系二阶",       	"群体中毒",    	     3,	    15,	       0.130,	     3,	     2,	     1,	     1,	     1,	     1	},
	{	"毒系三阶",       	"单体中毒",    	     3,	    10,	       0.120,	     3,	     1,	     1,	     1,	     1,	     1	},
	{	"毒系四阶",       	"群体中毒",    	     3,	    30,	       0.170,	     3,	     2,	     1,	     1,	     1,	     1	},
	{	"混乱术一阶",     	"单体混乱",    	     4,	     5,	       0.080,	     3,	     1,	     1,	     1,	     1,	     1	},
	{	"混乱术二阶",     	"群体混乱",    	     4,	    15,	       0.130,	     3,	     2,	     1,	     1,	     1,	     1	},
	{	"混乱术三阶",     	"单体混乱",    	     4,	    10,	       0.120,	     3,	     1,	     1,	     1,	     1,	     1	},
	{	"混乱术四阶",     	"群体混乱",    	     4,	    30,	       0.170,	     3,	     2,	     1,	     1,	     1,	     1	},
	{	"催眠术一阶",     	"单体昏睡",    	     2,	     5,	       0.080,	     3,	     1,	     1,	     1,	     1,	     1	},
	{	"催眠术二阶",     	"群体昏睡",    	     2,	    15,	       0.130,	     3,	     2,	     1,	     1,	     1,	     1	},
	{	"催眠术三阶",     	"单体昏睡",    	     2,	    10,	       0.120,	     3,	     1,	     1,	     1,	     1,	     1	},
	{	"催眠术四阶",     	"群体昏睡",    	     2,	    30,	       0.170,	     3,	     2,	     1,	     1,	     1,	     1	},
	{	"石化术一阶",     	"单体石化",    	     0,	     5,	       0.080,	     3,	     1,	     1,	     1,	     1,	     1	},
	{	"石化术二阶",     	"群体石化",    	     0,	    15,	       0.130,	     3,	     2,	     1,	     1,	     1,	     1	},
	{	"石化术三阶",     	"单体石化",    	     0,	    10,	       0.120,	     3,	     1,	     1,	     1,	     1,	     1	},
	{	"石化术四阶",     	"群体石化",    	     0,	    30,	       0.170,	     3,	     2,	     1,	     1,	     1,	     1	},
	{	"解除混乱一阶",   	"单体解除混乱",	    10,	     7,	       0.080,	     0,	     1,	     0,	     1,	     1,	     1	},
	{	"解除混乱二阶",   	"群体解除混乱",	    10,	    20,	       0.130,	     0,	     2,	     0,	     1,	     1,	     1	},
	{	"解除混乱三阶",   	"单体解除混乱",	    10,	    12,	       0.120,	     0,	     1,	     0,	     1,	     1,	     1	},
	{	"解除混乱四阶",   	"群体解除混乱",	    10,	    35,	       0.170,	     0,	     2,	     0,	     1,	     1,	     1	},
	{	"解除石化一阶",   	"单体解除石化",	    10,	     7,	       0.080,	     0,	     1,	     0,	     1,	     1,	     1	},
	{	"解除石化二阶",   	"群体解除石化",	    10,	    20,	       0.130,	     0,	     2,	     0,	     1,	     1,	     1	},
	{	"解除石化三阶",   	"单体解除石化",	    10,	    12,	       0.120,	     0,	     1,	     0,	     1,	     1,	     1	},
	{	"解除石化四阶",   	"群体解除石化",	    10,	    35,	       0.170,	     0,	     2,	     0,	     1,	     1,	     1	},
	{	"连矢",           	"单体多次攻击",	    12,	     7,	       0.060,	     0,	     1,	     1,	     1,	     1,	     1	},
	{	"乱射",           	"群体多次攻击",	    12,	    20,	       0.100,	     0,	     2,	     1,	     1,	     1,	     1	},
	{	"魔弓",           	"单体多次攻击",	    12,	    12,	       0.120,	     0,	     1,	     1,	     1,	     1,	     1	},
	{	"箭雨",           	"群体多次攻击",	    12,	    35,	       0.160,	     0,	     2,	     1,	     1,	     1,	     1	},
	{	"速度提升一阶",   	"单体加速",    	    13,	     7,	       0.080,	     3,	     1,	     0,	     1,	     1,	     1	},
	{	"速度提升二阶",   	"群体加速",    	    13,	    20,	       0.130,	     3,	     2,	     0,	     1,	     1,	     1	},
	{	"速度提升三阶",   	"单体加速",    	    13,	    12,	       0.120,	     3,	     1,	     0,	     1,	     1,	     1	},
	{	"速度提升四阶",   	"群体加速",    	    13,	    35,	       0.170,	     3,	     2,	     0,	     1,	     1,	     1	},
	{	"治愈术一阶",     	"单体回复体力",	    14,	     7,	       0.080,	     0,	     1,	     0,	     1,	     1,	     1	},
	{	"治愈术二阶",     	"群体回复体力",	    14,	    20,	       0.130,	     0,	     2,	     0,	     1,	     1,	     1	},
	{	"治愈术三阶",     	"单体回复体力",	    14,	    12,	       0.120,	     0,	     1,	     0,	     1,	     1,	     1	},
	{	"治愈术四阶",     	"群体回复体力",	    14,	    35,	       0.170,	     0,	     2,	     0,	     1,	     1,	     1	},
	{	"火系法术一阶",   	"单体火系攻击",	    23,	     8,	       0.100,	     0,	     1,	     1,	     1,	     1,	     1	},
	{	"火系法术二阶",   	"群体火系攻击",	    23,	    12,	       0.150,	     0,	     2,	     1,	     1,	     1,	     1	},
	{	"火系法术三阶",   	"单体火系攻击",	    23,	    18,	       0.180,	     0,	     1,	     1,	     1,	     1,	     1	},
	{	"火系法术四阶",   	"群体火系攻击",	    23,	    30,	       0.230,	     0,	     2,	     1,	     1,	     1,	     1	},
	{	"水系法术一阶",   	"单体水系攻击",	    22,	     8,	       0.100,	     0,	     1,	     1,	     1,	     1,	     1	},
	{	"水系法术二阶",   	"群体水系攻击",	    22,	    12,	       0.150,	     0,	     2,	     1,	     1,	     1,	     1	},
	{	"水系法术三阶",   	"单体火系攻击",	    22,	    18,	       0.180,	     0,	     1,	     1,	     1,	     1,	     1	},
	{	"水系法术四阶",   	"群体火系攻击",	    22,	    30,	       0.230,	     0,	     2,	     1,	     1,	     1,	     1	},
	{	"暗系法术一阶",   	"单体暗系攻击",	    20,	     8,	       0.100,	     0,	     1,	     1,	     1,	     1,	     1	},
	{	"暗系法术二阶",   	"群体暗系攻击",	    20,	    12,	       0.150,	     0,	     2,	     1,	     1,	     1,	     1	},
	{	"暗系法术三阶",   	"单体暗系攻击",	    20,	    18,	       0.180,	     0,	     1,	     1,	     1,	     1,	     1	},
	{	"暗系法术四阶",   	"群体暗系攻击",	    20,	    30,	       0.230,	     0,	     2,	     1,	     1,	     1,	     1	},
	{	"光系法术一阶",   	"单体光系攻击",	    21,	     8,	       0.100,	     0,	     1,	     1,	     1,	     1,	     1	},
	{	"光系法术二阶",   	"群体光系攻击",	    21,	    12,	       0.150,	     0,	     2,	     1,	     1,	     1,	     1	},
	{	"光系法术三阶",   	"单体光系攻击",	    21,	    18,	       0.180,	     0,	     1,	     1,	     1,	     1,	     1	},
	{	"光系法术四阶",   	"群体光系攻击",	    21,	    30,	       0.230,	     0,	     2,	     1,	     1,	     1,	     1	},
	{	"死亡宣告一阶",   	"单体死亡宣告",	    24,	     8,	       0.100,	     9,	     1,	     1,	     1,	     1,	     1	},
	{	"死亡宣告二阶",   	"群体死亡宣告",	    24,	    12,	       0.150,	    10,	     2,	     1,	     1,	     1,	     1	},
	{	"死亡宣告三阶",   	"单体死亡宣告",	    24,	    18,	       0.180,	     6,	     1,	     1,	     1,	     1,	     1	},
	{	"死亡宣告四阶",   	"群体死亡宣告",	    24,	    30,	       0.230,	     8,	     2,	     1,	     1,	     1,	     1	},
	{	"威力提升一阶",   	"单体提升攻防",	    33,	     3,	       0.040,	     3,	     1,	     0,	     1,	     1,	     1	},
	{	"威力提升二阶",   	"群体提升攻防",	    33,	     5,	       0.090,	     3,	     2,	     0,	     1,	     1,	     1	},
	{	"威力提升三阶",   	"单体提升攻防",	    33,	     6,	       0.100,	     3,	     1,	     0,	     1,	     1,	     1	},
	{	"威力提升四阶",   	"群体提升攻防",	    33,	    10,	       0.150,	     3,	     2,	     0,	     1,	     1,	     1	},
	{	"抗性提升一阶",   	"单体提升抗性",	    34,	     3,	       0.040,	     3,	     1,	     0,	     1,	     1,	     1	},
	{	"抗性提升二阶",   	"群体提升抗性",	    34,	     5,	       0.090,	     3,	     2,	     0,	     1,	     1,	     1	},
	{	"抗性提升三阶",   	"单体提升抗性",	    34,	     6,	       0.100,	     3,	     1,	     0,	     1,	     1,	     1	},
	{	"抗性提升四阶",   	"群体提升抗性",	    34,	    10,	       0.150,	     3,	     2,	     0,	     1,	     1,	     1	},
	{	"吸收术一阶",     	"单体吸收",    	    30,	     3,	       0.040,	     0,	     1,	     1,	     1,	     1,	     1	},
	{	"吸收术二阶",     	"群体吸收",    	    30,	     5,	       0.090,	     0,	     2,	     1,	     1,	     1,	     1	},
	{	"吸收术三阶",     	"单体吸收",    	    30,	     6,	       0.100,	     0,	     1,	     1,	     1,	     1,	     1	},
	{	"吸收术四阶",     	"群体吸收",    	    30,	    10,	       0.150,	     0,	     2,	     1,	     1,	     1,	     1	},
	{	"物理反弹一阶",   	"单体物理反射",	    31,	     3,	       0.040,	     3,	     1,	     0,	     1,	     1,	     1	},
	{	"物理反弹二阶",   	"群体物理反射",	    31,	     5,	       0.090,	     3,	     2,	     0,	     1,	     1,	     1	},
	{	"物理反弹三阶",   	"单体物理反射",	    31,	     6,	       0.100,	     3,	     1,	     0,	     1,	     1,	     1	},
	{	"物理反弹四阶",   	"群体物理反射",	    31,	    10,	       0.150,	     3,	     2,	     0,	     1,	     1,	     1	},
	{	"魔法反射一阶",   	"单体法术反射",	    32,	     3,	       0.040,	     3,	     1,	     0,	     1,	     1,	     1	},
	{	"魔法反射二阶",   	"群体法术反射",	    32,	     5,	       0.090,	     3,	     2,	     0,	     1,	     1,	     1	},
	{	"魔法反射三阶",   	"单体法术反射",	    32,	     6,	       0.100,	     3,	     1,	     0,	     1,	     1,	     1	},
	{	"魔法反射四阶",   	"群体法术反射",	    32,	    10,	       0.150,	     3,	     2,	     0,	     1,	     1,	     1	},		
};




/*******************************************************************************************************************}
{																													}
{		Define 程序执行流程 & Control Code																			}
{																													}
********************************************************************************************************************/
enum	SYSTEM_MAIN_TASK_CODE
{
		TASK_SYSTEM_INITIALIZE=						0,			// 系统启动
		TASK_SHOW_TITLE=							1,			// 显示片头 Avi
		TASK_SELECT_MAINFUNCTION=					2,			// 游戏选择主界面
		TASK_SYSTEM_BROADCAST=						3,			// 系统公告
		TASK_SERVER_SELECT=							4,			// 服务器选择界面
		TASK_ACCOUNT_INPUT=							5,			// 帐号输入界面
		TASK_SELECT_CHARACTER=						6,			// 选择主角界面
		TASK_SELECT_CHARACTER_IN=					7,			// 选择主角界面
		TASK_CREATE_CHARACTER=						8,			// 创建主角界面
		TASK_WORK_TEAM=								9,			// 工作人员名单
		TASK_GAME_LOGIN=							10,			// 游戏主登陆
// ---------
		TASK_CHANGE_SCENE=							99,
		TASK_GAME_MAIN=								100,		// 进入游戏

		TASK_SYSTEM_QUIT=							9999		// 结束系统
};

/*******************************************************************************************************************}
{																													}
{		Define 程序执行回传值																						}
{																													}
********************************************************************************************************************/
enum	SYSTEM_MAIN_TASK_RETURN_CODE
{
		RETURN_ERROR=								-1,			// 执行工作错误  (相当于 TTN_ERROR )
		RETURN_CANCEL=								-2,			// 执行工作取消  (相当于 TTN_NOT_OK )
		RETURN_OK=									0,			// 执行工作完成  (相当于 TTN_OK )
		RETURN_CHANGE_TASK=							1000		// 更换 task
};


/*******************************************************************************************************************}
{																													}
{		Define 天气 control code																					}
{																													}
********************************************************************************************************************/
enum	WEATHER_CONTROL_CODE
{
		WEATHER_TYPE_NONE=		0x00000000,			// 晴天
		WEATHER_TYPE_RAIN=		0x00000001,			// 下雨
		WEATHER_TYPE_SNOW=		0x00000002,			// 下雪
		WEATHER_TYPE_CLOUD=		0x00000004, 		// 雾或云
		WEATHER_TYPE_THUNDER=	0x00000008, 		// 打雷
			
		WEATHER_RANGE_SMALL=	0x00000000,			// 小 云的情况   灰云
		WEATHER_RANGE_MIDDLE=	0x01000000,			// 中			   黑云
		WEATHER_RANGE_LARGE=	0x02000000			// 大			   白云
};


/*******************************************************************************************************************}
{																													}
{		Define chat control code																					}
{																													}
********************************************************************************************************************/
enum	CHAT_CHANNEL_CODE
{
		CHAT_CHANNEL_SCREEN=			0,			// 当前频道
		CHAT_CHANNEL_TEAM=				1,			// 队伍
		CHAT_CHANNEL_PERSON=			2,			// 私聊
		CHAT_CHANNEL_GROUP=				3,			// 公会
		CHAT_CHANNEL_SELLBUY=			4,			// 经济
		CHAT_CHANNEL_WORLD=				5,			// 世界
		CHAT_CHANNEL_SYSTEM=			6,			// 系统说话
		CHAT_CHANNEL_MESSGAE=			7,			// 随机讯息
		CHAT_CHANNEL_FRIEND=			8,			// 好友频道
		CHAT_CHANNEL_NONE=				99
};


#define CHAT_CHANNEL_SCREEN_TIMER		1000*2			// 当前频道
#define CHAT_CHANNEL_TEAM_TIMER			1000*2			// 队伍
#define CHAT_CHANNEL_PERSON_TIMER		1000*2			// 私聊
#define CHAT_CHANNEL_GROUP_TIMER		1000*3			// 公会
#define CHAT_CHANNEL_SELLBUY_TIMER		1000*5			// 经济
#define CHAT_CHANNEL_WORLD_TIMER		1000*5			// 世界



#define CHARACTER_SEX_MAN							0			// 男性
#define CHARACTER_SEX_WOMEN							1			// 女性

#define CHARACTER_PHYLE_HUMAN						0			// 人类
#define CHARACTER_PHYLE_GENUS						1			// 精灵
#define CHARACTER_PHYLE_MAGIC						2			// 法师
#define CHARACTER_PHYLE_ROBOT						3			// 机械


#define CHARACTER_BASE_TYPE_HUMAN_MAN				CHARACTER_PHYLE_HUMAN*2+CHARACTER_SEX_MAN
#define CHARACTER_BASE_TYPE_HUMAN_WOMAN				CHARACTER_PHYLE_HUMAN*2+CHARACTER_SEX_WOMEN
#define CHARACTER_BASE_TYPE_GENUS_MAN				CHARACTER_PHYLE_GENUS*2+CHARACTER_SEX_MAN
#define CHARACTER_BASE_TYPE_GENUS_WOMAN				CHARACTER_PHYLE_GENUS*2+CHARACTER_SEX_WOMEN
#define CHARACTER_BASE_TYPE_MAGIC_MAN				CHARACTER_PHYLE_MAGIC*2+CHARACTER_SEX_MAN
#define CHARACTER_BASE_TYPE_MAGIC_WOMAN				CHARACTER_PHYLE_MAGIC*2+CHARACTER_SEX_WOMEN
#define CHARACTER_BASE_TYPE_ROBOT_MAN				CHARACTER_PHYLE_ROBOT*2+CHARACTER_SEX_MAN
#define CHARACTER_BASE_TYPE_ROBOT_WOMAN				CHARACTER_PHYLE_ROBOT*2+CHARACTER_SEX_WOMEN


#define BAOBAO_PHYLE_HUMAN							5			// 人形系
#define BAOBAO_PHYLE_FLY							2			// 飞行系
#define BAOBAO_PHYLE_DEVIL							1			// 恶魔系
#define BAOBAO_PHYLE_DEAD							4			// 不死系
#define BAOBAO_PHYLE_DRAGON							6			// 龙系
#define BAOBAO_PHYLE_SPECIAL						3			// 特殊系


// ---------- Define NPC CONTROL command
// -------- 地图NPC 动作方式
#define NPC_MOTION_STANDBY1				0
#define NPC_MOTION_STANDBY2				1
#define NPC_MOTION_WALK					2
#define NPC_MOTION_RUN					3				// CPU NPC 没有跑步

#define NPC_MOVE_HOLD					0				// 不移动
#define NPC_MOVE_PATH					1				// 循径移动
#define NPC_MOVE_AUTO					2				// 在格子(编辑器设定)里面移动
#define NPC_MOVE_FOLLOW					3				// 跟随移动(只适合宝宝)

#define NPC_DIR_UP						0
#define NPC_DIR_DOWN					1
#define NPC_DIR_LEFT					2
#define NPC_DIR_RIGHT					3
#define NPC_DIR_UP_RIGHT				4
#define NPC_DIR_DOWN_LEFT				5
#define NPC_DIR_UP_LEFT					6
#define NPC_DIR_DOWN_RIGHT				7

#define MAX_NPC_DIR						8




// --------- Define Chat Control code 
#define MAX_CHAT_LENGTH					160
#define MAX_CHAT_RECORD					1024
#define MAX_FRIEND_DATA_RECORD			512				

#define SCREEN_TEXT_TIMER				1000*8			// 8 秒
#define SCREEN_TEXT_WINDOW_WIDTH		12*8			// 6个1中文字




/*******************************************************************************************************************}
{																													}
{		Define 好友关系																								}
{																													}
********************************************************************************************************************/
enum
{
	NEXUS_FRIEND=						0,				// 一般朋友关系
	NEXUS_MARRIAGE=						1,				// 婚姻
	NEXUS_BROTHER=						2,				// 结拜
	NEXUS_MASTER=						3				// 师徒
};









typedef struct CHAT_RECORD_STRUCT
{
	ULONG user_id;										// 说话人的 ID  当最高位为1的时候为系统说话,不显示
	ULONG channel;										// chat 频道
	UCHR nickname[MAX_NAME_LENGTH+1];					// nicknane
	UCHR text[MAX_CHAT_LENGTH];							// 文字内容
	
} CHAT_RECORD;


typedef struct CHAT_RECEIVE_DATA_STRUCT
{
	ULONG user_id;										// 说话人的 ID  当最高位为1的时候为系统说话,不显示
	ULONG channel;										// chat 频道
	UCHR nickname[MAX_NAME_LENGTH+1];					// nicknane
	UCHR text[MAX_CHAT_LENGTH];							// 文字内容
	UCHR time[80];										// 时间
} CHAT_RECEIVE_DATA;


typedef struct CHAT_DATA_BUFFER_STRUCT
{
	SLONG top_index;									// 接受 point
	SLONG bottom_index;									// 底层 point
	SLONG colume;										// 显示行数
	SLONG display_index;								// 显示 point
	CHAT_RECORD record[MAX_CHAT_RECORD];				// 聊天资料
} CHAT_DATA_BUFFER;



#define FRIEND_NORMAL				0					// 一般好友
#define FRIEND_TEMP					1					// 临时好友
#define FRIEND_MASK					2					// 黑名单

typedef struct CHAT_FRIEND_LIST_STRUCT
{
	char online;										// 是否在线
	ULONG id;
	char friend_type;									// 好友种类 ( 0 -> 一般, 1 ->  临时好友  2 -> 黑名单)
	UCHR nickname[MAX_NAME_LENGTH+1];					// nicknane
	UCHR title[MAX_TITLE_LENGTH+1];						// 称谓
	SLONG level;										// 等级
	SLONG base_type;									// 基本形态
	UCHR group[MAX_GROUP_NAME_LENGTH+1];				// 公会
	SLONG nexus;										// 关系
	ULONG amity;										// 友好度
	
} CHAT_FRIEND_LIST;



typedef struct CLIENT_CONFIG_STRUCT
{
	char fight_flag;			// 切磋开关 ( 0 -> 关闭, 1 -> 切磋打开 )
	char mail_flag;				// 信件接受 ( 0 -> 关闭, 1 -> 信件接受打开 )
	char item_flag;				// 物品接受 ( 0 -> 关闭, 1 -> 物品接受打开 )
	char friend_flag;			// 好友开关 ( 0 -> 关闭, 1 -> 加入好友打开 )
	char team_flag;				// 组队开关 ( 0 -> 关闭, 1 -> 允许组队加入 )
	char strange_flag;			// 陌生人开关 ( 0 -> 关闭, 1 -> 拒绝陌生人消息 )

	char channel_screen_flag;	// 当前频道开关
	char channel_team_flag;		// 队伍频道开关
	char channel_person_flag;	// 私聊频道开关
	char channel_group_flag;	// 工会频道开关
	char channel_sellbuy_flag;	// 经济频道开关
	char channel_world_flag;	// 世界频道开关
	
	
} CLIENT_CONFIG;


#define MAX_MISSION				20
#define MAX_MISSION_TEXT_LEN	120

typedef struct MISSION_DATA_STRUCT
{
	SLONG mission_id;
	UCHR text[MAX_MISSION_TEXT_LEN+2];

} MISSION_DATA;







/*******************************************************************************************************************}
{																													}
{																													}
{																													}
{	SERVER  数 值 部 分																								}
{																													}
{																													}
{																													}
********************************************************************************************************************/
/*******************************************************************************************************************}
{																													}
{	公 用 数 值 部 分																								}
{																													}
********************************************************************************************************************/
enum	ITEM_TYPE_CODE 	// 装备种类 ( 根据选单功能分类 )
{
		ITEM_TYPE_EQUIP=								0,			// 武器装备 (可以装备在身上的)
		ITEM_TYPE_DRUP=									1,			// 药品
		ITEM_TYPE_ITEM=									2,			// 道具
		ITEM_TYPE_SOURCE=								3,			// 原料
		ITEM_TYPE_SPECIAL=								4			// 特殊物品 ( 程序用的,例如传送旗子,经验丹,点卡...)
};

enum	ITEM_STORE_CODE	// 存放需求
{																	// 所有东西都可以放在身上，所以不定义口袋类型
		ITEM_STORE_POPSHOP=								0x01,		// 可以存放当铺
		ITEM_STORE_STAFF=								0x02,		// 可以存放佣人
		ITEM_STORE_NPC=									0x04,		// 可以存放 Macro NPC
		ITEM_STORE_GIVE=								0x08,		// 可以给与
		ITEM_STORE_DEAL=								0x10		// 可以交易
};


enum	ITEM_USE_CODE	// 使用需求
{
		ITEM_USE_NONE=									0x00,		// 没有指定
		ITEM_USE_MAP=									0x01,		// 地图使用 ( 只能在地图使用,没有指定就是都可以,战斗也OK )
		ITEM_USE_FIGHT=									0x02,		// 战斗使用
		ITEM_USE_MACRO=									0x04,		// Macro 物品, 只能对Macro npc 使用,就是任务物品

};

enum	ITEM_POSITION_CODE	// 使用部位
{
		ITEM_POSITION_NONE=								0,			// 没用指定 ( 直接使用 )
		ITEM_POSITION_HAND=								0x01,		// 手部 or 打在武器
		ITEM_POSITION_HEAD=								0x02,		// 头部 or 打在帽子
		ITEM_POSITION_BODY=								0x04,		// 身体 or 打在衣服
		ITEM_POSITION_FOOT=								0x08,		// 脚部 or 打在鞋子
		ITEM_POSITION_FINGER=							0x10,		// 手指 
		ITEM_POSITION_WRIST=							0x20,		// 手腕 or 打在手镯 ( 魔法石头 )
		ITEM_POSITION_RING=								0x40,		// 项链 or 打在手镯 ( 魔法石头 )
		
};


enum	ITEM_PHYLE_CODE	// 使用种族
{
		ITEM_PHYLE_HUMAN_MAN=							0x01,		// 男人
		ITEM_PHYLE_HUMAN_WOMAN=							0x02,		// 女人
		ITEM_PHYLE_GENUS_MAN=							0x04,		// 男灵兽
		ITEM_PHYLE_GENUS_WOMAN=							0x08,		// 女灵兽
		ITEM_PHYLE_MAGIC_MAN=							0x10,		// 男法师
		ITEM_PHYLE_MAGIC_WOMAN=							0x20,		// 女法师
		ITEM_PHYLE_ROBOT_MAN=							0x40,		// 男机甲
		ITEM_PHYLE_ROBOT_WOMAN=							0x80,		// 女机甲
		ITEM_PHYLE_NONE=								0xff		// 没有指定(全部可以使用)
};


enum	ITEM_LIMIT_CODE	// 使用限制
{
		ITEM_LIMIT_NONE=								0,			// 没有限制
		ITEM_LIMIT_LEVEL=								0x01000000,	// 等级限制 ( 后面接 等级资料 )
		ITEM_LIMIT_HP=									0x02000000,	// 血量限制 ( 后面接 血点数资料 )
		ITEM_LIMIT_MP=									0x04000000,	// 法量限制 ( 后面接 法点数资料 )
		ITEM_LIMIT_ATT=									0x08000000,	// 力量限制 ( 后面接 力量点数资料 )
		ITEM_LIMIT_SP=									0x10000000,	// 速度限制 ( 后面接 速度点数资料 )
		ITEM_LIMIT_CREDIT=								0x20000000	// 声望限制 ( 后面接 声望资料 )
};


enum	ITEM_SPECIAL_CODE	// 特殊资料
{
		ITEM_SPECIAL_NONE=								0,			// 没有限制处理
		ITEM_SPECIAL_SERVICE=							0x10000,	// 具备耐久 ( 后面接 耐久数值 ) 被攻击10次-1 ,存放次数*10, show 的时候/10
		ITEM_SPECIAL_MAGIC=								0x20000,	// 具备灵力 ( 后面接 灵力数值 ) 每一场战斗 -1
		ITEM_SPECIAL_USE=								0x40000		// 具备法力 ( 后面接 法力数值 ) 使用一次 -1
};


enum	ITEM_EFFECT_CODE	// 效果种类
{
		ITEM_EFFECT_NONE=								0,			// 没有效果
		ITEM_EFFECT_HP=									1,			// 加血 ( 直接数值 )
		ITEM_EFFECT_HP_PERCENT=							2,			// 加血 ( 百分比 )
		ITEM_EFFECT_MP=									3,			// 加法 ( 直接数值 )
		ITEM_EFFECT_MP_PERCENT=							4,			// 加法 ( 百分比 )
		ITEM_EFFECT_HPMP=								5,			// 加血法 ( 直接数值 )
		ITEM_EFFECT_HPMP_PERCENT=						6,			// 加血法 ( 百分比 )
		ITEM_EFFECT_SPECIFY=							7,			// 程序指定 ( 不同种族,不同方法 )

		ITEM_EFFECT_MAX_HP=								8,			// 最大血
		ITEM_EFFECT_MAX_MP=								9,			// 最大法
		ITEM_EFFECT_ATT=								10,			// 攻击力
		ITEM_EFFECT_SPEED=								11,			// 速度
		ITEM_EFFECT_PROTECT=							12,			// 防御力

// ----
		ITEM_EFFECT_SHOOT=								100,		// 命中率
		ITEM_EFFECT_DODGE=								101,		// 躲避率
		ITEM_EFFECT_SUCK=								102,		// 抗吸
		ITEM_EFFECT_CREZY_PERCENT=						103,		// 狂暴几率
		ITEM_EFFECT_CRAZY_VALUE=						104,		// 狂暴效果
		ITEM_EFFECT_DEADLINESS_PERCENT=					105,		// 致命几率
		ITEM_EFFECT_DEADLINESS_VALUE=					106,		// 致命效果
		ITEM_EFFECT_REDEADLINESS=						107,		// 抗致命几率
		ITEM_EFFECT_DOUBLEATT_PERCENT=					108,		// 连击几率
		ITEM_EFFECT_DOUBLEATT_VALUE=					109,		// 连击次数
		ITEM_EFFECT_BACKATT_PERCENT=					110,		// 反击几率
		ITEM_EFFECT_BACKATT_VALUE=						111,		// 反击次数
		ITEM_EFFECT_BREAK_PHYSICS_PERCENT=				112,		// 破物理几率
		ITEM_EFFECT_BREAK_PHYSICS_VALUE=				113,		// 破物理程度
		ITEM_EFFECT_MAGIC_FEEDBACK_PERCENT=				114,		// 法术反馈几率
		ITEM_EFFECT_MAGIC_FEEDBACK_VALUE=				115,		// 法术反馈程度
		ITEM_EFFECT_PHYSICS_FEEDBACK_PERCENT=			116,		// 物理反馈几率
		ITEM_EFFECT_PHYSICS_FEEDBACK_VALUE=				117,		// 物理反馈程度
		ITEM_EFFECT_DEAD_PERCENT=						118,		// 抗死亡宣告几率
		ITEM_EFFECT_MAGIC_DARK=							119,		// 抗暗法术程度
		ITEM_EFFECT_MAGIC_LIGHT=						120,		// 抗光法术程度
		ITEM_EFFECT_MAGIC_WATER=						121,		// 抗水法术程度
		ITEM_EFFECT_MAGIC_FIRE=							122,		// 抗火法术程度
		ITEM_EFFECT_PHYSICS=							123,		// 抗物理程度
		ITEM_EFFECT_VIRUS=								124,		// 抗中毒程度
		ITEM_EFFECT_CHAOS=								125,		// 抗混乱程度
		ITEM_EFFECT_STONE=								126,		// 抗石化程度
		ITEM_EFFECT_SLEEP=								127,		// 抗昏睡程度
		ITEM_EFFECT_WEEK=								128,		// 抗衰老程度

// ----	
		ITEM_EFFECT_PLAYER_EXP=							200,		// player 经验
		ITEM_EFFECT_PLAYER_MAGIC=						201,		// 法术熟练
		ITEM_EFFECT_PLAYER_HP_POINT=					202,		// 玩家血点数
		ITEM_EFFECT_PLAYER_MP_POINT=					203,		// 玩家法点数
		ITEM_EFFECT_PLAYER_ATT_POINT=					204,		// 玩家力量点数
		ITEM_EFFECT_PLAYER_SP_POINT=					205,		// 玩家速度点数
		
// ----
		ITEM_EFFECT_BAOBAO_EXP=							300,		// 宝宝经验
		ITEM_EFFECT_BAOBAO_LOYALITY=					301,		// 忠诚度
		ITEM_EFFECT_BAOBAO_CLOSED=						302,		// 亲密度
		ITEM_EFFECT_BAOBAO_HP_POINT=					303,		// 宝宝血点数
		ITEM_EFFECT_BAOBAO_MP_POINT=					304,		// 宝宝法点数
		ITEM_EFFECT_BAOBAO_ATT_POINT=					305,		// 宝宝力量点数
		ITEM_EFFECT_BAOBAO_SP_POINT=					306,		// 宝宝速度点数
		ITEM_EFFECT_BAOBAO_GROW=						307,		// 宝宝成长系数

// ---- 
		ITEM_EFFECT_SERVICE=							400,		// 耐久
		ITEM_EFFECT_MAGIC=								401,		// 灵力
		ITEM_EFFECT_USE=								402			// 法力

};



enum	SKILL_EFFECT_CODE	// 法术种类
{
// --- skill for 人类
		SKILL_EFFECT_STONE_MAGIC=						0,			// 石化法术
		SKILL_EFFECT_CHAOS_MAGIC=						1,			// 混乱
		SKILL_EFFECT_SLEEP_MAGIC=						2,			// 昏睡
		SKILL_EFFECT_VIRUS_MAGIC=						3,			// 中毒
		SKILL_EFFECT_WEEK_MAGIC=						4,			// 衰老
	
// --- skill for 精灵
		SKILL_EFFECT_ATTACK_MAGIC=						10,			// 加攻击
		SKILL_EFFECT_FASTNESS_MAGIC=					11,			// 加抗性
		SKILL_EFFECT_MULTY_MAGIC=						12,			// 多物理攻击
		SKILL_EFFECT_SPEED_MAGIC=						13,			// 加速
		SKILL_EFFECT_RESCUE_MAGIC=						14,			// 恢复

// --- skill for 法师
		SKILL_EFFECT_DARK_MAGIC=						20,			// 黑暗系攻击法术
		SKILL_EFFECT_LIGHT_MAGIC=						21,			// 光明系攻击法术
		SKILL_EFFECT_WATER_MAGIC=						22,			// 水系攻击法术
		SKILL_EFFECT_FIRE_MAGIC=						23,			// 火系攻击法术
		SKILL_EFFECT_DEAD_MAGIC=						24,			// 死亡宣告

// --- skill for 机械
		SKILL_EFFECT_SUCK_MAGIC=						30,			// 吸
		SKILL_EFFECT_PHYSICS_FEEDBACK_MAGIC=			31,			// 物理回馈
		SKILL_EFFECT_MAGIC_FEEDBACK_MAGIC=				32,			// 法术回馈
		SKILL_EFFECT_LOCK_MAGIC=						33,			// 锁定
		SKILL_EFFECT_BREAK_MAGIC=						34			// 解除异常状态
		
};


enum	TITLE_TYPE_CODE	// 头衔种类
{
		TITLE_TYPE_NONE=								0,			// 没有意思
		TITLE_TYPE_MACRO=								1,			// 剧情头衔
		TITLE_TYPE_GROUP=								2,			// 工会头衔
		TITLE_TYPE_MARRAGE=								3,			// 婚姻头衔
		TITLE_TYPE_GAME=								4,			// 竞赛头衔
		TITLE_TYPE_HOLD=								5			// 保留头衔

};



enum	ITEM_INST_CODE
{
		ITEM_INST_POCKET=								0,			// 玩家口袋
		ITEM_INST_DEAL_OTHER_ITEM=						1,			// 交易时候我方宝宝列表
		ITEM_INST_DEAL_OTHER_BAOBAO=					2,			// 交易时候对方宝宝列表
		ITEM_INST_POPSHOP=								3,			// 当铺
		ITEM_INST_SELL_STORE=							4,			// 卖东西的商店
		ITEM_INST_EQUIP=								5,			// 装备 
		ITEM_INST_MY_BAOBAO=							6,			// 自己的宝宝(服务器不用处理)
		ITEM_INST_SKILL=								7,			// 技能说明

		ITEM_INST_HOUSEKEEPER=							10			// 管家 
		
};



/*******************************************************************************************************************}
{	抗性基本数值																									}
********************************************************************************************************************/
typedef struct PUBLIC_FASTNESS_DATA_STRUCT			// 抗性资料
{
	SHINT protect;									// 防御力
	SHINT shoot;									// 命中率
	SHINT dodge;									// 躲避率
	SHINT suck;										// 抗吸
	SHINT crazy_percent;							// 狂暴几率
	SHINT crazy_value;								// 狂暴效果
	SHINT deadliness_percent;						// 致命几率
	SHINT deadliness_value;							// 致命效果
	SHINT redeadliness_percent;						// 抗致命几率
	SHINT doubleatt_percent;						// 连击几率
	SHINT doubleatt_times;							// 连击次数
	SHINT backatt_percent;							// 反击几率
	SHINT backatt_times;							// 反击次数
	SHINT break_physics_percent;					// 破物理几率
	SHINT break_physics_value;						// 破物理程度
	SHINT magic_feedback_percent;					// 法术反馈几率
	SHINT magic_feedback_value;						// 法术反馈程度
	SHINT physics_feedback_percent;					// 物理反馈几率
	SHINT physics_feedback_value;					// 物理反馈程度
	SHINT dead_percent;								// 抗死亡宣告几率
	SHINT magic_dark;								// 抗暗法术程度
	SHINT magic_light;								// 抗光法术程度
	SHINT magic_water;								// 抗水法术程度
	SHINT magic_fire;								// 抗火法术程度
	SHINT physics;									// 抗物理程度
	SHINT virus;									// 抗中毒程度
	SHINT chaos;									// 抗混乱程度
	SHINT stone;									// 抗石化程度
	SHINT sleep;									// 抗昏睡程度
	SHINT week;										// 抗衰老程度

} PUBLIC_FASTNESS_DATA;



/*******************************************************************************************************************}
{	物品道具装备基本数值																							}
********************************************************************************************************************/
// --- 当需要单独查询的时候
typedef struct PUBLIC_ITEM_BASE_STRUCT				// 道具物品基本资料
{
	// ---- 基本资料	
	UCHR name[MAX_ITEM_NAME_LENGTH+1];				// 名称
	UCHR inst[MAX_ITEM_INST_LENGTH+1];				// 物品描述
	SHINT item_type;								// 物品类型 ( see ITEM_TYPE enum  )
	SHINT level;									// 物品等级
	SHINT priority;									// 优先顺序 ( 数字越小越优先使用)
	
	// ---- 存放需求
	SHINT store_type;								// 存放需求 ( see ITEM_STORE enum )

	
	// ---- 使用需求
	SHINT use_type;									// 使用需求 ( see ITEM_USE enum )
	SHINT use_position;								// 使用部位 ( see ITEM_POSITION enum )
	SHINT use_phyle;								// 使用种族类别 ( see ITEM_PHYLE enum )

	ULONG use_limit;								// 使用限制 ( see ITEM_LIMIT enum )
	ULONG use_special;								// 特殊资料 ( see ITEM_SPECIAL enum )
	
	// ---- 效果部分
	SHINT effect_type[3];							// 效果种类 ( see ITEM_EFFECT enum ) 基本效果0+特殊效果1..3
	SLONG effect_value[3];							// 效果数值

	SHINT effect_stone_type[3];						// 石头效果种类 ( see ITEM_EFFECT enum ) 基本效果0+特殊效果1..3
	SLONG effect_stone_value[3];					// 石头效果数值
	
} PUBLIC_ITEM_BASE;

// ----- 第一部分,口袋直接 update ----------
typedef struct PUBLIC_ITEM_DATA_STRUCT				// 物品道具资料
{
	SLONG item_id;									// < 0 代表没有资料 >= 0 代表资料
	SHINT number;									// 物品数量
// ---- 公用部分
	SHINT filename_id;								// 物品使用 MDA 档案 id
	SHINT single_price;								// 物品单价
	
} PUBLIC_ITEM_DATA;




/*******************************************************************************************************************}
{	技能基本数值																									}
********************************************************************************************************************/
typedef struct PUBLIC_SKILL_DATA_STRUCT				// 技能资料
{
	char idx;										// 法术 idx
	char level;										// 法术等级
	SHINT lithhand;									// 熟练度
	char action;									// 作用对象
	SHINT need_mp;									// 所需要MP
} PUBLIC_SKILL_DATA;





/*******************************************************************************************************************}
{	头衔基本数值																									}
********************************************************************************************************************/
typedef struct PUBLIC_TITLE_BASE_STRUCT				// 头衔基本资料
{
	UCHR name[MAX_TITLE_LENGTH+1];					// 名称
	UCHR inst[MAX_TITLE_INST_LENGTH+1];				// 描述
	SHINT type;										// 控制码 --> Macro 或者特殊检查用 ( see TITLE_TYPE snum )

} PUBLIC_TITLE_BASE;


typedef struct PUBLIC_TITLE_DATA_STRUCT				// 头衔资料
{
	PUBLIC_TITLE_BASE data;
} PUBLIC_TITLE_DATA;



typedef struct PUBLIC_GROUP_DATA_STRUCT				// 工会资料
{

} PUBLIC_GROUP_DATA;



/*******************************************************************************************************************}
{	人 物 数 值 部 分																								}
********************************************************************************************************************/
/*******************************************************************************************************************}
{	人物最终数值																									}
********************************************************************************************************************/
typedef struct SERVER_CHARACTER_FINAL_STRUCT		// 
{
	ULONG level;									// 等级
	SLONG max_hp;									// 最大 HP
	SLONG now_hp;									// 当前 HP
	SLONG max_mp;									// 最大 MP
	SLONG now_mp;									// 当前 MP
	SLONG att;										// 当前攻击力
	SLONG speed;									// 当前速度
	unsigned long total_exp;						// 目前总经验
	unsigned long now_exp;							// 当前经验
	unsigned long need_exp;							// 升级经验

	SLONG filename_id;								// 目前 filename id (可能变身)
	
} SERVER_CHARACTER_FINAL;

/*******************************************************************************************************************}
{	人物基本数值																									}
********************************************************************************************************************/
typedef struct SERVER_CHARACTER_BASE_STRUCT			// 
{
	SHINT point;									// 目前可以分配点数

	SLONG base_hp;									// 基本 HP
	SHINT hp_point;									// HP 点数
	float hp_grow;									// HP 成长系数

	SLONG base_mp;									// 基本 MP
	SHINT mp_point;									// MP 点数
	float mp_grow;									// MP 成长系数

	SLONG base_att;									// 基本 ATT
	SHINT att_point;								// ATT 点数
	float att_grow;									// ATT 成长系数

	SLONG base_speed;								// 基本 SPEED
	SHINT speed_point;								// SPEED 点数
	float speed_grow;								// SPEED 成长系数

	SLONG filename_id;								// 出生时的 MDA filename_id;
	SHINT base_point;								// 节庆送点
	char life_base;									// 目前几转

} SERVER_CHATACTER_BASE;


/*******************************************************************************************************************}
{	人物抗性数值																									}
********************************************************************************************************************/
typedef struct SERVER_CHARACTER_FASTNESS_STRUCT		// 
{
	bool active;									// 资料 ready 
	PUBLIC_FASTNESS_DATA fastness;					// 抗性资料
} SERVER_CHARACTER_FASTNESS;


/*******************************************************************************************************************}
{	人物口袋资料																									}
********************************************************************************************************************/
typedef struct SERVER_CHARACTER_POCKET_STRUCT		// 
{
	bool active;									// 资料 ready 
	SLONG idx;										// 目前口袋 idx
// --- 卖物品
	SLONG sell_number;								// 卖的数量
// --- give
	SLONG give_idx[3];								// 给与 idx
	SLONG give_number[3];							// 给与数量
	SLONG give_money;								// 给与金钱
// --- deal
// 我方资料
	bool my_deal_ready;								// 资料 ok
	SLONG my_deal_idx[3];							// 交易 idx
	SLONG my_deal_number[3];						// 交易数量
	SLONG my_deal_money;							// 交易金钱
// 对方资料
	bool other_deal_ready;							// 资料 ok
	SLONG other_deal_filename_id[3];				// 对方物品 filename_id
	SLONG other_deal_number[3];						// 交易数量
	SLONG other_deal_money;							// 交易金钱


// --- body 	
	PUBLIC_ITEM_DATA item[MAX_POCKET_ITEM];			// 道具资料
} SERVER_CHARACTER_POCKER;


/*******************************************************************************************************************}
{	人物装备资料																									}
********************************************************************************************************************/
typedef struct SERVER_CHARACTER_EQUIP_STRUCT		// 
{
	bool active;									// 资料 ready 
	SLONG idx;										// 口袋 idx
	PUBLIC_ITEM_DATA equip[MAX_EQUIP_ITEM];			// 武器装备资料
} SERVER_CHARACTER_EQUIP;


/*******************************************************************************************************************}
{	人物当铺资料																									}
********************************************************************************************************************/
typedef struct SERVER_CHARACTER_POPSHOP_STRUCT		// 
{
	bool active;									// 资料 ready 
	SLONG idx;										// 目前 当铺 idx
	SLONG sell_number;
	PUBLIC_ITEM_DATA item[MAX_POPSHOP_ITEM];		// 当铺资料
} SERVER_CHARACTER_POPSHOP;


/*******************************************************************************************************************}
{	人物银行资料																									}
********************************************************************************************************************/
typedef struct SERVER_CHARACTER_BANK_STRUCT			// 
{
	bool active;									// 资料 ready 
	SLONG now_money;								// 口袋金钱数量
	SLONG bank_money;								// 存款数量
	SLONG max_money;								// 金钱上限
} SERVER_CHARACTER_BANK;


/*******************************************************************************************************************}
{	人物其他资料																									}
********************************************************************************************************************/
typedef struct SERVER_CHARACTER_OTHER_STRUCT		// 
{
	SLONG credit;									// 声望
	SLONG dead_count;								// 死亡次数
	SLONG kind;										// 善恶
	SLONG military;									// 战绩
	SLONG group_id;									// 加入工会 id
	
} SERVER_CHARACTER_OTHER;


/*******************************************************************************************************************}
{	人物商店资料																									}
********************************************************************************************************************/
typedef struct SERVER_STORE_DATA_STRUCT
{ 
	bool active;
	SLONG idx;
	SLONG buy_number;
	SLONG total;
	PUBLIC_ITEM_DATA item[MAX_POCKET_ITEM];			// 道具资料, 里面的 number -> 当作单价
} SERVER_STORE_DATA;



/*******************************************************************************************************************}
{	物品说明资料																									}
********************************************************************************************************************/
typedef struct CLIENT_ITEM_INST_STRUCT
{
	bool active;									// 资料是否 ready 
	char type;										// 资料种类 see enum ( ITEM_INST_CODE )
	char idx;										// 口袋编号
	char old_idx;
	char inst[MAX_DETAIL_INST_LENGTH];				// 说明资料
	ULONG timer;									// request timer;
	SLONG handle;									// mda handle
} CLIENT_ITEM_INST;


/*******************************************************************************************************************}
{	宝 宝 数 值 部 分																								}
********************************************************************************************************************/
/*******************************************************************************************************************}
{	宝宝最终数值																									}
********************************************************************************************************************/
typedef struct SERVER_BAOBAO_FINAL_STRUCT		// 
{
	ULONG level;									// 等级
	ULONG max_hp;									// 最大 HP
	ULONG now_hp;									// 当前 HP
	ULONG max_mp;									// 最大 MP
	ULONG now_mp;									// 当前 MP
	ULONG att;										// 当前攻击力
	ULONG speed;									// 当前速度
	unsigned long total_exp;						// 目前总经验
	unsigned long now_exp;							// 当前经验
	unsigned long need_exp;							// 升级经验
	
} SERVER_BAOBAO_FINAL;


/*******************************************************************************************************************}
{	宝宝基本数值																									}
********************************************************************************************************************/
typedef struct SERVER_BAOBAO_BASE_STRUCT			// 
{
	SLONG point;									// 目前可以分配点数

	SLONG base_hp;									// 基本 HP
	SHINT hp_point;									// HP 点数

	SLONG base_mp;									// 基本 MP
	SHINT mp_point;									// MP 点数

	SLONG base_att;									// 基本 ATT
	SHINT att_point;								// ATT 点数

	SLONG base_speed;								// 基本 SPEED
	SHINT speed_point;								// SPEED 点数

	float grow;										// 成长系数
	SHINT phyle;									// 系别
	SHINT filename_id;
	char life_base;									// 目前几转
		
} SERVER_BAOBAO_BASE;


/*******************************************************************************************************************}
{	宝宝抗性数值																									}
********************************************************************************************************************/
typedef struct SERVER_BAOBAO_FASTNESS_STRUCT		// 
{
	bool active;									// 资料 ready 
	PUBLIC_FASTNESS_DATA fastness;					// 抗性资料
} SERVER_BAOBAO_FASTNESS;



/*******************************************************************************************************************}
{	人物所带宝宝资料																								}
********************************************************************************************************************/
typedef struct SERVER_CHARACTER_BAOBAO_STRUCT
{
	ULONG baobao_id;								// 宝宝 ID ( 0 代表没有资料 )
	char name[MAX_BAOBAO_NAME_LENGTH+1];			// 名称(玩家自定义名字)
	SHINT loyalty;									// 忠诚
	SLONG closed;									// 亲密度
	SERVER_BAOBAO_FINAL data;						// 宝宝数值
	SERVER_BAOBAO_BASE base;						// 所带宝宝基本资料

} SERVER_CHARACTER_BAOBAO;


typedef struct SERVER_CHARACTER_BAOBAO_STACK_STRUCT
{
	ULONG action_baobao_id;									// 目前所带宝宝的 ID
	SHINT active_idx;										// 目前所带宝宝 idx
	bool show[MAX_BAOBAO_STACK];							// 宝宝是否显示
	SERVER_CHARACTER_BAOBAO baobao_list[MAX_BAOBAO_STACK];	// 所带的宝宝资料

} SERVER_CHARACTER_BAOBAO_STACK;









/*******************************************************************************************************************}
{																													}
{																													}
{																													}
{	Client 数 值 部 分																								}
{																													}
{																													}
{																													}
********************************************************************************************************************/
/*******************************************************************************************************************}
{																													}
{	人 物 数 值 部 分																								}
{																													}
********************************************************************************************************************/
typedef struct CLIENT_CHARACTER_MAP_WINDOW_STRUCT	// 地图模式 window 要用的资料
{
	char group[MAX_GROUP_NAME_LENGTH+1];			// 工会名称
	SERVER_CHARACTER_FINAL final;					// 人物 final 资料	
	SERVER_CHATACTER_BASE base;						// 人物基本资料
	SERVER_CHARACTER_OTHER other;					// 人物其他资料
	
} CLIENT_CHARACTER_MAP_WINDOW;



typedef struct CLIENT_CHARACTER_POINT_BACK_STRUCT
{
	SHINT total_point;
	SHINT hp_point;
	SHINT mp_point;
	SHINT att_point;
	SHINT speed_point;

} CLIENT_CHARACTER_POINT_BACK;


typedef struct CLIENT_UPDATE_EXP_STRUCT
{
	unsigned long total_exp;						// 目前总经验
	unsigned long now_exp;							// 当前经验
	unsigned long need_exp;							// 升级经验
	
} CLIENT_UPDATE_EXP;


typedef struct CLIENT_UPDATE_POINT_STRUCT
{
	SHINT point;									// 目前可以分配点数
	SHINT hp_point;									// HP 点数
	SHINT mp_point;									// MP 点数
	SHINT att_point;								// ATT 点数
	SHINT speed_point;								// SPEED 点数
	
} CLIENT_UPDATE_POINT;



/*******************************************************************************************************************}
{																													}
{	宝 宝 数 值 部 分																								}
{																													}
********************************************************************************************************************/

typedef struct CLIENT_BAOBAO_SHOW_STRUCT
{
	ULONG id;
	ULONG follow_id;								// 主人 id
	SHINT filename_id;								// 宝宝 filename id
	char life_base;									// 转生次数
	char name[MAX_BAOBAO_NAME_LENGTH+1];			// 名称(玩家自定义名字)
	
} CLIENT_BAOBAO_SHOW;










/*******************************************************************************************************************}
{																													}
{																													}
{																													}
{	战 斗 部 分																										}
{																													}
{																													}
{																													}
********************************************************************************************************************/
/* 动作说明如下:

	step 1: 进入战斗
		1-1. Server 通知进入战斗，呼叫 clear_fight_npc_group(), 传送 FIGHT_BASE_DATA ( 最多20个), 呼叫 insert_fight_unit();
					并且 fill 参战宝宝 skill,-> baobao_skill_data[];
		1-2. Server 通知进入战斗 呼叫 change_to_fight();  命令
		1-3. client show 第一回合下命令等待
		1-4. client 发送 FIGHT_READY
		1-5. server 通知充电开始 fight_charge_start();

	step 2: 每回合充电完成
		2-1. client 充电完成,发出 fight_command_data ,并且 client 停止充电
		
	step 3:	等待主机命令
		3.0 server 发送所有人充电暂停
		3.1 server 传送 FIGHT_STATUS_RESULT 更新目前战斗状态 update_fight_status_result();
		3.1 server 传送 FIGHT_ACTION_RESULT					 update_fight_action_result();
		3.2 server 传送 FIGHT_VALUE_RESULT					 update_fight_value_result();
		3.3 server 传送 ACTION 开始 ( 播放 client 战斗)
		3.4 client 传送播放完毕

	step 4: 全部人播放完毕,或者 client time out( 最快播放完毕+ 3 sec 为 time_out 时间)
		4-1. server 送出通知充电继续
		
	step 5: 战斗结束
		5-1. server 发送战斗结束
		5-2. 呼叫 change_to_map() 命令

	step 6: server 发送奖励
		6-1. server 发送经验或者其他奖励
		6-2. 结束战斗




 
// --------- 参数说明
   FIGHT_ACTION_RESULT
   FIGHT_VALUE_RESULT

  source_id= 发动人 ID,就不说明了


*****   基本攻击部分   ********
( 0 - 0 ) FIGHT_ACTION_SINGLE_PHYSICS				物理单攻击 ( 含 feedback,致命, 狂暴 )

	target_id= 被打的人 ID

	FIGHT_ACTION_SINGLE_PHYSICS_DATA
	{
		SLONG hp;										// 攻击血量
		SLONG feed_back_hp;								// 反馈血量
		ULONG protect_id;								// 保护 id, id= 0 没有人保护
		SLONG back_hp;									// 反击血量 > 0 的时候发生反击
	}


=============================================================================================
( 0 - 1 ) FIGHT_ACTION_SINGLE_PHYSICS_DOUBLE		物理连击 ( 含 feedback, 致命，狂暴 )

	target_id= 被打的人 ID
  
	FIGHT_ACTION_SINGLE_PHYSICS_DOUBLE_DATA
	{
		char double_count;								// 连击次数
		SLONG hp[MAX_PHYSICS_DOUBLE_TIMES];				// 每次血量
		SLONG feedback[MAX_PHYSICS_DOUBLE_TIMES];		// 每次反馈
		SLONG back_hp[MAX_PHYSICS_DOUBLE_TIMES];		// 反击血量
	}

=============================================================================================
( 0 - 3 ) FIGHT_ACTION_SINGLE_MAGIC				法术单攻击 ( 含 feedback, 狂暴 )

	target_id= 被打的人 ID
	idx= 法术 ID
	FIGHT_ACTION_SINGLE_MAGIC_DATA
	{
		SLONG hp;										// 法术攻击 HP
		SLONG feed_back_hp;								// 反馈血量
	}


=============================================================================================
( 0 - 4 ) FIGHT_ACTION_SINGLE_MAGIC_DOUBLE			法术连击单攻击 ( 含 feedback, 狂暴 )

	target_id= 被打的人 ID
	idx= 法术 ID
	FIGHT_ACTION_SINGLE_MAGIC_DOUBLE_DATA
	{
		char double_count;								// 连击次数
		SLONG hp[MAX_PHYSICS_DOUBLE_TIMES];				// 每次血量
		SLONG feedback[MAX_PHYSICS_DOUBLE_TIMES];		// 每次反馈
	}


=============================================================================================
( 0 - 5 ) FIGHT_ACTION_ITEM							使用道具
	target_id= 被打的人 ID



=============================================================================================
( 0 - 6 ) FIGHT_ACTION_RUN							逃跑
	target_id= 被打的人 ID
	idx=0 -> 逃跑失败, 1-> 逃跑成功


=============================================================================================
( 0 - 7 ) FIGHT_ACTION_CHANGE						更换宝宝
	target_id= 更换宝宝的 id



=============================================================================================
( 0 - 8 ) FIGHT_ACTION_SINGLE_VIRUS					中毒单人
	target_id= 被打的人 ID

		FIGHT_ACTION_SINGLE_VIRUS_DATA
		{
			SLONG hp;										// 毒血量
			SLONG loop_hp;									// 这回合掉血量
		}


=============================================================================================
( 0 - 9 ) FIGHT_ACTION_SINGLE_STATUS				状态单人(石化,混,睡,死亡宣告.... )
	target_id= 被打的人 ID
		
	状态放在 fight_value_result 里面		
		  
			
			  
// 以下依次类推
// ---- 法术技能部分 
				
		FIGHT_ACTION_MULTI_MAGIC=						100,	// 法术多攻击 ( 含 feedback, 狂暴 )
		FIGHT_ACTION_MULTI_MAGIC_DOUBLE=				101,	// 法术连击多攻击 ( 含 feedback, 狂暴 )
				  
		FIGHT_ACTION_MULTI_STATUS=						102,	// 状态多人(石化,混,睡,死亡宣告.... )
					




*/


enum	FIGHT_UNIT_TYPE_CODE
{
	FIGHT_UNIT_TYPE_CHARACTER=						0,		// 基本玩家
	FIGHT_UNIT_TYPE_BAOBAO=							1,		// 宝宝
	FIGHT_UNIT_TYPE_MONSTER=						2,		// 小妖怪
	FIGHT_UNIT_TYPE_BOSS=							3,		// BOSS 怪物
	FIGHT_UNIT_TYPE_AVATAR=							4		// 玩家变身 ( 使用妖怪或 BOSS 的 MDA )
};


enum	FIGHT_STATUS_CODE
{
	FIGHT_STATUS_NORMAL=							0x0000,	// 正常
	FIGHT_STATUS_VIRUS=								0x0001,	// 中毒
	FIGHT_STATUS_SLEEP=								0x0002,	// 昏睡
	FIGHT_STATUS_STONE=								0x0004,	// 石化
	FIGHT_STATUS_WEEK=								0x0008,	// 衰老
	FIGHT_STATUS_CHAOS=								0x0010,	// 混乱
	FIGHT_STATUS_PLAGUE=							0x0020,	// 瘟疫
	FIGHT_STATUS_DARK=								0x0040,	// 黑暗
	FIGHT_STATUS_DELAY=								0x0080,	// 迟缓
	FIGHT_STATUS_HURT=								0x0100,	// 伤害加深
	FIGHT_STATUS_DEAD_CALL=							0x0200,	// 死亡宣告
	FIGHT_STATUS_POWER=								0x0400,	// 威力
	FIGHT_STATUS_FASTNESS=							0x0800,	// 提抗
	FIGHT_STATUS_SPEED=								0x1000,	// 加速
	FIGHT_STATUS_PHYSICS_FEEDBACK=					0x2000,	// 物理反馈
	FIGHT_STATUS_MAGIC_FEEDBACK=					0x4000, // 法术反馈
	FIGHT_STATUS_DEAD=								0x8000,	// 战斗不能

	FIGHT_STATUS_LEAVE=								0x10000,
	FIGHT_STATUS_DEFEND=							0x20000,
};



enum	FIGHT_COMMAND_CODE
{
	FIGHT_COMMAND_ATTACK=							0,		// 物理攻击
	FIGHT_COMMAND_MAGIC=							1,		// 法术攻击
	FIGHT_COMMAND_ITEM=								2,		// 使用道具
	FIGHT_COMMAND_PROTECT=							3,		// 保护
	FIGHT_COMMAND_RECOVER=							4,		// 防御
	FIGHT_COMMAND_RUN=								5,		// 逃跑
	FIGHT_COMMAND_CHANGE=							6,		// 更换宝宝
	FIGHT_COMMAND_AUTO_HP=							7,		// 自动补血
	FIGHT_COMMAND_AUTO_MP=							8,		// 自动补法
	FIGHT_COMMAND_AUTO_ATTACK=						9		// 自动攻击

};


enum	FIGHT_ACTION_CODE
{
// --- 基本攻击部分
	FIGHT_ACTION_SINGLE_PHYSICS=					0,		// 物理单攻击 ( 含 feedback,致命, 狂暴 )
	FIGHT_ACTION_SINGLE_PHYSICS_DOUBLE=				1,		// 物理连击 ( 含 feedback, 致命，狂暴 )

	FIGHT_ACTION_SINGLE_MAGIC=						2,		// 法术单攻击 ( 含 feedback, 狂暴 )
	FIGHT_ACTION_SINGLE_MAGIC_DOUBLE=				3,		// 法术连击单攻击 ( 含 feedback, 狂暴 )

	FIGHT_ACTION_ITEM=								4,		// 道具单人
	FIGHT_ACTION_RUN=								5,		// 逃跑单人
	FIGHT_ACTION_CHANGE=							6,		// 更换宝宝单人

	FIGHT_ACTION_SINGLE_STATUS=						7,		// 状态单人(石化,混,睡,死亡宣告.... )




// ---- 法术技能部分
	FIGHT_ACTION_MULTI_MAGIC=						100,	// 法术多攻击 ( 含 feedback, 狂暴 )
	FIGHT_ACTION_MULTI_MAGIC_DOUBLE=				101,	// 法术连击多攻击 ( 含 feedback, 狂暴 )

	FIGHT_ACTION_MULTI_STATUS=						102		// 状态多人(石化,混,睡,死亡宣告.... )
	

};



enum	CHARGE_TIME_CONTROL_CODE
{
	CHARGE_TIME_INITIALIZE=							0,		// 清除 充电时间
	CHARGE_TIME_PAUSE=								1,		// 暂停充电
	CHARGE_TIME_CONTINUE=							2,		// 继续充电
	CHARGE_TIME_RESET=								3		// 重新开始
};



// ------------------
// ------ 本身玩家的资料也要下载,怕能有进入战斗的变身数值效果...
// ------------------
// --- 第一次进入 request 
typedef struct FIGHT_BASE_DATA_STRUCT				// 战斗基本单元资料
{
	char active;									// 目前是否在战斗当中
	ULONG id;										// 单元的 id
	char name[MAX_NAME_LENGTH+1];					// 昵称
	SLONG max_hp;									// 最大 HP
	SLONG now_hp;									// 目前 HP
	SLONG max_mp;									// 最大 MP
	SLONG now_mp;									// 目前 MP
	char charge_speed;								// 目前充电编号
	SHINT filename_id;								// 战斗 MDA 编号
	char unit_type;									// 战斗人物种类 see enum ( FIGHT_UNIT_TYPE_CODE )
	UHINT status;									// 目前人物状态 see enum ( FIGHT_STATUS_CODE )
	char life_base;									// 转生次数( show 名字 color )
	
} FIGHT_BASE_DATA;


// --- ( 0 - 0 ) 每一回合开始 发送 ACTION_READY, 并且等待 STATUS_RESULT 回复
typedef struct FIGHT_STATUS_RESULT_STRUCT			// 接受的战斗状态结果
{
	ULONG target_id;								// 命令接受人
	UHINT status;									// 状态数值
	SLONG hp;										// 中毒的时候的数值
} FIGHT_STATUS_RESULT;


// --- ( 0 - 1 ) 发送动作命令
typedef struct FIGHT_COMMAND_DATA_STRUCT			// 发送的战斗命令
{
	char command;									// 主要攻击命令 see enum ( FIGHT_COMMAND_CODE )
	ULONG source_id;								// 下命令人 ID
	ULONG target_id;								// 受命令人 ID ( 可能是人,宝宝,BOSS,NPC...)
	char type_no;									// 技能编号,口袋编号
	
} FIGHT_COMMAND_DATA;



// --- ( 1 - 0 ) 接受动作结果 ( 平常都有可能, 一旦接受,停止所有人充电,执行结果 )
typedef struct FIGHT_ACTION_RESULE_STRUCT
{
	char command;									// 动作命令 see enum ( FIGHT_ACTION_CODE )
	ULONG source_id;								// 发动人 id
	ULONG target_id;								// 受动作人 id 如果有定义的动作,此参数无效 ( 刚换宝宝 ID )
	char idx;										// 其他资料 ( 法术编号...等等),逃跑时候 ( 0-> 不成功,1-> 成功)
} FIGHT_ACTION_RESULT;								// 资料放在 ( 9 - 0 ) 以后定义


// --- ( 1 - 1 ) 接受战斗数值结果
typedef struct FIGHT_VALUE_RESULT_STRUCT			// 接受的战斗数值结果
{													
	ULONG id;										// 接受人 id
	SLONG max_hp;									// 最大 HP
	SLONG now_hp;									// 目前 HP
	SLONG max_mp;									// 最大 MP
	SLONG now_mp;									// 目前 MP
	char charge_speed;								// 目前速度
	UHINT status;									// 目前状态

} FIGHT_VALUE_RESULT;



// --- ( 9 - 9 ) Fight Action 所需要的资料结构
typedef struct FIGHT_ACTION_SINGLE_PHYSICS_DATA_STRUCT
{													// 物理单攻击 ( 含 feedback,致命, 狂暴 )
	SLONG hp;										// 攻击血量
	SLONG feed_back_hp;								// 反馈血量
	ULONG protect_id;								// 保护 id, id= 0 没有人保护
	SLONG back_hp;									// 反击血量 > 0 的时候发生反击
} FIGHT_ACTION_SINGLE_PHYSICS_DATA;



typedef struct FIGHT_ACTION_SINGLE_PHYSICS_DOUBLE_DATA_STRUCT
{													// 物理连击 ( 含 feedback, 致命，狂暴 )
	char double_count;								// 连击次数
	SLONG hp[MAX_PHYSICS_DOUBLE_TIMES];				// 每次血量
	SLONG feedback[MAX_PHYSICS_DOUBLE_TIMES];		// 每次反馈
	SLONG back_hp[MAX_PHYSICS_DOUBLE_TIMES];		// 反击血量
} FIGHT_ACTION_SINGLE_PHYSICS_DOUBLE_DATA;



typedef struct FIGHT_ACTION_SINGLE_MAGIC_DATA_STRUCT
{													// 法术单攻击 ( 含 feedback, 狂暴 )
	SLONG hp;										// 法术攻击 HP
	SLONG feed_back_hp;								// 反馈血量
} FIGHT_ACTION_SINGLE_MAGIC_DATA;



typedef struct FIGHT_ACTION_SINGLE_MAGIC_DOUBLE_DATA_STRUCT
{													// 法术连击单攻击 ( 含 feedback, 狂暴 )
	char double_count;								// 连击次数
	SLONG hp[MAX_PHYSICS_DOUBLE_TIMES];				// 每次血量
	SLONG feedback[MAX_PHYSICS_DOUBLE_TIMES];		// 每次反馈
} FIGHT_ACTION_SINGLE_MAGIC_DOUBLE_DATA;



typedef struct FIGHT_ACTION_CHANGE_BAOBAO_DATA_STRUCT
{
	char name[MAX_NAME_LENGTH+1];					// 昵称
	SHINT filename_id;								// 战斗 MDA 编号
	char unit_type;									// 战斗人物种类 see enum ( FIGHT_UNIT_TYPE_CODE )
	char life_base;									// 转生次数( show 名字 color )
	FIGHT_VALUE_RESULT data;

} FIGHT_ACTION_CHANGE_BAOBAO_DATA;


// ---- 多人技能部分
typedef struct FIGHT_ACTION_MULTI_MAGIC_DATA_STRUCT
{													// 法术多攻击 ( 含 feedback, 狂暴 )
	char number;									// 攻击数量
	ULONG id[MAX_FIGHT_UNIT];						// 被攻击方id
	SLONG hp[MAX_FIGHT_UNIT];						// 攻击血量
	SLONG feed_back_hp[MAX_FIGHT_UNIT];				// 反馈血量
} FIGHT_ACTION_MULTI_MAGIC_DATA;



typedef struct FIGHT_ACTION_MULTI_MAGIC_DOUBLE_DATA_STRUCT
{													// 法术连击多攻击 ( 含 feedback, 狂暴 )
	char number;									// 攻击数量
	char double_count;								// 连击次数
	ULONG id[MAX_FIGHT_UNIT];						// 被攻击方id
	SLONG hp[MAX_FIGHT_UNIT][MAX_PHYSICS_DOUBLE_TIMES];	// 攻击血量
	SLONG feed_back_hp[MAX_FIGHT_UNIT][MAX_PHYSICS_DOUBLE_TIMES];	// 反馈血量
} FIGHT_ACTION_MULTI_MAGIC_DOUBLE_DATA;



#define CHARGE_DELAY_TIME							3000		// 充电满的时候的延迟时间 3 秒

typedef struct FIGHT_CHARGE_TIME_DATA_STRUCT
{
	ULONG charge_start_time;						// 开始充电时间
	ULONG charge_time;								// 总共需要充电时间 (充到 100%) 所需要的时间
	ULONG delay_time;								// 充电满的时候的延迟 conut 
} FIGHT_CHARGE_TIME_DATA;


typedef struct FIGHT_BAOBAO_SKILL_DATA_STRUCT		// 当前宝宝 技能表
{
	char skill_id;
} FIGHT_BAOBAO_SKILL_DATA;




#endif