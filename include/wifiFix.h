#ifndef __WIFIFIX_H
#define __WIFIFIX_H

#include "WiFi.h"

class WiFiClientFixed : public WiFiClient {
public:
	void flush() override;
};

#endif