#include "lodepng.h"
#include <stdio.h>
#include <stdlib.h>
void decodeOneStep(const char* filename){

unsigned error;
unsigned char* image;
unsigned width, height;
error = lodepng_decode32_file(&image, &width, &height, filename);
	if(error){
		printf("error %u: %s\n", error, 
		lodepng_error_text(error));
	}
	free(image);
}
void encodeOneStep(const char* filename, const unsigned char* image, unsigned width, unsigned height){

unsigned error = lodepng_encode32_file(filename, image, width, height);
	if(error){
		printf("error %u: %s\n", error, 
		lodepng_error_text(error));
	}
}
int main(int argc, char **argv){

unsigned int totalValues;
unsigned int error;
unsigned int encError;
unsigned char* image;
unsigned char* newImage;
unsigned int width;
unsigned int height;
char* filename;
const char* newFileName = "negative.png";
image = (char*) malloc(1000000);
printf("Enter a filename to scan:");
    scanf("%[^\n]%*c", filename);

error = lodepng_decode32_file(&image, &width, &height, filename);
	if(error){
		printf("error %u: %s\n", error, 
		lodepng_error_text(error));
	}

	totalValues = width * height * 4;
	
	//image = (char *) malloc (sizeof(int)*totalValues); 
	printf("width = %d height = %d\n", width, height);
	for(int i = 0; i<totalValues; i=i+4){
		image[0+i]=255-image[0+i];
		image[1+i]=255-image[1+i];
		image[2+i]=255-image[2+i];
		printf("%d %d %d %d\n", image[0+i], image[1+i], 
		image[2+i], image[3+i]);
		

	}
	encError = lodepng_encode32_file(newFileName, image, width, height);
	if(encError){
		printf("error %u: %s\n", error, 
		lodepng_error_text(encError));
	}
free(image);
return 0;
}
