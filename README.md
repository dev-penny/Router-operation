# Router operation simulation
A router is a device that connects two or more packet-switched networks or subnetworks. It serves two primary functions: managing traffic between these networks by forwarding data packets to their intended IP addresses, and allowing multiple devices to use the same Internet connection.

## Description
In this project we simulate the operation of routers that are available on a network. First, the user types in the number of routers and their details.
* Id
* Data management speed (receiving - sending)
* Maximum number of packages that can be managed
* Percentage of load

The application processes the information. Whenever a packet arrives at a router, it performs route processing and distributes forwarding tables until reaches the destination.

Each router receives packets according to the routing table. We assume that each packet needs a random period of time to be processed.
