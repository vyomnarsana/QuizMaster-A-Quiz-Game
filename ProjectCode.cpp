
#include <bits/stdc++.h>
#include <sys/types.h>
#include<thread>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<conio.h>
#include <time.h>
#include <windows.h>
#include <iostream>
#include <Windows.h>
#include <iomanip>








using namespace std;
vector<pair<vector<string>, string>> easyque;
vector<pair<vector<string>, string>> medque;
vector<pair<vector<string>, string>> hardque;
vector<pair<vector<string>, string>> exhardque;
vector<pair<vector<string>, string>> flipeasy;
vector<pair<vector<string>, string>> flipmed;
vector<pair<vector<string>, string>> fliphard;
vector<pair<vector<string>, string>> flipexhard;
vector<pair<vector<string>, string>> fieldwise_que;
vector<pair<vector<string>, string>> advanced_que;

vector<string> easy_hints;
vector<string> med_hints;
vector<string> hard_hints;
vector<string> exhard_hints;

const vector<string> list_amount = {"5000", "10,000", "20,000", "40,000", "80,000", "1,60,000", "3,20,000", "6,40,000", "12,80,000", "25,60,000", "50,00,000", "1,00,00,000", "7,00,00,000"};
const vector<string> advanced_amount = {"240000", "480000", "960000", "1920000", "3840000"};
const vector<string> bonus_amount={"10,00,000","12,00,000","23,00,000","15,00,000","17,00,000","20,00,000","16,00,000","18,00,000","21,00,000"};
bool visited[21]={0};
int counter = -1, adv_counter = 0;
string curr_amount = "0", checked_amount = "0";
int feasy = 0, fmed = 0, fhard = 0;
string total = "0";
int button = 0;
bool lifeline[5] = {0};
class Generator
{
protected:
    bool easy_flag[17] = {0};
    bool medium_flag[21] = {0};
    bool hard_flag[12] = {0};
    bool advanced_flag[10] = {0};
    bool exhard_flag[4] = {0};
    virtual void gen(){};
};

class Easy_Generator : public Generator
{
public:
    int idx;

    void gen()
    {

        srand(time(NULL));
        idx = rand() % 17;
        while (easy_flag[idx] !=0)
        {
            idx = rand() % 17;
        } 
        easy_flag[idx] = 1;
        for (int i = 0; i < 5; i++)
        {
            cout << easyque[idx].first[i] << endl;
        }
    }
};
class Medium_Generator : public Generator
{
public:
    int idx;
    void gen()
    {

        srand(time(NULL));
        idx = rand() % 21;
        while (medium_flag[idx] != 0)
        {
            idx = rand() % 21;
        }
        medium_flag[idx] = 1;
        for (int i = 0; i < 5; i++)
        {
            cout << medque[idx].first[i] << endl;
        }
    }
};
class Hard_Generator : public Generator
{
public: 
int idx;
    void gen()
    {

        srand(time(NULL));
        idx = rand() % 12;
        while (hard_flag[idx] != 0)
        {
            idx = rand() % 12;
        }
        hard_flag[idx] = 1;
        for (int i = 0; i < 5; i++)
        {
            cout << hardque[idx].first[i] << endl;
        }
    }
    
};

class exhard_Generator : public Generator
{
public: 
int idx;
    void gen()
    {

        srand(time(NULL));
        idx = rand() % 4;
        while (hard_flag[idx] != 0)
        {
            idx = rand() % 4;
        }
        hard_flag[idx] = 1;
        for (int i = 0; i < 5; i++)
        {
            cout << hardque[idx].first[i] << endl;
        }
    }
    
};
// class fieldwise_Generator : public Generator{
// private:
// int field_num;
// public:
//     fieldwise_Generator(int field_num){
//         this->field_num=field_num;
//     }
// public:
//     int idx=2*(field_num)-2;
//     void gen()
//     {

      
//         for (int i = 0; i < 5; i++)
//         {
//             cout << fieldwise_que[idx].first[i] << endl;
//         }
//     }

// };


class Evaluator
{
    virtual void eval(string ans, int idx){};
};

class Easy_Evaluator : public Evaluator
{
public:
    void eval(string ans, int idx,int &Signal)
    {

        if (ans == easyque[idx].second)
        {
            cout << "Your answer is correct" << endl;
            counter++;
            cout << "Congo , You have won Rs. " << list_amount[counter] << endl;
            curr_amount = list_amount[counter];
        }
        else
        {
            
            Signal=0;
            if(Signal==0){
                throw Signal;
            }
        }
    }
};
class Medium_Evaluator : public Evaluator
{
public:
    void eval(string ans, int idx,int &Signal)
    {
        if (ans == medque[idx].second)
        {
            cout << "Your answer is correct"<<endl;
            counter++;
            cout << "Congo , You have won Rs. " << list_amount[counter] << endl;
            curr_amount = list_amount[counter];
            if (counter == 4)
            {
                checked_amount = list_amount[counter];
                cout << "You have reached a check point worth Rs. " << checked_amount << endl;
            }
        }
        else
        {
           Signal=0;
            if(Signal==0){
                throw Signal;
            }
        }
    }
};
class Hard_Evaluator : public Evaluator
{
public:
    void eval(string ans, int idx,int &Signal)
    {
        if (ans == hardque[idx].second)
        {
            cout << "Your answer is correct"<<endl;
            counter++;
            cout << "Congo , You have won Rs. " << list_amount[counter] << endl;
            curr_amount = list_amount[counter];
            if (counter == 9 || counter==11)
            {
                checked_amount = list_amount[counter];
                cout << "You have reached a check point worth Rs. " << checked_amount << endl;
            }
        }
        else
        {
           Signal=0;
            if(Signal==0){
                throw Signal;
            }
        }
        
       
    }
};

class exhard_Evaluator : public Evaluator
{
public:
    void eval(string ans, int idx,int &Signal)
    {
        if (ans == hardque[idx].second)
        {
            cout << "Your answer is correct"<<endl;
            counter++;
            cout << "Congo , You have won Rs. " << list_amount[counter] << endl;
            curr_amount = list_amount[counter]; 
            cout<<"YOU ARE THE ULTIMATE WINNER"<<endl;
            
        }
        else
        {
           Signal=0;
            if(Signal==0){
                throw Signal;
            }
        }
    }
};
class fieldwise_Evaluator : public Evaluator {

private:
int idx;

   
public:
    void eval(string ans, int field_num)
    {idx=2*(field_num)-2;
        if (ans == fieldwise_que[idx].second)
        {
           cout<<"Woah , You got the Bonus"<<endl;
           curr_amount+=bonus_amount[field_num-1];
           cout<<"Your prize money currently stands at "<<curr_amount<<endl;
        }
        else
        {
            cout << "Oops , Better luck next time but you can still continue the game...."<<endl;
        }
    }



};
class Lifeline
{
private:
    bool help;
    public:
    
    void Lifeline_or_not()
    {

        
            cout << "Which lifeline do you want to take?" << endl;
            if (lifeline[0] == 0)
            {
                cout << "(%) 50: 50 " << endl;
            }
            if (lifeline[1] == 0)
            {
                cout << "(!) Flip the question " << endl;
            }
            if (lifeline[2] == 0)
            {
                cout << "(+) Expert's Advice" << endl;
            }

            if (lifeline[3] == 0)
            {
                cout << "(@) Audience Poll" << endl;
            }
            
        
    }
    virtual void help_the_person(int idx){};
};

class feed_the_greed
{
   public:
    virtual void display(){
        
        cout << "Now you are playing in the advanced mode with 1.5X prize money" << endl;
    
    }
    
};

class fifty_fifty : public Lifeline
{
public:
    void help_the_person(int idx)
    {

        cout << "Removed two incorrect options. The two remaining options are :" << endl;
    }
};

class easy_fifty_fifty : public fifty_fifty
{
public:
    void help_the_person(int idx)
    {
        if (easyque[idx].second == "A")
        {
            int arr[] = {2, 3, 4};
            cout << easyque[idx].first[1] << endl
                 << easyque[idx].first[arr[rand() % 3]];
        }
        else if (easyque[idx].second == "B")
        {
            int arr[] = {1, 3, 4};
            cout << easyque[idx].first[2] << endl
                 << easyque[idx].first[arr[rand() % 3]];
        }
        else if (easyque[idx].second == "C")
        {
            int arr[] = {1, 2, 4};
            cout << easyque[idx].first[3] << endl
                 << easyque[idx].first[arr[rand() % 3]];
        }
        else
        {
            int arr[] = {1, 2, 3};
            cout << easyque[idx].first[4] << endl
                 << easyque[idx].first[arr[rand() % 3]];
        }
    }
};

