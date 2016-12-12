#!/usr/bin/python3

import json
from jinja2 import Environment, FileSystemLoader
import sys

env = Environment(line_statement_prefix='##', loader=FileSystemLoader('templates'))
template = env.get_template('basic_struct.h')

context = {
    'include_guard_name': "SOME_FILE_H",
    'struct_name': 'some_file',
    'properties': [
        {
            "type": "const char *",
            "name": "name",
            "default_value": "NULL",
            "destructor": "free"
        },
        {
            "type": "int",
            "name": "name_length",
            "default_value": "0"
        }
    ],
}

print(template.render(context))

