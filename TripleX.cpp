//We are going to build a game with non-Graphical interface
#include<iostream>
#include<ctime> //Preprocesser Directive
using namespace std;
 void PrintIntroduction (int Difficulty){
     //Print Welcome message to the terminal
    std::cout<<"\n\nYou are a secret agent breaking into a level\n "<<Difficulty ;  //Expression statement
    std::cout<<"Secure server room..\nEnter the correct code to continue...\n\n"<<endl;

 }

//Function
bool PlayGame(int Difficulty)
{
    PrintIntroduction(Difficulty);
    //Declaration statement
    const int CodeA=rand() %Difficulty+Difficulty;
    const int CodeB=rand() %Difficulty+Difficulty;
    const int CodeC=rand() %Difficulty+Difficulty;

    const int CodeSum=CodeA+CodeB+CodeC;
    const int CodeProduct=CodeA*CodeB*CodeC;

    //Print CodeSum and CodeProduct to the terminal
    std::cout<<std::endl;
    std::cout<<"+There are 3 numbers in the code"<<std::endl;
    std::cout<<"\nThe code add-up to :"<<CodeSum;
    std::cout<<"\n+The code multiply to give: "<<CodeProduct<<std::endl;

    int GuessA,GuessB,GuessC;
    std::cin>>GuessA>>GuessB>>GuessC;


    int GuessSum=GuessA+GuessB+GuessC;
    int GuessProduct=GuessA*GuessB*GuessC;  

//Check if the player guess is correct
    if (GuessSum==CodeSum && GuessProduct==CodeProduct)
     {
        std::cout<<"\nWell Done Agent! You have extracted a file!Keep going!*** ";
        return true;
    } else{
        std::cout<<"\n***You entered the wrong code! careful agent!Try again ***";
        return false;
    }
}
int main(){ 
    srand(time(NULL));  //Create new random sequence based on time of day
        int LevelDifficulty=1;
        int const MaxDifficulty=5; 

         //Return statement
        while (LevelDifficulty<=MaxDifficulty)
         { 
            //Loop the game until all levels are completed
            bool bLevelComplete=PlayGame(LevelDifficulty);
            //This will solve your endless running issue
            std::cin.clear();//clear any error
            std::cin.ignore();//Discards the buffer

            if (bLevelComplete)
            {
                ++LevelDifficulty;

            }
        }
        std::cout<<"\n***Great Work Agent! You got all the files!Now get out of there!***\n";
        return 0; 



}