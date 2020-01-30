inherit "room/room";
object monster;
reset(arg) {
if(arg) return;
  if (!monster) {
        monster = clone_object("/wizards/nalle/area/monsters/phantomlord");
        move_object(monster, this_object());
    }
add_exit("up", "/wizards/nalle/area/towerd3");
short_desc = "A large room";
long_desc = "This part of the tower is no longer completely dark. There are torches\n"+
            "burning on the walls, making it possible to see. The room is furnished\n"+
            "with a blood red throne and a long oaken table. There are some silver\n"+
            "plates and goblets on the table, some of them are still full.\n";
set_not_out(1);
set_light(3);
}
