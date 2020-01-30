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
        add_exit("south","room23");
        add_exit("west","room20");
        add_exit("east","room22");
        short_desc = "A crossing in the path";
  long_desc = "The crossing point of the paths. A quiet whining sound can be heard\n"+
              "somewhere, it seems like somebody is asking for help. The ground is\n"+
              "full of fighting marks from animals. A couple torn pieces of child's\n"+
              "clothing can also be seen.\n";
}