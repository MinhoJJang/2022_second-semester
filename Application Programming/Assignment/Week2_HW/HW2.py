# 자동판매기 프로그램
# 202033762 장민호

won_500 = 500
won_500_total = 0
won_100 = 100
won_100_total = 0

inputMoney = int(input("투입한 돈: "))
price = int(input("물건 값: "))
change = inputMoney - price

won_500_total = int(change / won_500)
won_100_total = (change - (won_500_total * won_500)) / won_100

print("*** 거스름돈 %d 원 ***"%change)
print("500원 동전의 개수는 %d개이고, 100원 동전의 개수는 %d개이다." % (won_500_total, won_100_total))

