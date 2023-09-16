// FCI � Programming 1 � 2022 - Assignment 3
// Program Name: CS112-203-2nd�S12-20210118-20210144-20210149-A3.cpp
// Last Modification Date: 20/4/2022
// Author1 and ID and Group: Hazem Walied Khaled Mohamed / 20210118 / group A
// Author2 and ID and Group: Ziad Ahmed Mahomoud Foad / 20210144 / group A
// Author3 and ID and Group: Ziad Tarek Sayed Ali El-Masry / 20210149 / group A
// Teaching Assistant: Eng. Afaf abdelmonem
// Purpose: processing on RGB images


#include<bits/stdc++.h>
#include "bmplib.cpp"
using namespace std;

unsigned char image[SIZE][SIZE][RGB];
unsigned char image1[SIZE][SIZE][RGB];
unsigned char image2[SIZE][SIZE][RGB];
unsigned char image3[SIZE][SIZE][RGB];
unsigned char part1[SIZE][SIZE][RGB];
unsigned char part2[SIZE][SIZE][RGB];
unsigned char part3[SIZE][SIZE][RGB];
unsigned char part4[SIZE][SIZE][RGB];
char choice;
void display_menu();
void load_image();
void load_image_tomerge();
void save_image();
void save_merged();
void filter_1();
void filter_2();
void filter_3();
void filter_4();
void filter_5();
void filter_6();
void filter_7();
void filter_8();
void filter_9();
void filter_a();
void filter_b();
void filter_c();

int main()
{
    cout<<"!! Welcome to RGBIP !!"<<endl<<endl;
    while(true)
    {
        display_menu();
        if (choice=='1')
        {
            load_image();
            filter_1();
            save_image();
        }
        else if (choice=='2')
        {
            load_image();
            filter_2();
            save_image();
        }
        else if (choice=='3')
        {
            load_image_tomerge();
            filter_3();
            save_merged();
        }
        else if (choice=='4')
        {
            load_image();
            filter_4();
            save_image();
        }
        else if (choice=='5')
        {
            load_image();
            filter_5();
            save_image();
        }
        else if (choice=='6')
        {
            load_image();
            filter_6();
            save_image();
        }
        else if (choice=='7')
        {
            load_image();
            filter_7();
            save_image();
        }
        else if (choice=='8')
        {
            load_image();
            filter_8();
            save_image();
        }
        else if (choice=='9')
        {
            load_image();
            filter_9();
            save_image();
        }
        else if (choice=='a')
        {
            load_image();
            filter_a();
            save_image();
        }
        else if (choice=='b')
        {
            load_image();
            filter_b();
            save_image();
        }
        else if (choice=='c')
        {
            load_image();
            filter_c();
            save_image();
        }
        else if (choice=='0')
        {
            exit(0);
        }
    }
}

void load_image()
{
    char image_name[150];
    cout<<"Please enter the name of the image file: ";
    cin>> image_name;
    strcat(image_name,".bmp");
    readRGBBMP(image_name,image);
}

void save_image()
{
    char newimage_name[150];
    cout<<"Please enter the name of the new image to be saved: ";
    cin>>newimage_name;
    strcat(newimage_name,".bmp");
    writeRGBBMP(newimage_name,image);
}

void load_image_tomerge()
{
   char imageFileName1[100];
   char imageFileName2[100];

   // Get gray scale image file name
  cout << "Enter the source image file 1 name: ";
   cin >> imageFileName1;

   cout << "Enter the source image file 2 name: ";
   cin >> imageFileName2;

   // Add to it .bmp extension and load image
   strcat (imageFileName1, ".bmp");
   readRGBBMP(imageFileName1, image1);
   strcat (imageFileName2, ".bmp");
   readRGBBMP(imageFileName2, image2);
}


void save_merged()
{
   char imageFileName3[100];

   // Get gray scale image target file name
   cout << "Enter the target image file name: ";
   cin >> imageFileName3;

   // Add to it .bmp extension and load image
   strcat (imageFileName3, ".bmp");
   writeRGBBMP(imageFileName3, image3);
}


