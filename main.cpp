#include <iostream>
#include <vector>

using namespace std;

int or_tron(vector<vector<int>> inputs) {
    //Target array for Binary Input
    vector<int> t = {0, 1, 1, 1};

    // Considering learning rate=1
    int alp = 1;

    // yi = input
    // yo = output
    int w1 = 0, w2 = 0, b = 0, count = 0, i, yi, yo;
    int dw1, dw2, db;

    while(true) {
        vector<int> ans;
        for (int j = 0; j < inputs.size(); j++) {
            // Calculating Input
            yi = inputs[j][0] * w1 + inputs[j][1] * w2 + b;
            if(yi >= 0) {
                yo = 1;
            }
            else {
                yo = 0;
            }
            if(t[j] == yo) {
                count++;
                dw1 = 0;
                dw2 = 0;
                db = 0;
                ans.push_back(yo);
            }
                // Calculating Change in Weight
            else {
                dw1 = alp * (t[j] - yo) * inputs[j][0];
                dw2 = alp * (t[j] - yo) * inputs[j][1];
                db = alp*(t[j] - yo);
            }
            w1 = w1 + dw1;
            w2 = w2 + dw2;
            b = b + db;
        }
        if (count == arr.size()) {
            for (auto &&an : ans) {
                cout << an << endl;
            }
            return 0;
        }
        else {
            count = 0;
            ans.clear();
        }
    }
}

int and_tron(vector<vector<int>> arr) {
    //Target array for Binary Input
    vector<int> t = {0,0,0,1};

    // Considering learning rate=1
    int alp = 1;

    // yi = input
    // yo = output
    int w1 = 0, w2 = 0, b = 0, count = 0, i, yi, yo;
    int dw1, dw2, db;

    while(true) {
        vector<int> ans;
        for(i = 0; i < arr.size(); i++) {
            // Calculating Input
            yi = arr[i][0] * w1 + arr[i][1] * w2 + b;
            if (yi >= 0) {
                yo = 1;
            }
            else {
                yo = 0;
            }
            if(t[i] == yo) {
                ans.push_back(yo);
                count++;
                dw1 = 0;
                dw2 = 0;
                db = 0;
            }
                // Calculating Change in Weight
            else {
                dw1 = alp*(t[i] - yo) * arr[i][0];
                dw2 = alp*(t[i] - yo) * arr[i][1];
                db = alp*(t[i] - yo);
            }
            w1 = w1 + dw1;
            w2 = w2 + dw2;
            b = b + db;
        }

        if (count == arr.size()) {
            for (auto &&an : ans) {
                cout << an << endl;
            }
            return 0;
        }
        else {
            ans.clear();
            count = 0;
        }
    }
}

int nand_tron(vector<vector<int>> arr) {
    //Target array for Binary Input
    vector<int> t = {1,1,1,0};

    // Considering learning rate=1
    int alp = 1;

    // yi = input
    // yo = output
    int w1 = 0, w2 = 0, b = 0, count = 0, i, yi, yo;
    int dw1,dw2,db;

    while(true) {
        vector<int> ans;
        for(i = 0; i < arr.size(); i++) {
            // Calculating Input
            yi = arr[i][0] * w1 + arr[i][1] * w2 + b;
            if(yi >= 0) {
                yo = 1;
            }
            else {
                yo = 0;
            }
            if(t[i] == yo) {
                ans.push_back(yo);
                count++;
                dw1 = 0;
                dw2 = 0;
                db = 0;
            }
                // Calculating Change in Weight
            else {
                dw1 = alp*(t[i] - yo) * arr[i][0];
                dw2 = alp*(t[i] - yo) * arr[i][1];
                db = alp*(t[i] - yo);
            }
            w1 = w1 + dw1;
            w2 = w2 + dw2;
            b = b + db;
        }

        if (count == arr.size()) {
            for (auto &&an : ans) {
                cout << an << endl;
            }
            return 0;
        }
        else {
            ans.clear();
            count = 0;
        }
    }
}

int main() {
    vector<vector<int>> inputs = {{0, 0},
                                  {0, 1},
                                  {1, 0},
                                  {1, 1}
    };
    // AND OR NAND

    // OR PERCEPTRON
    cout << "OR" << endl;
    or_tron(inputs);

    // AND PERCEPTRON
    cout << "AND" << endl;
    and_tron(inputs);

    // NAND PERCEPTRON
    cout << "NAND" << endl;
    nand_tron(inputs);

    return 0;
}
