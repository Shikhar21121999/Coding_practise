#class inheritance

class person:
	def__init__(self,f_name,last_name):
		self.f_name=f_name
		self.last_name=last_name

	def print_name(self):
		print(self,f_name,self.last_name)

#student class

class student(person):
	def__init__(self,f_name,last_name,year):
		#now parent class is overidden by child class
		#hence we shift it by ourself
		super().__init__(f_name,last_name)
		self.graduation_year=year

	def welcome(self):
		print("Welcome",self.f_name,self.last_name,"to the year",self.graduation_year)

#make an object to call the required functions

stud1=student("ashiss","gupta",4561)
stud1.welcome()