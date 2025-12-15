/*
You are programming the crane software for a container ship. Containers are loaded onto a specific stack order.
However, the ship has a sensitive "Center of Gravity" sensor. At any moment, the captain needs to know the weight of 
the lightest container currently sitting in that specific stack to ensure the ship doesn't tilt too much.
Because the crane moves fast, this safety check must happen instantly O(1) time, without scanning the whole stack.

The Interface:
You must design a CargoStack class with these functions:
- loadContainer(weight): Pushes a container of a certain weight onto the stack.
- unloadContainer(): Removes the top container.
- peekTopWeight(): Returns the weight of the top container.
- getLightestWeight(): Returns the minimum weight currently existing anywhere in the stack.
*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class CargoStack {
private:
    // {val, minAtLevel}
    stack<pair<int, int>> containers; 

public:
    void loadContainer(int weight) {
        int currMin;
        if (containers.empty()) currMin = weight;
        else currMin = min(weight, containers.top().second);
        containers.push({weight, currMin});
    }
    
    void unloadContainer() {
        if (!containers.empty()) containers.pop();
    }
    
    int peekTopWeight() {
        return containers.top().first;
    }
    
    int getLightestWeight() {
        return containers.top().second;
    }
};