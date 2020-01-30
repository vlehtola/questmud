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
        add_exit("west","room19");
        add_exit("east","room21");
        short_desc = "A deeper in the forest full of purple mist";
  long_desc = "The part of the forest is full of purple mist, which makes seeing anything\n"+
              "clearly here almost impossible. The black trees are twisted and they look\n"+
              "quite scary, like they would be trying to get a hold of something and then\n"+
              "kill it! A enourmous looking spruce is little away east from here.\n";

}