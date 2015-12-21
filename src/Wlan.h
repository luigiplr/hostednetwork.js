#pragma once
#include "stdafx.h"

namespace WlanHostedNetwork
{
	class Wlan
	{
		HANDLE _hClientHandle;
	public:
		Wlan();
		~Wlan();
		void stop();
		void start();
		WLAN_HOSTED_NETWORK_STATE getRunningState();
	};
}

