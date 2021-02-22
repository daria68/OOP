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

## Patients of a family doctor

  A family doctor wants to know, at any time, the risk of acquiring a cardiovascular disease for patients in his office. The main risk factors are determined by: the total value of cholesterol and blood pressure levels. Total cholesterol values can be: below 200 mg / dl - optimal; between 200-239 mg / dl - normal and over 240 mg / dl - increased. The upper normal blood pressure is 130-139. Each patient appears in the family doctor's record with name, surname, age and address. Cholesterol and blood pressure values are recorded inside along with the date the tests were done.
  For patients over 40, smoking and sedentary lifestyle are added to the risk factors. In this case, the medical record must indicate the smoker or non-smoker and indicate sedentary lifestyle (low, medium or high). These values can evolve over time, depending on the patient's lifestyle.
  A patient has a cardiovascular risk either if the result of any of the mentioned analyzes exceeds the upper normal value, or if he has a family history (in the case of children), or if he is a smoker and has a high degree of sedentary lifestyle (in the case of patients over 40 years). A patient has a high cardiovascular risk if at least two of the cardiovascular risk situations are present.
  The program should enable the ntroduction of patients, one by one, together with their medical information, in the most convenient format, create a data structure in which to add patient records and display patient medical information in a standard format, depending on the doctor's choice.
  The doctor can choose between displaying medical information for:
  * 1. all patients.
  * 2. all adult patients with high cardiovascular risk factor.
  * 3. all pediatric patients with cardiovascular risk factor.
  * 4. all patients who have the (family) name equal to a given name.
