#include <stdio.h>
#define SIZE 255

void addPadding(double inputArr[], int inputArraySize, double outputArr[], int
*outputArraySize, int paddingWidth, void paddingMethod(double[], int, int));
void zeroPadding(double outputArr[], int outputArraySize, int paddingWidth);
void samePadding(double outputArr[], int outputArraySize, int paddingWidth);
void halfPadding(double outputArr[], int outputArraySize, int paddingWidth);

int main()
{
	int i;
	double inputArr[] = {2, 6, 7, 9};
	double outputArr[SIZE];
	int outputArrSize = 0;

	addPadding(inputArr, 4 , outputArr, &outputArrSize, 4, halfPadding);
	for(i=0; i<outputArrSize; i++)
	{
		printf("%.1f ", outputArr[i]);
	}
	printf("\n");
	return 0;
}

void addPadding(double inputArr[], int inputArraySize, double outputArr[], int
*outputArraySize, int paddingWidth, void paddingMethod(double[], int, int))
{

	int i,k; /*i for output array size counter k for input arrray size counter*/
	*outputArraySize = inputArraySize+(paddingWidth*2); /*initialize output array size*/

	/*from index 0 to index (padding width) doesn't bother me FOR NOW*/
	/*and from index(input array size+padding width) to last index doesn't bother me FOR NOW*/
	/*this line just copies input array to output array considering left and right sides of padding*/
	for(i=paddingWidth,k=0; i<*outputArraySize; i++, k++)
	{
		outputArr[i] = inputArr[k];
	}
	paddingMethod(outputArr, *outputArraySize, paddingWidth);

}

void zeroPadding(double outputArr[], int outputArraySize, int paddingWidth)
{
	int i;
	/*to do the padding on the left side*/
	for(i=0; i<paddingWidth; ++i)
	{
		outputArr[i]=0.0;
	}
	/*to do the padding on the right side*/
	for(i=outputArraySize-paddingWidth; i<outputArraySize; i++)
	{
		outputArr[i] = 0.0;
	}
}

void samePadding(double outputArr[], int outputArraySize, int paddingWidth)
{
	double first, last; /*first and last variables of the INPUT array*/
	int i;

	first = outputArr[paddingWidth];
	last = outputArr[outputArraySize-paddingWidth-1];

	for(i=0; i<paddingWidth; i++)
	{
		outputArr[i] = first;
	}

	for(i=outputArraySize-paddingWidth; i<outputArraySize; i++)
	{
		outputArr[i] = last;
	}

}

void halfPadding(double outputArr[], int outputArraySize, int paddingWidth)
{
	double first, last;
	int i;

	first = outputArr[paddingWidth]/2.0;
	last = outputArr[outputArraySize-paddingWidth-1]/2.0;
	printf("%.2f\n", last);

	for(i=0; i<paddingWidth; i++)
	{
		outputArr[i] = first;
	}

	for(i=outputArraySize-paddingWidth; i<outputArraySize; i++)
	{
		outputArr[i] = last;
	}
}
