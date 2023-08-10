#include <winrt/windows.foundation.h>
#include <winrt/windows.foundation.collections.h>
#include <winrt/windows.media.control.h>
#include <iostream>
int main() {
	system("chcp 65001");
	winrt::Windows::Media::Control::GlobalSystemMediaTransportControlsSessionManager SessionMgr(NULL);
	if (SessionMgr == NULL) {
		// gets SessionManager instance
		auto session_async = SessionMgr.RequestAsync();
		// waits 5 seconds before failure
		if (session_async.wait_for(std::chrono::seconds{ 5 }) == winrt::Windows::Foundation::AsyncStatus::Completed) {
			SessionMgr = session_async.GetResults();
		}
		else {
			std::cout << "Couldnt request instance of Session Manager" << std::endl;
		}
	}
	std::string current_song;
	while (true)
	{
		auto sessions = SessionMgr.GetCurrentSession();
		if (sessions == nullptr) continue;

		auto playbackinfo = sessions.TryGetMediaPropertiesAsync();

		if (playbackinfo.wait_for(std::chrono::seconds{ 5 }) == winrt::Windows::Foundation::AsyncStatus::Completed) {
			auto info = playbackinfo.GetResults();
			std::string title = winrt::to_string(info.Title());
			std::string artist = winrt::to_string(info.Artist());

			if (current_song != title)
			{
				current_song.clear();
				current_song = title;

				std::cout << current_song << " by " << artist << std::endl;
			};
		}
	}
}