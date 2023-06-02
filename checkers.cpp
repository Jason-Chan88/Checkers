#include "checkers.h"
// Name: Checkers() Default Constructor
// Desc - Instantiates an object of type Checkers, sets stuff for empty
// Preconditions - None
// Postconditions - None
Checkers::Checkers(){
    m_numColumns = 0;
    m_numRows = 0;
    m_blackDisks = 0;
    m_whiteDisks = 0;
    m_currPlayer = NONE;
    m_game = nullptr;
}
// Name: OverloadConstructor
// Desc - Initializes all the member variables if they meet conditions
// Preconditions - rows and columns
// Postconditions - initializes rows and columns than the other member variable
Checkers::Checkers(int rows, int columns){
    if (rows >= 8 && columns >= 8 && (columns % 2 == 0) && columns == rows) {
        m_numColumns = columns;
        m_numRows = rows;
        m_blackDisks = m_numColumns / 2 * 3;
        m_whiteDisks = m_numColumns / 2 * 3;
        m_currPlayer = NONE;
        m_game = new CELL *[m_numRows];
        for (int i = 0; i < m_numRows; i++) {
            m_game[i] = new CELL[m_numColumns];
        }
    }
    else {
        m_numColumns = 0;
        m_numRows = 0;
        m_blackDisks = 0;
        m_whiteDisks = 0;
        m_currPlayer = NONE;
        m_game = nullptr;
    }
}
// Name: Checker Destructor
// Desc - Calls clear
// Preconditions - None
// Postconditions - deallocates memory
Checkers::~Checkers(){
    clear();
}
// Name: clear
// Desc - deallocates all dynamically allocated memory
// Preconditions - None
// Postconditions - everything is empty
void Checkers::clear(){
    if (m_game) {
        for (int j = 0; j < m_numColumns; j++) {
            delete[] m_game[j];
        }
        delete[] m_game;
        m_game = nullptr;
    }
    m_numColumns = 0;
    m_numRows = 0;
    m_blackDisks = 0;
    m_whiteDisks = 0;
    m_currPlayer = NONE;
    m_game = nullptr;
}
// Name: InitBoard
// Desc - creates board
// Preconditions - None
// Postconditions - creates board of white and black cells
void Checkers::initBoard() {
    // use nested for loop and make sure i + j has a remainder of 0 to identify where black and white cells go
    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numColumns; j++) {
            if ((i + j) % 2 != 0) {
                m_game[i][j] = BCELL;
            } else {
                m_game[i][j] = WCELL;
            }
        }
    }
}
// Name: reportLostdisk
// Desc - prints out the amount of lost disk for white and black
// Preconditions - None
// Postconditions - recounts the disk on the board and puts them into equation to find solution
void Checkers::reportLostDisks(){
    m_blackDisks = 0;
    m_whiteDisks = 0;
    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numColumns; j++) {
            if(m_game[i][j] == WDISK || m_game[i][j] == WKING) { // counts only white king and disk
                m_whiteDisks += 1;
            }
            if (m_game[i][j] == BDISK || m_game[i][j] == BKING) { // counts only black king and disk
                m_blackDisks += 1;
            }
        }
    }
    int whiteDisks_loss = (m_numColumns / 2 * 3) - m_whiteDisks;
    int blackDisks_loss = (m_numColumns / 2 * 3)- m_blackDisks;
    cout << "White player lost disks: " << whiteDisks_loss << endl;
    cout << "Black player lost disks: " << blackDisks_loss << endl;
}
// Name: initGame
// Desc - places disk on board
// Preconditions - None
// Postconditions - runs a nested for loop than place the piece where they should be
void Checkers::initGame() {
    // one for loop for white and one for loop for black
    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numColumns; j++) {
            // the first three rows I checked i
                if (i == 0) {
                    if (j % 2 != 0) {
                        m_game[i][j] = WDISK;
                    }
                } else if (i == 1) {
                    if (j % 2 == 0) {
                        m_game[i][j] = WDISK;
                    }
                } else if (i == 2) {
                    if (j % 2 != 0) {
                        m_game[i][j] = WDISK;
                    }
                // last three rows I checked a constant and started decreasing for the back three rows
                } else if (i == m_numRows - 3) {
                    if (j % 2 == 0) {
                        m_game[i][j] = BDISK;
                    }
                } else if (i == m_numRows - 2) {
                    if (j % 2 != 0) {
                        m_game[i][j] = BDISK;
                    }
                } else if (i == m_numRows - 1) {
                    if (j % 2 == 0) {
                        m_game[i][j] = BDISK;
                    }
                }
            }
        }

    m_currPlayer = BPLAYER; // set player when board is set
}
// Name: play
// Desc - checks to see if a move is valid
// Preconditions - None
// Postconditions - tells you if move is valid or not with returning true of false
bool Checkers::play(pair<int,int> origin, pair<int,int> destination){
    bool origin_exist = false;
    bool destination_exist= false;
    bool black_move = false;
    bool white_move = false;

    if(m_blackDisks < 1 || m_whiteDisks < 1) {
        m_currPlayer = NONE;
    }
    // nested for loops to check if origin is within the board
    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numColumns; j++) {
            if (0 <= origin.first && origin.first < m_numRows && 0 <= origin.second && origin.second < m_numColumns) {
                origin_exist = true;
                }
            else{
                origin_exist = false;
                }
            }
        }
    // nested for loops to check if destination is within the board
    for (int i = 0; i < m_numRows; i++) {
        for (int j = 0; j < m_numColumns; j++) {
            if (0 <= destination.first && destination.first < m_numRows && 0 <= destination.second && destination.second < m_numColumns) {
                destination_exist = true;
            }
            else{
                destination_exist = false;
            }
        }
    }
     // checks if the current player is Black and the origin and destination exist
    if (m_currPlayer == BPLAYER && destination_exist == true && origin_exist == true) {
        // checks if origin is a black disk or king
        if (m_game[origin.first][origin.second] == BDISK || m_game[origin.first][origin.second] == BKING) {
            // checks if the origin isn't a king aka it's a bdisk
            if (m_game[origin.first][origin.second] != BKING) // regular black piece
            {      // checks destination is a Bcell
                if (m_game[destination.first][destination.second] == BCELL) {
                      // Checks to see if Bcell is empty
                    if (m_game[destination.first][destination.second] != BDISK || m_game[destination.first][destination.second] != WDISK || m_game[destination.first][destination.second] != WKING || m_game[destination.first][destination.second] != BKING ) {
                        // jump one space up from black perspective
                        if (destination.first - origin.first == -1) {
                            //going right
                            if (destination.second - origin.second == 1) {
                                // checks if destination is row 0 bc if it is turn bdisk to bking
                                if(destination.first == 0) {
                                    m_currPlayer = WPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = BKING;
                                    black_move = true;
                                    // if not than nothing
                                } else {
                                    m_currPlayer = WPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = BDISK;
                                    black_move = true;
                                }
                                //going left
                            } else if (destination.second - origin.second == -1) {
                                // checks if destination is row 0 bc if it is turn bdisk to bking
                                if(destination.first == 0) {
                                    m_currPlayer = WPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = BKING;
                                    black_move = true;
                                } else {
                                    m_currPlayer = WPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = BDISK;
                                    black_move = true;
                                }
                                // if move not -1 or 1 than move is invalid
                            } else {
                                black_move = false;
                            }
                            // only for capturing, jump two spaces
                        } else if (destination.first - origin.first == -2) {
                            // going right
                            if (destination.second - origin.second == 2) {
                                // checks to see there's a enemy player to jump over
                                if(m_game[destination.first+1][destination.second-1] == WDISK || m_game[destination.first+1][destination.second-1] == WKING) {
                                    // allows capturing than becoming king
                                    if (destination.first == 0) {
                                        m_whiteDisks = m_whiteDisks - 1;
                                        m_currPlayer = WPLAYER;
                                        m_game[origin.first][origin.second] = BCELL;
                                        m_game[destination.first][destination.second] = BKING;
                                        m_game[destination.first + 1][destination.second - 1] = BCELL;
                                        black_move = true;
                                    }
                                    else {
                                        m_whiteDisks = m_whiteDisks - 1;
                                        m_currPlayer = WPLAYER;
                                        m_game[origin.first][origin.second] = BCELL;
                                        m_game[destination.first][destination.second] = BDISK;
                                        m_game[destination.first + 1][destination.second - 1] = BCELL;
                                        black_move = true;
                                    }
                                }
                                else {
                                    black_move = false;
                                }
                            } else if (destination.second - origin.second == -2) {
                                // going left
                                if(m_game[destination.first+1][destination.second+1] == WDISK || m_game[destination.first+1][destination.second+1] == WKING ) { // going left
                                    if (destination.first == 0) {
                                        m_blackDisks = m_blackDisks - 1;
                                        m_currPlayer = WPLAYER;
                                        m_game[origin.first][origin.second] = BCELL;
                                        m_game[destination.first][destination.second] = BKING;
                                        m_game[destination.first + 1][destination.second + 1] = BCELL;
                                        black_move = true;
                                    }
                                    else {
                                        m_blackDisks = m_blackDisks - 1;
                                        m_currPlayer = WPLAYER;
                                        m_game[origin.first][origin.second] = BCELL;
                                        m_game[destination.first][destination.second] = BDISK;
                                        m_game[destination.first + 1][destination.second + 1] = BCELL;
                                        black_move = true;
                                    }
                                }
                                else {
                                    // bad move if there's no enemy to jump over
                                    black_move = false;
                                }
                            } else {
                                // bad move if there move isnt -2 or 2
                                black_move = false;
                            }
                        } else {
                            black_move = false;
                        }
                    } else {
                        // if destination is occupied than bad move
                        black_move = false;
                    }
                }else {
                    // bad move if not to bcell
                    black_move = false;
                }
            }
            // goes to king if origin is king
            else// king
            {
                if (m_game[destination.first][destination.second] == BCELL) {

                    if (m_game[destination.first][destination.second] != BDISK || m_game[destination.first][destination.second] != WDISK || m_game[destination.first][destination.second] != WKING || m_game[destination.first][destination.second] != BKING) {
                        // movement can now be forward and backwards with king with 1 and -1
                        if (destination.first - origin.first == 1) {
                            // jump one space up
                            if (destination.second - origin.second == 1) {
                                //going right
                                m_currPlayer = WPLAYER;
                                m_game[origin.first][origin.second] = BCELL;
                                m_game[destination.first][destination.second] = BKING;
                                black_move = true;
                            } else if (destination.second - origin.second == -1) {
                                //going left
                                m_currPlayer = WPLAYER;
                                m_game[origin.first][origin.second] = BCELL;
                                m_game[destination.first][destination.second] = BKING;
                                black_move = true;
                            } else {
                                black_move = false;
                            }
                        }
                        else if(destination.first - origin.first == -1){
                            // jump one space up
                            if (destination.second - origin.second == 1) {
                                //going right
                                m_currPlayer = WPLAYER;
                                m_game[origin.first][origin.second] = BCELL;
                                m_game[destination.first][destination.second] = BKING;
                                black_move = true;
                            } else if (destination.second - origin.second == -1) {
                                //going left
                                m_currPlayer = WPLAYER;
                                m_game[origin.first][origin.second] = BCELL;
                                m_game[destination.first][destination.second] = BKING;
                                black_move = true;
                            } else {
                                black_move = false;
                            }
                        }
                            // movement can now be forward and backwards with king with 2 and -2
                        else if (destination.first - origin.first == -2) {
                            // jump two spaces up
                            if (destination.second - origin.second == 2) {
                                if(m_game[destination.first+1][destination.second-1] == WDISK || m_game[destination.first+1][destination.second-1] == WKING) {
                                    // going right
                                    m_whiteDisks = m_whiteDisks - 1;
                                    m_currPlayer = WPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = BKING;
                                    m_game[destination.first+1][destination.second-1] = BCELL;
                                    black_move = true;
                                }
                                else {
                                    black_move = false;
                                }
                            } else if (destination.second - origin.second == -2) {
                                if(m_game[destination.first+1][destination.second+1] == WDISK || m_game[destination.first+1][destination.second+1] == WKING) {
                                    // going left
                                    m_whiteDisks = m_whiteDisks - 1;
                                    m_currPlayer = WPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = BKING;
                                    m_game[destination.first+1][destination.second+1] = BCELL;
                                    black_move = true;
                                }
                                else {
                                    black_move = false;
                                }
                            } else {
                                black_move = false;
                            }
                        }
                        else if (destination.first - origin.first == 2) {
                            // jump two spaces down
                            if (destination.second - origin.second == 2) {
                                if(m_game[destination.first-1][destination.second-1] == WDISK || m_game[destination.first-1][destination.second-1] == WKING) {
                                    // going right
                                    m_whiteDisks = m_whiteDisks-1;
                                    m_currPlayer = WPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = BKING;
                                    m_game[destination.first-1][destination.second-1] = BCELL;
                                    black_move = true;
                                }
                                else {
                                    black_move = false;
                                }
                            } else if (destination.second - origin.second == -2) {
                                if(m_game[destination.first-1][destination.second+1] == WDISK || m_game[destination.first-1][destination.second+1] == WKING) {
                                    // going left
                                    m_whiteDisks = m_whiteDisks - 1;
                                    m_currPlayer = WPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = BKING;
                                    m_game[destination.first-1][destination.second+1] = BCELL;
                                    black_move = true;
                                }
                                else {
                                    black_move = false;
                                }
                            } else {
                                black_move = false;
                            }
                        } else {
                            black_move = false;
                        }
                    } else {
                        black_move = false;
                    }
                }else {
                    black_move = false;
                }
            }
        }
    }

    if (m_currPlayer == WPLAYER && destination_exist == true && origin_exist == true) {

        if (m_game[origin.first][origin.second] == WDISK || m_game[origin.first][origin.second] == WKING) {

            if (m_game[origin.first][origin.second] != WKING) // regular white piece
            {

                if (m_game[destination.first][destination.second] == BCELL) {

                    if (m_game[destination.first][destination.second] != BDISK || m_game[destination.first][destination.second] != WDISK || m_game[destination.first][destination.second] != WKING || m_game[destination.first][destination.second] != BKING ) {

                        if (destination.first - origin.first == 1) {
                            // jump one space down
                            if (destination.second - origin.second == 1) { //going right
                                if (destination.first == m_numRows-1) {
                                    m_currPlayer = BPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = WKING;
                                    white_move = true;
                                }
                                else {
                                    m_currPlayer = BPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = WDISK;
                                    white_move = true;
                                }
                            } else if (destination.second - origin.second == -1) { //going left
                                if (destination.first == m_numRows-1) {
                                    m_currPlayer = BPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = WKING;
                                    white_move = true;
                                }
                                else {
                                    m_currPlayer = BPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = WDISK;
                                    white_move = true;
                                }
                            } else {
                                white_move = false;
                            }
                        } else if (destination.first - origin.first == 2) {

                            // jump two spaces
                            if (destination.second - origin.second == 2) { // going right

                                if(m_game[destination.first-1][destination.second-1] == BDISK || m_game[destination.first-1][destination.second-1] == BKING) {

                                    if (destination.first == m_numRows-1) {
                                        m_blackDisks = m_blackDisks - 1;
                                        m_currPlayer = BPLAYER;
                                        m_game[origin.first][origin.second] = BCELL;
                                        m_game[destination.first][destination.second] = WKING;
                                        m_game[destination.first - 1][destination.second - 1] = BCELL;
                                        white_move = true;
                                    }
                                    else {
                                        m_blackDisks = m_blackDisks - 1;
                                        m_currPlayer = BPLAYER;
                                        m_game[origin.first][origin.second] = BCELL;
                                        m_game[destination.first][destination.second] = WDISK;
                                        m_game[destination.first - 1][destination.second - 1] = BCELL;
                                        white_move = true;
                                    }
                                }
                                else {

                                    white_move = false;
                                }
                            } else if (destination.second - origin.second == -2) { // going left

                                if(m_game[destination.first-1][destination.second+1] == BDISK || m_game[destination.first-1][destination.second+1] == BKING ) {

                                    if (destination.first == m_numRows-1){
                                        m_blackDisks = m_blackDisks - 1;
                                        m_currPlayer = BPLAYER;
                                        m_game[origin.first][origin.second] = BCELL;
                                        m_game[destination.first][destination.second] = WKING;
                                        m_game[destination.first - 1][destination.second + 1] = BCELL;
                                        white_move = true;
                                    }
                                    else {
                                        m_blackDisks = m_blackDisks - 1;
                                        m_currPlayer = BPLAYER;
                                        m_game[origin.first][origin.second] = BCELL;
                                        m_game[destination.first][destination.second] = WDISK;
                                        m_game[destination.first - 1][destination.second + 1] = BCELL;
                                        white_move = true;
                                    }
                                }
                                else {

                                    white_move = false;
                                }
                            } else {
                                white_move = false;
                            }
                        } else {
                            white_move = false;
                        }
                    } else {
                        white_move = false;
                    }
                }else {
                    white_move = false;
                }
            }
            else// king
            {
                if (m_game[destination.first][destination.second] == BCELL) {

                    if (m_game[destination.first][destination.second] != BDISK || m_game[destination.first][destination.second] != WDISK || m_game[destination.first][destination.second] != WKING || m_game[destination.first][destination.second] != BKING) {
                        if (destination.first - origin.first == 1) {
                            // jump one space down
                            if (destination.second - origin.second == 1) {
                                //going right
                                m_currPlayer = BPLAYER;
                                m_game[origin.first][origin.second] = BCELL;
                                m_game[destination.first][destination.second] = WKING;
                                white_move = true;
                            } else if (destination.second - origin.second == -1) {
                                //going left
                                m_currPlayer = BPLAYER;
                                m_game[origin.first][origin.second] = BCELL;
                                m_game[destination.first][destination.second] = WKING;
                                white_move = true;
                            } else {
                                white_move = false;
                            }
                        }
                        else if(destination.first - origin.first == -1){
                            // jump one space up
                            if (destination.second - origin.second == 1) {
                                //going right
                                m_currPlayer = BPLAYER;
                                m_game[origin.first][origin.second] = BCELL;
                                m_game[destination.first][destination.second] = WKING;
                                white_move = true;
                            } else if (destination.second - origin.second == -1) {
                                //going left
                                m_currPlayer = BPLAYER;
                                m_game[origin.first][origin.second] = BCELL;
                                m_game[destination.first][destination.second] = WKING;
                                white_move = true;
                            } else {
                                white_move = false;
                            }
                        }
                        else if (destination.first - origin.first == -2) {
                            // jump two spaces up
                            if (destination.second - origin.second == 2) {
                                if(m_game[destination.first+1][destination.second-1] == BDISK || m_game[destination.first+1][destination.second-1] == BKING) {
                                    // going right
                                    m_blackDisks = m_blackDisks - 1;
                                    m_currPlayer = BPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = WKING;
                                    m_game[destination.first+1][destination.second-1] = BCELL;
                                    white_move = true;
                                }
                                else {
                                    white_move = false;
                                }
                            } else if (destination.second - origin.second == -2) {
                                if(m_game[destination.first+1][destination.second+1] == BDISK || m_game[destination.first+1][destination.second+1] == BKING) {
                                    // going left
                                    m_blackDisks = m_blackDisks - 1;
                                    m_currPlayer = BPLAYER;
                                    m_game[origin.first][origin.second] = BCELL;
                                    m_game[destination.first][destination.second] = WKING;
                                    m_game[destination.first+1][destination.second+1] = BCELL;
                                    white_move = true;
                                }
                                else {
                                    white_move = false;
                                }
                            } else {
                                white_move = false;
                            }
                        }
                        else if (destination.first - origin.first == 2) {
                                // jump two spaces down
                                if (destination.second - origin.second == 2) {
                                    if(m_game[destination.first-1][destination.second-1] == BDISK || m_game[destination.first-1][destination.second-1] == BKING) {
                                        // going right
                                        m_blackDisks = m_blackDisks-1;
                                        m_currPlayer = BPLAYER;
                                        m_game[origin.first][origin.second] = BCELL;
                                        m_game[destination.first][destination.second] = WKING;
                                        m_game[destination.first-1][destination.second-1] = BCELL;
                                        white_move = true;
                                    }
                                    else {
                                        white_move = false;
                                    }
                                } else if (destination.second - origin.second == -2) {
                                    if(m_game[destination.first-1][destination.second+1] == BDISK || m_game[destination.first-1][destination.second+1] == BKING) {
                                        // going left
                                        m_blackDisks = m_blackDisks - 1;
                                        m_currPlayer = BPLAYER;
                                        m_game[origin.first][origin.second] = BCELL;
                                        m_game[destination.first][destination.second] = WKING;
                                        m_game[destination.first-1][destination.second+1] = BCELL;
                                        white_move = true;
                                    }
                                    else {
                                        white_move = false;
                                    }
                                } else {
                                    white_move = false;
                                }
                        } else {
                            white_move = false;
                        }
                    } else {
                        white_move = false;
                    }
                }else {
                    white_move = false;
                }
            }
        }
    }

    if (origin_exist == true && destination_exist == true && (white_move == true || black_move == true)) {
        return true;
    }
    else {
        return false;
    }
}
// Name: setGameState
// Desc - sets the board to your liking
// Preconditions - None
// Postconditions - sets the member variable to the param and set the board to your liking
void Checkers::setGameState(CELL game[], int n, PLAYER player){
    if(n == (m_numRows * m_numColumns)) {
        m_currPlayer = player;

        int counter = 0;
        for (int i = 0; i < m_numRows; i++) {
            for (int j = 0; j < m_numColumns; j++) {
                // the counter keeps track of the number and using rows/columns allows the info to move on
                // to the next row instead of continuing in a straight line
                if (game[counter] != "") {
                    m_game[i][j] = game[counter];
                }
                counter++;
            }
        }
    }
}

void Checkers::dumpGame(){
    if (m_numRows > 0 && m_numColumns > 0 && m_game != nullptr){
        cout << "  ";
        for (int k=0;k<m_numColumns;k++){
            cout << k << " ";
        }
        cout << endl;
        for (int i=1;i <= m_numRows;i++){
            cout << i-1 << " ";
            for (int j=1;j<=m_numColumns;j++){
                cout << m_game[i-1][j-1];
            }
            cout << endl;
        }
        cout << endl;
    }
}


