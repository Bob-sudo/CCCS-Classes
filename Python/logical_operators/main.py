temp = -5
is_raining = False
is_sunny = True

if temp > 35 or temp < 0 or is_raining:
    print("The outdoor event is cancelled")
else:
    print("The outdoor event is still scheduled")
    
if temp >= 28 and is_sunny:
    print("It is HOT outside")   
elif temp <= 0 and is_sunny:
    print("It is COLD outside")  
elif 28 > temp > 0 and is_sunny:
    print("It is WARM outside")
    
if is_sunny:
    print("It is SUNNY")
else:
    print("It is CLOUDY")



