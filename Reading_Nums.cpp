//
// Created by kimem on 2019-09-19.
//
#include "Reading_Nums.hpp"

void Num_Reading(int int_limit){
    // file called Reading.txt
    fstream file{"Reading.txt"};

    // Total sum of all the doubles
    double sum = 0.0;
    // Number of doubles generated
    int total_Reading_num = 0;
    // Average reading
    double average_Reading = 0;
    // Highest reading set to lowest possible value
    double highest_Reading = 50.000;
    // lowest reading set to highest possible value
    double lowest_Reading = 90.000;
    // Median reading
    double median_Reading;
    // index, int part of the pair
    int i;
    // generated double, double part of the pair
    double d;

    string line;
    double * pArray;
    pArray = new (nothrow)double[int_limit];

    cout << "int_limit: " << int_limit << endl;

    while (getline(file, line)){
        // when reading each line, sum up the double,
        // Increase the number of the double
        total_Reading_num ++;
        istringstream stream(line);
        // Index goes to i, Double goes to d
        stream >> i >> d;
        sum += d;

        cout << "i: " << i << endl;
       // store double in the pArray
        pArray[i] = d;
        cout << "i set OK!: " << i << endl;

       // Update highest value
        if (d > highest_Reading){
            highest_Reading = d;
        }
        // Update lowest value
        if (d< lowest_Reading){
            lowest_Reading = d;
        }


    }
    // Sort the array
    sort(pArray, pArray + total_Reading_num);

    // median for even index
    if (total_Reading_num % 2 == 0){
        int left = total_Reading_num /2 -1;
        int right = total_Reading_num/2;
        median_Reading = ((pArray[left] + pArray [right])/2);

    }else{
        // median for odd index
        int middle = total_Reading_num/2;
        median_Reading =  pArray[middle];

    }
    average_Reading = sum/total_Reading_num;

    cout << "There are " << total_Reading_num << " readings in the file." <<endl;
    cout << fixed<< setprecision(3)<<"The average reading is " << average_Reading << "." <<endl;
    cout << "The highest reading is " << highest_Reading << "."<< endl;
    cout << "The lowest reading is " << lowest_Reading << "."<< endl;
    cout << "The median reading is " << median_Reading << "."<< endl;

}

