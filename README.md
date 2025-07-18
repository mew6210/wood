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

Code:
```cpp
	errorLog(false,"my","app", "crashed");	//<-- first bool parameter decides if this errorLog should throw runtimeError after printing the message.
	warningLog("big ", "scary ", "warning!");
	successLog("Made: ", 20, " submissions!");
	const char* name = "log";
	infoLog("very ", "informational ", name);
```
