#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

const int totchan=7;
void main()
{
 int number;        //the computer's random number
 int guess;         //the user's guess
 int chances=0,score=0,chanscor;        //chanscor stores score for 1 successful chance.
 char ans;
 do
 {
	clrscr();
	chances=score=0;

	cout<<"#############################################\n";
	cout<<"#\n";
	cout<<"# Welcome to the Alto-Basso.\n";
	cout<<"# I will pick a random number from 0 to 100.\n";
	cout<<"# You must try to guess the number.\n";
	cout<<"#\n";
	cout<<"#############################################\n";

	randomize();
	number=(int)(rand()%10);      //random number stored in mumber
	chanscor=100/totchan;        //score for each successful chance

	do
	{
	  cout<<"\nWhat is your guess? (0 to 100) ";
	  cin>>guess;
	  if((guess<0)||(guess>100))
	  {
			cout<<"Sorry, but your guess "<<guess<<" must be from 0 to 100.";    //Invalid number
	  }
	  else if(guess < number)
	  {
		  cout<<guess<<" is low. Try a higher number.";      //Number is low
	  }
	  else if(guess > number)
	  {
		  cout<<guess<<" is high. Try a lower number.";      //Number is high
	  }
	  else		//if correct number is guessed
	  {			//number is correct, and the "do" loop will end below
	cout<<guess<<" is correct. Congratulations!";
	score=chanscor*(totchan-chances);   //score calculated with number of chances left
	cout<<"\n\nYour score is "<<score<<endl;
		  break;
	  }
	  chances++;
	  if(guess!=number)
	 cout<<"Now you have "<<totchan-chances<<" chances left."<<endl;     //Chances left
	  if(chances==totchan)
	 { cout<<"Only "<<totchan<<" chances are allowed. Better luck next time.";
		cout<<" The actual number was "<<number<<".\n";                   //Reveal number
		break;
	 }
	  }while (guess!=number);

	  cout<<"\nThank you for playing Alto-Basso!";
	  cout<<"\nWant to play again? (y/n)...";
	  cin>>ans;
	}while(ans=='y' || ans=='Y');
 }