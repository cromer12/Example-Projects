#Sprites for Game
from settings import *
import pygame as pg
import os
import random
vec = pg.math.Vector2

#folder paths: assets#
#__file__ tracks file)#
game_folder = os.path.dirname(__file__)
img_folder = os.path.join(game_folder, "img")


class Player(pg.sprite.Sprite):

    def __init__(self, game):

        #Require to use spirite#
        pg.init()
        pg.sprite.Sprite.__init__(self)
        #Reference for the game#
        self.game = game
        #counter for walk
        self.counter = 0
        #Drawing Space#
        self.image = pg.image.load(os.path.join(img_folder, "p1_stand.png")).convert()
        #Removes black from background#
        self.image.set_colorkey(BLACK)

        #Fills space with color#
        #self.image.fill(YELLOW)#

        #Covers sprite in a rectangle#
        self.rect = self.image.get_rect()
        #Centers sprite on screen#
        self.rect.center = (WIDTH / 2, HEIGHT / 2)

        #starting position
        self.pos = vec(WIDTH / 2, HEIGHT / 2)
        self.vel = vec(0, 0)
        self.acc = vec(0, 0)

    def jump(self):
        #Jump#
        #checks for footing to Jump#
        self.rect.y += 1
        #checks for collisions#
        hits = pg.sprite.spritecollide(self, self.game.platforms, False)
        if hits:
            #returns to nomral position
            self.rect.y -= 1
            #Jump#
            self.vel.y = PLAYER_JUMP

    def update(self):

        #Resets acc at each loop#
        self.acc = vec(0, PLAYER_GRAV)

        #Var holding key presses#
        keys = pg.key.get_pressed()

        #Checks for left key downpress#
        if keys[pg.K_LEFT]:
            self.acc.x = -PLAYER_ACC

        #Checks for right key downpress#
        if keys[pg.K_RIGHT]:
            self.acc.x = PLAYER_ACC

        #Apply Friction#
        self.acc.x += self.vel.x * PLAYER_FRICTION

        # Moves Sprite#
        self.vel += self.acc
        self.pos += self.vel + 0.5 * self.acc

        #Wrap Sprite#
        if self.pos.x > 30 + WIDTH:
            self.pos.x = -30
        if self.pos.x < -30:
            self.pos.x = WIDTH + 30


        #Changes Animations for jump
        if self.vel.y < 0:
            self.image = pg.image.load(os.path.join(img_folder, "p1_jump.png")).convert()
            self.image.set_colorkey(BLACK)
            self.counter = 0
        else:
            self.image = pg.image.load(os.path.join(img_folder, "p1_stand.png")).convert()
            # Removes black from background#
            self.image.set_colorkey(BLACK)

        #change animation for walking
        if self.vel.x > 2 or self.vel.x < -2:
            self.image = pg.image.load(os.path.join(img_folder, "p1_walk03.png")).convert()
            self.image.set_colorkey(BLACK)
            self.counter += 1
        if self.counter > 10:
            self.image = pg.image.load(os.path.join(img_folder, "p1_walk02.png")).convert()
            self.image.set_colorkey(BLACK)
            self.counter += 1
        if self.counter > 20:
            self.counter = 0

        if self.pos.x > 30 + WIDTH:
            self.pos.x = -30
        if self.pos.x < -30:
            self.pos.x = WIDTH + 30

        #Relocates spite's rectangle#
        self.rect.midbottom = self.pos


class Platform(pg.sprite.Sprite):
    def __init__(self, x, y, w, h, color, game):
        pg.sprite.Sprite.__init__(self)
        self.game = game
        self.image = pg.Surface((w,h))
        self.width = w
        color = color
        self.image.fill(color)
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y
        self.vel = vec(1, 0)

    def gen_plat1(self):
        #gens the plat again bc rng
        width = random.randrange(50, 100)
        color = GREEN
        p = Platform(random.randrange(0, WIDTH - width), random.randrange(-175, -30), width, 20, color, self.game)
        #COLLISION CHECKS
        hits = pg.sprite.spritecollide(p, self.game.platforms, True)
        #Runs until no collision detected
        while hits:
            p = Platform(random.randrange(0, WIDTH - width), random.randrange(-175, -30), width, 20, color, self.game)
            hits = pg.sprite.spritecollide(p, self.game.platforms, True)
        #gives the new plat
        return p

    def gen_plat2(self):
        #gens the plat again bc rng
        width = random.randrange(50, 75)
        color = BLUE
        p = Platform(random.randrange(0, WIDTH - width), random.randrange(-175, -30), width, 15, color, self.game)
        #COLLISION CHECKS
        hits = pg.sprite.spritecollide(p, self.game.platforms, True)
        #Runs until no collision detected
        while hits:
            p = Platform(random.randrange(0, WIDTH - width), random.randrange(-175, -30), width, 15, color, self.game)
            hits = pg.sprite.spritecollide(p, self.game.platforms, True)
        #gives the new plat
        return p

    def gen_plat3(self):
        #gens the plat again bc rng
        width = random.randrange(25, 50)
        color = RED
        p = Platform(random.randrange(0, WIDTH - width), random.randrange(-175, -30), width, 10, color, self.game)
        #COLLISION CHECKS
        hits = pg.sprite.spritecollide(p, self.game.platforms, True)
        #Runs until no collision detected
        while hits:
            p = Platform(random.randrange(0, WIDTH - width), random.randrange(-175, -30), width, 10, color, self.game)
            hits = pg.sprite.spritecollide(p, self.game.platforms, True)
        #gives the new plat
        return p

    def update(self):
        if self.game.score > LEVELONE:
            self.rect.midbottom += self.vel
            if self.rect.x > WIDTH + self.width / 2:
                self.rect.x = -self.width

        if self.game.score > LEVELTWO:
            self.vel.x = 2
            self.rect.midbottom += self.vel
            if self.rect.x > WIDTH + self.width / 2:
                self.rect.x = -self.width

        if self.game.score > LEVELTHREE:
            self.vel.x = 3
            self.rect.midbottom += self.vel
            if self.rect.x > WIDTH + self.width / 2:
                self.rect.x = -self.width


class Powerup(pg.sprite.Sprite):
    def __init__(self, x, y, game):
        pg.sprite.Sprite.__init__(self)
        self.game = game
        self.image = pg.image.load(os.path.join(img_folder, "powerup.png")).convert()
        self.image.set_colorkey(BLACK)
        self.rect = self.image.get_rect()
        self.rect.x = x
        self.rect.y = y

    def give_power(self):
        powchance = random.randrange(0, 50)
        width = random.randrange(50, 100)
        if powchance == 3:
            power = Powerup(random.randrange(0, WIDTH - width), random.randrange(-100, -30), self.game)
            return power
        else:
            return 0

