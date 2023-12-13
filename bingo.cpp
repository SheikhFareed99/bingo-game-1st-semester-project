#include <iostream>
#include <string>   // for handling strings 
#include <windows.h>// in my project its use is for adding colours in text output
#include <fstream> // for file handling 
#include<ctime>// for differ randam number on differ time
using namespace std;
// constants
const int rows = 5;
const int cols = 5;
const int Size = 5;
const int max_number = 25;
// functions declarations
void finished_message();

void text_colour(int color);

void generate_bingocard(int arr[][cols], int row, int col);

void mark_number(int card[][cols], int number);

bool finding_bingo(int card[Size][Size]);

void print_bingo(int arr[][cols], int row, int col);

bool looking_dublicate(int arr[], int sizee, int number);

int take_input(int lowerBound, int upperBound);

void display_menu();

void display_mode(int& mode);

void winning_message(const string& winner, const string& loser, int bingoCard[][cols], int bingoCard2[][cols], int rows, int cols);

int mode_2(int arr[cols][rows], int& number);

int mode_3(int arr[cols][rows], int& number);

int toss(const string& playerName);

void wellcome_message();

void player_namebox(const string& playerName);

void player_selectionbox();

void exit_message();

void save_data(int turn, const string& playername, const string& playername2, int option, int mode, int bingocard[][cols], int bingocard2[][cols]);

