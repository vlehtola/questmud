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
        add_exit("south","room15");
        add_exit("west","room17");
        add_exit("east","room24");
        short_desc = "A twisted path";
        long_desc =
              "The path looks twisted and it is full of rotting things. Both side of this path\n"+
              "there is a floating purple mist, which is little strange because the path is\n"+
              "clear of it. A demonical roaring sound can be heard here clearly and it seems\n"+
              "to be coming quite near southwest from here.\n";
       

}
