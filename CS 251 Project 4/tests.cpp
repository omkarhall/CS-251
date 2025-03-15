#include <gtest/gtest.h>
#include <vector>
#include <map>
#include <sstream>
#include <set>
#include "maze.h"
#include "grid.h"
#include "EscapeTheLabyrinth.h"


TEST(grid, defaultConstructor){
    // tests for int
    Grid<int> g1;
    EXPECT_EQ(g1.size(), 16);
    EXPECT_EQ(g1.numrows(), 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(g1.numcols(i), 4);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(g1(i, j), 0);
        }
    }

    // tests for double
    Grid<double> g2;
    EXPECT_EQ(g2.size(), 16);
    EXPECT_EQ(g2.numrows(), 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(g2.numcols(i), 4);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(g2(i, j), 0);
        }
    }

    // tests for char
    Grid<char> g3;
    EXPECT_EQ(g3.size(), 16);
    EXPECT_EQ(g3.numrows(), 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(g3.numcols(i), 4);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(g3(i, j), '\0');
        }
    }

    // tests for float
    Grid<float> g4;
    EXPECT_EQ(g4.size(), 16);
    EXPECT_EQ(g4.numrows(), 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(g4.numcols(i), 4);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            EXPECT_EQ(g4(i, j), 0);
        }
    }
}

// TO DO:  Write many TESTs, at least one for, if not more,
// for each member function.  Each tests should have 100s of assertions.
TEST(grid, paramConstructor) {
    // tests for int
    Grid<int> g1(5, 5);
    EXPECT_EQ(g1.size(), 25);
    EXPECT_EQ(g1.numrows(), 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(g1.numcols(i), 5);
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            EXPECT_EQ(g1(i, j), 0);
        }
    }
    // rectangular grid
    Grid<int> g2(3, 5);
    EXPECT_EQ(g2.size(), 15);
    EXPECT_EQ(g2.numrows(), 3);
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(g2.numcols(i), 5);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            EXPECT_EQ(g2(i, j), 0);
        }
    }
    
    // tests for double
    Grid<double> g3(5, 5);
    EXPECT_EQ(g3.size(), 25);
    EXPECT_EQ(g3.numrows(), 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(g3.numcols(i), 5);
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            EXPECT_EQ(g3(i, j), 0);
        }
    }
    // rectangular grid
    Grid<double> g4(6, 3);
    EXPECT_EQ(g4.size(), 18);
    EXPECT_EQ(g4.numrows(), 6);
    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(g4.numcols(i), 3);
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(g4(i, j), 0);
        }
    }
    
    // tests for char
    Grid<char> g5(7, 7);
    EXPECT_EQ(g5.size(), 49);
    EXPECT_EQ(g5.numrows(), 7);
    for (int i = 0; i < 7; i++) {
        EXPECT_EQ(g5.numcols(i), 7);
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            EXPECT_EQ(g5(i, j), '\0');
        }
    }
    // rectangular grid
    Grid<char> g6(2, 10);
    EXPECT_EQ(g6.size(), 20);
    EXPECT_EQ(g6.numrows(), 2);
    for (int i = 0; i < 2; i++) {
        EXPECT_EQ(g6.numcols(i), 10);
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 10; j++) {
            EXPECT_EQ(g6(i, j), '\0');
        }
    }
    
    // tests for float
    Grid<float> g7(5, 5);
    EXPECT_EQ(g7.size(), 25);
    EXPECT_EQ(g7.numrows(), 5);
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(g7.numcols(i), 5);
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            EXPECT_EQ(g7(i, j), 0);
        }
    }
    // rectangular grid
    Grid<float> g8(4, 7);
    EXPECT_EQ(g8.size(), 28);
    EXPECT_EQ(g8.numrows(), 4);
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(g8.numcols(i), 7);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            EXPECT_EQ(g8(i, j), 0);
        }
    }
}

