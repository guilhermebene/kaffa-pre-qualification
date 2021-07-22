# Exercise 7 - Entity Relationship Diagram - Simple Order Manager

In this system, three tables are required:

* Clients
* Products
* Orders

## Relationships:

Simplified description:

* Client has 0 or N (many) orders
* An order has only one client
* An order has 1 or N (many) products
* A product can be a part of 0 or N (many) orders
* A product can be related to N (many) clients
* A client can have N (many) products