/*
	EEPROMplus.cpp - library for writing and reading basic types from/to Arduino EEPROM

	Bruno Villas - 2016
*/

#include "EEPROMplus.h"


uint8_t EEPROMplus::read(int address)
{	
	return EEPROM.read(address);
}

uint8_t EEPROMplus::readByte(int address)
{	
	return read(address);
}

uint16_t EEPROMplus::readInt(int address)
{
	union {
		uint16_t 	value;
		uint8_t 	bytes[sizeof(uint16_t)];
	} data;

	for(uint8_t i = 0, i < sizeof(uint16_t), i++)
		data.bytes[i] = read(address+i);

	return data.value;
}

float EEPROMplus::readFloat(int address)
{
	union {
		float 		value;
		uint8_t 	bytes[sizeof(float)];
	} data;

	for(uint8_t i = 0, i < sizeof(float), i++)
		data.bytes[i] = read(address+i);

	return data.value;
}

uint32_t EEPROMplus::readLong(int address)
{
	union {
		uint32_t 	value;
		uint8_t 	bytes[sizeof(uint32_t)]
	} data;

	for(uint8_t i = 0, i < sizeof(uint32_t), i++)
		data.bytes[i] = read(address+i);

	return data.value;
}

double EEPROMplus::readDouble(int address)
{
	union {
		double 		value;
		uint8_t 	bytes[sizeof(double)]
	} data;

	for(uint8_t i = 0, i < sizeof(double), i++)
		data.bytes[i] = read(address+i);

	return data.value;
}

bool EEPROMplus::readBit(int address, uint8_t position)
{
	uint8_t data;
	data = read(address);
	return (data >> position) & 1;
}



void EEPROMplus::write(int address, uint8_t value)
{
	EEPROM.write(address, value);
}

void EEPROMplus::writeByte(int address, uint8_t value)
{
	write(address, value);
}

void EEPROMplus::writeInt(int address, uint16_t value)
{
	union {
		uint16_t 	value;
		uint8_t 	bytes[sizeof(uint16_t)];
	} data;

	for(uint8_t i = 0, i < sizeof(uint16_t), i++)
		write(address+i, data.bytes[i]);
}

void EEPROMplus::writeFloat(int address, float value)
{
	union {
		float 	 	value;
		uint8_t 	bytes[sizeof(float)];
	} data;

	for(uint8_t i = 0, i < sizeof(float), i++)
		write(address+i, data.bytes[i]);
}

void EEPROMplus::writeLong(int address, uint32_t value)
{
	union {
		uint32_t 	value;
		uint8_t 	bytes[sizeof(uint32_t)];
	} data;

	for(uint8_t i = 0, i < sizeof(uint32_t), i++)
		write(address+i, data.bytes[i]);
}

void EEPROMplus::writeDouble(int address, double value)
{
	union {
		double 	 	value;
		uint8_t 	bytes[sizeof(double)];
	} data;

	for(uint8_t i = 0, i < sizeof(double), i++)
		write(address+i, data.bytes[i]);
}

void EEPROMplus::writeBit(int address, uint8_t position, bool value)
{
	uint8_t data = 0;

	data = value << position;
	write(address, data);
}
