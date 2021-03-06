#include "spi.h"

void SPI_init(unsigned char DORD,unsigned char CPOL){
//	SPCTL = 0x67 | DORD | CPOL;
	SPCTL = 0x63;
	SPSTAT = 0xc0;
}

void SPI_writeByte(unsigned char DAT){
	SS = 0;
  SPDAT = DAT;
	while(!(SPSTAT & 0x80));
	SPSTAT = 0xc0;
	SS = 1;
}

unsigned char readByte(){
  unsigned char DAT;
	DAT = SPDAT;
	return DAT;
}