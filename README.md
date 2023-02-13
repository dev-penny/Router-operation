# Router operation
Router operation simulation

In this project we simulate the operation of routers that are available on a network. First, the user types in the number of routers and their details:
* Id
* Data management speed (receiving - sending)
* Maximum number of packages that can be managed
* Percentage of load

The application processes the information. Whenever a packet arrives at a router, it will decide which router to forward it to until reaches the destination.

Each router receives packets according to the routing table. We assume that each packet needs a random period of time to be processed. Obviously it's advisable to avoid a router that exhibits a high load rate which means that it has reached the maximum number of packets that can be managed.
