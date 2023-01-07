from flask import Flask, render_template, url_for, json
import requests


app = Flask(__name__)

@app.route('/') 

def request_api():

    return render_template('index.html')

if __name__ == '__main__':
    app.run(debug = True)







