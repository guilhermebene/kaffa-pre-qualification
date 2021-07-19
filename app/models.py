from datetime import datetime

from flask_sqlalchemy import SQLAlchemy
from main import db

class Todo(db.Model):

    id = db.Column(db.Integer, primary_key=True, autoincrement=True)
    content = db.Column(db.String(500), nullable=False)
    creation_date = db.Column(db.DateTime, default=datetime.now)