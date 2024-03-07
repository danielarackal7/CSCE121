#include <iostream>
#include <iomanip>
#include <cstring>
#include "parallel_tracks.h"

using std::cin, std::cout, std::endl;

//
//
//
//
//
//

/* bad_numbers05 didn't work. Could be the reason why code is incorrect*/

//
//
//
//
//
//

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
	unsigned int i = 0;
    while (i < SIZE) {
        ary[i] = 0.0;
        i++;
    }
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
    unsigned int count = 0;
    while (count < SIZE) {
        ary[count] = 0;
        count++;
	}
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(char ary[][STRING_SIZE])
// making sure all values within the array are set to "N/A";
{
    for (unsigned int i = 0; i < SIZE; ++i) {
        strcpy(ary[i], "N/A");
	}
}

//-------------------------------------------------------
// Name: trim
// PreCondition:  the cstring
// PostCondition: whitespace has been removed from beginning and end of string
//---------------------------------------------------------
void trim(char str[STRING_SIZE]) {
    char temp[STRING_SIZE];
    int length = strlen(str);
    int start = 0, end = length - 1;

    while (start < length && isspace((unsigned char)str[start])) {
        start++;
    }

    while (end > start && isspace((unsigned char)str[end])) {
        end--;
    }

    int tempIndex = 0;
    for (int i = start; i <= end; ++i) {
        temp[tempIndex++] = str[i];
    }
    temp[tempIndex] = '\0';

    strcpy(str, temp);
}



//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data(double timeArray[], char countryArray[][STRING_SIZE], unsigned int numberArray[], char lastnameArray[][STRING_SIZE]) {
    for (unsigned int i = 0; i < SIZE; ++i) {
        std::cout << "Enter time, country, number, and lastname for runner " << (i+1) << ": ";
        if (!(std::cin >> timeArray[i])) return false; 
        
        std::cin >> countryArray[i];
        if (strlen(countryArray[i]) != 3 || !isupper(countryArray[i][0]) || !isupper(countryArray[i][1]) || !isupper(countryArray[i][2])) {
            return false; 
        }
        
        if (!(std::cin >> numberArray[i]) || numberArray[i] <= 0) {
            return false;
        }
        
        std::cin.ignore();
        std::cin.getline(lastnameArray[i], STRING_SIZE);
        if (strlen(lastnameArray[i]) == 0) {
            return false;
        }
    }
    return true;
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[]) {
    unsigned int counter = 0;
    while (counter < SIZE) {
        unsigned int rank = 1;
        unsigned int innerCounter = 0;
        while (innerCounter < SIZE) {
            if (timeArray[innerCounter] < timeArray[counter]) {
                rank++;
            }
            innerCounter++;
        }
        rankArray[counter] = rank;
        counter++;
    }
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const char countryArray[][STRING_SIZE],
		const char lastnameArray[][STRING_SIZE], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}