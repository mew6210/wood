#include "wood.h"
#include <fstream>

using namespace wood;

void basicLogs() {
	errorLog(false, "my", "app", "crashed");
	warningLog("big ", "scary ", "warning!");
	successLog("Made: ", 20, " submissions!");
	const char* name = "log";
	infoLog("very ", "informational ", name);
}

constexpr int GRAPHICS = 1;
constexpr int INTERNAL = 2;

void exLoggerLogs() {
	ExLogger logger;
	logger.addChannel(GRAPHICS, Channel("Graphics", false));
	logger.addChannel(INTERNAL, Channel("Graphics", false));

	logger.successLogChannel(INTERNAL, "logger correctly initialized");
	logger.enableTimestamps();
	logger.warningLogChannel(GRAPHICS, "drivers not found");
	Sleep(5000);
	logger.successLogChannel(GRAPHICS, "actually found", ", nevermind");
}

void logToFile() {

	ExLogger logger;
	constexpr int ALL = 3;
	logger.addChannel(3, Channel("All",false));
	std::ofstream outputFile("testing.txt");
	
	logger.changeStream(outputFile);
	logger.successLogChannel(ALL, "logging to", " file works", "!");
}

int main() {
	basicLogs();
	exLoggerLogs();
	logToFile();

	return 0;
}