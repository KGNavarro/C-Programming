#include <stdio.h>

int main() {

	int numOfProducts;
	printf("How many unique products are there?\n");
	scanf("%d", &numOfProducts);
	//I made an array table to get the average rating of each product and one to get the total ratings each product got
	int countTable[numOfProducts + 1][11];

	//prductRow and ratingColumn will serve as the loop indicators to access each array location in both tables

	int productRow, ratingColumn;
	int i, j;

	for (i = 0; i < numOfProducts + 1; i++){
		for (j = 0; j < 11; j++)
			countTable[i][j] = 0;
	}

	//As long as it reads in 2 variables to fill both tables

	printf("Enter product number and rating (1-10), separated by a space, one pair at a time. Enter "end" to finish.\n");

	while (scanf("%d %d", &productRow, &ratingColumn) == 2) {
		countTable[productRow][ratingColumn]++;//counts how many times each rating got an entry
	}
	int overallProductsReviewed = 0;
	for (i = 1; i <= numOfProducts; i++) {//iterate through the rows
		float avg = 0.0;
		int totalRatingsPerProduct = 0;
		int count = 0;
		for (j = 1; j < 11; j++) {
			totalRatingsPerProduct += countTable[i][j];//sum up the amount of times that row/product got a rating
		}
		for (j = 1; j < 11; j++) {
			count += countTable[i][j] * j; //get total by summing the amount of stars it got
		}
		if(totalRatingsPerProduct !=0)
			avg = (float)count / (float)totalRatingsPerProduct; // get average with the values just calculated
		overallProductsReviewed += totalRatingsPerProduct;
		if (totalRatingsPerProduct != 0) {
			printf("Product %d information.\n", i);
			printf("1 star: %d \n", countTable[i][1]);
			printf("2 star: %d \n", countTable[i][2]);
			printf("3 star: %d \n", countTable[i][3]);
			printf("4 star: %d \n", countTable[i][4]);
			printf("5 star: %d \n", countTable[i][5]);
			printf("6 star: %d \n", countTable[i][6]);
			printf("7 star: %d \n", countTable[i][7]);
			printf("8 star: %d \n", countTable[i][8]);
			printf("9 star: %d \n", countTable[i][9]);
			printf("10 star: %d \n", countTable[i][10]);
			printf("Average rating: %f out of 10 (%d ratings total)\n\n", avg, totalRatingsPerProduct);
		}
	}
	printf("%d product ratings evaluated in all\n\n", overallProductsReviewed);
}