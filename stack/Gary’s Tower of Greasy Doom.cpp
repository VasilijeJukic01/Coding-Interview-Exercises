/*
You are Gary. Gary is an overworked dishwasher at The Gilded Goblin, the most unhygienic tavern in the kingdom of Algo-Land.
The tavern is busy. Waiters are sprinting into the kitchen and slamming dirty plates onto your washing station.
You are trying to stack these plates into a single vertical tower. However, physics in Algo-Land is governed by the Law of Greasiness.

The Rules:
- Each plate has a Grease Level (an integer).
- The Gravity Rule: You can only place a plate on top of the stack if its Grease Level is less than or equal to the 
plate directly below it. (Basically, a greasier plate on top of a cleaner one will slip off).
- The Collision Rule: If you try to place a plate that is greasier (strictly greater) than the plate at the top of the 
stack, the plate on the stack slides out and shatters.
- The Scraping Effect: Here is the twist. Every time a plate on the stack shatters due to an incoming greasier plate, 
the incoming plate loses 1 unit of Grease (due to the friction of the collision).
- The Chain Reaction: The incoming plate keeps smashing plates and losing grease until:
	- It finds a plate on the stack that is greasier than or equal to itself (so it can sit on top safely).
	- Or the stack becomes empty (it sits on the counter).
	- Or the incoming plate’s Grease Level drops to 0. If a plate hits 0 grease, it is considered "Clean," and Gary 
		immediately frisbees it into the clean rack. It is not added to the stack.

Your Objective:
Given an array representing the stream of incoming plates, determine the state of the stack at the end of the shift.
Input:
plates: An array of integers
Output:
An array representing the final stack from bottom to top.

Input: [6, 4, 8]
Incoming 6: Stack is empty. Push 6.
Stack: [6]
Incoming 4: 4 <= 6. Safe to stack. Push 4.
Stack: [6, 4]
Incoming 8:
8 > 4 (Top of stack). SMASH! Plate 4 pops. Incoming 8 becomes 7.
7 > 6 (New top of stack). SMASH! Plate 6 pops. Incoming 7 becomes 6.
Stack is empty. Push 6.
Stack: [6]
Result: [6]
*/

#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main() {
	vector<int> input = {10, 2, 2, 4};
	deque<int> result;
	
	stack<int> s;
	
	for (int i = 0; i < input.size(); i++) {
	    int x = input[i];
	    
	    while (!s.empty() && x > s.top()) {
	        if (x == 0) break;
	        x--;
	        s.pop();
	    }
	    
	    if (x != 0) s.push(x);
	}
	
	while (!s.empty()) {
	    result.push_front(s.top());
	    s.pop();
	}
	
	return 0;
}
