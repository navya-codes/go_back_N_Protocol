# go_back_N_Protocol
 It is part of the Automatic Repeat reQuest (ARQ) family of protocols.

Key Features:
	1.	Sliding Window Mechanism:
	•	The sender maintains a window of size N that controls the number of frames it can send without waiting for an acknowledgment (ACK).
	•	The receiver can only accept frames in order, even if frames arrive out of sequence.
	2.	Acknowledgments (ACKs):
	•	The receiver sends an ACK for the last correctly received frame in sequence.
	•	If the sender does not receive an ACK for a frame before a timeout, it retransmits the frame and all subsequent frames (even if they were already sent).
	3.	Retransmission:
	•	When an error or packet loss occurs, the sender “goes back” and retransmits from the last unacknowledged frame.