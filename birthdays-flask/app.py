import os
from cs50 import SQL
from flask import Flask,redirect, render_template, request

app = Flask(__name__)
app.config["TEMPLATES_AUTO_RELOAD"] = True
db = SQL("sqlite:///birthdays.db")

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        name = request.form["name"]
        month = request.form["month"]
        day = request.form["day"]
        db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)
        return redirect("/")
    else:
        peoples = db.execute("SELECT * FROM birthdays;")
        return render_template("index.html", peoples=peoples)