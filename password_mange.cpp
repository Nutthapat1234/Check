#include "password_mange.h"
#include <QDebug>

password_mange::password_mange(){
    gen_key();
}
void password_mange::gen_key(){
    for(int each_key =0;each_key<key.length();each_key++){
        int pos;
        keys.push_back("");
        for(int each_alphabet =0;each_alphabet<alphabet.length();each_alphabet++){
            if(key[each_key] == alphabet[each_alphabet])
                pos = each_alphabet;
        }
        int add_tokey = pos;
        for(int in_alphabet =0;in_alphabet<alphabet.length()+pos;in_alphabet++){
            if(in_alphabet >= add_tokey){
                keys[each_key] += alphabet[add_tokey];
                add_tokey++;
            }
            if(add_tokey == alphabet.length())
                add_tokey = 0;
        }
    }
}

QString password_mange::encode(QString p){
    encode_pass = "";
    int now_key = 0;
    for(int each_pass = 0 ; each_pass<p.length();each_pass++){
        for(int each_alphabet =0;each_alphabet<alphabet.length();each_alphabet++)
            if(p[each_pass] == alphabet[each_alphabet])
                encode_pass += keys[now_key][each_alphabet];
        now_key++;
        if(now_key == key.length())
            now_key = 0;
    }
    return encode_pass;
}
QString password_mange ::decode(QString p){
    decoded_pass = "";
    int now_key = 0 ;
        for(int in_pass =0;in_pass < p.length();in_pass++){
            for(int match_key = 0;match_key<alphabet.length();match_key++) {
                if (p[in_pass] == keys[now_key][match_key]) {
                    decoded_pass += alphabet[match_key];
                    break;
                }
            }
            now_key++;
            if(now_key == key.length())
                now_key = 0;
        }
    return decoded_pass;
}


