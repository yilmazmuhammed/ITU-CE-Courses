
#####################################################################
### Assignment skeleton
### You can alter the below code to make your own dynamic website.
### The landing page for assignment 3 should be at /
#####################################################################

from bottle import route, run, default_app, debug, request
import csv

contents = []
with open("a2_input.csv") as input_file:
    for row in csv.reader(input_file):
        contents = contents + [row]
contents[0][1] = "Date"

def htmlify(title,text,style):
	page = """
<!doctype html>
<html lang="en">
	<head>
		<meta charset="utf-8" />
		<title>%(title)s</title>
		<style>%(style)s</style>
		
	</head>
	<body>%(body)s</body>
</html>
""" %{'style': style,
	  'title': title,
	  'body': text
	  }
	return page

def index():
	text = """
		<form action="/data" method="GET">
  			<input type="SUBMIT" value="Click for showing data">
		</form>
		<form action="/new_eartquake" method="GET">
  			<input type="SUBMIT" value="Click for adding new eartquake info">
		</form>
		<form action="/about" method="GET">
  			<input type="submit" value="Click for about page">
		</form>

	"""

	return htmlify("Eartquakes | Muhammed YILMAZ", text,"")

def about_page():
	style = """
		table, th, td {
			<!-- border: 1px solid black; -->
			border-collapse: collapse;
			font-weight:normal
		}
		th, td {
			padding: 5px;
			text-align: left;
		}
		th.header {
			font-weight:bold
		}
	"""

	text = """
		<h2> About me </h2>
		<table>
			<tr>
				<th class="header">Name:</th>
				<th>Muhammed YILMAZ</th>
			</tr>
			<tr>
				<th class="header">Number:</th>
				<th>150150149</th>
			</tr>
			<tr>
				<th class="header">Mail:</th>
				<th>yilmazmu15@itu.edu.tr</th>
			</tr>
			<tr>
				<th class="header">User Name:</th>
				<th>yilmazm</th>
			</tr>
		</table>
	"""
	return htmlify("About Me | Muhammed YILMAZ", text, style)

def data_page():
	#	tablolar yukarıya doğru hizalanacak
	body = """
		<h2 align="center"> EARTQUAKE RECORDS IN TURKISH STATISTICAL INSTITUTE </h2>
		<div align="center" style="margin-right:80px;">
			<table class = "table_page">
				<tr>
					<td class = "left_col_page">
							%(data)s
					</td>
					<td class = "right_col_page">
							%(forms)s
					</td>
				</tr>
			</table>
		</div>
	"""	%{'data':data_table_text(), 
		  'forms':data_form_text()
		}

	style = data_table_style() + """
			table.table_page, .left_col_page, .right_col_page {
				vertical-align: top;
			}
			.table_page, .left_col_page ,.div_formlar{
				text-align: center;
			}
			td.right_col_page{
				/* soldan bir miktar boşluk bırakılacak */
				/* sola dayanması lazım */
			}
		"""

	return htmlify("Data Page | Muhammed YILMAZ", body, style)

def data_form_text():
	text = """
		<form action="/data" method="get">
			<!-- type açılan menü-->
			<label>Select "all type" or "selected type",<br /> before selecting only one type. </label>
			<br />
			<table align="center" vertical-ali >
				<tr>
					<td>
						<select name="multiple_type">
							<option value="all">All</option>
							<option value="select_radio">Select Type</option>
						</select>
					</td>
					<td>
						<input type="radio" name="select_type" id="mb" value="mb"> Mb </input><br />
						<input type="radio" name="select_type" id="md" value="md"> Md </input><br />
						<input type="radio" name="select_type" id="ml" value="ml"> Ml </input><br />
						<input type="radio" name="select_type" id="mw" value="mw"> Mw </input><br />
					</td>
				</tr>
			</table>
			<br /><br />
			<div align="center">
				<label>Enter range of location</label>
				<br />
				<input type="text" name="min_latitude" placeholder="Min Latitude">
				<input type="text" name="max_latitude" placeholder="Max Latitude">
				<br />
				<input type="text" name="min_longitude" placeholder="Min Longitude">
				<input type="text" name="max_longitude" placeholder="Max Longitude">
			</div>
			<br />
			<div align="center">
				<label>Enter range of magnitude </label>
				<br />
				<input type="text" name="min_magnitude" placeholder="Min Magnitude">
				<input type="text" name="max_magnitude" placeholder="Max Magnitude">
			</div>
			<br />
			<div align="center">
				<label>Enter range of depth </label>
				<br />
				<input type="text" name="min_depth" placeholder="Min Depth">
				<input type="text" name="max_depth" placeholder="Max Depth">
			</div>
			<br />
			<div align="center">
				<label>Enter range of date </label>
				<br />
				<input type="text" name="min_date" placeholder="Min Date">
				<input type="text" name="max_date" placeholder="Max Date">
			</div>
			<br /><br />
			<input type="submit" value="Apply Filters"/>
			<input type="reset" value="Clear"/>
		</form>
		"""
	return text

