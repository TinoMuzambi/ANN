#include <iostream>
#include <vector>

using namespace std;

//double weights[2] = {0.0, 0.0};
//
//double classify(double input) {
//    double products[2];
//    double curr_sum;
//    double threshold;
//    products[0] = input * weights[0];
//    products[1] = 1.0 * weights[1];
//    curr_sum = products[0] + products[1];
//    if (curr_sum >= 0) {
//        threshold = 1.0;
//    }
//    else {
//        threshold = -1.0;
//    }
//    return threshold;
//}

int or_tron() {
    //Array for Binary Input
    vector<vector<int>> arr = { {0,0},
                                 {0,1},
                                 {1,0},
                                 {1,1}
    };

    //Target array for Binary Input
    vector<int> t = {0,1,1,1};

    // Considering learning rate=1
    int alp = 1;

    // yi = input
    // yo = output
    int w1 = 0, w2 = 0, b = 0, count = 0, i, yi, yo;
    int dw1,dw2,db;

    while(1)
    {
//        cout<<"x1"<<" "<<"x2"<<" "<<"b"<<" "<<"yi"<<" "<<
//            "yo"<<" "<<"t"<<" "<<"dw1"<<" "<<"dw2"<<" "<<"db"<<
//            " "<<"w1"<<" "<<"w2"<<" "<<"b"<<endl;

        vector<int> ans;
        for(i = 0; i < arr.size(); i++)
        {
            // Calculating Input
            yi = arr[i][0] * w1 + arr[i][1] * w2 + b;
            if(yi >= 0)
            {
                yo = 1;
            }
            else
            {
                yo = 0;
            }
            if(t[i] == yo)
            {
                count++;
                dw1 = 0;
                dw2 = 0;
                db = 0;
                ans.push_back(yo);
            }
                // Calculating Change in Weight
            else
            {
                dw1 = alp*(t[i] - yo) * arr[i][0];
                dw2 = alp*(t[i] - yo) * arr[i][1];
                db = alp*(t[i] - yo);
            }
            w1 = w1 + dw1;
            w2 = w2 + dw2;
            b = b + db;
//            cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<1<<" "<<yi<<" "<<yo
//                <<"     "<<t[i]<<" "<<dw1<<" "<<dw2<<" "<<db<<" "<<w1<<" "<<w2
//                <<" "<<b<<endl;
        }
        if(count == 4)
        {
            for (auto &&an : ans) {
                cout << an << endl;
            }
            return 0;
        }
        else
        {
            count = 0;
            ans.clear();
        }
    }
}

int and_tron() {
    //Array for Binary Input
    int arr[4][2] = { {0,0},
                      {0,1},
                      {1,0},
                      {1,1}
    };

    //Target array for Binary Input
    vector<int> t = {0,0,0,1};

    // Considering learning rate=1
    int alp = 1;

    // yi = input
    // yo = output
    int w1 = 0, w2 = 0, b = 0, count = 0, i, yi, yo;
    int dw1,dw2,db;

    while(1)
    {
//        cout<<"x1"<<" "<<"x2"<<" "<<"b"<<" "<<"yi"<<" "<<
//            "yo"<<" "<<"t"<<" "<<"dw1"<<" "<<"dw2"<<" "<<"db"<<
//            " "<<"w1"<<" "<<"w2"<<" "<<"b"<<endl;

        vector<int> ans;
        for(i = 0; i < 4; i++)
        {
            // Calculating Input
            yi = arr[i][0] * w1 + arr[i][1] * w2 + b;
            if(yi >= 0)
            {
                yo = 1;
            }
            else
            {
                yo = 0;
            }
            if(t[i] == yo)
            {
                ans.push_back(yo);
                count++;
                dw1 = 0;
                dw2 = 0;
                db = 0;
            }
                // Calculating Change in Weight
            else
            {
                dw1 = alp*(t[i] - yo) * arr[i][0];
                dw2 = alp*(t[i] - yo) * arr[i][1];
                db = alp*(t[i] - yo);
            }
            w1 = w1 + dw1;
            w2 = w2 + dw2;
            b = b + db;
//            cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<1<<" "<<yi<<" "<<yo
//                <<"     "<<t[i]<<" "<<dw1<<" "<<dw2<<" "<<db<<" "<<w1<<" "<<w2
//                <<" "<<b<<endl;
        }
//        cout<<endl;
        if(count == 4)
        {
            for (auto &&an : ans) {
                cout << an << endl;
            }
            return 0;
        }
        else
        {
            ans.clear();
            count = 0;
        }
    }
}

