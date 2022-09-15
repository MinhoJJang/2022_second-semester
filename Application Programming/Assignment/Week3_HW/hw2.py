# -(슬라이드 28) Homework 2: 사용자로부터 아이디를 입력 받아서 저장된 아이디와 일치하면 사용자로부터 비밀번호를 입력 받아 저장된 비밀번호와 일치하는지 여부를 출력하세요.(hw2.py)

admin_id = "lovePython!"
admin_pw = "p12345"

id = input("아이디를 입력하세요: ")
if id != admin_id :
    print("아이디를 찾을 수 없습니다.")
elif id == admin_id :
    pw = input("비밀번호를 입력하세요: ")
    if pw != admin_pw :
        print("비밀번호가 틀립니다.")
    elif pw == admin_pw:
        print("lovePython!님 환영합니다~!!")