class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        string pemail;
        map<string, int> unique_emails;
        
        for(int i = 0; i < emails.size(); ++i){
            pemail = parseEmail(emails[i]);
            unique_emails.insert(pair<string, int>(pemail, 1));
        }
        
        return unique_emails.size();
    }
    
    string parseEmail(const string& email){
        string pemail;
        int i = 0;
        bool ignored = false;
        
        // local name
        do {
            if(email[i] == '+'){
               ignored = true; 
            }
            else if(email[i] != '.' && !ignored){
                pemail += email[i];
            }
        } 
        while(email[++i] != '@');
        
        // domain name
        do {
            pemail += email[i];
        } 
        while(email[++i] != '\0');
        
        return pemail;
    }
};