TEST(grid, copyConstructorInt) {
    // tests for int
    // square grid
    Grid<int> g1(7, 7);
    vector<vector<int>> v1;
    // create vector with random values 0-9
    for (int i = 0; i < 7; i++) {
        vector<int> temp;
        for (int j = 0; j < 7; j++) {
            temp.push_back(rand() % 10);
        }
        v1.push_back(temp);
    }
    // copy numbers into g1
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            g1(i, j) = v1[i][j];
        }
    }
    // test g1 and g2 to see if they are the same
    Grid<int> g2(g1);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            EXPECT_EQ(g1(i, j), g2(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g1.numrows(), g2.numrows());
    for (int i = 0; i < 7; i++) {
        EXPECT_EQ(g1.numcols(i), g2.numcols(i));
    }
    EXPECT_EQ(g1.size(), g2.size());

    // rectangle grid
    Grid<int> g3(3, 5);
    vector<vector<int>> v2;
    for (int i = 0; i < 3; i++) {
        vector<int> temp2;
        for (int j = 0; j < 5; j++) {
            temp2.push_back(rand() % 10);
        }
        v2.push_back(temp2);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            g3(i, j) = v2[i][j];
        }
    }
    Grid<int> g4(g3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            EXPECT_EQ(g3(i, j), g4(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g3.numrows(), g4.numrows());
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(g3.numcols(i), g4.numcols(i));
    }
    EXPECT_EQ(g3.size(), g4.size());

    // change one grid make sure other does not change
    int changeVal1 = g4(0, 0);
    int changeVal2 = g4(2, 3);
    g3(0, 0) = 2;
    g3(2, 3) = 3;
    EXPECT_EQ(changeVal1, g4(0, 0));
    EXPECT_EQ(changeVal2, g4(2, 3));
}

TEST(grid, copyConstructorDouble) {
    // tests for double
    // square grid
    Grid<double> g5(5, 5);
    vector<vector<double>> v3;
    // create vector with random values 0-9
    for (int i = 0; i < 5; i++) {
        vector<double> temp3;
        for (int j = 0; j < 5; j++) {
            temp3.push_back(double(rand() % 10));
        }
        v3.push_back(temp3);
    }
    // copy numbers into g5
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            g5(i, j) = v3[i][j];
        }
    }
    // test g5 and g6 to see if they are the same
    Grid<double> g6(g5);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            EXPECT_EQ(g5(i, j), g6(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g5.numrows(), g6.numrows());
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(g5.numcols(i), g6.numcols(i));
    }
    EXPECT_EQ(g5.size(), g6.size());
    // rectangle grid
    Grid<double> g7(4, 3);
    vector<vector<double>> v4;
    for (int i = 0; i < 4; i++) {
        vector<double> temp4;
        for (int j = 0; j < 3; j++) {
            temp4.push_back(double(rand() % 10));
        }
        v4.push_back(temp4);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            g7(i, j) = v4[i][j];
        }
    }
    Grid<double> g8(g7);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(g7(i, j), g8(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g7.numrows(), g8.numrows());
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(g7.numcols(i), g8.numcols(i));
    }
    EXPECT_EQ(g7.size(), g8.size());
    
    // change one grid make sure other does not change
    double changeVal1 = g8(0, 0);
    double changeVal2 = g8(2, 2);
    g7(0, 0) = 2.0;
    g7(2, 2) = 3.0;
    EXPECT_EQ(changeVal1, g8(0, 0));
    EXPECT_EQ(changeVal2, g8(2, 2));
}

TEST(grid, copyConstructorChar) {
    // tests for char
    // square grid
    Grid<char> g1(10, 10);
    vector<vector<char>> v1;
    // create vector with random letters
    for (int i = 0; i < 10; i++) {
        vector<char> temp;
        for (int j = 0; j < 10; j++) {
            temp.push_back('a' + rand() % 26);
        }
        v1.push_back(temp);
    }
    // copy letters into g1
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            g1(i, j) = v1[i][j];
        }
    }
    // test g1 and g2 to see if they are the same
    Grid<char> g2(g1);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            EXPECT_EQ(g1(i, j), g2(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g1.numrows(), g2.numrows());
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(g1.numcols(i), g2.numcols(i));
    }
    EXPECT_EQ(g1.size(), g2.size());
    // rectangle grid
    Grid<char> g3(6, 3);
    vector<vector<char>> v2;
    for (int i = 0; i < 6; i++) {
        vector<char> temp2;
        for (int j = 0; j < 3; j++) {
            temp2.push_back('a' + rand() % 26);
        }
        v2.push_back(temp2);
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            g3(i, j) = v2[i][j];
        }
    }
    Grid<char> g4(g3);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(g3(i, j), g4(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g3.numrows(), g4.numrows());
    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(g3.numcols(i), g4.numcols(i));
    }
    EXPECT_EQ(g3.size(), g4.size());
    
    // change one grid make sure other does not change
    char changeVal1 = g4(0, 0);
    char changeVal2 = g4(3, 2);
    g3(0, 0) = 'a';
    g3(3, 2) = 'b';
    EXPECT_EQ(changeVal1, g4(0, 0));
    EXPECT_EQ(changeVal2, g4(3, 2));
}

