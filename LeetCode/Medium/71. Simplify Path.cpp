class Solution {
public:
    string simplifyPath(string path) {
        deque<string> items;

        string curr = "";
        for (int i=0; i<path.size(); ++i) {
            if (path[i] == '/' and curr != "") {
                if (curr == ".") {
                    // do nothing
                }
                else if (curr == "..") {
                    if (!items.empty())
                        items.pop_back();
                }
                else {
                    items.push_back(curr);
                }
                curr = "";
            }
            else if (path[i] != '/'){
                curr += path[i];
            }
        }

        if (curr != "") {
            if (curr == ".") {
            }
            else if (curr == "..") {
                if (!items.empty())
                    items.pop_back();
            }
            else {
                items.push_back(curr);
            }
        }

        string ans = "";
        while (!items.empty()) {
            ans += "/" + items.front();
            items.pop_front();
        }

        if (ans == "")
            return "/";

        return ans;
    }
};