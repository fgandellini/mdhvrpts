/*
 * Settings.cpp
 *
 *  Created on: 24/giu/2011
 *      Author: fede
 */

#include "Settings.h"

string Settings::InstanceFile = "";
string Settings::OutputImageFile = "output/output.png";
int Settings::VerbosityLevel = 10;

Settings::Settings() {
}

Settings::~Settings() {
}

void Settings::ParseCommandline(int argc, char** argv) {
	try {
		TCLAP::CmdLine cmd("TabuSearch Heuristic solver for Hybrid Multi-Depot Vehicle Routing Problems", ' ', "1.0");

		TCLAP::ValueArg<string> instanceArg("i", "instance", "VRP Instance to load", true, "", "filename", cmd);
		TCLAP::ValueArg<string> outputImageArg("o", "outputimage", "Output image in png format", false, "output/output.png", "filename", cmd);
		TCLAP::ValueArg<int> verbosityLevelArg("v", "verbosity", "Verbosity level", false, 10, "level [0-9]", cmd);

		// Legge la commandline
		cmd.parse(argc, argv);

		// Inizializza le impostazioni del programma
		Settings::InstanceFile = instanceArg.getValue();
		Settings::OutputImageFile = outputImageArg.getValue();

		// Livelli di verbosità:
		// 0 - Nessun messaggio
		// 1 - Log di ...
		// 2 - Log di ...
		// 3 - Log di ...
		// 4 - Log di ...
		// 5 - Log di ...
		// 6 - Log di ...
		// 7 - Log della classe Geni
		// 8 - Log delle Neighborhoods della classe Geni
		// 9 - Log della classe GeniTour
		Settings::VerbosityLevel = verbosityLevelArg.getValue();
		Console::SetVerbosityLevel(Settings::VerbosityLevel);

	} catch (TCLAP::ArgException &e) {
		std::cerr << "Error: " << e.error() << " for argument " << e.argId() << std::endl;
	}
}
