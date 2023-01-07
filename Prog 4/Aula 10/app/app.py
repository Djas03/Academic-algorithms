from flask import Flask, render_template, session, redirect, url_for, flash, request
from livereload import Server
from flask_bootstrap import Bootstrap
from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField, SelectField
from wtforms.validators import DataRequired
import os
from flask_sqlalchemy import SQLAlchemy
from flask_migrate import Migrate

basedir = os.path.abspath(os.path.dirname(__file__))

app=Flask(__name__)
app.config['SECRET_KEY'] = 'hard to guess string'
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///' + os.path.join(basedir, 'data.sqlite')
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False

db = SQLAlchemy(app)
bootstrap = Bootstrap(app)


class Product (db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name_prod = db.Column(db.String(64), unique=True, index=True)
    marca = db.Column(db.String(64))
    value = db.Column(db.Float)

    def __repr__(self):
        return '<Product %r>' % self.name_prod


@app.route('/index')
@app.route('/')
def index():
    return render_template('index.html')

@app.errorhandler(404)
def page_not_found(e):
    return render_template('404.html'), 404


@app.route('/cadastro')
def fom_page():
    return render_template('cadastro.html')

@app.route('/cadastro_db', methods=['POST'])
def route_cad():
    db.create_all()

    name = request.form['name']
    marca = request.form['marca']
    valor = request.form['valor']

    product = Product.query.filter_by(name_prod=name).first()

    if product is None:
        product = product = Product(name_prod=name,marca=marca, value=valor)
        db.session.add(product)
        db.session.commit()
    
        return redirect ('http://127.0.0.1:5000/cadastro')
    else:

        return redirect('http://127.0.0.1:5000')


@app.route('/list')
def list():
    listar = Product.query.all()
    return render_template('listar.html',list=listar)


@app.shell_context_processor
def make_shell_context():
    return dict(db=db, User=User, Role=Role)