/*
 * Problem Link https://www.codewars.com/kata/52cf02cd825aef67070008fa/train/cpp
 *
*/

#include <iostream>
#include <string>


using namespace std;

const string key = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789.,? /";

int myPow(int x, int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

int charToIndex(char c) {
    return key.find(c);
}

char indexToChar(size_t index) {
    //if (index != key.length()-1)
    index = index % key.length();
    return key[index];
}

char generateNext(size_t indexInString, size_t indexInKey) {
    size_t result = 0;
    size_t tmp = ++indexInKey;
    while(indexInString--) {
        indexInKey = indexInKey*2 + tmp;
        indexInKey %= key.length();
    }
    return indexToChar(tmp-1+indexInKey);
}


int formula(int a0, int n, int k) {
    return (a0 * myPow(n, k+1) - a0)/(n-1);
}

int badFormula(int a0, int n, int k) {
    //cout << a0 << " " << n << " " << k << endl;
    int result = a0;
    int increase = a0*n;
    int size = key.length();
    for (int i = 0; i < k; ++i) {
        result += increase;
        increase *= n;
        increase %= size;
        result %= size;
        //cout << "result: " << result << endl;
    }
    return result;
}

struct Encoder {
    static std::string encode(const string &str) {
        string result;
        for (int i = 0; i < str.length(); ++i) {
            size_t indexInKey = charToIndex(str[i]);
            if (indexInKey != string::npos) {
                result.push_back(generateNext(i, indexInKey));
            }
            else {
                result.push_back(str[i]);
            }
        }
        return result;
    }
};


const int MAXINDEX  = 50;
string matrix[67/*key.length()*/];

void fill() {
    if (matrix[0][0] != 'b') {
        for (auto ch : key) {
            for (int i = 0; i < 67; ++i) {
                matrix[i] = Encoder::encode(string(MAXINDEX, key[i]));
            }
        }
    }
    for (int i = 0; i < 67; ++i) {
        cout << indexToChar(i) << " " << matrix[i] << endl;
    }
}


struct Decoder {
	static std::string decode (const std::string& p_what) {  
        fill();
        string result;
        for (size_t i = 0; i < p_what.length(); ++i) {
            if (charToIndex(p_what[i]) != string::npos) {
                for (int j = 0; j < 67; ++j) {
                    if (matrix[j][i] == p_what[i]) {
                        result.push_back(indexToChar(j));
                        break;
                    }
                }
            }
            else {
                result.push_back(p_what[i]);
            }
        }
        return result;
	}
};




int main() {
    string test = Encoder::encode("Hello World!");
    cout << test << endl;
    cout << Decoder::decode(test) << endl;
    //std::cout << (myEncoder.encode ("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa")) << "\n" ;
    //std::cout << (myEncoder.encode ("bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb")) << "\n" ;  
    //std::cout << (myEncoder.encode ("!@#$%^&*()_+-")) << "\n" ;
}
