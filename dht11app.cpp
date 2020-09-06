#include "dht11.hpp"

int main(int argc, char* argv[])
{
	DHT11 Aosong;
	bool g_checkingPoint = true;

	while (true)
	{
		g_checkingPoint = Aosong.readSensor();
		if (g_checkingPoint == false)
		{
			std::cout << "Failed 1" << std::endl;
			std::cout << "Last time Humidity: " << bitset<8>(Aosong.g_Data[0]).to_ulong() << "%" << std::endl;
  			std::cout << "Last time Temperature: " << bitset<8>(Aosong.g_Data[2]).to_ulong() << "°C" << std::endl;
		}

		g_checkingPoint = Aosong.showData();
		if (g_checkingPoint == false)
		{
			std::cout << "Failed 2" << std::endl;
			std::cout << "Last time Humidity: " << bitset<8>(Aosong.g_Data[0]).to_ulong() << "%" << std::endl;
  			std::cout << "Last time Temperature: " << bitset<8>(Aosong.g_Data[2]).to_ulong() << "°C" << std::endl;
		}
			
  		std::cout << "Humidity: " << bitset<8>(Aosong.g_Data[0]).to_ulong() << "%" << std::endl;
  		std::cout << "Temperature: " << bitset<8>(Aosong.g_Data[2]).to_ulong() << "°C" << std::endl;
  		delay (3000);
	}
}