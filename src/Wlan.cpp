#include "stdafx.h"
#include "Wlan.h"

namespace WlanHostedNetwork
{
	Wlan::Wlan()
	{
		DWORD dwNegotiatedVersion;
		WlanOpenHandle(WLAN_API_VERSION, nullptr, &dwNegotiatedVersion, &_hClientHandle);
		WLAN_HOSTED_NETWORK_REASON failReason;
		WlanHostedNetworkInitSettings(_hClientHandle, &failReason, nullptr);
	}

	Wlan::~Wlan()
	{
		WlanCloseHandle(_hClientHandle, nullptr);
	}

	WLAN_HOSTED_NETWORK_STATE Wlan::getRunningState()
	{
		PWLAN_HOSTED_NETWORK_STATUS pWlanHostedNetworkStatus = nullptr;
		WlanHostedNetworkQueryStatus(_hClientHandle, &pWlanHostedNetworkStatus, nullptr);
		auto state = pWlanHostedNetworkStatus->HostedNetworkState;
		WlanFreeMemory(pWlanHostedNetworkStatus);
		return state;
	}

	void Wlan::start()
	{
		WLAN_HOSTED_NETWORK_REASON failReason;
		WlanHostedNetworkForceStart(_hClientHandle, &failReason, nullptr);
	}

	void Wlan::stop()
	{
		WLAN_HOSTED_NETWORK_REASON failReason;
		WlanHostedNetworkForceStop(_hClientHandle, &failReason, nullptr);
	}
}

