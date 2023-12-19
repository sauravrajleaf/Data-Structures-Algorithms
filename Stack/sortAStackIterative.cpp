// Time Complexity: O(n²), where n is the number of elements in the stack.
// Space Complexity: O(n), where n is the number of elements in the stack.


#include <iostream>
#include <stack>

using namespace std;

void sortStack(stack<int>& inputStack) {
    stack<int> auxStack;

    while (!inputStack.empty()) {
        int temp = inputStack.top();
        inputStack.pop();

        while (!auxStack.empty() && auxStack.top() > temp) {
            inputStack.push(auxStack.top());
            auxStack.pop();
        }

        auxStack.push(temp);
    }

    while (!auxStack.empty()) {
        inputStack.push(auxStack.top());
        auxStack.pop();
    }
}

int main() {
    stack<int> inputStack;

    inputStack.push(34);
    inputStack.push(3);
    inputStack.push(31);
    inputStack.push(98);
    inputStack.push(92);
    inputStack.push(23);

    cout << "Original Stack: ";
    stack<int> originalStack = inputStack;
    while (!originalStack.empty()) {
        cout << originalStack.top() << " ";
        originalStack.pop();
    }
    cout << endl;

    sortStack(inputStack);

    cout << "Sorted Stack: ";
    while (!inputStack.empty()) {
        cout << inputStack.top() << " ";
        inputStack.pop();
    }
    cout << endl;

    return 0;
}
