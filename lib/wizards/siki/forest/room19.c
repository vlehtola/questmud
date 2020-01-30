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
        add_exit("west","room6");
        add_exit("east","room20");
        short_desc = "A path full of purple mist";
  long_desc = "The part of the forest is full of purple mist, which makes seeing anything\n"+
              "clearly here almost impossible. The black trees are twisted and they look\n"+
              "quite scary, like they would be trying to get a hold of something and then\n"+
              "kill it!\n";

}