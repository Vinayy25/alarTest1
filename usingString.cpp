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

 void addCottonId ( string cottonIdToAddOrRemove )
 {
  cottonId[ cottonIdToAddOrRemove ] = true;
 }

 void removeCottonId ( string cottonIdToAddOrRemove ) 
 {

  cottonId[ cottonIdToAddOrRemove ] = false;
  writeData( cottonIdToAddOrRemove,cottonId[ cottonIdToAddOrRemove ]);
  cottonId.erase( cottonIdToAddOrRemove );

 }

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

 void writeData( string cottonIdToAddOrRemove , bool state )
 {
  ofstream file( "output.txt" , std::ios::app );

  if( file.is_open() == true )
  {
      file<<cottonIdToAddOrRemove<<"\t"<< state<< endl;
  }
  file.close();
 }

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

 void createFileWithProcedureNumber( string procedureNumber )
 {

 ofstream file("output.txt");
 if( file.is_open() == true ) 
 {
  file<<"PROCEDURE NUMBER: "<<procedureNumber<<endl;
 }
 }

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
cin>>patient.procedureNumber;

patient.createFileWithProcedureNumber( patient.procedureNumber );
patient.getCurrentDateAndTime();
patient.createTable();
while ( true )
{

string cottonIdToAddOrRemove;
cout<<"-> Enter cotton ID\n-> To end procedure enter 0\n-> To force stop enter -1\t\t Number Of Cotton In Use: "<<patient.cottonId.size()<<endl;
cin>>cottonIdToAddOrRemove;

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
else if(cottonIdToAddOrRemove == "-1")
{
patient.forceWriteData();
  break;
}
else if( patient.findCottonId( cottonIdToAddOrRemove ) == false )
{

  patient.addCottonId( cottonIdToAddOrRemove );

}
else if(patient.findCottonId( cottonIdToAddOrRemove ) == true)
{

patient.removeCottonId( cottonIdToAddOrRemove );

}
} 
return 0;

}
