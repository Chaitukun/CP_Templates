vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n,0);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(z[i - l], r - i ); //already precomputed z values is used
            //handle case of z[i] reaching for characters beyond what we have seen at r i.e,, (r-i)
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) { // if matching characters found,extend the search
            z[i]++;
        }
        if(i + z[i] > r) { //if rightMost segment exceeds r, update new boundaries
            l = i;
            r = i + z[i];
        }
    }
    return z; //used for patten search : 'aba $ abacaba'
}