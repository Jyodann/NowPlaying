# NowPlaying

## Introduction
A CLI tool that gets the information provided to `SystemMediaTransportControlsSessionManager` (SMTC) in WinRT. 

Windows uses this to display what is currently playing:

![image](https://github.com/Jyodann/NowPlaying/assets/48559311/d63bc500-2f17-444d-b49d-78620ceb5eef)

The CLI code uses `GlobalSystemMediaTransportControlsSessionManager` to check the information provided to `SystemMediaTransportControlsSessionManager` and tells you the title and artist of the currently playing media on your computer. 

![image](https://github.com/Jyodann/NowPlaying/assets/48559311/8a9588ae-12a5-4b9a-95a5-b0c35863f6c7)

 The CLI tool will update when: 
 - The Song changes
 - The source changes (i.e. you close Spotify)

## Future Plans

Currently I'm still getting the hang of C++ and especially the poorly documented WinRT documentation. This is my attempt to get song info without requiring any external services like Spotify. 
For now, I would like to focus on:

- [ ] Compling a binary for Windows Users to try
- [ ] Embedding this in [Bittify](https://github.com/Jyodann/Bittify) perhaps?
- [ ] Using MacOS's equivalent to SMTC to get music information on Mac Devices
- [ ] Optimizing memory usage (I feel like it is constantly copying a string in the while loop)
