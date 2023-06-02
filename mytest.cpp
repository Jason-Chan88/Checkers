#include "checkers.h"
using namespace std;
class Tester {
public:
    // The following is implemented as a sample test function.
    // This function tests whether the function play(...) performs
    //  a capturing move successfully or not.
    // Please note, before calling this test function we have set
    //  the state of the game to a certain state
    // Moreover note, After calling this test function the state
    //  of the of the game will change
    bool testCaptureSuccess(Checkers &checkers) {
        bool result = true;
        // before play we expect a BCELL in (3,2)
        result = result && (checkers.m_game[3][2] == BCELL);
        // before play we expect a WDISK in (1,4)
        result = result && (checkers.m_game[1][4] == WDISK);
        // before play we expect that it is WPLAYER turn to play
        result = result && (checkers.m_currPlayer == WPLAYER);
        // before play we expect a BDISK in (2,3), there is an opponent disk
        result = result && (checkers.m_game[2][3] == BDISK);
        // store the ccurrent opponent number if disks
        int opponentDisks = checkers.m_blackDisks;
        // now call the play(...) function
        result = checkers.play(pair<int, int>(1, 4), pair<int, int>(3, 2));
        // we are trying to move (1,4) to (3,2), we expect that move is successful
        // after play we expect a BCELL in (1,4)
        result = result && (checkers.m_game[1][4] == BCELL);
        // after play we expect a WDISK in (3,2)
        result = result && (checkers.m_game[3][2] == WDISK);
        // after play we expect that it is BPLAYER turn
        result = result && (checkers.m_currPlayer == BPLAYER);
        // after play we expect a BCELL in (2,3), an opponent disk is captured
        result = result && (checkers.m_game[2][3] == BCELL);
        // after play we expect one less disk for the opponent
        result = result && (checkers.m_blackDisks == (opponentDisks - 1));
        return result;
    }

    /******************************************
    * Test function declarations go here! *
    ******************************************/

    bool testEightByEight(Checkers &checkers) { // testing 8 by 8 want to succeed
        bool result = true;
        if (checkers.m_numRows >= 8 && checkers.m_numColumns >= 8) {
            cout << "test success" << endl;
            checkers.initBoard();
            
            checkers.initGame();
            
            cout << checkers.m_numColumns << endl;
            cout << checkers.m_numRows << endl;
            cout << checkers.m_blackDisks << endl;
            cout << checkers.m_whiteDisks << endl;
            cout << checkers.m_currPlayer << endl;
            result = true;
        } else {
            cout << "test fail" << endl;
            cout << checkers.m_numColumns << endl;
            cout << checkers.m_numRows << endl;
            cout << checkers.m_blackDisks << endl;
            cout << checkers.m_whiteDisks << endl;
            cout << checkers.m_currPlayer << endl;
            result = false;
        }
        return result;
    }

    bool testSixBySix(Checkers &checkers) { // testing 6 by 6 want to fail, should be empty object
        bool result = true;
        if (checkers.m_numRows >= 8 && checkers.m_numColumns >= 8) {
            cout << "test success" << endl;
            checkers.initBoard();
            
            checkers.initGame();
            
            cout << checkers.m_numColumns << endl;
            cout << checkers.m_numRows << endl;
            cout << checkers.m_blackDisks << endl;
            cout << checkers.m_whiteDisks << endl;
            cout << checkers.m_currPlayer << endl;
            result = true;
        } else {
            cout << "test fail" << endl;
            cout << checkers.m_numColumns << endl;
            cout << checkers.m_numRows << endl;
            cout << checkers.m_blackDisks << endl;
            cout << checkers.m_whiteDisks << endl;
            cout << checkers.m_currPlayer << endl;
            result = false;
        }
        return result;
    }

    bool testTenByTen(Checkers &checkers) { // testing 10 by 10 want to succeed
        bool result = true;
        if (checkers.m_numRows >= 8 && checkers.m_numColumns >= 8) {
            cout << "test success" << endl;
            checkers.initBoard();
            
            checkers.initGame();
            
            cout << checkers.m_numColumns << endl;
            cout << checkers.m_numRows << endl;
            cout << checkers.m_blackDisks << endl;
            cout << checkers.m_whiteDisks << endl;
            cout << checkers.m_currPlayer << endl;
            result = true;
        } else {
            cout << "test fail" << endl;
            cout << checkers.m_numColumns << endl;
            cout << checkers.m_numRows << endl;
            cout << checkers.m_blackDisks << endl;
            cout << checkers.m_whiteDisks << endl;
            cout << checkers.m_currPlayer << endl;
            result = false;
        }
        return result;
    }

    bool testFiveByTen(Checkers &checkers) { // testing -5 by -10 want to fail, should be empty
        bool result = true;
        if (checkers.m_numRows >= 8 && checkers.m_numColumns >= 8) {
            cout << "test success" << endl;
            checkers.initBoard();
            
            checkers.initGame();
            
            cout << checkers.m_numColumns << endl;
            cout << checkers.m_numRows << endl;
            cout << checkers.m_blackDisks << endl;
            cout << checkers.m_whiteDisks << endl;
            cout << checkers.m_currPlayer << endl;
            result = true;
        } else {
            cout << "test fail" << endl;
            cout << checkers.m_numColumns << endl;
            cout << checkers.m_numRows << endl;
            cout << checkers.m_blackDisks << endl;
            cout << checkers.m_whiteDisks << endl;
            cout << checkers.m_currPlayer << endl;
            result = false;
        }
        return result;
    }

    bool testNineByNine(Checkers &checkers) { // testing 9 by 10 want to fail should be empty
        bool result = true;
        if (checkers.m_numRows >= 8 && checkers.m_numColumns >= 8) {
            cout << "test success" << endl;
            checkers.initBoard();
            
            checkers.initGame();
            
            cout << checkers.m_numColumns << endl;
            cout << checkers.m_numRows << endl;
            cout << checkers.m_blackDisks << endl;
            cout << checkers.m_whiteDisks << endl;
            cout << checkers.m_currPlayer << endl;
            result = true;
        } else {
            cout << "test fail" << endl;
            cout << checkers.m_numColumns << endl;
            cout << checkers.m_numRows << endl;
            cout << checkers.m_blackDisks << endl;
            cout << checkers.m_whiteDisks << endl;
            cout << checkers.m_currPlayer << endl;
            result = false;
        }
        return result;
    }

