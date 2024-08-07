/*
**    XSOUND.H
**    DirectSound functions header.
**    ZJian,2000/7/10.
*/
#ifndef XSOUND_H_INCLUDE
#define XSOUND_H_INCLUDE        1
#include "packfile.h"


// DEFINES ////////////////////////////////////////////////////////////////////////////////////////////////////////
//assign sound channels--------------------------------------
#define MAX_SOUND_CHANNELS      8   //最大声音通道数
//
#define VOICE_CHANNEL_MIN       0   //音效的最小通道
#define VOICE_CHANNEL_0         0   //
#define VOICE_CHANNEL_MAX       6   //音效的最大通道
//
#define MUSIC_CHANNEL           7   //音乐的通道


//refrence <dsound.h> ---------------------------------------
#define MUSIC_VOLUME_MIN        DSBVOLUME_MIN   //-10000
#define MUSIC_VOLUME_MAX        DSBVOLUME_MAX   //0
#define MUSIC_PAN_LEFT          DSBPAN_LEFT     //-10000
#define MUSIC_PAN_CENTER        DSBPAN_CENTER   //0
#define MUSIC_PAN_RIGHT         DSBPAN_RIGHT    //10000

#define VOICE_VOLUME_MIN        DSBVOLUME_MIN   //-10000
#define VOICE_VOLUME_MAX        DSBVOLUME_MAX   //0
#define VOICE_PAN_LEFT          DSBPAN_LEFT     //-10000
#define VOICE_PAN_CENTER        DSBPAN_CENTER   //0
#define VOICE_PAN_RIGHT         DSBPAN_RIGHT    //10000

//changed sound cfg flags -----------------------------------
#define CHANGED_MUSIC_FLAG      0x01   //
#define CHANGED_MUSIC_TOTAL     0x02   //
#define CHANGED_MUSIC_VOLUME    0x04   //
#define CHANGED_MUSIC_PAN       0x08   //
#define CHANGED_VOICE_FLAG      0x10   //
#define CHANGED_VOICE_VOLUME    0x20   //
#define CHANGED_VOICE_PAN       0x40   //

//music types
#define MUSIC_TYPE_WAVE         0   //音乐采用wave档案格式
#define MUSIC_TYPE_MP3          1   //音乐采用mp3档案格式
#define MUSIC_TYPE_CDROM        2   //音乐采用cd音轨


//STRUCTURES ////////////////////////////////////////////////////////////////////////////////////////////////
//wave sample structure. 
#pragma pack(push)
#pragma pack(1)
typedef struct  tagSAMPLE
{
    WAVEFORMATEX    wf;     //声音格式
    SLONG   buffer_bytes;   //声音数据大小
    SLONG   number;         //编号
    USTR    buffer[1];      //声音数据区
} SAMPLE, *LPSAMPLE;
#pragma pack(pop)

//music structure.
typedef struct  tagMUSIC
{
	SLONG   buffer_bytes;   //数据大小
	SLONG   offset;         //数据偏移值
	void    *file;          //数据流文件指标
} MUSIC, *LPMUSIC;


//sound config-----------------------------------------------
typedef struct  tagSOUND_CFG
{
    SLONG   music_flag;         //音乐标志
    SLONG   music_no;           //当前播放的音乐编号
    SLONG   music_total;        //所有音乐数目
    SLONG   music_volume;       //音乐音量大小(-10000 ~ 0)
    SLONG   music_pan;          //音乐平衡(左 = -10000,中 = 0,右 = 10000)
    SLONG   voice_flag;         //音效标志
    SLONG   voice_volume;       //音效音量大小(-10000 ~ 0)
    SLONG   voice_pan;          //音效平衡(左 = -10000,中 = 0,右 = 10000)
} SOUND_CFG;


//GLOBALS ////////////////////////////////////////////////////////////////////////////////////////////////////
extern  SOUND_CFG   sound_cfg;
//

extern  void    (*play_music)(SLONG music_no, SLONG loop);
extern  void    (*stop_music)(void);
extern  void    (*set_music_volume)(SLONG volume);
extern  void    (*set_music_pan)(SLONG pan);
extern  SLONG   (*is_music_playing)(void);
//

//FUNCTION PROTOTYPES ///////////////////////////////////////////////////////////////////////////////////////
EXPORT  void    FNBACK  init_sound_cfg(void);
EXPORT  void    FNBACK  notify_changed_sound_cfg(SLONG changed_flags);
//
EXPORT  void    FNBACK  set_music_type(SLONG type);
EXPORT  int     FNBACK  init_sound(void);
EXPORT  void    FNBACK  free_sound(void);
EXPORT  void    FNBACK  active_sound(int active);
//
EXPORT  void    FNBACK  play_voice(SLONG channel,SLONG loop,USTR *filename);
EXPORT  void    FNBACK  play_buffer_voice(SLONG channel,SLONG loop,USTR *buffer, SLONG buffer_size);
EXPORT  void    FNBACK  stop_voice(SLONG channel);
EXPORT  void    FNBACK  set_voice_volume(SLONG channel,SLONG volume);
EXPORT  void    FNBACK  set_voice_pan(SLONG channel,SLONG pan);
EXPORT  SLONG   FNBACK  is_voice_playing(SLONG channel);
EXPORT	void	FNBACK	direct_play_voice(SLONG start_channel, SLONG end_channel, SLONG loop, USTR *filename);
//
EXPORT  SLONG   FNBACK  get_wavfile_information(USTR *filename, ULONG *channels, ULONG *sample_rate, 
                                                ULONG *bps, ULONG *size, ULONG *play_time);
//
//WAVE SAMPLE FUNCTIONS
EXPORT  SLONG   FNBACK  get_wav_format(PACK_FILE *hfile, WAVEFORMATEX *wf, SLONG *block_size, SLONG *wave_size);
EXPORT  SLONG   FNBACK  get_wav_data(PACK_FILE *hfile, USTR *data, SLONG blocksize);
EXPORT  SLONG   FNBACK  get_buffer_wav_format(USTR *buffer, SLONG *buffer_offset, WAVEFORMATEX *wf, SLONG *block_size, SLONG *wave_size);
EXPORT  SLONG   FNBACK  get_buffer_wav_data(USTR *buffer, SLONG *buffer_index, USTR *data, SLONG blocksize);
EXPORT  SAMPLE* FNBACK  load_wav_from_file(USTR *filename);
EXPORT  SAMPLE* FNBACK  load_wav_from_buffer(USTR *buffer, SLONG buffer_size);
EXPORT  void    FNBACK  destroy_sample(SAMPLE **sample);
//



#endif//XSOUND_H_INCLUDE
