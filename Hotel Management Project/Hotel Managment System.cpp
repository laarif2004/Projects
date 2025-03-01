#include<iostream>
#include<cctype>
#include<ctime>
using namespace std;
string date_(){
    time_t timestamp = time(&timestamp);
    struct tm datetime = *localtime(&timestamp);
    return (to_string(datetime.tm_mday)+"/"+to_string(datetime.tm_mon+1)+"/"+
    to_string(datetime.tm_year+1900)+"  "+to_string(datetime.tm_hour)+':'+to_string(datetime.tm_min));
}
int condition(int c,int c1,int c2){
        while (!(cin>>c) || c<c1 || c>c2 ){
        cin.clear();
        cin.ignore();
        cout<<"Invalid Input, try again: ";}
        return c; 
}
void continue_(){
    string e;
    cout<<'\n'<<"Enter any key to continue : ";
    cin>>e;
    cout<<"-----------------------------"<<'\n';
}
class room{
    public:
    string guest="EMPTY";
    double price;
    int id;
    bool booked=false;
    string book_date="NONE";string due_date="None";
};
class single_room:public room{
    public:
    string type="Single";
    };
class double_room:public room{
    public:
    string type="Double";
};
class customer{
    public:
    string name="NONE",nat,pn;
    int room=-1,freq=0,age,prefs,prefd,t;
    string record[5];

};
void display(single_room x[] , int i){
    cout<<"Room Number  : "<<x[i].id<<'\n'<<"Booked by    : "<<x[i].guest<<'\n'
    <<"Type         : "<<x[i].type<<'\n'<<"Booking Date : "<<x[i].book_date<<'\n'
    <<"Checking Out : "<<x[i].due_date<<'\n'
    <<"Bill         : "<<'$'<<x[i].price;
}
void display(double_room x[] , int i){
    cout<<"Room Number  : "<<x[i].id<<'\n'<<"Booked by    : "<<x[i].guest<<'\n'
    <<"Type         : "<<x[i].type<<'\n'<<"Booking Date : "<<x[i].book_date<<'\n'
    <<"Checking Out : "<<x[i].due_date<<'\n'
    <<"Bill         : "<<'$'<<x[i].price;
    
}
class Hotel{
    public:
    bool admin=false;
    int n=0;
    single_room s_rooms[5];
    double_room d_rooms[5];
    customer customers[20];

