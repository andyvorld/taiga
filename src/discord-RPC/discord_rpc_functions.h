#pragma once
#include "discord-RPC/include/discord_rpc.h"
#include <string>

namespace discord
{
  inline const char* APPLICATION_ID = "419764858976993280";

  void discordInit();
  void updateDiscordPresence(bool idling = true, const std::wstring& animeName = L"", const int episode_number = 0, const int episode_count = 0);
  void handleDiscordReady(void);
  void handleDiscordDisconnected(int errcode, const char* message);
  void handleDiscordError(int errcode, const char* message);
  void handleDiscordJoin(const char* secret);
  void handleDiscordSpectate(const char* secret);
  void handleDiscordJoinRequest(const DiscordJoinRequest* request);
} // namespace discord