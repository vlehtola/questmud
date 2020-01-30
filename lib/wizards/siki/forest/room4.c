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
        add_exit("west","room3");
        add_exit("east","room5");
        short_desc = "Deeper in the corrupted forest";
     long_desc = "Deeper in the corrupted forest. The air is even more heavier and the mist\n"+
                 "looms high in the first branches of the trees. Shadowy creatures are looming\n"+
                 "behing the twisted and black trees, and low gurgling sound can be heard from\n"+
                 "time to time.\n";
}