class medium_fifty_fifty : public fifty_fifty
{
public:
    void help_the_person(int idx)
    {
        if (medque[idx].second == "A")
        {
            int arr[] = {2, 3, 4};
            cout << medque[idx].first[1] << endl
                 << medque[idx].first[arr[rand() % 3]];
        }
        else if (medque[idx].second == "B")
        {
            int arr[] = {1, 3, 4};
            cout << medque[idx].first[2] << endl
                 << medque[idx].first[arr[rand() % 3]];
        }
        else if (medque[idx].second == "C")
        {
            int arr[] = {1, 2, 4};
            cout << medque[idx].first[3] << endl
                 << medque[idx].first[arr[rand() % 3]];
        }
        else
        {
            int arr[] = {1, 2, 3};
            cout << medque[idx].first[4] << endl
                 << medque[idx].first[arr[rand() % 3]];
        }
    }
};

class hard_fifty_fifty : public fifty_fifty
{
public:
    void help_the_person(int idx)
    {
        if (hardque[idx].second == "A")
        {
            int arr[] = {2, 3, 4};
            cout << hardque[idx].first[1] << endl
                 << hardque[idx].first[arr[rand() % 3]];
        }
        else if (hardque[idx].second == "B")
        {
            int arr[] = {1, 3, 4};
            cout << hardque[idx].first[2] << endl
                 << hardque[idx].first[arr[rand() % 3]];
        }
        else if (hardque[idx].second == "C")
        {
            int arr[] = {1, 2, 4};
            cout << hardque[idx].first[3] << endl
                 << hardque[idx].first[arr[rand() % 3]];
        }
        else
        {
            int arr[] = {1, 2, 3};
            cout << hardque[idx].first[4] << endl
                 << hardque[idx].first[arr[rand() % 3]];
        }
    }
};

class Audience_Poll : public Lifeline
{
    private:
     int voteA, voteB, voteC, voteD, total;
     float perA, perB, perC, perD;

public:
    Audience_Poll(int voteA, int voteB, int voteC, int voteD)
    { 
        this->voteA = voteA;
        this->voteB = voteB;
        this->voteC = voteC;
        this->voteD = voteD;
        
        total = voteA + voteB + voteC + voteD;
        perA = ((float)voteA * 100) / total;
        perB = ((float)voteB * 100) / total;
        perC = ((float)voteC * 100) / total;
        perD = ((float)voteD * 100) / total;
    } 

    void help_the_person(int idx)
    {

        cout << "A : " << fixed << setprecision(2) << perA << "% |";
        for (int i = 0; i < voteA; i++)
        {
            cout << ">";
        }
        cout << "|" << endl;
        cout << "B : " << perB << "% |";
        for (int i = 0; i < voteB; i++)
        {
            cout << ">";
        }
        cout << "|" << endl;
        cout << "C : " << perC << "% |";
        for (int i = 0; i < voteC; i++)
        {
            cout << ">";
        }
        cout << "|" << endl;
        cout << "D : " << perD << "% |";
        for (int i = 0; i < voteD; i++)
        {
            cout << ">";
        }
        cout << "|" << endl;
    }
};



class flip_easy : public Lifeline
{
public:
    void help_the_person(int idx)
    {     
        cout<<"The question is changed to :"<<endl;

        for (int i = 0; i < 5; i++)
        {
            cout << flipeasy[feasy].first[i] << endl;
        }
        feasy++;
    }
};
class flip_med : public Lifeline
{
public:
    void help_the_person(int idx)
    {
         cout<<"The question is changed to: "<<endl;
        for (int i = 0; i < 5; i++)
        {
            cout << flipmed[fmed].first[i] << endl;
        }

        fmed++;
    }
};
class flip_hard : public Lifeline
{
public:
    void help_the_person(int idx)
    {
        cout<<"The question is changed to: "<<endl;
        for (int i = 0; i < 5; i++)
        {
            cout << fliphard[fhard].first[i] << endl;
        }
        fhard++;
    }
};

class eval_flip_easy : public Evaluator
{
public:
    void eval(string ans, int idx,int &Signal)
    {
        if (ans == flipeasy[feasy-1].second)
        {
            cout << "Your answer is correct" << endl;
            counter++;
            cout << "Congo , You have won Rs. " << list_amount[counter] << endl;
            curr_amount = list_amount[counter];
        }
        else
        {
            Signal=0;
            if(Signal==0){
                throw Signal;
            }
        }
    }
};

class eval_flip_med : public Evaluator
{
public:
    void eval(string ans, int idx,int &Signal)
    {
        if (ans == flipmed[fmed-1].second)
        {
            cout << "Your answer is correct"<<endl;
            counter++;
            cout << "Congo , You have won Rs. " << list_amount[counter] << endl;
            curr_amount = list_amount[counter];
            if (counter == 4)
            {
                checked_amount = list_amount[counter];
                cout << "You have reached a check point worth Rs. " << checked_amount << endl;
            }
        }
        else
        {
            Signal=0;
            if(Signal==0){
                throw Signal;
            }
        }
    }
};

class eval_flip_hard : public Evaluator
{
public:
    void eval(string ans, int idx,int &Signal)
    {
        if (ans == fliphard[fhard-1].second)
        {
            cout << "Your answer is correct"<<endl;
            counter++;
            cout << "Congo , You have won Rs. " << list_amount[counter] << endl;
            curr_amount = list_amount[counter];
            if (counter == 9 || counter == 11)
            {
                checked_amount = list_amount[counter];
                cout << "You have reached a check point worth Rs. " << checked_amount << endl;
            }
        }
        else
        {
            Signal=0;
            if(Signal==0){
                throw Signal;
            }
        }
    }
};

class Set_the_field : public Lifeline
{

    
public:
    

    void display_fields()
    {    
        cout<<"You will be given the option to choose the field of your choice and then you will be answering a bonus question associated of that field "<<endl;
      cout<<"But , but , but every field has some amount along with it which will be added to your prize money if you answer the question correctly"<<endl<<endl;



        cout << "Fields to be chosen from are:" << endl;
        cout << " 1. Entertainment [10 lacs] " << endl
             << " 2. Sports [12 lacs]" << endl;
        cout << " 3. Current Affairs [23 lacs]" << endl
             << " 4. Science and Technology [15 lacs] " << endl;
        cout << " 5. Religion , Culture and Mythology [17 lacs]" << endl
             << " 6. Geography [20 lacs]" << endl;
        cout << " 7. Fashion and Lifestyle [16 lacs] " << endl
             << " 8. Language and Literature [18 lacs] " << endl;
        cout << " 9. Nature and Wildlife [21 lacs] " << endl;


        
        cout << "Enter the number representing your field:" << endl;
    }

    void help_the_person(int index, int choice)
    {  static int idx=0;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < 5; i++)
            {
                cout << fieldwise_que[idx].first[i] << endl;
            }
            
            break;

        case 2:
            for (int i = 0; i < 5; i++)
            {
                cout << fieldwise_que[idx + 2].first[i] << endl;
            }
            
            break;

        case 3:
            for (int i = 0; i < 5; i++)
            {
                cout << fieldwise_que[idx + 4].first[i] << endl;
            }
            
            break;

        case 4:
            for (int i = 0; i < 5; i++)
            {
                cout << fieldwise_que[idx + 6].first[i] << endl;
            }
            
            break;

        case 5:
            for (int i = 0; i < 5; i++)
            {
                cout << fieldwise_que[idx + 8].first[i] << endl;
            }
            
            break;

        case 6:
            for (int i = 0; i < 5; i++)
            {
                cout << fieldwise_que[idx + 10].first[i] << endl;
            }
            
            break;

        case 7:
            for (int i = 0; i < 5; i++)
            {
                cout << fieldwise_que[idx + 12].first[i] << endl;
            }
            
            break;

        case 8:
            for (int i = 0; i < 5; i++)
            {
                cout << fieldwise_que[idx + 14].first[i] << endl;
            }
            
            break;

        case 9:
            for (int i = 0; i < 5; i++)
            {
                cout << fieldwise_que[idx + 16].first[i] << endl;
            }
            
            break;

        default:
            break;
        }
    }

    void eval_fieldwise_que(string ans, int choice)
    { static int idx=1;

        if (ans == fieldwise_que[(choice - 1) * 2 + idx - 1].second)
        {
            cout << "Your answer is correct"<<endl;
            counter++;
            cout << "Congo , You have won Rs. " << list_amount[counter] << endl;
            curr_amount = list_amount[counter];

            if (counter == 4)
            {
                checked_amount = list_amount[counter];
                cout << "You have reached a check point worth Rs. " << checked_amount << endl;
            }
        }
        else
        {
            cout << "Your answer is incorrect"<<endl;
        }
    }
};

