#include<iostream>
#include<unordered_map>
#include<fstream>

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
  ofstream file("output.txt");

  if(file.is_open()== true){

      file<<tempCottonId<<" "<< state<< endl;

  }
  file.close();
 }

 void forceWriteData(){
  
 for(auto it: cottonId){
  ofstream file("output.txt");
  if(file.is_open()== true){
    file<<it.first<< " "<< it.second<<endl;
  }
  file.close();
 }

 }

};

int main() {
 
Procedure patient; 

cout<<"Enter the procedure id"<<endl;
cin>>patient.procedureNumber;



while (true) {

cout<<"Enter cotton ID // \n-> To end procedure enter 0\n-> To force stop enter -1 ";
int tempCottonId;
cin>>tempCottonId;


if( patient.findCottonId( tempCottonId ) == false ){

  patient.addCottonId( tempCottonId );

}else if(patient.findCottonId( tempCottonId ) == true){

patient.removeCottonId( tempCottonId );

}else if(tempCottonId == 0){
 
 if( patient.endProcedure() == true ){
    //as cottons are still present
    continue;
 }
 else {
  break;
 }
}
else if( tempCottonId == -1 ){
  patient.forceWriteData();
  break;
}
return 0;

}

}