int nand_tron() {
    //Array for Binary Input
    int arr[4][2] = { {0,0},
                      {0,1},
                      {1,0},
                      {1,1}
    };

    //Target array for Binary Input
    vector<int> t = {1,1,1,0};

    // Considering learning rate=1
    int alp = 1;

    // yi = input
    // yo = output
    int w1 = 0, w2 = 0, b = 0, count = 0, i, yi, yo;
    int dw1,dw2,db;

    while(1)
    {
//        cout<<"x1"<<" "<<"x2"<<" "<<"b"<<" "<<"yi"<<" "<<
//            "yo"<<" "<<"t"<<" "<<"dw1"<<" "<<"dw2"<<" "<<"db"<<
//            " "<<"w1"<<" "<<"w2"<<" "<<"b"<<endl;

        vector<int> ans;
        for(i = 0; i < 4; i++)
        {
            // Calculating Input
            yi = arr[i][0] * w1 + arr[i][1] * w2 + b;
            if(yi >= 0)
            {
                yo = 1;
            }
            else
            {
                yo = 0;
            }
            if(t[i] == yo)
            {
                ans.push_back(yo);
                count++;
                dw1 = 0;
                dw2 = 0;
                db = 0;
            }
                // Calculating Change in Weight
            else
            {
                dw1 = alp*(t[i] - yo) * arr[i][0];
                dw2 = alp*(t[i] - yo) * arr[i][1];
                db = alp*(t[i] - yo);
            }
            w1 = w1 + dw1;
            w2 = w2 + dw2;
            b = b + db;
//            cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<1<<" "<<yi<<" "<<yo
//                <<"     "<<t[i]<<" "<<dw1<<" "<<dw2<<" "<<db<<" "<<w1<<" "<<w2
//                <<" "<<b<<endl;
        }
//        cout<<endl;
        if(count == 4)
        {
            for (auto &&an : ans) {
                cout << an << endl;
            }
            return 0;
        }
        else
        {
            ans.clear();
            count = 0;
        }
    }
}

int main() {
    // AND OR NAND

    // OR PERCEPTRON
    cout << "OR" << endl;
    or_tron();

    // AND PERCEPTRON
    cout << "AND" << endl;
    and_tron();

    // NAND PERCEPTRON
    cout << "NAND" << endl;
    nand_tron();

//    double inputs[2] = {1.0, 2.0};
//    double outputs[2] = {1.0, -1.0};
//
//    bool trained = false;
//    while (!trained) {
//        trained = true;
//        // Output the current training state.
//        cout << inputs[0] << " , " << outputs[0] << " Eval = " << classify(inputs[0]) << endl;
//        cout << inputs[1] << " , " << outputs[1] << " Eval = " << classify(inputs[1]) << endl;
//        cout << "Weights = " << weights[0] << " , " << weights[1] << endl << endl;
//        int index = 0;
//        // Run through the data and update for misclassifications
//        while (index < 2) {
//            double input = inputs[index];
//            double output = outputs[index];
//            double curr_class = classify(input);
//            if (curr_class != output) {
//                weights[0] = weights[0] + output * input;
//                weights[1] = weights[1] + output * 1.0;
//                trained = false;
//            }
//            ++index;
//        }
//    }
    return 0;
}
