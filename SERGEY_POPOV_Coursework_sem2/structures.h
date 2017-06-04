#pragma pack(1) //ensure structure is packed
typedef struct tagBITMAPFILEHEADER
{
    short bfType;  		//specifies the file type
    int bfSize;  		//specifies the size in bytes of the bitmap file
    short bfReserved1;  //reserved; must be 0
    short bfReserved2;  //reserved; must be 0
    int bfOffBits;  	//species the offset in bytes from the bitmapfileheader to the bitmap bits
}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
    int biSize;  			//specifies the number of bytes required by the struct
    int biWidth;  			//specifies width in pixels
    int biHeight;           //species height in pixels
    short biPlanes; 		//specifies the number of color planes, must be 1
    short biBitCount; 		//specifies the number of bit per pixel
    int biCompression;		//spcifies the type of compression
    int biSizeImage;  		//size of image in bytes
    int biXPelsPerMeter; 	//number of pixels per meter in x axis
    int biYPelsPerMeter;  	//number of pixels biYPelsPerMeter meter in y axis
    int biClrUsed;  		//number of colors used by th ebitmap
    int biClrImportant;  	//number of colors that are important
}BITMAPINFOHEADER;

#pragma pack(0)  // restore normal structure packing rules
