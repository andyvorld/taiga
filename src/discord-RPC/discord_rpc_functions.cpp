#include "discord-RPC/discord_rpc_functions.h"
#include <string>
#include <ctime>

namespace discord
{
  void discordInit()
  {
    DiscordEventHandlers handlers;
    memset(&handlers, 0, sizeof(handlers));
    handlers.ready = handleDiscordReady;
    handlers.disconnected = handleDiscordDisconnected;
    handlers.errored = handleDiscordError;
    handlers.joinGame = handleDiscordJoin;
    handlers.spectateGame = handleDiscordSpectate;
    handlers.joinRequest = handleDiscordJoinRequest;
    Discord_Initialize(APPLICATION_ID, &handlers, 1, NULL);
  }

  //void updateDiscordPresence()
  //{
  //  DiscordRichPresence discordPresence;
  //  memset(&discordPresence, 0, sizeof(discordPresence));
  //  discordPresence.state = "Taiga Discord Test";
  //  discordPresence.details = "Watching something";
  //  Discord_UpdatePresence(&discordPresence);
  //}
  void updateDiscordPresence(bool idling, const std::wstring& anime_name, const int episode_number, const int episode_count)
  {
   
    //discordPresence.state = "Taiga Discord Test";
    //discordPresence.details = "Watching something";

    if (idling)
    {
      Discord_ClearPresence();
    }
    else
    {
      DiscordRichPresence discordPresence;
      memset(&discordPresence, 0, sizeof(discordPresence));
      size_t anime_name_len = anime_name.size() + (size_t) 1;
      char* tmpString = new char[anime_name_len];
      sprintf_s(tmpString, sizeof(char) * anime_name_len, "%ls", anime_name.c_str());
      discordPresence.details = tmpString;
      char* state = new char[255];
      if (episode_count == 0)
      {
        sprintf_s(state, sizeof(char) * 255, "Episode %d", episode_number);
      }
      else
      {
        sprintf_s(state, sizeof(char) * 255, "Episode %d of %d", episode_number, episode_count);
      }
      discordPresence.state = state;
      discordPresence.startTimestamp = time(0);
      Discord_UpdatePresence(&discordPresence);

    }

  }

  static void handleDiscordReady(void)
  {
    printf("\nDiscord: ready\n");
  }

  static void handleDiscordDisconnected(int errcode, const char* message)
  {
    printf("\nDiscord: disconnected (%d: %s)\n", errcode, message);
  }

  static void handleDiscordError(int errcode, const char* message)
  {
    printf("\nDiscord: error (%d: %s)\n", errcode, message);
  }

  static void handleDiscordJoin(const char* secret)
  {
    printf("\nDiscord: join (%s)\n", secret);
  }

  static void handleDiscordSpectate(const char* secret)
  {
    printf("\nDiscord: spectate (%s)\n", secret);
  }

  static void handleDiscordJoinRequest(const DiscordJoinRequest* request)
  {

  }
} // namespace discord