inherit "room/room";
reset(arg) {
if(arg) return;
set_light(7);
        short_desc = ("Inside the tower");
long_desc = ("You have entered in a large room.\n"+
"On the north wall there is a red curtain. many paintings are hanging on the wall and\n"+
"the floor is full of animal tracks. There are some vines which\n"+
"are moving silently on the roof pillars. Air is very heavy to breath.\n"+
"There are stairs leading to the next room. odd voices can be heard\n"+
"from the next floor. Torches are emiting light on the wall.\n");
items = allocate(4);
items[0] = "curtain";
items[1] = "Large red curtain is hanging on the northwall. there is lion mark on it and some runes.";
items[2] = "runes";
items[3] = "'Long live the brotherhood of fire and water'";

                add_exit("out" , "/wizards/moonstar/areas/forest/towere.c");
add_exit("up", "/wizards/moonstar/areas/forest/tow2.c");


}
