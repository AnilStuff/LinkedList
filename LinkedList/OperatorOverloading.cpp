//
//  OperatorOverloading.cpp
//  LinkedList
//
//  Created by Anil Kothari on 16/02/17.
//  Copyright © 2017 Anil Kothari. All rights reserved.
//

//#include <iostream>
//using namespace std;

class Location{
    float Longitude;
    float Latitude;
public:
    Location(){Latitude = 0; Longitude = 0;}

    Location(float lat,float longi){Latitude = lat; Longitude = longi;}
    void setLatitude(float lat){Latitude = lat;}
    void setLongitude(float longi){Longitude = longi;}
    
    float getLatitude(){return Latitude;}
    float getLongitude(){return Longitude;}
    
    Location operator+(Location L2);
};

Location Location::operator+(Location L2){
    Location temp;
    float longi = temp.getLongitude() + L2.getLongitude();
    float lati = temp.getLatitude() + L2.getLatitude();
    temp.setLatitude(lati);
    temp.setLongitude(longi);
    return temp;
}


/*
int main(int argc, const char * argv[]){
    
    Location L1 = Location(28.3, 54.2);
    Location L2 = Location(10.1, 1.2);
    
    Location L3 = L1 + L2;
    
    cout<<"Added Location Longitude"<<L3.getLongitude()<<endl;
    
    cout<<"Added Location Latitude"<<L3.getLatitude()<<endl;
    
    return 0;
}
*/
