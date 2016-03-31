# Activity: Project 2 Reservoir Height Analysis
# File:     PHW01_walke333.py
# Date:     30 March 2016
# By:       Joshua Walker
#           walke333
#
# Section:  03
# Team:     42
#
# ELECTRONIC SIGNATURE
# Joshua Walker
#
# The electronic signature above indicates that the program
# submitted for evaluation is my individual work. I have
# a general understanding of all aspects of its development
# and execution.
#
# This program tells the user the cost of building a wall
# and preparing the land in zone 1 for any given volume
# for some set reservoir depths


#Close enough approximation of pi
PI = 3.14159

#Price per meter of perimeter to build wall, key is height, values is price
heightCosts = {5:30, 7.5:60, 10:95, 12.5:135, 15: 180, 17.5:250, 20:340}

#Price in dollers per meter squared of land to clear
clearCost = 0.25

#Volume of water to hold
#No Error checking
volume = float(input("Please input the volume of the reservoir: "))


#Corresponding surface areas for each height
#Surface area = volume / height
surfaceAreas = {height: volume / height for height in heightCosts}

#Radius = sqrt(Surface Area / Pi)
radii = {height: (surfaceAreas[height] / 3.14159) ** 0.5
         for height in heightCosts}

#Perimeter = 2 * pi * Radius
perimeters = {height: 2 * radii[height] * 3.14159
              for height in heightCosts}

#Cost to clear land = clearCost * Surface Area
clearCosts = {height: clearCost * surfaceAreas[height]
              for height in surfaceAreas}

#Cost of Wall = perimeter * (Price / meter)
wallCosts = {height: perimeters[height] * heightCosts[height]
             for height in perimeters}

#Print total cost for each height, unordered
for height in heightCosts:
    print ("Height=", height, end = "")
    print("\tTotal cost=",clearCosts[height] + wallCosts[height])
print()

#Print indiviual wall and clear cost, unordered
for height in heightCosts:
    print("height=" , height , "\tCost of clearing land=", end = "")
    print(round(clearCosts[height], 1), "Wall=",wallCosts[height])

print()


