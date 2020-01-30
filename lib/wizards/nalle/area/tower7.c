inherit "room/room";
object monster;
reset(arg) {

if(arg) return;
    if (!monster) {
      monster = clone_object("/wizards/nalle/area/monsters/alevric");
      move_object(monster, this_object());

}

add_exit("up","/wizards/nalle/area/tower8");
add_exit("down","/wizards/nalle/area/tower6");
short_desc = "The 7th floor, Alevric's room";
long_desc = "This is where Alevric, Darvox's main apprentice spends his free time. \n" +
            "The room is simply furnished but a majestic stairway leads up, into \n" +
            "Darvox's room. \n";

    items = allocate(2);
    items[0] = "stairway";
    items[1] = "The stairway leads up into Darvox's quarters";
}
