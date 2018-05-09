import json

first_names = []
last_names = []
birth_years = []


def add_person(first_name, last_name, birth_year):
    global first_names, last_names, birth_years
    first_names += [first_name]
    last_names += [last_name]
    birth_years += [birth_year]


def find_person(first_name, last_name):
    global first_names, last_names
    person_no = -1
    for i in range(len(first_names)):
        if first_names[i] == first_name and last_names[i] == last_name:
            person_no = i
            break
    return person_no


def print_person(person_no):
    global first_names, last_names, birth_years
    if person_no == -1:
        print('Person not found.')
    else:
        print('---------------------')
        print('Name: ' + first_names[person_no] + ' ' + last_names[person_no])
        print('Birth year: ' + str(birth_years[person_no]))


def update_first_name(first_name, last_name, new_value):
    global first_names
    person_no = find_person(first_name, last_name)
    if person_no == -1:
        print('Person not found.')
    else:
        first_names[person_no] = new_value


def update_last_name(first_name, last_name, new_value):
    global last_names
    person_no = find_person(first_name, last_name)
    if person_no == -1:
        print('Person not found.')
    else:
        last_names[person_no] = new_value


def update_birth_year(first_name, last_name, new_value):
    global birth_years
    person_no = find_person(first_name, last_name)
    if person_no == -1:
        print('Person not found.')
    else:
        birth_years[person_no] = new_value


def list_people():
    global first_names
    for person_no in range(len(first_names)):
        print_person(person_no)


def save_to_file(filename):
    global first_names, last_names, birth_years
    first_name_file = open(filename + '_first_names.json', 'w')
    last_name_file = open(filename + '_last_names.json', 'w')
    birth_year_file = open(filename + '_birth_years.json', 'w')

    json.dump(first_names, first_name_file)
    json.dump(last_names, last_name_file)
    json.dump(birth_years, birth_year_file)

    first_name_file.close()
    last_name_file.close()
    birth_year_file.close()


def load_from_file(filename):
    global first_names, last_names, birth_years
    first_name_file = open(filename + '_first_names.json', 'r')
    last_name_file = open(filename + '_last_names.json', 'r')
    birth_year_file = open(filename + '_birth_years.json', 'r')

    first_names = json.load(first_name_file)
    last_names = json.load(last_name_file)
    birth_years = json.load(birth_year_file)

    first_name_file.close()
    last_name_file.close()
    birth_year_file.close()


def print_menu():
    print('\n/*********************\\')
    print(') BIL103 CONTACT BOOK (')
    print('\\*********************/\n')
    print('1. List people')
    print('2. Search person by name')
    print('3. Update person')
    print('4. Add person')
    print('5. Save to file')
    print('6. Load from file')
    print('7. Exit\n')
    print('Please make a selection: ')


while True:
    print_menu()
    select = int(input())

    if select == 1:
        list_people()
    elif select == 2:
        first_name = input('First name: ')
        last_name = input('Last name: ')
        print_person(find_person(first_name, last_name))
    elif select == 3:
        first_name = input('First name: ')
        last_name = input('Last name: ')
        key = input('Field to update: ')
        value = input('New value: ')
        if key == 'first_name':
            update_first_name(first_name, last_name, value)
        elif key == 'last_name':
            update_last_name(first_name, last_name, value)
        elif key == 'birth_year':
            update_birth_year(first_name, last_name, value)
    elif select == 4:
        first_name = input('First name: ')
        last_name = input('Last name: ')
        birth_year = int(input('Birth year: '))
        add_person(first_name, last_name, birth_year)
    elif select == 5:
        file_name = input('File name: ')
        save_to_file(file_name)
    elif select == 6:
        file_name = input('File name: ')
        load_from_file(file_name)
    elif select == 7:
        break
