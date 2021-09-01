# Router-operation
Router operation simulation

In this project we simulate the operation of routers that are available on a network. Assume that N routers are available on the network and each of them is characterized by:
* Id
* Data management speed (receiving - sending)
* Maximum number of packages that can be managed
* Percentage of load

Each router receives packets which it routes according to the routing table it adopts. We assume that each package needs a random period of time to be processed. Obviously when packet routing, it is advisable to avoid a router that exhibits a high load rate which means that it has reached the maximum number of packets that can be managed simultaneously.
