#include <Logging.h>
/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
 int D1=30;
 int D2=31;
 int D3=32;
 int D4=33;
 int A=34;
 int B=35;
 int C=36;
 int D=37;
 int E=38;
 int F=39;
 int G=40;
 void displayFourAt(int i);
 void clearAll();
 void displayString(String str);
 char intToString(int i);
  
  unsigned long previousMillis=0;
  unsigned long interval=1000;
  
  int increment=0;
  int hours=0;
  int minutes=0;
  int seconds=0;
  char message[50]="1234";
  char characters[50]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  int time[4]={0,0,0,0};
  
  
  char keys[100];
  int * objects[100];
  
  int mode=5;

#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  for (int i=30;i<41;i++){
  pinMode(i, OUTPUT);    
  } 
   if (mode==2){
    time[1]=0; 
    time[2]=9; 
    time[3]=5; 
    time[4]=1; 
   }
   
  //pinMode(2, INPUT);
 
  pinMode(0, OUTPUT);  // data IO
  pinMode(1, OUTPUT);  // data IO
  pinMode(2, OUTPUT);  // data IO
  pinMode(3, OUTPUT);  // data IO
  pinMode(13, OUTPUT);  // onboard led
  pinMode(17, OUTPUT);  // onboard led2
  pinMode(11, OUTPUT);  // Pinned on ICSP of LCD Keypad
  pinMode(12, OUTPUT);  // Pinned on ICSP of LCD Keypad
  pinMode(13, OUTPUT);  // Pinned on ICSP of LCD Keypad
  pinMode(10, OUTPUT); // LCD Keypad Shield BACKlight
  digitalWrite(10, 1);
}

// the loop routine runs over and over again forever:
void loop() {
  
 int adc_key_in = analogRead(0);
 
 if (adc_key_in < 60) {/*
    message[0]='r';
    message[1]='i';
    message[2]='g';
    message[3]='h';
    message[4]='t';
    message[5]=' ';*/
    rightHeld();
  }
  else if (adc_key_in < 200) {/*
    message[0]='U';
    message[1]='p';
    message[2]=' ';
    message[3]=' ';
    message[4]=' ';
    message[5]=' ';*/
    upHeld();
  }
  else if (adc_key_in < 400){
    message[0]='d';
    message[1]='o';
    message[2]='w';
    message[3]='n';
    message[4]=' ';
    message[5]=' ';
    downHeld();
  }
  else if (adc_key_in < 600){/*
    message[0]='L';
    message[1]='e';
    message[2]='f';
    message[3]='t';
    message[4]=' ';
    message[5]=' ';*/
    leftHeld();
  }
  else if (adc_key_in < 800){/*
    message[0]='s';
    message[1]='e';
    message[2]='l';
    message[3]='e';
    message[4]='c';
    message[5]='t';*/
    selectHeld();
  }
  else {
    /*
    message[0]=' ';
    message[1]=' ';
    message[2]=' ';
    message[3]=' ';
    message[4]=' ';
    message[5]=' ';*/
  }
  
  
  unsigned long currentMillis = millis();
 char buffer[2];
  if(currentMillis - previousMillis > interval) {
    if (mode==1){
      drop(message);
    }
    if (mode==2){
    time[4]=time[4]+1;
    if (time[4]>9){
     time[4]=0; 
     time[3]=time[3]+1;
    }
    if (time[3]>5){
     time[3]=0; 
     time[2]=time[2]+1;
    }
    if (time[2]>9){
     time[2]=0; 
     time[1]=time[1]+1;
    }
    
      message[0]=intToString(time[1]);
      message[1]=intToString(time[2]);
      message[2]=intToString(time[3]);
      message[3]=intToString(time[4]);
    }
    if (mode==3){
      drop(message);
    }
    if (mode==5){
      
      
      //displayLEDMapAt(1,search('a'));
      
      //message[0]=intToString(search('!'));
  
    
    //message[0]='!';
  }
    
    previousMillis=currentMillis;
  }
 

 
  displayString(message);
}

void clearAll(){
  for (int i=30;i<=40;i++){
    
  pinMode(i, OUTPUT); 
  digitalWrite(i, 1); 
  }
}


int  * search(char chr){
 for (int i=0;i<50;i++){
    if (keys[i]==chr){
      //message[0]=intToString(i);
      //message[1]=keys[i];
      message[i]=intToString((objects[1])[0]);
      //return objects[i];
    } 
 }
}

