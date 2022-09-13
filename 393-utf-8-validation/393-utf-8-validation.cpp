class Solution {
public:
    int get_num_bytes(int data) {
        if (data >> 7 == 0) {
            return 1;
        }
        if (data >> 5 == 6) {
            return 2;
        }
        if (data >> 4 == 14) { 
            return 3;
        }
        if (data >> 3 == 30) { 
            return 4;
        }
        return 0;
    }
    
    bool is_valid_multibyte(int data) {
       return (data >> 6 == 2); 
    }
    
    bool validUtf8(vector<int>& data) {
        for (int byte_index = 0; byte_index < data.size(); ++byte_index) {
            auto num_bytes = get_num_bytes(data[byte_index]);
            if (num_bytes == 0) {
                return false;
            }
            if (num_bytes == 1) { 
                continue;
            }
            if (data.size() < num_bytes + byte_index) {
                return false;
            }
            while(--num_bytes > 0) {
                ++byte_index;
                if (!is_valid_multibyte(data[byte_index])) {
                    return false;
                }
            }
        }
        return true;
    }
};