import flask
import requests

from flask_restx import Resource, Api, Namespace

api = Namespace('Ex6', description='Ex6')

@api.route('/')
class Datetime(Resource):
    def get(self):
        r = requests.get('http://worldclockapi.com/api/json/utc/now/')

        print(f'Received status code: {r}')
        if r.status_code != 200:
            api.abort(404)

        # Datetime conventions: https://www.w3.org/TR/NOTE-datetime
        return {
            'currentDateTime': r.json()['currentDateTime']
        }