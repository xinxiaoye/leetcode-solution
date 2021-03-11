/*实现Logistic Regression算法：
input:
n:sample count
d:feature dim

feature: x[n][d]
label:y[n]

param:
w[d], bias


可以直接完成下面代码中的 "TODO"部分
*/
#include <cmath>
#include <cassert>
#include <iostream>


#define MAX_N 1000
#define MAX_D 100



float sigmoid(float x) {
    return 1 / (1 + std::exp(-x));
}


int train(float x[][MAX_D], float y[], float w[], float* b, int n, int d, float lambda) {

    /* TODO: Write your SGD training code here. */

    double h = 0.0;
    double error = 0.0;         
    for(int i = 0; i < n; ++i){
        h = 0.0;  //
        for(int j = 0; j< d; ++j){
            h += w[j] * x[i][d];
        }
        h += b
        h = sigmoid(h)

        error = y[i] - h;                   //

        for(int j = 0; j < n; ++j){
            w[j] += error * lambda * x[j]   //权重更新
        }
        *b = error * lambda * 1;
    }
    return 0;

}



int main() {

    int n = 100;  // Number of training samples.

    int d = 10;  // Number of features.

    float x[MAX_N][MAX_D];  // Sample features: x[n][0,...,d-1] is the feature vector of sample n.

    float y[MAX_D];  // Labels: y[n] is 0 or 1.

    float w[MAX_D];  // Weight parameter.

    float b;  // Bias parameter.

    assert(n <= MAX_N && d <= MAX_D);

    /* Get train data x, y. Initialize w, b. Omit here. */


    /* Train. */

    float lambda = 0.001;  // Step length of SGD.

    train(x, y, w, &b, n, d, lambda);



    return 0;

}