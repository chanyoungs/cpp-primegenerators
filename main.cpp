#include <iostream>
#include <cmath>

using namespace std;

const int m=99999999;
int primes[m];
int menu=2;


int main()
{
    while(menu==2)
    {
        int currentcount=1;
        int option;
        int userinput;
        int simpler;
        int isprime=1;
        int nthprime;
        menu=1;
        cout << "Type in the the number of the option you wish to do and press [Enter]: \n\n"
        << "1. Print the first n primes \n"
        << "2. Print the primes less than or equal to n \n"
        << "3. Print the nth prime \n"
        << "4. To check whether or not n is prime \n\n";

        for(int error=1; error==1;)
            {
            cin >> option;
            if(option>0 && option<5)
                error=0;
            else
                cout <<"Error: Please type in number between 1 and 4 and press [Enter]:\n\n";
            }

        while(menu==1)
        {

            cout <<endl<< "Type in your desired value of n:\n";
            cin >> userinput;
            cout <<endl;
            simpler=userinput;


            primes[0]=2;

             if(option==3 && userinput==1)
                cout << "The 1st prime is:" << 2;

            else
            {
            if(option!=3 && userinput>=1 && option!=4)
                cout << 2<<endl;

            for(int n=3;(option==1 && currentcount<userinput) || (option==2 && n<=userinput) || option==3 || (option==4 && n<=userinput);n++)
                {

                for(int i=1; i<=currentcount && (option!=4 || n<=userinput); i++)
                    {
                    //cout << n <<" mod "<< primes[i-1] <<" = " << n%primes[i-1] << endl;
                    if(n%primes[i-1]==0)
                        {
                        n++;
                        i=0;
                        }
                    }

                if(option!=3 && option!=4)
                    cout << n <<endl;
                if(option==3 && userinput==currentcount)
                    {
                    cout << "The prime number " << userinput << " is:" << primes[currentcount-1];
                    break;
                    }

                if(option==4 & n>userinput)
                    break;

                primes[currentcount]=n;
                currentcount++;

               /* cout <<"[";
                for(int i=1; i<=currentcount;i++)
                    {
                    cout << primes[i-1];
                    if(i<currentcount)
                        cout << ", ";
                    }
                cout << "]"<<endl; */

                }
            if(option==4)
            {
                if(userinput>2)
                {
                      for(int i=1; primes[i-1]<=simpler;i++)
                    {

                        if(simpler%primes[i-1]==0)
                        {
                            if(isprime!=0)
                            {
                            if(simpler==primes[i-1])
                                break;
                            cout << userinput <<" is not a prime.\nIt can be written as "<<userinput<<"="<<primes[i-1];
                            simpler=simpler/primes[i-1];
                            isprime=0;
                            i=0;
                            }

                            else
                            {
                            cout <<"x"<<primes[i-1];
                            simpler=simpler/primes[i-1];
                            i=0;
                            }
                        }
                    }
                }

                if(isprime==1)

                    {for(int i=1;primes[i-1]<=userinput; i++)
                        {
                            if(userinput==primes[i-1])
                                {
                                nthprime=i;
                                break;
                                }

                        }

                        cout << "Yes, "<<userinput<<" is indeed a prime number.\nIt is in fact, the prime number "<<nthprime<<".\n\n";
                        }


            }
            }
             cout <<endl<<endl<<endl<< "Type in the the number of the option you wish to do and press [Enter]: \n\n"
            << "1. To try again \n"
            << "2. To return to the main menu \n"
            << "3. To quit \n\n";

            for(int error=1; error==1;)
            {
            cin >> menu;
            if(menu>0 && menu<4)
                error=0;
            else
                cout <<"Error: Please type in number between 1 and 3 and press [Enter]:\n\n";
            }
        }
    }
    cout <<"Good bye!";
    return 0;
}
