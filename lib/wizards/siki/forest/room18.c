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
        add_exit("west","room11");
        add_exit("south","room17");
        short_desc = "A deformed bushes are south from here";
  long_desc = "The twisted looking path is going different ways from here. A lots of that\n"+
              "purple mist is floating above the ground and it makes the breating almost\n"+
              "an impossible thing to do here. A strange looking bush is south from here.\n";

}