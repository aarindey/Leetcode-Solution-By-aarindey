class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        deque<int> dq;
        sort(deck.begin(),deck.end());
        int n=deck.size();
        if(n<=2)
        return deck;
        dq.push_front(deck.back());
        deck.pop_back();
        while(!deck.empty())
        {
            int temp=dq.back();
            dq.pop_back();
            dq.push_front(temp);
            dq.push_front(deck.back());
            deck.pop_back();
        }
        return vector<int>(dq.begin(),dq.end());
    }
};