void display_menu()
{
    cout<<endl<<"1- Black & White Filter."<<endl;
    cout<<"2- Invert Image."<<endl;
    cout<<"3- Merge Images."<<endl;
    cout<<"4- Flip Image."<<endl;
    cout<<"5- Rotate Image."<<endl;
    cout<<"6- Darken and Lighten Image."<<endl;
    cout<<"7- Detect Image Edges."<<endl;
    cout<<"8- Enlarge Image."<<endl;
    cout<<"9- Shrink Image."<<endl;
    cout<<"a- Mirror Image."<<endl;
    cout<<"b- Shuffle Image."<<endl;
    cout<<"c- Blur Image."<<endl;
    cout<<"0- EXIT."<<endl<<endl;
    cout<<"Please enter the filter you want to apply otherwise enter {0} to exit: "<<endl;
    cin>>choice;

}

void filter_1()
{
    for(int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if ((image[i][j][0] + image [i][j][1] + image [i][j][2]) > 384)
            {
                for (int k = 0; k < RGB; k++ )
                {
                    image[i][j][k] = 255;
                }
            }
            else
            {
                for (int k = 0; k < RGB; k++)
                {
                    image [i][j][k] = 0;
                }
            }
        }
    }
}

void filter_2()
{
    for(int i= 0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            for (int k=0; k<RGB; k++)
            {
                image[i][j][RGB-k] = 255 - image[i][j][RGB-k];
            }
        }
    }
}

void filter_3()
{
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
            for(int k=0;k<SIZE;k++){

                image3[i][j][k]=((image1[i][j][k]+image2[i][j][k])/2);

            }

    }
  }
}

void filter_4()
{
    int row1 = 0;
    int row2 = (SIZE - 1);
    unsigned char update [SIZE][RGB];
    bool test = true;
    while (test == true)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int a =0; a < RGB; a++)
            {
                update [i][a] = image [row1][i][a];
            }
        }
        for (int k = 0; k < SIZE; k++)
        {
            for (int a =0; a < RGB; a++)
            {
                image [row1][k][a] = image [row2][k][a];
            }
        }
        for (int j = 0; j < SIZE; j++)
        {
            for (int a =0; a < RGB; a++)
            {
                image [row2][j][a] = update [j][a];
            }
        }
        row1 = row1 + 1;
        row2 = row2 - 1;
        if (row1 == 128)
            test = false;

    }
}

void filter_5()
{
    string degree;
    cout<<"Please enter the degree to rotate with (90,180,270) --> ";
    cin>> degree;
    if(degree == "90")
    {
        for(int i=0; i<SIZE; i++)
        {
            for(int j=i; j<SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {
                    swap(image[i][j][k],image[j][i][k]);
                }
            }
        }
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE/2; j++)
            {
                for (int k=0; k<RGB; k++)
                {
                    swap(image[i][j][k],image[i][255-j][k]);
                }

            }
        }
    }
    else if (degree == "180")
    {
        for(int i=0; i<SIZE/2; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {
                    swap(image[i][j][k],image[255-i][255-j][k]);
                }
            }
        }
    }
    else if (degree == "270")
    {
        for(int i=0; i<SIZE; i++)
        {
            for(int j=i; j<SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {
                    swap(image[i][j][k],image[j][i][k]);
                }
            }
        }
        for(int i=0; i<SIZE/2; i++)
        {
            for(int j=0; j<SIZE; j++)
            {
                for (int k=0; k<RGB; k++)
                {
                    swap(image[i][j][k],image[255-i][255-j][k]);
                }
            }
        }
        for(int i=0; i<SIZE; i++)
        {
            for(int j=0; j<SIZE/2; j++)
            {
                for (int k=0; k<RGB; k++)
                {
                    swap(image[i][j][k],image[i][255-j][k]);
                }

            }
        }
    }
}

void filter_6()
{
   long avg;
int desscion;
cout<<"to darken enter 1 to lighten enter 2 ";
cin>>desscion;

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
            for (int k=0; k<RGB;k++){
                    if(desscion==1){
                           avg=(image[i][j][k]/2);
                         image[i][j][k]-=avg;
                    }
                    else{
                        avg=(255-image[i][j][k])/2;
                        image[i][j][k]+=avg;
                    }



            }
       }
    }
}

