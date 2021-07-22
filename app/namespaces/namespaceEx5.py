import datetime
import requests

from flask import request

from flask_restx import Resource, Api, Namespace, fields

api = Namespace('Ex5', description='Local and UTC time')

r = requests.get('http://worldclockapi.com/api/json/utc/now')

@api.route('/', methods=['GET'])
class Datetime(Resource):
    def get(self):
        # data = {'currentDateTime':  datetime.datetime.now().astimezone().isoformat(timespec='minutes')}
        today = datetime.datetime.today()
        r = requests.get('http://worldclockapi.com/api/json/utc/now')
        date, full_time = r.json()['currentDateTime'].split('T')
        date_split = date.split('-')
        date = date_split[1] + '/' + date_split[2] + '/' + date_split[0] 
        time = full_time[:5]
        data = {
            'local': {
                'date': today.strftime("%m/%d/%Y"),
                'time': today.strftime("%H:%M")
            },
            'utc': {
                'date': date,
                'time': time
            }

        }

        return data