    bool testEightByNine(Checkers &checkers) { // testing 8 by 9 want to fail
        bool result = true;
        if (checkers.m_numRows >= 8 && checkers.m_numColumns >= 8) {
            cout << "test success" << endl;
            checkers.initBoard();
            
            checkers.initGame();
            
            cout << checkers.m_numColumns << endl;
            cout << checkers.m_numRows << endl;
            cout << checkers.m_blackDisks << endl;
            cout << checkers.m_whiteDisks << endl;
            cout << checkers.m_currPlayer << endl;
            result = true;
        } else {
            cout << "test fail" << endl;
            cout << checkers.m_numColumns << endl;
            cout << checkers.m_numRows << endl;
            cout << checkers.m_blackDisks << endl;
            cout << checkers.m_whiteDisks << endl;
            cout << checkers.m_currPlayer << endl;
            result = false;
        }
        return result;
    }

    bool testMemoryObjectEightByEight(Checkers &checkers) { // testing empty object with constructor
        if (checkers.m_game != nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool testMemoryObjectSixBySix(Checkers &checkers) { // testing empty object with constructor
        if (checkers.m_game != nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool testMemoryObjectTenByTen(Checkers &checkers) { // testing empty object with constructor
        if (checkers.m_game != nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool testMemoryObjectFiveByTen(Checkers &checkers) { // testing empty object with constructor
        if (checkers.m_game != nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool testMemoryObjectNineByNine(Checkers &checkers) { // testing empty object with constructor
        if (checkers.m_game != nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool testMemoryObjectEightByNine(Checkers &checkers) { // testing empty object with constructor
        if (checkers.m_game != nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool testBuildBoardEightByEight(Checkers &checkers) { // test if an object can be made into a board
        if (checkers.m_game != nullptr) {
            checkers.initBoard();
            
            for (int i = 0; i < checkers.m_numRows; i++) {
                for (int j = 0; j < checkers.m_numColumns; j++) {
                    if ((i + j) % 2 != 0) {
                        if (checkers.m_game[i][j] != BCELL) { // if a spot is supose to be a black cell but isn't than fail
                            return false;
                        }
                    } else {
                        if (checkers.m_game[i][j] != WCELL) {
                            return false;
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool testBuildBoardSixBySix(Checkers &checkers) { // test if an object can be made into a board
        if (checkers.m_game != nullptr) {
            checkers.initBoard();
            
            for (int i = 0; i < checkers.m_numRows; i++) {
                for (int j = 0; j < checkers.m_numColumns; j++) {
                    if ((i + j) % 2 != 0) {
                        if (checkers.m_game[i][j] != BCELL) {
                            return false;
                        }
                    } else {
                        if (checkers.m_game[i][j] != WCELL) {
                            return false;
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool testBuildBoardTenByTen(Checkers &checkers) { // test if an object can be made into a board
        if (checkers.m_game != nullptr) {
            checkers.initBoard();
            
            for (int i = 0; i < checkers.m_numRows; i++) {
                for (int j = 0; j < checkers.m_numColumns; j++) {
                    if ((i + j) % 2 != 0) {
                        if (checkers.m_game[i][j] != BCELL) {
                            return false;
                        }
                    } else {
                        if (checkers.m_game[i][j] != WCELL) {
                            return false;
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool testBuildBoardFiveByTen(Checkers &checkers) { // test if an object can be made into a board
        if (checkers.m_game != nullptr) {
            checkers.initBoard();
            
            for (int i = 0; i < checkers.m_numRows; i++) {
                for (int j = 0; j < checkers.m_numColumns; j++) {
                    if ((i + j) % 2 != 0) {
                        if (checkers.m_game[i][j] != BCELL) {
                            return false;
                        }
                    } else {
                        if (checkers.m_game[i][j] != WCELL) {
                            return false;
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool testBuildBoardNineByNine(Checkers &checkers) { // test if an object can be made into a board
        if (checkers.m_game != nullptr) {
            checkers.initBoard();
            
            for (int i = 0; i < checkers.m_numRows; i++) {
                for (int j = 0; j < checkers.m_numColumns; j++) {
                    if ((i + j) % 2 != 0) {
                        if (checkers.m_game[i][j] != BCELL) {
                            return false;
                        }
                    } else {
                        if (checkers.m_game[i][j] != WCELL) {
                            return false;
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool testBuildBoardEightByNine(Checkers &checkers) { // test if an object can be made into a board
        if (checkers.m_game != nullptr) {
            checkers.initBoard();
            
            for (int i = 0; i < checkers.m_numRows; i++) {
                for (int j = 0; j < checkers.m_numColumns; j++) {
                    if ((i + j) % 2 != 0) {
                        if (checkers.m_game[i][j] != BCELL) {
                            return false;
                        }
                    } else {
                        if (checkers.m_game[i][j] != WCELL) {
                            return false;
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }
        // test if the piece are placed correctly on board
    bool testPiecePlacementEightByEight(Checkers &checkers) {
        if (checkers.m_game != nullptr && testBuildBoardEightByEight(checkers)) {
            checkers.initGame();
            

            if (checkers.m_currPlayer != BPLAYER) {
                return false;
            }
            // use nested for loop to check in position equal the right disk
            for (int i = 0; i < checkers.m_numRows; i++) {
                for (int j = 0; j < checkers.m_numColumns; j++) {
                    if ((checkers.m_numColumns % 2) == (checkers.m_numRows % 2)) {
                        if (i == 0) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 3) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        }
                    }
                    if ((checkers.m_numColumns % 2) != (checkers.m_numRows % 2)) {
                        if (i == 0) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 3) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 2) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 1) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool testPiecePlacementSixBySix(Checkers &checkers) {
        if (checkers.m_game != nullptr && testBuildBoardSixBySix(checkers)) {
            checkers.initGame();
            

            if (checkers.m_currPlayer != BPLAYER) {
                return false;
            }

            for (int i = 0; i < checkers.m_numRows; i++) {
                for (int j = 0; j < checkers.m_numColumns; j++) {
                    if ((checkers.m_numColumns % 2) == (checkers.m_numRows % 2)) {
                        if (i == 0) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 3) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        }
                    }
                    if ((checkers.m_numColumns % 2) != (checkers.m_numRows % 2)) {
                        if (i == 0) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 3) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 2) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 1) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool testPiecePlacementTenByTen(Checkers &checkers) {
        if (checkers.m_game != nullptr && testBuildBoardTenByTen(checkers)) {
            checkers.initGame();
            

            if (checkers.m_currPlayer != BPLAYER) {
                return false;
            }

            for (int i = 0; i < checkers.m_numRows; i++) {
                for (int j = 0; j < checkers.m_numColumns; j++) {
                    if ((checkers.m_numColumns % 2) == (checkers.m_numRows % 2)) {
                        if (i == 0) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 3) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        }
                    }
                    if ((checkers.m_numColumns % 2) != (checkers.m_numRows % 2)) {
                        if (i == 0) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 3) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 2) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 1) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool testPiecePlacementFiveByTen(Checkers &checkers) {
        if (checkers.m_game != nullptr && testBuildBoardFiveByTen(checkers)) {
            checkers.initGame();
            

            if (checkers.m_currPlayer != BPLAYER) {
                return false;
            }

            for (int i = 0; i < checkers.m_numRows; i++) {
                for (int j = 0; j < checkers.m_numColumns; j++) {
                    if ((checkers.m_numColumns % 2) == (checkers.m_numRows % 2)) {
                        if (i == 0) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 3) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        }
                    }
                    if ((checkers.m_numColumns % 2) != (checkers.m_numRows % 2)) {
                        if (i == 0) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 3) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 2) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 1) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool testPiecePlacementNineByNine(Checkers &checkers) {
        if (checkers.m_game != nullptr && testBuildBoardNineByNine(checkers)) {
            checkers.initGame();
            

            if (checkers.m_currPlayer != BPLAYER) {
                return false;
            }

            for (int i = 0; i < checkers.m_numRows; i++) {
                for (int j = 0; j < checkers.m_numColumns; j++) {
                    if ((checkers.m_numColumns % 2) == (checkers.m_numRows % 2)) {
                        if (i == 0) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 3) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        }
                    }
                    if ((checkers.m_numColumns % 2) != (checkers.m_numRows % 2)) {
                        if (i == 0) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 3) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 2) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 1) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }

    bool testPiecePlacementEightByNine(Checkers &checkers) {
        if (checkers.m_game != nullptr && testBuildBoardEightByNine(checkers)) {
            checkers.initGame();
            

            if (checkers.m_currPlayer != BPLAYER) {
                return false;
            }

            for (int i = 0; i < checkers.m_numRows; i++) {
                for (int j = 0; j < checkers.m_numColumns; j++) {
                    if ((checkers.m_numColumns % 2) == (checkers.m_numRows % 2)) {
                        if (i == 0) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 3) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        }
                    }
                    if ((checkers.m_numColumns % 2) != (checkers.m_numRows % 2)) {
                        if (i == 0) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 1) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == 2) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != WDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 3) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 2) {
                            if (j % 2 == 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        } else if (i == checkers.m_numRows - 1) {
                            if (j % 2 != 0) {
                                if (checkers.m_game[i][j] != BDISK) {
                                    return false;
                                }
                            }
                        }
                    }
                }
            }
            return true;
        } else {
            return false;
        }
    }
    // test the clear function
    bool testClearEightByEight(Checkers &checkers) {
        checkers.clear();
        if (checkers.m_game == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool testClearSixBySix(Checkers &checkers) {
        checkers.clear();
        if (checkers.m_game == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool testClearTenByTen(Checkers &checkers) {
        checkers.clear();
        if (checkers.m_game == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool testClearFiveByTen(Checkers &checkers) {
        checkers.clear();
        if (checkers.m_game == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool testClearNineByNine(Checkers &checkers) {
        checkers.clear();
        if (checkers.m_game == nullptr) {
            return true;
        } else {
            return false;
        }
    }

    bool testClearEightByNine(Checkers &checkers) {
        checkers.clear();
        if (checkers.m_game == nullptr) {
            return true;
        } else {
            return false;
        }
    }
        // test if 8 by 8 will work with set game to create a board
    bool testSetGameEightByEight(Checkers &checkers) {
        if (checkers.m_game != nullptr) {
            checkers.initBoard();
            checkers.initGame();
            const int size = 8 * 8;
            CELL game[size] =
                    {"", "", "", "", "", "", "", "",
                     "", "", "", "", "", "", "", "",
                     "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                     WDISK, "", "", "", WDISK, "", WDISK, "",
                     "", "", "", BDISK, "", BDISK, "", "",
                     "", "", BCELL, "", BCELL, "", BCELL, "",
                     "", "", "", "", "", "", "", "",
                     "", "", "", "", "", "", "", "",};
            // set the current state of the game to a certain pre-defined state
            checkers.setGameState(game, 64, WPLAYER);

            // checking is these are false bc if they are test fail
            if (checkers.m_currPlayer != WPLAYER) {
                return false;
            }
            if (checkers.m_game[2][1] != BCELL) {
                return false;
            }
            if (checkers.m_game[3][0] != WDISK) {
                return false;
            }
            if (checkers.m_game[3][4] != WDISK) {
                return false;
            }

            return true;
        } else {
            return false;
        }
    }

    bool testSetGameSixBySix(Checkers &checkers) {
        if (checkers.m_game != nullptr) {
            checkers.initBoard();
            checkers.initGame();
            const int size = 6 * 6;
            CELL game[size] =
                    {"", "", "", "", "", "", "", "",
                     "", "", "", "", "", "", "", "",
                     "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                     WDISK, "", "", "", WDISK, "", WDISK, "",
                     "", "", "", BDISK,};
            // set the current state of the game to a certain pre-defined state
            checkers.setGameState(game, 36, WPLAYER);

            if (checkers.m_currPlayer != NONE) {
                return false;
            }
            if (checkers.m_game != nullptr) {
                return false;
            }
            if (checkers.m_blackDisks != 0) {
                return false;
            }

            return true;
        } else {
            return false;
        }
    }

    bool testSetGameNineByNine(Checkers &checkers) {
        if (checkers.m_game != nullptr) {
            checkers.initBoard();
            checkers.initGame();
            const int size = 9 * 9;
            CELL game[size] =
                    {"", "", "", "", "", "", "", "", "", "",
                     "", "", "", "", "", "", "", "", "", "",
                     "", BCELL, "", BDISK, "", BCELL, "", BCELL, "", "",
                     WDISK, "", "", "", WDISK, "", WDISK, "", "", "",
                     "", "", "", BDISK, "", BDISK, "", "", "", "",
                     "", "", BCELL, "", BCELL, "", BCELL, "", "", "",
                     "", "", "", "", "", "", "", "", "", "",
                     "", "", "", "", "", "", "", "", "", "",
                     "",};
            // set the current state of the game to a certain pre-defined state
            checkers.setGameState(game, 81, WPLAYER);

            if (checkers.m_currPlayer != WPLAYER) {
                return false;
            }
            if (checkers.m_game[2][1] != BCELL) {
                return false;
            }
            if (checkers.m_game[3][0] != WDISK) {
                return false;
            }
            if (checkers.m_game[3][4] != WDISK) {
                return false;
            }

            return true;
        } else {
            return false;
        }
    }
        // test when the columns are different for the contructor and the size of cell game
    bool testSetGameMessUp(Checkers &checkers) {
        if (checkers.m_game != nullptr) {
            checkers.initBoard();
            checkers.initGame();
            const int size = 8 * 9;
            CELL game[size] =
                    {"", "", "", "", "", "", "", "",
                     "", "", "", "", "", "", "", "",
                     "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                     WDISK, "", "", "", WDISK, "", WDISK, "",
                     "", "", "", BDISK, "", BDISK, "", "",
                     "", "", BCELL, "", BCELL, "", BCELL, "",
                     "", "", "", "", "", "", "", "",
                     "", "", "", "", "", "", "", "",
                     "", "", "", "", "", "", "", "",};
            // set the current state of the game to a certain pre-defined state
            checkers.setGameState(game, 72, WPLAYER);
            bool result = true;

            if (checkers.m_currPlayer != WPLAYER) {
                result = false;
            }
            if (checkers.m_game[2][1] != BCELL) {
                result = false;
            }
            if (checkers.m_game[3][0] != WDISK) {
                result = false;
            }
            if (checkers.m_game[3][4] != WDISK) {
                result = false;
            }

            return result;
        } else {
            return false;
        }
    }
    // white disk moving to a white disk
    bool testWdiskToWdisk(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;

        // these should be the same at the end bc invalid movement
        result = result && (checkers.m_game[1][4] == WDISK);
        result = result && (checkers.m_game[2][5] == WDISK);

        int origin_first = 1;
        int origin_second = 4;
        int destination_first = 2;
        int destination_second = 5;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin_second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BDISK, "", "",
                 "", "", BCELL, "", BCELL, "", BCELL, "",
                 "", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, WPLAYER);

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(1,4), pair<int,int>(2,5));

        result = result && (checkers.m_game[1][4] == WDISK);
        result = result && (checkers.m_game[2][5] == WDISK);

        // if all these result a rue it returns true but if one of them false it's false

        return result;
    }
    // making sure right player with wdisk when Black turn
    bool testRightPlayer(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;

        result = result && (checkers.m_game[2][1] == WDISK);
        result = result && (checkers.m_game[3][2] == BCELL );

        int origin_first = 2;
        int origin_second = 1;
        int destination_first = 3;
        int destination_second = 2;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BDISK, "", "",
                 "", "", BCELL, "", BCELL, "", BCELL, "",
                 "", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, BPLAYER);

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(2,1), pair<int,int>(3,2));

        result = result && (checkers.m_game[2][1] == WDISK);
        result = result && (checkers.m_game[3][2] == BCELL);

        return result;
    }
    // trying to use a black disk origin when white player turn
    bool testOriginNotWhiteDisk(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;

        result = result && (checkers.m_game[5][0] == BDISK);
        result = result && (checkers.m_game[4][1] == BCELL );

        int origin_first = 5;
        int origin_second = 0;
        int destination_first = 4;
        int destination_second = 1;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BDISK, "", "",
                 "", "", BCELL, "", BCELL, "", BCELL, "",
                 "", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, WPLAYER);

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(5,0), pair<int,int>(4,1));

        result = result && (checkers.m_game[5][0] == WDISK);
        result = result && (checkers.m_game[4][1] == BCELL);

        return result;
    }
    // trying to go to a white cell as white disk
    bool testGoToWhiteCell(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BDISK, "", "",
                 "", "", BCELL, "", BCELL, "", BCELL, "",
                 "", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, WPLAYER);
        

        result = result && (checkers.m_game[1][0] == WDISK);
        result = result && (checkers.m_game[2][0] == WCELL);


        int origin_first = 1;
        int origin_second = 0;
        int destination_first = 2;
        int destination_second = 0;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(1,0), pair<int,int>(2,0));

        result = result && (checkers.m_game[1][0] == WDISK);
        result = result && (checkers.m_game[2][0] == BCELL);

        return result;
    }
        // test play with empty object
    bool testPlayWithEmpty(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;

        result = result && (checkers.m_game == nullptr);
        result = result && (checkers.m_numRows == 0);
        result = result && (checkers.m_blackDisks == 0);
        result = result && (checkers.m_currPlayer == NONE);

        return result;
    }
    // trying to go to use None as currplayer
    bool testTryingNonePlayer(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BDISK, "", "",
                 "", "", BCELL, "", BCELL, "", BCELL, "",
                 "", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, NONE);

        result = result && (checkers.m_game[1][0] == WDISK);
        result = result && (checkers.m_game[2][0] == WCELL);

        int origin_first = 1;
        int origin_second = 0;
        int destination_first = 2;
        int destination_second = 0;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(1,0), pair<int,int>(2,0));

        result = result && (checkers.m_game[1][0] == WDISK);
        result = result && (checkers.m_game[2][0] == BCELL);

        return result;
    }
    // moving forward to the left
    bool testWdiskMovingLeft(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BDISK, "", "",
                 "", "", BCELL, "", BCELL, "", BCELL, "",
                 "", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, WPLAYER);
        

        result = result && (checkers.m_game[1][2] == WDISK);
        result = result && (checkers.m_game[2][1] == BCELL);

        int origin_first = 1;
        int origin_second = 2;
        int destination_first = 2;
        int destination_second = 1;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(1,2), pair<int,int>(2,1));
        

        result = result && (checkers.m_game[1][2] == BCELL);
        result = result && (checkers.m_game[2][1] == WDISK);
        result = result && (checkers.m_currPlayer == BPLAYER);

        return result;
    }
    // moving forward to the right
    bool testWdiskMovingRight(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BDISK, "", "",
                 "", "", BCELL, "", BCELL, "", BCELL, "",
                 "", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, WPLAYER);
        

        result = result && (checkers.m_game[3][0] == WDISK);
        result = result && (checkers.m_game[4][1] == BCELL);

        int origin_first = 3;
        int origin_second = 0;
        int destination_first = 4;
        int destination_second = 1;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(3,0), pair<int,int>(4,1));
        

        result = result && (checkers.m_game[3][0] == BCELL);
        result = result && (checkers.m_game[4][1] == WDISK);
        result = result && (checkers.m_currPlayer == BPLAYER);

        return result;
    }
    // moving forward to the left capture
    bool testWdiskMovingLeftCapture(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BDISK, "", "",
                 "", "", BCELL, "", BCELL, "", BCELL, "",
                 "", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, WPLAYER);
        

        result = result && (checkers.m_game[3][4] == WDISK);
        result = result && (checkers.m_game[4][3] == BDISK);
        result = result && (checkers.m_game[5][2] == BCELL);

        int origin_first = 3;
        int origin_second = 4;
        int destination_first = 5;
        int destination_second = 2;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(3,4), pair<int,int>(5,2));
        

        result = result && (checkers.m_game[3][4] == BCELL);
        result = result && (checkers.m_game[4][3] == BCELL);
        result = result && (checkers.m_game[5][2] == WDISK);
        result = result && (checkers.m_currPlayer == BPLAYER);
        checkers.reportLostDisks();
        return result;
    }
    // moving forward to the left capture
    bool testWdiskMovingRightCaptureKing(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BKING, "", "",
                 "", "", BCELL, "", BCELL, "", BCELL, "",
                 "", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, WPLAYER);
        

        result = result && (checkers.m_game[3][4] == WDISK);
        result = result && (checkers.m_game[4][5] == BKING);
        result = result && (checkers.m_game[5][6] == BCELL);

        int origin_first = 3;
        int origin_second = 4;
        int destination_first = 5;
        int destination_second = 6;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(3,4), pair<int,int>(5,6));
        

        result = result && (checkers.m_game[3][4] == BCELL);
        result = result && (checkers.m_game[4][5] == BCELL);
        result = result && (checkers.m_game[5][6] == WDISK);
        result = result && (checkers.m_currPlayer == BPLAYER);
        checkers.reportLostDisks();
        return result;
    }
    // moving backwards with white disk
    bool testWdiskMovingBackwards(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BKING, "", "",
                 "", "", BCELL, "", BCELL, "", BCELL, "",
                 "", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, WPLAYER);
        

        result = result && (checkers.m_game[3][0] == WDISK);
        result = result && (checkers.m_game[2][1] == BCELL);

        int origin_first = 3;
        int origin_second = 0;
        int destination_first = 2;
        int destination_second = 1;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(3,0), pair<int,int>(2,1));
        

        result = result && (checkers.m_game[2][1] == BCELL);
        result = result && (checkers.m_game[3][0] == WDISK);
        result = result && (checkers.m_currPlayer == BPLAYER);
        checkers.reportLostDisks();
        return result;
    }
    // moving to row 7 to be king
    bool testWdiskMovingToKing(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BKING, "", "",
                 "", "", BCELL, "", BCELL, "", BCELL, "",
                 "", WDISK, "", "", "", "", "", "",
                 BCELL, "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, WPLAYER);
        

        result = result && (checkers.m_game[6][1] == WDISK);
        result = result && (checkers.m_game[7][0] == BCELL);

        int origin_first = 6;
        int origin_second = 1;
        int destination_first = 7;
        int destination_second = 0;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(6,1), pair<int,int>(7,0));
        

        result = result && (checkers.m_game[6][1] == BCELL);
        result = result && (checkers.m_game[7][0] == WKING);
        result = result && (checkers.m_currPlayer == BPLAYER);
        return result;
    }
    // capturing than becoming king
    bool testWdiskCapturingToKing(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BKING, "", "",
                 "", "", WDISK, "", BCELL, "", BCELL, "",
                 "", BDISK, "", "", "", "", "", "",
                 BCELL, "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, WPLAYER);
        

        result = result && (checkers.m_game[5][2] == WDISK);
        result = result && (checkers.m_game[6][1] == BDISK);
        result = result && (checkers.m_game[7][0] == BCELL);

        int origin_first = 5;
        int origin_second = 2;
        int destination_first = 7;
        int destination_second = 0;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(5,2), pair<int,int>(7,0));
        

        result = result && (checkers.m_game[5][2] == BCELL);
        result = result && (checkers.m_game[6][1] == BCELL);
        result = result && (checkers.m_game[7][0] == WKING);
        result = result && (checkers.m_currPlayer == BPLAYER);
        checkers.reportLostDisks();
        return result;
    }
    // black disk move right to capture
    bool testBdiskMovingRightCapture(Checkers &checkers) {
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BDISK, "", "",
                 "", "", WDISK, "", BCELL, "", BCELL, "",
                 "", BDISK, "", "", "", "", "", "",
                 BCELL, "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, BPLAYER);
        

        result = result && (checkers.m_game[4][3] == BDISK);
        result = result && (checkers.m_game[3][4] == WDISK);
        result = result && (checkers.m_game[2][5] == BCELL);

        int origin_first = 4;
        int origin_second = 3;
        int destination_first = 2;
        int destination_second = 5;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(4,3), pair<int,int>(2,5));
        

        result = result && (checkers.m_game[4][3] == BCELL);
        result = result && (checkers.m_game[3][4] == BCELL);
        result = result && (checkers.m_game[2][5] == BDISK);
        result = result && (checkers.m_currPlayer == WPLAYER);
        checkers.reportLostDisks();
        return result;
    }
       // black disk captures spot for king status
    bool testBdiskCapturingLeftForKing(Checkers &checkers) { // goes to row 0 to capture and become king
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", BCELL, "", "", "", "", "", "",
                 "", "", WDISK, "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BDISK, "", "",
                 "", "", WDISK, "", BCELL, "", BCELL, "",
                 "", BDISK, "", "", "", "", "", "",
                 BCELL, "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, BPLAYER);
        

        result = result && (checkers.m_game[2][3] == BDISK);
        result = result && (checkers.m_game[1][2] == WDISK);
        result = result && (checkers.m_game[0][1] == BCELL);

        int origin_first = 2;
        int origin_second = 3;
        int destination_first = 0;
        int destination_second = 1;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(2,3), pair<int,int>(0,1));
        

        result = result && (checkers.m_game[2][3] == BCELL);
        result = result && (checkers.m_game[1][2] == BCELL);
        result = result && (checkers.m_game[0][1] == BKING);
        result = result && (checkers.m_currPlayer == WPLAYER);
        checkers.reportLostDisks();
        return result;
    }
     // can't move backwards
    bool testBdiskMovingBackwards(Checkers &checkers) { 
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", BCELL, "", "", "", "", "", "",
                 "", "", WDISK, "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", WDISK, "",
                 "", "", "", BDISK, "", BDISK, "", "",
                 "", "", WDISK, "", BCELL, "", BCELL, "",
                 "", BDISK, "", "", "", "", "", "",
                 BCELL, "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, BPLAYER);
        

        result = result && (checkers.m_game[2][3] == BDISK);
        result = result && (checkers.m_game[3][2] == BCELL);

        int origin_first = 2;
        int origin_second = 3;
        int destination_first = 3;
        int destination_second = 2;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(2,3), pair<int,int>(3,2));
        

        result = result && (checkers.m_game[2][3] == BDISK);
        result = result && (checkers.m_game[3][2] == BCELL);

        return result;
    }
            // wking moving backwards right
    bool testWkingMoveBackwardsRight(Checkers &checkers) { 
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BDISK, "", BCELL, "", BCELL,
                 WDISK, "", "", "", WDISK, "", BCELL, "",
                 "", "", "", BDISK, "", WKING, "", "",
                 "", "", WDISK, "", BCELL, "", BCELL, "",
                 "", BDISK, "", "", "", "", "", "",
                 BCELL, "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, WPLAYER);
        

        result = result && (checkers.m_game[4][5] == WKING);
        result = result && (checkers.m_game[3][6] == BCELL);

        int origin_first = 4;
        int origin_second = 5;
        int destination_first = 3;
        int destination_second = 6;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(4,5), pair<int,int>(3,6));
        

        result = result && (checkers.m_game[4][5] == BCELL);
        result = result && (checkers.m_game[3][6] == WKING);
        result = result && (checkers.m_currPlayer == BPLAYER);
        return result;
    }
        // wking move backwars capture
    bool testWkingMoveBackwardsLeftCapture(Checkers &checkers) { // moving backwards with white disk
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BCELL, "", BCELL, "", BCELL,
                 WDISK, "", "", "", BDISK, "", BCELL, "",
                 "", "", "", BDISK, "", WKING, "", "",
                 "", "", WDISK, "", BCELL, "", BCELL, "",
                 "", BDISK, "", "", "", "", "", "",
                 BCELL, "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, WPLAYER);
        

        result = result && (checkers.m_game[4][5] == WKING);
        result = result && (checkers.m_game[3][4] == BDISK);
        result = result && (checkers.m_game[2][3] == BCELL);

        int origin_first = 4;
        int origin_second = 5;
        int destination_first = 2;
        int destination_second = 3;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(4,5), pair<int,int>(2,3));
        

        result = result && (checkers.m_game[4][5] == BCELL);
        result = result && (checkers.m_game[3][4] == BCELL);
        result = result && (checkers.m_game[2][3] == WKING);
        result = result && (checkers.m_currPlayer == BPLAYER);
        checkers.reportLostDisks();
        return result;
    }
    // nothing should happen to the king as it's already king
    bool testWkingMoveToKingSpot(Checkers &checkers) { 
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BCELL, "", BCELL, "", BCELL,
                 WDISK, "", "", "", BDISK, "", BCELL, "",
                 "", "", "", BDISK, "", WKING, "", "",
                 "", "", WDISK, "", BCELL, "", BCELL, "",
                 "", WKING, "", "", "", "", "", "",
                 BCELL, "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, WPLAYER);
        

        result = result && (checkers.m_game[6][1] == WKING);
        result = result && (checkers.m_game[7][0] == BDISK);

        int origin_first = 6;
        int origin_second = 1;
        int destination_first = 7;
        int destination_second = 0;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(6,1), pair<int,int>(7,0));
        

        result = result && (checkers.m_game[6][1] == BCELL);
        result = result && (checkers.m_game[7][0] == WKING);
        result = result && (checkers.m_currPlayer == BPLAYER);

        return result;
    }
    // black disk takes king
    bool testBdiskTakesKing(Checkers &checkers) { 
        checkers.initBoard();
        checkers.initGame();
        bool result = true;
        const int size = 8 * 8;
        CELL game[size] =
                {"", "", "", "", "", "", "", "",
                 "", "", "", "", "", "", "", "",
                 "", BCELL, "", BCELL, "", BCELL, "", BCELL,
                 WDISK, "", "", "", BDISK, "", BCELL, "",
                 "", "", "", BCELL, "", WKING, "", "",
                 "", "", WKING, "", BCELL, "", BCELL, "",
                 "", BDISK, "", "", "", "", "", "",
                 BCELL, "", "", "", "", "", "", "",};
        // set the current state of the game to a certain pre-defined state
        checkers.setGameState(game, 64, BPLAYER);
        

        result = result && (checkers.m_game[5][2] == WKING);
        result = result && (checkers.m_game[6][1] == BDISK);
        result = result && (checkers.m_game[4][3] == BCELL);

        int origin_first = 6;
        int origin_second = 1;
        int destination_first = 4;
        int destination_second = 3;

        pair<int,int> origin;
        pair<int,int> destination;

        origin.first = origin_first;
        origin.second = origin_second;
        destination.first = destination_first;
        destination.second = destination_second;

        result = result && (0 <= origin_first && origin_first < checkers.m_numRows);
        result = result && (0 <= origin_second && origin_second < checkers.m_numColumns);
        result = result && (0 <= destination_first && destination_first < checkers.m_numRows);
        result = result && (0 <= destination_second && destination_second < checkers.m_numColumns);

        result = checkers.play(pair<int,int>(6,1), pair<int,int>(4,3));
        

        result = result && (checkers.m_game[5][2] == BCELL);
        result = result && (checkers.m_game[6][1] == BCELL);
        result = result && (checkers.m_game[4][3] == BDISK);
        result = result && (checkers.m_currPlayer == WPLAYER);
        checkers.reportLostDisks();
        return result;
    }

};

int main(){
    Tester tester;

    Checkers checkers(DEFBOARDSIZE, DEFBOARDSIZE);
    Checkers checkers2(6,6);
    Checkers checkers3(10,10);
    Checkers checkers4(-5,-10);
    Checkers checkers5(9,9); // get rid of this test or change to 9 by 9
    Checkers checkers6(8,9);


    if (tester.testEightByEight(checkers)) // should return true
        cout << "\ttestEightByEight() returned true." << endl;
    else
        cout << "\ttestEightByEight() returned false." << endl;

    if ( tester.testSixBySix(checkers2)) // should return false
        cout << "\ttestSixBySix() returned true." << endl;
    else
        cout << "\ttestSixBySix() returned false." << endl;

    if (tester.testTenByTen(checkers3)) // should return true
        cout << "\ttestTenByTen() returned true." << endl;
    else
        cout << "\ttestTenByTen() returned false." << endl;

    if (tester.testFiveByTen(checkers4)) // should return false
        cout << "\ttestFiveByTen() returned true." << endl;
    else
        cout << "\ttestFiveByTen() returned false." << endl;

    if (tester.testNineByNine(checkers5))   // should return false
        cout << "\ttestNineByNine() returned true." << endl;
    else
        cout << "\ttestNineByNine() returned false." << endl;

    if (tester.testEightByNine(checkers6)) // should return false
        cout << "\ttestEightByNine() returned true." << endl;
    else
        cout << "\ttestEightByNine() returned false." << "\n" << endl;


    if (tester.testMemoryObjectEightByEight(checkers)) // should return true
        cout << "\ttestMemoryObjectEightByEight() returned true." << endl;
    else
        cout << "\ttestMemoryObjectEightByEight() returned false." << endl;

    if (tester.testMemoryObjectSixBySix(checkers2)) // should return false
        cout << "\ttestMemoryObjectSixBySix() returned true." << endl;
    else
        cout << "\ttestMemoryObjectSixBySix() returned false." << endl;

    if (tester.testMemoryObjectTenByTen(checkers3)) // should return true
        cout << "\ttestMemoryObjectTenByTen() returned true." << endl;
    else
        cout << "\ttestMemoryObjectTenByTen() returned false." << endl;

    if ( tester.testMemoryObjectFiveByTen(checkers4)) // should return false
        cout << "\ttestMemoryObjectFiveByTen() returned true." << endl;
    else
        cout << "\ttestMemoryObjectFiveByTen() returned false." << endl;

    if (tester.testMemoryObjectNineByNine(checkers5)) // should return false
        cout << "\ttestMemoryObjectNineByNine() returned true." << endl;
    else
        cout << "\ttestMemoryObjectNineByNine() returned false." << endl;

    if (tester.testMemoryObjectEightByNine(checkers6)) // should return false
        cout << "\ttestMemoryObjectEightByNine() returned true." << endl;
    else
        cout << "\ttestMemoryObjectEightByNine() returned false." << "\n" << endl;



    if (tester.testBuildBoardEightByEight(checkers)) // should return true
        cout << "\ttestBuildBoardEightByEight() returned true." << endl;
    else
        cout << "\ttestBuildBoardEightByEight() returned false." << endl;

    if (tester.testBuildBoardSixBySix(checkers2)) // should return false
        cout << "\ttestBuildBoardESixBySix() returned true." << endl;
    else
        cout << "\ttestBuildBoardSixBySix() returned false." << endl;

    if (tester.testBuildBoardTenByTen(checkers3)) // should return true
        cout << "\ttestBuildBoardTenByTen() returned true." << endl;
    else
        cout << "\ttestBuildBoardTenByTen() returned false." << endl;

    if (tester.testBuildBoardFiveByTen(checkers4)) // should return false
        cout << "\ttestBuildBoardFiveByTen() returned true." << endl;
    else
        cout << "\ttestBuildBoardFiveByTen() returned false." << endl;

    if (tester.testBuildBoardNineByNine(checkers5)) // should return false
        cout << "\ttestBuildBoardNineByNine() returned true." << endl;
    else
        cout << "\ttestBuildBoardNineByNine() returned false." << endl;

    if (tester.testBuildBoardEightByNine(checkers6)) // should return false
        cout << "\ttestBuildBoardEightByNine() returned true." << endl;
    else
        cout << "\ttestBuildBoardEightByNine() returned false." << "\n" << endl;



    if (tester.testPiecePlacementEightByEight(checkers)) // should return true
        cout << "\ttestPiecePlacementEightByEight() returned true." << endl;
    else
        cout << "\ttestPiecePlacementEightByEight() returned false." << endl;

    if (tester.testPiecePlacementSixBySix(checkers2)) // should return false
        cout << "\ttestPiecePlacementSixBySix() returned true." << endl;
    else
        cout << "\ttestPiecePlacementSixBySix() returned false." << endl;

    if (tester.testPiecePlacementTenByTen(checkers3)) // should return true
        cout << "\ttestPiecePlacementTenByTen() returned true." << endl;
    else
        cout << "\ttestPiecePlacementTenByTen() returned false." << endl;

    if (tester.testPiecePlacementFiveByTen(checkers4)) // should return false
        cout << "\ttestPiecePlacementFiveByTen() returned true." << endl;
    else
        cout << "\ttestPiecePlacementFiveByTen() returned false." << endl;

    if (tester.testPiecePlacementNineByNine(checkers5)) // should return false
        cout << "\ttestPiecePlacementNineByNine() returned true." << endl;
    else
        cout << "\ttestPiecePlacementNineByNine() returned false." << endl;

    if (tester.testPiecePlacementEightByNine(checkers6)) // should return false
        cout << "\ttestPiecePlacementEightByNine() returned true." << endl;
    else
        cout << "\ttestPiecePlacementEightByNine() returned false." << "\n" << endl;



    if (tester.testSetGameEightByEight(checkers)) // should return true
        cout << "\ttestSetGameEightByEight() returned true." << endl;
    else
        cout << "\ttestSetGameEightByEight() returned false." << endl;

    if (tester.testSetGameSixBySix(checkers2)) // should return false
        cout << "\ttestSetGameSixBySix() returned true." << endl;
    else
        cout << "\ttestSetGameSixBySix() returned false." << endl;

    if (tester.testSetGameNineByNine(checkers5)) // should return false
        cout << "\ttestSetGameNineByNine() returned true." << endl;
    else
        cout << "\ttestSetGameNineByNine() returned false." << endl;

    if (tester.testSetGameMessUp(checkers3)) // should return false
        cout << "\ttestSetGameMessUp() returned true." << endl;
    else
        cout << "\ttestSetGameMessUp() returned false." << "\n" << endl;



    if(tester.testWdiskToWdisk(checkers)) // should return false
        cout << "\ttestWdiskToWdisk returned true." << "\n" << endl;
    else
        cout << "\ttestWdiskToWdisk returned false." << "\n" << endl;

    if(tester.testRightPlayer(checkers)) // should return false
        cout << "\ttestRightPlayer returned true." << "\n" << endl;
    else
        cout << "\ttestRightPlayer returned false." << "\n" << endl;

    if(tester.testOriginNotWhiteDisk(checkers)) // should return false
        cout << "\ttestOriginNotWhiteDisk returned true." << "\n" << endl;
    else
        cout << "\ttestOriginNotWhiteDisk returned false." << "\n" << endl;

    if(tester.testGoToWhiteCell(checkers)) // should return false
        cout << "\ttestGoToWhiteCell returned true." << "\n" << endl;
    else
        cout << "\ttestGoToWhiteCell returned false." << "\n" << endl;

    if(tester.testPlayWithEmpty(checkers2)) // should return false
        cout << "\ttestPlayWithEmpty returned true." << "\n" << endl;
    else
        cout << "\ttestPlayWithEmpty returned false." << "\n" << endl;

    if(tester.testTryingNonePlayer(checkers)) // should return false
        cout << "\ttestTryingNonePlayer returned true." << "\n" << endl;
    else
        cout << "\ttestTryingNonePlayer returned false." << "\n" << endl;

    if(tester.testWdiskMovingLeft(checkers)) // should return true
        cout << "\ttestWdiskMovingLeft returned true." << "\n" << endl;
    else
        cout << "\ttestWdiskMovingLeft returned false." << "\n" << endl;

    if(tester.testWdiskMovingRight(checkers)) // should return true
        cout << "\ttestWdiskMovingRight returned true." << "\n" << endl;
    else
        cout << "\ttestWdiskMovingRight returned false." << "\n" << endl;

    if(tester.testWdiskMovingLeftCapture(checkers)) // should return true
        cout << "\ttestWdiskMovingLeftCapture returned true." << "\n" << endl;
    else
        cout << "\ttestWdiskMovingLeftCapture returned false." << "\n" << endl;

    if(tester.testWdiskMovingRightCaptureKing(checkers)) // should return true
        cout << "\ttestWdiskMovingRightCaptureKing returned true." << "\n" << endl;
    else
        cout << "\ttestWdiskMovingRightCaptureKing returned false." << "\n" << endl;

    if(tester.testWdiskMovingBackwards(checkers)) // should return false
        cout << "\ttestWdiskMovingBackwards returned true." << "\n" << endl;
    else
        cout << "\ttestWdiskMovingBackwards returned false." << "\n" << endl;

    if(tester.testWdiskMovingToKing(checkers)) // should return true
        cout << "\ttestWdiskMovingToKing returned true." << "\n" << endl;
    else
        cout << "\ttestWdiskMovingToKing returned false." << "\n" << endl;

    if(tester.testWdiskCapturingToKing(checkers)) // should return true
        cout << "\ttestWdiskCapturingToKing returned true." << "\n" << endl;
    else
        cout << "\ttestWdiskCapturingToKing returned false." << "\n" << endl;

    if(tester.testBdiskMovingRightCapture(checkers)) // should return true
        cout << "\ttestBdiskMovingRightCapture returned true." << "\n" << endl;
    else
        cout << "\ttestBdiskMovingRightCapture returned false." << "\n" << endl;

    if(tester.testBdiskCapturingLeftForKing(checkers)) // should return true
        cout << "\ttestBdiskCapturingLeftForKing returned true." << "\n" << endl;
    else
        cout << "\ttestBdiskCapturingLeftForKing returned false." << "\n" << endl;

    if(tester.testBdiskMovingBackwards(checkers)) // should return false
        cout << "\ttesttestBdiskMovingBackwards returned true." << "\n" << endl;
    else
        cout << "\ttesttestBdiskMovingBackwards returned false." << "\n" << endl;

    if(tester.testWkingMoveBackwardsRight(checkers)) // should return true
        cout << "\ttestWkingMoveBackwardsRight returned true." << "\n" << endl;
    else
        cout << "\ttestWkingMoveBackwardsRight returned false." << "\n" << endl;

    if(tester.testWkingMoveBackwardsLeftCapture(checkers)) // should return true
        cout << "\ttestWkingMoveBackwardsLeftCapture returned true." << "\n" << endl;
    else
        cout << "\ttestWkingMoveBackwardsLeftCapture returned false." << "\n" << endl;

    if(tester.testWkingMoveToKingSpot(checkers)) // should return true
        cout << "\ttestWkingMoveBackwardsLeftCapture returned true." << "\n" << endl;
    else
        cout << "\ttestWkingMoveBackwardsLeftCapture returned false." << "\n" << endl;

    if(tester.testWkingMoveToKingSpot(checkers)) // should return true
        cout << "\ttestWkingMoveToKingSpot returned true." << "\n" << endl;
    else
        cout << "\ttestWkingMoveToKingSpot returned false." << "\n" << endl;

    if(tester.testBdiskTakesKing(checkers)) // should return true
        cout << "\ttestBdiskTakesKing returned true." << "\n" << endl;
    else
        cout << "\ttestBdiskTakesKing returned false." << "\n" << endl;



    if (tester.testClearEightByEight(checkers)) // should return true
        cout << "\ttestClearEightByEight() returned true." << endl;
    else
        cout << "\ttestClearEightByEight() returned false." << endl;

    if (tester.testClearSixBySix(checkers2)) // should return true
        cout << "\ttestClearSixBySix() returned true." << endl;
    else
        cout << "\ttestClearSixBySix() returned false." << endl;

    if (tester.testClearTenByTen(checkers3)) // should return true
        cout << "\ttestClearTenByTen() returned true." << endl;
    else
        cout << "\ttestClearTenByTen() returned false." << endl;

    if (tester.testClearFiveByTen(checkers4)) // should return true
        cout << "\ttestClearFiveByTen() returned true." << endl;
    else
        cout << "\ttestClearFiveByTen() returned false." << endl;

    if (tester.testClearNineByNine(checkers5)) // should return true
        cout << "\ttestClearNineByNine() returned true." << endl;
    else
        cout << "\ttestClearNineByNine() returned false." << endl;

    if (tester.testClearEightByNine(checkers6)) // should return true
        cout << "\ttestClearEightByNine() returned true." << endl;
    else
        cout << "\ttestClearEightByNine() returned false." << endl;


    return 0;
}