def data_table_style():
	style = """
			tr.table_title{
				font-weight: bold;
			}
			.data_table {
				width: 100px; 
				border-style: solid;
				border-width: 1px;
				text-align: center;    
				table-layout: fixed;	/*sütun genişlikleri*/
				border-collapse: collapse;	/*kenarlıklar arası boşluk gider*/
			}
			"""
	return style

def data_table_text():

	#typex = request.forms.getall("multiple_type")
	if "multiple_type" in request.GET:
		typex = request.GET['multiple_type']
	else:
		typex = 'yok'
	which_type = request.GET.getlist('select_type')
	if "min_date" in request.GET:
		min_datex = request.GET['min_date']
	else:
		min_datex = ''
	if "max_date" in request.GET:
		max_datex = request.GET['max_date']
	else:
		max_datex = ''
	if "min_latitude" in request.GET:
		min_latitudex = request.GET['min_latitude']
	else:
		min_latitudex = ''
	if "max_latitude" in request.GET:
		max_latitudex = request.GET['max_latitude']
	else:
		max_latitudex = ''
	if "min_longitude" in request.GET:
		min_longitudex = request.GET['min_longitude']
	else:
		min_longitudex = ''
	if "max_longitude" in request.GET:
		max_longitudex = request.GET['max_longitude']
	else:
		max_longitudex = ''
	if "min_depth" in request.GET:
		min_depthx = request.GET['min_depth']
	else:
		min_depthx = ''
	if "max_depth" in request.GET:
		max_depthx = request.GET['max_depth']
	else:
		max_depthx = ''
	if "min_magnitude" in request.GET:
		min_magnitudex = request.GET['min_magnitude']
	else:
		min_magnitudex = ''
	if "max_magnitude" in request.GET:
		max_magnitudex = request.GET['max_magnitude']
	else:
		max_magnitudex = ''
	

	text = """
							<table class = "data_table">
							"""
	x = -1
	for t in contents:
		x = x+1
		if(x==0):
			text = text + """
								<tr class="table_title">
								"""
		else:
			if( (min_datex != '' and min_datex > contents[x][1]) or
				(max_datex != '' and max_datex < contents[x][1]) or
				(min_latitudex != '' and min_latitudex > contents[x][2]) or 
				(max_latitudex != '' and max_latitudex < contents[x][2]) or
				(min_longitudex != '' and min_longitudex > contents[x][3]) or 
				(max_longitudex != '' and max_longitudex < contents[x][3]) or
				(min_depthx != '' and min_depthx > contents[x][4]) or
				(max_depthx != '' and max_depthx < contents[x][4]) or
				(min_magnitudex != '' and min_magnitudex > contents[x][8]) or
				(max_magnitudex != '' and max_magnitudex < contents[x][8])
				):
				continue
			show = []

			show = "all"
			if "all" in typex:
				pass
			elif "yok" in typex:
				pass
			elif ("mb" in which_type):
				show =  "mb" 
			elif ("md" in which_type):
				show =  "md" 
			elif ("ml" in which_type):
				show = "ml" 
			elif ("mw" in which_type):
				show = "mw" 
			else:
				show = ""

			if "all" in show:
				pass
			elif contents[x][7].lower() in show:
				pass
			else:
				continue


			text = text + """
								<tr>
								"""

		for y in range(0,11):
			if(y==0 or y==6 or y==5 or y==9 or y==10):
				continue
			if(y==1):
				text = text + """
									<td class = "data_table">"""+contents[x][y][0:10]+"""</td>
									"""
				continue

			text = text + """
									<td class = "data_table">"""+contents[x][y]+"""</td>
									""" 

			pass
		
		text = text + """
								</tr>
								"""
		pass

	text = text + """
							</table>
							"""
	return text