class advanced_generator : public Generator, feed_the_greed
{
public:
    int idx;

    void gen()
    {

        srand(time(NULL));
        idx = rand() % 10;
        while (advanced_flag[idx] != 0)
        {
            idx = rand() % 10;
        }
        advanced_flag[idx] = 1;
        for (int i = 0; i < 5; i++)
        {
            cout << advanced_que[idx].first[i] << endl;
        }
    }
};

class advanced_evaluator : public Evaluator, feed_the_greed
{
public:
    void eval(string ans, int idx, float &ans_status,int &Signal)
    {
        int len1 = ans.length();
        int len2 = advanced_que[idx].second.length();
        int flag = 0;

        if (ans.compare(advanced_que[idx].second) == 0)
        {
            cout << "Your answer is correct" << endl;
            
            counter++;
            cout << "Congo , You have won Rs. " << advanced_amount[adv_counter] << endl; 
            adv_counter++;
            curr_amount = advanced_amount[adv_counter];
            flag = 1;
            ans_status = 1;
        }
        bool cond = 0;
        for (int i = 0; i < min(len1, len2); i++)
        {
            if (ans[i] == advanced_que[idx].second[i])
            {
                cond = 1;
            }
        }
        if (flag == 0)
        {
            if (cond == 1)
            {

                cout << "Your answer is partially correct" << endl;
                
                counter++;

                cout << stoi(advanced_amount[adv_counter]) / 4 << " have been deducted from your prize money and you have been shifted to the normal mode" << endl;
                int finalamount = stoi(curr_amount) - ((stoi(advanced_amount[adv_counter])) / 4); 
                adv_counter++;
                curr_amount = to_string(finalamount);
                cout << "Congo , You have won Rs. " << curr_amount << endl;
                ans_status = 0.5;
            }

            else
            {
                Signal=0;
            if(Signal==0){
                throw Signal;
            }
            }
        }
    }
};

class User_details
{

    string username;
    string password;
    string verifyusername;
    string verifypassword;
    bool verification;

public:
    User_details();
    User_details(string username, string password)
    {
        this->username = username;
        this->password = password;
    }

      void User_verified(string verifyusername, string verifypassword)
     {

         this->verifyusername = verifyusername;
        this->verifypassword = verifypassword;
     }

    bool operator ^ (User_details const &obj){
    
    return username==obj.verifyusername && password==obj.verifypassword;
        
        
    } 

};
// class Rulebook
// {
// public:
    static void rules1()
    {


        cout << "THE RULES OF THE GAME ARE PRETTY SIMPLE :" << endl;sleep(1.75);
        cout << "~> The game consists of total 13 questions with 4 different difficulty levels" << endl;sleep(1.5);
        cout << "~> Each question will have 4 options " << endl;sleep(1.75);
        cout << "~> The game will start with the amount of 5,000 and will go upto 70,000,000" << endl;sleep(1.5);
        cout << "~> Checkpoints are 80,000 , 25,60,000 and 10,000,000" << endl;sleep(1.5);
        cout << "~> If you give wrong answer , then you will get the amount mentioned in the previous checkpoint" << endl;sleep(1.5);
        cout << "~> At any point of time , you can escape the game and take home the amount that you have won till the moment" << endl;sleep(1.5);
        cout << "~> The game will have five lifelines : " << endl;sleep(1.5);
        cout << " # Flip the question " << endl
             << "# 50 : 50 " << endl
             << "# Expert's Advice " << endl
             << "# Audience poll " << endl
             << "# Feed the Greed " << endl;sleep(1.5);
        cout << "You can flip any question using 'Flip the Question' " << endl;sleep(1.5);
        cout << "You can eliminate two incorrect options using '50:50' " << endl;sleep(1.5);
        cout << "You can get a hint using 'Expert's Advice' " << endl;sleep(1.5);
        cout << "You can consider audience's opinion using 'Audience Poll'" << endl;sleep(1.5);
        cout << "After earning 80,000 , you can use ' Feed the Greed ' to get 1.5 times the money on each question for the next 5 questions but you will get multiple correct choice questions" << endl;sleep(1.5);
        cout << "If any of your multiple correct choice question is incorrect , you will receive just 80,000 and the game will end" << endl;sleep(1.5);
        cout << "But if it partially correct , your prize money will be reduced by half the amount of that questions and you will be shifted in the normal mode" << endl
             << endl;sleep(1.5);}
           static void rules2(){
         

        cout << "IMP RULES FOR EVERY QUESTION:" << endl;sleep(1.5);
        cout << "Remember , Press A,B,C,D to answer the question " << endl;sleep(1.5);
        cout << "Type Lifeline to take a Lifeline" << endl;sleep(1.5);
        cout << "Press Quit to escape the game" << endl;sleep(1.5);
        cout << "Press '!' for flipping the question" << endl;sleep(1.5);
        cout << "Press '%' for 50:50" << endl;sleep(1.5);
        cout << "Press '+' for Expert's Advice " << endl;sleep(1.5);
        cout << "Press '@' for Audience Poll" << endl;sleep(1.5);
        cout << "After winning 80,000 , you can press '&' for feed the greed lifeline" << endl;sleep(1.5);
        cout << "You can use maximum one lifeline per question" << endl;sleep(1.5);


        cout << "HERE WE BEGIN" << endl;sleep(1.5);
    }

       


class Timer{

public:
void display_timer(int seconds){


    Sleep(1000);
    cout << setfill(' ') << setw(55) << "         TIMER         \n";
    cout << setfill(' ') << setw(55) << " --------------------------\n";
    
   while (!_kbhit()) {
        //cout <<setfill(' ') << setw(40)<< seconds << " seconds" << flush<<endl; 
        cout << "\r                                      " << seconds <<" seconds"<<flush;




        Sleep(1000);
        // counter--;

        // sleep(1);
        seconds--;  
         //if any key is pressed then timer stops 
    //but what if seconds hit zero then 
        if(seconds==-1){ 
        throw 505;
        }
    } 
    cout<<endl;  
   
    


}

void display_timer(int min,int sec){

int counter1 = min; 
int counter2 = sec;
    Sleep(1000);
    cout << setfill(' ') << setw(55) << "         TIMER         \n";
    cout << setfill(' ') << setw(55) << " --------------------------\n"; 
    //
    while (!_kbhit()) { 
        cout <<"\r                                      "<< counter1<<":"<< counter2 << "seconds" << flush;
       
       Sleep(1000);
        counter2--;  
        if(counter1==0 && counter2==-1) {throw 505;}
        if(counter2==0 ){
            counter1--;
            counter2=59;
        } 
        
        
       
    } 
    cout<<endl;   
}
    

   
};

void sig_handler(int signum){
 
  printf("Inside handler function\n");
}



