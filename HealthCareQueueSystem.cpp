//Elliot Chauke
//Health care queue system

#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <sstream>
#include <iomanip>
using namespace std;

//structure called patient is defined
struct patient
{
    string speciality;//stores speciality for a patient Wound,Adult or Children
    int arrivalTime;// Time the patient arrives
    int processingTime;//The time it takes for a will be with a speciality

};



int main()
{
    patient newPatient;//Create patient object

    string line;//String variable to store each line from the input file
    int simulationTime=23;//The maximum simulation time which change be adjusted
    string ptime;//String variable to store processing time from the input file
    string timeCount;//String variable to store time count from the input file
    string spec;//String variable to store speciality from the input file

    queue<patient>WoundQueue;//Wound speciality queue
    queue<patient>AdultQueue;//Adult speciality queue
    queue<patient>ChildrenQueue;//Children speciality queue
    queue<patient>timeArrive;//arrival time queue


    ifstream inputFile("c:\data\dataclient.txt");//open input file
//if statement to check when the file opened successfully
    if(!inputFile)
    {
        cout<<"file did not open try again"<<endl;//error message to display when the file did not opne
    }

  //While loop to read each line from input file
while(getline(inputFile,line))
    {

      stringstream ss(line);//create a stream string for each line to extract data
      getline(ss,timeCount,',');//extract time count from the input file line
      newPatient.arrivalTime=stoi(timeCount);//convert time count string into int and store it into structure vriable


      getline(ss,spec,',');//extract speciality from the input file line
      newPatient.speciality=spec;//store it into structure vriable

      getline(ss,ptime,',');//extract processing time from the input file line
      newPatient.processingTime=stoi(ptime);//convert time count string into int and store it into structure vriable

     //if and else if statements to push new patient based on speciality into their corresponding queue
      if(newPatient.speciality =="W")
      {
          WoundQueue.push(newPatient);
      }
      else if(newPatient.speciality=="A")
      {
          AdultQueue.push(newPatient);
      }
      else if(newPatient.speciality=="C")
      {
          ChildrenQueue.push(newPatient);
      }

    }
inputFile.close();//close the input file

cout<<"Time Count \t|"<<"\tWound\t\t|"<<"\tAdult\t\t|"<<"\tChildren"<<endl;//Display the header

int Count=0;//initialize the count for simulation time

//loop until the end of simulation time
while(Count<simulationTime)
{

    cout<<Count;//Display the current count of the simulation time

    //Process the Wound Queue
    //if statement to check if the queue is not empty and the patient arrived at a certain time
if(!WoundQueue.empty() && WoundQueue.front().arrivalTime <= Count)
{
    cout<<"\t\t|\t1("<<WoundQueue.front().processingTime<<")";//display the processing time
    WoundQueue.front().processingTime--;//decrement the processing time
    //if statement to check the processing time has completed
    if(WoundQueue.front().processingTime==0)
    {
        WoundQueue.pop();//remove the patient
    }

}
else
    {
    cout<<"\t\t|\t0" ;//display 0 when the is no patient in the queue
    }

     //Process the Adult Queue
    //if statement to check if the queue is not empty and the patient arrived at a certain time
if(!AdultQueue.empty() && AdultQueue.front().arrivalTime <= Count)
{
    cout<<"\t\t|\t1("<<AdultQueue.front().processingTime<<")";//display the processing time
    AdultQueue.front().processingTime--;//decrement the processing time
    //if statement to check the processing time has completed
    if(AdultQueue.front().processingTime==0)
    {
        AdultQueue.pop();//remove the patient
    }

}
else
    {
    cout<<"\t\t|\t0";//display 0 when the is no patient in the queue
    }

     //Process the Adult Queue
    //if statement to check if the queue is not empty and the patient arrived at a certain time
if(!ChildrenQueue.empty() && ChildrenQueue.front().arrivalTime <= Count)
{
    cout<<"\t\t|\t1("<<ChildrenQueue.front().processingTime<<")";//display the processing time
    ChildrenQueue.front().processingTime--;//decrement the processing time
    //if statement to check the processing time has completed
    if(ChildrenQueue.front().processingTime==0)
    {
        ChildrenQueue.pop();//remove the patient
    }

}
else
    {
    cout<<"\t\t|\t0";//display 0 when the is no patient in the queue
    }
cout<<endl;
 Count++;//increment the count of the simulation
}

return 0;
}
