/* Function to reverse a string using recursion */

#include <bits/stdc++.h>
#include <string>
using namespace std;

void stringReverse(string &line, int i = 0) {
    int n = line.length();
    if(i == n/2) {  // if i reaches half of string length stop the process because once we reached half we know that
                    // string has been reversed(swapped).
        return;
    }
    else {
        swap(line[i], line[n - 1 - i]); // swap built-in function in bits/stdc++.h
        stringReverse(line, i + 1);
    }

}

//My version (GVG)
void stringReverse2(string& line, std::stack<char>& myStack){
    if(line.empty()){
        while(!myStack.empty()){
            line.push_back(myStack.top());
            myStack.pop();
        }
        return;
    }
    myStack.push(line.front());
    line.erase(line.begin());
    stringReverse2(line, myStack);
}

int main()
{
    string line;
    cout<<"Enter string"<<endl;
    getline(cin, line);   // function to use when accepting a sentence as a input.

    stringReverse(line);
    cout<<line<<endl;

    //This is my version (GVG)
    string line2;
    cout<<"Enter string2"<<endl;
    getline(cin, line2);   // function to use when accepting a sentence as a input.

    std::stack<char> myStack;
    stringReverse2(line2, myStack);
    cout<<line2<<endl;
    return 0;
}
