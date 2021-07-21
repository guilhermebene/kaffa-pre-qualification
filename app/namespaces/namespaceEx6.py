"""Defines Ex6 route"""
import datetime

import flask
import requests

from flask_restx import Resource, Api, Namespace

api = Namespace('Ex6', description='Ex6')

@api.route('/', methods=['GET'])
class Datetime(Resource):
    def get(self): # Defining GET method
        data = {'currentDateTime':  datetime.datetime.now().astimezone().isoformat(timespec='minutes')}
        return flask.jsonify(data)