void read_data(int& turn, string& playername, string& playername2, int& option, int& mode, int bingocard[][Size], int bingocard2[][Size]);

    int main()
    {
        
        srand(static_cast<unsigned int>(time(0)));
        //use of srand is to have differnt random number each time .
        // i need random numbers in toss,generating bingo  card and in single player game.
        wellcome_message();
        // made a function in which board appear to select menu
        Sleep(5000);
        // sleep function to pause my console screen for 5 second
        int choice_menu;
        string resume_option;
        int mode=0;
        int bingo_card[rows][cols];
        // bingo card of 1st player
        int bingo_card2[rows][cols];
        //bingo card of 2nd player
        string player_name;
        string player_name2;
        int array[max_number] ;
        // this array is to store numbers  that are selected by all the players
        // its purpose is that no number is repeated again by comparing new number with this array 
        int array_size = 0; // Keep track of numbers revealed during the game      
        int player_number2 = 0;
        int player_number = 0;
        int player_option = 0;
        int turn=0;
       
        while (true)
        {
            display_menu();
            
            choice_menu = take_input(1, 4);
            // player can elect any of 4 options only else he will get error
            if (choice_menu == 4)
            {
                system("cls");
                // use of system cls is to clear the screen after showing the main menu box

                exit_message();
                
                break;
                // if user enter choice 4 the program will terminat wih showi ng exit message .
            }
            else if (choice_menu == 3)
            {
                system("cls");
                ifstream history("gamehistroy.txt");  
                // Use ifstream to open the file in read mode
                // if user enter choice 3 all the previous game histroy wil be showed up 
                string line;

                if (history.is_open())
                {
                    // Read and display each line from the file
                    while (getline(history, line))
                    {
                        text_colour(3);
                        cout << line << endl;
                        
                    }

                    history.close(); // close the file after reading
                }
                else
                {
                    cerr << "Error opening file: gamehistroy.txt" << endl;
                }
                cout << "Enter anything to go to main menu\n";
                text_colour(15);
                cin.ignore();
                // use of cin.ignore is to pause the screen it will be paused till user press enter or something
                system("cls");
            }
            
          
                
                
            else  if (choice_menu == 1)
            {
                system("cls");
                player_selectionbox();
                // so when user chose 1 in main meun which is start previous screen will be clear bcz of system cls
                // player selection board will be appear to select w1 player or 2 player game 
                player_option = take_input(1, 2);
                system("cls");
                if (player_option == 1)
                {
                    display_mode(mode);
                    // if user enter 1 its mean he want to play with computer 
                    // so mode variable to tell wheather user want to play easy hard medium
                    text_colour(11);
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    player_namebox("Player 1");
                    getline(cin, player_name);
                    text_colour(15);
                    player_name2 = "computer";

                }

                else
                {
                    // if user select 2 player game else will open and ask bth player names 
                    text_colour(11);
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    player_namebox("Player 1");
                    getline(cin, player_name);
                    text_colour(15);
                    cout << "\n\n";

                    // this text_colour function is add colour in text 
                    text_colour(11);
                    player_namebox(" Player  2  ");
                    getline(cin, player_name2);
                    text_colour(15);
                }

                // generate bingo card function will make a random 2d array of 5x5
                generate_bingocard(bingo_card, rows, cols);
                generate_bingocard(bingo_card2, rows, cols);

                system("cls");
                // now toss function it is running on random number between 0 and 1 
                turn = toss(player_name);

                Sleep(2500);
            }

            else if (choice_menu == 2)
            {
              
                // it will read all the files that are included in it 
                // its purpose is when user leave game and come again he can start where he stoppped
                    read_data(turn, player_name, player_name2, player_option, mode, bingo_card, bingo_card2);
            }
             
            if (choice_menu == 1 || choice_menu == 2)
            {
                //this if will work when choice is either start or resume and put you in while loop
                //  to initilise game
                while (true)
                {
          	if(choice_menu == 2)
                	{
                	  ifstream resume;
                resume.open("resume.txt");
                resume>> resume_option;

    if (resume_option == "finished") {
             finished_message();
        break; 
    }
}
                  
                  	
				  

                    //  when player leave the game all his data will be saved here so when i come again 
                    //this data can be saved so he can continue without any disturbance
                    save_data(turn, player_name, player_name2, player_option, mode, bingo_card, bingo_card2);
                  // so when turn is 0 player 1 plays when 1 player 2 or computer plays
                    if (turn == 0)
                    {  
                      // on the top of screen this text willl appear to tell  what player 2 has chooses
                            text_colour(11);
                            cout << player_name2 << "  chooses: " << player_number2 <<"\n\n\n";
                            text_colour(15);
                

                        // Player's turn
                        text_colour(14);
                        cout << player_name << " card:\n\n";
                        text_colour(15);
                        print_bingo(bingo_card, rows, cols);
                        // this function is to print updated bingo card 
                        text_colour(14);
                        cout << player_name << " turn:\n";
                        text_colour(15);

                    
                        // this loop will see wheater number enter by user is repeated or not 
                        // by comparing user entered number with array i told before
                         player_number = take_input(1, 25);

                        while (looking_dublicate(array, array_size, player_number))
                        {
                        	 text_colour(3);
                        	cout<<"number already present\n";
                        	 text_colour(15);
                            player_number = take_input(1, 25);
                        }
                        array[array_size] = player_number;
                        array_size++;
                        // when unrepeated number is entered by user it will be stored in array so it 
                        // cant be enter again
                        mark_number(bingo_card, player_number);
                        mark_number(bingo_card2, player_number);
                        // this function is mark thar number in both bingo cards by replacing that number 
                       // on bingo card with zero (0)

                        if (finding_bingo(bingo_card))
                        {
                        
                            winning_message(player_name, player_name2, bingo_card, bingo_card2, rows, cols);
                            break;
                        }


                        else if (finding_bingo(bingo_card2))
                        {
                            
                            winning_message(player_name2, player_name, bingo_card2, bingo_card, rows, cols);

                            break;
                        }

                        // now this function will look if the player has achieve bingo or not if achieve show winning box
                        turn = 1; 
                        // Switch turn to the player 2
                    }



                    else

                    {
                        if (player_option == 1)
                            // Computer's turn when player chooses to play 1 player game he has to 
                            // compete with computer havng different modes

                        {

                            player_number2 = rand() % 25 + 1;
                            // computer will give random number it is for easy mode 
                            // Adjust the computer's number based on the selected mode

                            if (mode == 2)
                            {
                                player_number2 = mode_2(bingo_card2, player_number2);
                            }
                            if (mode == 3)
                            {
                                player_number2 = mode_3(bingo_card2, player_number2);
                            }

                            while (looking_dublicate(array, array_size, player_number2))
                            {
                                player_number2 = rand() % 25 + 1;
                            }
                            // all below functions are same as player 1 

                            array[array_size] = player_number2;
                            array_size++;

                            mark_number(bingo_card, player_number2);
                            mark_number(bingo_card2, player_number2);


                            if (finding_bingo(bingo_card))
                            {
                            
                                winning_message(player_name, player_name2, bingo_card, bingo_card2, rows, cols);

                                break;
                            }
                            else if (finding_bingo(bingo_card2))
                            {
                                
                                winning_message(player_name2, player_name, bingo_card2, bingo_card, rows, cols);

                                break;
                            }
                  ofstream resume;                         	
                resume.open("resume.txt");
                resume<< "unfinished"<<endl;
                            turn = 0; // Switch turn to the player
                        }

                        else if (player_option == 2)
                        {
                            // in this if player chooses 2 player game this if condition will run 
                            // all its running functions and process are same as above player 1
                            system("cls");
                            text_colour(11);
                            cout << player_name << "  chooses: " << player_number <<"\n\n\n";
                            text_colour(15);

                            // Player's turn
                            text_colour(14);
                            cout << player_name2 << " card:\n\n";
                            text_colour(15);
                            print_bingo(bingo_card2, rows, cols);

                            text_colour(14);
                            cout << player_name2 << " turn:\n";
                            text_colour(15);

                            player_number2 = take_input(1, 25);

                        while (looking_dublicate(array, array_size, player_number2))
                        {
                        	text_colour(3);
                        	cout<<"number already present\n";
                        	text_colour(15);
                            player_number2 = take_input(1, 25);
                        }
                            array[array_size] = player_number2;
                            array_size++;

                            mark_number(bingo_card, player_number2);
                            mark_number(bingo_card2, player_number2);

                            if (finding_bingo(bingo_card))
                            {
                            
                                winning_message(player_name, player_name2, bingo_card, bingo_card2, rows, cols);

                                break;
                            }
                            else if (finding_bingo(bingo_card2))

                            {
                        
                                winning_message(player_name2, player_name, bingo_card2, bingo_card, rows, cols);

                                break;
                            }

                            turn = 0;

                        }
                    }
                }
            }
            
        }
        
    }// so  main body finished here
    // now all the functions that are being declared above are below with definations 


