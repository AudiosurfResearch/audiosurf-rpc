# audiosurf-rpc
Discord Rich Presence for Audiosurf in the form of a DLL. No seperate program, DLL injector or any other stuff required.

Also has an integrated WebSocket server that other programs can use to get info from the game!

# Installation
Download the latest version from the [releases page](https://github.com/RubberDuckShobe/audiosurf-rpc/releases).
Open Audiosurf's ``engine`` folder and then enter the ``channels`` folder (on a normal install it's at C:\Program Files (x86)\Steam\steamapps\common\Audiosurf\engine\channels), copy all the things from the release's .zip into there and allow Windows to overwrite the existing files.

All that's left to do is launch the game! If a command line window opens while the game is loading, that means you installed audiosurf-rpc correctly!
Have fun!

# How does it work?
It uses a proxy DLL (that's the Crypt.dll) made with [wrap_dll](https://github.com/mavenlin/wrap_dll) to load together with the game.  
From that proxy DLL, it loads the real Crypt.dll from the game (real_Crypt.dll), discord_game_sdk.dll and audiosurf-rpc.dll, the mod itself.  
Then audiosurf-rpc hooks a TagLib function (the game uses that to get the tags of the audio file) that fires everytime a song is selected and stores the title and the artist.  
It also hooks Windows' SendMessage API to get outgoing messages from [Audiosurf's WM_COPYDATA API](https://web.archive.org/web/20190219094649/http://www.audio-surf.com/forum/index.php?topic=2885.0) and registers the game _to itself_ as soon as possible with the quickstart register command (doing this because I don't have to/can't watch for incoming messages, just outcoming ones).  
It changes the presence based on the messages it gets from the game with the difference that it doesn't use the tag data from the WM_COPYDATA messages, it uses the ones from TagLib because those support unicode, have proper capitalization and don't break randomly. The game sends messages everytime the player enters the character select screen, starts playing a song or when they finish a song. That's how the mod knows what the player is doing.  
