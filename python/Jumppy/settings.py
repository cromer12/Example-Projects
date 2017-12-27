#TITLE
TITLE = "To The Moon"
#Screen Constants
WIDTH = 660
HEIGHT = 850
FPS = 60
FONT_NAME = 'arial'

#Player Properties
PLAYER_ACC = 0.7
PLAYER_FRICTION = -0.12
PLAYER_GRAV = 0.6
PLAYER_JUMP = -23.5

#Starting Platforms
PLATFORM_LIST = [(0, HEIGHT - 40, WIDTH, 40),
                 (WIDTH / 2 - 50, HEIGHT * .75, 100, 20),
                 (125, HEIGHT - 350, 100, 20),
                 (350, 200, 100, 20),
                 (150, 100, 50, 10)]

#SCORE LEVELS
LEVELONE = 600
LEVELTWO = 800
LEVELTHREE = 1000


#Colors
WHITE=(255, 255, 255)
BLACK=(0, 0, 0)
RED=(255, 0, 0)
GREEN=(0, 255, 0)
BLUE=(0, 0, 255)
YELLOW=(255, 255, 0)
PURPLE=(255, 0, 255)
CYAN=(0, 255, 255)
LIGHTBLUE =  (0, 155, 155)
BGCOLOR = LIGHTBLUE