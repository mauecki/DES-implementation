#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

void HexToBin (string input, int outputArr[]){
    string sReturn = "";
    for (int i = 0; i < input.length(); ++i){
        switch (input [i]){
        case '0':
            sReturn.append ("0000");
            break;
        case '1':
            sReturn.append ("0001");
            break;
        case '2':
            sReturn.append ("0010");
            break;
        case '3':
            sReturn.append ("0011");
            break;
        case '4':
            sReturn.append ("0100");
            break;
        case '5':
            sReturn.append ("0101");
            break;
        case '6':
            sReturn.append ("0110");
            break;
        case '7':
            sReturn.append ("0111");
            break;
        case '8':
            sReturn.append ("1000");
            break;
        case '9':
            sReturn.append ("1001");
            break;
        case 'a':
        case 'A':
            sReturn.append ("1010");
            break;
        case 'b':
        case 'B':
            sReturn.append ("1011");
            break;
        case 'c':
        case 'C':
            sReturn.append ("1100");
            break;
        case 'd':
        case 'D':
            sReturn.append ("1101");
            break;
        case 'e':
        case 'E':
            sReturn.append ("1110");
            break;
        case 'f':
        case 'F':
            sReturn.append ("1111");
            break;
        }
    }

    for(int i=0; i<64; i++){
        if(i<(input.length()*4)){
            char tmp=sReturn[i];
            outputArr[i]=tmp-'0';
        }
        else{
            outputArr[i]=0;
        }
    }

}


string GetHexFromBin(string sBinary){
    string rest,tmp,chr = "";
    int len = sBinary.length()/4;
    chr = chr.substr(0,len);
    sBinary = chr+sBinary;
    for (int i=0; i<sBinary.length(); i+=4){
        tmp = sBinary.substr(i,4);
        if (!tmp.compare("0000")){
            rest = rest + "0";
        }
        else if (!tmp.compare("0001")){
            rest = rest + "1";
        }
        else if (!tmp.compare("0010")){
            rest = rest + "2";
        }
        else if (!tmp.compare("0011")){
            rest = rest + "3";
        }
        else if (!tmp.compare("0100")){
            rest = rest + "4";
        }
        else if (!tmp.compare("0101")){
            rest = rest + "5";
        }
        else if (!tmp.compare("0110")){
            rest = rest + "6";
        }
        else if (!tmp.compare("0111")){
            rest = rest + "7";
        }
        else if (!tmp.compare("1000")){
            rest = rest + "8";
        }
        else if (!tmp.compare("1001")){
            rest = rest + "9";
        }
        else if (!tmp.compare("1010")){
            rest = rest + "A";
        }
        else if (!tmp.compare("1011")){
            rest = rest + "B";
        }
        else if (!tmp.compare("1100")){
            rest = rest + "C";
        }
        else if (!tmp.compare("1101")){
            rest = rest + "D";
        }
        else if (!tmp.compare("1110")){
            rest = rest + "E";
        }
        else if (!tmp.compare("1111")){
            rest = rest + "F";
        }
        else{
            continue;
        }
    }
    return rest;
}


void DecToBin(int tabDec[], const int sizeDec, int tabBin[]){
    int is=0;
    for(int i=0; i<sizeDec; i++){
        int tempDec = tabDec[i];
        unsigned int mask = 0b10000000;
        while(mask > 0){
            if((tempDec & mask) == 0){
                tabBin[is]=0;
            }
            else{
                tabBin[is]=1;
            }
            mask = mask>>1;
            is++;
        }
    }
    if(is<64){
        for(int i=is; i<64; i++){
            tabBin[i]=0;
        }
    }
}

string DecTo4Bit(int value){
    unsigned int mask = 0b1000;
    string binary = "";
    while(mask > 0){
        if((value & mask) == 0 ){
            binary=binary+"0";
        }
        else{
            binary=binary+"1";
        }
        mask = mask >> 1 ;
    }
    return binary;
}

