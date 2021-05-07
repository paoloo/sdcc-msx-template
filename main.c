#include "targetconfig.h"
#include "MSX/BIOS/msxbios.h"
#include "msx_fusion.h"

#pragma disable_warning 85	// because the var msg is not used in C context
void _print(char* msg) {
__asm
	ld      hl, #2			; retrieve address from stack
	add     hl, sp
	ld		b, (hl)
	inc		hl
	ld		h, (hl)
	ld		l, b

_printMSG_loop :
	ld		a, (hl)			; print
	or		a
	ret z
	call	0x00a2			; BIOS_CHPUT
	inc		hl
	jr		_printMSG_loop
__endasm;

	return;
}

char* ____func_param_parser(char** data){
    char buffer[0xff];
	unsigned int i=0;
	if (**data != '(') { return  (unsigned char *)-1; }
	(*data)++;
	if (**data != '"') { return  (unsigned char *)-1; }
	(*data)++;
	while (**data != '"') {
		buffer[i++] = **data;
		(*data)++;
	}
	buffer[i] = 0;
	(*data)++;
	if (**data != ')') { return  (unsigned char *)-1; }
	(*data)++;
	// seek end of command (0x00/EoL ou 0x3a/":")
	while (**data == ' ') { (*data)++; }
	if ((**data != 0) && (**data != 0x3a)) { return (unsigned char *)-1; }
    return buffer;
}

unsigned char onCallCMD1(char** param) {
    char* _param = ____func_param_parser(param);
	_print("The C handler for CMD1 says: \0");
	_print(_param);
	_print("\r\n\0");
	return 0;
}

unsigned char onCallCMD2(char** param) {
	// check no parameters (next char must be 0x00/EoL ou 0x3a/":")
	if ((**param != 0) && (**param != 0x3a)) {
		return -1;
	}
	_print("The C handler for CMD2 says hi!\r\n\0");
	return 0;
}

char onDeviceDEV_getId() {
	_print("The C handler for DEV_getId says hi!\r\n\0");
	return 0;
}

void onDeviceDEV_IO(char* param, char cmd) {
	_print("The C handler for DEV_IO says hi!\r\n\0");
}

void main(void) {
	Screen(2);
	Width(36);
	_print("Hello MSX from C!\r\n"
		"If you don't want your\r\n"
		"ROM program to return to\r\n"
		"BASIC/MSX-DOS, just avoid\r\n"
		"main's return instruction.\r\n\0");
}