TEST(grid, copyConstructorFloat) {
    // tests for float
    // square grid
    Grid<float> g1(8, 8);
    vector<vector<float>> v1;
    // create vector with random values 0-9
    for (int i = 0; i < 8; i++) {
        vector<float> temp;
        for (int j = 0; j < 8; j++) {
            temp.push_back(rand() % 10);
        }
        v1.push_back(temp);
    }
    // copy numbers into g1
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            g1(i, j) = v1[i][j];
        }
    }
    // test g1 and g2 to see if they are the same
    Grid<float> g2(g1);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            EXPECT_EQ(g1(i, j), g2(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g1.numrows(), g2.numrows());
    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(g1.numcols(i), g2.numcols(i));
    }
    EXPECT_EQ(g1.size(), g2.size());
    // rectangle grid
    Grid<float> g3(2, 11);
    vector<vector<float>> v2;
    for (int i = 0; i < 2; i++) {
        vector<float> temp2;
        for (int j = 0; j < 11; j++) {
            temp2.push_back(rand() % 10);
        }
        v2.push_back(temp2);
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 11; j++) {
            g3(i, j) = v2[i][j];
        }
    }
    Grid<float> g4(g3);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 11; j++) {
            EXPECT_EQ(g3(i, j), g4(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g3.numrows(), g4.numrows());
    for (int i = 0; i < 2; i++) {
        EXPECT_EQ(g3.numcols(i), g4.numcols(i));
    }
    EXPECT_EQ(g3.size(), g4.size());
    
    // change one grid make sure other does not change
    float changeVal1 = g4(0, 0);
    float changeVal2 = g4(1, 7);
    g3(0, 0) = 2;
    g3(1, 7) = 3;
    EXPECT_EQ(changeVal1, g4(0, 0));
    EXPECT_EQ(changeVal2, g4(1, 7));
}

TEST(grid, copyOperatorInt) {
    // tests for int
    // square grid
    Grid<int> g1(7, 7);
    vector<vector<int>> v1;
    // create vector with random values 0-9
    for (int i = 0; i < 7; i++) {
        vector<int> temp;
        for (int j = 0; j < 7; j++) {
            temp.push_back(rand() % 10);
        }
        v1.push_back(temp);
    }
    // copy numbers into g1
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            g1(i, j) = v1[i][j];
        }
    }
    // test g1 and g2 to see if they are the same
    Grid<int> g2(3, 3);
    g2 = g1;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            EXPECT_EQ(g1(i, j), g2(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g1.numrows(), g2.numrows());
    for (int i = 0; i < 7; i++) {
        EXPECT_EQ(g1.numcols(i), g2.numcols(i));
    }
    EXPECT_EQ(g1.size(), g2.size());

    // rectangle grid
    Grid<int> g3(3, 5);
    vector<vector<int>> v2;
    for (int i = 0; i < 3; i++) {
        vector<int> temp2;
        for (int j = 0; j < 5; j++) {
            temp2.push_back(rand() % 10);
        }
        v2.push_back(temp2);
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            g3(i, j) = v2[i][j];
        }
    }
    Grid<int> g4(4, 5);
    g4 = g3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            EXPECT_EQ(g3(i, j), g4(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g3.numrows(), g4.numrows());
    for (int i = 0; i < 3; i++) {
        EXPECT_EQ(g3.numcols(i), g4.numcols(i));
    }
    EXPECT_EQ(g3.size(), g4.size());

    // change one grid make sure other does not change
    int changeVal1 = g4(0, 0);
    int changeVal2 = g4(2, 3);
    g3(0, 0) = 2;
    g3(2, 3) = 3;
    EXPECT_EQ(changeVal1, g4(0, 0));
    EXPECT_EQ(changeVal2, g4(2, 3));
}

