#include <iostream>
#include <string>
#include <cmath>
using namespace std;


bool inputCheck(int x){
     
    if (x < 0){
        return true;
    }
    else{
        return false;
    }
}



bool getInput(string  useType, int & useMin, int & useSMS, int & useINT,
               int & aMin, int & aSMS, int & aINT) {
 
    cout<<"Please enter how many minutes you used this month "<<useType<<": ";
    cin>>useMin;
    if (inputCheck(useMin)){
    
        cout<<"Number of minutes cannot be smaller than 0."<<endl;
        return false;
    }
    
    cout<<"Please enter how many SMSs you sent this month "<<useType<<": ";
    cin>>useSMS;
    if (inputCheck(useSMS)){
        cout<<"Number of SMSs cannot be smaller than 0."<<endl;
        return false;
    }
    
    cout<<"Please enter how many MBs you used this month "<<useType<<": ";
    cin>>useINT;
    if (inputCheck(useINT)){
        cout<<"Number of MBs cannot be smaller than 0."<<endl;
        return false;
    }
    
    cout<<"Please specify how many additional packages you bought for calls, SMS and internet in this order: ";
    cin>>aMin>>aSMS>>aINT;
    
    if (inputCheck(aMin)){
        cout<<"Number of additional minutes packages cannot be smaller than 0."<<endl;
        return false;
        
    }
    if (inputCheck(aSMS)){
        cout<<"Number of additional SMS packages cannot be smaller than 0."<<endl;
        return false;
        
    }
    if (inputCheck(aINT)){
        cout<<"Number of additional internet packages cannot be smaller than 0."<<endl;
        return false;
        
    }
    return true;
    
}

double costCalculations(int  usedMins, int  usedSMS, int  usedInternet,
                        int  boughtMIN, int boughtSMS, int  boughtInternet,
                        int  singlePack, int  packMIN, int  packSMS, int  packINT,
                        int  priceAdd, int  addMin, int  addSms, int  addInt,
                        int  rateMin, int  rateSMS, int  rateInt){
    double costt;
    
    int allowMin, allowSMS, allowInternet ;
    int totalcost, extraMin, extraSMS, extraInternet;
    double exPM = 0, exPS = 0, exPI = 0;
    
    allowMin = packMIN + (boughtMIN * addMin);
    allowSMS = packSMS + (boughtSMS * addSms);
    allowInternet = packINT + (boughtInternet * addInt);
    
    totalcost = singlePack + priceAdd*(boughtMIN+boughtSMS+boughtInternet);
    
   
    
    extraMin = usedMins - allowMin;
    
    if (allowMin <= usedMins){
        
        exPM = extraMin * rateMin;
        
    }
    extraSMS = usedSMS - allowSMS;
    if (allowSMS <= usedSMS){
       
        exPS = extraSMS * rateSMS;
        
    }
    extraInternet = usedInternet - allowInternet;
    if (allowInternet <= usedInternet){
       
        exPI = extraInternet * ((1024.0/100.0)*rateInt);
       
    }
    
    costt = totalcost + exPM + exPS + exPI;
    
    return costt;
}

void displayResults(int singlePack, string useType, int totalCost){
    
    if (singlePack >= totalCost){
        
        cout<<"Total cost of your phone usage "<<useType<<" is "<<totalCost<<" TL."<<" You did not exceed your package."<<endl;
        
    }else if ((singlePack * 2)>= totalCost){
        
        cout<<"Total cost of your phone usage "<<useType<<" is "<<totalCost<<" TL."<<" You exceeded your package."<<endl;
        
    }
    else{
        
        cout<<"Total cost of your phone usage "<<useType<<" is "<<totalCost<<" TL."<<" You exceeded your package too much. We suggest you to change your package."<<endl;
        
    }
}
int main() {
    int minutes = 0, sms = 0, internet = 0 , useMin = 0 , useSMSs = 0 , useInternet = 0 ;
    
    int singlePack = 120, packMins = 250, packSMS = 1000, packINT = 5*1024,
        priceAdd = 30, addMin = 250, addSMS = 250, addINT = 1024;
    double rateMin = 2, rateSMS = 1, rateINT = 2;
    string useType = "in Turkey";
    
    int minutes2 = 0, sms2 = 0, internet2 = 0 , useMin2 = 0 , useSMSs2 = 0 , useInternet2 = 0 ;
    
    int singlePack2 = 300, packMins2 = 100, packSMS2 = 200, packINT2 = 2*1024,
    priceAdd2 = 100, addMin2 = 50, addSMS2 = 100, addINT2 = 1024;
    double rateMin2 = 15, rateSMS2 = 3, rateINT2 = 5;
    
    string useType2 = "Internationally";
   
    
    if (getInput(useType, minutes, sms, internet, useMin, useSMSs, useInternet)){
        double x;
       x = costCalculations(minutes, sms, internet, useMin, useSMSs, useInternet, singlePack,
                               packMins, packSMS, packINT, priceAdd, addMin, addSMS, addINT,
                               rateMin, rateSMS, rateINT);
        displayResults(singlePack, useType, x);
        
    }else{
        return 0;
    }
    if (getInput(useType2, minutes2, sms2, internet2, useMin2, useSMSs2, useInternet2)){
        
        double y;
        y = costCalculations(minutes2, sms2, internet2, useMin2, useSMSs2, useInternet2, singlePack2, packMins2, packSMS2, packINT2, priceAdd2, addMin2, addSMS2, addINT2,
            rateMin2, rateSMS2, rateINT2);
        displayResults(singlePack2, useType2, y);
    }
    else{
        return 0;
    }
    
    return 0;
}