void finished_message() {
    system("cls");

    text_colour(9);
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
    cout << "\t\t\t\t\t\t\t\t|    GAME HAS BEEN FINISHED             |\n";
    cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
    text_colour(15);

    cin.ignore();
}

    void text_colour(int color)
    {

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);

    }
    //  this function will generate 2d array and fill each index with random number
    void generate_bingocard(int arr[][cols], int row, int col)
    {
        for (int i = 0; i < row * col;)
        {
            int randomNum = rand() % max_number + 1;

            bool isDuplicate = false;

            // Check if the randomly generated number already exists in the array
            //generated 2d array in single loop to avoid dublication
            for (int j = 0; j < i; j++)
            {
                if (arr[j / col][j % col] == randomNum)
                {
                    isDuplicate = true;
                    break;
                }
            }

            // If the number is not a duplicate, insert it into the array
            if (!isDuplicate)
            {
                arr[i / col][i % col] = randomNum;
                i++;
            }
        }
    }
    // this function will mark numbber of number entered by user and replaced it will zero
    void mark_number(int card[][cols], int number)
    {
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (card[i][j] == number)
                {
                    card[i][j] = 0;
                }
            }
        }
    }



    // function to check if a bingo is found in the given card.
    bool finding_bingo(int card[Size][Size])
    {
        // check for bingo in rows.
        int rowcheck = 0;
        for (int row = 0; row < Size; ++row)
        {
            int count = 0;
            // count the number of marked cells (0) in the current row.
            for (int col = 0; col < Size; ++col)
            {
                if (card[row][col] == 0)
                {
                    count++;
                }
            }
            // if all cells in the row are marked increment rowcheck.
            if (count == Size)
            {
                rowcheck++;
            }
        }

        // check for bingo in columns.
        int columncheck = 0;
        for (int col = 0; col < Size; ++col)
        {
            int count = 0;
            // count the number of marked line (0) in the current column.
            for (int row = 0; row < Size; ++row)
            {
                if (card[row][col] == 0)
                {
                    count++;
                }
            }
            // if all cells in the column are marked increment columncheck.
            if (count == Size)
            {
                columncheck++;
            }
        }

        // Check for bingo in diagonals.
        int diagonalcheck = 0;

        // Count the number of marked line (0) in the main diagonal.
        int count = 0;
        for (int i = 0; i < Size; ++i)
        {
            if (card[i][i] == 0)
            {
                count++;
            }
        }
        // If all cells in the main diagonal are marked  increment diagonalcheck.
        if (count == Size)
        {
            diagonalcheck++;
        }

        // Count the number of marked line of 0's in the other diagonal.
        count = 0;
        for (int i = 0; i < Size; ++i)
        {
            if (card[i][Size - 1 - i] == 0)
            {
                count++;
            }
        }
        // If all cells in the other diagonal are marked increment diagonalcheck.
        if (count == Size)
        {
            diagonalcheck++;
        }

        // Return true if at least 5 rows, columns, or diagonals have bingo.
        return (rowcheck + columncheck + diagonalcheck) >= 5;
    }

    // this below function will print the updated 2d array or bingo card after every modification

    void print_bingo(int arr[][cols], int row, int col)
    {
       
        text_colour(6); 
        

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                
                if (arr[i][j] == 0)
                {
                    text_colour(10); 
                }

                cout << arr[i][j] << "\t";

                
                text_colour(6); 
            }
            cout << "\n\n\n";
        }

        text_colour(15);
    }

    // this function will se wheater number is repeated or not 
    // this functoon will compare entered number of user with array that stored all the already entered number

    bool looking_dublicate(int arr[], int sizee, int number)
    {
        for (int i = 0; i < sizee; i++)
        {
            if (arr[i] == number)
            {

                return true;
            }
        }
        // return false only after checking the entire array
        return false;
    }
    //  this wil check and do error handling by checking if user  entered corrected input betwen range
    int take_input(int mini, int maxi)
    {
        int user_input;
        while (true)
        {


            if (cin >> user_input && user_input >= mini && user_input <= maxi)
            {
                break;
            }
        //  also it wil check if the user havent enter anything other then integer
            cin.clear();
            text_colour(3);
            cout << "Enter a valid number:\n";
            text_colour(15);
            cin.ignore(INT_MAX, '\n');
        }

        cin.ignore(INT_MAX, '\n');
        return user_input;
    }


    // display function to show different options in i box this is for user interaction
    void display_menu()
    {
        system("cls");
        text_colour(14);
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t|              BINGO GAME              |\n";
        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t| Options:                             |\n";
        cout << "\t\t\t\t\t\t\t\t|        1. Start Game                 |\n";
        cout << "\t\t\t\t\t\t\t\t|        2. Resume Game                |\n";
        cout << "\t\t\t\t\t\t\t\t|        3. Game Histroy               |\n";
        cout << "\t\t\t\t\t\t\t\t|        4. Exit                       |\n";
        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
        text_colour(15);
    }

    // this is mode function which will only appear when player chooses 1player game 
    // so he will selet what mode he want to play with the co mputer 
    void display_mode(int& mode)
    {
        text_colour(11);
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t|              MODE SELECT             |\n";
        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t| Options:                             |\n";
        cout << "\t\t\t\t\t\t\t\t|        1. Easy                       |\n";
        cout << "\t\t\t\t\t\t\t\t|        2. Medium                     |\n";
        cout << "\t\t\t\t\t\t\t\t|        3. Hard                       |\n";
        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
        text_colour(15);

        mode = take_input(1, 3);
        cout << endl;

        text_colour(10);

        cout << "\t\t\t\t\t\t\t\t-----------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t|           MODE SELECTED:               |\n";
        cout << "\t\t\t\t\t\t\t\t-----------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t|                                        |\n";


        switch (mode)
        {
        case 1:

            cout << "\t\t\t\t\t\t\t\t|                 Easy                   |\n";
            break;
        case 2:

            cout << "\t\t\t\t\t\t\t\t|                 Medium                 |\n";
            break;
        case 3:

            cout << "\t\t\t\t\t\t\t\t|                 Hard                   |    \n";
            break;
        }
        cout << "\t\t\t\t\t\t\t\t------------------------------------------\n";
        text_colour(15);
        Sleep(2500);
        system("cls");

    }
    // this function will do many things apart for show winnning message 
    void winning_message(const string& winner, const string& loser, int bingoCard[][cols], int bingoCard2[][cols], int rows, int cols)
    {
        system("cls");
        text_colour(3);
        //if player won it will show the message
        cout << "*************************\n\n\n";
        cout << "*  Bingoooo! " << winner << " won! *\n\n\n";
        cout << "*************************\n\n\n";
        text_colour(15);
        // below i uses files_del function so when player won all the saved files can be deleted 
        // to avoid any buffer value
        
        // below i use gamehistroy file opened to store who won the contest so i can have the record
        ofstream out;
        out.open("gamehistroy.txt", ios::app);
        out << winner << " vs " << loser << endl;
        out << winner << " won the contest " << endl;
        out << endl;
        ofstream inn;
        inn.open("resume.txt");
        inn << "finished"<<endl;
        inn.close();
        cout << winner << " bingo card\n";
        print_bingo(bingoCard, rows, cols);
        cout << loser << " bingo card\n";
        print_bingo(bingoCard2, rows, cols);



        cout << "\n\nEnter anything to continue....";
        cin.ignore();
        system("cls");
    }
    // so this  mode 2 which is medium this function wil work by filling one diagonal and then randomly
    int mode_2(int arr[cols][rows], int& number)
    {
        // firstly it will see how many zeros are in one diagnol
        // its purpose is to fill diagonal with zeros and in one diagnonal of 5x5 there are 5 elements
        // if all are zero it will do nothing and give random number else it will fill diagnols
        int c = 0;
        for (int i = 0; i < Size; i++)
        {
            if (arr[i][i] == 0)
            {
                c++;
            }
        }
        // if less then 5 zeros in one diagonal then it will go inside this condition
        if (c < 5)
        {

            while (true)
            {
                bool check = false;
                for (int i = 0; i < Size; i++)
                {

                    if (arr[i][i] == number)
                    {
                        check = true;
                        break;
                    }
                    else
                    {
                        check = false;
                    }
                }
                // it willl give that number which will be equal to diagnaol number in bingo card randomly
                // untill random number match wih diagonal number of bingo card
                if (!check)
                {

                    number = rand() % 25 + 1;
                }
                else
                { // when found it will return that number
                    return number;
                    break;
                }
            }
        }
        //if zeros are 5 it will give that random number
        else
        {
            return number;
        }
    }
          // so this  mode 3 which is hard this function wil work by filling two diagonal and then randomly
    int mode_3(int arr[cols][rows], int& number)
    {
         // firstly it will see how many zeros are in two diagnol
        // its purpose is to fill diagonal with zeros and in two diagnonal of 5x5 there are 10 elements
       // if all are zero it will do nothing and give random number else it will fill diagnols
        int c = 0;
        for (int i = 0; i < Size; i++)
        {
            if (arr[i][i] == 0)
            {
                c++;
            }
            if (arr[i][Size - 1 - i] == 0)
            {
                c++;
            }
        }
        // if less then 10 zeros in one diagonal then it will go inside this condition
        if (c < 10)
        {

            while (true)
            {
                bool check = false;
                for (int i = 0; i < Size; i++)
                {

                    if (arr[i][i] == number || arr[i][Size - 1 - i] == number)
                    {
                        check = true;
                        break;
                    }
                    else
                    {
                        check = false;
                    }
                }
                // it willl give that number which will be equal to diagnaol number in bingo card randomly
                // untill random number match wih diagonal number of bingo card
                if (!check)
                {

                    number = rand() % 25 + 1;
                }
                else
                {
                    // when found it will return that number
                    return number;
                    break;
                }
            }
        }
        else
        {   // when all diagonals are zero it will l return that already given random number
            return number;
        }
    }
    // toss function
    int toss(const string& playerName)
    {
        text_colour(10);
        cout << playerName << " select\n";
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t|              Toss                     |\n";
        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t|          press 0 for head             |\n";
        cout << "\t\t\t\t\t\t\t\t|          press 1 for tail             | \n";
        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
        text_colour(15);
        // toss is also made fair and square random number will be given between 0 and 1
        int toss_no = take_input(0, 1);
        int turn = rand() % 2;
        if (toss_no == turn)
        {
            text_colour(12);

            cout << "\t\t\t\t\t\t\t\t -------------------------------------------------\n";
            cout << "\t\t\t\t\t\t\t\t |                  Toss update                   |\n";
            cout << "\t\t\t\t\t\t\t\t -------------------------------------------------\n";
            cout << "\t\t\t\t\t\t\t\t           You won the toss, " << playerName << ": ";
            text_colour(15);
            turn = 0;
        }
        else
        {
            text_colour(12);

            cout << "\t\t\t\t\t\t\t\t----------------------------------------------\n";
            cout << "\t\t\t\t\t\t\t\t|              Toss update                       |\n";
            cout << "\t\t\t\t\t\t\t\t----------------------------------------------\n";
            cout << "\t\t\t\t\t\t\t\t|        You lose the toss," << playerName << "|\n";
            cout << "\t\t\t\t\t\t\t\t----------------------------------------------\n";
            text_colour(15);
            turn = 1;
        }
        return turn;
    }

    // So it is our wellcome board box 
    void wellcome_message()
    {
        text_colour(6);
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t****************************************************************************************\n";
        cout << "\t\t\t\t\t\t*                                                                                      *\n";
        text_colour(3);
        cout << "\t\t\t\t\t\t                          WELCOME TO bingo                                         \n";
        text_colour(6);
        cout << "\t\t\t\t\t\t*                                                                                      *\n";
        cout << "\t\t\t\t\t\t****************************************************************************************\n";
        text_colour(6);
        cout << "\t\t\t\t\t\t*    ###########   ##   ## ##            ##     ##################     ###########     *       \n";
        cout << "\t\t\t\t\t\t     ##      ##    ##   ##   ##          ##     ##              ##     ##       ##             \n";
        cout << "\t\t\t\t\t\t*    ##    ##      ##   ##     ##        ##     ##          ##  ##     ##       ##     *       \n";
        cout << "\t\t\t\t\t\t     ##   ###      ##   ##       ##      ##     ##          ######     ##       ##             \n";
        cout << "\t\t\t\t\t\t*    ##    ##      ##   ##         ##    ##     ##                     ##       ##     *       \n";
        cout << "\t\t\t\t\t\t     ##      ##    ##   ##           ##  ##     ##              ##     ##       ##              \n";
        cout << "\t\t\t\t\t\t*    ###########   ##   ##             ####     ##################     ###########     *       \n";

        text_colour(2);
        cout << "                                                             \n";

        cout << "\t\t\t\t\t\t                                                                                                \n";

        text_colour(6);
        cout << "\t\t\t\t\t\t***************************************************************************************\n\n";
        cout << "\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tloading....";


    }
    // player name box
    void player_namebox(const string& playerName)
    {

        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t              PLAYER NAME              |\n";
        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t  Enter your  name, " << playerName << ": ";
    }
    // player selection board
    void player_selectionbox()
    {
        text_colour(11);
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t|         PLAYER SELECTION MENU         |\n";
        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";
        cout << "\t\t\t\t\t\t\t\t| Options:                              |\n";
        cout << "\t\t\t\t\t\t\t\t|        1. singer player game          |\n";
        cout << "\t\t\t\t\t\t\t\t|        2. two Player game             |\n";
        cout << "\t\t\t\t\t\t\t\t----------------------------------------\n";

        text_colour(15);
    }
    // when player chooses to exit this message will appear
    void exit_message() {
        text_colour(10);
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        cout << "\t\t\t\t\t\t\t=========================================================\n\n" << endl;
        cout << "\t\t\t\t\t\t\t\t        you choose to exit the game.       \n" << endl;
        cout << "\t\t\t\t\t\t\t\t        We hope to see you again soon!    \n\n" << endl;
        cout << "\t\t\t\t\t\t\t=========================================================" << endl;
        text_colour(15);
    }
    // so this function is store the data of both the players so when they chooses 
    // to leave the data can be stored in the files so they can contiune where they stopped
    void save_data(int turn, const string& playername, const string& playername2, int option, int mode, int bingocard[][cols], int bingocard2[][cols]) {
        system("cls");

        // Save turn to file
        ofstream turnfile("turn.txt");
        if (turnfile.is_open()) {
            turnfile << turn;
            turnfile.close();
        }

        // Save player names to files
        ofstream name1file("name1.txt");
        if (name1file.is_open()) {
            name1file << playername;
            name1file.close();
        }

        ofstream name2file("name2.txt");
        if (name2file.is_open()) {
            name2file << playername2;
            name2file.close();
        }

        // Save option to file
        ofstream optionfile("option.txt");
        if (optionfile.is_open()) {
            optionfile << option;
            optionfile.close();
        }

        // Save mode to file (if option is 1)
        if (option == 1) {
            ofstream modefile("mode.txt");
            if (modefile.is_open()) {
                modefile << mode;
                modefile.close();
            }
        }

        // Save bingo cards to files
        ofstream card1file("card1.txt");
        if (card1file.is_open()) {
            for (int i = 0; i < Size; i++) {
                for (int j = 0; j < Size; j++) {
                    card1file << bingocard[i][j] << " ";
                }
                card1file << endl;
            }
            card1file.close();
        }

        ofstream card2file("card2.txt");
        if (card2file.is_open()) {
            for (int i = 0; i < Size; i++) {
                for (int j = 0; j < Size; j++) {
                    card2file << bingocard2[i][j] << " ";
                }
                card2file << endl;
            }
            card2file.close();
        }
    }
    // this will read the data of the user when he chooses to contiune from where he stopped
    // his data will be read and put in their concenered variables
    void read_data(int& turn, string& playername, string& playername2, int& option, int& mode, int bingocard[][Size], int bingocard2[][Size]) 
    {
        // read turn from file.
        ifstream turnfile("turn.txt");
        if (turnfile.is_open()) {
            turnfile >> turn;
            turnfile.close();
        }

        // read player 1 name from file.
        ifstream name1file("name1.txt");
        if (name1file.is_open()) {
            name1file >> playername;
            name1file.close();
        }

        // Read player 2 name from file.
        ifstream name2file("name2.txt");
        if (name2file.is_open()) {
            name2file >> playername2;
            name2file.close();
        }

        // read game option from file.
        ifstream optionfile("option.txt");
        if (optionfile.is_open()) {
            optionfile >> option;
            optionfile.close();
        }

        // If option is 1 (indicating single player mode), read mode from file.
        if (option == 1) {
            ifstream modefile("mode.txt");
            if (modefile.is_open()) {
                modefile >> mode;
                modefile.close();
            }
        }

        // read player 1 bingo card from file.
        ifstream card1file("card1.txt");
        if (card1file.is_open()) {
            for (int i = 0; i < Size; i++) {
                for (int j = 0; j < Size; j++) {
                    card1file >> bingocard[i][j];
                }
            }
            card1file.close();
        }

        // Read player 2 bingo card from file.
        ifstream card2file("card2.txt");
        if (card2file.is_open()) {
            for (int i = 0; i < Size; i++) {
                for (int j = 0; j < Size; j++) {
                    card2file >> bingocard2[i][j];
                }
            }
            card2file.close();
        }
    }
