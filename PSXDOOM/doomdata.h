/* DoomData.h */

/* all external data is defined here */
/* most of the data is loaded into different structures at run time */

#ifndef __DOOMDATA__
#define __DOOMDATA__

#ifndef __BYTEBOOL__
#define __BYTEBOOL__
#include <stdbool.h>

typedef bool boolean;
typedef unsigned char byte;
#endif

/*
===============================================================================

						map level types

===============================================================================
*/

/* lump order in a map wad */
enum {ML_LABEL, ML_THINGS, ML_LINEDEFS, ML_SIDEDEFS, ML_VERTEXES, ML_SEGS,
ML_SSECTORS, ML_NODES, ML_SECTORS , ML_REJECT, ML_BLOCKMAP, ML_LEAFS, ENDOFWAD
};


typedef struct
{
	int x, y; //Psx Doom
} mapvertex_t;

typedef struct
{
	short		textureoffset;
	short		rowoffset;
	char		toptexture[8], bottomtexture[8], midtexture[8];
	short		sector;				/* on viewer's side */
} mapsidedef_t;

typedef struct
{
	short		v1, v2;
	short		flags;
	short		special, tag;
	short		sidenum[2];			/* sidenum[1] will be -1 if one sided */
} maplinedef_t;

#define	ML_BLOCKING			1
#define	ML_BLOCKMONSTERS	2
#define	ML_TWOSIDED			4		/* backside will not be present at all  */
									/* if not two sided ???:obsolete */

/* if a texture is pegged, the texture will have the end exposed to air held */
/* constant at the top or bottom of the texture (stairs or pulled down things) */
/* and will move with a height change of one of the neighbor sectors */
/* Unpegged textures allways have the first row of the texture at the top */
/* pixel of the line for both top and bottom textures (windows) */
#define	ML_DONTPEGTOP		8
#define	ML_DONTPEGBOTTOM	16

#define ML_SECRET			32	/* don't map as two sided: IT'S A SECRET! */
#define ML_SOUNDBLOCK		64	/* don't let sound cross two of these */
#define	ML_DONTDRAW			128	/* don't draw on the automap */
#define	ML_MAPPED			256	/* set if allready drawn in automap */

// Psx Doom New Flags
#define ML_MIDMASKED		0x200
#define ML_MIDTRANSLUCENT	0x400
#define ML_BLOCKPRJECTILE	0x800

typedef	struct
{
	short		floorheight, ceilingheight; //*, *2
	char		floorpic[8], ceilingpic[8]; //*4 ,*12
	char		lightlevel;                 //*20
	char		colorid;                    //*21
	short		special, tag;               //*22, *24
	short		flags;	                    //Psx Doom *26
} mapsector_t;

typedef struct
{
	short		numsegs;
	short		firstseg;			/* segs are stored sequentially */
} mapsubsector_t;

typedef struct
{
	short		v1, v2;
	short		angle;			/* ???: make this a sidedef? */
	short		linedef, side;
	short		offset;
} mapseg_t;

enum {BOXTOP,BOXBOTTOM,BOXLEFT,BOXRIGHT};	/* bbox coordinates */

#define	NF_SUBSECTOR	0x8000
typedef struct
{
	short		x,y,dx,dy;			/* partition line */
	short		bbox[2][4];			/* bounding box for each child */
	unsigned short	children[2];		/* if NF_SUBSECTOR its a subsector */
} mapnode_t;

typedef struct
{
	short		x,y;
	short		angle;
	short		type;
	short		options;
} mapthing_t;

#define	MTF_EASY		1
#define	MTF_NORMAL		2
#define	MTF_HARD		4
#define	MTF_AMBUSH		8
//Psx Doom
#define MTF_BLENDMASK1	0x20
#define MTF_BLENDMASK2	0x40
#define MTF_BLENDMASK3	0x80

/*
===============================================================================

						texture definition

===============================================================================
*/

typedef struct
{
	short	originx;
	short	originy;
	short	patch;
	short	stepdir;
	short	colormap;
} mappatch_t;

typedef struct
{
	//char		name[8];
	//boolean		masked;
	short		leftoffset;
	short		topoffset;
	short		width;
	short		height;
	//void		**columndirectory;	/* OBSOLETE */
	//short		patchcount;
	//mappatch_t	patches[1];
} maptexture_t;


/*
===============================================================================

							graphics

===============================================================================
*/

/* shorts are stored BIG ENDIAN */


/* column_t are runs of non masked source pixels */
typedef struct
{
	byte			topdelta;	/* 0xff is the last post in a column */
	byte			length;
	unsigned short	dataofs;	/* from data start in patch_t */
} column_t;

/* a patch holds one or more columns */
/* patches are used for sprites and all masked pictures */
typedef struct
{
	short		width;				/* bounding box size  */
	short		height;
	short		leftoffset;			/* pixels to the left of origin  */
	short		topoffset;			/* pixels below the origin  */
	unsigned short	columnofs[8];	/* only [width] used */
									/* the [0] is &columnofs[width]  */
} patch_t;


/*
===============================================================================

							status

===============================================================================
*/




#endif			/* __DOOMDATA__ */

