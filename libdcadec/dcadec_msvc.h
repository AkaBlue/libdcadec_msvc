#pragma once

#include <intrin.h>

int __inline msvc_clz(unsigned value)
{
	unsigned long temp = 0;
	if (_BitScanReverse(&temp,value))
		return (int)(31 - temp);
	return 32;
}

int __inline msvc_clz64(unsigned long long value)
{
	unsigned long temp = 0;
#if !defined(_M_IX86)
	if (_BitScanReverse64(&temp,value))
		return (int)(63 - temp);
#else
	if (_BitScanReverse(&temp,(unsigned long)(value >> 32)))
		return (int)(63 - (temp + 32));
	if (_BitScanReverse(&temp,(unsigned long)value))
		return (int)(63 - temp);
#endif
	return 64;
}