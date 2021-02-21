# OOP
University projects implemented using Object Oriented Programming concepts

## Car Exhibition

Mandatory requirements:
1. use of templates
2. use of STL
3. the use of variables, static functions, constants and a const function
4. use of RTTI concepts related to templates
5. handling exceptions
6. reading the complete information of n objects, storing and displaying them

The sports car fair is organized in May, so that enthusiasts can enjoy themselves
with COUPE, HOT-HATCH models (small and compact hatckback models with
high-performance engines based on regular models), CABRIO (convertible models with
metal or textile roof) and SUPERSPORT (Audi R8 speed cars, Bugatti
Veyron, Lexus LF-A, etc.). Some supersport cars can be sold right within
exhibition, if the transaction is made with payment on the spot.
Data structure: vector or list <pair <car, price >> (the cars sold and the price of
sale, if the car was not sold the price is -1)
Additional requirement:
- Add all relevant fields for modeling this problem.
- To build the Exhibition template class containing the total number of cars on display
(automatically incremented) and a dynamically allocated machine-type object vector.
- To build a specialization for the SUPERSPORT type containing a total number of
exposed supersport cars (automatically decremented when selling a car), no cars
sold (automatically incremented) and two pointer vectors to supersport car objects,
two dynamically allocated structures to manage cars in stock and those
sold. To overload the operator - = to update the data of the class at the sale
a car.

