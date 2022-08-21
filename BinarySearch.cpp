#include <iostream>
#include <vector>
#include <algorithm>

// template<typename anyType>
void binarySearch(std::vector<uint64_t>& vec /*std::vector<int> vec*/, uint64_t val/*anyType val*/){
    // anyType min = 0;
    // anyType max = vec.size();
    uint64_t min = 0, max = vec.size();
    
    while (1)
    {
        // anyType middle = (min + max)/2;
        // uint64_t middle = (min + max)/2;
        uint64_t middle = min + (max - min)/2; //to avoid integer overflow

        //std::cout << min << " " << max << std::endl;
        if (vec[middle] == val){
            std::cout << "Data found on position: " << middle + 1;
            break;
        }
        else if(vec[middle] > val ){
            max = middle;
        }
        else if(vec[middle] < val ) {
            min = middle;
        }

        if(min == (max - 1)){
            std::cout << "Data not found";
            break;
        }
    }    
}

int main(){

    uint64_t n; 
    uint64_t x;

    std::cout << "Insert the size of the array here: ";
    std::cin >> n;

    std::vector<uint64_t> array(n);
    std::cout << "Insert the array here (it will be sorted): ";

    for (uint64_t i = 0; i < n; i++)
    {
        std::cin >> array[i];
    }

    std::sort(array.begin(), array.end());

    std::cout << "The sorted array is: " << std::endl;

    for (uint64_t i = 0; i < n; i++)
    {
        std::cout << array[i] << std::endl;
    }

    std::cout << "which data are you looking for?: ";
    std::cin >> x;
    
    binarySearch(array, x);
}