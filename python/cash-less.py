from cs50 import get_float
# declarando constantes
change = 0
count = 0
# se valida si el cambio es un numero positivo
while change <= 0:
    change = get_float("Change owed: ")
    cents = round(change * 100)
# define el valor de centavos, dimes etc...
coin_values = [25, 10, 5, 1]
# itera solbre el valor de cada moneda
for coin in coin_values:
    while cents >= coin:
        # resta el valor de la moneda del cambio restante
        cents -= coin
        #itera
        count += 1

print(count)