int * LEDMapDataFor(char chr){
  /*if (search(chr)){
   return search(chr); 
  }*/
  if (chr=='0'){
    static int data[7]={ 0, 0, 0, 0, 0, 0, 1};
    return data;
  }
  else if (chr=='1'){
    static int data[7]={ 1, 0, 0, 1, 1, 1, 1};
    return data;
  }
  else if (chr=='2'){
    static int data[7]={ 0, 0, 1, 0, 0, 1, 0};
    return data;
  }
  else if (chr=='3'){
    static int data[7]={ 0, 0, 0, 0, 1, 1, 0};
    return data;
  }
  else if (chr=='4'){
    static int data[7]={ 1, 0, 0, 1, 1, 0, 0};
    return data;
  }
  else if (chr=='5'){
    static int data[7]={ 0, 1, 0, 0, 1, 0, 0};
    return data;
  }
  else if (chr=='6'){
    static int data[7]={ 0, 1, 0, 0, 0, 0, 0};
    return data;
  }
  else if (chr=='7'){
    static int data[7]={ 0, 0, 0, 1, 1, 1, 1};
    return data;
  }
  else if (chr=='8'){
    static int data[7]={ 0, 0, 0, 0, 0, 0, 0};
    return data;
  }
  else if (chr=='9'){
    static int data[7]={ 0, 0, 0, 1, 1, 0, 0};
    return data;
  }
  else if (chr=='a'||chr=='A'){
    static int data[7]={ 0, 0, 0, 1, 0, 0, 0};
    return data;
  }
  else if (chr=='b'){
    static int data[7]={ 1, 1, 0, 0, 0, 0, 0};
    return data;
  }
  else if (chr=='B'){
    static int data[7]={ 0, 0, 0, 0, 0, 0, 0};
    return data;
  }
  else if (chr=='c'){
    static int data[7]={ 1, 1, 1, 0, 0, 1, 0};
    return data;
  }
  else if (chr=='C'){
    static int data[7]={ 0, 1, 1, 0, 0, 0, 1};
    return data;
  }
  else if (chr=='d'){
    static int data[7]={ 1, 0, 0, 0, 0, 1, 0};
    return data;
  }
  else if (chr=='D'){
    static int data[7]={ 0, 0, 0, 0, 0, 0, 1};
    return data;
  }
  else if (chr=='e'){
    static int data[7]={ 0, 0, 1, 0, 0, 0, 0};
    return data;
  }
  else if (chr=='E'){
    static int data[7]={ 0, 1, 1, 0, 0, 0, 0};
    return data;
  }
  else if (chr=='f'||chr=='F'){
    static int data[7]={ 0, 1, 1, 1, 0, 0, 0};
    return data;
  }
  else if (chr=='f'||chr=='F'){
    static int data[7]={ 0, 1, 1, 1, 0, 0, 0};
    return data;
  }
  else if (chr=='g'){
    static int data[7]={ 0, 0, 0, 0, 1, 0, 0};
    return data;
  }
  else if (chr=='G'){
    static int data[7]={ 0, 1, 0, 0, 0, 0, 1};
    return data;
  }
  else if (chr=='h'){
    static int data[7]={ 1, 1, 0, 1, 0, 0, 0};
    return data;
  }
  else if (chr=='H'){
    static int data[7]={ 1, 0, 0, 1, 0, 0, 0};
    return data;
  }
  else if (chr=='i'||chr=='I'){
    static int data[7]={ 1, 1, 1, 1, 0, 0, 1};
    return data;
  }
  else if (chr=='j'||chr=='J'){
    static int data[7]={ 1, 0, 0, 0, 0, 1, 1};
    return data;
  }
  else if (chr=='k'||chr=='K'){
    static int data[7]={ 1, 0, 0, 1, 0, 0, 0};
    return data;
  }
  else if (chr=='l'){
    static int data[7]={ 1, 1, 1, 1, 0, 0, 1};
    return data;
  }
  else if (chr=='L'){
    static int data[7]={ 1, 1, 1, 0, 0, 0, 1};
    return data;
  }
  else if (chr=='m'||chr=='M'||chr=='n'||chr=='N'){
    static int data[7]={ 1, 1, 0, 1, 0, 1, 0};
    return data;
  }
  else if (chr=='o'){
    static int data[7]={ 1, 1, 0, 0, 0, 1, 0};
    return data;
  }
  else if (chr=='O'){
    static int data[7]={ 0, 0, 0, 0, 0, 0, 1};
    return data;
  }
  else if (chr=='p'||chr=='P'){
    static int data[7]={ 0, 0, 1, 1, 0, 0, 0};
    return data;
  }
  else if (chr=='q'||chr=='Q'){
    static int data[7]={ 0, 0, 0, 1, 1, 0, 0};
    return data;
  }
  else if (chr=='r'){
    static int data[7]={ 1, 1, 1, 1, 0, 1, 0};
    return data;
  }
  else if (chr=='R'){
    static int data[7]={ 0, 0, 0, 1, 0, 0, 0};
    return data;
  }
  else if (chr=='s'||chr=='S'){
    static int data[7]={ 0, 1, 0, 0, 1, 0, 0};
    return data;
  }
  else if (chr=='t'){
    static int data[7]={ 1, 1, 1, 1, 0, 0, 0};
    return data;
  }
  else if (chr=='T'){
    static int data[7]={ 0, 1, 1, 1, 0, 0, 1};
    return data;
  }
  else if (chr=='u'){
    static int data[7]={ 1, 1, 0, 0, 0, 1, 1};
    return data;
  }
  else if (chr=='U'){
    static int data[7]={ 1, 0, 0, 0, 0, 0, 1};
    return data;
  }
  else if (chr=='v'){
    static int data[7]={ 1, 1, 0, 0, 0, 1, 1};
    return data;
  }
  else if (chr=='V'){
    static int data[7]={ 1, 0, 0, 0, 0, 0, 1};
    return data;
  }
  else if (chr=='w'||chr=='W'){
    static int data[14]={ 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1};
    return data;
  }
  else if (chr=='x'||chr=='X'){
    static int data[7]={ 1, 0, 0, 1, 0, 0, 0};
    return data;
  }
  else if (chr=='y'||chr=='Y'){
    static int data[7]={ 1, 0, 0, 1, 1, 0, 0};
    return data;
  }
  else if (chr=='z'||chr=='Z'){
    static int data[7]={ 0, 0, 1, 0, 0, 1, 0};
    return data;
  }
  else if (chr==' '){
    static int data[7]={ 1, 1, 1, 0, 1, 1, 1};
    return data;
  }
  static int data[7]={ 1, 1, 1, 1, 1, 1, 1};
  return data;
}

