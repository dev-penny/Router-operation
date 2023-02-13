# Router operation
Router operation simulation

In this project we simulate the operation of routers that are available on a network. First, the user types in the number of routers and their details:
* Id
* Data management speed (receiving - sending)
* Maximum number of packages that can be managed
* Percentage of load

The application processes the information and then through the routing table will receive packets and the output lines to which packets can be sent. So, whenever a packet arrives at a router, it will decide which router to forward it to until it reaches its destination.

Each router receives packets which it routes according to the routing table it adopts. We assume that each package needs a random period of time to be processed. Obviously when packet routing, it is advisable to avoid a router that exhibits a high load rate which means that it has reached the maximum number of packets that can be managed simultaneously.
