#include "wood.h"

struct Foo{};

int main() {
	
	errorLog(false,"my","app", "crashed");
	warningLog("big ", "scary ", "warning!");
	successLog("Made: ", 20, " submissions!");
	const char* name = "log";
	infoLog("very ", "informational ", name);
	return 0;
}