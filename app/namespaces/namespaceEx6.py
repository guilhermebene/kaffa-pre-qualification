import datetime

import flask
import requests

from flask_restx import Resource, Api, Namespace

api = Namespace('Ex6', description='Ex6')

@api.route('/')
class Datetime(Resource):
    def get(self):
        data = {'currentDateTime':  datetime.datetime.now().astimezone().isoformat(timespec='minutes')}
        return flask.jsonify(data)