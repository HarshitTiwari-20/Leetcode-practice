# Write your MySQL query statement below
SELECT 
    p.firstName, 
    p.lastName, 
    a.city, 
    a.state
FROM Person p
LEFT JOIN Address a 
    ON p.personId = a.personId;


################################################################################  

# Write your MySQL query statement below
SELECT 
    e.name AS Employee
FROM Employee e
JOIN Employee m 
    ON e.managerId = m.id
WHERE e.salary > m.salary;


###############################################################################


