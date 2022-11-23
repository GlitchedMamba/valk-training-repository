class BrowserHistory {
public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        curr = 0;
        //cout << curr << ", " << history.size() << ", " << history[curr] << std::endl;
    }
    
    void visit(string url) {
        curr++;
        history.insert(history.begin() + curr, url);
        //cout << "V: " << curr << ", " << history.size() << ", " << history[curr] << std::endl;
        history.erase(history.begin() + curr + 1, history.end());
        //cout << "V: " << curr << ", " << history.size() << ", " << history[curr] << std::endl;
    }
    
    string back(int steps) {
        if (curr - steps < 0) {
            curr = 0;
        } else {
            curr -= steps;
        }
        //cout << curr << ", " << history.size() << ", " << history[curr] << std::endl;
        return history[curr];
    }
    
    string forward(int steps) {
        if (curr + steps > history.size() - 1) {
            curr = history.size() - 1;
        } else {
            curr += steps;
        }
        //cout << curr << ", " << history.size() << ", " << history[curr] << std::endl;
        return history[curr];
    }
    
private:
    vector<string> history;
    int curr;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