void leftRotate(int arr[], int d, int size){
    for (int i = 0; i < d; i++){
        int temp = arr[0];
        for (int i = 0; i < size - 1; i++){
            arr[i] = arr[i + 1];
        }
        arr[size-1] = temp;
    }
}

void f_xor(int a[], int b[],int size){
    for(int i=0; i<size; i++){
        a[i]= a[i] ^ b[i];
    }
}

string int_array_to_string(int int_array[], int size_of_array){
    ostringstream oss("");
    for (int temp = 0; temp < size_of_array; temp++)
        oss << int_array[temp];
    return oss.str();
}

void initialPerm(int arr[]){
    int IP[]= {58, 50, 42, 34, 26, 18, 10, 2,
               60, 52, 44, 36, 28, 20, 12, 4,
               62, 54, 46, 38, 30, 22, 14, 6,
               64, 56, 48, 40, 32, 24, 16, 8,
               57, 49, 41, 33, 25, 17, 9,  1,
               59, 51, 43, 35, 27, 19, 11, 3,
               61, 53, 45, 37, 29, 21, 13, 5,
               63, 55, 47, 39, 31, 23, 15, 7
              };

    int afterPerm[64];

    for(int i=0; i<64; i++){
        afterPerm[i]=arr[IP[i]-1];
    }

    for(int i=0; i<64; i++){
        arr[i]=afterPerm[i];
    }
}

void finalPerm(int left[], int right[], int arr[]){

    int il=0;
    int ip=0;

    for(int i=0; i<64; i++){
        if(i<32){
            arr[i]=left[il];
            il++;
        }
        else{
            arr[i]=right[ip];
            ip++;
        }
    }


    int P_1[64] ={
        40,8,48,16,56,24,64,32,
        39,7,47,15,55,23,63,31,
        38,6,46,14,54,22,62,30,
        37,5,45,13,53,21,61,29,
        36,4,44,12,52,20,60,28,
        35,3,43,11,51,19,59,27,
        34,2,42,10,50,18,58,26,
        33,1,41,9,49,17,57,25
    };

    int afterPerm[64];

    for(int i=0; i<64; i++){
        afterPerm[i]=arr[P_1[i]-1];
    }
    for(int i=0; i<64; i++){
        arr[i]=afterPerm[i];
    }

}

void permutationP(int arr[]){
    int afterPermP[32];

    int P[32] ={
        16,7,20,21,
        29,12,28,17,
        1,15,23,26,
        5,18,31,10,
        2,8,24,14,
        32,27,3,9,
        19,13,30,6,
        22,11,4,25
    };

    for(int i=0; i<32; i++){
        afterPermP[i]=arr[P[i]-1];
    }

    for(int i=0; i<32; i++){
        arr[i]=afterPermP[i];
    }
}

void expansion(int arr[], int expansioned[]){
    int Expansion[] ={
        32,1,2,3,4,5,
        4,5,6,7,8,9,
        8,9,10,11,12,13,
        12,13,14,15,16,17,
        16,17,18,19,20,21,
        20,21,22,23,24,25,
        24,25,26,27,28,29,
        28,29,30,31,32,1
    };

    for(int i=0; i<48; i++){
        expansioned[i]= arr[Expansion[i]-1];
    }
}

void pc1(int arr[], int outputPC1[]){
    int pc_1[56] = {  57,49,41,33,25,17,9,
                      1,58,50,42,34,26,18,
                      10,2,59,51,43,35,27,
                      19,11,3,60,52,44,36,
                      63,55,47,39,31,23,15,
                      7,62,54,46,38,30,22,
                      14,6,61,53,45,37,29,
                      21,13,5,28,20,12,4
                   };


    for(int i=0; i<56; i++){
        outputPC1[i]=arr[pc_1[i]-1];
    }
}

