"""Defines main server api and namespaces for each route"""

from flask_restx import Api

from .namespaceEx6 import api as nsEx6
from .namespaceEx5 import api as nsEx5
from .namespaceEx4 import api as nsEx4

api = Api(
    title='My KAFFA-PRE-EVALUATION API',
    version='1.1',
    description='KAFFA PRE-EVALUATION',
)

api.add_namespace(nsEx4, path='/Ex4/todo')
api.add_namespace(nsEx5, path='/Ex5')
api.add_namespace(nsEx6, path='/Ex6')