/*
 * grid.h
 * Abstraction designed to support 2D grid. With this we can create
 * mazes and labyrinths later.
 */

#pragma once

#include <iostream>
#include <exception>
#include <stdexcept>
#include <algorithm>

using namespace std;

template<typename T>
class Grid {
private:
  struct CELL {
    CELL* Next;
    T Val;
    size_t NumCols;  // total # of columns (0..NumCols-1)
    CELL(CELL* _Next = nullptr, T _Val = T(), size_t _NumCols = 0) {
        Next = _Next;
        Val = _Val;
        NumCols = _NumCols;
    }
  };

  size_t NumRows;  // total # of rows (0..NumRows-1)
  CELL** Rows;     // C array of linked lists
public:
  /*
   * default constructor:
   *
   * Called automatically by C++ to construct a 4x4 Grid.  All
   * elements are initialized to the default value of T.
   */
  Grid() {
    // initialize 4 rows
    Rows = new CELL*[4];
    NumRows = 4;

    // allocate the first cell of the linked list with default value:
    for (size_t r = 0; r < NumRows; ++r) {
        Rows[r] = new CELL(nullptr, T(), 4);
        CELL* cur = Rows[r];

        // create the linked list for this row.
        for(size_t c = 1; c < Rows[r]->NumCols; ++c) {
            cur->Next = new CELL(nullptr, T());
            cur = cur->Next;
        }
    }

  }

  /*
   * parameterized constructor:
   *
   * Called automatically by C++ to construct a Grid with R rows,
   * where each row has C columns. All elements are initialized to
   * the default value of T.
   */
  Grid(size_t R, size_t C) {
      if (R <= 0 || C <= 0) {
          throw invalid_argument("Invalid input for R/C.");
      }
      // initialize R rows
      Rows = new CELL*[R];
      NumRows = R;

      // allocate the first cell of the linked list with given value:
      for (size_t r = 0; r < NumRows; ++r) {
          Rows[r] = new CELL(nullptr, T(), C);
          CELL* cur = Rows[r];

          // create the linked list for this row.
          for(size_t c = 1; c < Rows[r]->NumCols; ++c) {
              cur->Next = new CELL(nullptr, T());
              cur = cur->Next;
          }
      }
  }
    
  /*
   * destructor:
   *
   * Called automatically by C++ to free the memory associated by the vector.
   * Deletes node in linked list then deletes linked list
   */
  virtual ~Grid() {
      if (Rows != nullptr) {
          for (size_t r = 0; r < this->NumRows; ++r) {
              CELL* curr = Rows[r];
              CELL* prev = nullptr;
              while (curr != nullptr) {
                  prev = curr;
                  curr = curr->Next;
                  delete prev;
              }
          }
          delete[] Rows;
      }
  }


  /*
   * copy constructor:
   *
   * Called automatically by C++ to construct a Grid that contains a
   * copy of an existing Grid. Takes grid to be copied as parameter.
   */
  Grid(const Grid<T>& other) {
      this->Rows = new CELL*[other.NumRows];
      this->NumRows = other.NumRows;
      
      // allocate the first cell of the linked list with given value:
      for (size_t r = 0; r < other.NumRows; ++r) {
          this->Rows[r] = new CELL(nullptr, other.Rows[r]->Val, other.Rows[r]->NumCols);
          CELL* curOther = other.Rows[r];
          CELL* curThis = this->Rows[r];
          // create the linked list for this row.
          for(size_t c = 1; c < other.Rows[r]->NumCols; ++c) {
              curThis->Next = new CELL(nullptr, curOther->Next->Val);
              curOther = curOther->Next;
              curThis = curThis->Next;
          }
      }
  }
    
  /*
   * copy operator=
   *
   * Called when you assign one vector into another, i.e. this = other;
   */
  Grid& operator=(const Grid& other) {
      if (this == &other) {
          return *this;
      }
      for (size_t r = 0; r < this->NumRows; ++r) {
          CELL* curr = this->Rows[r];
          CELL* prev = nullptr;
          while (curr != nullptr) {
            prev = curr;
            curr = curr->Next;
            delete prev;
          }
      }
      delete[] this->Rows;
      
      this->Rows = new CELL*[other.NumRows];
      this->NumRows = other.NumRows;
      // allocate the first cell of the linked list with given value:
      for (size_t r = 0; r < other.NumRows; ++r) {
          this->Rows[r] = new CELL(nullptr, other.Rows[r]->Val, other.Rows[r]->NumCols);
          CELL* curOther = other.Rows[r];
          CELL* curThis = this->Rows[r];
          // create the linked list for this row.
          for(size_t c = 1; c < other.Rows[r]->NumCols; ++c) {
              curThis->Next = new CELL(nullptr, curOther->Next->Val);
              curOther = curOther->Next;
              curThis = curThis->Next;
          }
      }
      return *this;
  }

  /*
   * numrows
   *
   * Returns the # of rows in the Grid.  The indices for these rows
   * are 0..numrows-1.
   */
  size_t numrows() const {
      return NumRows;
  }
  

  /*
   * numcols
   *
   * Returns the # of columns in row r (parameter.  The indices for these columns
   * are 0..numcols-1.
   */
  size_t numcols(size_t r) const {
      if (r < 0 || r >= NumRows) {
          throw out_of_range("Invalid: r out of bounds.");
      }
      return Rows[r]->NumCols;

  }


  /*
   * size
   *
   * Returns the total # of elements in the grid.
   */
  size_t size() const {
      /*
      int elements = 0;
      for (int i = 0; i < NumRows; i++) {
          elements += Rows[i]->NumCols;
      }
      return elements;
       */
      return NumRows * Rows[0]->NumCols;
  }


  /*
   * ()
   *
   * Returns a reference to the element at location (r, c); this
   * allows you to access the element or change it:
   *
   *    grid(r, c) = ...
   *    cout << grid(r, c) << endl;
   */
  T& operator()(size_t r, size_t c) {
      if (r < 0 || c < 0 || r >= NumRows || c >= Rows[r]->NumCols) {
          throw out_of_range("Invalid: r/c out of bounds.");
      }
      CELL* curr = Rows[r];
      for (int i = 0; i < c; i++) {
          curr = curr->Next;
      }
      return curr->Val;
  }

  /*
   * _output
   *
   *  Outputs the contents of the grid; for debugging purposes.  This is not
   * tested.
   */
  void _output() {

      // TO DO:  Write this function.
      for (size_t r = 0; r < NumRows; r++) {
          CELL* cur = Rows[r];
          while (cur != nullptr) {
              cout << cur->Val << " ";
              cur = cur->Next;
          }
          cout << endl;
      }
  }

};