void pc2(int leftKey[], int rightKey[], int outputPC2[]){
    int pc_2[48] ={
        14,17,11,24,1,5,
        3,28,15,6,21,10,
        23,19,12,4,26,8,
        16,7,27,20,13,2,
        41,52,31,37,47,55,
        30,40,51,45,33,48,
        44,49,39,56,34,53,
        46,42,50,36,29,32
    };

    int temp[56];

    int il=0;
    int ip=0;
    for(int i=0; i<56; i++){
        if(i<(28)){
            temp[i]=leftKey[il];
            il++;
        }
        else{
            temp[i]= rightKey[ip];
            ip++;
        }
    }

    for(int i=0; i<48; i++){
        outputPC2[i]=temp[pc_2[i]-1];
    }
}

void division(int arr[], int left[], int right[], int size){
    int il=0;
    int ip=0;
    for(int i=0; i<size; i++){
        if(i<(size/2)){
            left[il] = arr[i];
            il++;
        }
        else{
            right[ip] = arr[i];
            ip++;
        }
    }
}

void rotating(int leftKey[], int rightKey[],int round){
    if(round == 1 or round == 2 or round == 9 or round == 16){
        leftRotate( leftKey,  1,  28);
        leftRotate( rightKey,  1,  28);
    }
    else{
        leftRotate( leftKey,  2,  28);
        leftRotate( rightKey, 2,  28);
    }
}

void keySchedule(int leftKey[], int rightKey[], int round, int FinalKey[]){

    rotating(leftKey, rightKey, round);

    pc2(leftKey, rightKey, FinalKey);
}


