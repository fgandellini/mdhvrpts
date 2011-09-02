/*
 * Settings.h
 *
 *  Created on: 24/giu/2011
 *      Author: fede
 */

#ifndef SETTINGS_H_
#define SETTINGS_H_

#include "DataStructures.h"
#include "tclap/CmdLine.h"
#include "Console.h"

class Settings {
public:
	Settings();
	virtual ~Settings();

	static string InstanceFile;
	static string OutputImageFile;

	static int VerbosityLevel;

	static void ParseCommandline(int argc, char** argv);
};

#endif /* SETTINGS_H_ */
