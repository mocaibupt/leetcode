class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n, ladder = 1;
        unordered_set<string> dict(wordList.begin(), wordList.end());
		if(dict.find(endWord) == dict.end())
			return 0;
		queue<string> todo;
		todo.push(beginWord);
		while(!todo.empty()){
			n = todo.size();
			for(int i = 0; i < n; i++){
				string str = todo.front();
				todo.pop();
				if(str == endWord)
					return ladder;
				dict.erase(str);
				for(int j = 0; j < str.size(); j++){
					char c = str[j];
					for(int k = 0; k < 26; k++){
						str[j] = 'a'+k;
						if(dict.find(str) != dict.end())
							todo.push(str);
					}
					str[j] = c;
				}
			}
			ladder++;
		}
		return 0;
    }
	
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {        
		unordered_set<string> s(wordList.begin(),wordList.end());
		unordered_set<string> tail,head,*phead,*ptail;
		if (s.find(endWord) == s.end()) {
			return 0;
		}
		int ladder=2;
		head.insert(beginWord);
		tail.insert(endWord);
		while(!head.empty() && !tail.empty()) {
			if(head.size()<tail.size()) {
				phead = &head;
				ptail= &tail;
			} else {
				phead = &tail;
				ptail = &head;
			}
			unordered_set<string> temp;
			for( auto it = phead->begin();it!=phead->end();it++) {
				string word = *it;
				for(int i=0;i<word.size();i++) {
					char c = word[i];
					for(int k=0;k<26;k++) {
						word[i]=k+'a';
						if(ptail->find(word)!=ptail->end())
							return ladder;
						if(s.find(word)!=s.end()) {
							temp.insert(word);
						  s.erase(word); 
						}	
					}
					word[i]=c;
				}
			}
			ladder++;
			phead->swap(temp);	
		}
        return 0;
    }
};