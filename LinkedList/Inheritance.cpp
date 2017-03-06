//
//  Inheritance.cpp
//  LinkedList
//
//  Created by Anil Kothari on 04/03/17.
//  Copyright © 2017 Anil Kothari. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Person{
protected:
    string firstName;
    string lastName;
    int id;
public:
    Person(string firstName, string lastName, int identification){
        this->firstName = firstName;
        this->lastName = lastName;
        this->id = identification;
    }
    void printPerson(){
        cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n";
    }
    
};


class Student :  public Person{
private:
    vector<int> testScores;
public:
    /*
     *   Class Constructor
     *
     *   Parameters:
     *   firstName - A string denoting the Person's first name.
     *   lastName - A string denoting the Person's last name.
     *   id - An integer denoting the Person's ID number.
     *   scores - An array of integers denoting the Person's test scores.
     */
    
    Student(string firstName, string lastName, int identification, vector<int> scores):Person(firstName, lastName,  identification), testScores(scores) {};

    char calculate(){
        float sum = 0;
        for (auto &value : testScores) {
            sum += value;
        }
        
        sum = sum / testScores.size();
        
        if (sum >=40 && sum <55){
            return 'D';
        }else if (sum >=55 && sum <70){
            return 'P';
        }else if (sum >=70 && sum <80){
            return 'A';
        }else if (sum >=80 && sum <90){
            return 'E';
        }else if (sum >=90 && sum <=100){
            return 'O';
        }else{
            return 'T';
        }
    }
};



//practice c++ coding
//HackerRank
int calculateSum() {
    string firstName;
    string lastName;
    int id;
    int numScores;
    cin >> firstName >> lastName >> id >> numScores;
    vector<int> scores;
    for(int i = 0; i < numScores; i++){
        int tmpScore;
        cin >> tmpScore;
        scores.push_back(tmpScore);
    }
    Student* s = new Student(firstName, lastName, id, scores);
    s->printPerson();
    cout << "Grade: " << s->calculate() << "\n";
    return 0;
}





//6716-the-time-in-words-English
//HackerRank
string getStringValue(int n){
    string array[31] = {"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","quarter","sixteen","seventeen","eighteen","nineteen","twenty","twenty one","twenty two","twenty three","twenty four","twenty five","twenty six","twenty seven","twenty eight","twenty nine","half"};
    
    return array[n];
}

int entryOfTimeToWord(){
    // Get hour value
    int h;
    cin >> h;
    
    // Get minutes value
    int m ;
    cin >> m;

    // if minutes is greater than 30 increase value
    bool nextHourTime = false;

    // Get the string value of the hour and minutes
    string hourValue;
    string minutesValue;
    
    if (m > 30){
        nextHourTime = true;
        h++;
        m = 60 - m;
    }
    
    hourValue = getStringValue(h);
    minutesValue = getStringValue(m);
    
    if (m == 0) {
        cout<<hourValue<<" o’ Clock";
    }else if (m==1 && nextHourTime == false){
        cout<<minutesValue<<" minute past "<<hourValue;
    }else if (m==15 || m==30){
        if (nextHourTime) {
            cout<<minutesValue<<" to "<<hourValue;
        }else{
            cout<<minutesValue<<" past "<<hourValue;
        }
    }
    else {
        if (nextHourTime) {
            if (m==1) {
                cout<<minutesValue<<" minute to "<<hourValue;
            }else{
                cout<<minutesValue<<" minutes to "<<hourValue;
            }
        }else{
            if (m==1) {
                cout<<minutesValue<<" minute past "<<hourValue;
            }else{
                cout<<minutesValue<<" minutes past "<<hourValue;
            }
        }
    }
    
    return 0;
}


int mainThirteen(){

    string s = "aba";
    //cin >> s;
    string t = "aba";
    //cin >> t;
    int k =7;
    //cin>>k;
    
    int j = 1;
    
    for (j=1; j<k; j++) {
        s.pop_back();
        size_t found = t.rfind(s);
        if (found != string::npos){
             break;
        }
    }

    
    if (s.length() == 0) {
        j++;
    }
    j += t.length() - s.length();
    if (j <=k) {
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return  0;
}


