CREATE OR REPLACE FUNCTION NthHighestSalary(N INT) RETURNS TABLE (Salary INT) AS $$
BEGIN
  RETURN QUERY (    
    SELECT DISTINCT(employee.salary) FROM employee ORDER BY salary DESC LIMIT 1 OFFSET (N - 1)
  );
END;
$$ LANGUAGE plpgsql;
