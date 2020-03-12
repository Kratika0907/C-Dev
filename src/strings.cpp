#include<iostream>
#include<string>
using namespace std;


class StringStorageTest {
    public:
        void run() {
            string s1("12345");
            string s2 = s1;
            cout<<(s1==s2)<<endl;
            s1[0] = '6';
            cout<<s1<<"s1"<<endl;
            cout<<s2 << "s2" << endl;
            cout<<(s1==s2)<<endl;
            string s3("what is the sound of one clam napping?");
            string s4(s3,0,8);
            cout<<"s4" << " " << s4 << endl;
            string s5(s3 , 7 , 10);
            cout<< "s5" << " " << s5 << endl;
            string s6 = s3.substr(0,11);
            cout<<"s6" << " " << s6 << endl;
            cout << (s6 == s3) << endl;
            string s7(s3.begin(),s3.end());
            cout << "s7" << " "<< s7<< endl;
            string s8(5,'a');
            cout<< "s8" << " " << s8 << endl;
        }
};
int main() {
    StringStorageTest t;
    t.run();
    return 0;
   
}