#include "RowColInfo.h"

RowColInfo::RowColInfo() {
    totalPoints = 0;
    totalVoltorbs = 0;
    pointsFound = 0;
    voltorbsFound = 0;
    totalTiles = 0;
    flippedTiles = 0;
}

RowColInfo::RowColInfo(int n, int tp, int tv) {
    totalPoints = tp;
    totalVoltorbs = tv;
    pointsFound = 0;
    voltorbsFound = 0;
    totalTiles = n;
    flippedTiles = 0;
}
// getters
int RowColInfo::getTotalPoints() const {
    return totalPoints;
}

int RowColInfo::getTotalVoltorbs() const {
    return totalVoltorbs;
}

int RowColInfo::getPointsFound() const {
    return pointsFound;
}

int RowColInfo::getVoltorbsFound() const {
    return voltorbsFound;
}

int RowColInfo::getTotalTiles() const {
    return totalTiles;
}

int RowColInfo::getFlippedTiles() const {
    return flippedTiles;
}
// setters
void RowColInfo::setTotalPoints(int tp) {
    totalPoints = tp;
}

void RowColInfo::setTotalVoltorbs(int tv) {
    totalVoltorbs = tv;
}

void RowColInfo::setTotalTiles(int n) {
    totalTiles = n;
}

void RowColInfo::setPointsFound(int pf) {
    pointsFound = pf;
}

void RowColInfo::setVoltorbsFound(int vf) {
    voltorbsFound = vf;
}

void RowColInfo::setFlippedTiles(int ft) {
    flippedTiles = ft;
}

void RowColInfo::addFlippedTiles(int f) {
    flippedTiles += f;
}

void RowColInfo::addPointsFound(int p) {
    pointsFound += p;
}

void RowColInfo::addVoltorbsFound(int v) {
    voltorbsFound += v;
}