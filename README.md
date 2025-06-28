# Task #3. Website analytics

Tasks
This console program performs analytics for a website selling products (similar to Amazon).
It processes two CSV files that contain information about the products viewed by users on different days and displays the user IDs of the users who:
1. Visited the pages on both days.
2. On the second day, visited **at least one new product page** that was not visited on the first day.

Input data
Each CSV file has a format:
user_id,product_id,timestamp
101,5,2025-06-25T12:00:00

'user_id' - an integer
'product_id' - an integer
'timestamp' - ignored (not used in calculations)

How to run
1. In the program directory there are files ‘day1.csv’ and ‘day2.csv’. They contain default data, but you can change them if you wish.
2. Compile the program. In Visual Studio or through the console. It doesn't matter.
3. User IDs that meet the conditions will appear in the console.

Algorithm
CSV files are read into type structures:
std::map<int, std::set<int>>
Where map is a mapping user_id → set product_id.
For each user from the second day:
If it exists on the first day, it checks if there are any new products (which were not present on the first day).
If any are found, their user_id is added to the result.

Big O - O(k * p)
