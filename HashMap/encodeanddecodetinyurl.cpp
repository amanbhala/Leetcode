class Solution {
public:
    unordered_map<string,int>map;
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        map[longUrl]=rand();
        return to_string(map[longUrl]);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string decodeString="";
        for(auto it: map){
            if(it.second==stoi(shortUrl)){
                decodeString=it.first;
                break;
            }
        }
        return decodeString;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));