TEST(grid, copyOperatorDouble) {
    // tests for double
    // square grid
    Grid<double> g5(5, 5);
    vector<vector<double>> v3;
    // create vector with random values 0-9
    for (int i = 0; i < 5; i++) {
        vector<double> temp3;
        for (int j = 0; j < 5; j++) {
            temp3.push_back(double(rand() % 10));
        }
        v3.push_back(temp3);
    }
    // copy numbers into g5
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            g5(i, j) = v3[i][j];
        }
    }
    // test g5 and g6 to see if they are the same
    Grid<double> g6(4, 4);
    g6 = g5;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            EXPECT_EQ(g5(i, j), g6(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g5.numrows(), g6.numrows());
    for (int i = 0; i < 5; i++) {
        EXPECT_EQ(g5.numcols(i), g6.numcols(i));
    }
    EXPECT_EQ(g5.size(), g6.size());
    // rectangle grid
    Grid<double> g7(4, 3);
    vector<vector<double>> v4;
    for (int i = 0; i < 4; i++) {
        vector<double> temp4;
        for (int j = 0; j < 3; j++) {
            temp4.push_back(double(rand() % 10));
        }
        v4.push_back(temp4);
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            g7(i, j) = v4[i][j];
        }
    }
    Grid<double> g8(8, 9);
    g8 = g7;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(g7(i, j), g8(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g7.numrows(), g8.numrows());
    for (int i = 0; i < 4; i++) {
        EXPECT_EQ(g7.numcols(i), g8.numcols(i));
    }
    EXPECT_EQ(g7.size(), g8.size());
    
    // change one grid make sure other does not change
    double changeVal1 = g8(0, 0);
    double changeVal2 = g8(2, 2);
    g7(0, 0) = 2.0;
    g7(2, 2) = 3.0;
    EXPECT_EQ(changeVal1, g8(0, 0));
    EXPECT_EQ(changeVal2, g8(2, 2));
}

TEST(grid, copyOperatorChar) {
    // tests for char
    // square grid
    Grid<char> g1(10, 10);
    vector<vector<char>> v1;
    // create vector with random letters
    for (int i = 0; i < 10; i++) {
        vector<char> temp;
        for (int j = 0; j < 10; j++) {
            temp.push_back('a' + rand() % 26);
        }
        v1.push_back(temp);
    }
    // copy letters into g1
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            g1(i, j) = v1[i][j];
        }
    }
    // test g1 and g2 to see if they are the same
    Grid<char> g2(7, 7);
    g2 = g1;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            EXPECT_EQ(g1(i, j), g2(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g1.numrows(), g2.numrows());
    for (int i = 0; i < 10; i++) {
        EXPECT_EQ(g1.numcols(i), g2.numcols(i));
    }
    EXPECT_EQ(g1.size(), g2.size());
    // rectangle grid
    Grid<char> g3(6, 3);
    vector<vector<char>> v2;
    for (int i = 0; i < 6; i++) {
        vector<char> temp2;
        for (int j = 0; j < 3; j++) {
            temp2.push_back('a' + rand() % 26);
        }
        v2.push_back(temp2);
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            g3(i, j) = v2[i][j];
        }
    }
    Grid<char> g4(12, 3);
    g4 = g3;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            EXPECT_EQ(g3(i, j), g4(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g3.numrows(), g4.numrows());
    for (int i = 0; i < 6; i++) {
        EXPECT_EQ(g3.numcols(i), g4.numcols(i));
    }
    EXPECT_EQ(g3.size(), g4.size());
    
    // change one grid make sure other does not change
    char changeVal1 = g4(0, 0);
    char changeVal2 = g4(3, 2);
    g3(0, 0) = 'a';
    g3(3, 2) = 'b';
    EXPECT_EQ(changeVal1, g4(0, 0));
    EXPECT_EQ(changeVal2, g4(3, 2));
}

TEST(grid, copyOperatorFloat) {
    // tests for float
    // square grid
    Grid<float> g1(8, 8);
    vector<vector<float>> v1;
    // create vector with random values 0-9
    for (int i = 0; i < 8; i++) {
        vector<float> temp;
        for (int j = 0; j < 8; j++) {
            temp.push_back(rand() % 10);
        }
        v1.push_back(temp);
    }
    // copy numbers into g1
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            g1(i, j) = v1[i][j];
        }
    }
    // test g1 and g2 to see if they are the same
    Grid<float> g2(11, 11);
    g2 = g1;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            EXPECT_EQ(g1(i, j), g2(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g1.numrows(), g2.numrows());
    for (int i = 0; i < 8; i++) {
        EXPECT_EQ(g1.numcols(i), g2.numcols(i));
    }
    EXPECT_EQ(g1.size(), g2.size());
    // rectangle grid
    Grid<float> g3(2, 11);
    vector<vector<float>> v2;
    for (int i = 0; i < 2; i++) {
        vector<float> temp2;
        for (int j = 0; j < 11; j++) {
            temp2.push_back(rand() % 10);
        }
        v2.push_back(temp2);
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 11; j++) {
            g3(i, j) = v2[i][j];
        }
    }
    Grid<float> g4(2, 2);
    g4 = g3;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 11; j++) {
            EXPECT_EQ(g3(i, j), g4(i, j));
        }
    }
    // check rows, cols, size are same
    EXPECT_EQ(g3.numrows(), g4.numrows());
    for (int i = 0; i < 2; i++) {
        EXPECT_EQ(g3.numcols(i), g4.numcols(i));
    }
    EXPECT_EQ(g3.size(), g4.size());
    
    // change one grid make sure other does not change
    float changeVal1 = g4(0, 0);
    float changeVal2 = g4(1, 7);
    g3(0, 0) = 2;
    g3(1, 7) = 3;
    EXPECT_EQ(changeVal1, g4(0, 0));
    EXPECT_EQ(changeVal2, g4(1, 7));
}

