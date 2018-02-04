#include <stdio.h>
#include <tins/tins.h>
#include <unistd.h>

using namespace Tins;

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		printf("Usage: %s [interface] [ssid]\n", argv[0]);
		return 0;
	}
	Dot11Beacon beacon;
	beacon.addr1(Dot11::BROADCAST);
	beacon.addr2("00:01:02:03:04:05");
	beacon.addr3(beacon.addr2());
	beacon.ssid(argv[2]);
	beacon.ds_parameter_set(8);
	beacon.supported_rates({1.0f, 5.5f, 11.0f});
	beacon.rsn_information(RSNInformation::wpa2_psk());
	
	PacketSender sender;
	RadioTap radio = RadioTap() / beacon;
	for (int i = 1; ; i++)
	{
		printf("send ssid: %s (count: %d)\n", argv[2], i);
		sender.send(radio, argv[1]);
		usleep(150000);
	}
    return 0;
}