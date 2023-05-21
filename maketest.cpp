#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    const int MAX = 1000000;
    random_device rd;  
    mt19937 gen(rd()); 
    uniform_int_distribution<> dis(1, MAX);
    srand(time(NULL));
    string inputs[10] = {"input1.txt", "input2.txt", "input3.txt", "input4.txt", "input5.txt", "input6.txt", "input7.txt", "input8.txt", "input9.txt", "input10.txt"};
    for (int i = 0; i < 10; i++) {
        ofstream fout(inputs[i]);
        int *num = new int[MAX];
        for (int i = 0; i < MAX; i++) num[i] = dis(gen);
        if (i == 0) sort(num, num + MAX);
        if (i == 1) sort(num, num + MAX, cmp);
        for (int i = 0; i < MAX; i++) fout << num[i] << " ";
        fout.close();
        delete []num;
    }
    return 0;
}