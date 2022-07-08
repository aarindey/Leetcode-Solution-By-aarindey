# Write your MySQL query statement below
select u.name , sum(amount) as balance from Transactions join Users u using (account) group by account having balance > 10000;

