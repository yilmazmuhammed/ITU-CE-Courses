import json

people = []


def add_person(first_name, last_name, birth_year):
    global people
    people += [{'first_name': first_name, 'last_name': last_name, 'birth_year': birth_year}]


def find_person(first_name, last_name):
    global people
    person_no = -1
    for i in range(len(people)):
        if people[i]['first_name'] == first_name and people[i]['last_name'] == last_name:
            person_no = i
            break
    return person_no


def print_person(person_no):
    global people
    if person_no == -1:
        print('Person not found.')
    else:
        print('---------------------')
        print('Name: ' + people[person_no]['first_name'] + ' ' + people[person_no]['last_name'])
        print('Birth year: ' + str(people[person_no]['birth_year']))


def update_first_name(first_name, last_name, new_value):
    global people
    person_no = find_person(first_name, last_name)
    if person_no == -1:
        print('Person not found.')
    else:
        people[person_no]['first_name'] = new_value


def update_last_name(first_name, last_name, new_value):
    global people
    person_no = find_person(first_name, last_name)
    if person_no == -1:
        print('Person not found.')
    else:
        people[person_no]['last_name'] = new_value


def update_birth_year(first_name, last_name, new_value):
    global people
    person_no = find_person(first_name, last_name)
    if person_no == -1:
        print('Person not found.')
    else:
        people[person_no]['birth_year'] = new_value


def list_people():
    global people
    for person_no in range(len(people)):
        print_person(person_no)


def save_to_file(filename):
    global people
    people_file = open(filename + '_people.json', 'w')
    json.dump(people, people_file)
    people_file.close()


def load_from_file(filename):
    global people
    people_file = open(filename + '_people.json', 'r')
    people = json.load(people_file)
    people_file.close()


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
