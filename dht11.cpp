#include "dht11.hpp"

bool DHT11::readSensor (void)
{
	// Init the wiringPi library
    wiringPiSetupGpio();
    piHiPri(99);

	// Reset 40 bits of received data to zero.
    g_Data[0] = g_Data[1] = g_Data[2] = g_Data[3] = g_Data[4] = 0;

	/*MCU sends out start signal and pulls down voltage DHT_GPIO for at least 18ms to let DHT11 detect the start signal*/
    pinMode(DHT_GPIO, OUTPUT);
    digitalWrite(DHT_GPIO, LOW);
	usleep(18000); // at least 18ms as the DHT11 specification

	// NEED TO IGNORE THE FIRST AND SECOND HIGH AFTER GOING LOW

	/*MCU pulls up the voltage DHT_GPIO*/
	digitalWrite(DHT_GPIO, HIGH);
	/*From this point of time, DHT_GPIO is input mode to let MCU reads the DHT11 response*/
    pinMode(DHT_GPIO, INPUT);
	/*MCU waits for DHT11 response 20-40us*/
    do { delayMicroseconds(1); } while(digitalRead(DHT_GPIO)==HIGH);
	/*DHT11 sends out response signal and keeps it for 80us*/
    do { delayMicroseconds(1); } while(digitalRead(DHT_GPIO)==LOW);
	/*DHT11 pulls up voltage DHT_GPIO and keeps it for 80us*/
    do { delayMicroseconds(1); } while(digitalRead(DHT_GPIO)==HIGH);

	/*Now read the 40 bits sent by the sensor.  Each bit is sent as a 50
    microsecond low pulse followed by a variable length high pulse.  If the
    high pulse is ~28 microseconds then it's a 0 and if it's ~70 microseconds
    then it's a 1.  We measure the cycle count of the initial 50us low pulse
    and use that to compare to the cycle count of the high pulse to determine
    if the bit is a 0 (high state cycle count < low state cycle count), or a
    1 (high state cycle count > low state cycle count). Note that for speed
    all the pulses are read into a array and then examined in a later step.*/

	uint32_t l_matrix[2][8][5];
	{
		for (uint8_t arrays = 0; arrays < 5; arrays++)
		{
			for (uint8_t columns = 0; columns < 8; columns++)
			{
				l_matrix[0][columns][arrays] = expectPulse(LOW);
				l_matrix[1][columns][arrays] = expectPulse(HIGH);
				if ((l_matrix[0][columns][arrays] == TIMEOUT) || (l_matrix[1][columns][arrays] == TIMEOUT))
				{
					std::cout << "DHT11 timeout waiting for pulse." << std::endl;
					return false;
				}
				/*Inspect pulses and determine which ones are 0 (high state cycle count < low state cycle count), or 1 (high state cycle count > low state cycle count)*/
				g_Data[arrays] = g_Data[arrays] | ((l_matrix[1][columns][arrays] > l_matrix[0][columns][arrays]) << (7-columns));
			}
		}
	}
	return true;
}

bool DHT11::showData (void)
{
	std::cout << "Received from DHT11: " << endl;
	for (uint8_t view = 0; view < 5; view++)
	{
		std::cout << bitset<8>(g_Data[view]).to_ulong() << "--->";
      	std::cout << bitset<8>(g_Data[view]).to_string() << "	";
    }
    std::cout << endl;

	std::cout << "Calculated checksum from DHT11: " << bitset<8>((g_Data[0] + g_Data[1] + g_Data[2] + g_Data[3]) & 0xFF).to_ulong();
	std::cout << "--->" << bitset<8>((g_Data[0] + g_Data[1] + g_Data[2] + g_Data[3]) & 0xFF).to_string() << endl;
	return (g_Data[4] == ((g_Data[0] + g_Data[1] + g_Data[2] + g_Data[3]) & 0xFF));
}

uint32_t DHT11::expectPulse (bool l_level)
{
	uint32_t l_count = 0, l_maxcycles = microsecondsToClockCycles(1000);
	while (digitalRead(DHT_GPIO) == l_level)
	{
    	if (l_count++ >= l_maxcycles) return TIMEOUT;
	}
	return l_count;
}