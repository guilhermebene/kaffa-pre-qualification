from flask import request

from flask_restx import Resource, Api, Namespace, fields

from services import save_new_todo, get_all_todos, delete_todo

api = Namespace('todo', description='To-do routes')

class TodoDto:
    todo = api.model('todo', {
        'id': fields.Integer(description='TO-DO identifier'),
        'content': fields.String(description='TO-DO information'),
        'creation_date': fields.String
    })

@api.route('/new')
# @api.param('content', 'To-do text')
@api.response(404, 'TO-DO could not be added')
@api.response(201, 'TO-DO created')
class TodoNew(Resource):
    @api.doc('Create a TO-DO')
    @api.expect(TodoDto.todo)
    def post(self):
        
        data = request.json
        status = save_new_todo(data)

        if status is not True:
            api.abort(404, 'TO-DO could not be added')

@api.route('/all')
@api.response(200, 'Found TO-DOs')
class TodoList(Resource):
    @api.doc('Get all TO-DOs')
    @api.marshal_list_with(TodoDto.todo, envelope='data')
    def get(self):
        return get_all_todos()


@api.route('/delete')
# @api.param('id', 'To-do id')
@api.response(404, 'TO-DO could not be deleted')
@api.response(200, 'Deleted TO-DO')
class TodoDelete(Resource):
    @api.doc('Delete a TO-DO')
    @api.expect(TodoDto.todo)
    def post(self):
        
        data = request.json
        status = delete_todo(data)

        if status is not True:
            api.abort(404, 'TO-DO could not be deleted')