# wood

My logging library that will be used in my other projects.


## Usage

CMakeLists.txt:
```

FetchContent_Declare(
  wood
  GIT_REPOSITORY https://github.com/mew6210/wood.git
  GIT_TAG v${WOOD_VERSION}
)
FetchContent_MakeAvailable(wood)

add_executable(...)

target_link_libraries(${PROJECT_NAME} PRIVATE wood)
```

Basic logs:
```cpp
	errorLog(false,"my","app", "crashed");	//<-- first bool parameter decides if this errorLog should throw runtimeError after printing the message.
	warningLog("big ", "scary ", "warning!");
	successLog("Made: ", 20, " submissions!");
	const char* name = "log";
	infoLog("very ", "informational ", name);
```

Channels:

```cpp

constexpr auto GRAPHICS=1;
constexpr auto AUDIO=2;

ExLogger logger;

logger.addChannel(GRAPHICS, Channel("Graphics",false));
logger.addChannel(AUDIO, Channel("Audio", false));


std::string graphics_card = "GTX 1060";
logger.errorLogChannel(false,GRAPHICS, "failed to load firmware for this graphic card: ", graphics_card);
logger.successLogChannel(GRAPHICS, "successfully did something with gpu idk");

logger.muteChannel(AUDIO);
logger.infoLogChannel(AUDIO, "this will not show up, it");

logger.unmuteChannel(AUDIO);
logger.infoLogChannel(AUDIO, "current volume is now 10.54");
const char* text = "volume";
logger.warningLogChannel(AUDIO, "watch out thats a very loud",text);
```

See main.cpp for more examples