def new_eartquake_page():
	text = """
	<div align="center">
	<form action="/new_eartquake/add" method="GET">
		<div align="left">
			<label><strong>	Select desired entries </strong></label><br />
			<input type="checkbox" name="selected_col" value="1">Date<br />
			<input type="checkbox" name="selected_col" value="2">Latitude<br />
			<input type="checkbox" name="selected_col" value="3">Longtitude<br />
			<input type="checkbox" name="selected_col" value="4">Depth<br />
			<input type="checkbox" name="selected_col" value="7">Type<br />
			<input type="checkbox" name="selected_col" value="8">Magnitude<br />
			<input type="submit" value="Add New Record">
		</div>
	</form>
	</div>
	"""
	return htmlify("New Eartquake | Muhammed YILMAZ", text,"")

def new_eartquake_add_page():

	selected_colx = request.GET.getlist("selected_col")

	form_text = ["","""
				<label>Date: </label>
				<br />
				<input type="text" name="add_date" placeholder="Ex: dd-mm-yyyy"><br />
	""","""
				<label>Latitude: </label>
				<br />
				<input type="text" name="add_latitude" placeholder="Ex: 45.78"><br />
	""","""	
				<label>Longtitude: </label>
				<br />
				<input type="text" name="add_longtitude" placeholder="Ex: 25.68"><br />
	""","""	
				<label>Depth: </label>
				<br />
				<input type="text" name="add_depth" placeholder="Ex: 15.5"><br />
	""","","","""
				<label>Type: </label>
				<br />
				<input type="text" name="add_type" placeholder="Ex: (mb/md/ml/mw)"><br />
	""","""	
				<label>Magnitude: </label>
				<br />
				<input type="text" name="add_magnitude" placeholder="Ex: 5,6"><br />
	""","","",""]

	text = """
		<div align = "center">
			<form action="/new_eartquake/add/adding" method="get">
				<label> <strong> Add New Eartquake Record </strong> </label> <br /><br />
	"""

	for a in selected_colx:
		text += form_text[int(a)]

	text += """
				<br />
				<input type="submit" name="add_record" value="Add Record">
				<!--<input type="button" value="Click me" onclick="alert('This operation is not create')">-->
				<input type="reset" value="Clear"/>
			</form>
		</div>
	"""
	return htmlify("Add New Eartquake | Muhammed YILMAZ",text,"")

def new_eartquake_add_adding_page():
	

	adding = ["","","","","","","","","","",""]


	if "add_date" in request.GET:
		adding[1] = request.GET['add_date']
	else:
		adding[1] = ''
	if "add_latitude" in request.GET:
		adding[2] = request.GET['add_latitude']
	else:
		adding[2] = ''
	if "add_longtitude" in request.GET:
		adding[3] = request.GET['add_longtitude']
	else:
		adding[3] = ''
	if "add_depth" in request.GET:
		adding[4] = request.GET['add_depth']
	else:
		adding[4] = ''
	if "add_type" in request.GET:
		adding[7] = request.GET['add_type']
	else:
		adding[7] = ''
	if "add_magnitude" in request.GET:
		adding[8] = request.GET['add_magnitude']
	else:
		adding[8] = ''

	contents.append(adding)

	return """
		<!doctype html>
		<html lang="en">
			<head>
				<meta charset="utf-8" />
				 <meta http-equiv="refresh" content="1; URL=../../data">
				<title>Adding Operation | Muhammed YILMAZ</title>
				
			</head>
			<body>
				<p>Record was be added</p>
			</body>
		</html>
		"""

route('/', 'GET', index)
route('/data', 'GET', data_page)
route('/about', 'GET', about_page)
route('/new_eartquake','GET',new_eartquake_page)
route('/new_eartquake/add', 'GET', new_eartquake_add_page)
route('/new_eartquake/add/adding', 'GET', new_eartquake_add_adding_page)


#####################################################################
### Don't alter the below code.
### It allows this website to be hosted on Heroku
### OR run on your computer.
#####################################################################

# This line makes bottle give nicer error messages
debug(True)
# This line is necessary for running on Heroku
app = default_app()
# The below code is necessary for running this bottle app standalone on your computer.
if __name__ == "__main__":
  run()