void filter_7()
{
    unsigned char photo [SIZE][SIZE][RGB];
    filter_1();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                photo[i][j][k] = (image[i-1][j][k]+image[i+1][j][k]+image[i][j+1][k]+image[i][j-1][k])-(8 * image[i][j][k]);
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                image [i][j][k] = photo [i][j][k];
            }
        }
    }
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < RGB; k++)
            {
                image [i][j][k] = 255 - image [i][j][k];
            }
        }
    }
}

void filter_8()
{
    for (int i=0; i<SIZE/2; i++)
    {
        for (int j=0; j<SIZE/2; j++)
        {
            for(int k=0; k<RGB; k++)
            {
                part1[i][j][k]=image[i][j][k];
            }
        }
    }
    for (int i=0; i<SIZE/2; i++)
    {
        for (int j=SIZE/2; j<SIZE; j++)
        {
            for(int k=0; k<RGB; k++)
            {
                part2[i][j-128][k]=image[i][j][k];
            }
        }
    }
    for (int i=SIZE/2; i<SIZE; i++)
    {
        for (int j=0; j<SIZE/2; j++)
        {
            for(int k=0; k<RGB; k++)
            {
                part3[i-128][j][k]=image[i][j][k];
            }
        }
    }
    for (int i=SIZE/2; i<SIZE; i++)
    {
        for (int j=SIZE/2; j<SIZE; j++)
        {
            for(int k=0; k<RGB; k++)
            {
                part4[i-128][j-128][k]=image[i][j][k];
            }
        }
    }
    int chosen;
    cout<<"Enter the part you want to enlarge (1)(2)(3)(4): ";
    cin>>chosen;
    if (chosen==1)
    {
        for(int i=0,k=0; i<SIZE; i+=2,k++)
        {
            for(int j=0,l=0; j<SIZE; j+=2,l++)
            {
                for(int m=0; m<RGB; m++)
                {
                    image[i][j][m]=part1[k][l][m];
                    image[i+1][j][m]=part1[k][l][m];
                    image[i][j+1][m]=part1[k][l][m];
                    image[i+1][j+1][m]=part1[k][l][m];
                }
            }
        }
    }
    else if (chosen == 2)
    {
        for(int i=0,k=0; i<SIZE; i+=2,k++)
        {
            for(int j=0,l=0; j<SIZE; j+=2,l++)
            {
                for(int m=0; m<RGB; m++)
                {
                    image[i][j][m]=part2[k][l][m];
                    image[i+1][j][m]=part2[k][l][m];
                    image[i][j+1][m]=part2[k][l][m];
                    image[i+1][j+1][m]=part2[k][l][m];
                }
            }
        }
    }
    else if (chosen == 3)
    {
        for(int i=0,k=0; i<SIZE; i+=2,k++)
        {
            for(int j=0,l=0; j<SIZE; j+=2,l++)
            {
                for(int m=0; m<RGB; m++)
                {
                    image[i][j][m]=part3[k][l][m];
                    image[i+1][j][m]=part3[k][l][m];
                    image[i][j+1][m]=part3[k][l][m];
                    image[i+1][j+1][m]=part3[k][l][m];
                }
            }
        }
    }
    else if (chosen == 4)
    {
        for(int i=0,k=0; i<SIZE; i+=2,k++)
        {
            for(int j=0,l=0; j<SIZE; j+=2,l++)
            {
                for(int m=0; m<RGB; m++)
                {
                    image[i][j][m]=part4[k][l][m];
                    image[i+1][j][m]=part4[k][l][m];
                    image[i][j+1][m]=part4[k][l][m];
                    image[i+1][j+1][m]=part4[k][l][m];
                }
            }
        }
    }

}

