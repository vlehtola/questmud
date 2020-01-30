inherit "room/room";

reset(arg)
{
if(arg) return;
add_exit("north","wizards/adrigon/cavenborough/cavendel/road2.c");
add_exit("south","wizards/adrigon/cavenborough/cavendel/citygate.c");
add_exit("west","wizards/adrigon/cavenborough/cavendel/weststaird.c");
add_exit("east","wizards/adrigon/cavenborough/cavendel/eaststaird.c");
        
short_desc = "Southern part of the main street";
long_desc = 
"As your eyes adjust to the light after the citygate you notice the broad and\n" +
"and crowded main street of the Cavendel starting here. High citywalls are on\n" +
"the both sides of the street. Open doorway leads in both of the walls.\n" +
"As you peek inside the doorways you notice steep and wooden staircase going up.\n"; 

items = allocate (4);
items[0] = "walls";
items[1] = "Citywall look old but somehow durable as the age hasn't diminished\n" +
           "it's grandeur. Skillfully carved granite blocks have been used in\n" +
           "building this enormous masterpiece of masonry ahead of you.\n";
items[2] = "doorway";
items[3] = "Ornated and capped doorways are on the wall to east and west from\n" +
           "you.\n";

}