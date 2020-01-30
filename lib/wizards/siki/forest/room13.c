inherit "room/room";
object mob;
string *mobsters;
reset(arg) {
	mobsters = ({ "/wizards/siki/forest/monsters/bear","/wizards/siki/forest/monsters/deer","/wizards/siki/forest/monsters/rabbit","/wizards/siki/forest/monsters/wolf",});
        if(!mob) {
        mob = clone_object(mobsters[random(4)]);
        move_object(mob, this_object());
        }
        if(arg) return;
        add_exit("north","room12");
        add_exit("east","room14");
        short_desc = "A twisted crossing of the path's";
  long_desc = "The path is turning here to the north and east.\n"+
              "The path looks twisted and it is full of rotting things. Both side of this path\n"+
              "there is a floating purple mist, which is little strange because the path is\n"+
              "clear of it. A demonical roaring sound can be heard here clearly and it seems\n"+
              "to be coming quite near east from here.\n";
}
