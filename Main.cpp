#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <stdbool.h>
#include <ctype.h>
#include <iostream>
#include <vector>
#include <unistd.h>
#include <chrono>
#include <bits/stdc++.h>


using namespace std;
using namespace std::this_thread; 
using namespace std::chrono;


void mathGame();
void delay(int number_of_seconds);
int generateNumber(int MAX, int MIN);
int checkEvenNumber(int number, int MAX, int MIN);
void printResults(vector<int> cor, vector<int> incor);
int checkDivide(int number1, int number2, int MAX, int MIN);
int checkGreaterThan(int number1, int number2, int MAX, int MIN);


vector<int> cor;
vector<int> corNum;
vector<int> inCor;
vector<int> incorNum;


int main(void)
{  
   
    printf("Welcome to a game that will test your integer arithemtic skills. \n");
    sleep(1);
    mathGame();




return 0;
}


int generateNumber(int MAX, int MIN)
{
    //function that generates a random number every time it is called
    int NUM_CHOSEN = (rand() % MAX) + MIN;


    return NUM_CHOSEN;
}


int checkDivide(int number1, int number2, int MAX, int MIN)
{
    //checks whether the number is greater than and can divide.
    while(number1 < number2 && number1 / number2 <= 1 && number1 % 2 != 0)
        {
            number1 = (rand() % MAX) + MIN;
            number1 = checkEvenNumber(number1, MAX, MIN);
        }


    return number1;
}


int checkGreaterThan(int number1, int number2, int MAX, int MIN)
{
     while(number1 < number2)
    {
        number1 = (rand() % MAX) + MIN;
    }
    return number1;
}


int checkEvenNumber(int number, int MAX, int MIN)
{
    while(1)
    {
        if(number % 2 == 0)
        {
            number = (rand() % MAX) + MIN;
            break;
        }
    }
    return number;
}


void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
 
    // Storing start time
    clock_t start_time = clock();
 
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds) ;
}


void mathGame()
{
    int counter = 1;
    int numQuestions = 0;
    int userAnswer = 0;
    int result = 0;
    int correct = 0;
    int incorrect = 0;


   
    int MAX_NUM_ONE;
    int MIN_NUM_ONE;
    char replay;


    printf("\nWhat is the maximum number you want the game to go up to: ");
    scanf("%d",&MAX_NUM_ONE);
    printf("\nWhat is the minimum number you want the game to go down to: ");
    scanf("%d",&MIN_NUM_ONE);


    int MAX_NUM_TWO = MAX_NUM_ONE;
    int MIN_NUM_TWO = MIN_NUM_ONE;


    printf("\nEnter the amount of questions you will want to answer: ");
    scanf("%d",&numQuestions);


    srand(time(0));



    printf("3\n");
    sleep(1);
    printf("2\n");
    sleep(1);
    printf("1\n");
    sleep(1);
    printf("G0!\n");

    clock_t t;
        t = clock();
        auto start = chrono::steady_clock::now();


    do
    {
    int OPERATOR_CHOSEN = (rand() %  4) + 1;


    int NUM_ONE_CHOSEN = generateNumber(MAX_NUM_ONE, MIN_NUM_ONE);
    int NUM_TWO_CHOSEN = generateNumber(MAX_NUM_TWO, MIN_NUM_TWO);


        switch (OPERATOR_CHOSEN)
        {
        case 1:
            result = NUM_ONE_CHOSEN + NUM_TWO_CHOSEN;


            printf("%d. %d + %d = ", counter, NUM_ONE_CHOSEN, NUM_TWO_CHOSEN);
            scanf("%d",&userAnswer);
            if(userAnswer == result)
            {
                cor.push_back(result);
                corNum.push_back(counter);
                correct++;
                counter++;
            }
            else
            {
                inCor.push_back(result);
                incorNum.push_back(counter);
                incorrect++;
                counter++;
            }
        break;
       
        case 2:
            NUM_ONE_CHOSEN = checkGreaterThan(NUM_ONE_CHOSEN, NUM_TWO_CHOSEN,
            MAX_NUM_ONE, MIN_NUM_ONE);
            result = NUM_ONE_CHOSEN - NUM_TWO_CHOSEN;


            printf("%d. %d - %d = ", counter, NUM_ONE_CHOSEN, NUM_TWO_CHOSEN);
            scanf("%d",&userAnswer);
            if(userAnswer == result)
            {
                cor.push_back(result);
                corNum.push_back(counter);
                correct++;
                counter++;
            }
            else
            {
                inCor.push_back(result);
                incorNum.push_back(counter);
                incorrect++;
                counter++;
            }
        break;


        case 3:
            result = NUM_ONE_CHOSEN * NUM_TWO_CHOSEN;


            printf("%d. %d * %d = ", counter,NUM_ONE_CHOSEN, NUM_TWO_CHOSEN);
            scanf("%d",&userAnswer);
            if(userAnswer == result)
            {
                cor.push_back(result);
                corNum.push_back(counter);
                correct++;
                counter++;
            }
            else
            {
                inCor.push_back(result);
                incorNum.push_back(counter);
                incorrect++;
                counter++;
            }
        break;


        case 4:
           
            NUM_ONE_CHOSEN = checkGreaterThan(NUM_ONE_CHOSEN, NUM_TWO_CHOSEN,
            MAX_NUM_ONE, MIN_NUM_ONE);
           


            result = NUM_ONE_CHOSEN / NUM_TWO_CHOSEN;


            printf("%d. %d / %d = ", counter,NUM_ONE_CHOSEN, NUM_TWO_CHOSEN);
            scanf("%d",&userAnswer);
            if(userAnswer == result)
            {
                cor.push_back(result);
                corNum.push_back(counter);
                correct++;
                counter++;
            }
            else
            {
                inCor.push_back(result);
                incorNum.push_back(counter);
                incorrect++;
                counter++;
            }
        break;
       
        }
    } while (counter < numQuestions + 1);


    t = clock() - t;
    float time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
		auto end = chrono::steady_clock::now();
		time_taken = chrono::duration_cast<chrono::seconds>(end - start).count();
 



    printf("You got %d correct and %d incorrect out of %d questions!\n",
    correct, incorrect, numQuestions);
    sleep(1);
    printf("It took you %.2f seconds to complete %d questions.\n\n", time_taken, numQuestions);
    sleep(1);
    printResults(cor, inCor);
    sleep(3);
    printf("Would You Like to Play again? Y/N: ");
    scanf("%s",&replay);
   
    if(replay == 'Y')
    {
        cor.clear();
        inCor.clear();
        corNum.clear();
        incorNum.clear();
        mathGame();
    }
    else
        exit(0);
   
}
void printResults(vector<int> cor, vector<int> inCor)
{
    if(cor.size() == 0)
        cout << "You Have gotten no answers correct!" << endl;
    else
    {
        printf("Your correct answers were: ");
        cout << endl;
        cout << "Q: Numbers: ";
        for(auto i: corNum)
            cout << i << " ";


        cout << endl;
        cout << "Answers: ";
        for(auto i: cor)
            cout << i << " ";
    }
    cout << endl;
    if(inCor.size() == 0)
        cout << "You Have gotten no answers incorrect!" << endl;
    else
    {
        cout << endl;
        printf("Your incorrect answers were: \n");
        cout << "Q: Numbers: ";
        for(auto i: incorNum)
            cout << i << " ";


        cout << endl;
        cout << "Correct Answers: ";
        for(auto i: inCor)
            cout << i << " ";
    }
    cout << endl;


}
