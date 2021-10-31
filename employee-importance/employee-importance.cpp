/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
    unordered_map<int,Employee*> map;
    for(Employee* emp:employees)
    {
        map[emp->id]=emp;
    }
    queue<int> q;
    q.push(id);
    int sum=0;
    while(q.size()!=0)
    {
        int idx=q.front();
        sum+=map[idx]->importance;
        q.pop();
        for(int sub:map[idx]->subordinates)
        {
            q.push(sub);
        }
    }
    return sum;
    }
};