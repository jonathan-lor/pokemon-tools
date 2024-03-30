#ifndef ROWCOLINFO_H
#define ROWCOLINFO_H

class RowColInfo {
private:
    int totalPoints;
    int totalVoltorbs;
    int pointsFound;
    int voltorbsFound;
    int totalTiles; // this is just size of board, n
    // rowCol info needs knowledge of board size ?
    int flippedTiles;
public:
    RowColInfo();
    RowColInfo(int n, int tp, int tv);

    int getTotalPoints() const;
    int getTotalVoltorbs() const;
    int getPointsFound() const;
    int getVoltorbsFound() const;
    int getTotalTiles() const;
    int getFlippedTiles() const;

    void setTotalPoints(int tp);
    void setTotalVoltorbs(int tv);
    void setTotalTiles(int n);
    void setPointsFound(int pf);
    void setVoltorbsFound(int vf);
    void setFlippedTiles(int ft);
};

#endif