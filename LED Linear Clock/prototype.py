import pygame
from pygame.locals import *
from time import localtime, strftime

pygame.init()
fpsClock = pygame.time.Clock()
windowSurf = pygame.display.set_mode((200,480))
pygame.display.set_caption("Liner LED Clock")
windowW = windowSurf.get_width()
windowH = windowSurf.get_height()


redCol = pygame.color.Color(255,0,0)

running = True
while running:
    windowSurf.fill((0,0,0))
    now = strftime("%I:%M:%S" , localtime()).split(":")


    ## Hour LEDs
    for i in range(12):
        #                 surface    , col   , centre         , radius,width)
        pygame.draw.circle(windowSurf, redCol, ( 50,20+i*35 ) , 15    , 5   )
        if int(now[0]) == i:
            pygame.draw.circle(windowSurf, redCol, ( 50,20+i*35 ) , 15)
    
    ## Minute LEDs
    for i in range(12):
        min = int(now[1])
        pygame.draw.circle(windowSurf, redCol, ( 150,20+i*35 ) , 15    , 5   )
        if ( (min >= i*5) and (min < (i+1)*5) ):
            alpha = int( (1- min%5/5) * 255)
            #print("a1=",alpha)
            pygame.draw.circle(windowSurf, (255,0,0,alpha), ( 150,20+i*35 ) , 15)
            alpha = int(((min%5)/5)*255)
            #print("a2=",alpha)
            pygame.draw.circle(windowSurf, (255,0,0,alpha), (150, 20+(i+1)*35), 15)
            #alpha not working because I need to draw on a surf and set alpha of that
            #printed alpha values to test values is enough for POC
    # In actual set up I'd pass the minutes into a function that'd calculate which LEDs to put on from an array.


    
    pygame.display.update()
    fpsClock.tick(30)
    for event in pygame.event.get():
        if event.type == QUIT:
            pygame.quit()
            running = False
        elif event.type == KEYDOWN:
            if event.key == K_ESCAPE:
                pygame.quit()
                running = False
        