int main()
{
    easyque.push_back({{"What was the recent film starring ranveer Singh which focuses on the subject of patriarchy?", " (A) Ramleela ", " (B) Jayeshbhai Jordar ", " (C) 83 ", " (D) Gully Boy "}, "B"});
    easyque.push_back({{"The bollywood actor ayushman khurrana is prominent for providing what in his majority of films? ", " (A) Humour ", " (B) Dance ", " (C) Adult content ", " (D) Social message "}, "D"});
    easyque.push_back({{"Which of these sports requires you to shout out a word loudly during play? ", " (A) Ludo ", " (B) Kho-kho ", " (C) Cricket ", " (D) Chess "}, "B"});
    easyque.push_back({{"Which of these terms can only be used for women?", " (A) Dirghaayu ", " (B) Suhagan ", " (C) Chiranjeevi ", " (D) Vidhvah "}, "B"});
    easyque.push_back({{"Name the oldest mountain range of India", " (A) Himalayas ", " (B) Nilgiris ", " (C) Aravallis ", " (D) Vindhyas "}, "C"});
    easyque.push_back({{"The language of Lakshadweep, a Union Territory of India, is ", " (A) Tamil ", " (B) Hindi ", " (C) Malayalam ", " (D) Telugu "}, "C"});
    easyque.push_back({{"What do you call rice with Coconut? ", " (A) Chaval ", " (B) Masala bhat ", " (C) Nariyal chawal ", " (D) Palak chawal "}, "C"});
    easyque.push_back({{"Which of the following musical instruments is of Indian origin? ", " (A) Flute ", " (B) Sitar ", " (C) violin ", " (D) Tabla "}, "A"});
    easyque.push_back({{"Which of the following Muslim festivals is based on the 'Holy Quran'?  ", " (A) Id -ul-Zuha ", " (B)  Id -ul-Fitr ", " (C) Bakri-id ", " (D) Moharram "}, "A"});
    easyque.push_back({{"What is gulab jamun a type of?", " (A) A flower ", " (B) A fruit ", " (C) A tree ", " (D) A sweet "}, "D"});
    easyque.push_back({{"Among the following actors, which actor is commonly recognised as the 'Angry Young Man' ", " (A) Shahrukh Khan ", " (B) Saif Ali Khan ", " (C) John Abrahim ", " (D) Amitabh bachhan "}, "D"});
    easyque.push_back({{"Which substance is found in milk? ", " (A) Catric Acid ", " (B) Nitric Acid ", " (C) Formic Acid ", " (D) Lactic Acid "}, "D"});
    easyque.push_back({{"In which of the following game can have maximum four players? ", " (A) Chess ", " (B) Kabaddi ", " (C) Ludo ", " (D) Volleyball "}, "C"});
    easyque.push_back({{"Complete this dialogue from the movie : 3 Idiots :_____ tussi great ho, tohfa qubool karo", " (A) Badshah ", " (B) Shahenshah ", " (C) Jahanpanah ", " (D) Maharana "}, "C"});
    easyque.push_back({{"Which bird can turn their head 360 degree? ", " (A) Eagle ", " (B) Owl ", " (C) Pigeon ", " (D) Flamingo "}, "B"});
    easyque.push_back({{"What is the duration of elections for Central Government? ", " (A) 4 ", " (B) 5 ", " (C) 2 ", " (D) 3 "}, "B"});
    easyque.push_back({{"Which protocol use to transmit information on the World Wibe Web? ", " (A) htpp ", " (B) hptt ", " (C) htttp ", " (D) http "}, "D"});

    medque.push_back({{"Which day is observed as World Standards  Day? ", " (A) June 26 ", " (B) Oct 14 ", " (C) Nov 15 ", " (D) Dec 2 "}, "B"});
    medque.push_back({{"The Samadhi of Rajiv Gandhi is known as ", " (A) Vir sthal ", " (B) Vijay Ghat ", " (C) Shakti sthal ", " (D) Vir Bhoomi "}, "D"});
    medque.push_back({{"Who is the only leader to be elected Prime Minister of Pakistan three times?", " (A) Syed Yousaf Raza Gillani ", " (B) Benazir Bhutto ", " (C) Liaqat Ali Khan ", " (D) Nawaz Sharif "}, "D"});
    medque.push_back({{"Who brought the river ganga from heaven to earth?", " (A) Vishnu ", " (B) Brahama ", " (C) Bhagiratha ", " (D) Krishna "}, "C"});
    medque.push_back({{"What is the literal meaning of aasteen in the saying “Aasteen Ka Saanp”?", " (A) Home ", " (B) Business ", " (C) Sleeve ", " (D) Ground "}, "C"});
    medque.push_back({{"What are the two most common ways that a satellite is launched into orbit? ", " (A) Using remote control and riding in the cargo bay of a space shuttle ", " (B) Using remote control and magnetics ", " (C) Riding on a rocket and riding in the cargo bay of a space shuttle ", " (D) Magnetics and riding on a rocket launcher "}, "C"});
    medque.push_back({{"Which Indian batsman was the first to hit 44 fours in a test match innings ", " (A) Tendulkar ", " (B) Gavaskar ", " (C) Ganguly ", " (D) Laxman "}, "D"});
    medque.push_back({{"Who became the first Indian woman to score a hat trick in hockey in Olympic history?", " (A) Rani Rampal ", " (B) Gurjit Kaur ", " (C) Navneet Kaur ", " (D) Vandana Katariya "}, "D"});
    medque.push_back({{"Who co-created the UNIX operating system in 1969 with Dennis Ritchie? ", " (A) Bjarne stroustrup ", " (B) Steve woznaik ", " (C) Ken Thompson ", " (D) Niklaus wirth "}, "C"});
    medque.push_back({{"Who was issued the patent titled 'Improvement in Telegraphy' in 1876?", " (A) Alexander Graham Bell ", " (B) Henri Becquerel ", " (C) Marie curie ", " (D) Robert Bunsen "}, "A"});
    medque.push_back({{"Where did Homi Jehangir Bhaba, the principal architect of India’s nuclear program, die in a plane crash? ", " (A) Monte Rosa ", " (B) Mount Ararat ", " (C) Mount Elbrus ", " (D) Mont Blac "}, "D"});
    medque.push_back({{"With which of the following countries has India signed a Bilateral Investment promotion and Protection Treaty?", " (A)  Germany ", " (B) Japan ", " (C) France ", " (D) Italy "}, "A"});
    medque.push_back({{"Tomorrow is just another day' which famous American novel ends with these sentence? ", " (A) Roots ", " (B) Gone with the wind ", " (C) The Great Gatsby ", " (D) Seeds "}, "B"});
    medque.push_back({{"Which great star received the award of 'The Star of the Millenium' from BBC?", " (A) Dilip Kumar ", " (B) Amitabh Bachan ", " (C) Javed Jaffery ", " (D) Sunny Deol "}, "A"});
    medque.push_back({{"Ellora in Aurangabad (Maharashtra) is famous for ancient caves representing Buddhism, Hinduism and Jainism. Of these, the largest number pertains to ", " (A) Buddhism ", " (B) Hinduism ", " (C) Jainism ", " (D) Zorastrianism "}, "B"});
    medque.push_back({{"Who among these is known as the Adi Kavi of Gujarati Literature?", "(A) Akha Bhagat ", "(B) Gangasati ", "(C) Bhalan ", "(D) Narsih Mehta"}, "D"});
    medque.push_back({{"What was the ame of supercluster of galaxies , discovered by indian astronomers in 2017?", " (A) Saraswati ", " (B) Saptarishi ", " (C) Akash Ganga ", " (D) Brihaspati "}, "A"});
    medque.push_back({{"Biological Oxygen Demand is a standard criterion for which one of the following?", " (A) Measuring oxygen level in blood ", " (B) Computing oxygen levels in forest ecosystems ", " (C) Pollution assay in aquatic ecosystems ", " (D)  Assessing oxygen levels in the high altitude region "}, "C"});
    medque.push_back({{"Which person has done a triple century in test cricket for india? ", " (A) Karun Nayar ", " (B) Virat Kohli ", " (C) Murli Vijay ", " (D) Rohit Sharma "}, "A"});
    medque.push_back({{"Which of these medical conditions is most likely to cause dehydration? ", " (A) Malaria ", " (B) Tetanus ", " (C) Diarrhoea ", " (D) Beriberi "}, "C"});
    medque.push_back({{"Which is the first Indian Movie to cross the margin of 1,000 crore rupees? ", " (A) Bahubali 2: The conclusion ", " (B) KGF 2 ", " (C) Dangal ", " (D) Kick "}, "A"});

    hardque.push_back({{"Against which team did Rohit sharma take the only hat-trick in IPL? ", " (A) Rajasthan Royals ", " (B) Deccan Chargers ", " (C) Chennai Super Kings ", " (D) Royal Challengers Bangalore "}, "B"});
    hardque.push_back({{"The Ochterlony Monument was built in 1848 by Sir David Ochterlony to commemorate his victory in the Nepal War (1814 - 1816). What was it renamed as after India achieved independence?", " (A) Victory Tower ", " (B) Qutub Minar ", " (C) Shaheed Minar ", " (D) Char Minar "}, "C"});
    hardque.push_back({{"In 1850, the first experimental electric telegraph line in india was set up between calcutta and which place?  ", " (A) Diamond harbour ", " (B) Darjeeling ", " (C) Murshidabad ", " (D) Dhaka "}, "A"});
    hardque.push_back({{"Stripped of his heavyweight title in 1967 for refusing induction into the U.S. military, Muhammad Ali regained the heavyweight championship on October 30, 1974, in Kinshasa, Zaire with an eighth-round knockout of which prizefighter?", " (A) George Foreman ", " (B) Joe Frazier ", " (C) Leon Spinks ", " (D) Sputnik"}, "A"});
    hardque.push_back({{"Which of these is the title of a fantasy novel by Devkinandan Khatri? ", " (A) Chandraprabha ", " (B) Chandragupta ", " (C) Chandrakanta ", " (D) chandrabha "}, "C"});
    hardque.push_back({{"This regiment, raised in 1949, was the first all class regiment, made by combining the senior most battalions of four senior most infantry regiments. It is the most elite regiment of the Indian Army. Which regiment am I referring to?", " (A) Brigade of the Guards ", " (B) Mechanized Regiment ", " (C) Jammu Kashmir Light Infantry ", " (D) Punjab Regiment "}, "A"});
    hardque.push_back({{"Out of the following ,who does the constitution allow to participate in parliamentary proceedings?", " (A) Judges ", " Vice President ", " (C) Council of Ministers ", " (D) Attorney General "}, "D"});
    hardque.push_back({{"Which of the countries was the first african country to hire woman president?", " (A) Liberia ", " (B) Nigeria ", " (C) Angola ", " (D) Algeria "}, "A"});
    hardque.push_back({{"Which of these Mughal structures was known by the name 'Rauza-i-Munawwara?'", " (A) Shalimar Bagh ", " (B) Chini Ka Rauza ", " (C) Humayun’s Tomb ", " (D) Taj Mahal "}, "D"});
    hardque.push_back({{"What was the name of all the three soccer clubs set up with the help of Mahatama Gandhi in the early 20th century at Durban, Pretoria and Johannesburg?", " (A) Truth Seekers ", " (B) Non Violents ", " (C) Passive Resisters ", " (D) Non co-operators "}, "C"});
    hardque.push_back({{"Who was born as Mool Shankar in Tankara, Gujrat, worked towards reviving Vedic Ideologies and was the founder of the Arya Samaj?", " (A) Chaitanya Mahaprabhu ", " (B) Dayanand Saraswati ", " (C) Raja Ram Mohan Roy ", " (D) Ramakrishna Paramahamsa "}, "B"});
    hardque.push_back({{"In Greek Mythology, among the 3 Cyclops brothers who forged the signature weapons of the Three Great Gods, who was the oldest?", " (A) Arges ", " (B) Hephaestus ", " (C) Steropes ", "(D) Brontes "}, "D"});

    exhardque.push_back({{"Which of these leaders was a recipient of a gallantry award in 1987 by a state government for saving two girls from drowning? ", " (A) Anandiben Patel ", " (B) Vasundhara Raje Scindia ", " (C) Uma Bharti ", " (D) Mamata Banerjee "}, "A"});
    exhardque.push_back({{"Who was the Indian bowler off whom Australian legend Don Bradman got a single to reach his 100th first class century? ", " (A) Baqa Jilani ", " (B) Commandur Rangachari ", " (C) Gogumal Kishenchand ", " (D) Kanwar Rai Singh "}, "C"});
    exhardque.push_back({{"Which of these is not one of the names of three of Akbar's grandsons when they were briefly converted to Christianity after being handed over to Jesuit priests?", " (A) Don Felipe ", " (B) Don Henrique ", " (C) Don Carlos ", " (D) Don Francisco "}, "D"});
    exhardque.push_back({{"Which of these states has had the most number of its governors become presidents of India?", " (A) Rajasthan ", " (B) Andhra Pradesh ", " (C) Bihar ", " (D) Punjab "}, "C"});

    flipeasy.push_back({{"Who is the current (2022) Prime Minister of India?", " (A)  Narendra Modi ", " (B) Rajiv Gandhi ", " (C) Atal Bihari Vajpayee ", " (D) Javaharlal Nehru "}, "A"});
    flipeasy.push_back({{"Joint Entrance Exam (Main) and (Advanced) are conducted for admissions to which of these courses? ", " (A) Business Management ", " (B) Medicine ", " (C) Engineering ", " (D) Law "}, "C"});

    flipmed.push_back({{"Give the name of situation when batsmen out without playing a single ball in cricket. ", " (A) Duck", " (B) Silaver Duck ", " (C) Golden Duck ", " (D) Diamond Duck "}, "D"});
    flipmed.push_back({{"Which is the highest number of medals are achieved in Olympic session by India?(till 2022) ", " (A) 7 ", " (B) 6 ", " (C) 9 ", " (D) 4 "}, "A"});

    fliphard.push_back({{"Who was the first Indian director of the Indian Institute of Science, Bangalore, the brainchild of Jamshedji Nusserwanji Tata", " (A) Dorabji Tata ", " (B)  CV Raman ", " (C) Homi Jehangir Bhabha ", " (D) Satish Dhawan "}, "B"});
    fliphard.push_back({{"Which of these are names of national parks located in Madhya Pradesh? ", " (A) Krishna and Kanhaiya ", " (B) Kanha and Madhav ", " (C) Ghanshyam and Murari ", " (D) Girdhar and Gopal "}, "B"});

    flipexhard.push_back({{"Writers Building is the headquarters of_________.", " (A) The times of India group ", " (B) All India Writers Association ", " (C) West Bengal Government ", " (D) Press Trust of India "}, "D"});
    flipexhard.push_back({{"Which of the following years was celebrated as the World Communication Year?", " (A) 1981 ", " (B) 1983 ", " (C) 1985 ", " (D) 1987 "}, "B"});
    easy_hints.push_back("HINT : Written and Directed by Divyang Thakkar");
    easy_hints.push_back("HINT : More than Entertainment");
    easy_hints.push_back("HINT : It is a game of Indian Origin");
    easy_hints.push_back("HINT : Women are called so upon marriage");
    easy_hints.push_back("HINT : This mountain range does not obstruct the SW Trade Winds from the Arabian Sea");
    easy_hints.push_back("HINT : It has the same language as its nearest neighbouring state");
    easy_hints.push_back("HINT : Think in Hindi");
    easy_hints.push_back("HINT : It is an icon of an Indian God");
    easy_hints.push_back("HINT : It is also called as Bakr-Id");
    easy_hints.push_back("HINT : Don't go by its name");
    easy_hints.push_back("HINT : He got the nickname from a film by Prakash Mehra released in 1973");
    easy_hints.push_back("HINT : It is also responsible for muscle cramps");
    easy_hints.push_back("HINT : It is an Indoor Sport");
    easy_hints.push_back("HINT : Its not King or Emperor, its Your Highness");
    easy_hints.push_back("HINT : Birds of the Night");
    easy_hints.push_back("HINT : It refers to the length of the normal term of the Prime Minister without re-appointment");
    easy_hints.push_back("HINT : It is an Application Layer Protocol");

    med_hints.push_back(" HINT : Near Gandhi Jayanti");
    med_hints.push_back(" HINT : Land of the Brave");
    med_hints.push_back(" HINT : Pakistan is the opposite of his name");
    med_hints.push_back(" HINT : He was not a god");
    med_hints.push_back(" HINT : Cuff");
    med_hints.push_back(" HINT : Both ways are essentially similar");
    med_hints.push_back(" HINT : His first name was VVS");
    med_hints.push_back(" HINT : Her name resembles a weapon");
    med_hints.push_back(" HINT : His name means Sword/Blade in Japanese");
    med_hints.push_back(" HINT : He was a Scottish-born");
    med_hints.push_back(" HINT : Highest mountain in the Alps");
    med_hints.push_back(" HINT : Deutschland");
    med_hints.push_back(" HINT : Written by Margaret Mitchell");
    med_hints.push_back(" HINT : The First Khan of Bollywood");
    med_hints.push_back(" HINT : Same as the population");
    med_hints.push_back(" HINT : One of the highest awards of Gujarati Literature is named after him");
    med_hints.push_back(" HINT : It is named after a Goddess");
    med_hints.push_back(" HINT : It is not a criteria for Oxygen Levels");
    med_hints.push_back(" HINT : It is not a criteria for Oxygen Levels");
    med_hints.push_back(" HINT : Former India batting Coach");
    med_hints.push_back(" HINT : Caused by viruses or sometimes contaminated food");
    med_hints.push_back(" HINT : A 2017 Blockbuster");

    hard_hints.push_back("HINT : Famous American comic book publisher alongside Marvel Comics");
    hard_hints.push_back("HINT : Victory and Martyrs");
    hard_hints.push_back("HINT : Panna,MP is famous for it");
    hard_hints.push_back("HINT : An American former professional boxer, entrepreneur, minister and author");
    hard_hints.push_back("HINT : Moon-Scales");
    hard_hints.push_back("HINT : Have the Garuda Insignia");
    hard_hints.push_back("HINT : Main legal Advisor to the government");
    hard_hints.push_back("HINT : Synonymous with Free");
    hard_hints.push_back("HINT : Symbol of Love");
    hard_hints.push_back("HINT : The name contains Gandhiji's Ideology of Freedom movement");
    hard_hints.push_back("HINT : Also the founder of Paropkarini Sabha, Ajmer");
    hard_hints.push_back("HINT : His name means 'Thunder'");

    exhard_hints.push_back("HINT : 15th Chief Minister of Gujarat");
    exhard_hints.push_back("HINT : He had at least one duck in every one of the five Tests he played. He was also an occasional leg break bowler.");
    exhard_hints.push_back("HINT : Remember a country");
    exhard_hints.push_back("HINT : Most densely populated Indian State");

    fieldwise_que.push_back({{"Songs like 'Night Changes' , 'What makes you beautiful?' and 'Best Song ever' are the compositions of which if the following Boy Band? ", " (A) BTS ", " (B) BackStreet Boys ", " (C) Jonas Brothers ", " (D) One Direction "}, "D"});
    fieldwise_que.push_back({{"Which of the following movie is a musical romantic drama where a jazz pianist and an actress fall in love and ends with a tragic ending? ", " (A) After we fell ", " (B) La La Land ", " (C) A silent voice", " (D) Jazz in Maze "}, "B"});

    fieldwise_que.push_back({{"Which cricket ground is popularly called Gabba?", " (A) Melbourne Cricket Ground ", " (B)  Brisbane Cricket Ground ", " (C) Adelaide Oval ", " (D) Sydney Cricket Ground "}, "B"});
    fieldwise_que.push_back({{"For her excellence in which sport did Lovlina Borgohain win the Arjuna Award in 2020? ", " (A) Wrestling ", " (B) Boxing ", " (C) WeightLifting ", " (D) Badminton "}, "B"});

    fieldwise_que.push_back({{"How many armed forces personnel were honoured with the Kirti Chakra by the President on May 31, 2022?", " (A) 2 ", " (B) 1 ", " (C) 4 ", " (D) 3 "}, "B"});

    fieldwise_que.push_back({{"Which nation has rejected India’s wheat consignment?", " (A) Hungary ", " (B) Isarel ", " (C) US ", " (D) Turkey "}, "D"});

    fieldwise_que.push_back({{"Most commonly used material in making bulletproof jackets is ", " (A) Formalin ", " (B) Coal-tar ", " (C) Kevlar ", " (D) Fullerene "}, "C"});

    fieldwise_que.push_back({{"Ultrasound waves are NOT used for the following purposes ? ", " (A) To locate its prey by a bat ", " (B) To know the depth of sea bed by a ship ", " (C) To diagnose defeat in internals organs of human body ", " (D) To defeat aero plane in any air space "}, "D"});

    fieldwise_que.push_back({{"Sati (wife of Lord Shiva) is the daughter of ", " (A) Kubera   ", " (B) Daksh Prajapati ", " (C) Himsvsn ", " (D) Lord Brahma "}, "B"});

    fieldwise_que.push_back({{"Buddhism is an offshoot of what other major world religion?", " (A) Christianity   ", " (B) Zoroastrianism ", " (C) Islam ", " (D) Hinduism "}, "B"});

    fieldwise_que.push_back({{"What is the Capital of the Country, Liberia? ", " (A) Freetown ", " (B) Monrovia ", " (C) Conakry ", " (D) Bissau "}, "B"});
    fieldwise_que.push_back({{"The first national park of India was ", " (A) Galathea ", " (B) Guindy ", " (C) Jim Corbett ", " (D) Dudhwa "}, "C"});

    fieldwise_que.push_back({{"Who was the first male musician to appear on the cover of Vogue? ", " (A) Harry Styles ", " (B) Shawn Mendes ", " (C) Zayn ", " (D) Justin Bieber "}, "A"});
    fieldwise_que.push_back({{"What is the slogan of sports brand Nike? ", " (A) Raise the beast inside you ", " (B) Feel the heat  ", " (C) Just Do it ", " (D) Made for the Champions "}, "C"});
    fieldwise_que.push_back({{"The first Indian to receive Nobel Prize in literature was _______.  ", " (A) Mother Teresa ", " (B) C.V. Raman ", " (C) Rabindranath Tagore ", " (D) Sarojini Naidu "}, "C"});
    fieldwise_que.push_back({{"Supportive terms such as ‘oh’ and ‘really’ are called what? ", " (A) BackChanelling", " (B) Supportive terms ", " (C) Emphasising ", " (D) Expressive terms "}, "A"});
    fieldwise_que.push_back({{"Which of the following Sanctuary is famous for the rare gangetic dolphin and also for magar (Crocodile) and Gharial (Aligator)? ", " (A) Gulf of Kutch Marine National Park ", " (B) Mahatma Gandhi Marine National Park ", " (C) Gahirmatha Marine Wildlife Sanctuary ", " (D) National Chambal Sanctuary "}, "D"});
    fieldwise_que.push_back({{"Which of the following National Park is the only existent habitat for the nearly extinct Asiatic Lions in India? ", " (A) Gir National Park ", " (B) Mahatma Gandhi Marine National Park ", " (C) Gahirmatha Marine Wildlife Sanctuary ", " (D) National Chambal Sanctuary "}, "A"});

    vector<string> adv_ans;
    

    advanced_que.push_back({{"How many of the following served as the finance minister of India ?", " (A) Jaswant Singh ", " (B) Arun Jaitley ", " (C) Kamal Nath ", " (D) Nitin Gadkari "}, "AB"});
    advanced_que.push_back({{"Of the following , which are sanctuaries ?", " (A) Kaziranga ", " (B) Sundarbans ", " (C) Nal Sarovar ", " (D) Ranganathittu "}, "CD"});
    advanced_que.push_back({{"Out of following who didn’t serve as Captain of Hockey Team", " (A) Dhyan Chand ", " (B) Virat Kohli ", " (C) Prasun Banerjee ", " (D) Shabbir Ali "}, "AD"});
    advanced_que.push_back({{"Choose the correct option(s) from the following. ", " (A) Teflon is prepared by heating tetrafluoroethane in presence of a persulphate catalyst at high pressure ", " (B) Natural Rubber is polyisoprene containing trans alkene units ", " (C) Cellulose has only alpha D Glucose units that are joined by glycosidic linkages ", " (D) Nylon-6 has amide linkages "}, "BCD"});
    advanced_que.push_back({{"Each employee of a certain company is in either Department X or Department Y, and there are more than twice as many employees in Department X as in Department Y. The average (arithmetic mean) salary is $25,000 for the employees in Department X and $35,000 for the employees in Department Y. Which of the following amounts could be the average salary for all of the employees of the company? ", " (A) $26,000 ", " (B) $28,000 ", " (C) $29,000 ", " (D) $30,000 "}, "AB"});
    advanced_que.push_back({{"Which of the following metals was known during the Indus Valley Civilization ", " (A) Iron ", " (B) Copper ", " (C) Gold ", " (D) Silver "}, "BCD"});
    advanced_que.push_back({{"Which of the following is/are not an example of invertebrate?", " (A) Crabs ", " (B) Worms ", " (C) Fish ", " (D) Frog "}, "CD"});
    advanced_que.push_back({{"Which of the following song(s) has/have been released after 2010?", " (A) Tum Se Hi—Jab We Met ", " (B) Pehli Nazar Mein—Race ", " (C) Na Tum Jaano Na Hum—Kaho Na Pyar Hai ", " (D) Te Amo—Dum Maaro Dum  "}, "D"});
    advanced_que.push_back({{"Which of the following movies are adapted from the books written by Agatha Christie?", " (A) Murder on the Orient Express ", " (B) Girl on the Train ", " (C) Death on the Nile ", " (D) The perks of being a wallflower "}, "AC"});
    advanced_que.push_back({{"Which of the following is/are the avatars of Hindu Lord 'Vishnu'?", " (A) Matsya ", " (B) Varaha ", " (C) Mohini ", " (D) Dhanvantari "}, "ABD"});
   signal(SIGABRT,sig_handler);
    cout << "Welcome to the roller-coaster ride of Kaun Banega Crorepati" << endl
         << endl;
    
    string username;
    string password;

    cout << "Kindly sign up for the game" << endl;

    cout << "Enter username" << endl;
    cin >> username;
    cout << "Set the password" << endl;
    cin >> password;

    User_details ud1(username, password);

    cout << "You have successfully signed up" << endl
         << endl;

    cout << "Login using your credentials" << endl;
    string verify_username;
    string verify_password;
    User_details ud2("","");
    try{
    cout << "Username: ";
    cin >> verify_username;
    cout << "Password: ";
    cin >> verify_password;
    cout << endl;
    
    ud2.User_verified(verify_username,verify_password);
    if(ud1 ^ ud2){
        cout << "You have successfully logged in" << endl;
    }
    else{
        throw 505;
    }
    
    }
    catch(int error_name){
    cout<<"ERROR NO : "<<error_name<<endl;
while (!(ud1^ud2))
    {
        cout<<"WRONG CREDENTIALS"<<endl;

        cout << "Please Login again: " << endl;
        cout << "Username: ";
        cin >> verify_username;
        cout << "Password: ";
        cin >> verify_password;
    }
    cout << endl;
    cout << "You have successfully logged in" << endl;



    }
    

    
     //print rules1 and rules2
      rules1();
     rules2();


    int idx = 0;
    string ans;
    char choose_ll;
    
     Timer t1;
    cout << "Tighten your seat belts because we are about to start " << endl;
    int counteasy = 4;
     int Signal=1;
    while (counteasy != 0)
    {
        //button;
        cout << "Question worth Rs: " << list_amount[idx] << endl;
        idx++;
        Easy_Generator eg1;

        eg1.gen(); 
        try{
        t1.display_timer(30);}
        catch(...){
            cout<<"Your time is over"<<endl;
        cout<<"You have won Rs. "<<curr_amount<<endl;
        cout<<"CONGRATULATIONS!";
        return 0;

        }
        cin >> ans;

        Easy_Evaluator ee1;
        try{
        if (ans=="A" || ans=="B" || ans=="C" || ans=="D")
        {
            //cout << "Enter your answer: " << endl;
            //cin >> ans;
             
            ee1.eval(ans, eg1.idx,Signal);
        }
        else if (ans=="Lifeline")
        {
            Lifeline ll1;
            ll1.Lifeline_or_not();
            cin >> choose_ll;
             
            if (choose_ll == '!')
            {
                lifeline[1] = 1;
                flip_easy fe1;
                fe1.help_the_person(eg1.idx);
                cout<<endl;
                cout << "Enter the answer: ";
                cin >> ans;
                eval_flip_easy efe1;
                efe1.eval(ans, eg1.idx,Signal);
            }
            else if (choose_ll == '%')
            {
                lifeline[0] = 1;
                fifty_fifty ff1;
                ff1.help_the_person(eg1.idx);
                easy_fifty_fifty eff1;
                eff1.help_the_person(eg1.idx);
                cout<<endl;
                cout << "Enter the answer: ";
                cin >> ans;
                ee1.eval(ans, eg1.idx,Signal);
            }
            else if (choose_ll == '+')
            {
                lifeline[2] = 1;
                cout << "[" << easy_hints[eg1.idx] << "]";
                cout<<endl;
                cout << "Enter the answer: ";
                cin >> ans;
                ee1.eval(ans, eg1.idx,Signal);
            }
            else
            {
                lifeline[3] = 1;
                int countA = 0, countB = 0, countC = 0, countD = 0; 

                string realanswer=easyque[eg1.idx].second ; 
                //getting the real answer and giving maximum votes to that
                countA=rand()%67;
                countB=rand()%67;
                countC=rand()%67;
                countD=rand()%67;
                if(realanswer=="A"){countA=67;}
                else if(realanswer=="B"){countB=67;}
                else if(realanswer=="C"){countC=67;}
                else{countD=67;}

                
                

                Audience_Poll ap1(countA, countB, countC, countD);
                ap1.help_the_person(eg1.idx);
                cout << "Enter the answer: ";
                cin >> ans;
                ee1.eval(ans, eg1.idx,Signal);
            }
        }
        else
        {
            cout << "Congratulations , You have won Rs. " << curr_amount<<endl;
            return 0;
        }
        counteasy--;} 
        //if the answer is incorrect then it will throw error and catch will end the game
        catch(...){
        cout<<"Your answer is incorrect"<<endl;
        cout<<"You have lost the game but you have won Rs. "<<curr_amount<<endl;
        cout<<"CONGRATULATIONS!"<<endl;
        return 0;

        }
    }
    //%%%%

    cout << "Question worth Rs: " << list_amount[idx] << endl;
    idx++;
    Medium_Generator mg1;

    mg1.gen();
     //t1.display_timer(1,10); 
     try{
        t1.display_timer(1 , 10);}
        catch(...){
            cout<<"Your time is over"<<endl;
        cout<<"You have won Rs. "<<curr_amount<<endl;
        cout<<"CONGRATULATIONS!";
        return 0;

        }
    cin >> ans;

    Medium_Evaluator me1;
    try{
    if (ans=="A" || ans=="B" || ans=="C" || ans=="D")
    {
       // cout << "Enter your answer: " << endl;
        //cin >> ans;

        me1.eval(ans, mg1.idx,Signal);
    }
    else if (ans=="Lifeline")
    {
        Lifeline ll1;
        ll1.Lifeline_or_not();
        cin >> choose_ll;

        if (choose_ll == '!')
        {
            flip_med fm1;
            fm1.help_the_person(mg1.idx);
            cout<<endl;
            cout << "Enter the answer: ";
            cin >> ans;
            eval_flip_med efm1;
            efm1.eval(ans, mg1.idx,Signal);
        }
        else if (choose_ll == '%')
        {
            fifty_fifty ff1;
            ff1.help_the_person(mg1.idx);
            medium_fifty_fifty mff1;
            mff1.help_the_person(mg1.idx);
            cout<<endl;
            cout << "Enter the answer: ";
            cin >> ans;
            me1.eval(ans, mg1.idx,Signal);
        }
        else if (choose_ll == '+')
        {

            cout << "[" << easy_hints[mg1.idx] << "]";
            cout<<endl;
            cout << "Enter the answer: ";
            cin >> ans;
            me1.eval(ans, mg1.idx,Signal);
        }
        else
        {
            int countA = 0, countB = 0, countC = 0, countD = 0;
            cout << "Enter your votes: " << endl;
            string realanswer=medque[mg1.idx].second ; 
                //getting the real answer and giving maximum votes to that
                countA=rand()%67;
                countB=rand()%67;
                countC=rand()%67;
                countD=rand()%67;
                if(realanswer=="A"){countA=67;}
                else if(realanswer=="B"){countB=67;}
                else if(realanswer=="C"){countC=67;}
                else{countD=67;}

            Audience_Poll ap1(countA, countB, countC, countD);
            ap1.help_the_person(mg1.idx);
            cout << "Enter the answer: ";
                cin >> ans;
                me1.eval(ans, mg1.idx,Signal);
            
        }
    }
    else
    {
        cout << "Congratulations , You have won Rs. " << curr_amount<<endl;
        return 0;
    }}
    catch(...){
        cout<<"Your answer is incorrect"<<endl;
        cout<<"You have lost the game but you have won Rs. "<<curr_amount<<endl;
        cout<<"CONGRATULATIONS!";
        return 0;

        } 
    ////////////////////////////////////
    char adv_choice;
    int countmedium = 4;
    float ans_status = 0;
    cout << "Now you have the chance to win more amount , Press '&' to go to advanced_mode and if you don't want to risk it, Press'-' to stay in normal mode" << endl;
    cin >> adv_choice;
    if (adv_choice == '&')
    {
        feed_the_greed ftg1;
        ftg1.display(); 

        /////// 
        


        /////
         
        while (countmedium != 0)
        {   // 
            
            
            cout << "Question worth Rs: " << advanced_amount[adv_counter] << endl;
            adv_counter++;
            
            advanced_generator ag1;

            ag1.gen();
           //t1.display_timer(1,10); 
           try{
        t1.display_timer(1 , 10);}
        catch(...){
            cout<<"Your time is over"<<endl;
        cout<<"You have won Rs. "<<curr_amount<<endl;
        cout<<"CONGRATULATIONS!";
        return 0;

        }
            cout << "Enter your answer:" << endl;
           cin>>ans;

            advanced_evaluator ae1;
            try{
            ae1.eval(ans, ag1.idx, ans_status,Signal);

            if (ans_status == 0.5)
            {
                countmedium--;
                break;
            }

            countmedium--;
        }

        catch(...){
        cout<<"Your answer is incorrect"<<endl;
        cout<<"You have lost the game but you have won Rs. "<<curr_amount<<endl;
        cout<<"CONGRATULATIONS!"<<endl;
        return 0;}
        

        }
    }
    else
    {
        while (countmedium != 0)
        {
            cout << "Question worth Rs: " << list_amount[idx] << endl;
            idx++;
            Medium_Generator mg1;

            mg1.gen();
  // t1.display_timer(40); 
  try{
        t1.display_timer(40);}
        catch(...){
            cout<<"Your time is over"<<endl;
        cout<<"You have won Rs. "<<curr_amount<<endl;
        cout<<"CONGRATULATIONS!"<<endl;
        return 0;

        }
            cin >> ans;

            Medium_Evaluator me1;
            try{
            if (ans=="A" || ans=="B" || ans=="C" || ans=="D")
            {
                // cout << "Enter your answer: " << endl;
                // cin >> ans;

                me1.eval(ans, mg1.idx,Signal);
            }
            else if (ans=="Lifeline")
            {
                Lifeline ll1;
                ll1.Lifeline_or_not();
                cin >> choose_ll;

                if (choose_ll == '!')
                {
                    flip_med fm1;
                    fm1.help_the_person(mg1.idx);
                    cout<<endl;
                    cout << "Enter the answer: ";
                    cin >> ans;
                    eval_flip_med efm1;
                    efm1.eval(ans, mg1.idx,Signal);
                }
                else if (choose_ll == '%')
                {
                    fifty_fifty ff1;
                    ff1.help_the_person(mg1.idx);
                    medium_fifty_fifty mff1;
                    mff1.help_the_person(mg1.idx);
                    cout<<endl;
                
                    cout << "Enter the answer: ";
                    cin >> ans;
                    me1.eval(ans, mg1.idx,Signal);
                }
                else if (choose_ll == '+')
                {

                    cout << "[" << easy_hints[mg1.idx] << "]";
                    cout<<endl;
                    cout << "Enter the answer: ";
                    cin >> ans;
                    me1.eval(ans, mg1.idx,Signal);
                }
                else
                {
                    int countA = 0, countB = 0, countC = 0, countD = 0;
                    string realanswer=medque[mg1.idx].second ; 
                //getting the real answer and giving maximum votes to that
                countA=rand()%67;
                countB=rand()%67;
                countC=rand()%67;
                countD=rand()%67;
                if(realanswer=="A"){countA=67;}
                else if(realanswer=="B"){countB=67;}
                else if(realanswer=="C"){countC=67;}
                else{countD=67;}


                    Audience_Poll ap1(countA, countB, countC, countD);
                    ap1.help_the_person(mg1.idx);
                    cout << "Enter the answer: ";
                cin >> ans;
                me1.eval(ans, mg1.idx,Signal);
                }
            }
            else
            {
                cout << "Congratulations , You have won Rs. " << curr_amount<<endl;
                return 0;
            }
            countmedium--;
        }
        catch(...){
        cout<<"Your answer is incorrect"<<endl;
        cout<<"You have lost the game but you have won Rs. "<<curr_amount<<endl;
        cout<<"CONGRATULATIONS!"<<endl;
        return 0;}
        
    }} 

    if (ans_status == 0.5)
    { 
        while (countmedium != 0)
        {
            cout<<"....";
            cout << "Question worth Rs: " << list_amount[idx] << endl;
            idx++;
            Medium_Generator mg1;

            mg1.gen();

            cin >> ans;

            Medium_Evaluator me1;
            try{
            if (ans=="A" || ans=="B" || ans=="C" || ans=="D")
            {
                // cout << "Enter your answer: " << endl;
                // cin >> ans;

                me1.eval(ans, mg1.idx,Signal);
            }
            else if (ans=="Lifeline")
            {
                Lifeline ll1;
                ll1.Lifeline_or_not();
                cin >> choose_ll;

                if (choose_ll == '!')
                {
                    flip_med fm1;
                    fm1.help_the_person(mg1.idx);
                    cout<<endl;
                    cout << "Enter the answer: ";
                    cin >> ans;
                    eval_flip_med efm1;
                    efm1.eval(ans, mg1.idx,Signal);
                }
                else if (choose_ll == '%')
                {
                    fifty_fifty ff1;
                    ff1.help_the_person(mg1.idx);
                    medium_fifty_fifty mff1;
                    mff1.help_the_person(mg1.idx);
                    cout<<endl;
                    cout << "Enter the answer: ";
                    cin >> ans;
                    me1.eval(ans, mg1.idx,Signal);
                }
                else if (choose_ll == '+')
                {

                    cout << "[" << easy_hints[mg1.idx] << "]";
                    cout<<endl;
                    cout << "Enter the answer: ";
                    cin >> ans;
                    me1.eval(ans, mg1.idx,Signal);
                }
                else
                {
                    int countA = 0, countB = 0, countC = 0, countD = 0;
                    cout<<endl;
                    string realanswer=medque[mg1.idx].second ; 
                //getting the real answer and giving maximum votes to that
                countA=rand()%67;
                countB=rand()%67;
                countC=rand()%67;
                countD=rand()%67;
                if(realanswer=="A"){countA=67;}
                else if(realanswer=="B"){countB=67;}
                else if(realanswer=="C"){countC=67;}
                else{countD=67;}


                    Audience_Poll ap1(countA, countB, countC, countD);
                    ap1.help_the_person(mg1.idx);
                    cout << "Enter the answer: ";
                cin >> ans;
                me1.eval(ans, mg1.idx,Signal);
                }
            }
            else
            {
                cout << "Congratulations , You have won Rs. " << curr_amount;
                return 0;
            }
            countmedium--;}
            catch(...){
        cout<<"Your answer is incorrect"<<endl;
        cout<<"You have lost the game but you have won Rs. "<<curr_amount<<endl;
        cout<<"CONGRATULATIONS!"<<endl;
        return 0;
        }
    }}

////
cout<<"BONUS QUESTION ALERT!!!"<<endl;
int field_num;


Set_the_field stf1;
stf1.display_fields();
cin>>field_num;
stf1.help_the_person(0,field_num);

cout<<endl;
cout<<"Enter the answer:"<<endl;
cin>>ans;
fieldwise_Evaluator fe1;
fe1.eval(ans,field_num);
















    
    int counthard = 3;
    while (counthard != 0)
    {
        //button;
        cout << "Question worth Rs: " << list_amount[idx] << endl;
        idx++;
        Hard_Generator hg1;

        hg1.gen(); 
        
        cin >> ans;

        Hard_Evaluator he1;
        try{
        if (ans=="A" || ans=="B" || ans=="C" || ans=="D")
        {
            //cout << "Enter your answer: " << endl;
            //cin >> ans;
             
            he1.eval(ans, hg1.idx,Signal);
        }
        else if (ans=="Lifeline")
        {
            Lifeline ll1;
            ll1.Lifeline_or_not();
            cin >> choose_ll;
             
            if (choose_ll == '!')
            {
                lifeline[1] = 1;
                flip_hard fh1;
                fh1.help_the_person(hg1.idx);
                cout<<endl;
                cout << "Enter the answer: ";
                cin >> ans;
                eval_flip_hard efh1;
                efh1.eval(ans, hg1.idx,Signal);
            }
            else if (choose_ll == '%')
            {
                lifeline[0] = 1;
                fifty_fifty ff1;
                ff1.help_the_person(hg1.idx);
                hard_fifty_fifty hff1;
                hff1.help_the_person(hg1.idx);
                cout<<endl;
                cout << "Enter the answer: ";
                cin >> ans;
                he1.eval(ans, hg1.idx,Signal);
            }
            else if (choose_ll == '+')
            {
                lifeline[2] = 1;
                cout << "[" << hard_hints[hg1.idx] << "]";
                cout<<endl;
                cout << "Enter the answer: ";
                cin >> ans;
                he1.eval(ans, hg1.idx,Signal);
            }
            else
            {
                lifeline[3] = 1;
                int countA = 0, countB = 0, countC = 0, countD = 0; 

                string realanswer=easyque[hg1.idx].second ; 
                //getting the real answer and giving maximum votes to that
                countA=rand()%67;
                countB=rand()%67;
                countC=rand()%67;
                countD=rand()%67;
                if(realanswer=="A"){countA=67;}
                else if(realanswer=="B"){countB=67;}
                else if(realanswer=="C"){countC=67;}
                else{countD=67;}

                
                

                Audience_Poll ap1(countA, countB, countC, countD);
                ap1.help_the_person(hg1.idx);
                cout << "Enter the answer: ";
                cin >> ans;
                he1.eval(ans, hg1.idx,Signal);
            }
        }
        else
        {
            cout << "Congratulations , You have won Rs. " << curr_amount<<endl;
            return 0;
        }
        counthard--;} 
        //if the answer is incorrect then it will throw error and catch will end the game
        catch(...){
        cout<<"Your answer is incorrect"<<endl;
        cout<<"You have lost the game but you have won Rs. "<<curr_amount<<endl;
        cout<<"CONGRATULATIONS!"<<endl;
        return 0;

        }
    } 
    ////%% 
    
     cout << "Question worth Rs: " << list_amount[idx] << endl;
        idx++;
        exhard_Generator ehg1;

        
        try{ 
         ehg1.gen(); 
        int click;    
        cout<<"Click 1 to give the answer "<<endl;
        cout<<"Click 2 to take the hint"<<endl;  
        cin>>click;
        exhard_Evaluator ehe1;
        if(click==1) { 
          cout<<"Enter your answer"<<endl;  
        cin >> ans; 
        
            //cout << "Enter your answer: " << endl;
            //cin >> ans;
             
            ehe1.eval(ans, ehg1.idx,Signal);
        }
         
        else{ 
            cout<<exhard_hints[ehg1.idx]<<endl;
            cout<<"Enter your answer"<<endl; 
            cin>>ans;  
            ehe1.eval(ans, ehg1.idx,Signal);




        }  }
         catch(...){
        cout<<"Your answer is incorrect"<<endl;
        cout<<"You have lost the game but you have won Rs. "<<curr_amount<<endl;
        cout<<"CONGRATULATIONS!"<<endl;
        return 0;
}
        
        
        
           
              
        
    

    //%%%%

    
    
    
    
    
    }
