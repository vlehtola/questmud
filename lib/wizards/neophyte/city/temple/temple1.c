inherit "room/room";
object guard,sign;
reset (arg) {
if (arg) { return; }
    add_exit("north","temple2");
    add_exit("south","/wizards/neophyte/city/navigator2");
        short_desc = "Entrance to temple of light";
        long_desc = "You are standing front of the temple. In here is a two tall pillars\n"+
                    "bouth side of the massive iron gates. Walls are made of grey rocks\n"+
                    "and they have only a couple simple decorations on them, The sun and a moon.\n"+
                    "windows are little opened and they are made to look colourfull with these\n"+
                    "images on them. Silent prayers can be heard inside the temple.\n";
               items = allocate(6);
               items[0] = "walls";
               items[1] = "walls have allkinds of decorations on them, demons to gods";
               items[2] = "windows";
               items[3] = "All the windows are moustly red, only a little yellow on them";
               items[4] = "gates";
               items[5] = "A massive looking iron gates";
}
