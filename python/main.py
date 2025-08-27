from tkinter import *
from tkinter import messagebox
import random
import pyperclip
import json
from tkinter import simpledialog
# Constants
FONT = ("Comic Sans MS", 14, "italic")
BUTTON_BG = "#2C3E50"  # Button background
BUTTON_FG = "#ECF0F1"  # Button text color
BUTTON_HOVER = "#34495E"  # Hover color
BG_COLOR = "#81BFDA"  # Light blue background for the window

# ---------------------------- PASSWORD GENERATOR ------------------------------- #
def generate_pass():
    letters = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'
    numbers = '0123456789'
    symbols = '!#$%&()*+'

    password_letters = [random.choice(letters) for _ in range(random.randint(8, 10))]
    password_symbols = [random.choice(symbols) for _ in range(random.randint(2, 4))]
    password_numbers = [random.choice(numbers) for _ in range(random.randint(2, 4))]

    password_list = password_letters + password_symbols + password_numbers
    random.shuffle(password_list)
    password = "".join(password_list)
    input_pass.delete(0, END)
    input_pass.insert(0, password)
    pyperclip.copy(password)

# ---------------------------- SAVE PASSWORD ------------------------------- #
def save():
    website = input_web.get()
    email = input_mail.get()
    password = input_pass.get()
    new_data = {website: {"email": email, "password": password}}

    if len(website) == 0 or len(password) == 0:
        messagebox.showinfo(title="Oops", message="Please make sure you haven't left any fields empty.")
    else:
        try:
            with open("data.json", "r") as data_file:
                data = json.load(data_file)
        except FileNotFoundError:
            data = {}

        data.update(new_data)

        with open("data.json", "w") as data_file:
            json.dump(data, data_file, indent=4)

        input_web.delete(0, END)
        input_pass.delete(0, END)

# ------------------- FIND PASSWORD --------------------------- #
def search_web():
    website = input_web.get()
    try:
        with open("data.json") as data_file:
            data = json.load(data_file)
    except FileNotFoundError:
        messagebox.showinfo(title="Error", message="No data file found.")
    else:
        if website in data:
            email = data[website]["email"]
            password = data[website]["password"]
            messagebox.showinfo(title=website, message=f"Email: {email}\nPassword: {password}")
        else:
            messagebox.showinfo(title="Error", message=f"No details for {website} exist.")



def authenticate():
    master_password = "your"  # Store securely in a hashed format
    entered_password = simpledialog.askstring("Authentication", "Enter master password:", show="*")
    if entered_password != master_password:
        messagebox.showerror("Access Denied", "Incorrect master password!")
        window.destroy()

authenticate()

# ---------------------------- UI SETUP ------------------------------- #

def on_enter(button, hover_color):
    """Change button color on hover."""
    button.config(bg=hover_color)
  
def on_leave(button, original_color):
    """Revert button color when hover ends."""
    button.config(bg=original_color)

# Create window
window = Tk()
window.title("Password Manager")
window.config(padx=50, pady=50, bg=BG_COLOR)

# Logo
canvas = Canvas(width=200, height=200, bg=BG_COLOR, highlightthickness=0)
img = PhotoImage(file='logo.png')
canvas.create_image(100, 100, image=img)
canvas.grid(row=0, column=1)

# Labels
label_web = Label(text="Website:", font=FONT, bg=BG_COLOR, fg=BUTTON_BG)
label_web.grid(column=0, row=1, sticky="w", pady=5)
label_email = Label(text="Email/Username:", font=FONT, bg=BG_COLOR, fg=BUTTON_BG)
label_email.grid(column=0, row=2, sticky="w", pady=5)
label_pass = Label(text="Password:", font=FONT, bg=BG_COLOR, fg=BUTTON_BG)
label_pass.grid(column=0, row=3, sticky="w", pady=5)

# Entries
input_web = Entry(width=25, font=("Comic Sans MS", 12))
input_web.grid(column=1, row=1, pady=5, sticky="w")
input_mail = Entry(width=35, font=("Comic Sans MS", 12))
input_mail.grid(column=1, row=2, columnspan=2, pady=5, sticky="w")
input_mail.insert(0, "example@example.com")
input_pass = Entry(width=21, font=("Comic Sans MS", 12))
input_pass.grid(column=1, row=3, pady=5, sticky="w")

# Buttons
button_search = Button(text="Search", font=("Roboto", 12, "bold"), bg=BUTTON_BG, fg=BUTTON_FG, bd=0, command=search_web)
button_search.grid(column=2, row=1, padx=5)
button_search.bind("<Enter>", lambda e: on_enter(button_search, BUTTON_HOVER))
button_search.bind("<Leave>", lambda e: on_leave(button_search, BUTTON_BG))

button_generate = Button(text="Generate Password", font=("Roboto", 12, "bold"), bg=BUTTON_BG, fg=BUTTON_FG, bd=0, command=generate_pass)
button_generate.grid(column=2, row=3, padx=5)
button_generate.bind("<Enter>", lambda e: on_enter(button_generate, BUTTON_HOVER))
button_generate.bind("<Leave>", lambda e: on_leave(button_generate, BUTTON_BG))

button_add = Button(text="Add", font=("Roboto", 12, "bold"), bg=BUTTON_BG, fg=BUTTON_FG, bd=0, width=36, command=save)
button_add.grid(column=1, row=4, columnspan=2, pady=10)
button_add.bind("<Enter>", lambda e: on_enter(button_add, BUTTON_HOVER))
button_add.bind("<Leave>", lambda e: on_leave(button_add, BUTTON_BG))



window.mainloop()