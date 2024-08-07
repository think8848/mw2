#ifndef _LBMLIB_H_
#define _LBMLIB_H_


void LoadLBM (char *filename, byte **picture, byte **palette);
void WriteLBMfile (char *filename, byte *data, int width, int height
	, byte *palette);
int LoadPCX (char *filename, byte **picture, byte **palette, int *width, int *height);
void WritePCXfile (char *filename, byte *data, int width, int height
	, byte *palette);

// loads / saves either lbm or pcx, depending on extension
void Load256Image (char *name, byte **pixels, byte **palette,
				   int *width, int *height);
void Save256Image (char *name, byte *pixels, byte *palette,
				   int width, int height);


int	LoadTGA (char *filename, byte **pixels, int *width, int *height);
void Sys_Printf (char *text, ...);

#endif