TEST(grid, numrowsInt) {
    // tests for int
    // square grid
    Grid<int> g1(3, 3);
    EXPECT_EQ(g1.numrows(), 3);
    Grid<int> g2(5, 5);
    EXPECT_EQ(g2.numrows(), 5);
    // rectangular Grid
    Grid<int> g3(7, 4);
    EXPECT_EQ(g3.numrows(), 7);
    Grid<int> g4(13, 6);
    EXPECT_EQ(g4.numrows(), 13);
}

TEST(grid, numrowsDouble) {
    // tests for double
    // square grid
    Grid<double> g1(2, 2);
    EXPECT_EQ(g1.numrows(), 2);
    Grid<double> g2(4, 4);
    EXPECT_EQ(g2.numrows(), 4);
    // rectangular Grid
    Grid<double> g3(8, 4);
    EXPECT_EQ(g3.numrows(), 8);
    Grid<double> g4(12, 6);
    EXPECT_EQ(g4.numrows(), 12);
}

TEST(grid, numrowsChar) {
    // tests for char
    // square grid
    Grid<char> g1(6, 6);
    EXPECT_EQ(g1.numrows(), 6);
    Grid<char> g2(4, 4);
    EXPECT_EQ(g2.numrows(), 4);
    // rectangular Grid
    Grid<char> g3(8, 10);
    EXPECT_EQ(g3.numrows(), 8);
    Grid<char> g4(9, 6);
    EXPECT_EQ(g4.numrows(), 9);
}

TEST(grid, numrowsFloat) {
    // tests for float
    // square grid
    Grid<float> g1(10, 10);
    EXPECT_EQ(g1.numrows(), 10);
    Grid<float> g2(7, 7);
    EXPECT_EQ(g2.numrows(), 7);
    // rectangular Grid
    Grid<float> g3(7, 11);
    EXPECT_EQ(g3.numrows(), 7);
    Grid<float> g4(15, 3);
    EXPECT_EQ(g4.numrows(), 15);
    
}

TEST(grid, numcolsInvalid) {
    // tests for numcols with invalid rows
    // tests for int
    Grid<int> g1(10, 10);
    try {
        g1.numcols(-1);
    } catch(exception& e) {
        string s1(e.what());
        EXPECT_EQ(s1, "Invalid: r out of bounds.");
    }
    //tests for double
    Grid<double> g2(7, 7);
    try {
        g2.numcols(8);
    } catch(exception& e) {
        string s2(e.what());
        EXPECT_EQ(s2, "Invalid: r out of bounds.");
    }
    // rectangular Grid
    // tests for char
    Grid<char> g3(7, 11);
    try {
        g3.numcols(-5);
    } catch(exception& e) {
        string s3(e.what());
        EXPECT_EQ(s3, "Invalid: r out of bounds.");
    }
    // tests for float
    Grid<float> g4(15, 3);
    try {
        g1.numcols(15);
    } catch(exception& e) {
        string s4(e.what());
        EXPECT_EQ(s4, "Invalid: r out of bounds.");
    }
}

TEST(grid, numcolsInt) {
    // tests for int
    // square grid
    Grid<int> g1(3, 3);
    EXPECT_EQ(g1.numcols(2), 3);
    Grid<int> g2(5, 5);
    EXPECT_EQ(g2.numcols(1), 5);
    // rectangular Grid
    Grid<int> g3(7, 4);
    EXPECT_EQ(g3.numcols(4), 4);
    Grid<int> g4(13, 6);
    EXPECT_EQ(g4.numcols(5), 6);
}

TEST(grid, numcolsDouble) {
    // tests for double
    // square grid
    Grid<double> g1(2, 2);
    EXPECT_EQ(g1.numcols(0), 2);
    Grid<double> g2(4, 4);
    EXPECT_EQ(g2.numcols(3), 4);
    // rectangular Grid
    Grid<double> g3(8, 4);
    EXPECT_EQ(g3.numcols(1), 4);
    Grid<double> g4(12, 6);
    EXPECT_EQ(g4.numcols(6), 6);
}