void filter_9()
{
      int desscion;
    cout<<"1-shrink half 2-shrink third 3-shrink quarter";
    cin>>desscion;
    if (desscion==1){
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
    for (int k = 0; k< RGB; k++){
        image[i/2][j/2][k]=image[i][j][k];
        image[i][j][k]=255;
        }

    }
  }

    }
        else if (desscion==2){
     for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        for (int k= 0; k< RGB; k++){
       image[i/3][j/3][k]=image[i][j][k];
        image[i][j][k]=255;
        }

    }
  }
    }
        if (desscion==3){
    for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j< SIZE; j++) {
        for (int k = 0; k< RGB; k++){
       image[i/4][j/4][k]=image[i][j][k];
        image[i][j][k]=255;
        }

    }
  }
    }

}

void filter_a()
{
    int counter1 = 0;
    int counter2 = (SIZE - 1);
    bool test = true;
    int choice;
    cout << "Please choose the 1/2 which is wanted to be mirrored:" << endl << "1-For the upper half" << endl;
    cout << "2-For the lower half" << endl;
    cout << "3-For the right half" << endl;
    cout << "4-For the left half" << endl;
    cout << "Your choice: ";
    cin >> choice;
    if (choice == 1)
    {
        while (test == true)
        {
            for(int i = 0; i < SIZE; i++)
            {
                for(int j = 0; j < RGB; j++)
                {
                    image [counter2][i][j] = image [counter1][i][j];
                }
            }
            counter1 = counter1 + 1;
            counter2 = counter2 - 1;
            if (counter1 == 128)
                test = false;
        }
    }
    if (choice == 2)
    {
        while (test == true)
        {
            for(int i = 0; i < SIZE; i++)
            {
                for(int j = 0; j < RGB; j++)
                {
                    image [counter1][i][j] = image [counter2][i][j];
                }
            }
            counter1 = counter1 + 1;
            counter2 = counter2 - 1;
            if (counter1 == 128)
                test = false;
        }
    }
    if (choice == 3)
    {
        while (test == true)
        {
            for(int i = 0; i < SIZE; i++)
            {
                for(int j = 0; j < RGB; j++)
                {
                    image [i][counter1][j]= image [i][counter2][j];
                }
            }
            counter1 = counter1 + 1;
            counter2 = counter2 - 1;
            if (counter1 == 128)
                test = false;
        }
    }
    if (choice == 4)
    {
        while (test == true)
        {
            for(int i = 0; i < SIZE; i++)
            {
                for(int j = 0; j < RGB; j++)
                {
                    image [i][counter2][j] = image [i][counter1][j];
                }
            }
            counter1 = counter1 + 1;
            counter2 = counter2 - 1;
            if (counter1 == 128)
                test = false;
        }
    }
}

