/*
 ___________________________________________________________
/               __           _                              \
|              / _|         (_)                             |
|             | |_ _   _ ___ _  ___  _ __                   |
|             |  _| | | / __| |/ _ \| '_ \                  |
|             | | | |_| \__ \ | (_) | | | |                 |
|             |_|  \__,_|___/_|\___/|_| |_| *               |
|                                                           |
|               The MSX C Library for SDCC                  |
|                   V1.0 - 09-10-11 2018                    |
|                                                           |
|                Eric Boez &  Fernando Garcia               |
|                                                           |
|          C   &   A S M    S O U R C E   C O D E           |
|                                                           |
|                                                           |
\___________________________________________________________/
*/
/* =============================================================================
 Sprite Reset  by Mvac. Restore All sprites data to default
============================================================================= */
#define EXPTBL  0xFCC1
#define CALSLT  0x001C
#define CLRSPR  0x0069


void SpriteReset(void)
{
__asm

  push IX
   
  ld   IX,#CLRSPR
  ld   IY,(EXPTBL-1)
  call CALSLT
  ei
    
  pop  IX
  
__endasm;
}