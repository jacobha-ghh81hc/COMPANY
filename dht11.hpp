#ifndef DHT11_H
#define DHT11_H

#include<iostream>
#include<unistd.h>
#include<wiringPi.h>
#include<iomanip>
#include <bitset>
using namespace std;

#define DHT_GPIO	22
#define MIN_INTERVAL	2000 
#define TIMEOUT 	UINT32_MAX
#define F_CPU   	600000000UL


#define clockCyclesPerMicrosecond() (F_CPU / 1000000L)
#define clockCyclesToMicroseconds(a) ((a) / clockCyclesPerMicrosecond())
#define microsecondsToClockCycles(a) ((a) * clockCyclesPerMicrosecond())

class DHT11 {
public:
	uint8_t g_Data[5];

    bool readSensor (void);
    bool showData (void);
    uint32_t expectPulse (bool l_level);
};

#endif