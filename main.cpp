#include "main.h"

#define NO_SONG_PLAYING nullptr
int main() {
	// Added for Support for Unicode Characters
	system("chcp 65001");
	winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager SessionMgr(NULL);

	// Request for Global Session
	auto session_async = SessionMgr.RequestAsync();

	// Attempt await for 5 seconds:
	if (session_async.wait_for(std::chrono::seconds{ 5 }) != winrt::Windows::Foundation::AsyncStatus::Completed)
	{
		// Exit Application if cannot find a Session:
		std::cout << "Couldnt request instance of Session Manager" << std::endl;
		return 0;
	}

	// Get Result of Session:
	SessionMgr = session_async.GetResults();

	// Keep track of current song
	std::string current_song;

	while (true)
	{
		winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSession sessions
			= SessionMgr.GetCurrentSession();

		if (sessions == NO_SONG_PLAYING) continue;

		// Get Attempt to get Media Metadata
		auto playbackinfo = sessions.TryGetMediaPropertiesAsync();

		if (playbackinfo.wait_for(std::chrono::seconds{ 5 }) != winrt::Windows::Foundation::AsyncStatus::Completed) continue;

		auto info = playbackinfo.GetResults();

		std::string title = winrt::to_string(info.Title());
		std::string artist = winrt::to_string(info.Artist());

		if (current_song != title)
		{
			current_song.clear();
			current_song = title;

			//Output song if song changed:
			std::cout << current_song << " by " << artist << std::endl;
		};
	}
}