void displayString(String str){
  displayLEDMapAt(1,LEDMapDataFor(str[0]));
  displayLEDMapAt(2,LEDMapDataFor(str[1]));
  displayLEDMapAt(3,LEDMapDataFor(str[2]));
  displayLEDMapAt(4,LEDMapDataFor(str[3]));
}

void displayChars(char chrs[]){
  
  displayLEDMapAt(1,LEDMapDataFor(chrs[0]));
  displayLEDMapAt(2,LEDMapDataFor(chrs[1]));
  displayLEDMapAt(3,LEDMapDataFor(chrs[2]));
  displayLEDMapAt(4,LEDMapDataFor(chrs[3]));
}

 void displayLEDMapAt(int i, int charLEDMap[]){
  clearAll();
   i--;
  if (i>=0&&i<=3){
    digitalWrite(D1+i, 0); 
  for (int x=0;x<7;x++){
  digitalWrite(A+x, charLEDMap[x]); 
  }
  }
  /*
  if (charLEDMap[8]){
  clearAll();
  if (i>=0&&i<=3){
    digitalWrite(D1+i+1, 0); 
  for (int b=7;b<14;b++){
  digitalWrite(A+b-7, charLEDMap[b]); 
  }
  }
  }*/
  clearAll();
}

char intToString(int i){
  //if (i>=0&&i<=9){
    if (i==0){ return '0';}
    if (i==1){ return '1';}
    if (i==2){ return '2';}
    if (i==3){ return '3';}
    if (i==4){ return '4';}
    if (i==5){ return '5';}
    if (i==6){ return '6';}
    if (i==7){ return '7';}
    if (i==8){ return '8';}
    if (i==9){ return '9';}
  //}
  return NULL;
}

void drop(char *chrs){
  for (int i=0;i<50;i++){
    chrs[i]=chrs[i+1];
  }
}

void rightDown(){
  
}

void rightHeld(){
  
}

void rightReleased(){
  
}


void leftDown(){
  
}

void leftHeld(){
  
}

void leftReleased(){
  
}


void upDown(){
  
}

void upHeld(){
  mode=1;
  message[0]='0';
  message[1]='1';
  message[2]='2';
  message[3]='3';
  message[4]='4';
  message[5]='5';
  message[6]='6';
  message[7]='7';
  message[8]='8';
  message[9]='9';
  message[10]='A';
  message[11]='B';
  message[12]='C';
  message[13]='D';
  message[14]='E';
  message[15]='F';
  message[16]='G';
  message[17]='H';
  message[18]='I';
  message[19]='J';
  message[20]='K';
  message[21]='L';
  message[22]='M';
  message[23]='N';
  message[24]='O';
  message[25]='P';
  message[26]='Q';
  message[27]='R';
  message[28]='S';
  message[29]='T';
  message[30]='U';
  message[31]='V';
  message[32]='W';
  message[33]='X';
  message[34]='Y';
  message[35]='Z';
  //message='0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ             ';
}

void upReleased(){
  
}


void downDown(){
  
}

void downHeld(){
    mode=2;
    time[1]=0; 
    time[2]=9; 
    time[3]=5; 
    time[4]=1; 
}

void downReleased(){
  
}


void selectDown(){
  
}

void selectHeld(){
  
}

void selectReleased(){
  
}


int * intArray(int a,int b,int c,int d,int e,int f,int g){
    static int data[7]={ a, b, c, d, e, f, g};
    return data;
}
