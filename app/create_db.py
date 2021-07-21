""""Create new database"""

from pathlib import Path

from main import db, DB_NAME
from models import *

def create_db():

    # if Path('./' + DB_NAME).exists():
    db.session.remove()
    db.drop_all()
    db.create_all()

if __name__ == '__main__':
    create_db()