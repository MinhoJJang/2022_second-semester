moneyInfo = { "미국":(1180.50, "달러"), "영국":(1570.13, "파운드"), "러시아":(15.01, "루블"), "중국":(173.93, "위안")}

def calc_money(n, m) :
    
    price = moneyInfo.get(n)
    if(price == None):
        print("국가를 잘못 입력했습니다.")
    else :
        print("{0}(원)을 {1:0.2f}({2})로 교환합니다.".format(m,m/price[0],price[1]))

money = 0 #금액
nation = 0 #국가
try:
    money = int(input("환전하려는 금액(원) : "))
except:
    print( "금액은 숫자로 입력하세요.")
else:
    nation = input("국가(미국/영국/러시아/중국) : ")
    calc_money(nation, money)
    # 함수 호출