TEST(grid, numcolsChar) {
    // tests for char
    // square grid
    Grid<char> g1(6, 6);
    EXPECT_EQ(g1.numcols(2), 6);
    Grid<char> g2(4, 4);
    EXPECT_EQ(g2.numcols(1), 4);
    // rectangular Grid
    Grid<char> g3(8, 10);
    EXPECT_EQ(g3.numcols(4), 10);
    Grid<char> g4(9, 6);
    EXPECT_EQ(g4.numcols(7), 6);
}

TEST(grid, numcolsFloat) {
    // tests for float
    // square grid
    Grid<float> g1(10, 10);
    EXPECT_EQ(g1.numcols(9), 10);
    Grid<float> g2(7, 7);
    EXPECT_EQ(g2.numcols(0), 7);
    // rectangular Grid
    Grid<float> g3(7, 11);
    EXPECT_EQ(g3.numcols(3), 11);
    Grid<float> g4(15, 3);
    EXPECT_EQ(g4.numcols(12), 3);
}

TEST(grid, sizeInt) {
    // tests for int
    // square grid
    Grid<int> g1(3, 3);
    EXPECT_EQ(g1.size(), 9);
    Grid<int> g2(5, 5);
    EXPECT_EQ(g2.size(), 25);
    // rectangular Grid
    Grid<int> g3(7, 4);
    EXPECT_EQ(g3.size(), 28);
    Grid<int> g4(13, 6);
    EXPECT_EQ(g4.size(), 78);
}

TEST(grid, sizeDouble) {
    // tests for double
    // square grid
    Grid<double> g1(2, 2);
    EXPECT_EQ(g1.size(), 4);
    Grid<double> g2(4, 4);
    EXPECT_EQ(g2.size(), 16);
    // rectangular Grid
    Grid<double> g3(8, 4);
    EXPECT_EQ(g3.size(), 32);
    Grid<double> g4(12, 6);
    EXPECT_EQ(g4.size(), 72);
}

TEST(grid, sizeChar) {
    // tests for char
    // square grid
    Grid<char> g1(6, 6);
    EXPECT_EQ(g1.size(), 36);
    Grid<char> g2(4, 4);
    EXPECT_EQ(g2.size(), 16);
    // rectangular Grid
    Grid<char> g3(8, 10);
    EXPECT_EQ(g3.size(), 80);
    Grid<char> g4(9, 6);
    EXPECT_EQ(g4.size(), 54);
}

TEST(grid, sizeFloat) {
    // tests for float
    // square grid
    Grid<float> g1(10, 10);
    EXPECT_EQ(g1.size(), 100);
    Grid<float> g2(7, 7);
    EXPECT_EQ(g2.size(), 49);
    // rectangular Grid
    Grid<float> g3(7, 11);
    EXPECT_EQ(g3.size(), 77);
    Grid<float> g4(15, 3);
    EXPECT_EQ(g4.size(), 45);
}

TEST(grid, accessInvalidElement) {
    // tests invalid input for () operator
    // tests for int
    Grid<int> g1(10, 10);
    // r < 0
    try {
        g1(-1, 0);
    } catch(exception& e) {
        string s1(e.what());
        EXPECT_EQ(s1, "Invalid: r/c out of bounds.");
    }
    // c < 0
    try {
        g1(0, -1);
    } catch(exception& e) {
        string s1(e.what());
        EXPECT_EQ(s1, "Invalid: r/c out of bounds.");
    }
    //tests for double
    Grid<double> g2(7, 7);
    // r and c < 0
    try {
        g2(-2, -2);
    } catch(exception& e) {
        string s2(e.what());
        EXPECT_EQ(s2, "Invalid: r/c out of bounds.");
    }
    // rectangular Grid
    // tests for char
    Grid<char> g3(3, 8);
    // r and c too big
    try {
        g3(7, 8);
    } catch(exception& e) {
        string s3(e.what());
        EXPECT_EQ(s3, "Invalid: r/c out of bounds.");
    }
    // tests for float
    Grid<float> g4(15, 3);
    // r too big
    try {
        g4(15, 2);
    } catch(exception& e) {
        string s4(e.what());
        EXPECT_EQ(s4, "Invalid: r/c out of bounds.");
    }
    // c too big
    try {
        g4(5, 3);
    } catch(exception& e) {
        string s4(e.what());
        EXPECT_EQ(s4, "Invalid: r/c out of bounds.");
    }
}

