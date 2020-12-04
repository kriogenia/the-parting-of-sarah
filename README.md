# the-parting-of-sarah
![The Parting of Sarah Logo](https://i.imgur.com/1Q5CbEP.png)

Assingment for the Videogames and Entertainment Software 20/21 subject of the University of Oviedo.

This little project intends to be a very light version of The Binding of Isaac with the player control of Enter the Gungeon. That's it.

The game will feature unlimited floors made with interconnected rooms filled with enemies. Killing those enemies and entering treasure rooms will gain upgrades to the player.
The game will be a complete rogue-like, dying in the game means the lost of all the progress made. Each run is a completely new run.
The goal is to reach the deepest floor you can killing the bosses of each one and getting access to the next one.

The game is developed in C++ only using the SDL2 library for handling audio and grahpics, that's all. Everything else will be pure manfactured C++.

![Screen](https://i.imgur.com/GbZWPSg.jpg)

# Controls

The game is controlled with mouse and keyboard. The mouse is used to aim and shoot and the keyboard to move the character.

* WASD for axis movement
* Mouse Left Click to shoot
* Return to pause the game
* Escape to exit the game
* Key 1 to make the game fullscreen
* Key 2 to replace the character in the room (bug safety measure)
* Key 3 to reset the game

# Mechanics

The objective of the game is reaching the highest possible floor before dying. To complete a floor you need to defeat its boss. Each floor has a peaceful starting room, a peaceful treasure room with an item, a boss room and from three to twenty-one commons rooms filled with basic enemies.

Each time a player enters a non-peaceful room it will need to clear it before beign able to leave it. Defeated enemies will drop coins, collecting five of them will heal the player one heart if they're damaged. Collecting them will power-up the player, giving them a random upgrade to one of the five stats (hp, attack damage, speed, shot cooldown and shot size). 

# Enemies

Currently the game features a total of seven enemies:

* **Bee**, it's a flying ranged enemy who follows and shoots the player within a certain range.
* **Bird**, it's a melee flying enemy that can approach the player very fast.
* **Ghost**, it's a melee flying enemy that goes invisible from time to time.
* **Pig**, it's a melee enemy which goes berserk when hit, gaining speed.
* **Plant**, it's a ranged static enemy who shoots three beans.
* **Raddish**, it's a melee enemy with a lot of health that needs to stop to rest.
* **Stone**, it's a melee enemy that leaves two smaller stones when it diest. Those stones also leave another two smaller ones. Smaller the stone, faster.

# Items

Currently the game features a total of seven items:

* **Banner of Rox Q.**, power-ups the player three times.
* **Gift of An**, gives three extra health and fully heals the player.
* **Green Arrow GRP**, increase the number of projectiles shot by the player (max. 5).
* **Iyanel**, at the cost of one maximum health upgrades all the other stats.
* **Kamespren**, makes the projectiles little and blue, it also increases a lot the shot cadence.
* **Meru's Razor**, multiplies the attack damage, it's not affected by the cap.
* **Shield of Xur**, will block a hit each 16s. Picking it up again will reduce the cooldown 1s.


# Resources

Almost all the graphic and sound assets of the game are from third-party creative common sources. I modified some of it but the big work is not mine.

* Basic enemies: https://pixelfrog-store.itch.io/pixel-adventure-2
* Boss theme: https://freesound.org/people/Sirkoto51/sounds/352171/
* Crosshair: https://opengameart.org/content/crosshair-pack-200%C3%97
* Main character: https://gamekrazzy.itch.io/8-direction-top-down-character
* Main theme: https://freesound.org/people/FoolBoyMedia/sounds/264295/
* Tileset: https://scut.itch.io/7drl-tileset-2018
* Wall: https://o-lobster.itch.io/simple-dungeon-crawler-16x16-pixel-pack
* Sources of some sprites: 
  * https://ansimuz.itch.io/patreons-top-down-collection
  * https://pixel-poem.itch.io/dungeon-assetpuck
  * https://uilleaggodwin.itch.io/roguelike-dungeon-asset-bundle