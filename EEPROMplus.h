/*
	EEPROMplus.h - header for EEPROMplus library

	Bruno Villas - 2016
*/

#ifndef EEPROMplus_h
	#define EEPROMplus_h

	#if ARDUINO >= 100
		#include <Arduino.h> 
	#else
		#include <WProgram.h> 
	#endif

	#include <EEPROM.h>
	 

	class EEPROMplus 
	{
		public:
			EEPROMplus();

			uint8_t		readByte(int);
			uint16_t 	readInt(int);
			float 		readFloat(int);
			uint32_t 	readLong(int);
			double 		readDouble(int);
			bool 		readBit(int, uint8_t);

			void	writeByte(int, uint8_t);
			void 	writeInt(int, uint16_t);
			void 	writeFloat(int, float);
			void 	writeLong(int, uint32_t);
			void 	writeDouble(int, double);
			void 	writeBit(int, uint8_t, bool);

		private:
			uint8_t 	read(int);
			uint8_t 	write(int, uint8_t);
	};

#endif