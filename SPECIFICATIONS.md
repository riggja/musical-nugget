## UML Diagram
![Draft](https://preview.c9users.io/mamatt/cptr142_group_project/cptr142_group_project/StarWarsPong.png?_c9_id=livepreview0&_c9_host=https://ide.c9.io)

## Procedural Flow Diagram
* Welcome Screen -> 1 Player / 2 Player / Exit
    * 1 Player / 2 Player -> Options (Determines time)
    * Options -> Game Duration / Maximum Points
        * Scoreboard -> Player 1 Points / Player 2 Points / Timer
        * Paddles -> move vertically 
        * "Ball" -> bounces off paddles and bottom and top of screen / adds one to the scoreboard when it goes off the left and right sides of the screen
        * Timer -> If Exceeds Parameter given by Options -> Endgame Screen
* Endgame Screen -> show winner and points
* Exit -> Elegantly Crashes To Desktop

## Anticipated Challenges
* Physics
    * Paddle Force Distribution
    * Angular Momentum
    * Graphics
    * Getting SFML to play nicely with Cloud9

## Project Management Plan

__Individual Tasks / Responsibilities__

* Cameron
    * Project Manager
    * AI Manager
    * Voice of Unrealistic Aspirations
    * Head Prototyper

* Jason
    * Lead Aesthetic Designer
    * Developer of Tests
    * Code Refactorer

* Matthew
    * Director of Group Planning
    * Researcher
    * Voice of Dissent

__Timelines__

* 3/1: Displaying Title Screen / Ability to Navigate between Screens
    * Jason will work on sound and art 
    * Matthew will work on screen transitions
* 3/5: Working Prototype
    * Cameron will work on AI 
    * Matthew will work on physics for the ball
    * Jason will work on art and help with testing 
* 3/10: Powerups / Unnecessarily Lucrative Addons
    * at this point the basic game should be done
    * All of us will work on the addition of extra addons