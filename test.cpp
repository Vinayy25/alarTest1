#include<iostream>
#include<unordered_map>
#include<fstream>
#include<ctime>

using namespace std;


class Procedure{
 public:
 int procedureNumber;
 
 unordered_map<int, bool> cottonId;


 bool findCottonId( int tempCottonId ){

  if(cottonId.count(tempCottonId) == true)
  {
    return true;
  }
   else 
  {
    return false;
  }

 }

 void addCottonId ( int tempcottonId ){
  cottonId[tempcottonId] = true;
 }

 void removeCottonId ( int tempCottonId ) {

  cottonId[tempCottonId]=false;
  writeData(tempCottonId,cottonId[tempCottonId]);
  cottonId.erase( tempCottonId );

 }

 bool endProcedure(){

  if(cottonId.size()==false){
     
    return false;
    
  }else{
    return true;
  }

 }

 void writeData(int tempCottonId, int state){
  ofstream file("output.txt",std::ios::app);

  if(file.is_open()== true){

      file<<tempCottonId<<"\t"<< state<< endl;

  }
  file.close();
 }

 void forceWriteData(){
 
 for(auto it: cottonId){
  ofstream file("output.txt",std::ios::app);
  if(file.is_open()== true){
    file<<it.first<< "\t"<< it.second<<endl;
  }
  getCurrentDateAndTime();
  file.close();
 }

 }

 void createFileWithProcedureNumber(int procedureNumber){

 ofstream file("output.txt");
 if(file.is_open()==true){
  file<<"PROCEDURE NUMBER: "<<procedureNumber<<endl;
 }
 }

void getCurrentDateAndTime(){
  time_t currentTime;
  time(&currentTime);
  ofstream file("output.txt",std::ios::app);
  if(file.is_open()==true){
    file<<ctime(&currentTime)<<endl;
  }
  file.close();
}
void createTable(){
  ofstream file("output.txt",std::ios::app);
  if(file.is_open()==true){
    file<<"COTTON-ID"<<"\t"<<"STATE"<<endl;
  }
  file.close();
}


};



int main() {
 
Procedure patient; 

cout<<"Enter the procedure id"<<endl;
cin>>patient.procedureNumber;

patient.createFileWithProcedureNumber(patient.procedureNumber);
patient.getCurrentDateAndTime();
patient.createTable();
while (true) {

int tempCottonId;
cout<<"-> Enter cotton ID // \n-> To end procedure enter 0\n-> To force stop enter -1\n ";
cin>>tempCottonId;

if(tempCottonId==0){
   if( patient.endProcedure() == true ){
    //as cottons are still presenT
    continue;
 }
 else {
  patient.getCurrentDateAndTime();
  break;
 }
}else if(tempCottonId == -1){
patient.forceWriteData();

  break;
}
else if( patient.findCottonId( tempCottonId ) == false ){

  patient.addCottonId( tempCottonId );

}else if(patient.findCottonId( tempCottonId ) == true){

patient.removeCottonId( tempCottonId );

}


}
return 0;

}
