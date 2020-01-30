inherit "room/room";
int i;
reset(arg) {
  i = random(21);
  if(arg) return;
  set_light(8);
  short_desc = "The vortex of gods";
if(i == 0) { long_desc =
"########### This is the Central Square of Duranghom between the\n"+
"# B  |  P # Mainstreet and Gold street. This crowdy square is\n"+
"#-+--*--+-# crowded almost around the clock as the merchants\n"+
"# I  |  Ba# keep their selling booths open all the time. Travellers\n"+
"########### passing through the city stop here to ask advise and to\n"+
"buy food. A few beggars beg for food in the corners of the square.\n"+
"The guards patrol here looking for criminals and pick-pockets.\n"+
"Better keep an eye at your money.\n";
}

if(i == 1) { long_desc =
"The inn of Duranghom is full of people from every part of Deleria.\n"+
"Above you lies a thick smoke, which makes the light coming from the\n"+
"candles and the fireplace dimmer. You feel comfortable warmth coming\n"+
"from the fireplace, situated on the southeast corner of the hall.\n"+
"Bards are playing happy music, which fills your ears and makes\n"+
"you feel safer than outside.\n"+
"\n"+
"    Use 'safe_quit' to save 5 items.\n"+
"\n"+
"There is a glowing corridor leading to the south.\n";
}

if(i == 2) { long_desc =
"The apprentice Mage guild hall.\n"+
"This is the guild where all Essence casters start their search for\n"+
"power. There are book shelves full of books on the sides of the hall.\n"+
"Five long shelves labelled 'Spellbooks' seem to attract attention.\n"+
"The place is well lit with some strange lamps that are hanging\n"+
"from the ceiling and glowing bright magical light.\n"+
"The streets of Duranghom lie to the east.\n";
}

if(i == 3) { long_desc =
"########### You are on Emerald street next to the Mainstreet street of\n"+
"# A  |    # Duranghom. This street is home to most of the rich\n"+
"#  We*    # people of Duranghom. The Mainstreet of Duranghom is located\n"+
"#    |    # just south of here. This old street has all kinds of shops\n"+
"########### scattered to each side of the street. The old-traditioned\n"+
"weapon smith's shop is located just west of here.\n";
}

if(i == 4) { long_desc =
"This building is the famous Fighter guild of Duranghom, the place where\n"+
"all adventurers who seek hand-to-hand combat training, come. The streets\n"+
"of Duranghom lie to the east.\n";
}

if(i == 5) { long_desc =
"The bar side of the tavern is full of people. The atmosphere is really warm\n"+
"and people are singing happily while drinking beer. There is also a small band\n"+
"playing music and a fireplace which is warming the room. You feel yourself very\n"+
"comfortable here mostly because the strange smoke which makes you feel happy.\n"+
"You could buy some beer from the counter.\n";
}

if(i == 6) { long_desc =
"The noises and the worries of the city seem to leave you as you stand here\n"+
"looking in at the graveyard. The graveyard radiates a calming breeze that\n"+
"that makes you feel quite at home. You can see lines of graves up ahead,\n"+
"and some bigger tombs that stand tall as small houses. There are gates that\n"+
"lead to the cemetary.\n";
}

if(i == 7) { long_desc =
"www  People call this Wasteland.\n"+
"w*w  There are dead trees everywhere. The earth is covered with\n"+
"^ww  dust. Few rocks lie on the ground making it look\n"+
"     more deserted. The everlasting darkness remains here.\n";
}

if(i == 8) { long_desc =
"Green garden with many different plants. Ground is full of\n"+
"different footsteps. Flowers bloom in many different colors and\n"+
"voices of different animals can be heard nearbye.\n";
}

if(i == 9) { long_desc =
"#ss  You stand on a large courtyard. The ground is sandy.\n"+
"G*s  Fortress has two strong walls. Behind the fortress\n"+
"#sf  is the insurmountable mountains. Huge gate is in west.\n"+
"     In the middle of the courtyard is high building which\n"+
"     is called the Tower of Blue Light.\n"+
"     Near the tower is small garden.\n";
}

if(i == 10) { long_desc =
"You are now top of the tower.\n"+
"There are ladders leading down and many candles are burning on the north wall.\n"+
"There are no roof anymore or somehow sky is now over you and stars are watching you.\n"+
"It's very cold and water is dropping everywhere.\n"+
"This is master Krazzt workroom.\n"+
"There is a small waterfall on the northwall and small pool in\n"+
"the middle of the room. Something is rising out from the the pool.\n"+
"Many owls are flying in the sky and strong blue light is goming out from the pool.\n";
}

if(i == 11) { long_desc =
"You are now in the fourth floor of the tower.\n"+
"There are stairs leading to the fifth floor.\n"+
"This floor seems to be same size as third floor.\n"+
"Many candles are burning on the north wall\n"+
"and there is no roof anymore or somehow sky is\n"+
"over you. It's very cold and water is dropping\n"+
"everywhere. Strong wind has broke all the windows.\n"+
"The whole place seems to be shaking. There are\n"+
"huge footsteps on the ground. This is the home of the\n"+
"water lords who are the highest soldiers of master Krazzt.\n"+
"Many plants and vines are rising from the ground and\n"+
"the whole floor is filled on mud.\n";
}

if(i == 12) { long_desc =
"You have entered a small, cosy looking room. There\n"+
"is a beautiful brown carpet on the floor and some\n"+
"weird looking paintings are hanged on the walls.\n"+
"A fluffy looking bed with beautiful decorations is\n"+
"placed in the corner and there is a small desk next\n"+
"to the bed.\n";
}

if(i == 13) { long_desc =
"You are walking in a gloomy looking dungeon\n"+
"inside the city well. The place is very wet and there\n"+
"are many spider webs everywhere, walls are made of some\n"+
"unknown dark material and there are no visible light sources\n"+
"anywhere near. You can hear some horrible screams coming\n"+
"from deeper, this surely is not a good place for anyone.\n";
}

if(i == 14) { long_desc =
"You are in the second floor of the house, there are toys\n"+
"everywhere around you and other stuff that kids\n"+
"use when they play their silly games. You can see a\n"+
"huge mansion rising towards the sky when you look out\n"+
"of the window. Wooden stairs are leading downstairs\n"+
"nearby.\n";
}

if(i == 15) { long_desc =
"On the sixth floor of the Demon Tower.\n"+
"The room looks shocking. Most of the killed guards have been dragged here.\n"+
"There is guards nailed on the walls, and those which are laying on the floor\n"+
"are waiting for their turn to be nailed up. Some of the guards laying on the\n"+
"floor are still alive and groaning in agony. No one can help these cursed souls\n"+
"anymore. There is human blood everywhere. The stench is unbelievably horrible.\n"+
"Room gets its illumination from the corpses on the walls. The glowing stones\n"+
"have been pierced through these poor guards. The captain of the guards has been\n"+
"separated from the normal castle guards. His stomach has been penetrated with a\n"+
"big-sized glowing stone, and his bowels have fallen on the rock, making the\n"+
"glow less bright. There is a hole in the ceiling in north.\n";
}

if(i == 16) { long_desc =
"Climbing at a small hill.\n"+
"The hillside is untouched, making the advancing quite hard. There\n"+
"are some gaping openings where more bright red light is entering the\n"+
"room. There are also some radiating, and normal, stones sticking out\n"+
"of the ground, dramatically rising the possibility of falling down\n"+
"on one of them and breaking your skull. In spite the danger, the hill\n"+
"is a work of art with its chaotical symmetry and soothing bright stones.\n";
}

if(i == 17) { long_desc =
"########### You are on Fire street crossing Silver street running north-\n"+
"#TTTWWWW  # south. These street are homes to most of the travellers and\n"+
"#-+--* W  # citizens of Duranghom. These streets are mostly filled with\n"+
"#    | WWW# high and good quality houses in which the travellers can spend\n"+
"########### the night and where the citizens live. Gold Street is located\n"+
"some distance in west and Emerald street is much to the west. The Main-\n"+
"street of Duranghom is located some distance in south.\n";
}

if(i == 18) { long_desc =
"You're standing in the woods or Moraloth, also known as the\n"+
"haunted forest. It has been said these woods have been damned\n"+
"from the beginning of time. There is only faint light coming\n"+
"through the branches. It would be easy to get lost in this\n"+
"kind of place. The ancient trees seem older than anything\n"+
"you've seen before. There is absolutely no voice.\n";
}

if(i == 19) { long_desc =
"You have entered the ogre fortress. The crude language of ogres can be\n"+
"heard everywhere. Some shopkeepers are trying to sell their stuff here\n"+
"and it seems that guards patrol around here regularly. Here aren't any other\n"+
"full-grown males here though. The buildings around this place are ugly and\n"+
"the ground is muddy. The road splits here, and it leads to northeast and\n"+
"to northwest.\n";
}

if(i == 20) { long_desc =
"The throne room of mighty ogre king, Tahn'garth. A huge banner is\n"+
"placed behind the throne. Throne is made of oak and decorated\n"+
"with gold and silver. A red velvet carpet is placed on the floor.\n";
}
  add_exit("east", "/wizards/moonstar/areas/asgroth/bazaar/4.c");
  add_exit("northeast", "/wizards/moonstar/areas/asgroth/bazaar/11.c");
    add_exit("southeast", "/wizards/moonstar/areas/asgroth/bazaar/17.c");
}