void filter_b()
{
    unsigned char sorted1[128][128][RGB];
    unsigned char sorted2[128][128][RGB];
    unsigned char sorted3[128][128][RGB];
    unsigned char sorted4[128][128][RGB];
    for(int i=0 ; i<128; i++)
    {
        for(int j =0; j<128; j++)
        {
            for(int k=0; k<RGB; k++)
            {
                part1[i][j][k]=image[i][j][k];
            }
        }
    }
    for(int i=0 ; i<128; i++)
    {
        for(int j =0; j<128; j++)
        {
            for(int k=0; k<RGB; k++)
            {
                part2[i][j][k]=image[i][128+j][k];
            }
        }
    }
    for(int i=0 ; i<128; i++)
    {
        for(int j =0; j<128; j++)
        {
            for(int k=0; k<RGB; k++)
            {
                part3[i][j][k]=image[128+i][j][k];
            }
        }
    }
    for(int i=0 ; i<128; i++)
    {
        for(int j =0; j<128; j++)
        {
            for(int k=0; k<RGB; k++)
            {
                part4[i][j][k]=image[128+i][128+j][k];
            }
        }
    }
    string order;
    cout<<"Enter the order to shuffle WITHOUT SPACES: ";
    cin.ignore();
    getline(cin,order);
    //////////////////////////////////////////////////////////////
    if (order[0]=='1' && order[1]=='2' && order[2]=='3' && order[3]=='4')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part4[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='1' && order[1]=='2' && order[2]=='4' && order[3]=='3')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part3[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='1' && order[1]=='3' && order[2]=='2' && order[3]=='4')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part4[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='1' && order[1]=='3' && order[2]=='4' && order[3]=='2')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part2[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='1' && order[1]=='4' && order[2]=='2' && order[3]=='3')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part3[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='1' && order[1]=='4' && order[2]=='3' && order[3]=='2')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part2[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='2' && order[1]=='1' && order[2]=='3' && order[3]=='4')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part4[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='2' && order[1]=='1' && order[2]=='4' && order[3]=='3')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part3[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='2' && order[1]=='3' && order[2]=='1' && order[3]=='4')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part4[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='2' && order[1]=='3' && order[2]=='4' && order[3]=='1')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part1[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='2' && order[1]=='4' && order[2]=='3' && order[3]=='1')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part1[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='2' && order[1]=='4' && order[2]=='1' && order[3]=='3')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part3[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='3' && order[1]=='1' && order[2]=='2' && order[3]=='4')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part4[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='3' && order[1]=='1' && order[2]=='4' && order[3]=='2')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part2[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='3' && order[1]=='2' && order[2]=='1' && order[3]=='4')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part4[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='3' && order[1]=='2' && order[2]=='4' && order[3]=='1')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part1[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='3' && order[1]=='4' && order[2]=='1' && order[3]=='2')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part2[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='3' && order[1]=='4' && order[2]=='2' && order[3]=='1')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part1[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='4' && order[1]=='1' && order[2]=='3' && order[3]=='2')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part2[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='4' && order[1]=='1' && order[2]=='2' && order[3]=='3')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part3[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='4' && order[1]=='2' && order[2]=='1' && order[3]=='3')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part3[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='4' && order[1]=='2' && order[2]=='3' && order[3]=='1')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part1[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='4' && order[1]=='3' && order[2]=='1' && order[3]=='2')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part1[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part2[i][j][k];
                }
            }
        }
    }
    else if (order[0]=='4' && order[1]=='3' && order[2]=='2' && order[3]=='1')
    {
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted1[i][j][k] = part4[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted2[i][j][k] = part3[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted3[i][j][k] = part2[i][j][k];
                }
            }
        }
        for(int i=0; i<128; i++)
        {
            for(int j=0; j<128; j++)
            {
                for(int k=0; k<RGB; k++)
                {
                    sorted4[i][j][k] = part1[i][j][k];
                }
            }
        }
    }
    else
    {
        cout<<"invalid order"<<endl;
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    for(int i=0; i<SIZE/2; i++)
    {
        for(int j=0; j<SIZE/2; j++)
        {

            for(int k=0; k<RGB; k++)
            {
                image[i][j][k] = sorted1[i][j][k];
            }
        }
    }
    for(int i=0; i<SIZE/2; i++)
    {
        for(int j=SIZE/2; j<SIZE; j++)
        {
            for(int k=0; k<RGB; k++)
            {
                image[i][j][k]= sorted2[i][j-128][k];
            }
        }
    }
    for(int i=SIZE/2; i<SIZE; i++)
    {
        for(int j=0; j<SIZE/2; j++)
        {
            for(int k=0; k<RGB; k++)
            {
                image[i][j][k]= sorted3[i-128][j][k];
            }
        }
    }
    for(int i=SIZE/2; i<SIZE; i++)
    {
        for(int j=SIZE/2; j<SIZE; j++)
        {
            for(int k=0; k<RGB; k++)
            {
                image[i][j][k]= sorted4[i-128][j-128][k];
            }
        }
    }
}

void filter_c()
{
        for(int l = 0; l < 15; l++){
        for(int i = 0; i<SIZE; i++){
            for(int j = 2; j<SIZE; j++){
                    for(int k=0; k<RGB; k++){
                       image2[i][j-1][k] = (image[i][j][k]+image[i][j-2][k])/2;
                    }

            }
            for(int j = 0; j < SIZE; j++){
                if(i == 0){
                    break;
                }
                for(int k=0; k<RGB; k++){

                        image2[i-1][j][k] = (image[i-2][j][k]+image[i][j][k])/2;

                }

            }
        }
        for(int i = 0; i<SIZE; i++){
            for(int j = 0; j<SIZE; j++){
                    for(int k=0; k<RGB; k++){
                        image[i][j][k] = image2[i][j][k];
                    }

            }
        }
    }
}
