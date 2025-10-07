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
constexpr int TESTING = 3;

void exLoggerLogs() {
	ExLogger logger;
	logger.addChannel(GRAPHICS, Channel("Graphics", false));
	logger.addChannel(INTERNAL, Channel("Internal", false));

	logger.successLogChannel(INTERNAL, "logger correctly initialized");
	logger.setTimestamps(true);
	logger.warningLogChannel(GRAPHICS, "drivers not found");
	Sleep(5000);
	logger.successLogChannel(GRAPHICS, "actually found", ", nevermind");
}

void logToFile() {

	ExLogger logger;
	logger.addChannel(TESTING, Channel("Testing",false));
	std::ofstream outputFile("testing.txt");
	
	logger.setStream(outputFile);
	logger.successLogChannel(TESTING, "logging to", " file works", "!");
}

int main() {
	basicLogs();
	exLoggerLogs();
	logToFile();

	return 0;
}