from tkinter import *

win = Tk()
win.geometry('300x320')
win.title('Map')

photo1 = PhotoImage(file='./africa.png')
photo2 = PhotoImage(file='america.png')
photo3 = PhotoImage(file='asia.png')
photo4 = PhotoImage(file='europe.png')

title = Label(win, text='MAP', font=('Alial', 20))
title.pack()


# four function definitions

def check():
    val = g1.get()
    if val == 'Africa':
        lbl['image'] = photo1
    elif val == 'America':
        lbl['image'] = photo2
    elif val == 'Asia':
        lbl['image'] = photo3
    elif val == 'Europe':
        lbl['image'] = photo4


f = Frame(win)
group = IntVar()

# four radio buttons
g1 = StringVar()

rdo1 = Radiobutton(win, text='Africa', variable=g1, value='Africa', command=check)
rdo2 = Radiobutton(win, text='America', variable=g1, value='America', command=check)
rdo3 = Radiobutton(win, text='Asia', variable=g1, value='Asia', command=check)
rdo4 = Radiobutton(win, text='Europe', variable=g1, value='Europe', command=check)

rdo1.pack()
rdo2.pack()
rdo3.pack()
rdo4.pack()

rdo1.select()

f.pack()

lbl = Label(win, width=300, height=320, bg='gray', image=photo1)
lbl.pack(side=BOTTOM)
win.mainloop()