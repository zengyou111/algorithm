//
// Created by zengyou on 2023/4/16.
//
#include "map"
#include "vector"
#include "algorithm"
#include "string"
using  namespace std;
int addMinimum(string word) {
    vector<char>str(word.size()*3,'\0');
    int index=0;
    for(int i=0;i<word.size();i++){
        if(word[i]=='a'){
            if(index%3!=0)
            do{
                index++;
            }while(index%3!=0);
            str[index++]='a';
        }
        else if(word[i]=='b'){
            if(index%3!=1){
                do{
                    index++;
                }while(index%3!=1);
            }
            str[index++]='b';
        }else{
            if(index%3!=2){
                do{
                    index++;
                }while(index%3!=2);
            }
            str[index++]='c';
        }
    }
    int cnt=0;
    for(int i=0;i<str.size();i+=3){
        if(str[i]!='\0'||str[i+1]!='\0'||str[i+2]!='\0'){
            cnt+=3;
        }
        return cnt-word.size();
    }

}
int main(){
    addMinimum("aaabcc");
    return 0;
}

