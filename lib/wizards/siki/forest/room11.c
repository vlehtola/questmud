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
        add_exit("north","room6");
        add_exit("south","room12");
        add_exit("east","room18");
        short_desc = "Deformed forest";
     long_desc = "The air in here is almost deadly and because of the purple mist it is almost\n"+
                 "impossible to see here clearly. This forest is full of twisted black trees\n"+
                 "and shadowy creatures are moving behind those. Near the surface of mist are\n"+
                 "the tops of the deformed bushes.\n";
}
