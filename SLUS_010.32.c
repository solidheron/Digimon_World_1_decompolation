typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned short    ushort;
typedef unsigned short    word;
typedef ulong u_long;

typedef ushort u_short;

typedef uint size_t;

typedef uchar u_char;

typedef struct MATRIX MATRIX, *PMATRIX;

struct MATRIX {
    short m[3][3];
    long t[3];
};

typedef struct VECTOR VECTOR, *PVECTOR;

struct VECTOR {
    long vx;
    long vy;
    long vz;
    long pad;
};

typedef struct SVECTOR SVECTOR, *PSVECTOR;

struct SVECTOR {
    short vx;
    short vy;
    short vz;
    short pad;
};

typedef struct CVECTOR CVECTOR, *PCVECTOR;

struct CVECTOR {
    u_char r;
    u_char g;
    u_char b;
    u_char cd;
};

typedef struct DVECTOR DVECTOR, *PDVECTOR;

struct DVECTOR {
    short vx;
    short vy;
};

typedef struct GsSPRITE GsSPRITE, *PGsSPRITE;

struct GsSPRITE {
    ulong attribute;
    short x;
    short y;
    ushort w;
    ushort h;
    ushort tpage;
    uchar u;
    uchar v;
    short cx;
    short cy;
    uchar r;
    uchar g;
    uchar b;
    short mx;
    short my;
    short scalex;
    short scaley;
    long rotate;
};

typedef struct GsDOBJ2 GsDOBJ2, *PGsDOBJ2;

typedef struct _GsCOORDINATE2 _GsCOORDINATE2, *P_GsCOORDINATE2;

typedef struct _GsCOORDINATE2 GsCOORDINATE2;

typedef struct GsCOORD2PARAM GsCOORD2PARAM, *PGsCOORD2PARAM;

struct GsCOORD2PARAM {
    struct VECTOR scale;
    struct SVECTOR rotate;
    struct VECTOR trans;
};

struct _GsCOORDINATE2 {
    ulong flg;
    struct MATRIX coord;
    struct MATRIX workm;
    struct GsCOORD2PARAM *param;
    struct _GsCOORDINATE2 *super;
    struct _GsCOORDINATE2 *sub;
};

struct GsDOBJ2 {
    ulong attribute;
    GsCOORDINATE2 *coord2;
    ulong *tmd;
    ulong id;
};

typedef struct GsOT_TAG GsOT_TAG, *PGsOT_TAG;

struct GsOT_TAG {
    uint p:24;
    uchar num:8;
};

typedef struct GsOT GsOT, *PGsOT;

struct GsOT {
    ulong length;
    struct GsOT_TAG *org;
    ulong offset;
    ulong point;
    struct GsOT_TAG *tag;
};

typedef struct GsBOXF GsBOXF, *PGsBOXF;

struct GsBOXF {
    ulong attribute;
    short x;
    short y;
    ushort w;
    ushort h;
    uchar r;
    uchar g;
    uchar b;
};

typedef struct GsVIEW2 GsVIEW2, *PGsVIEW2;

struct GsVIEW2 {
    struct MATRIX view;
    GsCOORDINATE2 *super;
};

typedef struct GsIMAGE GsIMAGE, *PGsIMAGE;

struct GsIMAGE {
    ulong pmode;
    short px;
    short py;
    ushort pw;
    ushort ph;
    ulong *pixel;
    short cx;
    short cy;
    ushort cw;
    ushort ch;
    ulong *clut;
};

typedef struct VERTC VERTC, *PVERTC;

struct VERTC {
    short vx;
    short vy;
    short vz;
    u_char tu;
    u_char tv;
    struct CVECTOR col;
};

typedef struct ProgAtr ProgAtr, *PProgAtr;

struct ProgAtr {
    uchar tones;
    uchar mvol;
    uchar prior;
    uchar mode;
    uchar mpan;
    char reserved0;
    short attr;
    ulong reserved1;
    ulong reserved2;
};

typedef struct VagAtr VagAtr, *PVagAtr;

struct VagAtr {
    uchar prior;
    uchar mode;
    uchar vol;
    uchar pan;
    uchar center;
    uchar shift;
    uchar min;
    uchar max;
    uchar vibW;
    uchar vibT;
    uchar porW;
    uchar porT;
    uchar pbmin;
    uchar pbmax;
    uchar reserved1;
    uchar reserved2;
    ushort adsr1;
    ushort adsr2;
    short prog;
    short vag;
    short reserved[4];
};

typedef struct CdlLOC CdlLOC, *PCdlLOC;

struct CdlLOC {
    u_char minute;
    u_char second;
    u_char sector;
    u_char track;
};

typedef struct LINE_F3 LINE_F3, *PLINE_F3;

struct LINE_F3 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char code;
    short x0;
    short y0;
    short x1;
    short y1;
    short x2;
    short y2;
    u_long pad;
};

typedef struct LINE_F4 LINE_F4, *PLINE_F4;

struct LINE_F4 {
    u_long tag;
    u_char r0;
    u_char g0;
    u_char b0;
    u_char code;
    short x0;
    short y0;
    short x1;
    short y1;
    short x2;
    short y2;
    short x3;
    short y3;
    u_long pad;
};

typedef struct DIRENTRY DIRENTRY, *PDIRENTRY;

struct DIRENTRY {
};

typedef struct SpuVoiceAttr SpuVoiceAttr, *PSpuVoiceAttr;

typedef struct SpuVolume SpuVolume, *PSpuVolume;

struct SpuVolume {
    short left;
    short right;
};

struct SpuVoiceAttr {
    ulong voice;
    ulong mask;
    struct SpuVolume volume;
    struct SpuVolume volmode;
    struct SpuVolume volumex;
    ushort pitch;
    ushort note;
    ushort sample_note;
    short envx;
    ulong addr;
    ulong loop_addr;
    long a_mode;
    long s_mode;
    long r_mode;
    ushort ar;
    ushort dr;
    ushort sr;
    ushort rr;
    ushort sl;
    ushort adsr1;
    ushort adsr2;
};

typedef struct SpuExtAttr SpuExtAttr, *PSpuExtAttr;

struct SpuExtAttr {
    struct SpuVolume volume;
    long reverb;
    long mix;
};

typedef struct SpuCommonAttr SpuCommonAttr, *PSpuCommonAttr;

struct SpuCommonAttr {
    ulong mask;
    struct SpuVolume mvol;
    struct SpuVolume mvolmode;
    struct SpuVolume mvolx;
    struct SpuExtAttr cd;
    struct SpuExtAttr ext;
};

typedef struct SpuReverbAttr SpuReverbAttr, *PSpuReverbAttr;

struct SpuReverbAttr {
    ulong mask;
    long mode;
    struct SpuVolume depth;
    long delay;
    long feedback;
};



