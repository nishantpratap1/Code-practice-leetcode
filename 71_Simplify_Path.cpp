#include <bits/stdc++.h>
using namespace std;

string simplifyPath(string path) {
    stack<string> st;
    string res;
    int i = 0;
    while (i < path.size()) {
        // Skip consecutive slashes
        while (i < path.size() && path[i] == '/') {
            i++;
        }
        string temp;
        // Extract the directory name
        while (i < path.size() && path[i] != '/') {
            temp += path[i];
            i++;
        }
        if (temp == "..") {
            if (!st.empty()) {
                st.pop();
            }
        } else if (temp != "." && !temp.empty()) {
            st.push(temp);
        }
    }

    while (!st.empty()) {
        res = "/" + st.top() + res;
        st.pop();
    }

    if (res.empty()) {
        return "/";
    }

    return res;
}

int main() {
    string path = "/home/";
    string simplifiedPath = simplifyPath(path);

    cout << "Simplified Path: " << simplifiedPath << endl;

    return 0;
}
