#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

/* Change this constant to contain your full first and last name (middle is ok too).
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */
const string kYourName = "Omkar Halleppanawar";

/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "ESWSSEWNNENESSSNNNESSS";
const string kPathOutOfTwistyMaze = "SNNSWENWSWSN";

/*
 * checks to see if any 3 required items are in current cell
 * sets found to true if present
 */
void inspectCell(MazeCell* cell, bool& fS, bool& fP, bool& fW) {
    // check if spellbook/potion/wand on current cell
    if (cell->whatsHere == "Spellbook") {
        fS = true;
    } else if (cell->whatsHere == "Potion") {
        fP = true;
    } else if (cell->whatsHere == "Wand") {
        fW = true;
    }
}

/*
 * moves cell to next pointer based on char given (N/S/E/W)
 */
void goNext(char ch, MazeCell* &cell) {
    // move to next pointer
    if (ch == 'N') {
        cell = cell->north;
    } else if (ch == 'S') {
        cell = cell->south;
    } else if (ch == 'E') {
        cell = cell->east;
    } else if (ch == 'W') {
        cell = cell->west;
    }
}

/*
 * takes a start cell and given path and returns whether it is
 * a valid path or not
 */
bool isPathToFreedom(MazeCell *start, const string& moves) {
    bool foundSpellbook = false;
    bool foundPotion = false;
    bool foundWand = false;
    MazeCell* cell = start;
    // check if spellbook/potion/wand on start cell
    inspectCell(cell, foundSpellbook, foundPotion, foundWand);
    for (auto& ch : moves) {
        // check if character is valid or not
        if (ch != 'N' && ch != 'S' && ch != 'E' && ch != 'W') {
            return false;
        }
        goNext(ch, cell);
        // check if pointer is nullptr
        if (cell == nullptr) {
            return false;
        }
        inspectCell(cell, foundSpellbook, foundPotion, foundWand);
    }
    if (!foundSpellbook || !foundWand || !foundPotion) {
        return false;
    }
    return true;
}
