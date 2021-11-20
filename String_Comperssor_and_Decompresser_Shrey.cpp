#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define ll long long int
const int mod = 1000000007;

class CompressedData{
    public :
    string compressedString;
};

class Codec{
    public :
    virtual CompressedData compress(string data) = 0;
    virtual string decompress(CompressedData result) = 0;
};

class Solution : public Codec{
    public : 
    CompressedData compress(string data){
        string s="";int m=0;
        vector<char>ar(data.length(),' ');
        for(int i=0;i<data.length();i++)
        {
            int c=0;
            for(int j=i;j<data.length();j++)
            {
                if(data[i]==data[j])
                    c++;
                else
                    break;
            }
            ar[m]=data[i]; 
            m++;
            if(c==1)   
            continue;
            string tmp=to_string(c);      
            for(int j=0;j<tmp.length();j++)
            {
                ar[m]=tmp[j];
                m++;
            } 
            i=i+c-1;
        }
        data.clear();
        for(auto it : ar){
            s += it;
        }
        CompressedData cans;
        cans.compressedString = s;
        return cans;
    }

    string decompress(CompressedData result){
        string finalans = "";
        string s =result.compressedString;
        for(int i=0; i<s.length();i++){
            if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122)){
                finalans += s[i];
            }
            else if(s[i]==' '){
                break;
            }
            else if(s[i]>='0' && s[i]<='9') {
                for(int j =0;j<s[i];j++) {
                    finalans += s[i-1];
                }
            }
        }
        return finalans;
    }
};