#######################################################
### Please ignore the lines of code in this section.
### It loads the contents of a CSV file for you.
### The file's name should be a2_input.csv.
### You do not need to know how it works.
#######################################################

import csv

contents = []
with open("a2_input.csv") as input_file:
    for row in csv.reader(input_file):
        contents = contents + [row]

#######################################################
### Do your data processing below.
### The below code gives some examples
### of how to access the data.
### Print your results using the print function.
#######################################################
type = []
magnitudes = []
x = 0
while x<96:
	if(contents[x][8][1] == ','):
		magnitudes.append(float(contents[x][8].replace(',','.')))
		type.append(contents[x][7])
	x = x+1
	pass

sum = 0
for x in magnitudes:
	sum = sum + x
average = sum/95

sumOfMw = 0
numberOfMw = 0
for x in range(0,95):
	if(type[x] == "Mw"):
		sumOfMw = sumOfMw + magnitudes[x]
		numberOfMw = numberOfMw + 1
averageOfMw = sumOfMw/numberOfMw


########################################################
print("""
	<!DOCTYPE html>
	<html lang="en">
		<head>
			<meta charset="utf­8">
			<title>India Temperature Analysis</title>
		</head>

		<body>
			<h1>Eartquakes in Marmara Sea</h1>
			<p>This report is an analysis of earthquakes in the Sea of Marmara since 1995, with violence greater than 4.0.
			 Some analyzes of these earthquakes have been made. </p>
	""")
print("				<p>Sum of Mw's (type): ",sumOfMw,"<br/>")
print("Number of Mw's (type): ",numberOfMw,"<br/>")
print("Average of Mw's (type): ",averageOfMw,"<br/>")
print("Average of all eartquake's magnitude: ",average,"</p>")



print("			<table>")
for x in range(0,96):
	print("				<tr>")
	for y in contents[x]:
		print("					<td style='width:100px;'>"+y+"</td>")
		pass
	print("				</tr>")
	pass

print("			</table>")


print("""
		</body>
	</html>
	""")