TEST(grid, accessElement) {
    // tests () operator
    // tests for int
    // square grid
    // check if values are set and returned correctly
    Grid<int> g1(7, 7);
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            g1(i, j) = i * j;
        }
    }
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            ASSERT_EQ(g1(i, j), i * j);
        }
    }
    
    // tests for double
    // rectangular grid
    // check if values are set and returned correctly
    Grid<double> g2(3, 5);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            g2(i, j) = i * j;
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            ASSERT_EQ(g2(i, j), i * j);
        }
    }
    
    // tests for char
    // square grid
    // check if values are set and returned correctly
    Grid<int> g3(4, 4);
    vector<vector<char>> v1 = { {'a', 'b', 'c', 'd'},
                                {'e', 'f', 'g', 'h'},
                                {'i', 'j', 'k', 'l'},
                                {'m', 'n', 'o', 'p'} };
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            g3(i, j) = v1[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            ASSERT_EQ(g3(i, j), v1[i][j]);
        }
    }
    
    // tests for float
    // rectangular grid
    // check if values are set and returned correctly
    Grid<float> g4(6, 8);
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            g4(i, j) = i * j;
        }
    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            ASSERT_EQ(g4(i, j), i * j);
        }
    }
}

TEST(maze, endOnItem) {
    vector<string> textMaze;
    
    textMaze.push_back("*-* * *-W");
    textMaze.push_back("|     | |");
    textMaze.push_back("*-* * *-*");
    textMaze.push_back("  |   |  ");
    textMaze.push_back("S-*-*-*-*");
    textMaze.push_back("| | |   |");
    textMaze.push_back("*-* P-*-*");
    
    Maze m(textMaze);

    MazeCell* start = m.getStart(0, 0);
    
    // paths where last cell has an item
    EXPECT_TRUE(isPathToFreedom(start, "SESWSENESEENWNEN"));
    EXPECT_TRUE(isPathToFreedom(start, "SESEENNESWSESWWNWW"));
    EXPECT_TRUE(isPathToFreedom(start, "SESESEENWNENSWSWWW"));
    
    // paths that should not pick up all items
    EXPECT_FALSE(isPathToFreedom(start, "WESESEE"));
    EXPECT_FALSE(isPathToFreedom(start, "SESWSENEE"));
    EXPECT_FALSE(isPathToFreedom(start, "SESESEENWNEN"));
    
    // paths that are not legal
    EXPECT_FALSE(isPathToFreedom(start, "NNWE"));
    EXPECT_FALSE(isPathToFreedom(start, "SSWE"));
    EXPECT_FALSE(isPathToFreedom(start, "WWEE"));
}

TEST(maze, bigMaze) {
    vector<string> textMaze;
    
    textMaze.push_back("*-* * *-* *-*");
    textMaze.push_back("|     | |   |");
    textMaze.push_back("*-* * *-*-*-W");
    textMaze.push_back("  |   |     |");
    textMaze.push_back("S-*-*-*-*-*-*");
    textMaze.push_back("| | |   |    ");
    textMaze.push_back("*-* *-*-*-*-*");
    textMaze.push_back("| | |   |   |");
    textMaze.push_back("*-* P-*-*-*-*");

    Maze m(textMaze);

    MazeCell* start = m.getStart(0, 0);
    
    // paths that work
    EXPECT_TRUE(isPathToFreedom(start, "SESWEESSEENNWNEEE"));
    EXPECT_TRUE(isPathToFreedom(start, "SESWSENESSEEEENWWNEEN"));
    EXPECT_TRUE(isPathToFreedom(start, "EWSESWSENESSEENNEEN"));
    
    // paths that should not pick up all items
    EXPECT_FALSE(isPathToFreedom(start, "EWSES"));
    EXPECT_FALSE(isPathToFreedom(start, "SESWEE"));
    EXPECT_FALSE(isPathToFreedom(start, "SESWSSE"));
    
    // paths that are not legal
    EXPECT_FALSE(isPathToFreedom(start, "NNWE"));
    EXPECT_FALSE(isPathToFreedom(start, "SSWE"));
    EXPECT_FALSE(isPathToFreedom(start, "WWEE"));
}
// TO DO:  As you get to each milestone, you can comment out these provided
// tests.  They currently use grid.h and will segfault until you implement
// grid correctly.


