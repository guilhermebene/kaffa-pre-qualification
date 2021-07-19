from flask_restx import Api

from .namespaceEx6 import api as nsEx6
from .namespaceTODO import api as nsTODO

api = Api(
    title='My KAFFA-PRE-EVALUATION API',
    version='1.1',
    description='KAFFA PRE-EVALUATION',
)

api.add_namespace(nsEx6)
api.add_namespace(nsTODO)