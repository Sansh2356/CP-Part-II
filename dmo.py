import mysql.connector
from mysql.connector import Error
import pandas as pd
#creating a server connection through mysql
def create_server_connection(hostname,username,userpassword):

  try:
    connection=mysql.connector.connect(
        host=hostname,
        user=username,
        passwd=userpassword
    )
    print('MySql Database connection success')
  except Error as err:
    print('Error  ')
    print(err)
  return connection


pw = "Shweta@123"
db="mysql_python"
connection=create_server_connection("localhost","root",pw)

#Creating db using python
def create_db(connection,query):
  cursor=connection.cursor()
  try:
    cursor.execute(query)
    print("Database created success")
  except Error as err:
    print(err)
create_db_query="create database mysql_python"
create_db(connection,create_db_query);

#Connecting to db

def create_db_connection(host_name,user_name,user_password,db_name):
  connection=None
  try:
    connection=mysql.connector.connect(
      host=host_name,
      user=user_name,
      passwd=user_password,
      database = db_name 
    )
    print("Mysql database connection successful")
  except Error as err:
    print(err)
  return connection
  
  #Executing sql queries

def execute_query(connection,query):
    
    cursor=connection.cursor()
    try:
      cursor.execute(query)
      connection.commit()
      print('Query executed successfully')
    except Error as err:
      print(err)
#For reading a query
def read_query(connection,query):
  cursor=connection.cursor()
  result = None
  try:


    cursor.execute(query)
    result = cursor.fetchall()
    return result
  except Error as err:
    print(err)
  

create_demo_table = """
create table demo(
id int primary key,
name varchar(20) not null,
age int not null
);
"""

#connect to the database


execute_query(connection,create_demo_table)
connection=create_db_connection("localhost","root",pw,db)
create_demo_table="""
insert into demo values(1,"Simba","10")
"""
execute_query(connection,create_demo_table)

connection=create_db_connection("localhost","root",pw,db)
create_demo_table="""
select*from demo;
"""

q1 = read_query(connection,create_demo_table)
for i in q1:
  print(i)

