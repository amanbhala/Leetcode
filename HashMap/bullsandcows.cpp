class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0;
        int cows=0;
        vector<int>s(10,0);
        vector<int>g(10,0);
        if(secret.length()!=guess.length()){
            return "0A0B";
        }
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }else{
                s[secret[i]-'0']++;
                g[guess[i]-'0']++;
            } 
        }
        for(int i=0;i<10;i++){
            cows+=min(g[i],s[i]);
        }
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};