// Provided Test: sample maze from handout, make lots more yourself!
TEST(maze, basic) {
    vector<string> textMaze;

    textMaze.push_back("* *-W *");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("S *-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-*-* P");

    Maze m(textMaze);

    MazeCell* start = m.getStart(2, 2);

    /* These paths are the ones in the handout. They all work. */
    EXPECT_TRUE(isPathToFreedom(start, "ESNWWNNEWSSESWWN"));
    EXPECT_TRUE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES"));
    EXPECT_TRUE(isPathToFreedom(start, "WNNEWSSESWWNSEENES"));

    /* These paths don't work, since they don't pick up all items. */
    EXPECT_FALSE(isPathToFreedom(start, "ESNW"));
    EXPECT_FALSE(isPathToFreedom(start, "SWWN"));
    EXPECT_FALSE(isPathToFreedom(start, "WNNE"));

    /* These paths don't work, since they aren't legal paths. */
    EXPECT_FALSE(isPathToFreedom(start, "WW"));
    EXPECT_FALSE(isPathToFreedom(start, "NN"));
    EXPECT_FALSE(isPathToFreedom(start, "EE"));
    EXPECT_FALSE(isPathToFreedom(start, "SS"));
}

// Provided Test: don't allow going through walls
TEST(maze, tryingToGoThroughWalls) {
    vector<string> textMaze;

    textMaze.push_back("* S *");
    textMaze.push_back("     ");
    textMaze.push_back("W * P");
    textMaze.push_back( "     ");
    textMaze.push_back( "* * *");

    Maze m(textMaze);

    MazeCell* start = m.getStart(1, 1);

    EXPECT_FALSE(isPathToFreedom(start, "WNEES"));
    EXPECT_FALSE(isPathToFreedom(start, "NWSEE"));
    EXPECT_FALSE(isPathToFreedom(start, "ENWWS"));
    EXPECT_FALSE(isPathToFreedom(start, "SWNNEES"));
}

// Provided Test: Works when starting on an item
TEST(maze, startOnItem) {
    vector<string> textMaze;

    textMaze.push_back("P-S-W");

    Maze m(textMaze);
    MazeCell* start = m.getStart(0, 0);

    EXPECT_TRUE(isPathToFreedom(start, "EE"));
    start = m.getStart(0, 1);
    EXPECT_TRUE(isPathToFreedom(start, "WEE"));
    start = m.getStart(0, 2);
    EXPECT_TRUE(isPathToFreedom(start, "WW"));

}

// Provided Test: Reports errors if given illegal characters.
TEST(maze, invalidChar) {
    vector<string> textMaze;

    textMaze.push_back("* *-W *");
    textMaze.push_back("| |   |");
    textMaze.push_back("*-* * *");
    textMaze.push_back("  | | |");
    textMaze.push_back("S *-*-*");
    textMaze.push_back("|   | |");
    textMaze.push_back("*-*-* P");

    Maze m(textMaze);
    MazeCell* start = m.getStart(0, 0);

    /* These paths contain characters that aren't even close to permissible. */
    EXPECT_FALSE(isPathToFreedom(start, "Q"));
    EXPECT_FALSE(isPathToFreedom(start, "X"));
    EXPECT_FALSE(isPathToFreedom(start, "!"));
    EXPECT_FALSE(isPathToFreedom(start, "?"));

    EXPECT_FALSE(isPathToFreedom(start, "n"));
    EXPECT_FALSE(isPathToFreedom(start, "s"));
    EXPECT_FALSE(isPathToFreedom(start, "e"));
    EXPECT_FALSE(isPathToFreedom(start, "w"));

    ///* These are tricky - they're legal paths that happen to have an unexpected
    // * character at the end.
    start = m.getStart(2, 2);
    EXPECT_FALSE(isPathToFreedom(start, "ESNWWNNEWSSESWWNQ"));
    EXPECT_FALSE(isPathToFreedom(start, "SWWNSEENWNNEWSSEES!!!"));
    EXPECT_FALSE(isPathToFreedom(start, "WNNEWSSESWWNSEENES??"));

}

//// Provided Test: This tests your personalized regular maze to see if you were
//// able to escape.
TEST(maze, escapeRegularMaze) {
    Maze m(4, 4);
    MazeCell* start = m.mazeFor(kYourName);
    EXPECT_TRUE(isPathToFreedom(start, kPathOutOfRegularMaze));
}

//// Provided Test: This tests your personalized twisty maze to see if you were
//// able to escape.
TEST(maze, escapeTwistyMaze) {
    Maze m(4, 4);
    MazeCell* start = m.twistyMazeFor(kYourName);
    EXPECT_TRUE(isPathToFreedom(start, kPathOutOfTwistyMaze));
}

