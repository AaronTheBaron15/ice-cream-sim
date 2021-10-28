# ice-cream-sim
Simulates an ice cream shop's inventory and customer orders over a certain number of days.

Uses file I/O to take information about ice cream flavors, toppings, and bases. Additionally, has a list of names to use for customers.

We define ice cream as a class with three member variables (all of which are strings): base, flavor, and topping. Nothing too fancy for this other than getters and setters, however we did include an operator overload for stream insertion so that we can easily print all of the information about the ice cream.

Customers have member variable for name and for preferences, which is a vector of IceCream variables. The customer can be initialized so that it randomly generates a name and preferences based on four input vectors. The customer also has a function which randomly generates preferences, allowing a arbitary number of preferences to be generated based on bases, flavors, and toppings (all of which are vectors of strings). Stream insertion operator overload is also used for this class.

The Shop class helps bring the ice cream and customer classes together. The shop takes into account the different flavors, toppings, and bases for ice cream and the number of servings available per flavor, topping, and base. For our purposes, we assume that one serving is enough for one person, so each ice cream has one serving of the flavor, topping, and base. The shop also utilizes the queue data structure to help manage the line of customers. We also keep track of the amount of money the shop has. The shop spends money on new flavors when needed, but makes money when customers get their ice cream. In the shop, customers can make their order based on preferences and availability of preferences.

We run our simulation over a period of 10-15 days and keep track of total number of customers, the money the shop has, and list out all of the orders as the simulation runs.
