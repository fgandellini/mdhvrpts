/*
 * Instance.h
 *
 *  Created on: 24/giu/2011
 *      Author: Federico Gandellini
 */

#ifndef INSTANCE_H_
#define INSTANCE_H_

#include "DataStructures.h"

class Instance {
public:
	Instance();
	virtual ~Instance();

	static string mName;

	static pCoordVector mClientsX;
	static pCoordVector mClientsY;

	static pDistanceMatrix mDistances;

	static pDistanceVector mVehicles;

	static bool Load(string filename);
	static void Clear();

	static void Print();

private:
};
typedef Instance* pInstance;

#endif /* INSTANCE_H_ */
