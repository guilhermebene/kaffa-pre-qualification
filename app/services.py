from main import db
from models import Todo

def save_new_todo(data):

    # Add data validation if necessary

    if data['content'] is None:
        return False

    todo = Todo(content=data['content'])
    db.session.add(todo)
    db.session.commit()

    return True


def delete_todo(data):

    if data['id'] is None:
        return False

    result = db.session.query(Todo).filter_by(id = data['id'])

    if result.first() is None:
        return False

    result.delete()
    db.session.commit()

    return True


def get_all_todos():

    return db.session.query(Todo).all()