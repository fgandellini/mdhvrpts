/*
 * Instance.cpp
 *
 *  Created on: 24/giu/2011
 *      Author: Federico Gandellini
 */

#include "Instance.h"

string Instance::mName = "EmptyInstance";
pCoordVector Instance::mClientsX = new CoordVector();
pCoordVector Instance::mClientsY = new CoordVector();
pDistanceMatrix Instance::mDistances = new DistanceMatrix();
pDistanceVector Instance::mVehicles = new DistanceVector();

Instance::Instance() {
	/*Instance::mName = "EmptyInstance";

	Instance::mClientsX = new CoordVector();
	Instance::mClientsY = new CoordVector();

	Instance::mDistances = new DistanceMatrix();

    Instance::mVehicles = new DistanceVector();*/
}

Instance::~Instance() {
	/*
	if (Instance::mClientsX != NULL) {
		Instance::mClientsX->clear();
		delete Instance::mClientsX;
		Instance::mClientsX = NULL;
	}
	if (Instance::mClientsY != NULL) {
		Instance::mClientsY->clear();
		delete Instance::mClientsY;
		Instance::mClientsY = NULL;
	}

	if (Instance::mDistances != NULL) {
		for (int i=0; i<(int)Instance::mDistances->size(); ++i) {
			Instance::mDistances->at(i)->clear();
			delete Instance::mDistances->at(i);
			Instance::mDistances->at(i) = NULL;
		}
		Instance::mDistances->clear();
		delete Instance::mDistances;
		Instance::mDistances = NULL;
	}

	if (Instance::mVehicles != NULL) {
		Instance::mVehicles->clear();
		delete Instance::mVehicles;
		Instance::mVehicles = NULL;
	}
	*/
}

void Instance::Clear() {
	if (Instance::mClientsX != NULL) {
		Instance::mClientsX->clear();
		delete Instance::mClientsX;
		Instance::mClientsX = NULL;
	}
	if (Instance::mClientsY != NULL) {
		Instance::mClientsY->clear();
		delete Instance::mClientsY;
		Instance::mClientsY = NULL;
	}

	if (Instance::mDistances != NULL) {
		for (int i=0; i<(int)Instance::mDistances->size(); ++i) {
			Instance::mDistances->at(i)->clear();
			delete Instance::mDistances->at(i);
			Instance::mDistances->at(i) = NULL;
		}
		Instance::mDistances->clear();
		delete Instance::mDistances;
		Instance::mDistances = NULL;
	}

	if (Instance::mVehicles != NULL) {
		Instance::mVehicles->clear();
		delete Instance::mVehicles;
		Instance::mVehicles = NULL;
	}
}

bool Instance::Load(string filename) {
    string dummyStr;

    ifstream indata(filename.c_str(), fstream::in);

	if (indata) {

		Instance::mName = filename;

		// NUMBER OF BASIS: basis
		int basis = 0;
		indata >> dummyStr >> dummyStr >> dummyStr >> basis;

		// NUMBER OF SITES: sites
		int sites = 0;
		indata >> dummyStr >> dummyStr >> dummyStr >> sites;

		// BUDGET: mBudget
		indata >> dummyStr >> dummyStr;

		// Alloca lo spazio per le strutture
		Instance::mVehicles->reserve(2);

		Instance::mClientsX->reserve(basis + sites);
		Instance::mClientsY->reserve(basis + sites);

		int id;
		Coord x, y;
		Profit profit;
		Cost cost;
		Distance d;
		for (int v=0; v<2; ++v) {
			indata >> id >> d;
			Instance::mVehicles->push_back(d);
		}
		for (int b=0; b<basis; ++b) {
			indata >> id >> x >> y;
			Instance::mClientsX->push_back(x);
			Instance::mClientsY->push_back(y);
		}
		for (int s=0; s<sites; ++s) {
			indata >> id >> x >> y; // >> profit >> cost;
			Instance::mClientsX->push_back(x);
			Instance::mClientsY->push_back(y);
		}

		// Costruisce la matrice delle distanze
		int locations = basis + sites;
		Instance::mDistances->reserve(locations);
		for (int i=0; i<locations; ++i) {
			Instance::mDistances->push_back(new DistanceVector(locations, 0));
		}

		// Calcola le distanze tra i clienti
		for (int i=0; i<locations; ++i) {
			for (int j=0; j<locations; ++j) {
				Distance xi, xj, yi, yj;
				xi = (Distance)Instance::mClientsX->at(i);
				yi = (Distance)Instance::mClientsY->at(i);
				xj = (Distance)Instance::mClientsX->at(j);
				yj = (Distance)Instance::mClientsY->at(j);
				Distance xx = ( (xi - xj) * (xi - xj) );
				Distance yy = ( (yi - yj) * (yi - yj) );
				Distance d = sqrt(xx + yy);
				Instance::mDistances->at(i)->at(j) = d;
			}
		}

		indata.close();

		return true;
	}
	return false;
}

void Instance::Print() {
	cout << "Instance: " << Instance::mName << endl;
	cout << "Distances:" << endl;
    int locations = Instance::mDistances->size();
    for (int i=0; i<locations; ++i) {
    	for (int j=0; j<locations; ++j) {
			cout << right << setw(6) << setiosflags(ios::fixed) << setprecision(1) << Instance::mDistances->at(i)->at(j);
			(j < (locations-1)) ? cout << "\t" : cout << endl;
    	}
    }
    cout << endl;
}
