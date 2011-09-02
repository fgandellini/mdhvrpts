/*
 * DataStructures.h
 *
 *  Created on: 24/giu/2011
 *      Author: Federico Gandellini
 */

#ifndef DATASTRUCTURES_H_
#define DATASTRUCTURES_H_

#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include <cassert>
#include <string>
#include <algorithm>
#include <iomanip>
#include <limits>

using namespace std;

#define PI 3.14159265

// Coordinate
typedef double Coord;
typedef vector<Coord> CoordVector;
typedef CoordVector* pCoordVector;

// Cost
typedef double Cost;
typedef vector<Cost> CostVector;
typedef CostVector* pCostVector;

// Profit
typedef int Profit;
typedef vector<Profit> ProfitVector;
typedef ProfitVector* pProfitVector;

// Distance
typedef double Distance;
typedef vector<Distance> DistanceVector;
typedef DistanceVector* pDistanceVector;
typedef vector< pDistanceVector > DistanceMatrix;
typedef DistanceMatrix* pDistanceMatrix;
#define INF_DISTANCE numeric_limits<Distance>::max()

// Angle
typedef double Angle;

// ID
typedef int Id;
typedef Id* pId;
typedef vector<Id> IdVector;
typedef IdVector* pIdVector;
typedef vector< pIdVector > IdMatrix;
typedef IdMatrix* pIdMatrix;

// Arcs
typedef vector<bool> ArcVector;
typedef ArcVector* pArcVector;
typedef vector< pArcVector > ArcMatrix;
typedef ArcMatrix* pArcMatrix;

// Tour
typedef vector<Id> Tour;
typedef Tour* pTour;

#endif /* DATASTRUCTURES_H_ */
