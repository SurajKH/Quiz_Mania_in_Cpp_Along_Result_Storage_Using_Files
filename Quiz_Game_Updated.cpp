#include<bits/stdc++.h>
#define QUESTION_NUMBER 10
using namespace std;
//let user be the new user.
//let them ans five questions (random access)
//we need to consider the visitedness.
class Questions_Db
{
    private:
       int no_of_Questions=5;
        vector<string> Questions;
         vector<string> Solutions;
    public:
    
    //Getters and Setters functions.
    void setQnsValues(vector<string> &qns)
    {
        //Set the Values over here.
       this->Questions=qns;
       //this->Solutions=sol;
       
    }
    vector<string> getQnsValues()
    {
        return Questions;
    }
    void setSolValues(vector<string> &sol)
    {
        this->Solutions=sol;
    }
    vector<string> getSolValues()
    {
        return Solutions;
    }
    
    int calc_accuracy(int user_score)
    {
        int accuracy=user_score/QUESTION_NUMBER;
        return accuracy*100;
    }
};

int main()
{
    //Create an Object and then try to access the Values for Private Data members over here.
    //once we complete the operation we are able to store the result into the File over here.
     Questions_Db obj;
     
     vector<string> questions={"\n1.Which of the following is “address of operator”?\nOptions[*,&,&&,||]\n",
     "\n2.Which of the following data type is supported in C++ but not in C?\nOptions[int,bool,float,double]\n","\n3.Identify the correct example for a pre-increment operator.\nOptions[++a,--a,a++,a--]\n","\n4.Scope resoultion Operator is denoted as?\nOptions[,,.,::,?]\n","\n5.goto can be classified into?\nOptions[label,variable,operator,function]\n","\n6.\n","\n7.\n","\n8.\n","\n9.\n","\n10.\n"};
     vector<string> solutions={"&","bool","++a","::","label"};
     
     map<string,string> mp;
     for(int i=0;i<questions.size();i++)
     {
         mp[questions[i]]=solutions[i];
     }
     for(auto it:mp)
     {
         cout<<it.first<<" "<<it.second<<" ";
         cout<<endl;
     }
     obj.setQnsValues(questions);
     obj.setSolValues(solutions);
     vector<string> q=obj.getQnsValues();
     vector<string> s=obj.getSolValues();
     for(auto it:q)
     {
         cout<<it<<" ";
     }
     cout<<endl;
     for(auto it:s)
     {
         cout<<it<<" ";
     }
     cout<<"-------------------------QUIZ GAME IN C++-------------------------\n";
     cout<<endl;
     int choice;
     cout<<"Enter choice:\n";
     cout<<"1.Play Quiz,2.Exit\n";

     cin>>choice;
     cout<<endl;
     map<pair<string,char*>,int> mp_score;
     
     map<pair<string,char*>,int> mp_global_score;
     
     switch(choice)
     {
         case 1:{
                int n;
                cout<<"Enter the Number of Players in a Quiz:\n";
                cin>>n;
                for(int i=0;i<n;i++)
                {
                    
                
                
                cout<<"Enter the User Name:\n";
                string user_name;
                cin>>user_name;
                int user_score=0;
                int correct_ans=0;
                
                 vector<string> str_user_name;
                 vector<char*> user_time_stamp;
                 vector<string> user_score_string_vec;
         
                for(int i=0;i<questions.size();i++)
                {
                    string str;
                    cout<<"QUESTION:"<<i+1<<"\n"<<questions[i]<<endl;
                    cout<<"\n";
                    cout<<"Enter Your Answer:\n";
                    cin>>str;
                    if(mp[questions[i]]==str)
                    {
                        //correct answer!!!
                        user_score++;
                        correct_ans+=1;
                    }
                    else
                    {
                        user_score+=0;
                    }
                }
               
                int q_val=QUESTION_NUMBER;
                string user_score_string=to_string(user_score)+"/"+to_string(q_val);
                time_t now=time(0);
                char *date_time=ctime(&now);
                mp_score[{user_name,date_time}]=user_score;
               
                for(auto it:mp_score)
              {
                  
                      str_user_name.push_back(it.first.first);
                      user_time_stamp.push_back(it.first.second);
                      user_score_string_vec.push_back(user_score_string);
                  
              }
                
            ofstream file_store("datastore.txt");
               
            for(int i=0;i<str_user_name.size();i++)
             {
              file_store<<str_user_name[i]<<" , "<<user_score_string_vec[i]<<" , "<<user_time_stamp[i]<<endl;

              }
               
              
              mp_global_score=mp_score;
              vector<string> str_name;
              vector<char*> time_stamp;
              int str_score;
              int maxi=INT_MIN;
              
             //map<pair<string,char*>,int> mp_score;
              for(auto it:mp_score)
              {
                  if(it.second>maxi)
                  {
                      maxi=it.second;
                  }
              }
              
              for(auto it:mp_global_score)
              {
                  cout<<it.first.first<<"  "<<it.first.second<<endl;
              }
              
              for(auto it:mp_score)
              {
                  if(it.second==maxi)
                  {
                      str_name.push_back(it.first.first);
                      time_stamp.push_back(it.first.second);
                  }
              }
               ofstream res_store("resultstore.txt");
               
               for(int i=0;i<str_name.size();i++)
               {
                   res_store<<str_name[i]<<","<<time_stamp[i]<<" ";
               }
              //cout<<"The File Data is Updated Successfully."<<endl;
                
                }
         }
                break;
                
       case 2:exit(0)
              break;
                 
                
     }
}