// InProgress.h
#ifndef _INPROGRESS_H
#define _INPROGRESS_H

#include "board.h"

class InProgress : public board {
public:
    void MoveToCompleted(board& destinationBoard, size_t taskIndex);
};

#endif // _INPROGRESS_H
