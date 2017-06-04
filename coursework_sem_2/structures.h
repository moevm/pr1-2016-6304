#pragma pack(push, 1)//packs a structure with 1 byte aligning

typedef struct bmHeader
{
   unsigned short signature; //determines a file type. Must b a BM type.
   unsigned int fileSize; //file size in bytes
   unsigned short Reserved1; //reserved and must be a 0
   unsigned short Reserved2; //reserved and must be a 0
   unsigned int offsetToPixels; //shows where the actual bitmap massive starts
} bmHeader;

typedef struct DIBheader
{
   unsigned int DIBSize; //a structure size
   unsigned int width; //width of pic
   unsigned int height; //height of pic
   unsigned short planes; //number of planes (1 for now)
   unsigned short bitCount; //bytes per pixel
   unsigned int compression; //type of compression, put BI_RGB if there is no such
   unsigned int sizeImage; //size of pic in bytes but 0 if there was no compression
   unsigned int xPixPerMeter; //horizontal resolution of a gadget which a pic will be output on
   unsigned int yPixPerMeter; //vertical resolution of a gadget which a pic will be output on
   unsigned int colourUsed; //determines amount of used colours
   unsigned int colourImportant; //determines amount of important colours for pic showing, if 0 all are important
} DIBheader;



typedef struct RGB
{
	char  Blue;//blue part
	char  Green;//green part
	char  Red;//red part
} RGB;
#pragma pack(pop)//returns older aligning value
