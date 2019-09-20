//
// Created by kimem on 2019-09-19.
//

#include "Generate_Nums.hpp"

int Num_Generation(){
        ofstream ReadingFile{"Reading.txt"};
    // when the file cannot be opened
    if(!ReadingFile.is_open()){
        cerr << "Unable to open file" << endl;
        exit(1);
    }

    // Upper and Lower value for index
    int int_lower = 512;
    int int_upper = 1024;

    // get a random int between 512 and 1024
    random_device rd;
    mt19937 int_generator(time(NULL));
    uniform_int_distribution<> int_distribution (int_lower,int_upper);

    // Upper and lower value for the doubles
    double double_lower = 50.000;
    double double_upper = 90.000;
    default_random_engine double_generator(time(0));
    uniform_real_distribution<double> double_distribution(double_lower, double_upper);

    // Total number of doubles
    int int_limit = int_distribution(int_generator);

    // Writing to the file
    for (int i = 0; i <= int_limit; i++){
     double random_double = double_distribution(double_generator);
        ReadingFile<< i << " "
        << fixed<<setprecision(3)<< random_double << endl;
    }
    // return the total number of doubles
    return int_limit;
}
