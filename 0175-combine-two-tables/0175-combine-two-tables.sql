# Write your MySQL query statement below
SELECT Person.firstName,Person.lastName,Address.city,Address.state from Person ,Address
where Person.personId=Address.personId
union
select Person.firstName,Person.lastName,null as city , null as state from Person
where not exists (select * from Address where Person.personId=Address.personId )
;