void s_boxes(int arr[], int output[]){
    int sbox[8][4][16] ={
        {
            {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
            {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
            {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
            {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
        },
        {
            {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
            {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
            {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
            {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
        },
        {
            {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
            {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
            {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
            {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
        },
        {
            {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
            {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
            {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
            {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
        },
        {
            {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
            {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
            {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
            {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
        },
        {
            {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
            {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
            {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
            {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
        },
        {
            {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
            {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
            {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
            {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
        },
        {
            {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
            {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
            {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
            {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
        }
    };

    string input = int_array_to_string(arr, 48);
    string coordinates[8][2];
    int int_coordinates[8][2];

    int j=0;
    for(int i=0; i<8; i++){
        coordinates[i][0] = {input[j], input[j+5]};
        coordinates[i][1] = {input[j+1], input[j+2], input[j+3], input[j+4] };
        j=j+6;
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<2; j++){
            int_coordinates[i][j]= stoi(coordinates[i][j], 0, 2);
        }
    }

    string sbxResult="";
    for(int i=0; i<8; i++){
        string singleSbx= DecTo4Bit(sbox[i][int_coordinates[i][0]][int_coordinates[i][1]]);
        sbxResult = sbxResult+singleSbx;
    }

    for(int i=0; i<32; i++){
        output[i]=sbxResult[i]-'0';
    }
}


void feistel(int prawa[], int AfterKey[], int feistelOutput[]){

    int expArray[48];

    expansion(prawa, expArray);

    f_xor(expArray, AfterKey, 48);

    s_boxes(expArray, feistelOutput);

    permutationP(feistelOutput);

}

string des(int arrayBin[], int key[]){

    initialPerm(arrayBin);

    int left[32];
    int right[32];
    int schldKey[56];
    int leftKey[28];
    int rightKey[28];
    int encryptedArray[64];

    division(arrayBin, left, right, 64);
    pc1(key, schldKey);
    division(schldKey, leftKey, rightKey, 56);

    for(int i=1; i<17; i++){

        int feistel_output[32];

        keySchedule(leftKey,rightKey, i, schldKey);
        feistel(right, schldKey, feistel_output);
        f_xor(left, feistel_output, 32);
        swap(left,right);

    }

    swap(left,right);
    finalPerm(left, right, encryptedArray);

    string encryptedWord=int_array_to_string(encryptedArray, 64);
    return encryptedWord;
}

string hexCheck(){
    bool checkChar;
    bool checkLength;
    string hexa;
    do{
        checkChar = true;
        checkLength = true;
        cout<<"Ciag znakow w systemie szesnastkowym: ";
        cin >> hexa;

        if((hexa.length()%2)!=0){
            checkLength = false;
            cout<<"Wprowadzona liczba znakow w systemie szesnastkowym musi byc parzysta."<<endl;
        }


        for( int i=0; i<hexa.length(); i++){
            if((!isdigit(hexa[i]))  and hexa[i]!='a' and hexa[i]!='b' and hexa[i]!='c' and hexa[i]!='d' and hexa[i]!='e' and hexa[i]!='f'
               and hexa[i]!='A' and hexa[i]!='B' and hexa[i]!='C' and hexa[i]!='D' and hexa[i]!='E' and hexa[i]!='F')
                checkChar = false;
        }
        if(!checkChar){
            cout<<"Wpisano niepoprawna wartosc szesnastkowa. Prosze wprowadzic ponownie."<<endl;
        }
    }
    while(!checkChar or !checkLength);
    return hexa;
}


int inputOption(){
    bool checkInt;
    string number;
    do{
        cout<<"Wybor: ";
        checkInt = true;
        cin >> number;
        if(number.length()>1){
            checkInt = false;
        }

        for( int i=0; i<number.length(); i++){
            if(number[i]!='1' and number[i]!='2')
                checkInt = false;
        }
        if(!checkInt){
            cout<<"Wprowadzono nieprawidlowa wartosc."<<endl;
        }
    } while(!checkInt);

    int ret = stoi(number);
    return ret;
}

int main(){
    string Key;
    string word;
    int wordOption;
    int keyOption;
    string system;
    int key[64];

    cout<<"System tekstu jawnego: "<<endl;
    cout<<"1 - tekst zwykly (plaintext)"<<endl;
    cout<<"2 - szesnastkowo (hexadecimal)"<<endl;

    wordOption=inputOption();
    switch (wordOption){
    case 1: {
        cout<<"Tekst jawny: ";
        cin >> word;
        system ="plaintext";

        break;
    }
    case 2: {
        word = hexCheck();
        system ="hex";

        break;
    }
    }


    cout<<endl<<endl<<"Wybor systemu klucza: "<<endl;
    cout<<"1 - tekst zwykly (plaintext)"<<endl;
    cout<<"2 - szesnastkowo (hexadecimal)"<<endl;

    keyOption=inputOption();
    switch (keyOption){
    case 1:{
        cout<<"Tekst jawny: ";
        cin>>Key;
        while(Key.length()>8){
        cout<<"Tekst jawny: ";
        cin>>Key;
        }

        int keyLength = Key.length();
        int *keyDec;
        keyDec=new int[keyLength];

        for(int i=0; i<keyLength; i++){
            keyDec[i]=Key[i];
        }

        DecToBin(keyDec, keyLength, key);
        break;
    }
    case 2:{
        Key  = hexCheck();
        while(Key.length()>16){
            Key  = hexCheck();
        }
        HexToBin(Key, key);

        break;
    }
    }


    int arrayBin[64];
    double inputLength=word.length();
    double turns;

    if(system=="plaintext"){
        turns=(ceil(inputLength/8));
    }
    if(system=="hex"){
        turns=(ceil(inputLength/16));
    }

    string output="";
    for(int i=0; i<turns; i++){
    if(system=="plaintext"){
        string ret1 = word.substr(i*8,8);
        int retLength = ret1.length();
        int *arrayDec;
        arrayDec=new int [retLength];

        for(int i=0; i<retLength; i++){
            arrayDec[i]=ret1[i];
        }

        DecToBin(arrayDec, retLength, arrayBin);
        }

        if(system == "hex"){
        string ret1 = word.substr(i*16,16);
        HexToBin (ret1, arrayBin);


        }

        output = output+des(arrayBin, key);
    }



    cout<<endl<<endl<<"Zaszyfrowane slowo w systemie binarnym: "<<output;
    cout<<endl<<"Zaszyfrowane slowo w systemie szesnastkowym: "<<GetHexFromBin(output)<<endl<<endl;





    return 0;
}