    Hotel(){
    s_rooms[0].id=1;d_rooms[0].id=6;
    s_rooms[1].id=2;d_rooms[1].id=7;
    s_rooms[2].id=3;d_rooms[2].id=8;
    s_rooms[3].id=4;d_rooms[3].id=9;
    s_rooms[4].id=5;d_rooms[4].id=10;   
    }
    void bill(){
        string name;
        cout<<"Enter your name : ";
        cin>>name;
        for (int i=0;i<5;i++){
            if(s_rooms[i].guest==name){cout<<"You are booked in room "<<s_rooms[i].id<<"and your Bill is $"<<s_rooms[i].price;continue_();return;}
            if(d_rooms[i].guest==name){cout<<"You are booked in room "<<d_rooms[i].id<<"and your Bill is $"<<d_rooms[i].price;continue_();return;}
            cout<<"You are not booked in any room!";continue_();return;}
        }
    void security(){
        string pass;
        if (admin==true){
            database();
            return;}
        if (n==3){cout<<"This access have been blocked";continue_();return;}
        cout<<"Enter the password : ";
        do{
            cin>>pass;
            n++;
            if (pass=="mse"){admin=true;database();return;}
            else if(n<3) cout<<"Incorrect password ! try again : ";
        }while (n<3);
        cout<<"This access have been blocked";continue_();return;
    }
    void people(){
        if(customers[0].name=="NONE"){cout<<"****************************"<<'\n'<<"Empty List"<<'\n'<<"****************************"<<'\n';continue_();return;}
        int c,i=0;
        bool exist=false;
        cout<<'\n'<<"Customers :"<<'\n'<<"****************************"<<'\n';
        for(;i<20;i++){
            if (customers[i].name!="NONE") cout<<i+1<<" - "<<customers[i].name<<'\n';
            else break;
        }
        cout<<"Pick a command : ";
        c=condition(c,0,i);
        cout<<"****************************"<<'\n'
        <<"Name :           "<<customers[c-1].name<<'\n'<<"Age :            "<<customers[c-1].age<<'\n'<<"Country :        "<<customers[c-1].nat
        <<'\n'<<"Phone Number :   "<<customers[c-1].pn<<'\n'
        <<"Status :         ";if (customers[c-1].room==-1) cout<<"Currently Not Booked "; else cout<<"Currently Booked in Room "<<customers[c-1].room;
        cout<<'\n'<<"Loyalty Points:  "<<customers[c-1].freq<<'\n'<<"Room Preference: ";
        if(customers[c-1].t<3) cout<<"Not enough data!";else if(customers[c-1].prefd<customers[c-1].prefs) cout<<"Single Room"; else cout<<"Double Room";
        cout<<'\n'<<"****************************"<<'\n';
        cout<<" r : Records"<<'\n'<<"-----------------------------"<<'\n'<<" 0 : Back"<<'\n'<<" 1 :Return to Main Menu ";
        char c1;
        cin>>c1;
        switch (c1){
            case '1':start_();break;
            case 'r':{
                cout<<'\n'<<customers[c-1].name<<"'s Records :"<<'\n'<<"****************************"<<'\n';
                for (int k=4;k>=0;k--){
                    if (customers[c-1].record[k]!="") cout<<k+1<<" - "<<customers[c-1].record[k]<<'\n';}
                    cout<<"****************************"<<'\n';
                    continue_();
                    break;
                    }
        }

    }
    void about_(){
        cout<<"****************************"<<'\n'<<"This Our MSE 2nd Year C++ Project Made by : Majd Laarif, Roua Remadi and Rihem Amiche"<<'\n'
        <<"If You Are Reading This, Thanks For Stopping By !"<<'\n'<<"****************************";
        string e;
        cout<<'\n'<<"Enter any key to return : ";
        cin>>e;
        cout<<"-----------------------------"<<'\n';
    }
    void database(){
        int c;
        cout<<"Hotel DataBase"<<'\n'<<"****************************"<<'\n'
        <<" 1 : Rooms"<<'\n'<<" 2 : Customers"<<'\n'<<"****************************"<<'\n';
        cout<<"Pick a category : ";
        while (!(cin>>c) ){
            cin.clear();
            cin.ignore();
            cout<<"Invalid Input, try again: ";
            }
        switch (c){
            case 1 : hotel_management();break;
            case 2 : people();
        }
    }
    void services(){
        cout<<'\n'<<"Services"<<'\n'<<"****************************"<<'\n'
        <<" 1 : Book a Room"<<'\n'<<" 2 : Cancel a Booking"<<'\n'<<" 3 : Bill"
        <<'\n'<<"****************************"<<'\n';
        int c;
        cout<<"Pick a command : ";
        while (!(cin>>c)){
            cin.clear();
            cin.ignore();
            cout<<"Invalid Input, try again: ";
        }
        switch(c){
            case 1:book();break;
            case 2:cancel();break;
            case 3:bill();break;
        }
    }
    void book(){
    string guest,type,na,phone_number;
    int m,d,c=0,age;
    double coe=1;
    bool exist=false;
    cout<<"Enter your name ";
    getline(cin>>ws,guest);
    // Checking if the customer has not already booked
    for(int i=0;i<5;i++){
        if (s_rooms[i].guest==guest || d_rooms[i].guest==guest){
            if (s_rooms[i].guest==guest) cout<<"Sir, you are already booked in Room "<<s_rooms[i].id;
            else cout<<"Sir, you are already booked in Room "<<d_rooms[i].id;
            continue_();
            return;
        }}
    for(int i=0;i<20;i++){
            if(customers[i].name==guest){
                exist=true;
                if(customers[i].freq>1){
                cout<<"-----------------------------"
                <<'\n'<<"You are a loyal customer! A 20% discount has been applied, Thanks for choosing our hotel!  "<<'\n'
                <<"-----------------------------"<<'\n';
                coe=0.8;
                break;}}
        }
    if (exist==false){
        cout<<"Thanks for choosing our hotel, since this is your first booking we need you to add vital informations "<<'\n';
        cout<<"Enter you age : ";
        while (!(cin>>age)) {
            cin.clear();
            cin.ignore();
            cout<<"Enter a number please :";};
        if (age<18){
            cout<<"I am sorry you are too young to book a room."<<'\n';
            continue_();
            start_();}
        else while(age>100){
            cout<<"Sorry I find that hard to believe, try again : ";
            cin>>age;}
        cout<<"Enter you phone number : ";
        cin>>phone_number;
        cout<<"Enter your country : ";
        cin>>na;
        
    }
        
    cout<<"Single or Double Room ? ( S / D )? ";
    cin>>type;
    while(type!= "s" && type!="S" && type!="D" && type!="d"){ cout<<"Invalid Type. Try again ( S / D )? : ";cin>>type;}
    cout<<"for how long ? (months)";
    while (!(cin>>m) || m<0 || m>5 ){
        cin.clear();
        cin.ignore();
        cout<<"the maximum is 5 months, try again : ";}
    cout<<"how many days ? : ";
    if (m!=0)while (!(cin>>d) || d<0 || d>14 ){
            cin.clear();
            cin.ignore();
            cout<<"the maximum is 2 weeks and minimum is 0, try again : ";}
    else while (!(cin>>d) || d<1 || d>14){
        cin.clear();
        cin.ignore();
        cout<<"the maximum is 2 weeks and minimum is 1, try again : ";}
    for (;c<20;c++){
        if (customers[c].name==guest){
            customers[c].freq++;
            exist=true;
            break;
        }}
    if (exist==false){
        for(c=0;c<20;c++){
            if (customers[c].name=="NONE"){
                customers[c].name=guest;
                customers[c].age=age;
                customers[c].nat=na;
                customers[c].pn=phone_number;
                customers[c].freq++;
                break;
            }
        }
    }
    if (type=="s" || type=="S"){
        for(int i=0;i<5;i++){
            if (s_rooms[i].booked==false){
                s_rooms[i].guest=guest;
                s_rooms[i].booked=true;
                s_rooms[i].book_date=date_();
                s_rooms[i].price=(100*m+20*d)*coe;
                customers[c].room=s_rooms[i].id;
                customers[c].prefs++;customers[c].t++;
                if (m==0 && d>1) s_rooms[i].due_date="In "+to_string(d)+" Days";
                else if (m==0 && d==1)s_rooms[i].due_date="In "+to_string(d)+" Day";
                else if (m>1 && d==0) s_rooms[i].due_date="In "+to_string(m)+" Months";
                else if (m==1 && d==0) s_rooms[i].due_date="In "+to_string(m)+" Month";
                else if (m>1 && d>1) s_rooms[i].due_date="In "+to_string(m)+" Months and "+to_string(d)+" Days";
                else if (m==1 && d==1)s_rooms[i].due_date="In "+to_string(m)+" Month and "+to_string(d)+" Day";
                else if (m==1 && d>1)s_rooms[i].due_date="In "+to_string(m)+" Month and "+to_string(d)+" Days";
                else if (m>1 && d==1)s_rooms[i].due_date="In "+to_string(m)+" Months and "+to_string(d)+" Day";
                //Registering in the records
                for (int k=0;k<5;k++){
                    if (customers[c].record[k]==""){
                        customers[c].record[k]="Room "+to_string(s_rooms[i].id)+"  "+s_rooms[i].book_date;
                        break;
                }}
                cout<<"-----------------------------"<<'\n'<<"You have been booked in Room "<<s_rooms[i].id
                <<'\n'<<"-----------------------------"<<'\n';
                continue_();
                return;}
                }
        cout<<"Sorry there are no available single rooms for the moment.";
        continue_();
    }
    else{
        for(int i=0;i<5;i++){
            if (d_rooms[i].booked==false){
                d_rooms[i].guest=guest;
                d_rooms[i].booked=true;
                d_rooms[i].book_date=date_();
                d_rooms[i].price=(140*m+60*d)*coe;
                customers[c].room=d_rooms[i].id;
                customers[c].prefd++;customers[c].t++;
                if (m==0 && d>1) d_rooms[i].due_date="In "+to_string(d)+" Days";
                else if (m==0 && d==1)d_rooms[i].due_date="In "+to_string(d)+" Day";
                else if (m>1 && d==0) d_rooms[i].due_date="In "+to_string(m)+" Months";
                else if (m==1 && d==0) d_rooms[i].due_date="In "+to_string(m)+" Month";
                else if (m>1 && d>1) d_rooms[i].due_date="In "+to_string(m)+" Months and "+to_string(d)+" Days";
                else if (m==1 && d==1)d_rooms[i].due_date="In "+to_string(m)+" Month and "+to_string(d)+" Day";
                else if (m==1 && d>1)d_rooms[i].due_date="In "+to_string(m)+" Month and "+to_string(d)+" Days";
                else if (m>1 && d==1)d_rooms[i].due_date="In "+to_string(m)+" Months and "+to_string(d)+" Day";
                //Registering in the records
                for (int k=0;k<5;k++){
                    if (customers[c].record[k]==""){
                        customers[c].record[k]="Room "+to_string(d_rooms[i].id)+"  "+d_rooms[i].book_date;
                        break;}}
                cout<<"-----------------------------"<<'\n'<<"You have been booked in Room : "<<s_rooms[i].id+5
                <<'\n'<<"-----------------------------"<<'\n';
                continue_();
                return;}
        }
        cout<<"Sorry there are no available double rooms for the moment.";
        continue_();
        return;
    }
}
    void cancel(){
    string guest;
    cout<<"Enter your name: ";
    cin>>guest;
    for (int i=0;i<5;i++){
        if (s_rooms[i].guest==guest){
            s_rooms[i].guest="EMPTY";
            s_rooms[i].price=0;
            s_rooms[i].book_date="EMPTY";
            s_rooms[i].due_date="EMPTY";
            s_rooms[i].booked=false;
            for(int j=0;j<20;j++){
                if (customers[j].name==guest) customers[j].room=-1;
            }
            cout<<"****************************"<<'\n'<<"Booking Canceled Successfully!"
            <<'\n'<<"****************************"<<'\n';
            continue_();
            return;}}
    for (int i=0;i<5;i++){
        if (d_rooms[i].guest==guest){
            d_rooms[i].guest="EMPTY";
            d_rooms[i].price=0;
            d_rooms[i].book_date="EMPTY";
            d_rooms[i].due_date="EMPTY";
            d_rooms[i].booked=false;
            for(int j=0;j<20;j++){
                if (customers[j].name==guest) customers[j].room=-1;
            }
            cout<<"****************************"<<'\n'<<"Booking Canceled Successfully!"
            <<'\n'<<"****************************"<<'\n';
            continue_();
            return;
    
        }
    }
    cout<<"-----------------------------"<<'\n'<<"Name not Found !"<<'\n'
    <<"-----------------------------"<<'\n';
    continue_();
}
    void start_(){
        while (true){
        int c;
        cout<<"Welcome to our Hotel"<<'\n'<<"****************************"<<'\n'
        <<"1 : Hotel Database"<<'\n'<<"2 : Services"<<'\n'<<"3 : About"<<'\n'<<"4 : EXIT"<<'\n'
        <<"****************************"<<'\n';
        cout<<"Select a Command: ";
        while (!(cin>>c) || c<1 || c>4 ){
            cin.clear();
            cin.ignore();
            cout<<"invalid input : ";};
        switch (c){
            case 1 :security();break;
            case 2 :services();break;
            case 3 :about_();break;
            case 4 : exit(0);break;
        }}
    };
    void hotel_management(){
        int c;
        cout<<"****************************"<<'\n'<<"Hotel Database"<<'\n'<<"****************************"<<'\n';
        for(int i=0;i<5;i++){
            cout<<"   "<<s_rooms[i].id<<"   |   "<<d_rooms[i].id<<'\n';
        }
        cout<<"Pick a room (0 to exit) : ";
        while (!(cin>>c)|| c>10 || c<0){
            cin.clear();
            cin.ignore();
            cout<<"There are 10 rooms, try again : ";
        }
        if (c==0) start_();
        cout<<"****************************"<<'\n';
        if (s_rooms[c-1].booked==false) cout<<"---The Room is not Booked !---"<<'\n';
        else {if (c>=1 && c<=5) display(s_rooms,c-1);
        else {if( c>=6 && c<=10) display(d_rooms,c-6);
        else cout<<"Invalid Input !"<<'\n';}};
        c=-1;
        while (c!=1 || c!=0){
        cout<<'\n'<<"****************************"<<'\n'<<"0 : Back"<<'\n'<<"1 : Return to Main Menu"<<'\n';
        cin>>c;
        if (c==0) hotel_management();
        else if (c!=0) start_();}
    }
};

int main(){
    Hotel my_hotel;
    my_hotel.start_();
}