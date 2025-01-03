#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int TOTAL_PACKETS = 10; // Total number of packets to send
const int WINDOW_SIZE = 4;    // Sliding window size

// Simulate random packet loss
bool isPacketLost() {
    return rand() % 10 < 2; // 20% chance of packet loss
}

void sendPacket(int packetNumber) {
    cout << "Sending packet " << packetNumber << endl;
}

bool receiveAck(int packetNumber) {
    if (isPacketLost()) {
        cout << "No ACK received for packet " << packetNumber << " (Packet lost)\n";
        return false;
    } else {
        cout << "ACK received for packet " << packetNumber << endl;
        return true;
    }
}


int main() {
    srand(time(0)); // Seed for random number generation

    int base = 0;             // Base of the window
    int nextPacket = 0;       // Next packet to send

    while (base < TOTAL_PACKETS) {
        // Send packets within the window
        while (nextPacket < base + WINDOW_SIZE && nextPacket < TOTAL_PACKETS) {
            sendPacket(nextPacket);
            nextPacket++;
        }

        // Simulate acknowledgment process
        for (int i = base; i < nextPacket; i++) {
            if (!receiveAck(i)) {
                // Retransmit from the base if a packet is lost
                cout << "Retransmitting from packet " << base << "...\n";
                nextPacket = base; // Reset next packet to base
                break;
            }
        }

        // Slide the window forward for successfully acknowledged packets
        while (base < nextPacket && base < TOTAL_PACKETS && receiveAck(base)) {
            base++;
        }
    }

    cout << "All packets sent and acknowledged successfully!\n";
    return 0;
}
