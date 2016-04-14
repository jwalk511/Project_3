#include "init.h"

#define MIN_X 0
#define MIN_Y 0
#define MAX_X 275
#define MAX_Y 365

task main() {
    init();
    int coords[2];

    do {
        getPos(coords);
        if (coords == NULL) continue;
        if (coords[0] < MIN_X) {
            StopTask(talk);
            nxtDisplayTextLine(4, "X value too low");
        } else if (coords[0] > MAX_X) {
            StopTask(talk);
            nxtDisplayTextLine(4, "X value too high");
        }
        if (coords[1] < MIN_Y) {
            StopTask(talk);
            nxtDisplayTextLine(4, "Y value too low");
        } else if (coords[1] > MAX_Y) {
            StopTask(talk);
            nxtDisplayTextLine(4, "Y value too high");
        }

        wait1Msec(50);
    } while ((coords[0] == 0) && (coords[1] == 0));

    wait1Msec(10000);

}
