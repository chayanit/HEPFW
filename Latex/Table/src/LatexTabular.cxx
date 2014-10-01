#include "Latex/Table/interface/LatexTabular.h"

#include <iostream>

using namespace std;

/********************************************//**
 * Constructor for this class
 * @param nRow number of rows for this tabular.
 * @param nCol number of columns for this tabular.
 ***********************************************/
hepfw::LatexTabular::LatexTabular(int nRow,int nCol){
  
  init();
  
  if(nRow<1 || nCol<1){cout << "ERROR: tabular size needs to be bigger than 1 in columns or rows!" << endl;}
  
  for(int a=0; a<nRow; a++){
    m_rows           .push_back(hepfw::LatexTabularRow(nCol));
    m_rowsDecoration .push_back("");
  }
  m_rowsDecoration.push_back("");
  
  for(int b=0; b<nCol; b++){     
    m_columnAlignment .push_back("c");
    m_columnDecoration.push_back(""); 
  }
  m_columnDecoration.push_back("");  
  
  
}

void hepfw::LatexTabular::init(){
  
  m_name = "tabular";
  
}

void hepfw::LatexTabular::setCellContent(int iRow,int iCol,bool value){
  
  if(isCoordinateValid(iRow,iCol)){
    ((m_rows[iRow])[iCol]).setCellContent(value);
  }else{
    cout << "ERROR: Request tabular position is out of bounds." << endl;
  }
}

void hepfw::LatexTabular::setCellContent(int iRow,int iCol,int value){
  
  if(isCoordinateValid(iRow,iCol)){
    ((m_rows[iRow])[iCol]).setCellContent(value);
  }else{
    cout << "ERROR: Request tabular position is out of bounds." << endl;
  }
}

void hepfw::LatexTabular::setCellContent(int iRow,int iCol,unsigned value){
  
  if(isCoordinateValid(iRow,iCol)){
    ((m_rows[iRow])[iCol]).setCellContent(value);
  }else{
    cout << "ERROR: Request tabular position is out of bounds." << endl;
  }
}

void hepfw::LatexTabular::setCellContent(int iRow,int iCol,float value){
  
  if(isCoordinateValid(iRow,iCol)){
    ((m_rows[iRow])[iCol]).setCellContent(value);
  }else{
    cout << "ERROR: Request tabular position is out of bounds." << endl;
  }
}

void hepfw::LatexTabular::setCellContent(int iRow,int iCol,double value){
  
  if(isCoordinateValid(iRow,iCol)){
    ((m_rows[iRow])[iCol]).setCellContent(value);
  }else{
    cout << "ERROR: Request tabular position is out of bounds." << endl;
  }
}

void hepfw::LatexTabular::setCellContent(int iRow,int iCol,const char* value){

  if(isCoordinateValid(iRow,iCol)){
    ((m_rows[iRow])[iCol]).setCellContent(string(value));
  }else{
    cout << "ERROR: Request tabular position is out of bounds." << endl;
  }  
}

void hepfw::LatexTabular::setCellContent(int iRow,int iCol,string value){

  if(isCoordinateValid(iRow,iCol)){
    ((m_rows[iRow])[iCol]).setCellContent(value);
  }else{
    cout << "ERROR: Request tabular position is out of bounds." << endl;
  }
}

void hepfw::LatexTabular::setCellPrecision(int iRow,int iCol,std::string value){

  if(isCoordinateValid(iRow,iCol)){
    ((m_rows[iRow])[iCol]).setCellPrecision(value);
  }else{
    cout << "ERROR: Request tabular position is out of bounds." << endl;
  }  
}

void hepfw::LatexTabular::setCellColor(int iRow,int iCol,string value){
  
  if(isCoordinateValid(iRow,iCol)){
    ((m_rows[iRow])[iCol]).setCellColor(value);
    addRequiredPackage("xcolor");
  }else{
    cout << "ERROR: Request tabular position is out of bounds." << endl;
  }
}

void hepfw::LatexTabular::setColumnDecorationBefore(int iCol,std::string value){
  
  if(iCol<0 || iCol>=int(m_rows[0].size())){
    cout << "ERROR: Request column position is out of bounds." << endl;
  }else{
    m_columnDecoration[iCol]=value;
  }
}

void hepfw::LatexTabular::setColumnDecorationAfter (int iCol,std::string value){
  
  if(iCol<0 || iCol>=int(m_rows[0].size())){
    cout << "ERROR: Request column position is out of bounds." << endl;
  }else{
    m_columnDecoration[iCol+1]=value;
  }
}

void hepfw::LatexTabular::setRowDecorationBefore(int iRow,std::string value){
  
  if(iRow<0 || iRow>=int(m_rows.size())){
    cout << "ERROR: Request row position is out of bounds." << endl;
  }else{
    m_rowsDecoration[iRow]=value;
  }
}

void hepfw::LatexTabular::setRowDecorationAfter (int iRow,std::string value){
  
  if(iRow<0 || iRow>=int(m_rows.size())){  
    cout << "ERROR: Request row position is out of bounds." << endl;
  }else{
    m_rowsDecoration[iRow+1]=value;
  }
}

void hepfw::LatexTabular::setTabularColumnDecoration(std::string value){

 setColumnDecorationBefore(0,value);
  for(int iCol=0; iCol<int(m_rows[0].size()); iCol++){
    setColumnDecorationAfter(iCol,value);
  }  
}

void hepfw::LatexTabular::setTabularRowDecoration(std::string value){
  
  setRowDecorationBefore(0,value);
  for(int iRow=0; iRow<int(m_rows.size()); iRow++){      
    setRowDecorationAfter(iRow,value);
  }
}

void hepfw::LatexTabular::setTabularPrecision(std::string value){
 
  for(int iRow=0; iRow<int(m_rows.size()); iRow++){      
    for(int iCol=0; iCol<int(m_rows[0].size()); iCol++){
      ((m_rows[iRow])[iCol]).setCellPrecision(value);      
    }  
  }
}

string hepfw::LatexTabular::toStringEnvBegin(){

  string out = getRequiredPackagesString();
  out += "\n";

  // Beginning environment
  out += "\\begin{"+m_name+"}";

  // Adding position options
  if(m_position != ""){
    out += "["+m_position+"]";
  }

  // Adding column aligment and decoration
  out += "{";
  for(unsigned i=0; i<m_columnAlignment.size(); i++){
    out += m_columnDecoration[i];
    out += m_columnAlignment[i];
    if(i==m_columnAlignment.size()-1){
      out += m_columnDecoration[i+1];  
    }
  }
  out += "}";

  out += "\n";

  // Adding centering options
  if(m_centering){out += "\\centering\n";}

  return out;
  
}

string hepfw::LatexTabular::toStringEnvInner(){

  string out = "";  

  for(unsigned i=0; i<m_rows.size(); i++){
    if(m_rowsDecoration[i]!=""){
      out += m_rowsDecoration[i]+"\n";  
    }
    out += m_rows[i].toString();
  }

  if(m_rowsDecoration[m_rows.size()]!=""){
    out += m_rowsDecoration[m_rows.size()]+"\n";
  }

  return out;  
}

bool hepfw::LatexTabular::isCoordinateValid(int iRow,int iCol){
  
  bool out = true;
  
  if(iCol<0 || iCol>=int(m_rows[0].size())){out=false;}
  if(iRow<0 || iRow>=int(m_rows   .size())){out=false;}

  return out;
}
