#include<iostream>
#include<unordered_map>
#include<fstream>
#include<ctime>
#include<string>


using namespace std;


class Procedure{
 public:
 string procedureNumber;
 
 unordered_map < string, bool > cottonId ;

//search cotton id in the list 
 bool findCottonId( string cottonIdToAddOrRemove )
 {

  if(cottonId.count( cottonIdToAddOrRemove ) == true)
  {
    return true;
  }
   else 
  {
    return false;
  }

 }
//add new cotton id to the list
 void addCottonId ( string cottonIdToAddOrRemove )
 {
  cottonId[ cottonIdToAddOrRemove ] = true;
 }

//remove cotton id from the list 
 void removeCottonId ( string cottonIdToAddOrRemove ) 
 {

  cottonId[ cottonIdToAddOrRemove ] = false;
  writeData( cottonIdToAddOrRemove,cottonId[ cottonIdToAddOrRemove ]);
  cottonId.erase( cottonIdToAddOrRemove );

 }

//check if the procedure can be ended 
 bool endProcedure ()
 {

  if( cottonId.size() == false )
  {
    return false;
  } else 
  {
    return true;
  }

 }

//to add data too the current output.txt file 
 void writeData( string cottonIdToAddOrRemove , bool state )
 {
  ofstream file( "output.txt" , std::ios::app );

  if( file.is_open() == true )
  {
      file<<cottonIdToAddOrRemove<<"\t"<< state<< endl;
  }
  file.close();
 }


// force write data in case all cottons arent removed 
 void forceWriteData()
 {
 
 for( auto it: cottonId )
 {
  ofstream file( "output.txt" , std::ios::app );

  if( file.is_open()== true )
  {
    file<<it.first<< "\t"<< it.second<<endl;
  }
  file.close();
 }
  getCurrentDateAndTime();

 }

// create a new output.txt file 
 void createFileWithProcedureNumber( string procedureNumber )
 {

 ofstream file("output.txt");
 if( file.is_open() == true ) 
 {
  file<<"PROCEDURE NUMBER: "<<procedureNumber<<endl;
 }
 }

// gerenete current time and date 
void getCurrentDateAndTime()
{
  time_t currentTime;
  time( &currentTime );
  ofstream file( "output.txt",std::ios::app );
  if( file.is_open() == true )
  {
    file << ctime( &currentTime ) <<endl;
  }
  file.close();
}

// create table view 
void createTable()
{
  ofstream file( "output.txt" , std::ios::app );
  if( file.is_open() == true )
  {
    file<<"COTTON-ID"<<"\t"<<"STATE"<<endl;
  }
  file.close();
}


};




int main() {
 
Procedure patient; 

cout<<"Enter the procedure id"<<endl;
// input the procredure number 
cin>>patient.procedureNumber;

patient.createFileWithProcedureNumber( patient.procedureNumber );
patient.getCurrentDateAndTime();
patient.createTable();

// loop runs until a break is forced to end porcedure 
while ( true )
{

string cottonIdToAddOrRemove;
cout<<"-> Enter cotton ID\n-> To end procedure enter 0\n-> To force stop enter -1\t\t Number Of Cotton In Use: "<<patient.cottonId.size()<<endl;
//to input cotton Id
cin>>cottonIdToAddOrRemove;
//ends the procedure if there are no cottons remaining 
if( cottonIdToAddOrRemove == "0" )
{
   if( patient.endProcedure() == true ){
    //as cottons are still present
    continue;
 }
 else 
 {
  patient.getCurrentDateAndTime();
  break;
 }
}
// force stop the procedure no matter how many cottons are there and update it in the output.txt file 
else if(cottonIdToAddOrRemove == "-1")
{
patient.forceWriteData();
  break;
}
// adds cotton id to list if its not present in the list 
else if( patient.findCottonId( cottonIdToAddOrRemove ) == false )
{

  patient.addCottonId( cottonIdToAddOrRemove );

}
// removes cotton from the list if already present  
else if( patient.findCottonId( cottonIdToAddOrRemove ) == true  )
{

patient.removeCottonId( cottonIdToAddOrRemove );

}
} 
return 0;

}
