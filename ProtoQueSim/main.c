#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// Just a demo run
int main() {
    PacketQueue buffer;
    initQueue(&buffer);

    Packet p1 = {1, "Sensor-A", "Controller", 128};
    Packet p2 = {2, "Sensor-B", "Controller", 256};
    Packet p3 = {3, "Sensor-C", "Actuator", 512};

    enqueue(&buffer, p1);
    enqueue(&buffer, p2);
    enqueue(&buffer, p3);

    displayQueue(&buffer);

    dequeue(&buffer);

    Packet p4 = {4, "Sensor-D", "Logger", 64};
    enqueue(&buffer, p4);

    displayQueue(&buffer);

    return 0;
}
