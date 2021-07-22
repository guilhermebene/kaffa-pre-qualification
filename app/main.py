"""Main server app configuration"""

from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from flask_cors import CORS

app = Flask(__name__)
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
# app.config['SQLALCHEMY_DATABASE_URI'] = 'postgresql+psycopg2://postgres:4594@localhost:5432/todo'
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///db.sqlite3'
DB_NAME = 'db.sqlite3'
db = SQLAlchemy(app)
CORS(app)

if __name__ == '__main__':
    from namespaces import api
    
    db.init_app(app)
    api.init_app(app)
    app.run(debug=True)