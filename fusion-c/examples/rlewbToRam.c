//
// Fusion-C 
// Rle To Ram Example
// 
//
#include "fusion-c/header/msx_fusion.h"
#include "fusion-c/header/vdp_graph2.h"


unsigned char __at(0x8000) dest[7600];
const unsigned char cat[]={
 0x80, 0xfb, 0xff, 0x80, 0xfb, 0xff, 0x80, 0xfb, 0xff, 0x80, 0xef, 0xff, 0xfe, 0xcc, 0xce, 0x80,
 0x7c, 0xff, 0xed, 0xba, 0x90, 0x9d, 0x80, 0x7b, 0xff, 0xed, 0xb9, 0x80, 0x02, 0x00, 0x0d, 0x80,
 0x79, 0xff, 0xee, 0xed, 0xc9, 0x80, 0x03, 0x00, 0xae, 0x80, 0x78, 0xff, 0xdb, 0x80, 0x02, 0xa9,
 0x90, 0x80, 0x03, 0x00, 0xbf, 0x80, 0x75, 0xff, 0x80, 0x02, 0xee, 0xdb, 0x90, 0x80, 0x06, 0x00,
 0x9a, 0xdf, 0x80, 0x72, 0xff, 0xed, 0xcb, 0xaa, 0xbb, 0xa0, 0x80, 0x08, 0x00, 0x9c, 0x80, 0x71,
 0xff, 0xfe, 0xb9, 0x80, 0x0c, 0x00, 0x09, 0xdf, 0x80, 0x6f, 0xff, 0xfe, 0xb9, 0x80, 0x0e, 0x00,
 0xae, 0x80, 0x6e, 0xff, 0xfe, 0xca, 0x90, 0x80, 0x0e, 0x00, 0x0d, 0x80, 0x5f, 0xff, 0xfe, 0x80,
 0x04, 0xee, 0x80, 0x09, 0xff, 0xfe, 0xca, 0x80, 0x10, 0x00, 0x0b, 0xef, 0x80, 0x5c, 0xff, 0xee,
 0xdc, 0xbb, 0xba, 0x80, 0x02, 0xaa, 0xbb, 0xbc, 0xcd, 0xee, 0xef, 0x80, 0x04, 0xff, 0xfe, 0xca,
 0x90, 0x80, 0x10, 0x00, 0x0b, 0xef, 0x80, 0x5b, 0xff, 0xec, 0xa9, 0x90, 0x80, 0x06, 0x00, 0x99,
 0x9a, 0xbc, 0x80, 0x04, 0xee, 0xca, 0x90, 0x80, 0x11, 0x00, 0x0b, 0xef, 0x80, 0x5a, 0xff, 0xdb,
 0x99, 0x80, 0x0a, 0x00, 0x09, 0x80, 0x04, 0xaa, 0x90, 0x80, 0x12, 0x00, 0x0b, 0xef, 0x80, 0x59,
 0xff, 0xeb, 0x90, 0x80, 0x23, 0x00, 0x0a, 0xef, 0x80, 0x58, 0xff, 0xfe, 0xa0, 0x80, 0x25, 0x00,
 0xcf, 0x80, 0x58, 0xff, 0xea, 0x80, 0x26, 0x00, 0x9d, 0x80, 0x57, 0xff, 0xfe, 0xa0, 0x80, 0x26,
 0x00, 0x0c, 0x80, 0x57, 0xff, 0xdb, 0x90, 0x80, 0x26, 0x00, 0x9d, 0x80, 0x55, 0xff, 0xfe, 0xcb,
 0x90, 0x80, 0x27, 0x00, 0xcf, 0x80, 0x55, 0xff, 0xda, 0x80, 0x22, 0x00, 0x9a, 0xa9, 0x90, 0x80,
 0x03, 0x00, 0x9b, 0xef, 0x80, 0x54, 0xff, 0xfd, 0xa0, 0x80, 0x21, 0x00, 0x9b, 0xde, 0xed, 0xcb,
 0xa9, 0x99, 0x09, 0xbe, 0x80, 0x55, 0xff, 0xd9, 0x80, 0x22, 0x00, 0xce, 0x80, 0x02, 0xff, 0xfe,
 0xed, 0xcc, 0xcd, 0xef, 0x80, 0x54, 0xff, 0xfd, 0x90, 0x80, 0x21, 0x00, 0x0b, 0x80, 0x5c, 0xff,
 0xd9, 0x80, 0x22, 0x00, 0xae, 0x80, 0x5b, 0xff, 0xfd, 0x90, 0x80, 0x22, 0x00, 0xcf, 0x80, 0x5b,
 0xff, 0xda, 0x80, 0x22, 0x00, 0x0a, 0xef, 0x80, 0x5a, 0xff, 0xfe, 0xa0, 0x80, 0x22, 0x00, 0x9c,
 0x80, 0x5b, 0xff, 0xda, 0x80, 0x03, 0x00, 0x90, 0x80, 0x1f, 0x00, 0x9e, 0x80, 0x5a, 0xff, 0xfd,
 0xa0, 0x80, 0x02, 0x00, 0x0b, 0xc9, 0x80, 0x1f, 0x00, 0x9e, 0x80, 0x5a, 0xff, 0xc9, 0x80, 0x03,
 0x00, 0xbf, 0xea, 0x80, 0x1f, 0x00, 0x9e, 0x80, 0x59, 0xff, 0xfc, 0x90, 0x80, 0x02, 0x00, 0x9b,
 0xef, 0xea, 0x80, 0x1f, 0x00, 0x9e, 0x80, 0x58, 0xff, 0xfe, 0xb9, 0x80, 0x02, 0x00, 0x09, 0xcf,
 0xff, 0xe9, 0x80, 0x1f, 0x00, 0xae, 0x80, 0x58, 0xff, 0xdb, 0x80, 0x03, 0x00, 0xad, 0x80, 0x02,
 0xff, 0xd9, 0x80, 0x19, 0x00, 0x99, 0x80, 0x04, 0x00, 0x09, 0xcf, 0x80, 0x57, 0xff, 0xec, 0xa0,
 0x80, 0x02, 0x00, 0x0a, 0xef, 0x80, 0x02, 0xff, 0xb0, 0x80, 0x18, 0x00, 0x09, 0xcc, 0x90, 0x80,
 0x03, 0x00, 0x09, 0xef, 0x80, 0x56, 0xff, 0xdc, 0xa9, 0x80, 0x02, 0x00, 0x09, 0xbe, 0x80, 0x02,
 0xff, 0xfd, 0x90, 0x80, 0x18, 0x00, 0x9c, 0xef, 0xda, 0x80, 0x03, 0x00, 0x0a, 0x80, 0x53, 0xff,
 0xfe, 0xcb, 0x80, 0x02, 0xaa, 0xa9, 0x80, 0x03, 0x00, 0x9c, 0xef, 0x80, 0x02, 0xff, 0xeb, 0x80,
 0x18, 0x00, 0x0b, 0xdf, 0xff, 0xfe, 0xb0, 0x80, 0x02, 0x00, 0x0b, 0x80, 0x52, 0xff, 0xec, 0xb9,
 0x90, 0x80, 0x05, 0x00, 0x0a, 0xdf, 0xff, 0xfe, 0xdc, 0xa0, 0x80, 0x17, 0x00, 0x9a, 0xce, 0x80,
 0x03, 0xff, 0xfc, 0x90, 0x00, 0x0c, 0x80, 0x51, 0xff, 0xec, 0xa0, 0x80, 0x06, 0x00, 0x09, 0xbe,
 0xff, 0xfe, 0xca, 0x99, 0x80, 0x16, 0x00, 0x09, 0x9b, 0xce, 0x80, 0x05, 0xff, 0xb0, 0x00, 0xae,
 0x80, 0x50, 0xff, 0xed, 0xa0, 0x80, 0x06, 0x00, 0x09, 0xad, 0x80, 0x02, 0xff, 0xfc, 0x90, 0x80,
 0x15, 0x00, 0x9a, 0xab, 0xbc, 0xef, 0x80, 0x06, 0xff, 0xc0, 0x00, 0xbf, 0x80, 0x4f, 0xff, 0xfe,
 0xc9, 0x80, 0x07, 0x00, 0x9c, 0xef, 0xff, 0xfe, 0xb0, 0x80, 0x0e, 0x00, 0x09, 0xaa, 0xa9, 0x99,
 0x80, 0x03, 0x00, 0x9a, 0xce, 0xee, 0x80, 0x08, 0xff, 0xb0, 0x00, 0xcf, 0x80, 0x4f, 0xff, 0xfd,
 0x80, 0x06, 0x00, 0x09, 0xac, 0xef, 0x80, 0x02, 0xff, 0xfd, 0x90, 0x80, 0x0d, 0x00, 0x0a, 0xcd,
 0xee, 0x80, 0x02, 0xdd, 0xcc, 0xbb, 0xbc, 0xde, 0x80, 0x08, 0xff, 0xfe, 0xcb, 0x90, 0x0a, 0xef,
 0x80, 0x4f, 0xff, 0xfd, 0xa9, 0x80, 0x04, 0x00, 0x99, 0xbc, 0xef, 0x80, 0x03, 0xff, 0xea, 0x80,
 0x0d, 0x00, 0x9a, 0xce, 0x80, 0x10, 0xff, 0xeb, 0x90, 0x00, 0x0c, 0x80, 0x51, 0xff, 0xec, 0xcb,
 0xaa, 0xbb, 0xbc, 0xde, 0x80, 0x05, 0xff, 0xc0, 0x80, 0x0c, 0x00, 0x9a, 0xdf, 0x80, 0x11, 0xff,
 0xb0, 0x80, 0x02, 0x00, 0xae, 0x80, 0x5c, 0xff, 0xc0, 0x80, 0x0b, 0x00, 0x09, 0xce, 0x80, 0x12,
 0xff, 0xb0, 0x00, 0x09, 0xdf, 0x80, 0x5c, 0xff, 0xb0, 0x80, 0x0b, 0x00, 0xad, 0x80, 0x13, 0xff,
 0xb0, 0x00, 0x9c, 0x80, 0x5d, 0xff, 0xb0, 0x80, 0x0a, 0x00, 0x0b, 0xef, 0x80, 0x13, 0xff, 0xda,
 0x9a, 0xcf, 0x80, 0x5d, 0xff, 0xc0, 0x80, 0x09, 0x00, 0x09, 0xcf, 0x80, 0x14, 0xff, 0xfe, 0xde,
 0x80, 0x5e, 0xff, 0xc0, 0x80, 0x09, 0x00, 0x9c, 0x80, 0x75, 0xff, 0xd9, 0x80, 0x08, 0x00, 0x9b,
 0xce, 0x80, 0x75, 0xff, 0xea, 0x80, 0x03, 0x00, 0x09, 0x80, 0x02, 0xaa, 0xab, 0xbc, 0xde, 0x80,
 0x76, 0xff, 0xec, 0x80, 0x03, 0x00, 0x0b, 0x80, 0x02, 0xee, 0xef, 0x80, 0x78, 0xff, 0xfd, 0x90,
 0x80, 0x02, 0x00, 0x0b, 0x80, 0x7b, 0xff, 0xfe, 0x90, 0x80, 0x02, 0x00, 0x09, 0xef, 0x80, 0x7a,
 0xff, 0xfe, 0xa0, 0x80, 0x02, 0x00, 0x09, 0xcf, 0x80, 0x7b, 0xff, 0xc0, 0x80, 0x03, 0x00, 0xaf,
 0x80, 0x7b, 0xff, 0xe9, 0x80, 0x03, 0x00, 0x9c, 0x80, 0x7b, 0xff, 0xfb, 0x80, 0x03, 0x00, 0x09,
 0xbc, 0xcc, 0xdf, 0x80, 0x78, 0xff, 0xfc, 0x80, 0x04, 0x00, 0x99, 0x09, 0xad, 0x80, 0x78, 0xff,
 0xfe, 0xa0, 0x80, 0x05, 0x00, 0x0c, 0x80, 0x79, 0xff, 0xda, 0x99, 0x80, 0x04, 0x00, 0x0c, 0x80,
 0x79, 0xff, 0xee, 0xed, 0xca, 0xa9, 0x99, 0x9a, 0xbe, 0x80, 0x7c, 0xff, 0x80, 0x03, 0xee, 0x80,
 0xfb, 0xff, 0x80, 0xfb, 0xff, 0x80, 0xff, 0x80, 0xff};




void main(void)
{ 

  char n=1;

  char mypalette[] = 
    {
    0, 0,0,0,
    1, 0,0,0,
    2, 0,0,0,
    3, 0,0,0,
    4, 0,0,0,
    5, 0,0,0,
    6, 0,0,0,
    7, 0,0,0,
    8, 0,0,0,
    9, 1,1,1,
    10, 2,2,2,
    11, 3,3,3,
    12, 4,4,4,
    13, 5,5,5,
    14, 6,6,6,
    15, 7,7,7
  };

  Screen(5);
  SetColors(15,0,0);
  SetSC5Palette((Palette *)mypalette);


  SetActivePage(0);
  SetDisplayPage(0);

  RleWBToRam(&cat[0],&dest[0]);   // Uncompress data to Ram

  HMMC( dest, 0, 0, 256, 73 );  // Copy RAM to VRAM

  WaitForKey();
   
  Screen(0);
	Exit(0);

}
