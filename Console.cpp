/*
 * Console.cpp
 *
 *  Created on: 26/lug/2011
 *      Author: fede
 */

#include "Console.h"

int Console::verbosityLevel = 0;

Console::Console(int moduleVerbosityLevel) {
	this->SetModuleVerbosityLevel(moduleVerbosityLevel);
}

Console::~Console() {
	// TODO Auto-generated destructor stub
}

void Console::SetModuleVerbosityLevel(int moduleVerbosityLevel) {
	this->moduleVerbosityLevel = moduleVerbosityLevel;
}

void Console::SetVerbosityLevel(int verbosityLevel) {
	Console::verbosityLevel = verbosityLevel;
}

pConsole Console::o(string message) {
	if (verbosityLevel >= moduleVerbosityLevel) {
		cout << message;
	}
	return this;
}

pConsole Console::o(int message) {
	if (verbosityLevel >= moduleVerbosityLevel) {
		cout << message;
	}
	return this;
}

pConsole Console::o(long message) {
	if (verbosityLevel >= moduleVerbosityLevel) {
		cout << message;
	}
	return this;
}

pConsole Console::o(float message) {
	if (verbosityLevel >= moduleVerbosityLevel) {
		cout << message;
	}
	return this;
}

pConsole Console::o(double message) {
	if (verbosityLevel >= moduleVerbosityLevel) {
		cout << message;
	}
	return this;
}

pConsole Console::o(double message, int width) {
	if (verbosityLevel >= moduleVerbosityLevel) {
		cout << setw(width) << message;
	}
	return this;
}

pConsole Console::n() {
	if (verbosityLevel >= moduleVerbosityLevel) {
		cout << endl;
	}
	return this;
}
