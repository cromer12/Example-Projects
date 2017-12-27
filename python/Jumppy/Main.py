#pygame template
import pygame as pg
import random
import time
from settings import *
from Spirtes import *

class Game:
    #Intilize all values#
    def __init__(self):
        # Starts game window etc
        self.running = True

        # starts pygame and its sound options
        pg.init()
        pg.mixer.init()

        # basics of a window initilzation and clock creation
        self.screen = pg.display.set_mode((WIDTH, HEIGHT))
        pg.display.set_caption(TITLE)
        self.clock = pg.time.Clock()
        self.font_name = pg.font.match_font(FONT_NAME)

    #Starts new Game#
    def new(self):
        # Restarts Game#
        self.all_sprites = pg.sprite.Group()
        self.platforms = pg.sprite.Group()
        self.powerups = pg.sprite.Group()
        self.player = Player(self)
        self.all_sprites.add(self.player)
        self.score = 0
        self.ispower = False

        #Platform creation at start
        for plat in PLATFORM_LIST:
            p = Platform(*plat, GREEN, self)
            self.all_sprites.add(p)
            self.platforms.add(p)

        self.run()

    #Game Loop#
    def run(self):
        #Game Loop
        self.playing = True
        while self.playing:
            self.clock.tick(FPS)
            self.events()
            self.update()
            self.draw()

    #Checks for events#
    def events(self):
        #Game Loop - Events
        # Process input (events)
        for event in pg.event.get():
            # CLOSE
            if event.type == pg.QUIT:
                if self.playing:
                    self.playing = False
                    self.running = False
                    pg.quit()

            if event.type == pg.KEYDOWN:
                if event.key == pg.K_SPACE:
                    self.player.jump()

    #Updates the screen#
    def update(self):
        #Game Loop - Update#
        self.all_sprites.update()

        #Pygame functoin to check for collision betweeen 'player' and 'platforms'#
        hits = pg.sprite.spritecollide(self.player, self.platforms, False)
        if self.player.vel.y > 0:
            #If hits is true, set player's Y position to the top of the platforms rectangle position.
            if hits:
                self.player.pos.y = hits[0].rect.top + 1
                #Removes Gravity whlie in contact with platform#
                self.player.vel.y = 0
                if self.score > LEVELONE:
                    self.player.pos.x += 1
                if self.score > LEVELTWO:
                    self.player.pos.x += 2
                if self.score > LEVELTHREE:
                    self.player.pos.x += 3

        #player reaches top 1/4 of screen
        if self.player.rect.top <= HEIGHT /4:
            self.player.pos.y += abs(self.player.vel.y)
            for plat in self.platforms:
                plat.rect.y += abs(self.player.vel.y)
                if plat.rect.top >= HEIGHT:
                    plat.kill()
                    self.score += 10
            for power in self.powerups:
                power.rect.y += abs(self.player.vel.y)
                if power.rect.y >= HEIGHT:
                    power.kill()
                    self.ispower = False
        #Game Over
        if self.player.rect.bottom > HEIGHT:
            for sprite in self.all_sprites:
                sprite.rect.y -= max(self.player.vel.y, 10)
                if sprite.rect.bottom < 0:
                    sprite.kill()
                if len(self.platforms) == 0:
                    self.playing = False

        hits = pg.sprite.spritecollide(self.player, self.powerups, True)
        if hits:
            self.liftoff()
            self.ispower = False

        #Spawn new platforms to replace old#
        while len(self.platforms) < 8 and self.score < 3000:
            width = random.randrange(50, 100)
            color = BLACK
            p = Platform(random.randrange(0, WIDTH - width), random.randrange(-100, -30), width, 20, color, self)
            #gens new platforms#
            if self.score <= 500:
                p = p.gen_plat1()
            if self.score <= 2000 and self.score > 500:
                p = p.gen_plat2()
            if self.score > 2000:
                p = p.gen_plat3()
            #adds it to sprite group#
            self.platforms.add(p)
            self.all_sprites.add(p)

            #randomizes the spawn of powerups#
            powchance = random.randrange(0, 45)
            #checks to see if there is one on screen and if there isnt, there is the possiblity to spawning one#
            if self.ispower == False:
               if powchance == 3:
                    power = Powerup(random.randrange(0, WIDTH - width), random.randrange(-100, -30), self)
                    self.all_sprites.add(power)
                    self.powerups.add(power)
                    self.ispower = True

        while len(self.platforms) < 8 and self.score > 3000:
            width = random.randrange(50, 100)
            color = BLACK
            p = Platform(random.randrange(0, WIDTH - width), random.randrange(-100, -30), width, 20, color, self)
            # gens new platforms#
            p.gen_plat2()
            # adds it to sprite group#
            self.platforms.add(p)
            self.all_sprites.add(p)

            # randomizes the spawn of powerups#
            powchance = random.randrange(0, 45)
            # checks to see if there is one on screen and if there isnt, there is the possiblity to spawning one#
            if self.ispower == False:
                if powchance == 3:
                    power = Powerup(random.randrange(0, WIDTH - width), random.randrange(-100, -30), self)
                    self.all_sprites.add(power)
                    self.powerups.add(power)
                    self.ispower = True


    #Flips the screen#
    def draw(self):
        #Game Loop - Draw
        # Draw / Render
        self.screen.fill(BGCOLOR)
        self.all_sprites.draw(self.screen)
        self.draw_text(str(self.score), 22, WHITE, WIDTH / 2, 20)
        pg.display.flip()

    #Start Screen
    def show_start_screen(self):
        #Start screen
        self.screen.fill(BGCOLOR)
        #draws text to screen and waits for input to start
        self.draw_text(TITLE, 48, WHITE, WIDTH / 2, HEIGHT / 4)
        self.draw_text("Arrow to move, Space to jump", 22, WHITE, WIDTH / 2, HEIGHT / 2)
        self.draw_text("Press a key to play", 22, WHITE, WIDTH / 2, HEIGHT * 3 / 4)
        pg.display.flip()
        self.wait_for_key()



    #Gameover Screen
    def show_go_screen(self):
        #Start screen
        self.screen.fill(BLACK)
        #draws text to screen and waits for input to start
        self.draw_text("You have fell to Earth without ever reaching the Moon", 22, WHITE, WIDTH / 2, HEIGHT / 2)
        self.draw_text("Press a key to restart", 22, WHITE, WIDTH / 2, HEIGHT * 3 / 4)
        pg.display.flip()
        self.wait_for_key()


    def wait_for_key(self):
        waiting = True
        while waiting:
            self.clock.tick(FPS)
            for event in pg.event.get():
                if event.type == pg.QUIT:
                    waiting = False
                    self.running = False
                    pg.quit()
                if event.type == pg.KEYUP:
                    waiting = False


    def draw_text(self, text, size, color, x, y):
        font = pg.font.Font(self.font_name, size)
        text_surface = font.render(text, True, color)
        text_rect = text_surface.get_rect()
        text_rect.midtop = (x, y)
        self.screen.blit(text_surface, text_rect)

    def liftoff(self):
        t = time.time() + 6
        while time.time() < t:
            self.player.vel.y = -2
            self.player.vel.x = 0
            self.update()
            self.draw()
        px = self.player.pos.x
        pz = self.player.pos.y
        p = Platform(px - 25, pz + 50, 50, 20, WHITE, self)
        self.platforms.add(p)
        self.all_sprites.add(p)





#Call a new game
g = Game()
#Show start screen
g.show_start_screen()
#Begins game
while g.running:
    #Calls new in Game Class
    g.new()
    #Calls gameover
    g.show_go_screen()

pg.quit()