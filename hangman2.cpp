#include<iostream>
#include <cstdlib>
#include<vector>
#include<fstream>
#include<string>
#include<time.h>
using namespace std;

void prntMsg(string msg,bool prnTop= true, bool prnBottom=true)
{
    if(prnTop)
    {
        cout<<"+-------------------------------------+"<<endl;
        cout<<"|";
    }
    else
        cout<<"|";
    bool front=true;
    for(int i=msg.length();i<38;i++)
    {
        if(front) // if front =true
            msg=" "+msg;
         else
            msg=msg+" "; 
        front=!front; // to alternate front to t&f
    } 
    cout<<msg;// msg.c_str() ends with null-character but will also work
    if(prnBottom)
    {
        cout<<"|"<<endl;
        cout<<"+-------------------------------------+"<<endl;
    }
    else
        cout<<"|";
}
void drawHM(int cguess=0)
{
    if(cguess>=1)
        prntMsg("|",false, false);
    else
        prntMsg(" ",false,false);
    
    cout<<endl;
     
     if(cguess>=2)
        prntMsg("|",false, false);
    else
        prntMsg(" ",false,false);
    
    cout<<endl;
     
     if(cguess>=3)
        prntMsg("O",false, false);
    else
        prntMsg(" ",false,false);

    cout<<endl;
     
     if(cguess==4)
        prntMsg("/",false, false);
    if(cguess==5)
        prntMsg("/|",false, false);
    if(cguess>=6)
        prntMsg("/|\\",false, false); // "\" is an escape character
    else
        prntMsg(" ",false,false);
    
    cout<<endl;

    if(cguess==7)
        prntMsg("/",false, false);
    if(cguess>=8)
        prntMsg("/ \\",false, false); 
    else
        prntMsg(" ",false,false);
    cout<<endl;
    //prntMsg("+-----------------+",false, false);
    //cout<<endl;
}

void letters(string input,char from, char to)
{
    string s="";
    for(char i=from;i<=to;i++)
    {
        if(input.find(i)==string::npos)//if the given letter is not in the string
        {
            s+=i;
            s+=" ";
        }
        else
            s+="  ";
    }
    prntMsg(s,false,false);
}
void availLetters(string taken)
{
    prntMsg("AVAILABLE LETTERS");
    letters(taken,'A','M');
    cout<<endl;
    letters(taken,'N','Z');
}
bool check(string word, string gd) //gd=guessed
// this function will return true ya false if the guess is right or wrong
{
    bool won=true;
    string s="";
    for(int i=0;i<word.length();i++)
    {
        if(gd.find(word[i])==string::npos)
        {
            won=false;
            s=s+"_ ";
        }
        else
        {
            s+=word[i];
            s+=" ";
        }
    }
    prntMsg(s,false);
    return won;
}
string randWord()
{
    string word;
    string months[] =
	{
		"ALEXENDER",
        "DIGAMBER",
        "VERONICA",
        "ANUSHI",
        "NAVYA"
	};
	
	srand(time(NULL));
	int n=rand()% 5 ;
	word=months[n];

  return word;  
}
int triesLeft(string word, string guessed)
{
    int error=0;
    for(int i=0;i<guessed.length();i++)
    {
        if(word.find(guessed[i])==string::npos)
            error++;
    }
    return error;
}
int main()
{
    srand(time(0));

    string g; //gussess
    string wordGuess;

    wordGuess=randWord();
    int tries=0;
    bool win=false;
    while (tries<9)
    {
        system("cls");
        prntMsg("HANG MAN");
        drawHM(tries);
        availLetters(g);
        cout<<endl;
        prntMsg("GUESS THE WORD");
        win=check(wordGuess,g);

        if(win==true)
            break;
        char x;
       cout<<">" ; cin>>x;
       if(g.find(x)==string::npos)
                   g+=x;
    
    tries= triesLeft(wordGuess,g);
    }

    if(win) // win==true
        prntMsg("YOU WON!");
    else
        prntMsg("GAME OVER");
    system("pause");
    return 0;
}