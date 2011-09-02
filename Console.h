/*
 * Console.h
 *
 *  Created on: 26/lug/2011
 *      Author: Federico Gandellini
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "DataStructures.h"

class Console {
public:
	Console(int moduleVerbosityLevel);
	virtual ~Console();

	int moduleVerbosityLevel;
	void SetModuleVerbosityLevel(int moduleVerbosityLevel);

	Console* o(string message);
	Console* o(int message);
	Console* o(long message);
	Console* o(float message);
	Console* o(double message);
	Console* o(double message, int width);

	Console* n();

	static int verbosityLevel;
	static void SetVerbosityLevel(int verbosityLevel);
};
typedef Console* pConsole;

#endif /* CONSOLE_H_ */
