#ifndef BOARD_H
#define BOARD_H

class Board
{
public:
	enum BOARD_PIECE {PIECE_EMPTY, PIECE_X, PIECE_O};
    Board();
    void render();
    void restart();
    bool hasWinner();
    bool isDraw();
    void place(int row, int col, bool humanPiece=true);
    bool isFieldEmpty(int row, int col);
    bool isFieldCross(int row, int col);
    bool isFieldCircle(int row, int col);
    
private:
	BOARD_PIECE m[3][3];
    int occupiedPlaces;
    void renderBoard();
    void renderPieces();
    bool checkRows();
    bool checkColumns();
    bool checkDiagonals();
};

#endif