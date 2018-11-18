
#include <iostream>
#include <vector>

int main() {

	std::vector<unsigned int> swiftScore;
	std::vector<unsigned int> semScore;

	unsigned int daysPlayed;

	std::cout << "How many days were played?: ";
	std::cin >> daysPlayed;
	std::cout << std::endl;

	// Get Swift's scores
	
	unsigned int score;
	for(int i = 0; i < daysPlayed; i++) {
		
	std::cout << "Swift Day " << i+1 << ": ";
	std::cin >> score;

	swiftScore.push_back(score);

	}	

	// Get Semaphore Score
	for(int i =0; i < daysPlayed; i++) {

	std::cout << "Semaphores Day " << i+1 << ": ";
	std::cin >> score;

	semScore.push_back(score);

	}
 	
	// our k value
	unsigned int k = 0;
	unsigned int swiftSum  = 0;
	unsigned int semSum = 0;
	
	for(int i = 0; i < daysPlayed; i++) {
		swiftSum += swiftScore[i];
		semSum += semScore[i];

  	if(swiftSum == semSum) k = i+1;		

 	}

	std::cout << "K value is " << k << std::endl;


	return 0;
}
