inherit "room/room";

reset(arg) {

 if(!present("warrior")) {
   move_object(clone_object("/wizards/torspo/areat/ogre/monsters/ogre2.c"), this_object());
 }

  if(arg) { return; }
  add_exit("southeast", "/wizards/torspo/areat/ogre/room20.c");

   short_desc = "Fortress";
  long_desc = "The barracks of the guards is located here. Usually many children gather\n"+
              "here and admire the skilled guards and listen to the tales the guards\n"+
              "tell them. The barracks itself has collapsed, probably due to some\n"+
              "misunderstanings among the ranks of warriors.\n";
}
