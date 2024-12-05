bool canChange(char* s, char* t) {
    const int n=strlen(s);
    for (register int i=0, j=0; i<n  || j<n ; i++, j++){
        while(i<n && s[i]=='_') i++;
        while(j<n && t[j]=='_') j++;
        char c=s[i];
        if (c!=t[j]) return 0;
        if (c=='L' && i<j) return 0;
        if (c=='R' && i>j) return 0;
    }
    return 1;

}